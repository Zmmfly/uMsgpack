#include "uMsgpack.h"

int ump_init(ump_handle_t hd, ump_stream_t st)
{
    ump_err err = UMP_FAIL;
    do{
        if (hd == NULL || st == NULL) {
            err = UMP_ERR_NULLPTR;
            break;
        }

        hd->stream  = st;
        hd->err     = UMP_EOK;
        hd->dec_pos = 0;
        hd->dec_nxt = 0;

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_next(ump_handle_t hd, ump_type_t type)
{
    uint8_t be[8];
    union{
        uint8_t u8[2];
        uint16_t u16;
    }be16;
    union{
        uint8_t u8[4];
        uint32_t u32;
    }be32;
    uint8_t mtype;
    ump_err err = UMP_FAIL;
    do{
        if (ump_check_handle(hd) != UMP_EOK || type == NULL) {
            err = UMP_ERR_NULLPTR;
            break;
        }

        err = ump_st_seek(hd, hd->dec_nxt, UMP_SEEK_BEG);
        if (err != UMP_EOK) {
            break;
        }
        hd->dec_pos = hd->dec_nxt;

        err = ump_st_read(hd, 0, &mtype, 1, false);
        if (err != UMP_EOK) {
            break;
        }

        if (mtype >= 0x00 && mtype <= 0x7f) {
            *type       = ump_type_pfint;
            hd->dec_nxt = hd->dec_pos + 1;
            err         = UMP_EOK;
            break;
        }

        else if (mtype >= 0x80 && mtype <= 0x8f) {
            *type       = ump_type_fmap;
            hd->dec_nxt = hd->dec_pos + 1;
            err         = UMP_EOK;
            break;
        }

        else if (mtype >= 0x90 && mtype <= 0x9f) {
            *type       = ump_type_farr;
            hd->dec_nxt = hd->dec_pos + 1;
            err         = UMP_EOK;
            break;
        }

        else if (mtype >= 0xa0 && mtype <= 0xbf) {
            *type       = ump_type_fstr;
            hd->dec_nxt = hd->dec_pos + 1 + (mtype&0x1f);
            err         = UMP_EOK;
            break;
        }

        else if (mtype >= 0xe0 && mtype <= 0xff) {
            *type       = ump_type_nfint;
            hd->dec_nxt = hd->dec_pos + 1;
            err         = UMP_EOK;
            break;
        }

        else if (mtype == ump_type_nil || mtype == ump_type_false || mtype == ump_type_true) {
            hd->dec_nxt = hd->dec_pos + 1;
        }

        else if (mtype == ump_type_b8 || mtype == ump_type_s8) {
            err = ump_st_read(hd, 1, be, 1, false);
            if (err != UMP_EOK) {
                break;
            }
            hd->dec_nxt = hd->dec_pos + 2 + be[0];
        }

        else if (mtype == ump_type_b16 || mtype == ump_type_s16) {
            err = ump_st_read(hd, 1, be, 2, false);
            if (err != UMP_EOK) {
                break;
            }
            be16.u8[0] = be[1];
            be16.u8[1] = be[0];
            hd->dec_nxt = hd->dec_pos + 3 + be16.u16;
        }

        else if (mtype == ump_type_b32 || mtype == ump_type_s32) {
            err = ump_st_read(hd, 1, be, 4, false);
            if (err != UMP_EOK) {
                break;
            }
            be32.u8[0] = be[3];
            be32.u8[1] = be[2];
            be32.u8[2] = be[1];
            be32.u8[3] = be[0];
            hd->dec_nxt = hd->dec_pos + 5 + be32.u32;
        }

        else if (mtype == ump_type_e8) {
            err = ump_st_read(hd, 1, be, 1, false);
            if (err != UMP_EOK) {
                break;
            }
            hd->dec_nxt = hd->dec_pos + 3 + be[0];
        }

        else if (mtype == ump_type_e16) {
            err = ump_st_read(hd, 1, be, 2, false);
            if (err != UMP_EOK) {
                break;
            }
            be16.u8[0] = be[1];
            be16.u8[1] = be[0];
            hd->dec_nxt = hd->dec_pos + 4 + be16.u16;
        }

        else if (mtype == ump_type_e32) {
            err = ump_st_read(hd, 1, be, 4, false);
            if (err != UMP_EOK) {
                break;
            }
            be32.u8[0] = be[3];
            be32.u8[1] = be[2];
            be32.u8[2] = be[1];
            be32.u8[3] = be[0];
            hd->dec_nxt = hd->dec_pos + 6 + be32.u32;
        }

        else if (mtype == ump_type_f32) {
            hd->dec_nxt = hd->dec_pos + 5;
        }

        else if (mtype == ump_type_f64) {
            hd->dec_nxt = hd->dec_pos + 9;
        }

        else if (mtype == ump_type_u8 || mtype == ump_type_i8) {
            hd->dec_nxt = hd->dec_pos + 2;
        }

        else if (mtype == ump_type_u16 || mtype == ump_type_i16) {
            hd->dec_nxt = hd->dec_pos + 3;
        }

        else if (mtype == ump_type_u32 || mtype == ump_type_i32) {
            hd->dec_nxt = hd->dec_pos + 5;
        }

        else if (mtype == ump_type_u64 || mtype == ump_type_i64) {
            hd->dec_nxt = hd->dec_pos + 9;
        }

        else if (mtype == ump_type_fe1) {
            hd->dec_nxt = hd->dec_pos + 3;
        }

        else if (mtype == ump_type_fe2) {
            hd->dec_nxt = hd->dec_pos + 4;
        }

        else if (mtype == ump_type_fe4) {
            hd->dec_nxt = hd->dec_pos + 6;
        }

        else if (mtype == ump_type_fe8) {
            hd->dec_nxt = hd->dec_pos + 10;
        }

        else if (mtype == ump_type_fe16) {
            hd->dec_nxt = hd->dec_pos + 18;
        }

        else if (mtype == ump_type_a16 || mtype == ump_type_m16) {
            hd->dec_nxt = hd->dec_pos + 3;
        }

        else if (mtype == ump_type_a32 || mtype == ump_type_m32) {
            hd->dec_nxt = hd->dec_pos + 5;
        }

        else {
            err = UMP_ERR_UNKNOWN;
            break;
        }

        *type = mtype;
        err = UMP_EOK;
    }while(0);
    return err;
}

const char* ump_strerr(int umperr)
{
    switch(umperr) {
        case UMP_EOK:
            return "ump_strerr: ok";
        case UMP_EOF:
            return "ump_strerr: end of stream";
        case UMP_FAIL:
            return "ump_strerr: fail";
        case UMP_ERR_NULLPTR:
            return "ump_strerr: null pointer";
        case UMP_ERR_NOMEM:
            return "ump_strerr: no memory";
        case UMP_ERR_TYPE:
            return "ump_strerr: type error";
        case UMP_ERR_READ:
            return "ump_strerr: read error";
        case UMP_ERR_WRITE:
            return "ump_strerr: write error";
        case UMP_ERR_RANGEOVF:
            return "ump_strerr: range overflow";
        case UMP_ERR_INVALID_ARG:
            return "ump_strerr: invalid argument";
        case UMP_ERR_INVALID_TYPE:
            return "ump_strerr: invalid type";
        case UMP_ERR_INVALID_STREAM:
            return "ump_strerr: invalid stream";
        case UMP_ERR_INVALID_MEMOP:
            return "ump_strerr: invalid memory operation";
        case UMP_ERR_CLOSE4DECODE:
            return "ump_strerr: close for decode";
        case UMP_ERR_UNKNOWN:
            return "ump_strerr: unknown error";
        case UMP_ERR_UNSUPPORTED:
            return "ump_strerr: unsupported";
        default:
            return "ump_strerr: unhadled error";
    }
}
