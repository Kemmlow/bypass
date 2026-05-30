__int64 (*osub_68CD2F4)(__int64 a1, __int64 a2);
__int64 (*osub_69CBE8C)(__int64 result, __int64 a2);

__int64 hsub_69CBE8C(__int64 result, __int64 a2)
{
    if (result)
    {
        *(_DWORD *)(result + 492) = 1;
        __int64 weapon = *(__int64 *)(result + 608);
        if (!weapon) *(__int64 *)(result + 608) = a2;
    }
    return osub_69CBE8C(result, a2);
}

__int64 hsub_68CD2F4(__int64 a1, __int64 a2)
{
    if (a1 && a2)
    {
        *(_QWORD *)(a1 + 496) = a2;
        return hsub_69CBE8C(a1, a2);
    }
    return osub_68CD2F4(a1, a2);
}
