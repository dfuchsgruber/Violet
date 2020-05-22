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

extern u8 ow_script_person_pokeball[];
extern u8 ow_script_person_egg[];
extern u8 ow_script_person_pokemon[];


u8 *person_get_script(u8 target_idx, u8 map_id, u8 bank) {
	map_event_person *p = map_get_person(target_idx, map_id, bank);
	switch(p->script_std) {
	case PERSON_ITEM:
		*var_access(0x8000) = p->value;
		*var_access(0x8001) = 1;
		return ow_script_person_pokeball;
	case PERSON_EGG:
		// dprintf("Person egg\n");
		*var_access(0x8000) = p->value;
		return ow_script_person_egg;
	case PERSON_POKEMON:
		*var_access(0x8000) = p->value;
		return ow_script_person_pokemon;

	default:
		return p->script;
	}
}
