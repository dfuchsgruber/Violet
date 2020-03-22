#include "types.h"
#include "battle/battler.h"
#include "save.h"
#include "battle/state.h"

void battle_clear_temporary_custom_effects(bool clear_all){
    if(clear_all){
        int i;
        for(i = 0; i < battler_cnt; i++){
            BATTLE_STATE2->status_custom[i] = 0;
        }
    }
}
