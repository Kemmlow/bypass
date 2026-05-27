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

__pid_t (**(*osub_2940D0)(__pid_t (**result)(void)))(void) = nullptr;
__pid_t (**__fastcall hsub_2940D0(__pid_t (**result)(void)))(void)
{
    if (result)
    {
        auto res = osub_2940D0(result);
        if (res == (__pid_t(**)(void)) & ptrace)
            return 0LL;
        return res;
    }
    return 0LL;
}

__int64 (*osub_21248C)(__int64 a1);
__int64 hsub_21248C(__int64 a1)
{
    if (a1)
    {
        *(uint32_t *)(a1 + 116) = 0;
    }
    return 0;
} // case 16

__int64 (*osub_228168)(__int64 a1, unsigned __int8 *a2, uint32_t a3);
__int64 hsub_228168(__int64 a1, unsigned __int8 *a2, uint32_t a3)
{
    if (a2 && a3 > 0x10)
    {
        if (a2[0] == 0x1B)
            return 0;
    }
    return 0xFFFFFFFFLL;
} // case 35

void (*osub_228560)();
void hsub_228560() { return; } // case 37

__int64 (*osub_36A5B8)(_DWORD *a1, _QWORD *a2);
__int64 hsub_36A5B8(_DWORD *a1, _QWORD *a2)
{
    if (a1)
    {
        a1[4] = 0;
    }
    return 0;
}

__int64 (*osub_39F56C)(unsigned __int8 *a1, uint32_t a2);
__int64 hsub_39F56C(unsigned __int8 *a1, uint32_t a2)
{
    return 0;
}

__int64 (*osub_447750)(__int64 a1, __int64 a2);
__int64 hsub_447750(__int64 a1, __int64 a2)
{
    return 0;
}

__int64 (*osub_461F04)(_BYTE *a1, int a2, __int64 a3, int a4);
__int64 hsub_461F04(_BYTE *a1, int a2, __int64 a3, int a4)
{
    return 0;
}

__int64 (*osub_471B68)(__int64 a1, int a2);
__int64 hsub_471B68(__int64 a1, int a2)
{
    return 0;
}

__int64 (*osub_47B5CC)();
__int64 hsub_47B5CC()
{
    return 0;
}

_QWORD *(*osub_4D4C94)(int a1, int a2);
_QWORD *hsub_4D4C94(int a1, int a2)
{
    return nullptr;
}

void *(*osub_51F980)(void *dest, const void *src, size_t n);
void *hsub_51F980(void *dest, const void *src, size_t n)
{
    if (n == 0x140)
        return dest;
    return memcpy(dest, src, n);
}

void *(*osub_51F9A0)(void *s, int c, size_t n);
void *hsub_51F9A0(void *s, int c, size_t n)
{
    return memset(s, c, n);
}

__int64 (*osub_3A564C)(__int64 a1, uint64_t a2, void *a3, double a4);
__int64 hsub_3A564C(__int64 a1, uint64_t a2, void *a3, double a4)
{
    return 0;
}

void *(*osub_46ED30)(__int64 a1, FILE *a2, uint32_t *a3);
void *hsub_46ED30(__int64 a1, FILE *a2, uint32_t *a3)
{
    return nullptr;
}

__int64 (*osub_2328F0)(__int64 a1, const char *a2, __int64 a3);
__int64 hsub_2328F0(__int64 a1, const char *a2, __int64 a3)
{
    if (a2 && (strstr(a2, oxorany("crash")) || strstr(a2, oxorany("opcode")) ||
               strstr(a2, oxorany("kick")) || strstr(a2, oxorany("terminate")) ||
               strstr(a2, oxorany("ban"))))
        return 0;
    return osub_2328F0(a1, a2, a3);
}

__int64 (*osub_389744)(__int64 a1, _QWORD *a2, int a3, __int64 a4, __int64 a5);
__int64 hsub_389744(__int64 a1, _QWORD *a2, int a3, __int64 a4, __int64 a5)
{
    return 0;
} // case 34

__int64 (*osub_49AA00)(char *a1, __int64 a2);
__int64 hsub_49AA00(char *a1, __int64 a2)
{
    return 0;
} // runtime hash verifier

__int64 (*oAnoSDKInit)(__int64 result);
__int64 hAnoSDKInit(__int64 result) { return 0; }

__int64 (*oAnoSDKGetReportData)();
__int64 hAnoSDKGetReportData() { return 0; }

__int64 (*oAnoSDKOnRecvSignature)(_BYTE *a1, __int64 a2, uint32_t a3, int a4);
__int64 hAnoSDKOnRecvSignature(_BYTE *a1, __int64 a2, uint32_t a3, int a4) { return 0; }

typedef __int64(__fastcall *osub_451564_t)(__int64, __int64);
osub_451564_t osub_451564 = nullptr;

