#ifndef __TEST_STFILE_H__
#define __TEST_STFILE_H__

#include "utils/test.h"
#include "utils/hex.h"
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include "uMsgpack.h"

#define tastf_dec(n) int t_astf_fn_##n(std::string &msg);
#define tastf_def(n) int t_astf_fn_##n(std::string &msg)
#define tastf_nm(n) t_astf_fn_##n

#define test(n) tastf_dec(n)
#include "test_def"
#undef test

#define test(n) t_astf_##n,
typedef enum test_astf_item
{
    #include "test_def"
    t_astf_num
}test_astf_item;
#undef test

extern utils::test::unit_item t_astf_units[];
void t_astf_destroy_ump(ump_handle_t hd);
ump_handle_t t_astf_create_ump(const char* name);

#endif // __TEST_STFILE_H__
