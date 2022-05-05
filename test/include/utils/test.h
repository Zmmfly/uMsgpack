#ifndef __UTILS_TEST_H__
#define __UTILS_TEST_H__

#include <string>

namespace utils
{
namespace test
{

typedef enum result_t{
    TEST_OK,
    TEST_FAIL,
    TEST_SKIP,
    TEST_MAX
} result_t;

typedef int(*unit_fn_t)(std::string &msg);

typedef struct unit_item
{
    std::string name;
    unit_fn_t   fn;
}unit_item;

typedef struct unit_group
{
    std::string name;
    unit_item*  items;
    size_t      item_cnt;
}unit_group;

bool run_units(unit_item *units, size_t unit_cnt, bool exit_on_fail = true, std::string output_prefix = "");
bool run_groups(unit_group *groups, size_t group_cnt, bool exit_on_fail = true, std::string output_prefix = "");

}
}

#endif