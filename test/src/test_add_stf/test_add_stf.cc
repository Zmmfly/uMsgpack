#include "test_astf.h"

#define test(n) {.name = #n, .fn = tastf_nm(n)},
utils::test::unit_item t_astf_units[] = {
#include "test_def"
};
#undef test

#define test(n) __attribute__((weak)) tastf_def(n) {msg = "not implement";return false;}
#include "test_def"
#undef test

ump_handle_t t_astf_create_ump(const char* name)
{
    bool ret = false;
    ump_handle_t     hd = nullptr;
    ump_stream_file_t st = nullptr;
    do{
        hd = (ump_handle_t)calloc(1, sizeof(ump_handle));
        if (hd == nullptr) break;

        st = ump_st_file_create(name, &ump_memop_default);
        if (st == nullptr) break;
        if (ump_st_file_open(st, 0, false) != UMP_EOK) break;

        ump_init(hd, &st->stream);
        ret = true;
    }while(0);
    if (!ret && hd) {
        t_astf_destroy_ump(hd);
    }
    return hd;
}

void t_astf_destroy_ump(ump_handle_t hd)
{
    ump_stream_file_t st;
    if (hd == nullptr) return;
    if (hd->stream) {
        st = (ump_stream_file_t)hd->stream;
        ump_st_file_close(st);
        unlink(st->path);
        ump_st_file_destroy(st);
    }
    free(hd);
}
