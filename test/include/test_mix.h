#ifndef __TEST_MIX_H__
#define __TEST_MIX_H__

#include "utils/test.h"
#include "utils/hex.h"
#include <string>
#include <string.h>
#include "uMsgpack.h"

#define tmix_dec(n) int t_mix_fn_##n(std::string &msg);
#define tmix_def(n) int t_mix_fn_##n(std::string &msg)
#define tmix_nm(n) t_mix_fn_##n

#define mix(n) tmix_dec(n)
#include "test_mix"
#undef mix

#define mix(n) t_mix_##n,
typedef enum test_mix_item
{
    #include "test_mix"
    t_mix_num
}test_mix_item;
#undef mix

extern utils::test::unit_item t_mix_units[];

#endif // __TEST_MIX_H__