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
#include "constants/battle/battle_results.h"
#include "pokemon/virtual.h"
#include "superstate.h"
#include "bios.h"
#include "oam.h"
#include "color.h"
#include "anim_engine.h"

void whiteout_reset_vars(){
    *var_access(BATTLE_SONG_OVERRIDE) = 0;
    *var_access(SONG_OVERRIDE) = 0;
    clearflag(TRANS_DISABLE);
    setflag(TRANS_PALETTE_FETCH);
}

void battle_trainerbattle_continuation() {

	if (battle_trainer_kind == 9) {
		if (trainer_vars.rival_flags & 4) { // Battle against Lucius
			pokemon_heal_player_party();
			anim_engine_initiatlize(ae_scripts[19]);
			callback1_set(generic_callback1);
			return;
		}

		if (battle_result_is_loss(battle_result)) {
			lastresult = true;
			if (trainer_vars.rival_flags & 1) {
				pokemon_heal_player_party();
			} else {
				callback1_set(whiteout_callback1);
				return;
			}
			callback1_set(battle_map_reload_and_play_map_music);
			trainer_set_flags();
			// The questlog stuff will not be executed here..., I don't bother this BS
		} else {
			lastresult = false;
			callback1_set(battle_map_reload_and_play_map_music);
			trainer_set_flags();
		}
	} else {
		lastresult = battle_result_is_loss(battle_result);
		if (trainer_vars.trainer_id == 0x400) {
			callback1_set(battle_map_reload_and_play_map_music);
		} else if (battle_result_is_loss(battle_result)) {
			callback1_set(whiteout_callback1);
		} else {
			callback1_set(battle_map_reload_and_play_map_music);
			trainer_set_flags();
			// The questlog stuff will not be executed here..., I don't bother this BS
		}
	}
}

void battle_scripted_wild_battle_continuation() {
	int zero = 0;
	cpuset(&zero, pals, CPUSET_HALFWORD | CPUSET_FILL | CPUSET_HALFWORD_SIZE(256 * sizeof(color_t))); // clear bg pals?
	oam_buffer_reset(0, 0x80);
	if (battle_result_is_loss(battle_result)) {
		if (checkflag(FLAG_SCRIPTED_WILD_BATTLES_LOSABLE)) {
			pokemon_heal_player_party();
		} else {
			callback1_set(whiteout_callback1);
			return;
		}
	}
	callback1_set(battle_map_reload_and_play_map_music);
}


void whiteout_setup_warp(warp_save_t *target) {
	int healing_place_idx = map_get_flightposition(
			save1->healingplace.bank, save1->healingplace.map);
	target->bank = (u8)(healing_places[healing_place_idx - 1].bank);
	target->map = (u8)(healing_places[healing_place_idx - 1].map);
	target->exit = 0xFF;
	target->x = healing_place_target_coordinates[healing_place_idx - 1].x;
	target->y = healing_place_target_coordinates[healing_place_idx - 1].y;
	whiteout_set_target_person(healing_place_idx);
}
