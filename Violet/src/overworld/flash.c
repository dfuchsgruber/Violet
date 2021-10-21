#include "constants/attacks.h"
#include "constants/flags.h"
#include "constants/levelscript_types.h"
#include "debug.h"
#include "flags.h"
#include "map/header.h"
#include "options.h"
#include "overworld/map_control.h"
#include "overworld/pokemon_party_menu.h"
#include "save.h"
#include "types.h"
#include "vars.h"

bool map_flash_usable() {
    return !checkflag(FLASH_USED) && get_mapheader(save1->bank, save1->map)->flash_type;
}

u8 player_pokemon_get_highest_level_flash_user() {
    int highest_level = -1;
    u8 idx = 6;
    for (u8 i = 0; i < player_pokemon_cnt; i++) {
        if (pokemon_get_attribute(player_pokemon + i, ATTRIBUTE_SPECIES, 0)) {
            int level = pokemon_get_attribute(player_pokemon + i, ATTRIBUTE_LEVEL, 0);
            if (level <= highest_level)
                continue;
            for (int j = 0; j < 4; j++) {
                if (pokemon_get_attribute(player_pokemon + i, (u16)(ATTRIBUTE_ATTACK1 + j), 0) == ATTACK_BLITZ) {
                    highest_level = level;
                    idx = i;
                    break;
                }
            }
        }
    }
    if (idx < 6) {
        pokemon_party_menu_current_index = idx;
    }
    dprintf("Highest flash user level is for index %d\n", idx);
    return idx;
}

bool player_pokemon_has_flash() {
    return player_pokemon_get_highest_level_flash_user() < 6;
}

bool map_flash_try_automatic_usage() {
    if (map_flash_usable() && checkflag(FRBADGE_1) && automatic_hm_usage_active() && player_pokemon_has_flash()) {
        return true;
    }
    return false;
}

void overworld_get_flash_level() {
    int flash_level = 3;
    int level = pokemon_get_attribute(player_pokemon + pokemon_party_menu_current_index, ATTRIBUTE_LEVEL, 0);
    if (level > 15)
        flash_level--;
    if (level > 25)
        flash_level--;
    if (level > 50)
        flash_level--;
    dprintf("Set flash level to %d because user has level %d\n", flash_level, level);
    *var_access(LASTRESULT) = (u16)MAX(0, flash_level);
}
