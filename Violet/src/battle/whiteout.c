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
#include "text.h"
#include "callbacks.h"
#include "map/healing_place.h"
#include "overworld/npc.h"
#include "overworld/weather.h"
#include "overworld/script.h"
#include "dma.h"
#include "fading.h"

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
	target->bank = (u8)(healing_place_maps[healing_place_idx - 1].bank);
	target->map = (u8)(healing_place_maps[healing_place_idx - 1].map);
	target->exit = 0xFF;
	target->x = healing_place_target_coordinates[healing_place_idx - 1].x;
	target->y = healing_place_target_coordinates[healing_place_idx - 1].y;
	whiteout_set_target_person(healing_place_idx);
}

static int healingplace_get_current() {
	return HEALINGPLACE_BBSHIP;
	for (int i = 1; i <= NUM_HEALING_PLACES; i++) {
		stru_flight_position *position = flightposition_by_id(i);
		if (save1->healingplace.bank == position->bank && save1->healingplace.map == position->map &&
			save1->healingplace.x == position->x && save1->healingplace.y == position->y) {
				dprintf("Current healingplace is %d\n", i);
				return i;
		}
	}
	return -1;
}

extern u8 str_whiteout[];
extern u8 str_whiteout_mother[];
extern u8 str_whiteout_bbship[];

extern u8 ow_script_whiteout_bbship[];
extern u8 ow_script_whiteout_joy[];
extern u8 ow_script_whiteout_mother[];

void whiteout_callback_print_text(u8 self) {
	u16 *state = big_callbacks[self].params + 0;
	switch (*state) {
		case 0: {
			u8 tbox_idx = tbox_new(&tboxdata_whiteout_text);
			big_callbacks[self].params[1] = tbox_idx;
			tbox_load_std_frame_palette_at(15 * 16);
			tbox_flush_set(tbox_idx, 0 | (0 << 4));
			tbox_tilemap_draw(tbox_idx);
			tbox_copy_to_vram(tbox_idx, 3);
			++*state;
			break;
		}
		case 1: {
			u8 *str;
			u8 direction = DIR_UP;
			switch(healingplace_get_current()) {
				case HEALINGPLACE_AMONIA: str = str_whiteout_mother; break;
				case HEALINGPLACE_BBSHIP: str = str_whiteout_bbship; direction = DIR_DOWN; break;
				default: str = str_whiteout; break;
			}
			if (whiteout_print_string(self, str, 2, 8)) {
				++*state;
				npc_set_facing(npcs + player_state.npc_idx, direction);
			}
			break;
		}
		case 2: {
			u8 tbox_idx = (u8)big_callbacks[self].params[1];
			tbox_flush_map(tbox_idx);
			tbox_copy_to_vram(tbox_idx, 1);
			tbox_free_2(tbox_idx);
			pal_set_all_to_black();
			fadescreen_and_clear_dma3_source();
			++*state;
			break;
		}
		case 3: {
			if (overworld_fading_effect_finished()) {
				big_callback_delete(self);
				u8 *script;
				switch(healingplace_get_current()) {
					case HEALINGPLACE_AMONIA: script = ow_script_whiteout_mother; break;
					case HEALINGPLACE_BBSHIP: script = ow_script_whiteout_bbship; break;
					default: script = ow_script_whiteout_joy; break;
				}
				overworld_script_init(script);
			}
		}
	}
}