#include "types.h"
#include "romfuncs.h"
#include "battle.h"
#include "oams.h"
#include "mega.h"
#include "debug.h"


u8 bsc_get_byte(){
    u8 result = **bsc_offset;
    (*bsc_offset)++;
    return result;
}

int bsc_get_word(){
    return bsc_get_byte() + (bsc_get_byte() << 8) + (bsc_get_byte() << 16) +
            (bsc_get_byte() << 24);
}


void bsc_cmd_custom_attack_anim(){
    //Parameter structure
    //Slot: 0=attacker, 1=defender
    //Unkown: usually 1
    //Animation Offset
    bsc_get_byte(); //read the command id itself
    u8 slot = bsc_get_byte();
    u8 unkown = bsc_get_byte();
    u8 *anim = (u8*)bsc_get_word();
    dprintf("Slot %d, unkown %d, offset %d", slot, unkown, anim);
    slot = slot ? *attacking_battler : *defending_battler; //read the slot
    call_attack_anim_by_offset(slot, unkown, anim);
    
    
}