#include <jni.h>
#include <string>
#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/mman.h>
#include <sys/ptrace.h>
#include <unwind.h>
#include <libgen.h>
#include <stdint.h>
#include <functional>
#include <sys/stat.h>
#include <fcntl.h>
#include <android/log.h>
#include "Main/Tools.h"
#include "Main/Logger.h"
#include "Main/oxorany.h"
#include "Main/obfuscate.h"
#include "Main/Utils.h"
#include "Main/KittyMemory/MemoryPatch.h"
#include "Main/Macros.h"
#define targetLibName oxorany("libanogs.so")
#define HOOK_LIB_NO_ORIG(lib, offset, hook) DobbyHook((void *)get_remote_lib_address(lib, offset), (void *)hook, nullptr)
typedef uint64_t _QWORD;
typedef uint32_t _DWORD;
typedef uint16_t _WORD;
typedef uint8_t _BYTE;
__int64 (*osub_1D6598)();
__int64 hsub_1D6598() { return 0; }
typedef __int64 (*sub_dispatcher_a2_t)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64);
__int64 (*osub_3A8DA8)(__int64, sub_dispatcher_a2_t, int, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64);
__int64 hsub_3A8DA8(__int64 a1, sub_dispatcher_a2_t a2, int a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9, __int64 a10, __int64 a11) { return 0; }
__int64 (*osub_3F9928)(sub_dispatcher_a2_t, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64);
__int64 hsub_3F9928(sub_dispatcher_a2_t a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9) { return 0; }
__int64 (*osub_3FC5C8)(__int64, __int64, double);
__int64 hsub_3FC5C8(__int64 a1, __int64 a2, double a3) { if (a1) { *(_QWORD*)(a1 + 208) = 0; *(_QWORD*)(a1 + 224) = 0; *(_QWORD*)(a1 + 280) = 0; *(_QWORD*)(a1 + 288) = 0; } return 0; }
__int64 (*osub_37966C)(int*, __int64);
__int64 hsub_37966C(int* a1, __int64 a2) { if (a2 && *(_QWORD*)(a2 + 8)) *(_DWORD*)a2 = 0xFFFFFFFF; return 0; }
__int64 (*osub_4B39E0)(__int64, const char*);
__int64 hsub_4B39E0(__int64 a1, const char* a2) { if (a2 && (strstr(a2, oxorany("Report")) || strstr(a2, oxorany("Termination")))) return 0; return osub_4B39E0 ? osub_4B39E0(a1, a2) : 0; }
__int64 (*osub_2328F0)(__int64, const char*, __int64);
__int64 hsub_2328F0(__int64 a1, const char* a2, __int64 a3) { if (a2 && (strstr(a2, oxorany("crash")) || strstr(a2, oxorany("ban")))) return 0; return osub_2328F0 ? osub_2328F0(a1, a2, a3) : 0; }
__int64 (*osub_379220)(__int64, const char*, const char*);
__int64 hsub_379220(__int64 a1, const char* a2, const char *a3) { if (a2 && (strstr(a2, oxorany("ms_data_crc")) || strstr(a2, oxorany("ms_down_data")))) return 0; return osub_379220 ? osub_379220(a1, a2, a3) : 0; }
__int64 (*osub_21248C)(__int64);
__int64 hsub_21248C(__int64 a1) { if (a1) *(uint32_t*)(a1 + 116) = 0; return 0; }
__int64 (*osub_36A5B8)(_DWORD*, _QWORD*);
__int64 hsub_36A5B8(_DWORD* a1, _QWORD* a2) { if (a1) a1[4] = 0; return 0; }
__int64 (*osub_228168)(__int64, unsigned __int8*, uint32_t);
__int64 hsub_228168(__int64 a1, unsigned __int8* a2, uint32_t a3) { if (a2 && a2[0] == 0x1B) return 0; return 0xFFFFFFFFLL; }
__int64 (*osub_451564)(__int64, __int64);
__int64 hsub_451564(__int64 a1, __int64 a2) { if (a2) { size_t sz = *(size_t*)(a2 + 240); if (sz > 0 && sz <= 32) memset((void*)(a2 + 248), 0, sz); } return osub_451564 ? osub_451564(a1, a2) : 0; }
void (*osub_425864)(__int64);
void hsub_425864(__int64 a1) { if (a1) { *(uint8_t*)((uintptr_t)a1 + 0x48) = 0; *(uint8_t*)((uintptr_t)a1 + 0x60) = 0; } if (osub_425864) osub_425864(a1); }
__pid_t (**__fastcall hsub_2940D0(__pid_t (**result)(void)))(void) { return 0LL; }
void nhsub_5003A4(const char* a1, ...) { return; }
__int64 nhsub_431AD8(__int64 a1, unsigned int a2) { return 0; }
__int64 nhsub_3F99E8(__int64 a1, sub_dispatcher_a2_t a2, double a3) { return 0; }
__int64 nhsub_1C1F9C(unsigned int a1) { return 0; }
__int64 nhsub_1D081C(__int64 a1, __int64 a2, __int64 a3) { return 0; }
__int64 nhsub_1DF544(__int64 a1) { return 0; }
__int64 nhsub_1EE7D0(__int64 a1) { return 0; }
void *ue4_thread(void *) {
    do { sleep(1); } while (!isLibraryLoaded("libUE4.so"));
#if defined(__aarch64__)
    PATCH_LIB("libUE4.so", "0x7A649A8", "00 00 80 D2 C0 03 5F D6");
#endif
    return NULL;
}
void *anogs_thread(void *) {
    do { sleep(1); } while (!isLibraryLoaded("libanogs.so"));
    PATCH_LIB("libanogs.so", "0x4B3560", "20 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x225528", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x31DCB0", "1F 20 03 D5");
    PATCH_LIB("libanogs.so", "0x330494", "E0 03 27 1E C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x362BF4", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x371418", "1F 20 03 D5");
    PATCH_LIB("libanogs.so", "0x37C904", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x431800", "20 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x46EFD0", "1F 20 03 D5");
    PATCH_LIB("libanogs.so", "0x4F7074", "E0 03 27 1E C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x232B28", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x213DC8", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1C76E4", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1C77E8", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1CD404", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1CE2A4", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1D339C", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1DBD48", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1DC09C", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1DD054", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1DEAE0", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1E060C", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1E1A20", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1E2B44", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1E3C68", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1E4D8C", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1E5EB0", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1E6FD4", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1E80F8", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1E921C", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1EA340", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1EB464", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1EC588", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1ED6AC", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2F3EB8", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2FD548", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x3B5190", "C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4B6C94", "C0 03 5F D6");
    HOOK_LIB("libanogs.so", "0x1D6598", hsub_1D6598, osub_1D6598);
    HOOK_LIB("libanogs.so", "0x3A8DA8", hsub_3A8DA8, osub_3A8DA8);
    HOOK_LIB("libanogs.so", "0x3F9928", hsub_3F9928, osub_3F9928);
    HOOK_LIB("libanogs.so", "0x3FC5C8", hsub_3FC5C8, osub_3FC5C8);
    HOOK_LIB("libanogs.so", "0x37966C", hsub_37966C, osub_37966C);
    HOOK_LIB("libanogs.so", "0x4B39E0", hsub_4B39E0, osub_4B39E0);
    HOOK_LIB("libanogs.so", "0x2328F0", hsub_2328F0, osub_2328F0);
    HOOK_LIB("libanogs.so", "0x379220", hsub_379220, osub_379220);
    HOOK_LIB("libanogs.so", "0x21248C", hsub_21248C, osub_21248C);
    HOOK_LIB("libanogs.so", "0x36A5B8", hsub_36A5B8, osub_36A5B8);
    HOOK_LIB("libanogs.so", "0x451564", hsub_451564, osub_451564);
    HOOK_LIB("libanogs.so", "0x425864", hsub_425864, osub_425864);
    HOOK_LIB_NO_ORIG("libanogs.so", "0x2940D0", hsub_2940D0);
    HOOK_LIB_NO_ORIG("libanogs.so", "0x5003A4", nhsub_5003A4);
    HOOK_LIB_NO_ORIG("libanogs.so", "0x431AD8", nhsub_431AD8);
    HOOK_LIB_NO_ORIG("libanogs.so", "0x3F99E8", nhsub_3F99E8);
    HOOK_LIB_NO_ORIG("libanogs.so", "0x1C1F9C", nhsub_1C1F9C);
    HOOK_LIB_NO_ORIG("libanogs.so", "0x1D081C", nhsub_1D081C);
    HOOK_LIB_NO_ORIG("libanogs.so", "0x1DF544", nhsub_1DF544);
    return NULL;
}
__attribute__((constructor)) void mainload() { pthread_t ptid, ptid2; pthread_create(&ptid, NULL, anogs_thread, NULL); pthread_create(&ptid2, NULL, ue4_thread, NULL); }
