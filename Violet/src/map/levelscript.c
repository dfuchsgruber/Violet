#include "types.h"
#include "overworld/script.h"
#include "map/levelscript.h"
#include "dungeon/dungeon2.h"
#include "save.h"
#include "debug.h"
#include "constants/levelscript_types.h"

void map_init_levelscript_4() {
    u8 *a = fmem.additional_levelscript_4;
    if (a) {
        overworld_script_init_muted(a);
        fmem.additional_levelscript_4 = NULL;
    }
    u8 *s = map_levelscript_get_if_triggered(LEVELSCRIPT_TYPE_ON_WARP_INTO_MAP_TABLE);
    if (s) {
        overworld_script_init_muted(s);
    }
}

void map_init_levelscript_1() {
	// Apply map changes due to dungeons on map
	dungeon_map_set_tiles();
	map_levelscript_init_no_var_check(1);
}

extern u8 ow_script_automatic_flash_usage[];

bool map_init_levelscript_2_on_frame() {
    // Dump all the questlog bs...
    // First check if there are actual levelscripts
    u8 *lscr = map_levelscript_get_if_triggered(LEVELSCRIPT_TYPE_ON_FRAME_TABLE);
    if (lscr) {
        overworld_script_init(lscr);
        return true;
    }
    if (map_flash_try_automatic_usage()) {
        overworld_script_init(ow_script_automatic_flash_usage);
        return true;
    }
    return false;
}