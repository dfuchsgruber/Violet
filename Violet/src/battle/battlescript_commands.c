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
#include "battle/attack.h"
#include "callbacks.h"

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

void battle_animation(u8 user, u8 target, u8 *animation) {
    battle_animation_user = user;
    battle_animation_target = target;
    battle_animation_initialize(&animation, 0, false);
    u8 cb = big_callback_new(battle_special_anim_clear_flags_when_finished, 10);
    u8 battler_idx = user; // The battler that is being active
    big_callbacks[cb].params[0] = battler_idx; 
    battle_sprite_data->healthbox_info[battler_idx].special_anim_active = 1;
}


// Parameter structure animation user_type target_type 
void bsc_cmd_custom_attack_anim(){
    bsc_offset++;
    u8 user = bsc_get_byte() ? attacking_battler : defending_battler;
    u8 target = bsc_get_byte() ? attacking_battler : defending_battler;
    u8 *animation = (u8*)bsc_get_word();
    battle_animation(user, target, animation);
}

void bsc_cmd_wait_battle_animation() {
    if (!battle_animation_running) {
        bsc_offset++;
    }
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
