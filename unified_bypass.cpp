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

typedef uint64_t _QWORD;
typedef uint32_t _DWORD;
typedef uint16_t _WORD;
typedef uint8_t _BYTE;

typedef int (*__pid_t_func)(void);
typedef __pid_t_func* __pid_t_ptr_ptr;
__pid_t_ptr_ptr (*osub_2940D0)(__pid_t_ptr_ptr result) = nullptr;
__pid_t_ptr_ptr hsub_2940D0(__pid_t_ptr_ptr result) {
    if (result) {
        auto res = osub_2940D0(result);
        if (res == (__pid_t_ptr_ptr)&ptrace) return 0LL;
        return res;
    }
    return 0LL;
}

__int64 (*osub_21248C)(__int64 a1) = nullptr;
__int64 hsub_21248C(__int64 a1) {
    if (a1) { *(_DWORD *)(a1 + 116) = 0; }
    return 0;
} // Fix Crash

__int64 (*osub_2328F0)(__int64 a1, const char *a2, __int64 a3) = nullptr;
__int64 hsub_2328F0(__int64 a1, const char *a2, __int64 a3) {
    if (a2 && (strstr(a2, oxorany("crash")) || strstr(a2, oxorany("opcode")) || strstr(a2, oxorany("profiler")))) return 0;
    return osub_2328F0(a1, a2, a3);
} // case 16

__int64 (*osub_228168)(__int64 a1, unsigned __int8 *a2, size_t a3) = nullptr;
__int64 hsub_228168(__int64 a1, unsigned __int8 *a2, size_t a3) {
    switch (a3) {
        case 0x62: case 0x3E: case 0x18: return osub_228168(a1, a2, a3);
        default: return 0LL;
    }
} // case 35

void (*osub_228560)() = nullptr;
void hsub_228560() { return; } // case 37

__int64 (*osub_362BF4)(__int64 a1, unsigned int a2, __int64 a3) = nullptr;
__int64 hsub_362BF4(__int64 a1, unsigned int a2, __int64 a3) {
    if (!a1 || !a2 || a2 >= 0x10000) return 0LL;
    return osub_362BF4(a1, a2, a3);
} // case 35

__int64 (*osub_389744)(__int64 a1, _QWORD *a2, int a3, __int64 a4, __int64 a5) = nullptr;
__int64 hsub_389744(__int64 a1, _QWORD *a2, int a3, __int64 a4, __int64 a5) {
    return 0;
} // case 34

__int64 (*osub_49AA00)(char *a1, __int64 a2) = nullptr;
__int64 hsub_49AA00(char *a1, __int64 a2) { return 0; } // runtime hash verifier

__int64 (*osub_2124C8)(__int64 a1, char a2) = nullptr;
void hsub_2124C8(__int64 a1, char a2) {
    if (!a1) return;
    *(uint8_t *)(a1 + 112) = 0;
    return;
}

__int64 (*osub_21E9C4)(__int64 a1, __int64 a2, __int64 a3, int a4, int a5) = nullptr;
void hsub_21E9C4(__int64 a1, __int64 a2, __int64 a3, int a4, int a5) { return; }

__int64 (*oAnoSDKInit)(__int64 result) = nullptr;
__int64 hAnoSDKInit(__int64 result) { return 0; }

__int64 (*oAnoSDKGetReportData)() = nullptr;
__int64 hAnoSDKGetReportData() { return 0; }

__int64 (*osub_36A5B8)(_DWORD *a1, _QWORD *a2) = nullptr;
__int64 hsub_36A5B8(_DWORD *a1, _QWORD *a2) { return 0; }

__int64 (*osub_39F56C)(unsigned __int8 *a1, uint32_t a2) = nullptr;
__int64 hsub_39F56C(unsigned __int8 *a1, uint32_t a2) { return 0; }

__int64 (*osub_447750)(__int64 a1, __int64 a2) = nullptr;
__int64 hsub_447750(__int64 a1, __int64 a2) { return 0; }

__int64 (*osub_461F04)(_BYTE *a1, int a2, __int64 a3, int a4) = nullptr;
__int64 hsub_461F04(_BYTE *a1, int a2, __int64 a3, int a4) { return 0; }

__int64 (*osub_471B68)(__int64 a1, int a2) = nullptr;
__int64 hsub_471B68(__int64 a1, int a2) { return 0; }

__int64 (*osub_47B5CC)() = nullptr;
__int64 hsub_47B5CC() { return 0; }

_QWORD *(*osub_4D4C94)(int a1, int a2) = nullptr;
_QWORD *hsub_4D4C94(int a1, int a2) { return nullptr; }

void *(*osub_51F980)(void *dest, const void *src, size_t n) = nullptr;
void *hsub_51F980(void *dest, const void *src, size_t n) { return memcpy(dest, src, n); }

