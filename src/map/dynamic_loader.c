#include "types.h"
#include "romfuncs.h"
#include "oams.h"
#include "callbacks.h"
#include "battle.h"
#include "basestats.h"
#include "trainer.h"
#include "item.h"
#include "save.h"
#include <stdbool.h>
#include "unaligned_types.h"
#include "pokemon.h"
#include "map.h"
#include "dungeon_generator.h"

mapheader *get_mapheader(u8 bank, u8 map) {
    if (is_dungeon_map()) {
        //return (mapheader*)0x8350558;
        return compute_dungeon_header();
    } else {
        return ((*mapbank_table_ptr)[bank]).maps[map];
    }
}

mapfooter *get_mapfooter() {

    if (is_dungeon_map()) {
        compute_dungeon_blocks();
        return &(cmem->footer);
    }

    //return standard map header
    u16 current_footer = (*save1)->current_footer_id;
    if (current_footer) {
        return ((*main_map_table_ptr)[current_footer - 1]);
    }
    return (mapfooter*) 0;
}

bool is_dungeon_map() {
    return ((checkflag(FLAG_LOAD_DMAP))); // && map == 10 && bank == 0);
}