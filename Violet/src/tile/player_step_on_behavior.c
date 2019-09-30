#include "types.h"
#include "tile/any_grass.h"
#include "save.h"
#include "overworld/npc.h"
#include "callbacks.h"
#include "tile/cloud.h"
#include "overworld/script.h"

bool player_step_force_on_cloud() {
    // Check if the player transits to a non-walkable tile on a cloud map
    if (cloud_not_dismountable() && !(player_state.state & PLAYER_STATE_BIKING)) {
        u8 cb_idx = big_callback_new(player_transition_to_bike, 0);
        overworld_script_set_active();
        player_transition_to_bike(cb_idx);
        return true;
    }
    return false;
}

u8 *player_step_on_behavior(){


    s16 pos[2];
    player_get_coordinates(&pos[0], &pos[1]);
    u8 behavior = (u8)block_get_behaviour_by_pos(pos[0], pos[1]);

    
    if(behavior == 0xBB){
        //anygrass, execute player_step_function
        int i;
        for(i = 0; tile_any_grasses[i].bank != 0xFF; i++){
            if (save1->bank == tile_any_grasses[i].bank &&
                    save1->map == tile_any_grasses[i].map && 
                    behavior == tile_any_grasses[i].triggered_by_behavior){
                return tile_any_grasses[i].player_step_cb();
            }
        }
    }
    return NULL;
}