void *(*osub_51F9A0)(void *s, int c, size_t n) = nullptr;
void *hsub_51F9A0(void *s, int c, size_t n) { return memset(s, c, n); }

__int64 (*osub_3A564C)(__int64 a1, uint64_t a2, void *a3, double a4) = nullptr;
__int64 hsub_3A564C(__int64 a1, uint64_t a2, void *a3, double a4) { return 0; }

void *(*osub_46ED30)(__int64 a1, FILE *a2, uint32_t *a3) = nullptr;
void *hsub_46ED30(__int64 a1, FILE *a2, uint32_t *a3) { return nullptr; }

void *ue4_thread(void *) {
    do { sleep(1); } while (!isLibraryLoaded("libUE4.so"));
#if defined(__aarch64__)
    PATCH_LIB("libUE4.so", "0x74B1BC0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x776AFF8", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x5ACC184", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x62E286C", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x68CD9C8", "1F 20 03 D5");
    PATCH_LIB("libUE4.so", "0x7A649A8", "C0 03 5F D6"); // Fix Crash
#endif
    return NULL;
}

void *anogs_thread(void *) {
    do { sleep(1); } while (!isLibraryLoaded("libanogs.so"));

    HOOKSYM_LIB("libanogs.so", "AnoSDKInit", hAnoSDKInit, oAnoSDKInit);
    HOOKSYM_LIB("libanogs.so", "AnoSDKGetReportData", hAnoSDKGetReportData, oAnoSDKGetReportData);

    HOOK_LIB("libanogs.so", "0x21248C", hsub_21248C, osub_21248C); // Fix Crash
    HOOK_LIB("libanogs.so", "0x2124C8", hsub_2124C8, osub_2124C8);
    HOOK_LIB("libanogs.so", "0x21E9C4", hsub_21E9C4, osub_21E9C4);
    HOOK_LIB("libanogs.so", "0x228168", hsub_228168, osub_228168); // case 35
    HOOK_LIB("libanogs.so", "0x228560", hsub_228560, osub_228560); // case 37
    HOOK_LIB("libanogs.so", "0x2328F0", hsub_2328F0, osub_2328F0); // case 16
    HOOK_LIB("libanogs.so", "0x362BF4", hsub_362BF4, osub_362BF4); // case 35
    HOOK_LIB("libanogs.so", "0x389744", hsub_389744, osub_389744); // case 34
    HOOK_LIB("libanogs.so", "0x2940D0", hsub_2940D0, osub_2940D0);
    HOOK_LIB("libanogs.so", "0x49AA00", hsub_49AA00, osub_49AA00); // runtime hash verifier
    HOOK_LIB("libanogs.so", "0x36A5B8", hsub_36A5B8, osub_36A5B8);
    HOOK_LIB("libanogs.so", "0x39F56C", hsub_39F56C, osub_39F56C);
    HOOK_LIB("libanogs.so", "0x447750", hsub_447750, osub_447750);
    HOOK_LIB("libanogs.so", "0x461F04", hsub_461F04, osub_461F04);
    HOOK_LIB("libanogs.so", "0x471B68", hsub_471B68, osub_471B68);
    HOOK_LIB("libanogs.so", "0x47B5CC", hsub_47B5CC, osub_47B5CC);
    HOOK_LIB("libanogs.so", "0x4D4C94", hsub_4D4C94, osub_4D4C94);
    HOOK_LIB("libanogs.so", "0x51F980", hsub_51F980, osub_51F980);
    HOOK_LIB("libanogs.so", "0x51F9A0", hsub_51F9A0, osub_51F9A0);
    HOOK_LIB("libanogs.so", "0x3A564C", hsub_3A564C, osub_3A564C);
    HOOK_LIB("libanogs.so", "0x46ED30", hsub_46ED30, osub_46ED30);

    PATCH_LIB("libanogs.so", "0x4B3560", "20 00 80 D2 C0 03 5F D6"); // Fix Crash
    PATCH_LIB("libanogs.so", "0x225528", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x31DCB0", "1F 20 03 D5");
    PATCH_LIB("libanogs.so", "0x330494", "E0 03 27 1E C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x371418", "1F 20 03 D5");
    PATCH_LIB("libanogs.so", "0x37C904", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x431800", "20 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x46EFD0", "1F 20 03 D5");
    PATCH_LIB("libanogs.so", "0x4B39E0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4F7074", "E0 03 27 1E C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x51F9C0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x51FA20", "1F 20 03 D5");
    PATCH_LIB("libanogs.so", "0x51FAB0", "20 00 80 D2 C0 03 5F D6");

    return NULL;
}

__attribute__((constructor)) void mainload() {
    pthread_t ptid;
    pthread_create(&ptid, NULL, anogs_thread, NULL);
    pthread_create(&ptid, NULL, ue4_thread, NULL);
}
