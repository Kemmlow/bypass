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
#define anogsLibrary oxorany("libanogs.so")

class _BYTE;
class _QWORD;
class _DWORD;
class _WORD;
#define _QWORD long
#define _DWORD long
#define _BYTE long
#define _WORD long

__int64 (*osub_493A18)(__int64 a1, __int64 a2, __int64 a3, ...);
__int64 hsub_493A18(__int64 a1, __int64 a2, __int64 a3, ...) { return 0; }

void (*osub_51F940)();
void hsub_51F940() { return; }

__int64 (*osub_3BBD00)();
__int64 hsub_3BBD00() { return 0; }

__int64 (*osub_5058AC)();
__int64 hsub_5058AC() { return 0; }

void (*osub_3F2104)();
void hsub_3F2104() { return; }

__int64 (*osub_4F7E28)();
__int64 hsub_4F7E28() { return 0; }

__int64 (*osub_4B6D8C)(__int64 a1, const char *a2, ...);
__int64 hsub_4B6D8C(__int64 a1, const char *a2, ...) { return 0; }

__int64 (*osub_48AE3C)();
__int64 hsub_48AE3C() { return 0; }

void (*osub_456EEC)();
void hsub_456EEC() { return; }

__int64 (*osub_4CA688)();
__int64 hsub_4CA688() { return 0; }

__int64 (*osub_4C11E4)(__int64 a1);
__int64 hsub_4C11E4(__int64 a1) { return 0; }

void (*osub_3A54F0)();
void hsub_3A54F0() { return; }

void (*osub_50137C)();
void hsub_50137C() { return; }

__int64 (*osub_393DE0)(__int64 a1);
__int64 hsub_393DE0(__int64 a1) { return 0; }

__int64 (*osub_404D14)();
__int64 hsub_404D14() { return 0; }

void (*osub_4E17CC)(__int64 a1);
void hsub_4E17CC(__int64 a1) { return; }

__int64 (*osub_425608)();
__int64 hsub_425608() { return 0; }

__int64 (*osub_2E7E60)(__int64 a1);
__int64 hsub_2E7E60(__int64 a1) { return 0; }

void (*osub_4B3E34)();
void hsub_4B3E34() { return; }

__int64 (*osub_3E80A8)();
__int64 hsub_3E80A8() { return 0; }

__int64 (*osub_4E58EC)(__int64 a1);
__int64 hsub_4E58EC(__int64 a1) { return 0; }

void (*osub_4EA870)();
void hsub_4EA870() { return; }

void (*osub_51C3E0)();
void hsub_51C3E0() { return; }

__int64 (*osub_3CA8B4)();
__int64 hsub_3CA8B4() { return 0; }

__int64 (*osub_4F10CC)();
__int64 hsub_4F10CC() { return 0; }

void (*osub_1D37A8)();
void hsub_1D37A8() { return; }

void (*osub_4ED6BC)();
void hsub_4ED6BC() { return; }

__int64 (*osub_1C79D4)();
__int64 hsub_1C79D4() { return 0; }

__int64 (*osub_487600)();
__int64 hsub_487600() { return 0; }

void (*osub_4D8950)();
void hsub_4D8950() { return; }

__int64 (*osub_317068)();
__int64 hsub_317068() { return 0; }

__int64 (*osub_47B5CC)();
__int64 hsub_47B5CC() { return 0; }

void (*osub_1CCA4C)();
void hsub_1CCA4C() { return; }

__int64 (*osub_515578)();
__int64 hsub_515578() { return 0; }

void (*osub_4DA95C)();
void hsub_4DA95C() { return; }

void (*osub_4E89C0)();
void hsub_4E89C0() { return; }

void (*osub_1EB98C)();
void hsub_1EB98C() { return; }

__int64 (*osub_1EF328)();
__int64 hsub_1EF328() { return 0; }

__int64 (*osub_32E308)();
__int64 hsub_32E308() { return 0; }

__int64 (*osub_23AEF4)();
__int64 hsub_23AEF4() { return 0; }

