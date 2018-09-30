#include "types.h"
#include "battle/battler.h"
#include "battle/battlescript.h"
#include "mega.h"
#include "debug.h"
#include "battle/bg.h"
#include "constants/battle_bgs.h"
#include "constants/pokemon_types.h"

u8 bsc_get_byte(){
    u8 result = *bsc_offset;
    (bsc_offset)++;
    return result;
}

int bsc_get_word(){
    return bsc_get_byte() + (bsc_get_byte() << 8) + (bsc_get_byte() << 16) +
            (bsc_get_byte() << 24);
    bsc_offset += 4;
}


void bsc_cmd_custom_attack_anim(){
    //Parameter structure
    //Slot: 0=attacker, 1=defender
    //Unkown: usually 1
    //Animation Offset
    bsc_get_byte(); //read the command id itself
    u8 slot_user = bsc_get_byte();
    u8 slot_target = bsc_get_byte();
    u8 *anim = (u8*)bsc_get_word();
    dprintf("User %d, Target %d, offset %d\n", slot_user, slot_target, anim);
    slot_user = slot_user ? attacking_battler : defending_battler; //read the slot
    slot_target = slot_target ? attacking_battler : defending_battler; //read the slot
    call_attack_anim_by_offset(slot_user, slot_target, anim);
    
    
}

void bsc_cmd_callasm(){
    //Parameter structure
    //Offset : word
    bsc_get_byte(); //command itself
    void (*function)() = (void (*)()) bsc_get_word();
    function();
}
