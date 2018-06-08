#include "types.h"
#include "oam.h"
#include "callbacks.h"
#include "save.h"
#include "map/header.h"
#include "dungeon2.h"
#include "constants/vars.h"
#include "vars.h"


mapheader *get_mapheader(u8 bank, u8 map) {
    if (dungeon_get_type()) {
        dungeon2_init();
        return &(fmem->dmapheader);
    } else {
        return mapbanks[bank][map];
    }
}

mapfooter *get_mapfooter() {

    if (dungeon_get_type()) {
        dungeon2_init();
        return &(fmem->dmapfooter);
    }

    //return standard map header
    u16 current_footer = (*save1)->current_footer_id;
    if (current_footer) {
        return mapfooters[current_footer - 1];
    }
    return (mapfooter*) 0;
}

int dungeon_get_type() {
    u16 *dtype = var_access(DUNGEON_TYPE);
    return *dtype;
}
