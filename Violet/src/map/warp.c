#include "types.h"
#include "map/event.h"
#include "map/header.h"
#include "tile/coordinate.h"
#include "constants/block_behaviour.h"
#include "item/item.h"
#include "overworld/npc.h"
#include "overworld/map_control.h"
#include "overworld/script.h"
#include "callbacks.h"
#include "map/cloud.h"
#include "music.h"
#include "flags.h"
#include "debug.h"
#include "save.h"
#include "vars.h"

static void warp_setup_cloud_upstream_callback() {
    map_fade_out_music();
    u8 cb_idx = big_callback_new(warp_teleport_callback, 10);
    // This is a bit hacky, but we replicate the behaviour of case 0  in the warp callback
    big_callbacks[cb_idx].params[0] = 1; // Directly go to case 1
    npc_stop_all_movements_but_players();
    warp_teleport_start_player_warp_out_animation();
    play_sound(128);
    map_reload_continuation = map_reload_continuation_exit_warp;
}

static void big_callback_cloud_upstream_warp_waiting(u8 self) {
    if (++big_callbacks[self].params[0] >= 48) {
        warp_setup_cloud_upstream_callback();
        big_callback_delete(self);
    }
}

void warp_setup_by_event_and_position(map_header_t *header, s8 warp_idx, position_t *position) {
    (void) header;
    map_event_warp *warp = mapheader_virtual.events->warps + warp_idx;
    if (warp->target_map == 0x7F) {
        warp_set_dynamic_map_idx(warp->target_warp_id);
    } else { 
        warp_setup_by_event(warp->target_bank, warp->target_map, warp->target_warp_id);
        warp_update_last_outdoor_map(position->coordinates.x, position->coordinates.y);
        map_header_t *header = get_mapheader(warp->target_bank, warp->target_map);
        if (header->events->warps[warp->target_warp_id].target_map == 0x7F)
            warp_last_map_set_on_current_position((s8)header->events->warps[warp_idx].target_warp_id, save1->bank, save1->map, warp_idx);
    }
}

extern u8 ow_script_lockall_and_pause[];

bool step_on_warp(position_t *position, u8 behaviour) {
    s8 warp_idx = map_get_warp_idx_by_position(&mapheader_virtual, position);
    if (warp_idx == -1) {
        return false;
    }
    if (behaviour == MB_CLOUD_UPSTREAM_WARP && checkflag(ROUTE_5_CLOUD_RECEIVED)) {//&& item_check(ITEM_FAHRRAD, 1)) {
        if (!(player_state.state & PLAYER_STATE_BIKING)) {
            u8 cb_idx = big_callback_new(player_transition_to_bike, 0);
            player_transition_to_bike(cb_idx);
        }
        player_save_initial_state();
        player_initial_state.state |= PLAYER_STATE_BIKING;
        warp_setup_by_event_and_position(&mapheader_virtual, warp_idx, position);
        map_cloud_upstream_whirlwind_at((s16)(position->coordinates.x - 7), (s16)(position->coordinates.y - 7));
        overworld_script_set_active();
        overworld_script_init(ow_script_lockall_and_pause);
        big_callback_new(big_callback_cloud_upstream_warp_waiting, 0);
    } else if (behaviour_is_warp(behaviour)) {
        player_save_initial_state();
        warp_setup_by_event_and_position(&mapheader_virtual, warp_idx, position);
        if (behaviour_is_escalator(behaviour)) {
            warp_setup_escalator_callback();
        } else if (behaviour_is_lavaridge_b1f_warp(behaviour)) {
            warp_setup_lavaridge_b1f_callback();
        } else if (behaviour_is_lavaridge_1f_warp(behaviour)) {
            warp_setup_lavaridge_1f_callback();
        } else if (behaviour_is_teleport_warp(behaviour)) {
            warp_setup_teleport_callback();
        } else if (behaviour_is_union_room_warp(behaviour)) {
            warp_setup_union_room_callback();
        } else if (behaviour_is_fall_warp(behaviour)) {
            player_reset_initial_state();
            overworld_script_init(ow_script_fall_warp);
        } else {
            warp_setup_callbacks(); // Standard warp without any effect
        }
        return true;
    }
    return false;
}