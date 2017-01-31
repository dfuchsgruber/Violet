#include "dungeon_generator.h"
#include "map.h"
#include "types.h"
#include "save.h"
#include "romfuncs.h"
#include "item.h"
#include "overworld_script.h"
#include "dungeon_generator.h"


static u8 earthquake_script [] = {
    O_SCRIPT_SETVAR(0x8004, 3),
    O_SCRIPT_SETVAR(0x8005, 3),
    O_SCRIPT_SETVAR(0x8006, 35),
    O_SCRIPT_SETVAR(0x8007, 5),
    O_SCRIPT_SPECIAL(0x136),
    O_SCRIPT_MSGBOX(0x8810281, 6),
    0x8e,
    O_SCRIPT_END
};

bool dungeon_crash() {

    s16 coordinates[2];
    get_current_tile_position(&coordinates[0], &coordinates[1]);
    if (is_dungeon_map()) {
        if (((*vardecrypt(0x50E1))++ >= 4 * (cmem->dgen.width + cmem->dgen.height)) ||
                get_block_info_behaviour(coordinates[0], coordinates[1]) == 0xB0) {
            init_script((void*) 0x8719D01);
            clearflag(FLAG_LOAD_DMAP);
            init_script(&earthquake_script);
            return true;
        }
    }
    return false;
}

bool special_dungeon_warpback() {

    warp_setup(cmem->dgen.from_bank, cmem->dgen.from_map, 0xFF, cmem->dgen.from_x, cmem->dgen.from_y);
    warp_setup_callbacks();
    script_wait_for_warp();
    script_halt();
    clearflag(0x910);
    return true;
}

void dungeon_store_current_pos() {
    u8 bank = (*save1)->bank;
    u8 map = (*save1)->map;
    cmem->dgen.from_bank = bank;
    cmem->dgen.from_map = map;
    cmem->dgen.from_x = (*save1)->x;
    cmem->dgen.from_y = (*save1)->y;
    cmem->dgen.facing = (u8) (*vardecrypt(0x800C));
    cmem->dhead.name_bank = ((*mapbank_table_ptr)[bank]).maps[map]->name_bank;
    cmem->dgen.initial_seed = (u32) (random_change_seed() | (random_change_seed() << 16));
}