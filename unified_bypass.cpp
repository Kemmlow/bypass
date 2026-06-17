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
#include <time.h>
#include <sys/time.h>
#include "Main/Tools.h"
#include "Main/Logger.h"
#include "Main/oxorany.h"
#include "Main/obfuscate.h"
#include "Main/Utils.h"
#include "Main/KittyMemory/MemoryPatch.h"
#include "Main/Macros.h"
#define targetLibName oxorany("libanogs.so")
typedef uint64_t _QWORD;
typedef uint32_t _DWORD;
typedef uint16_t _WORD;
typedef uint8_t _BYTE;
__int64 (*osub_3FC5C8)(__int64, __int64, double);
__int64 hsub_3FC5C8(__int64 a1, __int64 a2, double a3) {
    if (a1) { *(_QWORD*)(a1 + 208) = 0; *(_QWORD*)(a1 + 224) = 0; *(_QWORD*)(a1 + 280) = 0; *(_QWORD*)(a1 + 288) = 0; }
    return osub_3FC5C8 ? osub_3FC5C8(a1, a2, a3) : 0;
}
__int64 (*osub_37966C)(int*, __int64);
__int64 hsub_37966C(int* a1, __int64 a2) {
    if (a2 && *(_QWORD*)(a2 + 8)) *(_DWORD*)a2 = 0xFFFFFFFF;
    return 0;
}
__int64 (*osub_4B39E0)(__int64, const char*);
__int64 hsub_4B39E0(__int64 a1, const char* a2) {
    if (a2 && (strstr(a2, oxorany("Report")) || strstr(a2, oxorany("Termination")))) return 0;
    return osub_4B39E0 ? osub_4B39E0(a1, a2) : 0;
}
__int64 (*osub_2328F0)(__int64, const char*, __int64);
__int64 hsub_2328F0(__int64 a1, const char* a2, __int64 a3) {
    if (a2 && (strstr(a2, oxorany("crash")) || strstr(a2, oxorany("ban")))) return 0;
    return osub_2328F0 ? osub_2328F0(a1, a2, a3) : 0;
}
__int64 (*osub_379220)(__int64, const char*, const char*);
__int64 hsub_379220(__int64 a1, const char* a2, const char *a3) {
    if (a2 && strstr(a2, oxorany("ms_data_crc"))) return 0;
    return osub_379220 ? osub_379220(a1, a2, a3) : 0;
}
__int64 (*osub_21248C)(__int64);
__int64 hsub_21248C(__int64 a1) { if (a1) *(uint32_t*)(a1 + 116) = 0; return 0; }
__int64 (*osub_36A5B8)(_DWORD*, _QWORD*);
__int64 hsub_36A5B8(_DWORD* a1, _QWORD* a2) { if (a1) a1[4] = 0; return 0; }
__int64 (*osub_228168)(__int64, unsigned __int8*, uint32_t);
__int64 hsub_228168(__int64 a1, unsigned __int8* a2, uint32_t a3) { if (a2 && a2[0] == 0x1B) return 0; return 0xFFFFFFFFLL; }
__int64 (*osub_451564)(__int64, __int64);
__int64 hsub_451564(__int64 a1, __int64 a2) {
    if (a2) { size_t sz = *(size_t*)(a2 + 240); if (sz > 0 && sz <= 32) memset((void*)(a2 + 248), 0, sz); }
    return osub_451564 ? osub_451564(a1, a2) : 0;
}
void (*osub_425864)(__int64);
void hsub_425864(__int64 a1) { if (a1) { *(uint8_t*)((uintptr_t)a1 + 0x48) = 0; *(uint8_t*)((uintptr_t)a1 + 0x60) = 0; } if (osub_425864) osub_425864(a1); }
__pid_t (**(*osub_2940D0)(__pid_t (**result)(void)))(void);
__pid_t (**__fastcall hsub_2940D0(__pid_t (**result)(void)))(void) {
    if (result) { auto res = osub_2940D0(result); if (res == (__pid_t(**)(void)) & ptrace) return 0LL; return res; }
    return 0LL;
}
void (*osub_5003A4)(const char*, ...);
void hsub_5003A4(const char* a1, ...) { return; }
void *ue4_thread(void *) {
    do { sleep(1); } while (!isLibraryLoaded("libUE4.so"));
#if defined(__aarch64__)
    PATCH_LIB("libUE4.so", "0x7A649A8", "00 00 80 D2 C0 03 5F D6");
#endif
    return NULL;
}
void *anogs_thread(void *) {
    do { sleep(1); } while (!isLibraryLoaded("libanogs.so"));
    PATCH_LIB("libanogs.so", "0x4B3560", "20 00 80 D2 C0 03 5F D6"); // bypass integrity check
    PATCH_LIB("libanogs.so", "0x225528", "00 00 80 D2 C0 03 5F D6"); // kill heartbeat thread
    PATCH_LIB("libanogs.so", "0x31DCB0", "1F 20 03 D5");             // disable ptrace trap
    PATCH_LIB("libanogs.so", "0x330494", "E0 03 27 1E C0 03 5F D6"); // bypass signal verify
    PATCH_LIB("libanogs.so", "0x362BF4", "00 00 80 D2 C0 03 5F D6"); // kill scan thread
    PATCH_LIB("libanogs.so", "0x371418", "1F 20 03 D5");             // disable debug check
    PATCH_LIB("libanogs.so", "0x37C904", "00 00 80 D2 C0 03 5F D6"); // bypass crc verify
    PATCH_LIB("libanogs.so", "0x431800", "20 00 80 D2 C0 03 5F D6"); // kill report thread
    PATCH_LIB("libanogs.so", "0x46EFD0", "1F 20 03 D5");             // disable maps scan
    PATCH_LIB("libanogs.so", "0x4F7074", "E0 03 27 1E C0 03 5F D6"); // bypass hash verify
    PATCH_LIB("libanogs.so", "0x232B28", "C0 03 5F D6");             // kill root check
    PATCH_LIB("libanogs.so", "0x213DC8", "C0 03 5F D6");             // kill emu check
    PATCH_LIB("libanogs.so", "0x1C76E4", "C0 03 5F D6");             // bypass file integrity
    PATCH_LIB("libanogs.so", "0x1C77E8", "C0 03 5F D6");             // bypass signature verify
    PATCH_LIB("libanogs.so", "0x1CD404", "C0 03 5F D6");             // kill scan monitor
    PATCH_LIB("libanogs.so", "0x1CE2A4", "C0 03 5F D6");             // bypass memory verify
    PATCH_LIB("libanogs.so", "0x1D339C", "C0 03 5F D6");             // bypass sdk startup
    PATCH_LIB("libanogs.so", "0x1DBD48", "C0 03 5F D6");             // kill env tracker
    PATCH_LIB("libanogs.so", "0x1DC09C", "C0 03 5F D6");             // bypass pkg integrity
    PATCH_LIB("libanogs.so", "0x1DD054", "C0 03 5F D6");             // disable integrity signal
    PATCH_LIB("libanogs.so", "0x1DEAE0", "C0 03 5F D6");             // kill thread watchdog
    PATCH_LIB("libanogs.so", "0x1E060C", "C0 03 5F D6");             // disable status verify
    PATCH_LIB("libanogs.so", "0x1E1A20", "C0 03 5F D6");             // kill debug tracker
    PATCH_LIB("libanogs.so", "0x1E2B44", "C0 03 5F D6");             // bypass loader tracker
    PATCH_LIB("libanogs.so", "0x1E3C68", "C0 03 5F D6");             // disable apk signature
    PATCH_LIB("libanogs.so", "0x1E4D8C", "C0 03 5F D6");             // kill injected tracker
    PATCH_LIB("libanogs.so", "0x1E5EB0", "C0 03 5F D6");             // bypass dalvik verify
    PATCH_LIB("libanogs.so", "0x1E6FD4", "C0 03 5F D6");             // disable mount tracker
    PATCH_LIB("libanogs.so", "0x1E80F8", "C0 03 5F D6");             // kill virtual verify
    PATCH_LIB("libanogs.so", "0x1E921C", "C0 03 5F D6");             // bypass multi tracker
    PATCH_LIB("libanogs.so", "0x1EA340", "C0 03 5F D6");             // disable parallel verify
    PATCH_LIB("libanogs.so", "0x1EB464", "C0 03 5F D6");             // kill dual tracker
    PATCH_LIB("libanogs.so", "0x1EC588", "C0 03 5F D6");             // bypass mount verify
    PATCH_LIB("libanogs.so", "0x1ED6AC", "C0 03 5F D6");             // disable proc verify
    PATCH_LIB("libanogs.so", "0x2F3EB8", "C0 03 5F D6");             // bypass file logic
    PATCH_LIB("libanogs.so", "0x2FD548", "C0 03 5F D6");             // bypass mutex logic
    PATCH_LIB("libanogs.so", "0x3B5190", "C0 03 5F D6");             // disable wait logic
    PATCH_LIB("libanogs.so", "0x4B6C94", "C0 03 5F D6");             // bypass string logic
    HOOK_LIB("libanogs.so", "0x3FC5C8", hsub_3FC5C8, osub_3FC5C8); // state clearing precision
    HOOK_LIB("libanogs.so", "0x37966C", hsub_37966C, osub_37966C); // reporter state precision
    HOOK_LIB("libanogs.so", "0x4B39E0", hsub_4B39E0, osub_4B39E0); // string dispatcher filter
    HOOK_LIB("libanogs.so", "0x2328F0", hsub_2328F0, osub_2328F0); // crash string filter
    HOOK_LIB("libanogs.so", "0x379220", hsub_379220, osub_379220); // reporting center filter
    HOOK_LIB("libanogs.so", "0x21248C", hsub_21248C, osub_21248C); // dispatcher crash fix
    HOOK_LIB("libanogs.so", "0x36A5B8", hsub_36A5B8, osub_36A5B8); // scan state bypass
    HOOK_LIB("libanogs.so", "0x228168", hsub_228168, osub_228168); // case 35 dispatcher
    HOOK_LIB("libanogs.so", "0x451564", hsub_451564, osub_451564); // hash verify dispatcher
    HOOK_LIB("libanogs.so", "0x425864", hsub_425864, osub_425864); // memory master logic
    HOOK_LIB("libanogs.so", "0x2940D0", hsub_2940D0, osub_2940D0); // ptrace pointer blocker
    HOOK_LIB("libanogs.so", "0x5003A4", hsub_5003A4, osub_5003A4); // terminate signal blocker
    return NULL;
}
__attribute__((constructor)) void mainload() { pthread_t ptid, ptid2; pthread_create(&ptid, NULL, anogs_thread, NULL); pthread_create(&ptid2, NULL, ue4_thread, NULL); }
