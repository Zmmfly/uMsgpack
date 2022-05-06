# uMsgpack
Embedded friendly lightweight Messagepack implemented in C language.

# License
1. [AGPL V3.0](/LICENSE)
2. [AEL V0.1](/LICENSE_AEL)

# Todo
- [x] Implementation plan
- [x] In development
- [x] Mini usable version
- [ ] File stream
- [ ] First full version
- [ ] Follow-up maintenance

## Development progress
- [x] Utils
- [x] Stream for mem
- [x] API for add
- [x] API for get
- [x] Test for add
- [x] Test for get
- [x] Test for mixed
- [ ] Stream for file
- [ ] Complete

# Build
- require [xmake](https://xmake.io/#/)

```bash
# The static library will put into ./dist directory.
$ xmake

# Build and run test
$ xmake -b ump_test
$ xmake run ump_test
```

# Example
```bash
# build
$ xmake -b simple
# run
$ xmake run simple
d9 0c 48 65 6c 6c 6f 20 57 6f 72 6c 64 21

```

```c
#include "uMsgpack.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    ump_handle handle;
    ump_stream_mem_t st  = NULL;
    uint8_t*         buf = NULL;
    uint64_t         sz  = 0;

    /* Reset uMsgpack handle */
    memset(&handle, 0x00, sizeof(ump_handle));
    do{
        /* Create memory stream */
        st = ump_st_mem_create(128, &ump_memop_default);
        if (st == NULL) break;

        /* Initialize uMsgpack handle */
        ump_init(&handle, &st->stream);

        /* Add str8 */
        ump_add_str8(&handle, "Hello World!", 12);

        /* Get buffer ptr */
        buf = ump_st_mem_get_buf(st, &sz);

        /* Make sure buf not NULL, and size rather than zero. */
        if (buf == NULL || sz == 0) break;

        for (size_t i=0; i<sz; i++) 
        {
            printf("%02x ", buf[i]);
        }
        printf("\n");

    }while(0);
    if (st) {
        ump_st_mem_destroy(st);
    }
    return 0;
}

```
