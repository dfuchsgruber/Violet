#include "types.h"
#include "transparency.h"
#include "debug.h"
#include "battle/battler.h"
#include "battle/state.h"
#include "battle/whiteout.h"
#include "constants/vars.h"
#include "constants/flags.h"
#include "vars.h"
#include "flags.h"
#include "trainer/virtual.h"
#include "map/healing_place.h"
#include "worldmap.h"

void whiteout_reset_vars(){
    *var_access(BATTLE_SONG_OVERRIDE) = 0;
    *var_access(SONG_OVERRIDE) = 0;
    clearflag(TRANS_DISABLE);
    setflag(TRANS_PALETTE_FETCH);
}

void trainerbattle_store_possible_loss_in_lastresult(){
    trainerbattle_continuation();
    if(*battle_trainer_kind == 9 && (*battle_result == 3 || *battle_result == 2))
        *lastresult = 0xFF;
}


void whiteout_setup_warp(warp_save_t *target) {
	int healing_place_idx = map_get_flightposition(
			(*save1)->healingplace.bank, (*save1)->healingplace.map);
	target->bank = (u8)(healing_places[healing_place_idx - 1].bank);
	target->map = (u8)(healing_places[healing_place_idx - 1].map);
	target->exit = 0xFF;
	target->x = healing_place_target_coordinates[healing_place_idx - 1].x;
	target->y = healing_place_target_coordinates[healing_place_idx - 1].y;
	whiteout_set_target_person(healing_place_idx);
}
