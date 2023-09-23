/*
 * person_get_script.c
 *
 *  Created on: Feb 4, 2019
 *      Author: dominik
 */

#include "types.h"
#include "overworld/script.h"
#include "map/event.h"
#include "vars.h"
#include "debug.h"
#include "constants/person_script_stds.h"
#include "save.h"
#include "pokemon/virtual.h"
#include "prng.h"
#include "battle/state.h"
#include "trainer/trainer.h"

extern const u8 ow_script_person_pokeball[];
extern const u8 ow_script_person_egg[];
extern const u8 ow_script_person_pokemon[];
extern const u8 ow_script_aggressive_wild[];
extern const u8 ow_script_berry_tree[];
extern const u8 ow_script_mushroom[];
extern const u8 ow_script_shell[];
extern const u8 ow_script_boulder_gym_puzzle[];
extern const u8 ow_script_boulder_hay_bale[];
extern const u8 ow_script_person_pokemon_non_facing[];
extern const u8 ow_script_person_accessible_move_tutor[];
extern const u8 ow_script_trash_can[];
extern const u8 ow_script_dungeon2_enter_forest[];
extern const u8 ow_script_static_berry_tree[];
extern const u8 ow_script_dungeon2_enter_cave[];
extern const u8 ow_script_recipe[];

void battle_initialize_aggressive_wild() {
	super.saved_callback = battle_continuation_wild_legendary_battle_end;
	battle_flags = BATTLE_AGGRESSIVE_WILD | BATTLE_LEGENDARY;
	if (trainers_cnt > 1)
		battle_flags |= BATTLE_DOUBLE;
	battle_initialize(battle_get_intro_type(), 0);
	save_increment_key(8);
	save_increment_key(9);
	overworld_script_halt();
}

void battle_initialize_misc_ecounter() {
	super.saved_callback = battle_continuation_wild_legendary_battle_end;
	battle_flags = BATTLE_AGGRESSIVE_WILD | BATTLE_LEGENDARY;
	battle_initialize(battle_get_intro_type(), 0);
	save_increment_key(8);
	save_increment_key(9);
	overworld_script_halt();
}

const u8 *person_get_script(u8 target_idx, u8 map_id, u8 bank) {
	const map_event_person *p = map_get_person(target_idx, map_id, bank);
	// DEBUG("Get script of person idx %d at %d.%d. Person offset is 0x%x\n", target_idx, bank, map_id, p);
	if (p->script)
		return p->script;
	switch(p->script_std) {
		case PERSON_ITEM:
			*var_access(0x8000) = p->value;
			*var_access(0x8001) = 1;
			return ow_script_person_pokeball;
		case PERSON_ITEM_MULTIPLE_COPIES:
			*var_access(0x8000) = p->value;
			*var_access(0x8001) = MAX(1, p->argument);
			return ow_script_person_pokeball;
		case PERSON_EGG:
			// DEBUG("Person egg\n");
			*var_access(0x8000) = p->value;
			return ow_script_person_egg;
		case PERSON_POKEMON:
			*var_access(0x8000) = p->value;
			return ow_script_person_pokemon;
		case PERSON_POKEMON_NON_FACING:
			*var_access(0x8000) = p->value;
			return ow_script_person_pokemon_non_facing;
		case PERSON_AGGRESSIVE_POKEMON:
			*var_access(0x8000) = p->value;
			*var_access(0x8001) = p->argument;
			return ow_script_aggressive_wild;
		case PERSON_BERRY_TREE:
			*var_access(0x8000) = p->value;
			return ow_script_berry_tree;
		case PERSON_MUSHROOM:
			*var_access(0x8000) = p->value;
			return ow_script_mushroom;
		case PERSON_SHELL:
			*var_access(0x8000) = p->value;
			return ow_script_shell;
		case PERSON_TRASH_CAN:
			*var_access(0x8000) = p->value;
			return ow_script_trash_can;
		case PERSON_PUZZLE_BOULDER:
			return ow_script_boulder_gym_puzzle;
		case PERSON_HAY_BALE:
			return ow_script_boulder_hay_bale;
		case PERSON_ACCESSIBLE_MOVE_TUTOR:
			*var_access(VAR_ACCESIBLE_MOVE_TUTOR_TYPE) = (u16)(p->value + 1);
			return ow_script_person_accessible_move_tutor;
		case PERSON_AGGRESSIVE_POKEMON_NO_OVERWORLD_EFFECT:
			*var_access(0x8000) = p->value;
			*var_access(0x8001) = p->argument;
			return ow_script_aggressive_wild;
		case PERSON_SECRET_POWER_VINE:
			*var_access(0x8000) = p->value;
			return ow_script_dungeon2_enter_forest;
		case PERSON_STATIC_BERRY_TREE:
			*var_access(0x8000) = p->value;
			*var_access(0x8001) = p->argument;
			return ow_script_static_berry_tree;
		case PERSON_SECRET_POWER_CAVE:
			*var_access(0x8000) = p->value;
			return ow_script_dungeon2_enter_cave;
		case PERSON_RECIPE:
			*var_access(0x8000) = p->flag;
			return ow_script_recipe;
		default:
			return NULL;
	}
}
