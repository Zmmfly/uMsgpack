#ifndef __TEST_GET_H__
#define __TEST_GET_H__

#include "utils/test.h"
#include "utils/hex.h"
#include <string>
#include <string.h>
#include "uMsgpack.h"

#define tget_dec(n) int t_get_fn_##n(std::string &msg);
#define tget_def(n) int t_get_fn_##n(std::string &msg)
#define tget_nm(n) t_get_fn_##n

#define test(n) tget_dec(n)
#include "test_def"
#undef test

#define test(n) t_get_##n,
typedef enum test_get_item
{
    #include "test_def"
    t_get_num
}test_get_item;
#undef test

extern utils::test::unit_item t_get_units[];
void t_get_destroy_ump(ump_handle_t hd);
ump_handle_t t_get_create_ump(void *ptr, size_t size);

#endif // __TEST_GET_H__