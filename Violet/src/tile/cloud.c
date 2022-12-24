#include "types.h"
#include "vars.h"
#include "map/header.h"
#include "map/event.h"
#include "save.h"
#include "constants/items.h"
#include "tile/cloud.h"
#include "tile/coordinate.h"
#include "overworld/npc.h"
#include "constants/flags.h"
#include "flags.h"
#include "item/item.h"
#include "overworld/map_control.h"
#include "constants/battle/battle_bgs.h"
#include "debug.h"

void cloud_force() {
    if ((player_state.state & 1) && cloud_not_dismountable()) {
        npc_player_set_bike_state(2);
        DEBUG("Forced to bike.\n");
    }
}

bool map_is_cloud(){
	return mapheader_virtual.type == MAP_TYPE_CLOUD;
}


// u8 *cloud_trigger(bool back) {
// 	(void)back;
// 	return NULL; 
// }

void cloud_enter() {
	position_t pos;
	// player_get_position_faced(&pos);
	player_get_position(&pos);
	s8 warp_idx = map_get_warp_idx_by_position(&mapheader_virtual, &pos);
	map_event_warp *w = &(mapheader_virtual.events->warps[warp_idx]);
	warp_setup_by_event(w->target_bank, w->target_map, w->target_warp_id);
	// warp_update_last_outdoor_map(pos.coordinates.x, pos.coordinates.y);
	// As MAP_TYPE_UNDERWATER is treaded as clouds as well, we need to update the last outdoor
	// map manually
	if (map_type_is_outside(mapheader_virtual.type)) {
		warp_set_last_outdoor_map(save1->bank, save1->map, -1, (s16)(pos.coordinates.x - 7),
			(s16)(pos.coordinates.y - 7));
	}
	warp_last_map_set_on_current_position(warp_idx, save1->bank, save1->map, warp_idx);
    warp_setup_muted_callback();
    warp_reset_initial_player_state();
    clearflag(TRANS_PALETTE_FETCH);
}

void warp_to_pos_with_facing() {
    u16 x = *var_access(0x8000);
    u16 y = *var_access(0x8001);
    u16 bank = *var_access(0x8002);
    u16 map = *var_access(0x8003);
    u16 facing = *var_access(0x8004);


	position_t pos;
	player_get_position(&pos);
	warp_update_last_outdoor_map(pos.coordinates.x, pos.coordinates.y);
	warp_last_map_set(0, save1->bank, save1->map, 0xFF, (s16)(pos.coordinates.x - 7),
			(s16)(pos.coordinates.y - 7));
    fmem.additional_levelscript_4 = script_cloud_facings[facing];
    warp_setup((u8) bank, (u8) map, 0xFF, (s16) x, (s16) y);
    //warp_setup_callbacks();
    warp_setup_muted_callback();
    warp_reset_initial_player_state();
    clearflag(TRANS_PALETTE_FETCH);
}

static u16 cloud_dismountable_blocks[] = {
	0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF, 
	0xE2, 0xEA, 0xF2, 0xE4, 0xE5, 0xCA, 0xCB, 0xCC, 
	0xC6, 0xCE, 0xD6, 0xEC, 0xF4,
	0xFFFF,
};

static u16 cloud_ardeal_dismountable_blocks[] = {
	0x281, 0x282, 0x298, 0x299, 0x2a0, 0x2a1, 0x2a8, 
	0x2a9, 0x28b, 0x28c, 0x293, 0x29b, 0x2a4, 0x2d9, 
	0x296, 0x295, 0x294, 0x29E,
	0xFFFF,
};


static bool cloud_current_block_dismountable(u16 *blocks) {
	position_t pos;
	player_get_position(&pos);
	u16 block = block_get_by_pos(pos.coordinates.x, pos.coordinates.y);

	
	for (int i = 0; blocks[i] != 0xFFFF; i++) {
		if (block == blocks[i]) return true;
	}
	return false;
}

bool cloud_not_dismountable() {
	if (map_is_cloud() && !player_state_disables_bike()) {
		if (tileset_primary_is_clouds(mapheader_virtual.footer->tileset1)) {
			position_t pos;
			player_get_position(&pos);
			// DEBUG("Position is %d,%d, with battle bg %d\n", pos.coordinates.x, pos.coordinates.y, block_get_field_by_pos(pos.coordinates.x, pos.coordinates.y, FIELD_BATTLE_BG));

			if (block_get_field_by_pos(pos.coordinates.x, pos.coordinates.y, FIELD_BATTLE_BG) == BATTLE_BG_SKY_ISLAND) {
				return false; // These are all land tiles, more or less...
			}
		}
		if (cloud_current_block_dismountable(cloud_dismountable_blocks)) {
			// On cloud maps only on certain blocks the player can dismount
			return false;
		}
		if (mapheader_virtual.footer->tileset2 == &maptileset_cloud_ardeal &&
			cloud_current_block_dismountable(cloud_ardeal_dismountable_blocks)) {
			return false;
		}
		return true;
	}
	return false;
}

