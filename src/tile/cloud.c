#include "types.h"
#include "vars.h"
#include "map/header.h"
#include "save.h"
#include "constants/items.h"
#include "tile/cloud.h"
#include "overworld/npc.h"
#include "constants/flags.h"
#include "flags.h"
#include "item/item.h"
#include "overworld/map_control.h"

u8 *cloud_trigger(bool back) {
    if (item_check(ITEM_FAHRRAD, 1)) {


        map_events *events = get_mapheader((*save1)->bank, (*save1)->map)->events;
        s16 pos[2];
        player_get_facing_position(&pos[0], &pos[1]);
        u8 height = npcs[player_state->player_npc_id].height.current;
        u32 i;
        for (i = 0; i < events->warp_cnt; i++) {
            if (events->warps[i].x == pos[0] - 7 && events->warps[i].y == pos[1] - 7 &&
                    (!events->warps[i].height || events->warps[i].height == height)) {
                *var_access(0x8000) = (u16) i;
                if (back) {
                    fmem->additional_levelscript_4 = script_cloud_facings[player_get_facing() + 4];
                    return script_use_cloud_back_ref;
                } else {
                    fmem->additional_levelscript_4 = script_cloud_facings[player_get_facing()];
                    return script_use_cloud_ref;
                }
            }
        }
    } else {
        return script_cloud_none_ref;
    }
    return NULL;
}

void cloud_enter() {
    s16 pos[2];
    player_get_facing_position(&pos[0], &pos[1]);
    map_event_warp warp = get_mapheader((*save1)->bank, (*save1)->map)->events->warps[*var_access(0x8000)];

    //find the target warp
    map_event_warp target_warp = get_mapheader(warp.target_bank, warp.target_map)->events->warps[warp.target_warp_id];
    s16 x = (s16) (target_warp.x - walking_directions[player_get_facing()].x);
    s16 y = (s16) (target_warp.y - walking_directions[player_get_facing()].y);


    warp_setup(warp.target_bank, warp.target_map, 0xFF, x, y);
    //warp_setup_callbacks();
    warp_setup_muted_callback();
    warp_enable_flags();
    clearflag(TRANS_PALETTE_FETCH);
}

void warp_to_pos_with_facing() {
    u16 x = *var_access(0x8000);
    u16 y = *var_access(0x8001);
    u16 bank = *var_access(0x8002);
    u16 map = *var_access(0x8003);
    u16 facing = *var_access(0x8004);

    //ampf(x, y, bank, map);

    fmem->additional_levelscript_4 = script_cloud_facings[facing];
    warp_setup((u8) bank, (u8) map, 0xFF, (s16) x, (s16) y);
    //warp_setup_callbacks();
    warp_setup_muted_callback();
    warp_enable_flags();
    clearflag(TRANS_PALETTE_FETCH);
}

