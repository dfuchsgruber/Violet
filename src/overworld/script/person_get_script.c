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

extern u8 ow_script_person_pokeball[];

u8 *person_get_script(u8 target_idx, u8 map_id, u8 bank) {
	map_event_person *p = map_get_person(target_idx, map_id, bank);
	// Check if the event is a pokeball
	if (p->item) {
		*var_access(0x8000) = p->item;
		*var_access(0x8001) = 1;
		//dprintf("item %d @%x\n", p->item, p);
		return ow_script_person_pokeball;
	} else {
		return p->script;
	}
}
