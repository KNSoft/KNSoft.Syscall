/* Usage: ThunkGenerator Solution-Directory */

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

using KNSoft.C4Lib.CodeHelper;
using KNSoft.NDK.SDK;

/* The parameter should be solution directory */
if (!File.Exists(args[0] + @"\KNSoft.Syscall.sln"))
{
    throw new ArgumentException("Input parameter should be path of solution directory.");
}
String SlnDir = args[0];

/* Locate KNSoft.NDK header directory and get syscalls */
String NDKHeaderDir = Directory.GetDirectories(SlnDir + @"\packages",
                                               "KNSoft.NDK.*",
                                               SearchOption.TopDirectoryOnly)[0] + @"\build\Include\KNSoft\NDK";
List<Cpp.Function> ZwApi = SyscallResolver.GetSyscalls(NDKHeaderDir + @"\NT", SyscallResolver.SyscallType.Zw);
List<Cpp.Function> ZwManualApi = SyscallResolver.GetSyscalls(NDKHeaderDir + @"\NT", SyscallResolver.SyscallType.ZwManual);
List<Cpp.Function> NtUserApi = SyscallResolver.GetSyscalls(NDKHeaderDir + @"\NT", SyscallResolver.SyscallType.NtUser);
ZwApi.AddRange(ZwManualApi.DistinctBy(x => x.Name));
ZwApi = [.. ZwApi.OrderBy(x => x.Name)];
NtUserApi = [.. NtUserApi.OrderBy(x => x.Name)];

/* Sanity checks */

/* Name at least 5 characters, encoded data at least 4 bytes */
Debug.Assert(!ZwApi.Any(x => x.Name.Length < 5));
Debug.Assert(!NtUserApi.Any(x => x.Name.Length < 5));

/* Name cannot exceeds 85 characters. Maximum blob size in bytes = 64, 64 * 8 / 6 = 85.333... */
Debug.Assert(!ZwApi.Any(x => x.Name.Length < 5));
Debug.Assert(!NtUserApi.Any(x => x.Name.Length < 5));

/* No Zw* syscall named ZwUser* */
Debug.Assert(!ZwApi.Any(x => x.Name.StartsWith("User")));

/* Write output files */

String MinName = String.Empty, MaxName = String.Empty;
Int32 MinNameLength = Int32.MaxValue, MaxNameLength = 0;
String ThunkDir = SlnDir + @"\KNSoft.Syscall\Thunks";
StreamWriter ThunksH = Cpp.CreateOutputFile(SlnDir + @"\KNSoft.Syscall\Syscall.Thunks.h");
StreamWriter AllThunks = Cpp.CreateOutputFile(SlnDir + @"\UnitTest\AllThunks.inl");

Cpp.OutputWithNewLine(ThunksH, Cpp.CodeFragment.AutoGenerateFileComment);
Cpp.OutputWithNewLine(ThunksH, Cpp.CodeFragment.PragmaOnce);
Cpp.OutputWithNewLine(ThunksH, "#include <KNSoft/NDK/NDK.h>");
Cpp.OutputWithNewLine(ThunksH, Cpp.CodeFragment.ExternCStart);

Cpp.OutputWithNewLine(AllThunks, Cpp.CodeFragment.AutoGenerateFileComment);
AllThunks.Write(
    "#include \"UnitTest.h\"\r\n\r\n" +
    "typedef struct _THUNK\r\n" +
    "{\r\n" +
    "    PVOID Address;\r\n" +
    "    PCSTR Name;\r\n" +
    "    ULONG NameCch;\r\n" +
    "} THUNK, *PTHUNK;\r\n\r\n" +
    "#define DEFINE_THUNK(x) { &x, #x, _STR_LEN(#x) }\r\n\r\n");
AllThunks.Write("static THUNK AllThunkDef[] = {\r\n");

HandleSyscalls(ZwApi, false);
HandleSyscalls(NtUserApi, true);

ThunksH.WriteLine(Cpp.CodeFragment.ExternCEnd);
ThunksH.Dispose();

AllThunks.WriteLine("};");
AllThunks.Dispose();

Console.WriteLine("MinName: {0} ({1})", MinName, MinNameLength);
Console.WriteLine("MaxName: {0} ({1})", MaxName, MaxNameLength);

return 0;

void HandleSyscalls(List<Cpp.Function> Syscalls, Boolean IsWin32u)
{
    foreach (Cpp.Function Syscall in Syscalls)
    {
        /* Get name and fixup declaration */
        String Name = Syscall.Name[2..];
        Syscall.Name = "Sc" + Name;
        Syscall.Prefixes.Remove("NTSYSCALLAPI");
        Syscall.Prefixes.Insert(0, "EXTERN_C");

        /* Write to output files */
        String[] FuncDecl = Cpp.CodeResolver.FunctionToDeclaration(Syscall);
        foreach (String Line in FuncDecl)
        {
            ThunksH.WriteLine(Line);
        }
        ThunksH.WriteLine();
        if (!IsWin32u)
        {
            AllThunks.Write("    DEFINE_THUNK(" + "Sc" + Name + "),\r\n");
        }

        /* Prepare thunk data */
        if (IsWin32u)
        {
            Name = Name[4..];
        }
        if (Name.Length > MaxNameLength)
        {
            MaxNameLength = Name.Length;
            MaxName = Name;
        }
        if (Name.Length < MinNameLength)
        {
            MinNameLength = Name.Length;
            MinName = Name;
        }
        Int32 ArgCount = 0;
        foreach (Cpp.Parameter Param in Syscall.Parameters)
        {
            if (Param.FixedSize != null)
            {
                ArgCount += (Int32)Param.FixedSize / 4;
            } else
            {
                ArgCount++;
            }
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
                throw new InvalidDataException("Unrecognized character in name: " + Name);
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
                throw new InvalidDataException("Incorrect encoded size of name: " + Name);
            }
        }

        if (IsWin32u)
        {
            Name = "User" + Name;
        }
        Name = "Sc" + Name;
        File.WriteAllText(ThunkDir + @"\" + Name + ".asm",
                          "INCLUDE Syscall.inc\r\n\r\n" +
                          "$SYSCALL " + Name + ", " +
                          (IsWin32u ? "1" : "0") + ", " +
                          ArgCount.ToString() + ", " +
                          String.Join(", ", ThunkData) + "\r\n\r\n" +
                          "END\r\n");
    }
}
