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
#include "constants/block_cloud_types.h"

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
	const map_event_warp *w = &(mapheader_virtual.events->warps[warp_idx]);
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
	DEBUG("Warping with facing %d\n", facing);
    additional_levelscript_4 = script_cloud_facings[facing];
    warp_setup((u8) bank, (u8) map, 0xFF, (s16) x, (s16) y);
    //warp_setup_callbacks();
    warp_setup_muted_callback();
    warp_reset_initial_player_state();
    clearflag(TRANS_PALETTE_FETCH);
}

bool cloud_not_dismountable() {
	if (!player_state_disables_bike()) {
		position_t pos;
		player_get_position(&pos);
		u32 cloud_type = block_get_field_by_pos(pos.coordinates.x, pos.coordinates.y, FIELD_CLOUD_TYPE);
		return cloud_type == BLOCK_FORCE_ON_CLOUD;
	}
	return false;
}

bool player_should_be_forced_off_cloud() {
	position_t pos;
	player_get_position(&pos);
	u32 cloud_type = block_get_field_by_pos(pos.coordinates.x, pos.coordinates.y, FIELD_CLOUD_TYPE);
	return cloud_type == BLOCK_FORCE_OFF_CLOUD;
}
