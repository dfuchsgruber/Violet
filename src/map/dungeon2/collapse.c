#include "types.h"
#include "map/header.h"
#include "save.h"
#include "dungeon2.h"
#include "debug.h"
#include "romfuncs.h"
#include "constants/vars.h"

#define DG2_STEPS_TO_COLLAPSE 10000

int dungeon2_step_is_collapsing(){
    if(!dungeon_get_type()) return 0;
    u16 *steps = vardecrypt(DUNGEON_STEPS);
    if(++(*steps) == DG2_STEPS_TO_COLLAPSE){
        //Todo
    }
    return 0;
}
