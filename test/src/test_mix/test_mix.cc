#include "test_mix.h"

#define mix(n) {.name = #n, .fn = tmix_nm(n)},
utils::test::unit_item t_mix_units[] = {
#include "test_mix"
};
#undef mix

#define mix(n) __attribute__((weak)) tmix_def(n) {msg = "not implement";return false;}
#include "test_mix"
#undef mix
