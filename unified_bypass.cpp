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

__int64 (*osub_493A18)(__int64 a1);
__int64 hsub_493A18(__int64 a1) { return 0; }

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

__int64 (*osub_4B6D8C)(__int64 a1);
__int64 hsub_4B6D8C(__int64 a1) { return 0; }

__int64 (*osub_48AE3C)();
__int64 hsub_48AE3C() { return 0; }

void (*osub_456EEC)();
void hsub_456EEC() { return; }

__int64 (*osub_4CA688)();
__int64 hsub_4CA688() { return 0; }

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
    if (a1) { *(_BYTE *)(a1 + 112) = 1; return 0; }
    return osub_2124C8 ? osub_2124C8(a1, a2) : 0;
}

__int64 (*osub_228168)(__int64 a1, unsigned __int8 *a2, unsigned int a3);
__int64 hsub_228168(__int64 a1, unsigned __int8 *a2, unsigned int a3)
{
    if (a3 == 0x1A) return 0;
    return osub_228168 ? osub_228168(a1, a2, a3) : 0;
}

void *anogs_thread(void *)
{
    do { sleep(1); } while (!isLibraryLoaded("libanogs.so"));

    HOOK_LIB("libanogs.so", "0x493A18", hsub_493A18, osub_493A18); // dispatcher bypass
    HOOK_LIB("libanogs.so", "0x51F940", hsub_51F940, osub_51F940); // loop bypass
    HOOK_LIB("libanogs.so", "0x3BBD00", hsub_3BBD00, osub_3BBD00); // logic bypass
    HOOK_LIB("libanogs.so", "0x5058AC", hsub_5058AC, osub_5058AC); // flow bypass
    HOOK_LIB("libanogs.so", "0x3F2104", hsub_3F2104, osub_3F2104); // branch bypass
    HOOK_LIB("libanogs.so", "0x4F7E28", hsub_4F7E28, osub_4F7E28); // call bypass
    HOOK_LIB("libanogs.so", "0x4B6D8C", hsub_4B6D8C, osub_4B6D8C); // trace bypass
    HOOK_LIB("libanogs.so", "0x48AE3C", hsub_48AE3C, osub_48AE3C); // debug bypass
    HOOK_LIB("libanogs.so", "0x456EEC", hsub_456EEC, osub_456EEC); // check bypass
    HOOK_LIB("libanogs.so", "0x4CA688", hsub_4CA688, osub_4CA688); // auth bypass

    HOOK_LIB("libanogs.so", "0x4B5E48", hsub_4B5E48, osub_4B5E48); // memory comparer
    HOOK_LIB("libanogs.so", "0x49AA00", hsub_49AA00, osub_49AA00); // crc verifier
    HOOK_LIB("libanogs.so", "0x39F56C", hsub_39F56C, osub_39F56C); // checksum calculator
    HOOK_LIB("libanogs.so", "0x330494", hsub_330494, osub_330494); // state integrity
    HOOK_LIB("libanogs.so", "0x37C904", hsub_37C904, osub_37C904); // block allocator
    HOOK_LIB("libanogs.so", "0x2124C8", hsub_2124C8, osub_2124C8); // flag modifier
    HOOK_LIB("libanogs.so", "0x228168", hsub_228168, osub_228168); // type checker

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
}
