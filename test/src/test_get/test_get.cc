#include "test_get.h"

#define test(n) {.name = #n, .fn = tget_nm(n)},
utils::test::unit_item t_get_units[] = {
#include "test_def"
};
#undef test

#define test(n) __attribute__((weak)) tget_def(n) {msg = "not implement";return false;}
#include "test_def"
#undef test

ump_handle_t t_get_create_ump(void *ptr, size_t size)
{
    bool ret = false;
    ump_handle_t     hd = nullptr;
    ump_stream_mem_t st = nullptr;
    do{
        hd = (ump_handle_t)calloc(1, sizeof(ump_handle));
        if (hd == nullptr) break;

        st = ump_st_mem_create_with(ptr, size, &ump_memop_default);
        if (st == nullptr) break;

        ump_init(hd, &st->stream);
        ret = true;
    }while(0);
    if (!ret && hd) {
        t_get_destroy_ump(hd);
    }
    return hd;
}

void t_get_destroy_ump(ump_handle_t hd)
{
    if (hd == nullptr) return;
    if (hd->stream) ump_st_mem_destroy((ump_stream_mem_t)hd->stream);
    free(hd);
}
