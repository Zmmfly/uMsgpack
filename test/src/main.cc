#include <stdio.h>
#include <string>

#include "test_add.h"
#include "utils/test.h"

int main(int argc, char **argv)
{
    utils::test::run_units(t_add_units, t_add_num, false, "add_test: ");
}
