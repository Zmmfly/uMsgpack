#ifndef __U_MSGPACK_H__
#define __U_MSGPACK_H__

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum fmp_opcode
{
    FMP_OP_RD,
    FMP_OP_WR,
    FMP_OP_SEEK,
    FMP_OP_TELL,
    FMP_OP_REQMEM,
    FMP_OP_DONE,
    FMP_OP_MAX
} fmp_opcode;

typedef struct fmp_opargs_rd
{
    void *ptr;
    size_t len;
} fmp_opargs_rd;
typedef fmp_opargs_rd *fmp_opargs_rd_t;

typedef fmp_opargs_rd fmp_opargs_wr;
typedef fmp_opargs_rd_t fmp_opargs_wr_t;

typedef struct fmp_opargs_seek
{
    size_t pos;
    uint8_t dir;
    size_t len;
} fmp_opargs_seek;

typedef struct fmp_opargs_tell
{
    uint8_t dir;
    size_t *out;
} fmp_opargs_tell;

typedef size_t fmp_opargs_reqmem;

//DONE have no args;

typedef struct fmp_vecport
{
    void *usr_arg;
    bool (*port_fn)(fmp_vecport *vec_handle, fmp_opcode opcode, void *args);
} fmp_vecport;
typedef fmp_vecport *fmp_vecport_t;

typedef struct fmp_handle
{
    fmp_vecport *vecport;
    bool auto_reduce;
} fmp_handle;
typedef fmp_handle *fmp_handle_t;

bool fmp_init(fmp_handle_t hd, fmp_vecport_t vecport, bool auto_reduce);

bool fmp_add_u8(fmp_handle_t hd, uint8_t u8);
bool fmp_add_i8(fmp_handle_t hd, int8_t i8);

bool fmp_add_u16(fmp_handle_t hd, uint16_t u16);
bool fmp_add_i16(fmp_handle_t hd, int16_t i16);

bool fmp_add_u32(fmp_handle_t hd, uint32_t u32);
bool fmp_add_i32(fmp_handle_t hd, int32_t i32);

bool fmp_add_u64(fmp_handle_t hd, uint64_t u64);
bool fmp_add_i64(fmp_handle_t hd, int64_t i64);

bool fmp_add_bin(fmp_handle_t hd, void *ptr, size_t len);

bool fmp_add_ext(fmp_handle_t hd, void *ptr, size_t len, uint8_t type);

bool fmp_add_pfixint(fmp_handle_t hd, int num);
bool fmp_add_fixmap(fmp_handle_t hd, uint8_t num);
bool fmp_add_fixarray(fmp_handle_t hd, uint8_t num);
bool fmp_add_fixstr(fmp_handle_t hd, char *str);
bool fmp_add_nil(fmp_handle_t hd);
bool fmp_add_bool(fmp_handle_t hd, bool in);
bool fmp_add_bin8(fmp_handle_t hd, void *ptr, uint8_t len);
bool fmp_add_bin16(fmp_handle_t hd, void *ptr, uint16_t);

#endif