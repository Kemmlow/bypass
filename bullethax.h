__int64 (*osub_68CD2F4)(__int64 a1, __int64 a2);
__int64 (*osub_69CBE8C)(__int64 result, __int64 a2);

__int64 hsub_69CBE8C(__int64 result, __int64 a2)
{
    if (result && (uintptr_t)result > 0x1000)
    {
        // hyper-precise normalization of the final hit packet
        *(_DWORD *)(result + 492) = 1; // force valid status
        __int64 weapon = *(__int64 *)(result + 608);
        if (!weapon) *(__int64 *)(result + 608) = a2; // normalize weapon context
    }
    return osub_69CBE8C(result, a2);
}

__int64 hsub_68CD2F4(__int64 a1, __int64 a2)
{
    if (a1 && a2 && (uintptr_t)a1 > 0x1000)
    {
        // hyper-precise normalization of the hit component
        *(_QWORD *)(a1 + 496) = a2; // weapon pointer alignment
    }
    // call original to avoid recursion and maintain stack integrity
    return osub_68CD2F4(a1, a2);
}
