/*
 * KNSoft.Syscall (https://github.com/KNSoft/KNSoft.Syscall) Syscall Thunk Data Generator
 * Copyright (c) KNSoft.org (https://github.com/KNSoft). All rights reserved.
 * Licensed under the MIT license.
 * 
 * Usage: SyscallThunkGen Path-To-NDK-Dir Output-Directory
 */

using System;
using System.IO;

String CodeIncludeOnce = "#pragma once\r\n\r\n";
String CodeIncludePublic = "#include <KNSoft/NDK/NDK.h>\r\n\r\n";
String CodeCBegin = "EXTERN_C_START\r\n\r\n";
String CodeCEnd = "EXTERN_C_END\r\n";

String CodeThunksC = @"
#include ""Syscall.inl""

#pragma section("".ScData"", long, read, write)
#pragma section("".ScThunk$THK"", long, read, write)

#define DEFINE_THUNK(Name, NtUser, BlobSize, ArgCount, ...)\
EXTERN_C FN_##Name Syscall_##Name;\
__declspec(allocate("".ScData"")) DECLSPEC_ALIGN(4) struct\
{\
    SYSCALL_THUNK_DATA_HEADER Header;\
    BYTE Blob[BlobSize + 1];\
} Syscall_ThunkData_##Name = { { { NtUser, BlobSize, ArgCount }, &Syscall_##Name },  { __VA_ARGS__ } };\
__declspec(allocate("".ScThunk$THK"")) FN_##Name * volatile Name = (FN_##Name *)&Syscall_ThunkData_##Name

";

String MaxName = String.Empty, MaxArg = String.Empty;
Int32 MaxNameCount = 0, MaxArgCount = 0;

/* Initialize output file streams */

StreamWriter ThunksH = File.CreateText(args[1] + @"\Syscall.Thunks.h");
StreamWriter ThunksC = File.CreateText(args[1] + @"\Syscall.Thunks.c");
StreamWriter ThunksAsm = File.CreateText(args[1] + @"\Syscall.Thunks.Proc.asm");

ThunksH.Write(CodeIncludeOnce + CodeIncludePublic + CodeCBegin);
ThunksC.Write(CodeThunksC);
ThunksAsm.Write("INCLUDE Syscall.inc\r\n\r\nScCode SEGMENT PARA READ EXECUTE ALIAS(\".ScCode\")\r\n\r\n");

ResolveFile(args[0] + @"\NT\ZwApi.h", false);
ResolveFile(args[0] + @"\NT\Win32K\Win32KApi.h", true);

ThunksH.Write(CodeCEnd);
ThunksAsm.Write("\r\nScCode ENDS\r\n\r\nEND\r\n");

Console.WriteLine("MaxName: {0} ({1})", MaxName, MaxNameCount);
Console.WriteLine("MaxArg: {0} ({1})", MaxArg, MaxArgCount);

ThunksAsm.Dispose();
ThunksH.Dispose();
ThunksC.Dispose();

