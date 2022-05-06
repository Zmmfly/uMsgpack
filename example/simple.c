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
