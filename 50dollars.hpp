#ifndef FIFTYDOLLARS_HPP
#define FIFTYDOLLARS_HPP
typedef __int64 (*sub_dispatcher_a2_t)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64);
__int64 (*osub_3A8DA8)(__int64, sub_dispatcher_a2_t, int, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64) = nullptr;
__int64 hsub_3A8DA8(__int64 a1, sub_dispatcher_a2_t a2, int a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9, __int64 a10, __int64 a11) {
    return 0;
}
HOOK_LIB("libanogs.so", "0x3A8DA8", hsub_3A8DA8, osub_3A8DA8);
#endif
