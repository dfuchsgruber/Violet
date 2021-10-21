/*
 * rock_climb.c
 *
 *  Created on: Sep 30, 2018
 *      Author: dominik
 */

#include "constants/block_hm_usage.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "debug.h"
#include "field_move.h"
#include "flags.h"
#include "oam.h"
#include "overworld/pokemon_party_menu.h"
#include "overworld/script.h"
#include "tile/block.h"
#include "tile/coordinate.h"
#include "types.h"
#include "vars.h"

void field_move_rock_climb_overworld() {
    *var_access(LASTRESULT) = pokemon_party_menu_get_current_index();
    overworld_script_init(ow_script_execute_rock_climb);
}

bool rock_climb_block_is_climbable() {
    position_t player_pos, faced_pos;
    player_get_position(&player_pos);
    player_get_position_faced(&faced_pos);
    if (player_pos.height == faced_pos.height || faced_pos.height == 0) {
        // Check if the adjacent tile is climbable
        u32 hm_usage = block_get_field_by_pos((s16)(faced_pos.coordinates.x),
                                              (s16)(faced_pos.coordinates.y), BDATA_HM_USAGE);
        dprintf("Check position %d, %d, rock climb: %d\n", faced_pos.coordinates.x,
                faced_pos.coordinates.y, hm_usage);
        return (hm_usage & HM_USAGE_ROCK_CLIMB) > 0;
    }
    return false;
}

bool field_move_check_rock_climb() {
    if (checkflag(FRBADGE_8) || true) {
        // Check if there is a dungeon to enter
        if (rock_climb_block_is_climbable()) {
            pokemon_party_menu_continuation = pokemon_party_menu_return_and_execute_field_move;
            field_move_overworld_continuation = field_move_rock_climb_overworld;
            return true;
        }
    }
    return false;
}
