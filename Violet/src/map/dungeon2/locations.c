/*
 * locate.c
 *
 *  Created on: Jun 3, 2018
 *      Author: dominik
 */
#include "types.h"
#include "dungeon/dungeon2.h"
#include "save.h"
#include "tile/dungeon.h"
#include "tile/block.h"
#include "debug.h"
#include "vars.h"
#include "overworld/map_control.h"
#include "constants/dungeon/dungeon_cave_types.h"
#include "constants/person_script_stds.h"

void dungeon2_seed_init() {
	u32 dungeon_idx = *var_access(0x8000);
	u32 seq[1] = {dungeon_idx};
	cmem.dg2.initial_seed = daily_events_hash(seq, 1);
	DEBUG("Setup seed for dungeon %d to %d\n", dungeon_idx, cmem.dg2.initial_seed);
}

void dungeon_map_entrance_set_flag() {
	DEBUG("Set flag for dungeon %d\n", *var_access(0x8000));
	dungeon_flag_set(*var_access(0x8000));
}

u8 dungeon2_get_dungeon_type_by_person_faced() {
	position_t faced_position;
	player_get_position_faced(&faced_position);
	u8 npc_idx = npc_get_by_position_and_height(faced_position.coordinates.x, faced_position.coordinates.y, faced_position.height);
	if (npc_idx < NUM_NPCS) {
		map_event_person *p = map_get_person(npcs[npc_idx].overworld_id, npcs[npc_idx].map, npcs[npc_idx].bank);
		if (p) {
			switch (p->script_std) {
				case PERSON_SECRET_POWER_VINE:
					return DUNGEON_TYPE_FOREST;
				case PERSON_SECRET_POWER_CAVE:
					return DUNGEON_TYPE_CAVE;
				case PERSON_SECRET_POWER_WHIRLPOOL:
					return DUNGEON_TYPE_OCEAN;
			}
		}
	}
	return DUNGEON_TYPE_NONE;
}