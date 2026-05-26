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

__int64 (*osub_4B5E48)(unsigned __int8 *a1, unsigned __int8 *a2, __int64 a3);
__int64 hsub_4B5E48(unsigned __int8 *a1, unsigned __int8 *a2, __int64 a3)
{
    if (a3 == 16 || a3 == 20 || a3 == 32) return 0;
    __int64 res = osub_4B5E48 ? osub_4B5E48(a1, a2, a3) : 0;
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
void (*osub_1F64D8)(int a1, int a2, unsigned __int8 *a3);
void hsub_1F64D8(int a1, int a2, unsigned __int8 *a3) { return; }
__int64 (*osub_4F5604)(__int64 a1, _BYTE *a2);
__int64 hsub_4F5604(__int64 a1, _BYTE *a2) { return 0; }
void (*osub_1F9028)(__int64 a1);
void hsub_1F9028(__int64 a1) { return; }
__int64 (*osub_4B5F64)(void *a1, void *a2);
__int64 hsub_4B5F64(void *a1, void *a2) { return 1; }
void (*osub_4DB148)(__int64 a1);
void hsub_4DB148(__int64 a1) { return; }
__int64 (*osub_4EEA08)(void *a1);
__int64 hsub_4EEA08(void *a1) { return 0; }
__int64 (*osub_461F04)(_BYTE *a1, int a2, __int64 a3, int a4);
__int64 hsub_461F04(_BYTE *a1, int a2, __int64 a3, int a4) { return 0; }
__int64 (*osub_471B68)(__int64 a1, int a2);
__int64 hsub_471B68(__int64 a1, int a2) { return 0; }
__int64 (*osub_447750)(__int64 a1, __int64 a2);
__int64 hsub_447750(__int64 a1, __int64 a2) { return 0; }
_QWORD *(*osub_4D4C94)(int a1, int a2);
_QWORD *hsub_4D4C94(int a1, int a2) { return nullptr; }
__int64 (*osub_1CCA7C)(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, int a9);
__int64 hsub_1CCA7C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, int a9) { return 0; }
__int64 (*osub_404D14)();
__int64 hsub_404D14() { return 0; }

void *ue4_thread(void *)
{
    do { sleep(1); } while (!isLibraryLoaded("libUE4.so"));
#if defined(__aarch64__)
    PATCH_LIB("libUE4.so", "0x7A649A8", "00 00 80 D2 C0 03 5F D6");
#endif
    return NULL;
}

void *anogs_thread(void *)
{
    do { sleep(1); } while (!isLibraryLoaded("libanogs.so"));

    HOOK_LIB("libanogs.so", "0x4B5E48", hsub_4B5E48, osub_4B5E48);
    HOOK_LIB("libanogs.so", "0x49AA00", hsub_49AA00, osub_49AA00);
    HOOK_LIB("libanogs.so", "0x39F56C", hsub_39F56C, osub_39F56C);
    HOOK_LIB("libanogs.so", "0x330494", hsub_330494, osub_330494);
    HOOK_LIB("libanogs.so", "0x37C904", hsub_37C904, osub_37C904);
    HOOK_LIB("libanogs.so", "0x2124C8", hsub_2124C8, osub_2124C8);
    HOOK_LIB("libanogs.so", "0x228168", hsub_228168, osub_228168);
    HOOK_LIB("libanogs.so", "0x404D50", hsub_404D50, osub_404D50);
    HOOK_LIB("libanogs.so", "0x313810", hsub_313810, osub_313810);
    HOOK_LIB("libanogs.so", "0x37BC4C", hsub_37BC4C, osub_37BC4C);
    HOOK_LIB("libanogs.so", "0x2ECE70", hsub_2ECE70, osub_2ECE70);
    HOOK_LIB("libanogs.so", "0x4690CC", hsub_4690CC, osub_4690CC);
    HOOK_LIB("libanogs.so", "0x50B808", hsub_50B808, osub_50B808);
    HOOK_LIB("libanogs.so", "0x320470", hsub_320470, osub_320470);
    HOOK_LIB("libanogs.so", "0x35E5DC", hsub_35E5DC, osub_35E5DC);
    HOOK_LIB("libanogs.so", "0x5026EC", hsub_5026EC, osub_5026EC);
    HOOK_LIB("libanogs.so", "0x37FD78", hsub_37FD78, osub_37FD78);
    HOOK_LIB("libanogs.so", "0x1F64D8", hsub_1F64D8, osub_1F64D8);
    HOOK_LIB("libanogs.so", "0x4F5604", hsub_4F5604, osub_4F5604);
    HOOK_LIB("libanogs.so", "0x1F9028", hsub_1F9028, osub_1F9028);
    HOOK_LIB("libanogs.so", "0x4B5F64", hsub_4B5F64, osub_4B5F64);
    HOOK_LIB("libanogs.so", "0x4DB148", hsub_4DB148, osub_4DB148);
    HOOK_LIB("libanogs.so", "0x4EEA08", hsub_4EEA08, osub_4EEA08);
    HOOK_LIB("libanogs.so", "0x461F04", hsub_461F04, osub_461F04);
    HOOK_LIB("libanogs.so", "0x471B68", hsub_471B68, osub_471B68);
    HOOK_LIB("libanogs.so", "0x447750", hsub_447750, osub_447750);
    HOOK_LIB("libanogs.so", "0x4D4C94", (void *)hsub_4D4C94, (void **)&osub_4D4C94);
    HOOK_LIB("libanogs.so", "0x1CCA7C", hsub_1CCA7C, osub_1CCA7C);
    HOOK_LIB("libanogs.so", "0x404D14", hsub_404D14, osub_404D14);

    PATCH_LIB("libanogs.so", "0x493A18", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x51F940", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x3BBD00", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x5058AC", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x3F2104", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4F7E28", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4B6D8C", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x48AE3C", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x456EEC", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4CA688", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4C11E4", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x3A54F0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x50137C", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x393DE0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4E17CC", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x425608", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2E7E60", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4B3E34", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x3E80A8", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4E58EC", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4EA870", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x51C3E0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x3CA8B4", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4F10CC", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1D37A8", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4ED6BC", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x487600", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4D8950", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x317068", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x47B5CC", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1CCA4C", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x515578", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4DA95C", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4E89C0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1EF328", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x32E308", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4D66D4", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x31DCA0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x3D3EE0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x1FE854", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x3D9FD0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x230848", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4B3560", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x225528", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x228168", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x228560", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2328F0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x31DCB0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x330494", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x362BF4", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x371418", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x37C904", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x39F56C", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x3A564C", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x431800", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x461F04", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x46EFD0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x471B68", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x47B5CC", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4B39E0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4D4C94", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x4F7074", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x51F9A0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x51F9C0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x51FA20", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x51FAB0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x228360", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AF2B4", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AF350", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AF3F0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AF41C", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AF448", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AF4D8", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AF568", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AF594", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AF5C0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AF640", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AF6C0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AF740", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AF7E0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AF80C", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AF838", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AF8C8", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AF958", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AF984", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AF9B0", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2AFA40", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x2CA678", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x3DFA14", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x3E4650", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x3F9928", "00 00 80 D2 C0 03 5F D6");
    PATCH_LIB("libanogs.so", "0x49AA3C", "00 00 80 D2 C0 03 5F D6");

    return NULL;
}

__attribute__((constructor)) void mainload()
{
    pthread_t ptid;
    pthread_create(&ptid, NULL, anogs_thread, NULL);
    pthread_create(&ptid, NULL, ue4_thread, NULL);
}
