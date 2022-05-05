#include <stdio.h>
#include <string>

#include "test_add.h"
#include "test_get.h"
#include "utils/test.h"

int main(int argc, char **argv)
{
    utils::test::run_units(t_add_units, t_add_num, false, "add_test: ");
    utils::test::run_units(t_get_units, t_get_num, false, "get_test: ");
    return 0;
}
