#include "types.h"
#include "save.h"
#include "flags.h"
#include "debug.h"

bool gp_flag_get(u16 flag, u8 *flags) {
    return (flags[flag / 8] & (1 << (flag & 7))) != 0;
}

void gp_flag_set(u16 flag, u8 *flags) {
    flags[flag / 8] = (u8)(flags[flag / 8] | (1 << (flag & 7)));
}

void gp_flag_clear(u16 flag, u8 *flags) {
    flags[flag / 8] = (u8)(flags[flag / 8] & (~(1 << (flag & 7))));
}

u8 *flag_access_ext(u16 flag) {
    if(flag < 0xD00){
        int index = (flag - 0x900) / 8;
        return &(cmem.flag_extension[index]);
    } else if (flag < 0xF00) { // 0xD00 - 0xF00 are mapped to mushrooms
        int idx = (flag - 0xD00) / 8;
        return cmem.mushroom_flags + idx;
    } else if (flag < 0xF80) { // 0xF00 - 0xF80 are mapped to shells
        int idx = (flag - 0xF00) / 8;
        return cmem.shell_flags + idx;
    } else if (flag < 0x1000) { // 0xF80 - 0x1000 are mapped to trash cans
        int idx = (flag - 0xF80);
        return cmem.trash_flags + idx;
    } else {
        err2(ERR_FLAG_ACCESS_INVALID, flag);
        return NULL;
    }
}

u16 *var_access_ext(u16 var) {
    int index = var - 0x5000;
    return &(cmem.var_extension[index]);
}

bool checkflag(u16 flag) {

    if (flag >= 0x8000) return !checkflag((u16) (flag - 0x8000));
    u8 *off = flag_access(flag);
    if (off) {
        if (*off & (1 << (flag & 7))) return true;
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



