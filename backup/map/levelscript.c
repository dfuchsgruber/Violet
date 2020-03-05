#include "types.h"
#include "overworld/script.h"
#include "map/levelscript.h"
#include "dungeon/dungeon2.h"
#include "save.h"
#include "debug.h"

void map_init_levelscript_4() {
    u8 *a = fmem.additional_levelscript_4;
    if (a) {
        overworld_script_init_muted(a);
        fmem.additional_levelscript_4 = NULL;
    }
    u8 *s = map_levelscript_get_if_triggered(4);
    if (s) {
        overworld_script_init_muted(s);
    }
}

void map_init_levelscript_1() {
	// Apply map changes due to dungeons on map
	dungeon_map_set_tiles();
	map_levelscript_init_no_var_check(1);

	//void (*fun)(int) = (void(*)(int)) 0x08069BB1;
	//fun(1);

}