__int64 (*osub_4D66D4)();
__int64 hsub_4D66D4() { return 0; }

void (*osub_31DCA0)();
void hsub_31DCA0() { return; }

__int64 (*osub_3D3EE0)();
__int64 hsub_3D3EE0() { return 0; }

void (*osub_37B2EC)();
void hsub_37B2EC() { return; }

__int64 (*osub_1FE854)();
__int64 hsub_1FE854() { return 0; }

__int64 (*osub_3D9FD0)();
__int64 hsub_3D9FD0() { return 0; }

void (*osub_1E2830)();
void hsub_1E2830() { return; }

__int64 (*osub_489534)(__int64 a1);
__int64 hsub_489534(__int64 a1) { return 0; }

__int64 (*osub_230848)();
__int64 hsub_230848() { return 0; }

void (*osub_4B2C58)();
void hsub_4B2C58() { return; }

__int64 (*osub_4B5E48)(unsigned __int8 *a1, unsigned __int8 *a2, __int64 a3);
__int64 hsub_4B5E48(unsigned __int8 *a1, unsigned __int8 *a2, __int64 a3)
{
    if (a3 == 16 || a3 == 20 || a3 == 32) return 0;
    __int64 res = osub_4B5E48(a1, a2, a3);
    if (res != 0 && a3 > 8) return 0;
    return res;
}

__int64 (*osub_49AA00)(char *a1, __int64 a2);
__int64 hsub_49AA00(char *a1, __int64 a2) { return 0; }

__int64 (*osub_39F56C)(unsigned __int8 *a1, unsigned int a2);
__int64 hsub_39F56C(unsigned __int8 *a1, unsigned int a2) { return 0; }

__int64 (*osub_330494)(__int64 a1, unsigned int a2);
__int64 hsub_330494(__int64 a1, unsigned int a2) { return 0; }

__int64 (*osub_37C904)(__int64 a1, __int64 a2, __int64 *a3, unsigned int *a4);
__int64 hsub_37C904(__int64 a1, __int64 a2, __int64 *a3, unsigned int *a4) { return 0; }

__int64 (*osub_2124C8)(__int64 a1, char a2);
__int64 hsub_2124C8(__int64 a1, char a2)
{
    if (a1) { *(uint8_t *)(a1 + 112) = 1; return 0; }
    return osub_2124C8 ? osub_2124C8(a1, a2) : 0;
}

__int64 (*osub_228168)(__int64 a1, unsigned __int8 *a2, unsigned int a3);
__int64 hsub_228168(__int64 a1, unsigned __int8 *a2, unsigned int a3)
{
    if (a3 == 0x1A) return 0;
    return osub_228168 ? osub_228168(a1, a2, a3) : 0;
}

__int64 (*osub_404D50)(__int64 a1, __int64 a2);
__int64 hsub_404D50(__int64 a1, __int64 a2) { return 0; }

void (*osub_313810)(__int64 a1);
void hsub_313810(__int64 a1) { return; }

__int64 (*osub_37BC4C)(__int64 a1, __int64 a2, __int64 a3);
__int64 hsub_37BC4C(__int64 a1, __int64 a2, __int64 a3) { return 0; }

__int64 (*osub_2ECE70)(__int64 a1, __int64 a2);
__int64 hsub_2ECE70(__int64 a1, __int64 a2) { return 0; }

void (*osub_4690CC)(__int64 a1, __int64 a2);
void hsub_4690CC(__int64 a1, __int64 a2) { return; }

__int64 (*osub_50B808)(__int64 a1);
__int64 hsub_50B808(__int64 a1) { return 0; }

__int64 (*osub_320470)(__int64 a1, __int64 a2, __int64 a3);
__int64 hsub_320470(__int64 a1, __int64 a2, __int64 a3) { return 0; }

__int64 (*osub_35E5DC)(__int64 a1);
__int64 hsub_35E5DC(__int64 a1) { return 0; }

void (*osub_5026EC)(__int64 a1);
void hsub_5026EC(__int64 a1) { return; }

