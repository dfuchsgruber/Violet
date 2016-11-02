#include "types.h"
#include "save.h"
#include "romfuncs.h"

u8 *flag_access_ext(u16 flag) {
    int index = (flag - 0x900) / 8;
    return &(cmem->flag_extension[index]);
}

u16 *var_access_ext(u16 var) {
    int index = var - 0x5000;
    return &(cmem->var_extension[index]);
}

bool checkflag(u16 flag) {

    if (flag >= 0x8000) return !checkflag((u16) (flag - 0x8000));
    u8 *off = flag_access(flag);
    if (off) {
        u8 mask = (u8) (1 << (flag & 7));
        if (*off & mask) return true;
    }
    return false;
}

void setflag(u16 flag) {

    if (flag >= 0x8000) {
        clearflag((u16) (flag - 0x8000));
    } else {
        u8 *off = flag_access(flag);
        if (off) {
            u8 mask = (u8) (1 << (flag & 7));
            *off |= mask;
        }
    }
}

void clearflag(u16 flag) {

    if (flag >= 0x8000) {
        setflag((u16) (flag - 0x8000));
    } else {
        u8 *off = flag_access(flag);
        if (off) {
            u8 mask = (u8) (~(1 << (flag & 7)));
            *off &= mask;
        }
    }
}



