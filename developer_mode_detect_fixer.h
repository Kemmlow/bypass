__int64 (*osub_8241084)(__int64 result);
__int64 hsub_8241084(__int64 result)
{
    if (result && (uintptr_t)result > 0x1000)
    {
        // surgically normalize the environmental context report
        // mask developer mode, adb status, and debugger presence
        *(_DWORD *)(result + 44) = 0;
        *(_DWORD *)(result + 48) = 0;
        *(_BYTE *)(result + 52) = 0;
    }
    return osub_8241084(result);
}
HOOK_LIB("libUE4.so", "0x8241084", hsub_8241084, (void**)&osub_8241084); // developer mode detection fixer
