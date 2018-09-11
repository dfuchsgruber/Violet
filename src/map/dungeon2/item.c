/*
 * item.c
 *
 *  Created on: Jun 25, 2018
 *      Author: dominik
 */

#include "types.h"
#include "dungeon/dungeon2.h"
#include "vars.h"
#include "constants/vars.h"
#include "map/event.h"
#include "save.h"

void dungeon_special_item_by_overworld_idx() {
  u16 overworld_idx = *var_access(0x8004);
  map_event_person *person = map_get_person((u8)overworld_idx, save1->map, save1->bank);
  *var_access(0x8005) = person->private;
}
