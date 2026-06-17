bool (*osub_382768)();
bool hsub_382768() {
    return true;
}
HOOK_LIB("libanogs.so", "0x382768", hsub_382768, osub_382768);
