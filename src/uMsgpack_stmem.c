#include "uMsgpack_stmem.h"

#ifdef CONFIG_UMSGPACK_DEFAULT_MEMOP
#include <stdlib.h>
ump_memop ump_memop_default = {
    .malloc = malloc,
    .calloc = calloc,
    .free   = free,
    .calloc = calloc
};
#endif

/**
 * @brief Create a ump_stream_mem
 * 
 * @param len The length of the buffer initalized
 * @param memop 
 * @return ump_stream_mem_t 
 */
ump_stream_mem_t ump_st_mem_create(uint64_t len, ump_memop_t memop)
{
    bool             valid  = false;
    ump_stream_mem_t mem_st = NULL;
    do{
        if (memop == NULL) break;
        if (memop->malloc == NULL || memop->calloc == NULL) break;
        if (memop->free == NULL || memop->realloc == NULL) break;

        // create mem stream
        mem_st = (ump_stream_mem_t)memop->calloc(1, sizeof(ump_stream_mem));
        if (mem_st == NULL) break;

        // init mem stream
        mem_st->buf = memop->malloc(len);
        if (mem_st->buf == NULL) break;
        mem_st->spc = len;
        mem_st->memop = memop;

        valid = true;
    }while(0);
    if (valid) return mem_st;
    if (mem_st) {
        if (mem_st->buf) {
            mem_st->memop->free(mem_st->buf);
        }
        mem_st->memop->free(mem_st);
        mem_st = NULL;
    }
    return mem_st;
}

/**
 * @brief Create a mem stream for a given buffer
 * @note This function does not copy or free the input buffer.
 * 
 * @param buf 
 * @param len 
 * @param memop 
 * @return ump_stream_mem_t 
 */
ump_stream_mem_t ump_st_mem_create_with(const void* buf, uint64_t len, ump_memop_t memop)
{
    bool             valid  = false;
    ump_stream_mem_t mem_st = NULL;
    do{
        if (buf == NULL || len == 0) break;
        if (memop == NULL) break;
        if (memop->malloc == NULL || memop->calloc == NULL) break;
        if (memop->free == NULL || memop->realloc == NULL) break;

        // create mem stream
        mem_st = (ump_stream_mem_t)memop->calloc(1, sizeof(ump_stream_mem));
        if (mem_st == NULL) break;

        // init mem stream
        mem_st->buf   = buf;
        mem_st->spc   = 0;
        mem_st->len   = len;
        mem_st->memop = memop;

        valid = true;
    }while(0);
    if (valid) return mem_st;
    if (mem_st) {
        if (mem_st->buf) {
            mem_st->memop->free(mem_st->buf);
        }
        mem_st->memop->free(mem_st);
        mem_st = NULL;
    }
    return mem_st;
}

/**
 * @brief Destroy a ump_stream_mem
 * @note This function will free the buffer if spc not zero.
 * 
 * @param st 
 * @return int 
 */
int ump_st_mem_destroy(ump_stream_mem_t st)
{
    ump_err err = UMP_FAIL;
    do{
        if (st == NULL) {
            err = UMP_ERR_NULLPTR;
            break;
        }
        if (st->memop == NULL) {
            err = UMP_ERR_INVALID_STREAM;
            break;
        }
        if (st->spc == 0) {
            st->memop->free(st->spc);
        }
        st->memop->free(st);
        err = UMP_EOK;
    }while(0);
    return err;
}
