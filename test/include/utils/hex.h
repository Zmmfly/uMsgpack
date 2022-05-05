#ifndef __UTILS_HEX_H__
#define __UTILS_HEX_H__

#include <string>

namespace utils
{
namespace hex
{

void dump(void *data, size_t size, std::string prefix = "hex: ", size_t group_size = 1, size_t line_byte = 16);

}
}

#endif