void ResolveFile(String Path, Boolean IsWin32u)
{
    String[] FileContent = File.ReadAllLines(Path);
    String PreviousName = String.Empty;

    /* Read file content */
    for (Int32 i = 0; i < FileContent.Length; i++)
    {
        Int32 iStart, iEnd;

        /* Match NTSYSCALLAPI */
        if (FileContent[i] != "NTSYSCALLAPI")
        {
            continue;
        }

        /* Find end of declaration, after 5 lines at least */
        for (iEnd = i + 5; iEnd < FileContent.Length; iEnd++)
        {
            if (FileContent[iEnd] == "    );")
            {
                break;
            }
        }
        if (iEnd >= FileContent.Length)
        {
            break;
        }
        iStart = i;
        i = iEnd;

        /* Resolve declaration within [iStart .. iEnd] */

        String Name;

        /* Get name */
        Name = FileContent[iStart + 3];
        if ((!IsWin32u && !Name.StartsWith("Zw")) ||
            (IsWin32u && !Name.StartsWith("NtUser")))
        {
            Console.WriteLine("Unrecognized declaration in {0} Line {1} to {2}", Path, iStart, iEnd);
            continue;
        }
        if (Name == PreviousName)
        {
            continue;
        }
        PreviousName = Name;
        Name = Name[2..^1];

        /* Rewrite to Syscall.Thunk.h with "Sc" prefix and remove "NTSYSCALLAPI" */
        ThunksH.WriteLine("typedef");
        for (Int32 j = iStart + 1; j <= iEnd; j++)
        {
            if (j == iStart + 3)
            {
                ThunksH.WriteLine("FN_Sc" + Name + "(");
            } else
            {
                ThunksH.WriteLine(FileContent[j]);
            }
        }
        ThunksH.WriteLine("EXTERN_C FN_Sc" + Name + "* volatile Sc" + Name + ";");
        ThunksH.WriteLine();

        /* Prepare thunk data */
        if (IsWin32u)
        {
            Name = Name[4..];
        }
        if (Name.Length > MaxNameCount)
        {
            MaxNameCount = Name.Length;
            MaxName = Name;
        }
        if (Name.Length > 128)
        {
            Console.WriteLine("Name too long to encode: " + Name);
            continue;
        }
        Int32 ArgCount = 0;
        if (FileContent[iStart + 4] != "    VOID")
        {
            for (Int32 j = iStart + 4; j < iEnd; j++)
            {
                if (FileContent[j].Contains(" POINT "))
                {
                    ArgCount += 1;
                }
                ArgCount++;
            }
        }
        if (ArgCount > MaxArgCount)
        {
            MaxArgCount = ArgCount;
            MaxArg = Name;
        }

        /* Encode thunk data and write file */
        Byte Char, ByteRemain = 0;
        Int32 iThunkData = 0, BlobSize = (Name.Length * 6 - 1) / 8 + 1;
        Byte[] ThunkData = new Byte[BlobSize];

        for (Int32 iName = 0; iName < Name.Length; iName++)
        {
            if (Name[iName] >= 'a' && Name[iName] <= 'z')
            {
                Char = (Byte)(Name[iName] - 'a' + 1);
            } else if (Name[iName] >= 'A' && Name[iName] <= 'Z')
            {
                Char = (Byte)(Name[iName] - 'A' + 27);
            } else if (Name[iName] >= '0' && Name[iName] <= '9')
            {
                Char = (Byte)(Name[iName] - '0' + 53);
            } else
            {
                Console.WriteLine("Unrecognized character in name: " + Name);
                break;
            }

            if (iName % 4 == 0)
            {
                ByteRemain = (Byte)(Char << 2);
            } else if (iName % 4 == 1)
            {
                ThunkData[iThunkData++] = (Byte)(ByteRemain | (Char >> 4));
                ByteRemain = (Byte)(Char << 4);
            } else if (iName % 4 == 2)
            {
                ThunkData[iThunkData++] = (Byte)(ByteRemain | (Char >> 2));
                ByteRemain = (Byte)(Char << 6);
            } else if ((iName % 4) == 3)
            {
                ThunkData[iThunkData++] = (Byte)(ByteRemain | Char);
                ByteRemain = 0;
            }
        }
        if (iThunkData != BlobSize)
        {
            if (iThunkData == BlobSize - 1)
            {
                ThunkData[iThunkData++] = ByteRemain;
            } else
            {
                Console.WriteLine("Incorrect encoded size of name: " + Name);
                continue;
            }
        }

        if (IsWin32u)
        {
            Name = "User" + Name;
        }
        Name = "Sc" + Name;
        ThunksC.Write("DEFINE_THUNK(" + Name + ", " +
                      (IsWin32u ? "1" : "0") + ", " +
                      (BlobSize - 1).ToString() + ", " +
                      ArgCount.ToString() + ", " +
                      String.Join(", ", ThunkData) + ");\r\n");
        ThunksAsm.Write("$SYSCALL " + Name + ", " + ArgCount.ToString() + "\r\n");
    }
}