__int64 __fastcall hsub_451564(__int64 a1, __int64 a2)
{
    if (!a2)
        return 0LL;
    size_t sz = *(size_t *)(a2 + 240);
    if (sz > 0 && sz <= 32)
        memset((void *)(a2 + 248), 0, sz);
    return osub_451564(a1, a2);
}

__int64 (*osub_21E9C4)(__int64 a1, __int64 a2, __int64 a3, int a4, int a5) = nullptr;
void hsub_21E9C4(__int64 a1, __int64 a2, __int64 a3, int a4, int a5) { return; }

void (*osub_425864)(__int64 a1) = nullptr;
void hsub_425864(__int64 a1)
{
    if (a1)
    {
        *(uint8_t *)((uintptr_t)a1 + 0x48) = 0;
        *(uint8_t *)((uintptr_t)a1 + 0x60) = 0;
    }

    if (osub_425864)
        osub_425864(a1);
}

typedef __int64 (*sub_3A8DA8_a2_t)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64);

__int64 (*osub_3A8DA8)(
    __int64 a1,
    sub_3A8DA8_a2_t a2,
    int a3,
    __int64 a4,
    __int64 a5,
    __int64 a6,
    __int64 a7,
    __int64 a8,
    __int64 a9,
    __int64 a10,
    __int64 a11) = nullptr;

__int64 hsub_3A8DA8(
    __int64 a1,
    sub_3A8DA8_a2_t a2,
    int a3,
    __int64 a4,
    __int64 a5,
    __int64 a6,
    __int64 a7,
    __int64 a8,
    __int64 a9,
    __int64 a10,
    __int64 a11)
{
    // GOD FILTER: Master Caller Dispatcher
    switch (a3)
    {
        case 1: case 10: case 23: case 36: case 38: case 40: case 57:
            return 0;
        default:
            break;
    }
    if (osub_3A8DA8)
        return osub_3A8DA8(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    return 0;
}

__int64 (*osub_3FC5C8)(__int64 a1, __int64 a2, double a3);
__int64 __fastcall hsub_3FC5C8(__int64 a1, __int64 a2, double a3)
{
    if (!a1)
        return 0;

    // Surgical state clearing to prevent server-side termination signals
    *(_QWORD *)(a1 + 208) = 0;
    *(_QWORD *)(a1 + 224) = 0;
    *(_QWORD *)(a1 + 280) = 0;
    *(_QWORD *)(a1 + 288) = 0;

    return osub_3FC5C8(a1, a2, a3);
}

__int64 (*osub_37966C)(int *a1, __int64 a2);
__int64 hsub_37966C(int *a1, __int64 a2)
{
    if (a2 && *(_QWORD *)(a2 + 8))
    {
        *(_DWORD *)a2 = 0xFFFFFFFF;
        *(_DWORD *)(a2 + 4) = 0;
    }
    if (osub_37966C)
        return osub_37966C(a1, a2);
    return 0;
}

void (*osub_5003A4)(const char *a1, ...);
void hsub_5003A4(const char *a1, ...)
{
    // Anti-abort: prevents game closure during detection
    return;
}

__int64 __fastcall (*osub_3F9928)(__int64(__fastcall *a1)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64), __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9);

__int64 __fastcall hsub_3F9928(__int64(__fastcall *a1)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64), __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9)
{
    // GOD FILTER: Terminator Fixer (case 0x1E, 0x2E, 0x5B, 0x61, 0x6E, 0x6F)
    return 0;
}

__int64 (*osub_387FE4)(__int64 a1) = nullptr;
__int64 hsub_387FE4(__int64 a1) { return 0; } // case 1

__int64 (*osub_388464)(__int64 a1, __int64 a2) = nullptr;
__int64 hsub_388464(__int64 a1, __int64 a2) { return 0; } // case 10

__int64 (*osub_388A18)(__int64 a1, unsigned int a2) = nullptr;
__int64 hsub_388A18(__int64 a1, unsigned int a2) { return 0; } // case 23

__int64 (*osub_389C14)(__int64 a1, __int64 a2, __int64 a3, __int64 a4) = nullptr;
__int64 hsub_389C14(__int64 a1, __int64 a2, __int64 a3, __int64 a4) { return 0; } // case 36

__int64 (*osub_389FFC)(__int64 a1, __int64 a2, __int64 a3, ...) = nullptr;
__int64 hsub_389FFC(__int64 a1, __int64 a2, __int64 a3, ...) { return 0; } // case 38

__int64 (*osub_38A210)(__int64 a1, _QWORD *a2, int a3, __int64 a4, __int64 a5) = nullptr;
__int64 hsub_38A210(__int64 a1, _QWORD *a2, int a3, __int64 a4, __int64 a5) { return 0; } // case 40

