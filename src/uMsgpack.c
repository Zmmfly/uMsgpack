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
    union{
        uint8_t u8[8];
        uint64_t u64;
    }be64;
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

        err = ump_st_read(hd, 0, mtype, 1, false);
        if (err != UMP_EOK) {
            break;
        }

        if (mtype >= 0x00 && mtype <= 0x7f) {
            *type = ump_type_pfint;
            hd->dec_nxt = hd->dec_pos + 1;
        }

        else if (mtype >= 0x80 && mtype <= 0x8f) {
            *type = ump_type_fmap;
            hd->dec_nxt = hd->dec_pos + 1;
        }

        else if (mtype >= 0x90 && mtype <= 0x9f) {
            *type = ump_type_farr;
            hd->dec_nxt = hd->dec_pos + 1;
        }

        else if (mtype >= 0xa0 && mtype <= 0xbf) {
            *type = ump_type_fstr;
            hd->dec_nxt = hd->dec_pos + 1 + (mtype&0x1f);
        }

        else if (mtype >= 0xe0 && mtype <= 0xff) {
            *type = ump_type_nfint;
            hd->dec_nxt = hd->dec_pos + 1;
        }

        else if (mtype == ump_type_nil || mtype == ump_type_false || mtype == ump_type_true) {
            *type = mtype;
            hd->dec_nxt = hd->dec_pos + 1;
        }

        else if (mtype == ump_type_b8 || mtype == ump_type_s8) {
            *type = mtype;
            err = ump_st_read(hd, 1, be, 1, false);
            if (err != UMP_EOK) {
                break;
            }
            hd->dec_nxt = hd->dec_pos + 1 + be[0];
        }

        else if (mtype == ump_type_b16 || mtype == ump_type_s16) {
            *type = mtype;
            err = ump_st_read(hd, 1, be, 2, false);
            if (err != UMP_EOK) {
                break;
            }
            be16.u8[0] = be[1];
            be16.u8[1] = be[0];
            hd->dec_nxt = hd->dec_pos + 1 + be16.u16;
        }

        else if (mtype == ump_type_b32 || mtype == ump_type_s32) {
            *type = mtype;
            err = ump_st_read(hd, 1, be, 4, false);
            if (err != UMP_EOK) {
                break;
            }
            be32.u8[0] = be[3];
            be32.u8[1] = be[2];
            be32.u8[2] = be[1];
            be32.u8[3] = be[0];
            hd->dec_nxt = hd->dec_pos + 1 + be32.u32;
        }

        else if (mtype == ump_type_e8) {
            *type = mtype;
            err = ump_st_read(hd, 1, be, 1, false);
            if (err != UMP_EOK) {
                break;
            }
            hd->dec_nxt = hd->dec_pos + 3 + be[0];
        }

        else if (mtype == ump_type_e16) {
            *type = mtype;
            err = ump_st_read(hd, 1, be, 2, false);
            if (err != UMP_EOK) {
                break;
            }
            be16.u8[0] = be[1];
            be16.u8[1] = be[0];
            hd->dec_nxt = hd->dec_pos + 4 + be16.u16;
        }

        else if (mtype == ump_type_e32) {
            *type = mtype;
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
            *type == mtype;
            hd->dec_nxt = hd->dec_pos + 5;
        }

        else if (mtype == ump_type_f64) {
            *type = mtype;
            hd->dec_nxt = hd->dec_pos + 9;
        }

        else if (mtype == ump_type_u8 || mtype == ump_type_i8) {
            *type = mtype;
            hd->dec_nxt = hd->dec_pos + 2;
        }

        else if (mtype == ump_type_u16 || mtype == ump_type_i16) {
            *type = mtype;
            hd->dec_nxt = hd->dec_pos + 3;
        }

        else if (mtype == ump_type_u32 || mtype == ump_type_i32) {
            *type = mtype;
            hd->dec_nxt = hd->dec_pos + 5;
        }

        else if (mtype == ump_type_u64 || mtype == ump_type_i64) {
            *type = mtype;
            hd->dec_nxt = hd->dec_pos + 9;
        }

        else if (mtype == ump_type_fixe1) {
            *type = mtype;
            hd->dec_nxt = hd->dec_pos + 3;
        }

        else if (mtype == ump_type_fixe2) {
            *type == mtype;
            hd->dec_nxt = hd->dec_pos + 4;
        }

        else if (mtype == ump_type_fixe4) {
            *type = mtype;
            hd->dec_nxt = hd->dec_pos + 6;
        }

        else if (type == ump_type_fixe8) {
            *type = mtype;
            hd->dec_nxt = hd->dec_pos + 10;
        }

        else if (type == ump_type_a16 || type == ump_type_m16) {
            *type = mtype;
            hd->dec_nxt = hd->dec_pos + 3;
        }

        else if (type == ump_type_a32 || type == ump_type_m32) {
            *type = mtype;
            hd->dec_nxt = hd->dec_pos + 5;
        }

        else {
            err = UMP_ERR_UNKNOWN;
            break;
        }

        err = UMP_EOK;
    }while(0);
    return err;
}

