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
#include "dungeon2.h"


mapheader *get_mapheader(u8 bank, u8 map) {
    if (dungeon_get_type()) {
        //return (mapheader*)0x8350558;
        //return compute_dungeon_header();
        //return dungeon2_init_header();
        return &(cmem->dmapheader);
    } else {
        return mapbanks[bank][map];
    }
}

mapfooter *get_mapfooter() {

    if (dungeon_get_type()) {
        //dungeon_compute_blocks();
        //dungeon2_compute();
        return &(cmem->dmapfooter);
    }

    //return standard map header
    u16 current_footer = (*save1)->current_footer_id;
    if (current_footer) {
        return mapfooters[current_footer - 1];
    }
    return (mapfooter*) 0;
}

int dungeon_get_type() {
    u16 *dtype = vardecrypt(DUNGEON_TYPE);
    return *dtype;
}