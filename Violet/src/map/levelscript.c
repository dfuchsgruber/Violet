#include "types.h"
#include "overworld/script.h"
#include "map/levelscript.h"
#include "dungeon/dungeon2.h"
#include "save.h"
#include "debug.h"
#include "constants/levelscript_types.h"
#include "map/cloud.h"
#include "achievements.h"

EWRAM const u8 *additional_levelscript_4 = NULL;

void map_init_levelscript_4() {
    DEBUG("Additional levelscript 4 0x%x\n", additional_levelscript_4);
    const u8 *a = additional_levelscript_4;
    if (a) {
        overworld_script_init_muted(a);
        additional_levelscript_4 = NULL;
    }
    const u8 *s = map_levelscript_get_if_triggered(LEVELSCRIPT_TYPE_ON_WARP_INTO_MAP_TABLE);
    if (s) {
        overworld_script_init_muted(s);
    }
}

void map_init_levelscript_1() {
	// Apply map changes due to dungeons on map
	map_levelscript_init_no_var_check(LEVELSCRIPT_TYPE_ON_LOAD);
}

extern const u8 ow_script_automatic_flash_usage[];

bool map_init_levelscript_2_on_frame() {
    // Dump all the questlog bs...
    // First check if there are actual levelscripts
    const u8 *lscr = map_levelscript_get_if_triggered(LEVELSCRIPT_TYPE_ON_FRAME_TABLE);
    if (lscr) {
        overworld_script_init(lscr);
        return true;
    }
    if (map_flash_try_automatic_usage()) {
        overworld_script_init(ow_script_automatic_flash_usage);
        return true;
    }
    u8 group_idx, achievement_idx;
    if (achievements_get_issued_unlocked_message_group_idx(&group_idx, &achievement_idx)) {
        // Handle the case where there's an issued unlocked message for a specific achievement group
        achievements_set_current(group_idx, achievement_idx);
        overworld_script_init(ow_script_achievement_unlocked);
        return true;
    }
    return false;
}

void map_init_levelscript_on_transition() {
	map_levelscript_init_no_var_check(LEVELSCRIPT_TYPE_ON_TRANSITION);
}

void map_init_levelscript_7_on_return_to_overworld() {
    achievements_compute_unlocked_message_issued();
    map_levelscript_init_no_var_check(LEVELSCRIPT_TYPE_ON_RETURN_TO_OVERWORLD);
}
