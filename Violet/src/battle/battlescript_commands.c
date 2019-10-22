#include "types.h"
#include "battle/battler.h"
#include "battle/battlescript.h"
#include "mega.h"
#include "debug.h"
#include "battle/bg.h"
#include "constants/battle_bgs.h"
#include "constants/pokemon_types.h"
#include "battle/state.h"
#include "constants/species.h"
#include "map/wild_pokemon.h"

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
    bsc_offset++; //command itself
    void (*function)() = (void (*)()) bsc_get_word();
    function();
}

void attack_calculate_damage_from_target_name() {
    battle_dynamic_base_power = 20;
    if (battlers[attacking_battler].species == POKEMON_ICOGNITO) {
        int matches = 0;
        int unown_letter = battlers[attacking_battler].pid.fields.unown_letter;   
        for (int i = 0; battlers[defending_battler].name[i] != 0xFF; i++) {
            int letter = battlers[defending_battler].name[i];
            switch (unown_letter) {
                case POKEMON_ICOGNITO_EXCLAMATION - POKEMON_EGG:
                    if (letter == 0xAB) matches++;
                    break;
                case POKEMON_ICOGNITO_QUESTION - POKEMON_EGG:
                    if (letter == 0xAC) matches++;
                    break;
                default:
                    if (letter == 0xBB + unown_letter || letter == 0xD5 + unown_letter) matches++;
                    break;
            }
        }
        switch (matches) {
            case 0: battle_dynamic_base_power = 55; break;
            case 1: battle_dynamic_base_power = 95; break;
            case 2: battle_dynamic_base_power = 135; break;
            default: battle_dynamic_base_power = 180; break;
        }
    }
    dprintf("Damage for runengleich %d\n", battle_dynamic_base_power);

}
