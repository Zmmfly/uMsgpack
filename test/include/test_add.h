#ifndef __TEST_ADD_H__
#define __TEST_ADD_H__

#include "utils/test.h"
#include "utils/hex.h"
#include <string>
#include <string.h>
#include "uMsgpack.h"

#define tadd_dec(n) int t_add_fn_##n(std::string &msg);
#define tadd_def(n) int t_add_fn_##n(std::string &msg)
#define tadd_nm(n) t_add_fn_##n

#define test(n) tadd_dec(n)
#include "test_def"
#undef test

#define test(n) t_add_##n,
typedef enum test_add_item
{
    #include "test_def"
    t_add_num
}test_add_item;
#undef test

extern utils::test::unit_item t_add_units[];
void t_add_destroy_ump(ump_handle_t hd);
ump_handle_t t_add_create_ump();

#endif // __TEST_ADD_H__