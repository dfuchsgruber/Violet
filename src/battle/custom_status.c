#include "types.h"
#include "romfuncs.h"
#include "battle/battler.h"
#include "save.h"
#include <stdbool.h>

void battle_clear_temporary_custom_effects(bool clear_all){
    if(clear_all){
        int i;
        for(i = 0; i < *battler_cnt; i++){
            fmem->battle_custom_status[i] = 0;
        }
    }
}