__int64 (*osub_38C0D8)(__int64 a1, __int64 a2, __int64 a3, __int64 a4) = nullptr;
__int64 hsub_38C0D8(__int64 a1, __int64 a2, __int64 a3, __int64 a4) { return 0; } // case 57

__int64 (*osub_379220)(__int64 a1, const char *a2, const char *a3) = nullptr;
__int64 hsub_379220(__int64 a1, const char *a2, const char *a3)
{
    if (a2)
    {
        // FILTER: reporting nerve center - catches BGMI patch monitoring
        if (strstr(a2, oxorany("ms_data_crc")) ||
            strstr(a2, oxorany("ms_down_data")) ||
            strstr(a2, oxorany("ms_scan_start")))
            return 0;
    }
    return 0;
}

__int64 (*osub_3F99E8)(__int64 a1, __int64(__fastcall *a2)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64), double a3) = nullptr;
__int64 hsub_3F99E8(__int64 a1, __int64(__fastcall *a2)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64), double a3)
{
    return 0;
}

__int64 (*osub_431AD8)(__int64 a1, unsigned int a2) = nullptr;
__int64 hsub_431AD8(__int64 a1, unsigned int a2)
{
    return 0;
}

__int64 (*osub_375F54)(__int64 a1, const char *a2, int a3, unsigned int *a4, unsigned int *a5) = nullptr;
__int64 hsub_375F54(__int64 a1, const char *a2, int a3, unsigned int *a4, unsigned int *a5) { return 0; }

__int64 (*osub_381944)() = nullptr;
__int64 hsub_381944() { return 0; }

__int64 (*osub_46270C)(_BYTE *a1, unsigned int a2, __int64 a3, int a4) = nullptr;
__int64 hsub_46270C(_BYTE *a1, unsigned int a2, __int64 a3, int a4) { return 0; }

__int64 (*osub_4633F4)(_BYTE *a1, unsigned int a2, __int64 a3, int a4) = nullptr;
__int64 hsub_4633F4(_BYTE *a1, unsigned int a2, __int64 a3, int a4) { return 0; }

__int64 (*osub_4B39E0)(__int64 a1, const char *a2) = nullptr;
__int64 hsub_4B39E0(__int64 a1, const char *a2)
{
    if (a2)
    {
        // FILTER: string-based ban dispatcher - intercepts "TERMINATION PEL RHA HAI"
        if (strstr(a2, oxorany("Report")) ||
            strstr(a2, oxorany("Termination")) ||
            strstr(a2, oxorany("Kick")) ||
            strstr(a2, oxorany("Complaint")))
            return 0;
    }
    if (osub_4B39E0)
        return osub_4B39E0(a1, a2);
    return 0;
}

void *ue4_thread(void *)
{
    do
    {
        sleep(1);
    } while (!isLibraryLoaded("libUE4.so"));
#if defined(__aarch64__)
    PATCH_LIB("libUE4.so", "0x7A649A8", "00 00 80 D2 C0 03 5F D6"); // fake damage fixer
#endif
    return NULL;
}