__int64 (*osub_37FD78)(__int64 a1, __int64 a2);
__int64 hsub_37FD78(__int64 a1, __int64 a2) { return 0; }

void *ue4_thread(void *)
{
    do { sleep(1); } while (!isLibraryLoaded("libUE4.so"));
#if defined(__aarch64__)
    PATCH_LIB("libUE4.so", "0x7A649A8", "00 00 80 D2 C0 03 5F D6"); // fake damage
#endif
    return NULL;
}

void *anogs_thread(void *)
{
    do { sleep(1); } while (!isLibraryLoaded("libanogs.so"));

    HOOK_LIB("libanogs.so", "0x493A18", hsub_493A18, osub_493A18); // 30 min termination
    HOOK_LIB("libanogs.so", "0x51F940", hsub_51F940, osub_51F940); // 30 min termination
    HOOK_LIB("libanogs.so", "0x3BBD00", hsub_3BBD00, osub_3BBD00); // 30 min termination
    HOOK_LIB("libanogs.so", "0x5058AC", hsub_5058AC, osub_5058AC); // 30 min termination
    HOOK_LIB("libanogs.so", "0x3F2104", hsub_3F2104, osub_3F2104); // branch bypass
    HOOK_LIB("libanogs.so", "0x4F7E28", hsub_4F7E28, osub_4F7E28); // call bypass
    HOOK_LIB("libanogs.so", "0x4B6D8C", hsub_4B6D8C, osub_4B6D8C); // trace bypass
    HOOK_LIB("libanogs.so", "0x48AE3C", hsub_48AE3C, osub_48AE3C); // debug bypass
    HOOK_LIB("libanogs.so", "0x456EEC", hsub_456EEC, osub_456EEC); // check bypass
    HOOK_LIB("libanogs.so", "0x4CA688", hsub_4CA688, osub_4CA688); // auth bypass
    HOOK_LIB("libanogs.so", "0x4C11E4", hsub_4C11E4, osub_4C11E4); // logic bypass
    HOOK_LIB("libanogs.so", "0x3A54F0", hsub_3A54F0, osub_3A54F0); // flow bypass
    HOOK_LIB("libanogs.so", "0x50137C", hsub_50137C, osub_50137C); // jump bypass
    HOOK_LIB("libanogs.so", "0x393DE0", hsub_393DE0, osub_393DE0); // crypt bypass
    HOOK_LIB("libanogs.so", "0x404D14", hsub_404D14, osub_404D14); // sync bypass
    HOOK_LIB("libanogs.so", "0x4E17CC", hsub_4E17CC, osub_4E17CC); // thread bypass
    HOOK_LIB("libanogs.so", "0x425608", hsub_425608, osub_425608); // mem bypass
    HOOK_LIB("libanogs.so", "0x2E7E60", hsub_2E7E60, osub_2E7E60); // state bypass
    HOOK_LIB("libanogs.so", "0x4B3E34", hsub_4B3E34, osub_4B3E34); // loop bypass
    HOOK_LIB("libanogs.so", "0x3E80A8", hsub_3E80A8, osub_3E80A8); // call bypass
    HOOK_LIB("libanogs.so", "0x4E58EC", hsub_4E58EC, osub_4E58EC); // sign bypass
    HOOK_LIB("libanogs.so", "0x4EA870", hsub_4EA870, osub_4EA870); // verify bypass
    HOOK_LIB("libanogs.so", "0x51C3E0", hsub_51C3E0, osub_51C3E0); // monitor bypass
    HOOK_LIB("libanogs.so", "0x3CA8B4", hsub_3CA8B4, osub_3CA8B4); // alert bypass
    HOOK_LIB("libanogs.so", "0x4F10CC", hsub_4F10CC, osub_4F10CC); // report bypass
    HOOK_LIB("libanogs.so", "0x1D37A8", hsub_1D37A8, osub_1D37A8); // event bypass
    HOOK_LIB("libanogs.so", "0x4ED6BC", hsub_4ED6BC, osub_4ED6BC); // init bypass
    HOOK_LIB("libanogs.so", "0x1C79D4", hsub_1C79D4, osub_1C79D4); // block bypass
    HOOK_LIB("libanogs.so", "0x487600", hsub_487600, osub_487600); // auth bypass
    HOOK_LIB("libanogs.so", "0x4D8950", hsub_4D8950, osub_4D8950); // heart bypass
    HOOK_LIB("libanogs.so", "0x317068", hsub_317068, osub_317068); // sign bypass
    HOOK_LIB("libanogs.so", "0x47B5CC", hsub_47B5CC, osub_47B5CC); // key bypass
    HOOK_LIB("libanogs.so", "0x1CCA4C", hsub_1CCA4C, osub_1CCA4C); // calc bypass
    HOOK_LIB("libanogs.so", "0x515578", hsub_515578, osub_515578); // hash bypass
    HOOK_LIB("libanogs.so", "0x4DA95C", hsub_4DA95C, osub_4DA95C); // monitor bypass
    HOOK_LIB("libanogs.so", "0x4E89C0", hsub_4E89C0, osub_4E89C0); // sync bypass
    HOOK_LIB("libanogs.so", "0x1EB98C", hsub_1EB98C, osub_1EB98C); // check bypass
    HOOK_LIB("libanogs.so", "0x1EF328", hsub_1EF328, osub_1EF328); // sign bypass
    HOOK_LIB("libanogs.so", "0x32E308", hsub_32E308, osub_32E308); // alert bypass
    HOOK_LIB("libanogs.so", "0x23AEF4", hsub_23AEF4, osub_23AEF4); // call bypass
    HOOK_LIB("libanogs.so", "0x4D66D4", hsub_4D66D4, osub_4D66D4); // report bypass
    HOOK_LIB("libanogs.so", "0x31DCA0", hsub_31DCA0, osub_31DCA0); // event bypass
    HOOK_LIB("libanogs.so", "0x3D3EE0", hsub_3D3EE0, osub_3D3EE0); // thread bypass
    HOOK_LIB("libanogs.so", "0x37B2EC", hsub_37B2EC, osub_37B2EC); // auth bypass
    HOOK_LIB("libanogs.so", "0x1FE854", hsub_1FE854, osub_1FE854); // verify bypass
    HOOK_LIB("libanogs.so", "0x3D9FD0", hsub_3D9FD0, osub_3D9FD0); // monitor bypass
    HOOK_LIB("libanogs.so", "0x1E2830", hsub_1E2830, osub_1E2830); // loop bypass
    HOOK_LIB("libanogs.so", "0x489534", hsub_489534, osub_489534); // sign bypass
    HOOK_LIB("libanogs.so", "0x230848", hsub_230848, osub_230848); // alert bypass
    HOOK_LIB("libanogs.so", "0x4B2C58", hsub_4B2C58, osub_4B2C58); // flow bypass

    HOOK_LIB("libanogs.so", "0x4B5E48", hsub_4B5E48, osub_4B5E48); // memory comparer
    HOOK_LIB("libanogs.so", "0x49AA00", hsub_49AA00, osub_49AA00); // crc verifier
    HOOK_LIB("libanogs.so", "0x39F56C", hsub_39F56C, osub_39F56C); // checksum calculator
    HOOK_LIB("libanogs.so", "0x330494", hsub_330494, osub_330494); // state integrity
    HOOK_LIB("libanogs.so", "0x37C904", hsub_37C904, osub_37C904); // block allocator
    HOOK_LIB("libanogs.so", "0x2124C8", hsub_2124C8, osub_2124C8); // flag modifier
    HOOK_LIB("libanogs.so", "0x228168", hsub_228168, osub_228168); // type checker
    HOOK_LIB("libanogs.so", "0x404D50", hsub_404D50, osub_404D50); // integrity dispatcher
    HOOK_LIB("libanogs.so", "0x313810", hsub_313810, osub_313810); // reporting cleanup
    HOOK_LIB("libanogs.so", "0x37BC4C", hsub_37BC4C, osub_37BC4C); // memory validator
    HOOK_LIB("libanogs.so", "0x2ECE70", hsub_2ECE70, osub_2ECE70); // signature tracker
    HOOK_LIB("libanogs.so", "0x4690CC", hsub_4690CC, osub_4690CC); // heartbeat suppressor
    HOOK_LIB("libanogs.so", "0x50B808", hsub_50B808, osub_50B808); // profile verifier
    HOOK_LIB("libanogs.so", "0x320470", hsub_320470, osub_320470); // thread analyzer
    HOOK_LIB("libanogs.so", "0x35E5DC", hsub_35E5DC, osub_35E5DC); // library guard
    HOOK_LIB("libanogs.so", "0x5026EC", hsub_5026EC, osub_5026EC); // scan scheduler
    HOOK_LIB("libanogs.so", "0x37FD78", hsub_37FD78, osub_37FD78); // data obfuscator

    PATCH_LIB("libanogs.so", "0x228360", "C0 03 5F D6"); // init bypass
    PATCH_LIB("libanogs.so", "0x2AF2B4", "C0 03 5F D6"); // jump bypass
    PATCH_LIB("libanogs.so", "0x2AF350", "C0 03 5F D6"); // loop bypass
    PATCH_LIB("libanogs.so", "0x2AF3F0", "C0 03 5F D6"); // logic bypass
    PATCH_LIB("libanogs.so", "0x2AF41C", "C0 03 5F D6"); // flow bypass
    PATCH_LIB("libanogs.so", "0x2AF448", "C0 03 5F D6"); // branch bypass
    PATCH_LIB("libanogs.so", "0x2AF4D8", "C0 03 5F D6"); // call bypass
    PATCH_LIB("libanogs.so", "0x2AF568", "C0 03 5F D6"); // trace bypass
    PATCH_LIB("libanogs.so", "0x2AF594", "C0 03 5F D6"); // debug bypass
    PATCH_LIB("libanogs.so", "0x2AF5C0", "C0 03 5F D6"); // check bypass
    PATCH_LIB("libanogs.so", "0x2AF640", "C0 03 5F D6"); // auth bypass
    PATCH_LIB("libanogs.so", "0x2AF6C0", "C0 03 5F D6"); // sync bypass
    PATCH_LIB("libanogs.so", "0x2AF740", "C0 03 5F D6"); // key bypass
    PATCH_LIB("libanogs.so", "0x2AF7E0", "C0 03 5F D6"); // crypt bypass
    PATCH_LIB("libanogs.so", "0x2AF80C", "C0 03 5F D6"); // hash bypass
    PATCH_LIB("libanogs.so", "0x2AF838", "C0 03 5F D6"); // sign bypass
    PATCH_LIB("libanogs.so", "0x2AF8C8", "C0 03 5F D6"); // verify bypass
    PATCH_LIB("libanogs.so", "0x2AF958", "C0 03 5F D6"); // monitor bypass
    PATCH_LIB("libanogs.so", "0x2AF984", "C0 03 5F D6"); // alert bypass
    PATCH_LIB("libanogs.so", "0x2AF9B0", "C0 03 5F D6"); // report bypass
    PATCH_LIB("libanogs.so", "0x2AFA40", "C0 03 5F D6"); // event bypass
    PATCH_LIB("libanogs.so", "0x2CA678", "C0 03 5F D6"); // thread bypass
    PATCH_LIB("libanogs.so", "0x3DFA14", "C0 03 5F D6"); // dispatch bypass
    PATCH_LIB("libanogs.so", "0x3E4650", "C0 03 5F D6"); // switch bypass
    PATCH_LIB("libanogs.so", "0x3F9928", "C0 03 5F D6"); // call bypass
    PATCH_LIB("libanogs.so", "0x49AA3C", "C0 03 5F D6"); // check bypass

    return NULL;
}

__attribute__((constructor)) void mainload()
{
    pthread_t ptid;
    pthread_create(&ptid, NULL, anogs_thread, NULL);
    pthread_create(&ptid, NULL, ue4_thread, NULL);
}
