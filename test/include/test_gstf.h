#ifndef __TEST_GSTF_H__
#define __TEST_GSTF_H__

#include "utils/test.h"
#include "utils/hex.h"
#include <string>
#include <string.h>
#include "uMsgpack.h"

#define tgstf_dec(n) int t_gstf_fn_##n(std::string &msg);
#define tgstf_def(n) int t_gstf_fn_##n(std::string &msg)
#define tgstf_nm(n) t_gstf_fn_##n

#define test(n) tgstf_dec(n)
#include "test_def"
#undef test

#define test(n) t_gstf_##n,
typedef enum test_gstf_item
{
    #include "test_def"
    t_gstf_num
}test_gstf_item;
#undef test

extern utils::test::unit_item t_gstf_units[];
void t_gstf_destroy_ump(ump_handle_t hd);
ump_handle_t t_gstf_create_ump(const char* name, void *ptr, size_t size);

#endif // __TEST_GSTF_H__