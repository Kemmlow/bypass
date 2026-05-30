__int64 (*osub_8241084)(__int64 result);
__int64 hsub_8241084(__int64 result)
{
    if (result && (uintptr_t)result > 0x1000)
    {
        uintptr_t base = Tools::GetBaseAddress("libUE4.so");
        if (base)
        {
            __int64 ctx = *(__int64 *)(base + 0xE114258);
            if (ctx && (uintptr_t)ctx > 0x1000)
            {
                *(_DWORD *)(result + 44) = 0;
                *(_DWORD *)(result + 48) = 0;
                *(_BYTE *)(result + 52) = 0;
            }
        }
    }
    return osub_8241084(result);
}
HOOK_LIB("libUE4.so", "0x8241084", hsub_8241084, (void**)&osub_8241084); // developer mode detection fixer
