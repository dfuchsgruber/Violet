#include "types.h"
#include "romfuncs.h"
#include "tile.h"
#include "save.h"

u8 *player_step_on_behavior(){
    s16 pos[2];
    get_current_tile_position(&pos[0], &pos[1]);
    u8 behavior = (u8)get_block_info_behaviour(pos[0], pos[1]);
    
    if(behavior == 0xBB){
        //anygrass, execute player_step_function
        int i;
        for(i = 0; tile_any_grasses[i].bank != 0xFF; i++){
            if ((*save1)->bank == tile_any_grasses[i].bank &&
                    (*save1)->map == tile_any_grasses[i].map && 
                    behavior == tile_any_grasses[i].triggered_by_behavior){
                return tile_any_grasses[i].player_step_cb();
            }
        }
    }
    return NULL;
}
