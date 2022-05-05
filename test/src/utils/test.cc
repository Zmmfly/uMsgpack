#include "utils/test.h"

namespace utils
{
namespace test
{

void result_output(std::string prefix, std::string name, bool pass, std::string msg = "")
{
    if (pass) {
        printf("%s%-20s: \033[32mPASS\033[0m\n", prefix.c_str(), name.c_str());
    } else {
        printf("%s%-20s: \033[31mFAIL\033[0m\n", prefix.c_str(), name.c_str());
    }

    if (!msg.empty()) {
        printf("%s\tmsg: \033[33m%s\033[0m\n", prefix.c_str(), msg.c_str());
    }
}

bool run_units(unit_item *units, size_t unit_cnt, bool exit_on_fail, std::string output_prefix)
{
    bool uret = false;
    std::string msg;
    if (units == nullptr) return false;
    for (unit_item* unit = units; unit < units + unit_cnt; unit ++) {
        if (unit->fn == nullptr) continue;
        msg.clear();
        uret = unit->fn(msg);
        result_output(output_prefix, unit->name, uret, msg);
        if (exit_on_fail && !uret) return false;
    }
    return true;
}

bool run_groups(unit_group *groups, size_t group_cnt, bool exit_on_fail, std::string output_prefix)
{
    bool unsret = false;
    for (unit_group* group = groups; group < groups + group_cnt; group ++) {
        unsret = run_units(group->items, group->item_cnt, exit_on_fail, output_prefix + group->name + ": ");
        if (!unsret && exit_on_fail) return false;
    }
    return true;
}

}}
