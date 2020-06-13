#include "types.h"
#include "overworld/sprite.h"
#include "color.h"
#include "constants/items.h"
#include "save.h"
#include "debug.h"
#include "flags.h"
#include "vars.h"
#include "agbmemory.h"
#include "prng.h"
#include "mushroom_and_shell.h"

// These special shells will spawn either shoal salt or shoal shell
static u16 shell_idx_with_shoal_salt_or_shoal_shell[] = {
    0x1337 // stub
};

u16 special_mushroom_get_stage() {
    return mushroom_get_stage(map_get_person((u8)(*var_access(LASTTALKED)), save1->map, save1->bank)->value);
}

u16 mushroom_get_stage(u16 mushroom_idx) {
    if (gp_flag_get(mushroom_idx, cmem.mushroom_flags))
        return MUSHROOM_TYPE_PLUCKED;
    u32 seq[1] = {mushroom_idx};
    u32 hash = daily_events_hash(seq, ARRAY_COUNT(seq)) ;
    u32 r = hash % 100;
    if (r < 20) {
        return MUSHROOM_TYPE_LARGE_MUSHROOM;
    } else {
        return MUSHROOM_TYPE_TINY_MUSHROOM;
    }
}

void mushroom_pluck() {
    map_event_person *p = map_get_person((u8)(*var_access(LASTTALKED)), save1->map, save1->bank);
    u16 mushroom_idx = p->value;
    gp_flag_set(mushroom_idx, cmem.mushroom_flags);
}

u16 special_shell_get_stage() {
    return shell_get_stage(map_get_person((u8)(*var_access(LASTTALKED)), save1->map, save1->bank)->value);
}

u16 shell_get_stage(u16 shell_idx) {
    if (gp_flag_get(shell_idx, cmem.shell_flags)) {
        return SHELL_TYPE_EMPTY;
    }
    u32 seq[1] = {shell_idx};
    u32 hash = daily_events_hash(seq, ARRAY_COUNT(seq));
    // Check if we have special shell
    bool special_shell = false;
    for(size_t i = 0; i < ARRAY_COUNT(shell_idx_with_shoal_salt_or_shoal_shell); i++) {
        if (shell_idx_with_shoal_salt_or_shoal_shell[i] == shell_idx) {
            special_shell = true;
            break;
        }
    }
    if (special_shell) {
        if ((hash % 2) == 0) {
            return SHELL_TYPE_SHOAL_SALT;
        } else {
            return SHELL_TYPE_SHOAL_SHELL;
        }
    } else {
        u32 r = hash % 100;
        if (r < 5) {
            return SHELL_TYPE_HEART_SCALE;
        } else if (r < 35) {
            return SHELL_TYPE_PEARL;
        } else if (r < 40) {
            return SHELL_TYPE_LARGE_PEARL;
        } else {
            return SHELL_TYPE_EMPTY; // Most of the shells are empty by design...
        }
    }
}

void shell_open() {
    map_event_person *p = map_get_person((u8)(*var_access(LASTTALKED)), save1->map, save1->bank);
    u16 shell_idx = p->value;
    gp_flag_set(shell_idx, cmem.shell_flags);
}

void mushroom_and_shell_regrow() {
    memset(cmem.mushroom_flags, 0, sizeof(cmem.mushroom_flags));
    memset(cmem.shell_flags, 0, sizeof(cmem.shell_flags));
}