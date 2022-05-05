#include "test_add.h"

#define test(n) {.name = #n, .fn = t_add_fn_##n},
utils::test::unit_item t_add_units[] = {
#include "test_def"
};
#undef test

ump_handle_t t_add_create_ump()
{
    bool ret = false;
    ump_handle_t     hd = nullptr;
    ump_stream_mem_t st = nullptr;
    do{
        hd = new ump_handle;
        if (hd == nullptr) break;

        st = ump_st_mem_create(128, &ump_memop_default);
        if (st == nullptr) break;

        ump_init(hd, &st->stream);
        ret = true;
    }while(0);
    if (!ret && hd) {
        t_add_destroy_ump(hd);
    }
    return hd;
}

void t_add_destroy_ump(ump_handle_t hd)
{
    if (hd == nullptr) return;
    if (hd->stream) ump_st_mem_destroy((ump_stream_mem_t)hd->stream);
    delete hd;
}
