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
#include <sys/sysinfo.h>
#include <unwind.h>
#include <libgen.h>
#include <stdint.h>
#include <functional>
#include <sys/stat.h>
#include <fcntl.h>
#include <android/log.h>

#include "Tools.h"
#include "oxorany.h"
#include "Macros.h"

#define targetLibName oxorany("libanogs.so")

typedef uint64_t _QWORD;
typedef uint32_t _DWORD;
typedef uint16_t _WORD;
typedef uint8_t _BYTE;

// Helper for UTF-16 hex formatting (UE4 compatible)
void format_hex_utf16(uint16_t* out, uint32_t* ids) {
    const char* hex = "0123456789ABCDEF";
    for (int i = 0; i < 4; i++) {
        uint32_t val = ids[i];
        for (int j = 7; j >= 0; j--) {
            out[i * 8 + j] = (uint16_t)hex[val & 0xF];
            val >>= 4;
        }
    }
}

// --- libanogs.so Hooks ---

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
    if (a2 && (strstr(a2, oxorany("crash")) || strstr(a2, oxorany("opcode"))))
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

// --- libUE4.so Hooks ---

__int16 *(*osub_81C2F70)(__int64 a1);
__int16 *hsub_81C2F70(__int64 a1)
{
    struct sysinfo si;
    if (::sysinfo(&si) != 0) return nullptr;
    srand(si.procs + si.totalram);
    uint32_t id[4];
    id[0] = (uint32_t)(si.uptime * 1000) ^ 0x55AA55AA;
    id[1] = (uint32_t)(si.totalram >> 12) | 0x10000;
    id[2] = (uint32_t)(si.loads[0] << 16) | (uint32_t)(si.procs & 0xFFFF);
    id[3] = (uint32_t)si.sharedram ^ 0xDEADBEEF;

    uint16_t buf[32];
    format_hex_utf16(buf, id);

    void (*alloc)(__int64, unsigned int, unsigned int) = (void (*)(__int64, unsigned int, unsigned int))(Tools::GetBaseAddress("libUE4.so") + 0x5625AEC);
    *(_QWORD *)a1 = 0;
    *(_DWORD *)(a1 + 8) = 64;
    alloc(a1, 64, 0);
    memcpy(*(void **)a1, buf, 64);
    return (__int16 *)*(void **)a1;
}

bool (*osub_C492610)(__int64 a1, unsigned int a2, __int64 a3);
bool hsub_C492610(__int64 a1, unsigned int a2, __int64 a3)
{
    bool res = osub_C492610(a1, a2, a3);
    struct sysinfo si;
    if (::sysinfo(&si) != 0) return res;
    uint32_t id[4];
    id[0] = (uint32_t)(si.uptime * 1000) ^ 0x55AA55AA;
    id[1] = (uint32_t)(si.totalram >> 12) | 0x10000;
    id[2] = (uint32_t)(si.loads[0] << 16) | (uint32_t)(si.procs & 0xFFFF);
    id[3] = (uint32_t)si.sharedram ^ 0xDEADBEEF;

    uint16_t buf[32];
    format_hex_utf16(buf, id);

    __int16 *ptr = *(__int16 **)(a3 + 0x58);
    if (ptr)
        memcpy(ptr, buf, 64);
    return res;
}

__int64 (*osub_C4E0330)(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5);
__int64 hsub_C4E0330(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
    return 0; // termination
}

void (*osub_82A8280)(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9);
void hsub_82A8280(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9)
{
    return; // flag fix
}

__int64 (*osub_7ADAE8C)();
__int64 hsub_7ADAE8C()
{
    return 0; // 10 years
}

int *(*osub_81FF6F4)(int *result, uint16_t *src, int a3);
int *hsub_81FF6F4(int *result, uint16_t *src, int a3)
{
    if (src && a3 >= 20)
    {
        const uint16_t target[] = {'l','o','g','i','n','-','i','d','e','n','t','i','f','i','e','r','.','t','x','t'};
        bool match = true;
        for(int i=0; i<20; i++) {
            if(src[i] != target[i]) { match = false; break; }
        }
        if (match) return nullptr;
    }
    return osub_81FF6F4(result, src, a3);
}

// Hyper Precise Bullet Registration God Hook
__int64 (*osub_68CD2F4)(__int64 a1, __int64 a2);
__int64 hsub_68CD2F4(__int64 a1, __int64 a2)
{
    if (!a1 || !a2) return 0;

    // Normalization: Ensure weapon state is synchronized
    *(_QWORD *)(a1 + 496) = a2;

    // God Bypass: Call the internal UE4 packet pusher directly
    // This skips the entire middle section of 0x68CD2F4 which triggers security reports
    typedef __int64 (*Pusher_t)(__int64, __int64);
    Pusher_t pusher = (Pusher_t)(Tools::GetBaseAddress("libUE4.so") + 0x69CBE8C);
    return pusher(a1, a2);
}

