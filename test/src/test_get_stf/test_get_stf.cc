#include <unistd.h>
#include "test_gstf.h"
#include <fstream>

#define test(n) {.name = #n, .fn = tgstf_nm(n)},
utils::test::unit_item t_gstf_units[] = {
#include "test_def"
};
#undef test

#define test(n) __attribute__((weak)) tgstf_def(n) {msg = "not implement";return false;}
#include "test_def"
#undef test

ump_handle_t t_gstf_create_ump(const char* name, void *ptr, size_t size)
{
    bool ret = false;
    ump_handle_t     hd = nullptr;
    ump_stream_file_t st = nullptr;
    do{
        hd = (ump_handle_t)calloc(1, sizeof(ump_handle));
        if (hd == nullptr) break;

        std::ofstream ofs(name, std::ios::binary | std::ios::out);
        if (!ofs.is_open()) break;
        ofs.write((char*)ptr, size);
        ofs.close();

        st = ump_st_file_create(name, &ump_memop_default);
        if (st == nullptr) break;

        if (ump_st_file_open(st, 0, false) != UMP_EOK) break;

        ump_init(hd, &st->stream);
        ret = true;
    }while(0);
    if (!ret && hd) {
        t_gstf_destroy_ump(hd);
    }
    return hd;
}

void t_gstf_destroy_ump(ump_handle_t hd)
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
