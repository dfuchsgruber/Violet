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
#include "worldmap.h"
#include "constants/battle/battle_results.h"
#include "pokemon/virtual.h"
#include "superstate.h"
#include "bios.h"
#include "oam.h"
#include "color.h"
#include "cutscene_script.h"
#include "text.h"
#include "callbacks.h"
#include "overworld/npc.h"
#include "overworld/weather.h"
#include "overworld/script.h"
#include "dma.h"
#include "fading.h"
#include "constants/healingplaces.h"

extern const u8 str_whiteout[];
extern const u8 str_whiteout_mother[];
extern const u8 str_whiteout_bbship[];
extern const u8 str_whiteout_tann[];
extern const u8 str_whiteout_desert[];

extern const u8 ow_script_whiteout_bbship[];
extern const u8 ow_script_whiteout_joy[];
extern const u8 ow_script_whiteout_mother[];
extern const u8 ow_script_whiteout_tann[];
extern const u8 ow_script_whiteout_desert[];

static const healing_place2_t healing_places[NUM_HEALING_PLACES] = {
    [HEALINGPLACE_AMONIA] = {.bank = 4, .map = 0, .x = 0x12, .y = 0x6, .target_person = 1},
    [HEALINGPLACE_MERIANA_CITY] = {.bank = 5, .map = 4, .x = 0x7, .y = 0x4, .target_person = 1},
    [HEALINGPLACE_AKTANIA] = {.bank = 6, .map = 5, .x = 0x7, .y = 0x4, .target_person = 3},
    [HEALINGPLACE_SILVANIA_CITY] = {.bank = 7, .map = 3, .x = 0x7, .y = 0x4, .target_person = 1},
    [HEALINGPLACE_KASKADA] = {.bank = 8, .map = 0, .x = 0x7, .y = 0x4, .target_person = 1},
    [HEALINGPLACE_ORINA_CITY] = {.bank = 9, .map = 1, .x = 0x7, .y = 0x4, .target_person = 1},
    [HEALINGPLACE_INFERIOR] = {.bank = 10, .map = 12, .x = 0x7, .y = 0x4, .target_person = 1},
    [HEALINGPLACE_LAUBDORF] = {.bank = 12, .map = 0, .x = 0x7, .y = 0x4, .target_person = 1},
    [HEALINGPLACE_CEOMETRIA] = {.bank = 19, .map = 0, .x = 0x7, .y = 0x4, .target_person = 1},
    [HEALINGPLACE_HAWEILAND] = {.bank = 27, .map = 3, .x = 0x7, .y = 0x4, .target_person = 1},
    [HEALINGPLACE_BBSHIP] = {.bank = 33, .map = 0, .x = 3, .y = 5, .target_person = 0xFF},
    [HEALINGPLACE_TANNS_LAB] = {.bank = 35, .map = 0, .x = 0x7, .y = 0x4, .target_person = 1},
    [HEALINGPLACE_DESERT] = {.bank = 37, .map = 0, .x = 7, .y = 4, .target_person = 1},
}; 

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
			cutscene_script_initiatlize(cutscene_scripts[19]);
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
	target->bank = healing_places[csave.healing_place_idx].bank;
	target->map = healing_places[csave.healing_place_idx].map;
	target->exit = 0xFF;
	target->x = healing_places[csave.healing_place_idx].x;
	target->y = healing_places[csave.healing_place_idx].y;
	lasttalked = healing_places[csave.healing_place_idx].target_person;
}

void whiteout_callback_print_text(u8 self) {
	u16 *state = big_callbacks[self].params + 0;
	DEBUG("Whiteout state %d\n", *state);
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
			const u8 *str;
			u8 direction = DIR_UP;
			switch(csave.healing_place_idx) {
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
			tbox_free(tbox_idx);
			pal_set_all_to_black();
			fadescreen_and_clear_dma3_source();
			++*state;
			break;
		}
		case 3: {
			if (overworld_fading_effect_finished()) {
				big_callback_delete(self);
				const u8 *script;
				switch(csave.healing_place_idx) {
					case HEALINGPLACE_AMONIA: script = ow_script_whiteout_mother; break;
					case HEALINGPLACE_BBSHIP: script = ow_script_whiteout_bbship; break;
					default: script = ow_script_whiteout_joy; break;
				}
				overworld_script_init(script);
			}
		}
	}
}

void healing_place_set(u8 idx) {
	csave.healing_place_idx = idx;
	whiteout_setup_warp(&save1->healingplace);
}