// God Event Filter: Silently drop specific security reports
__int64 (*osub_84DCE80)(__int64 result, __int64 a2, int a3);
__int64 hsub_84DCE80(__int64 result, __int64 a2, int a3)
{
    if (a2) {
        uintptr_t base = Tools::GetBaseAddress("libUE4.so");
        // Compare the event string address directly (Hyper Precision)
        if (a2 == (base + 0xD573708) || a2 == (base + 0xCAB19B8)) {
            return 0; // Silently drop the report
        }
    }
    return osub_84DCE80(result, a2, a3);
}

void *ue4_thread(void *)
{
    do
    {
        sleep(1);
    } while (!isLibraryLoaded("libUE4.so"));
#if defined(__aarch64__)
    // Premium God Hooks - Bullet Issues FIXED, Reports BLOCKED
    HOOK_LIB("libUE4.so", "0x68CD2F4", hsub_68CD2F4, osub_68CD2F4);
    HOOK_LIB("libUE4.so", "0x84DCE80", hsub_84DCE80, osub_84DCE80);

    PATCH_LIB("libUE4.so", "0x7A649A8", "00 00 80 D2 C0 03 5F D6"); // fake damage fix
    PATCH_LIB("libUE4.so", "0x69913E0", "00 00 80 D2 C0 03 5F D6"); // accuracy fix

    // HWID & Identity
    HOOK_LIB("libUE4.so", "0x81C2F70", hsub_81C2F70, osub_81C2F70);
    HOOK_LIB("libUE4.so", "0xC492610", hsub_C492610, osub_C492610);
    HOOK_LIB("libUE4.so", "0x81FF6F4", hsub_81FF6F4, osub_81FF6F4);

    // Global Anti-Cheat Dispatchers
    HOOK_LIB("libUE4.so", "0xC4E0330", hsub_C4E0330, osub_C4E0330);
    HOOK_LIB("libUE4.so", "0x82A8280", hsub_82A8280, osub_82A8280);

    // Security Orchestration
    HOOK_LIB("libUE4.so", "0x7ADAE8C", hsub_7ADAE8C, osub_7ADAE8C);
    PATCH_LIB("libUE4.so", "0x5ACC184", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x7ADADB4", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x7ADAE00", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x7ADAE4C", "00 00 80 D2 C0 03 5F D6");

    // Movement & Environment
    PATCH_LIB("libUE4.so", "0x77DFF68", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x59C0EB8", "00 00 80 D2 C0 03 5F D6");

    // Security Collectors
    PATCH_LIB("libUE4.so", "0x7820930", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x7820A08", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x7820B2C", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x7820BB8", "00 00 80 D2 C0 03 5F D6");

    // Server-Side Kick & Flag Bypasses
    PATCH_LIB("libUE4.so", "0x640B598", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x62E286C", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x74B1BC0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x776AFF8", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libUE4.so", "0x761CD04", "00 00 80 D2 C0 03 5F D6");
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

    HOOK_LIB("libanogs.so", "0x451564", hsub_451564, osub_451564);
    HOOK_LIB("libanogs.so", "0x21248C", hsub_21248C, osub_21248C);
    HOOK_LIB("libanogs.so", "0x228168", hsub_228168, osub_228168);
    HOOK_LIB("libanogs.so", "0x228560", hsub_228560, osub_228560);
    HOOK_LIB("libanogs.so", "0x389744", hsub_389744, osub_389744);
    HOOK_LIB("libanogs.so", "0x2940D0", hsub_2940D0, osub_2940D0);
    HOOK_LIB("libanogs.so", "0x425864", sub_425864, osub_425864);
    HOOK_LIB("libanogs.so", "0x21E9C4", hsub_21E9C4, osub_21E9C4);
    HOOK_LIB("libanogs.so", "0x49AA00", hsub_49AA00, osub_49AA00);
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
    PATCH_LIB("libanogs.so", "0x4B3560", "20 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x225528", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x31DCB0", "1F 20 03 D5");
    PATCH_LIB("libanogs.so", "0x330494", "E0 03 27 1E C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x362BF4", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x371418", "1F 20 03 D5");
    PATCH_LIB("libanogs.so", "0x37C904", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x431800", "20 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x46EFD0", "1F 20 03 D5");
    PATCH_LIB("libanogs.so", "0x4B39E0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4F7074", "E0 03 27 1E C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x51F9C0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x51FAB0", "20 00 80 D2 C0 03 5F D6");
    return NULL;
}

__attribute__((constructor)) void mainload()
{
    pthread_t ptid;
    pthread_create(&ptid, NULL, anogs_thread, NULL);
    pthread_create(&ptid, NULL, ue4_thread, NULL);
}
