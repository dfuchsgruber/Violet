#include "types.h"
#include "map.h"
#include "save.h"
#include "tile.h"
#include "dungeon2.h"
#include "debug.h"
#include "utils.h"
#include "romfuncs.h"
#include "mapevents.h"

#define DG2_STEPS_TO_COLLAPSE 10000

int dungeon2_step_is_collapsing(){
    if(!is_dungeon_map()) return 0;
    u16 *steps = vardecrypt(DG2_STEPS);
    if(++(*steps) == DG2_STEPS_TO_COLLAPSE){
        //Todo
    }
    return 0;
}