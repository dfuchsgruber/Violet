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
#include "constants/abilities.h"
#include "battle/controller.h"
#include "prng.h"
#include "constants/battle/battle_results.h"
#include "trainer/trainer.h"
#include "trainer/virtual.h"
#include "save.h"
#include "vars.h"
#include "constants/difficulties.h"
#include "battle/battle_string.h"
#include "flags.h"

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

//Parameter structure
//Offset : word
void bsc_cmd_callasm(){
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

void bsc_cmd_switch_out_abilites() {
    bsc_offset++;
    active_battler = battlescript_argument_to_battler_idx(*bsc_offset);
    bsc_offset++;
    if (battlers[active_battler].ability == INNERE_KRAFT) {
        battlers[active_battler].status1 = 0;
        battle_controller_emit_set_pokemon_data(0, 0x28, (u8)int_bitmasks[battle_state->switch_out_party_idxs[active_battler]], 4, 
            &battlers[active_battler].status1);
        battler_mark_for_controller_execution(active_battler);
    }
    /** else if (battlers[active_battler].ability == 0xFF) { // TODO: This is code for a potential regenerator ability
    
        battlers[active_battler].current_hp = (u16) MIN(battlers[active_battler].max_hp, battlers[active_battler].current_hp +
            battlers[active_battler].max_hp / 3);
        battle_controller_emit_set_pokemon_data(0, ??, (u8)int_bitmasks[battle_state->switch_out_party_idxs[active_battler]], 4,
            &battlers[active_battler].current_hp);
        battler_mark_for_controller_execution(active_battler);
        
    }**/
    if (battlers[active_battler].species == POKEMON_DURENGARDA) {
        battler_form_change(active_battler, POKEMON_DURENGARD);
    }
}

void bsc_cmd_x4f_jump_if_unable_to_switch() {
    active_battler = battlescript_argument_to_battler_idx((u8)(bsc_offset[1] & 0x7F));
    u8 partner = 4, foe = 4, foe_partner = 4, first = 6, last = 6;
    battler_get_partner_and_foes(active_battler, &partner, &foe, &foe_partner);
    pokemon *party = battler_load_party_range(active_battler, &first, &last);
    // Check if this battler can switch-out
    if (bsc_offset[1] & 0x80 || BATTLER_CAN_SWITCH_OUT(active_battler)){ // Check if there is any target for switching-out into
        for (u8 j = first; j < last; j++) {
            if (POKEMON_IS_VIABLE(party + j) && battler_party_idxs[active_battler] != j && battler_party_idxs[partner] != j) {
                bsc_offset = bsc_offset + 6;
                return;
            }
        }
    }
    bsc_offset = (u8*)UNALIGNED_32_GET(bsc_offset + 2);
}

void bsc_cmd_x8f_random_switch_out() {
    if (battle_flags & BATTLE_TRAINER) { // Trainerbattle, check if the target trainer has other pokemons that are viable
        u8 first = 6, last = 6, partner = 4, foe = 4, foe_partner = 4;
        pokemon *party = battler_load_party_range(defending_battler, &first, &last);
        battler_get_partner_and_foes(defending_battler, &partner, &foe, &foe_partner);
        int num_valid_targets = 0;
        u8 valid_targets[6] = {0xFF};
        for (u8 j = first; j < last; j++) {
            if (POKEMON_IS_VIABLE(party + j) && battler_party_idxs[defending_battler] != j && battler_party_idxs[partner] != j) {
                valid_targets[num_valid_targets++] = j;
            }
        }
        if (num_valid_targets < 1) {
            bsc_offset = (u8*) UNALIGNED_32_GET(bsc_offset + 1);
            return;
        }
        if (battlescript_force_switch_out()) {
            u8 switch_into = valid_targets[rnd16() % num_valid_targets];
            battle_state->battler_to_switch_into[defending_battler] = switch_into;
            if (!battle_is_multi_double() && !battle_is_tag()) {
                sub_08013ef0(defending_battler);
            }
            battle_link_multi_switch_party_order(defending_battler, switch_into, 0);
            battle_link_multi_switch_party_order(PARTNER(defending_battler), switch_into, 1);
        }
    } else {
        battlescript_force_switch_out();
    }
}

void bsc_cmd_trainerslideout() {
    active_battler = battler_get_by_position(bsc_offset[1]);
    battle_controller_emit_trainer_slide_out(0);
    battler_mark_for_controller_execution(active_battler);
    bsc_offset += 2;    
}

void bsc_cmd_trainerslidein() {
    active_battler = battler_get_by_position(bsc_offset[1]);
    battle_controller_emit_trainer_slide_in(0);
    battler_mark_for_controller_execution(active_battler);
    bsc_offset += 2;    
}


static int trainer_pricemoney_get(u16 trainer_idx) {
    // Calculate the average level of the trainer pokemon
    int average_level = 0;
    if (trainers[trainer_idx].uses_custom_items && trainers[trainer_idx].uses_custom_items) {
        trainer_pokemon_custom_item_custom_attacks *party = (trainer_pokemon_custom_item_custom_attacks*) trainers[trainer_idx].party;
        for (int i = 0; i < trainers[trainer_idx].pokemon_cnt; i++)
            average_level += party[i].level;
    } else if (trainers[trainer_idx].uses_custom_items) {
        trainer_pokemon_custom_item_default_attacks *party = (trainer_pokemon_custom_item_default_attacks*) trainers[trainer_idx].party;
        for (int i = 0; i < trainers[trainer_idx].pokemon_cnt; i++)
            average_level += party[i].level;
    } else if (trainers[trainer_idx].uses_custom_moves) {
        trainer_pokemon_default_item_custom_attacks *party = (trainer_pokemon_default_item_custom_attacks*) trainers[trainer_idx].party;
        for (int i = 0; i < trainers[trainer_idx].pokemon_cnt; i++)
            average_level += party[i].level;
    } else {
        trainer_pokemon_default_item_default_attacks *party = (trainer_pokemon_default_item_default_attacks*) trainers[trainer_idx].party;
        for (int i = 0; i < trainers[trainer_idx].pokemon_cnt; i++)
            average_level += party[i].level;
    }
    average_level = MAX(1, 1000 * average_level / trainers[trainer_idx].pokemon_cnt); // Higher resultion by multplying with 1000
    dprintf("Trainer %d has an average level of %d / 1000\n", trainer_idx, average_level);
    int money = average_level * battle_state->money_multiplier * trainer_class_money_multipliers[trainers[trainer_idx].trainerclass] * 4;
    dprintf("Trainer %d yields %d / 1000 money. Multiplier is %d, class multiplier is %d\n", trainer_idx, 
        money, battle_state->money_multiplier, trainer_class_money_multipliers[trainers[trainer_idx].trainerclass]);
    return money / 1000;
}

u32 money_lost() {
    int average_player_level = 0, pokemon_cnt = 0;
    for (int i = 0; i < 6; i++) {
        if (pokemon_get_attribute(player_pokemon + i, ATTRIBUTE_SANITY_HAS_SPECIES, 0) && 
            !pokemon_get_attribute(player_pokemon + i, ATTRIBUTE_SANITY_IS_EGG, 0)) {
            average_player_level += pokemon_get_attribute(player_pokemon + i, ATTRIBUTE_LEVEL, 0);
            pokemon_cnt++;
        }
    }
    if (pokemon_cnt) average_player_level = MAX(1, average_player_level * 1000 / pokemon_cnt);
    else average_player_level = 1;
    dprintf("Average player level is %d / 1000.\n", average_player_level);
    int money = money_lost_multipliers_by_number_of_badges[badges_number_get()] * 4 * average_player_level;
    switch (*var_access(DIFFICULTY)) {
        case DIFFICULTY_VERY_EASY: money /= 2; break;
        case DIFFICULTY_EASY: money -= money / 2; break;
        case DIFFICULTY_HARD: money += money / 2; break;
        case DIFFICULTY_VERY_HARD: money *= 2; break;
    }
    return MIN((u32)(money / 1000), money_get(&save1->money));
}

void bsc_cmd_pricemoney() {
    int money = 0;
    if (battle_result & BATTLE_RESULT_WON) {
        // Cut on trainer-tower stuff...
        money = trainer_pricemoney_get(trainer_vars.trainer_id);
        if (battle_flags & BATTLE_TWO_TRAINERS)
            money += trainer_pricemoney_get(fmem.trainer_varsB.trainer_id);
        else if (battle_flags & BATTLE_DOUBLE)
            money *= 2;
        switch(*var_access(DIFFICULTY)) {
            case DIFFICULTY_VERY_EASY: money *= 2; break;
            case DIFFICULTY_EASY: money += money / 2; break;
            case DIFFICULTY_HARD: money -= money / 2; break;
            case DIFFICULTY_VERY_HARD: money /= 2; break;
        }
        money_add(&save1->money, (u32)money);
    } else {
        money = (int)money_lost();
    }
    BSC_BUFFER_NUMBER(bsc_string_buffer0, 5, money);
    if (money == 0) {
        bsc_offset = (u8*) UNALIGNED_32_GET(bsc_offset + 1);
    } else {
        bsc_offset += 5;
    }
}