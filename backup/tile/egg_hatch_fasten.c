#include "types.h"
#include "stdbool.h"
#include "vars.h"
#include "pokemon/virtual.h"
#include "tile/block.h"
#include "save.h"
#include "debug.h"
#include "constants/abilities.h"
#include "constants/vars.h"
#include "constants/pokemon_attributes.h"

void egg_warm_update(){
    s16 pos[2];
    player_get_coordinates(&pos[0], &pos[1]);
    u8 behavior = (u8)block_get_behaviour_by_pos(pos[0], pos[1]);
    
    u16 *v_hatching_fastened_left = var_access(HATCHING_BOOST_STEPS);
    
    if (save1->bank == 3 && save1->map == 6 && behavior == 0x28){
        //restore 1000 to the var
        *v_hatching_fastened_left = 1000;
    }else{

        if(*v_hatching_fastened_left)
            (*v_hatching_fastened_left)--;
    }
}
