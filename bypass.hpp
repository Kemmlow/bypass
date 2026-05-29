__int16 *(*osub_81C2F70)(__int64 a1);
__int16 *hsub_81C2F70(__int64 a1) {
    struct sysinfo si;
    sysinfo(&si);
    srand(si.procs + si.totalram);
    uint32_t id[4];
    id[0] = (uint32_t)(si.uptime * 1000) ^ 0x55AA55AA;
    id[1] = (uint32_t)(si.totalram >> 12) | 0x10000;
    id[2] = (uint32_t)(si.loads[0] << 16) | (uint32_t)(si.procs & 0xFFFF);
    id[3] = (uint32_t)si.sharedram ^ 0xDEADBEEF;
    wchar_t buf[33];
    swprintf(buf, 32, L"%08X%08X%08X%08X", id[0], id[1], id[2], id[3]);
    void (*alloc)(__int64, unsigned int, unsigned int) = (void (*)(__int64, unsigned int, unsigned int))(libUE4Base + 0x5625AEC);
    *(_QWORD *)a1 = 0;
    *(_DWORD *)(a1 + 8) = 64;
    alloc(a1, 64, 0);
    memcpy(*(void **)a1, buf, 64);
    return (__int16 *)*(void **)a1;
}

bool (*osub_C492610)(__int64 a1, unsigned int a2, __int64 a3);
bool hsub_C492610(__int64 a1, unsigned int a2, __int64 a3) {
    bool res = osub_C492610(a1, a2, a3);
    struct sysinfo si;
    sysinfo(&si);
    uint32_t id[4];
    id[0] = (uint32_t)(si.uptime * 1000) ^ 0x55AA55AA;
    id[1] = (uint32_t)(si.totalram >> 12) | 0x10000;
    id[2] = (uint32_t)(si.loads[0] << 16) | (uint32_t)(si.procs & 0xFFFF);
    id[3] = (uint32_t)si.sharedram ^ 0xDEADBEEF;
    wchar_t buf[33];
    swprintf(buf, 32, L"%08X%08X%08X%08X", id[0], id[1], id[2], id[3]);
    __int16* ptr = *(__int16**)(a3 + 0x58);
    if (ptr) memcpy(ptr, buf, 64);
    return res;
}

__int64 (*osub_C4E0330)(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5);
__int64 hsub_C4E0330(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5) {
    return 0; // termination
}

void (*osub_82A8280)(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9);
void hsub_82A8280(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9) {
    return; // flag fix
}

__int64 (*osub_68CD2F4)(__int64 a1, __int64 a2);
__int64 hsub_68CD2F4(__int64 a1, __int64 a2) {
    return 0; // flag fix
}

__int64 (*osub_6F9FAC0)(__int64 a1, __int64 a2, __int64 *a3);
__int64 hsub_6F9FAC0(__int64 a1, __int64 a2, __int64 *a3) {
    return 0; // flag fix
}

__int64 (*osub_7ADAE8C)();
__int64 hsub_7ADAE8C() {
    return 0; // 10 years
}

HOOK_LIB("libUE4.so", "0x81C2F70", hsub_81C2F70, osub_81C2F70);                         // hwid spoofer (record spoofer)
HOOK_LIB("libUE4.so", "0xC492610", hsub_C492610, osub_C492610);                         // hwid spoofer (login request spoofer)
HOOK_LIB("libUE4.so", "0xC4E0330", hsub_C4E0330, osub_C4E0330);                         // termination
HOOK_LIB("libUE4.so", "0x82A8280", hsub_82A8280, osub_82A8280);                         // flag fix
HOOK_LIB("libUE4.so", "0x68CD2F4", hsub_68CD2F4, osub_68CD2F4);                         // flag fix
HOOK_LIB("libUE4.so", "0x6F9FAC0", hsub_6F9FAC0, osub_6F9FAC0);                         // flag fix
HOOK_LIB("libUE4.so", "0x7ADAE8C", hsub_7ADAE8C, osub_7ADAE8C);                         // 10 years
PATCH_LIB("libUE4.so", "0xCAB19B8", "00 00 80 D2 C0 03 5F D6");                         // flag fix
PATCH_LIB("libUE4.so", "0xD573708", "00 00 80 D2 C0 03 5F D6");                         // flag fix
PATCH_LIB("libUE4.so", "0x5ACC184", "00 00 80 D2 C0 03 5F D6");                         // termination
PATCH_LIB("libUE4.so", "0x7ADADB4", "00 00 80 D2 C0 03 5F D6");                         // 10 years
PATCH_LIB("libUE4.so", "0x7ADAE00", "00 00 80 D2 C0 03 5F D6");                         // 10 years
PATCH_LIB("libUE4.so", "0x7ADAE4C", "00 00 80 D2 C0 03 5F D6");                         // 10 years
PATCH_LIB("libUE4.so", "0x77DFF68", "00 00 80 D2 C0 03 5F D6");                         // flag delay
PATCH_LIB("libUE4.so", "0x59C0EB8", "00 00 80 D2 C0 03 5F D6");                         // violation
PATCH_LIB("libUE4.so", "0x7820930", "00 00 80 D2 C0 03 5F D6");                         // flag fix
PATCH_LIB("libUE4.so", "0x7820A08", "00 00 80 D2 C0 03 5F D6");                         // flag fix
PATCH_LIB("libUE4.so", "0x7820B2C", "00 00 80 D2 C0 03 5F D6");                         // flag fix
PATCH_LIB("libUE4.so", "0x7820BB8", "00 00 80 D2 C0 03 5F D6");                         // flag fix
PATCH_LIB("libUE4.so", "0x57A8EB4", "00 00 80 D2 C0 03 5F D6");                         // 10 years
