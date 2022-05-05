#include "utils/hex.h"

namespace utils
{
namespace hex
{

void dump(void *data, size_t size, std::string prefix, size_t group_size, size_t line_byte) 
{
    std::string str = prefix;
    char buf[3];
    size_t gpcnt = 0, linecnt = 0;
    for (size_t i = 0; i < size; i ++) {
        snprintf(buf, 3, "%02x", ((unsigned char *)data)[i]);
        str += buf;

        if (++gpcnt == group_size) {
            str   += " ";
            gpcnt  = 0;
        }

        if (++linecnt == line_byte) {
            str += "\n";
            linecnt = 0;
            printf("%s", str.c_str());
            str = prefix;
        }
    }
    if (linecnt) {
        str += "\n";
        printf("%s", str.c_str());
    }
}

}}
