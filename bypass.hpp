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
    swprintf(buf, 33, L"%08X%08X%08X%08X", id[0], id[1], id[2], id[3]);
    void (*alloc)(__int64, unsigned int, unsigned int) = (void (*)(__int64, unsigned int, unsigned int))(libUE4Base + 0x5625AEC);
    *(_QWORD *)a1 = 0;
    *(_DWORD *)(a1 + 8) = 32;
    alloc(a1, 32, 0);
    memcpy(*(void **)a1, buf, 64);
    *(__int128 *)(libUE4Base + 0xE0DEAD0) = 0;
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
    swprintf(buf, 33, L"%08X%08X%08X%08X", id[0], id[1], id[2], id[3]);
    __int16* ptr = *(__int16**)(a3 + 0x58);
    if (ptr) memcpy(ptr, buf, 64);
    return res;
}

__int64 (*osub_C4E0330)(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5);
__int64 hsub_C4E0330(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5) {
    return 0;
}

__int64 (*osub_59C0EB8)(__int64 a1);
__int64 hsub_59C0EB8(__int64 a1) {
    return 0;
}

__int64 (*osub_68CD2F4)(__int64 a1, __int64 a2);
__int64 hsub_68CD2F4(__int64 a1, __int64 a2) {
    return 0;
}

__int64 (*osub_68CD7F0)(__int64 a1, __int64 a2, int *a3, __int64 a4);
__int64 hsub_68CD7F0(__int64 a1, __int64 a2, int *a3, __int64 a4) {
    return 0;
}

HOOK_LIB("libUE4.so", "0x81C2F70", hsub_81C2F70, osub_81C2F70); // hwid record
HOOK_LIB("libUE4.so", "0xC492610", hsub_C492610, osub_C492610); // hwid network
HOOK_LIB("libUE4.so", "0xC4E0330", hsub_C4E0330, osub_C4E0330); // anosdk god hook
HOOK_LIB("libUE4.so", "0x59C0EB8", hsub_59C0EB8, osub_59C0EB8); // move anticheat
HOOK_LIB("libUE4.so", "0x68CD2F4", hsub_68CD2F4, osub_68CD2F4); // security collector
HOOK_LIB("libUE4.so", "0x68CD7F0", hsub_68CD7F0, osub_68CD7F0); // bullet hit upload
PATCH_LIB("libUE4.so", "0x81C2F70", "00 00 80 D2 C0 03 5F D6"); // ban record kill
PATCH_LIB("libUE4.so", "0xCAB19B8", "00 00 80 D2 C0 03 5F D6"); // attack flow kill
PATCH_LIB("libUE4.so", "0xD573708", "00 00 80 D2 C0 03 5F D6"); // damage report kill