void *anogs_thread(void *)
{
    do
    {
        sleep(1);
    } while (!isLibraryLoaded("libanogs.so"));

    HOOKSYM_LIB("libanogs.so", "AnoSDKInit", hAnoSDKInit, oAnoSDKInit);
    HOOKSYM_LIB("libanogs.so", "AnoSDKGetReportData", hAnoSDKGetReportData, oAnoSDKGetReportData);
    HOOKSYM_LIB("libanogs.so", "AnoSDKOnRecvSignature", hAnoSDKOnRecvSignature, oAnoSDKOnRecvSignature);

    HOOK_LIB("libanogs.so", "0x451564", hsub_451564, osub_451564); // fake hash returner
    HOOK_LIB("libanogs.so", "0x21248C", hsub_21248C, osub_21248C); // case 16 (crash fix)
    HOOK_LIB("libanogs.so", "0x228168", hsub_228168, osub_228168); // case 35
    HOOK_LIB("libanogs.so", "0x228560", hsub_228560, osub_228560); // case 37
    HOOK_LIB("libanogs.so", "0x389744", hsub_389744, osub_389744); // case 34
    HOOK_LIB("libanogs.so", "0x387FE4", hsub_387FE4, osub_387FE4); // case 1
    HOOK_LIB("libanogs.so", "0x388464", hsub_388464, osub_388464); // case 10
    HOOK_LIB("libanogs.so", "0x388A18", hsub_388A18, osub_388A18); // case 23
    HOOK_LIB("libanogs.so", "0x389C14", hsub_389C14, osub_389C14); // case 36
    HOOK_LIB("libanogs.so", "0x389FFC", hsub_389FFC, osub_389FFC); // case 38
    HOOK_LIB("libanogs.so", "0x38A210", hsub_38A210, osub_38A210); // case 40
    HOOK_LIB("libanogs.so", "0x38C0D8", hsub_38C0D8, osub_38C0D8); // case 57
    HOOK_LIB("libanogs.so", "0x37966C", hsub_37966C, osub_37966C); // reporter
    HOOK_LIB("libanogs.so", "0x375F54", hsub_375F54, osub_375F54); // suspicion
    HOOK_LIB("libanogs.so", "0x381944", hsub_381944, osub_381944); // suspicion
    HOOK_LIB("libanogs.so", "0x46270C", hsub_46270C, osub_46270C); // suspicion
    HOOK_LIB("libanogs.so", "0x4633F4", hsub_4633F4, osub_4633F4); // suspicion
    HOOK_LIB("libanogs.so", "0x379220", hsub_379220, osub_379220); // GOD FILTER: reporting
    HOOK_LIB("libanogs.so", "0x4B39E0", hsub_4B39E0, osub_4B39E0); // GOD FILTER: dispatcher
    HOOK_LIB("libanogs.so", "0x3F9928", hsub_3F9928, osub_3F9928); // terminator fixer
    HOOK_LIB("libanogs.so", "0x5003A4", hsub_5003A4, osub_5003A4); // Anti-abort
    HOOK_LIB("libanogs.so", "0x2940D0", hsub_2940D0, osub_2940D0);
    HOOK_LIB("libanogs.so", "0x425864", hsub_425864, osub_425864); // memory master
    HOOK_LIB("libanogs.so", "0x3A8DA8", hsub_3A8DA8, osub_3A8DA8); // master caller
    HOOK_LIB("libanogs.so", "0x3FC5C8", hsub_3FC5C8, osub_3FC5C8); // master caller
    HOOK_LIB("libanogs.so", "0x3F99E8", hsub_3F99E8, osub_3F99E8);
    HOOK_LIB("libanogs.so", "0x431AD8", hsub_431AD8, osub_431AD8);
    HOOK_LIB("libanogs.so", "0x21E9C4", hsub_21E9C4, osub_21E9C4); // new hook
    HOOK_LIB("libanogs.so", "0x49AA00", hsub_49AA00, osub_49AA00); // runtime hash verifier
    HOOK_LIB("libanogs.so", "0x36A5B8", hsub_36A5B8, osub_36A5B8);
    HOOK_LIB("libanogs.so", "0x39F56C", hsub_39F56C, osub_39F56C);
    HOOK_LIB("libanogs.so", "0x447750", hsub_447750, osub_447750);
    HOOK_LIB("libanogs.so", "0x461F04", hsub_461F04, osub_461F04);
    HOOK_LIB("libanogs.so", "0x471B68", hsub_471B68, osub_471B68);
    HOOK_LIB("libanogs.so", "0x47B5CC", hsub_47B5CC, osub_47B5CC);
    HOOK_LIB("libanogs.so", "0x4D4C94", hsub_4D4C94, osub_4D4C94);
    HOOK_LIB("libanogs.so", "0x3A564C", hsub_3A564C, osub_3A564C);
    HOOK_LIB("libanogs.so", "0x46ED30", hsub_46ED30, osub_46ED30);
    HOOK_LIB("libanogs.so", "0x2328F0", hsub_2328F0, osub_2328F0);
    HOOK_LIB("libanogs.so", "0x51F980", hsub_51F980, osub_51F980);
    HOOK_LIB("libanogs.so", "0x51F9A0", hsub_51F9A0, osub_51F9A0);
    PATCH_LIB("libanogs.so", "0x4B3560", "20 00 80 D2 C0 03 5F D6"); // Fix Crash
    PATCH_LIB("libanogs.so", "0x225528", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x31DCB0", "1F 20 03 D5");
    PATCH_LIB("libanogs.so", "0x330494", "E0 03 27 1E C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x362BF4", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x371418", "1F 20 03 D5");
    PATCH_LIB("libanogs.so", "0x37C904", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x431800", "20 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x46EFD0", "1F 20 03 D5");
    // PATCH_LIB("libanogs.so", "0x4B39E0", "00 00 80 D2 C0 03 5F D6"); // Hooked instead to avoid detection
    PATCH_LIB("libanogs.so", "0x4F7074", "E0 03 27 1E C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x232B28", "C0 03 5F D6"); // zeue4
    PATCH_LIB("libanogs.so", "0x213DC8", "C0 03 5F D6"); // zeue4
    return NULL;
}

__attribute__((constructor)) void mainload()
{
    pthread_t ptid;
    pthread_create(&ptid, NULL, anogs_thread, NULL);
    pthread_create(&ptid, NULL, ue4_thread, NULL);
}
