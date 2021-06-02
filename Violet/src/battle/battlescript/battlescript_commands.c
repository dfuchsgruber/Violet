#include "types.h"
#include "battle/battler.h"
#include "battle/battlescript.h"
#include "battle/communication.h"
#include "mega.h"
#include "debug.h"
#include "battle/bg.h"
#include "constants/battle/battle_bgs.h"
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
#include "overworld/pokemon_party_menu.h"
#include "item/item_effect.h"
#include "abilities.h"
#include "item/item.h"
#include "attack.h"
#include "constants/item_hold_effects.h"
#include "constants/battle/battle_handicaps.h"

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
    if (battlers[active_battler].species == POKEMON_DURENGARD_OFFENSIVE) {
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
            if (POKEMON_IS_VIABLE(party + j) && battler_idx_to_party_idx(active_battler) != j && battler_idx_to_party_idx(partner) != j) {
                bsc_offset = bsc_offset + 6;
                return;
            }
        }
    }
    bsc_offset = (u8*)UNALIGNED_32_GET(bsc_offset + 2);
}

bool bsc_cmd_x8f_random_switch_out_replace_in_wild_double_battle() {
    return (BATTLE_IS_WILD_DOUBLE && battler_is_opponent(attacking_battler) && !battler_is_opponent(defending_battler) &&
            battler_is_alive(defending_battler) && battler_is_alive(PARTNER(defending_battler))) ||
        (BATTLE_IS_WILD_DOUBLE && !battler_is_opponent(attacking_battler) && !battler_is_opponent(defending_battler));
}



void bsc_roar_failure() {
    if (BATTLE_IS_WILD_DOUBLE) {
        // dprintf("Roar failure in double wild battles.\n");
        // Roar fails if a) player uses it against two wild mons b) a wild mon uses it against a wild mon
        if (!battler_is_opponent(attacking_battler) && battler_is_opponent(defending_battler) && battler_is_alive(defending_battler) &&
            battler_is_alive(PARTNER(defending_battler))) {
            bsc_offset = battlescript_attack_failed_no_pp_reduce;
        } else if (battler_is_opponent(attacking_battler) && battler_is_opponent(defending_battler)) {
            bsc_offset = battlescript_attack_failed_no_pp_reduce;
        }
    }
}

void bsc_cmd_x8f_random_switch_out() {
     if ((battle_flags & BATTLE_TRAINER) || bsc_cmd_x8f_random_switch_out_replace_in_wild_double_battle()) { 
        // A new target is selectable in the following cases
        // a) trainer battles
        // b) wild double battles, when the wild pokemon attacks the player and both player mons are alive
        // c) wild double battles, when the player attacks his partner
        dprintf("Random switchout forced, select something.\n");
        u8 first = 6, last = 6, partner = 4, foe = 4, foe_partner = 4;
        pokemon *party = battler_load_party_range(defending_battler, &first, &last);
        battler_get_partner_and_foes(defending_battler, &partner, &foe, &foe_partner);
        int num_valid_targets = 0;
        u8 valid_targets[6] = {0xFF};
        for (u8 j = first; j < last; j++) {
            if (POKEMON_IS_VIABLE(party + j) && battler_idx_to_party_idx(defending_battler) != j && battler_idx_to_party_idx(partner) != j) {
                valid_targets[num_valid_targets++] = j;
            }
        }
        if (num_valid_targets < 1) {
            bsc_offset = (u8*) UNALIGNED_32_GET(bsc_offset + 1);
            return;
        }
        // Roar should succeed regardless of the level, like in generations >= V, so if we reach this point, roar will succed!
        u8 switch_into = valid_targets[rnd16() % num_valid_targets];
        battle_state->battler_to_switch_into[defending_battler] = switch_into;
        if (!battle_is_multi_double() && !battle_is_tag()) {
            sub_08013ef0(defending_battler);
        }
        battle_link_multi_switch_party_order(defending_battler, switch_into, 0);
        battle_link_multi_switch_party_order(PARTNER(defending_battler), switch_into, 1);
        bsc_offset = bsc_roar_success_force_out;
        
    } else {
        // Roar will succced regardless of the level, like in generations >= V, so if we reach this point roar will succed!
        dprintf("Roar ends battle.\n");
        bsc_offset = bsc_roar_sucess_end_battle;
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
    return money / 2048;
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
        case DIFFICULTY_EASY: money -= money / 2; break;
        case DIFFICULTY_HARD: money *= 2; break;
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
            case DIFFICULTY_EASY: money += money / 2; break;
            case DIFFICULTY_HARD: money /= 2; break;
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

void bsc_cmd_opponent_use_item() {
    battler_in_party_menu = attacking_battler;
    dprintf("Bsc opp use item for attacking battler %d\n", attacking_battler);
    pokemon *p = (battler_is_opponent(attacking_battler) ? opponent_pokemon : player_pokemon) + battler_idx_to_party_idx(attacking_battler);
    item_effect(p, bsc_last_used_item, battler_idx_to_party_idx(attacking_battler), 0, true, false);
    bsc_offset++;
}


bool bsc_cmd_exp_gain_should_gain_exp() {
    u8 idx = battle_state->exp_getter_idx;
    if (battle_is_tag() && (idx == 3 || idx == 4 || idx == 5)) return false;
    return pokemon_get_attribute(player_pokemon + idx, ATTRIBUTE_LEVEL, 0) < 100;
}

bool bsc_cmd_switch_in_effects_check_ability_or_handicap() {
    if (ability_execute(ABILITY_CONTEXT_ENTER, active_battler, 0, 0, 0)) return true;
    if (battle_handicap_switch_in_effects(active_battler)) return true;
    return false;
}

void bsc_cmd_before_attack() {
    BATTLE_STATE2->status_custom[attacking_battler] &= (u32)(~(CUSTOM_STATUS_ATTACK_WEAKENED_BY_BERRY | CUSTOM_STATUS_GEM_USED));
    bool effect = false;
    while(!effect) {
        dprintf("Executing before attack events in state %d\n", BATTLE_STATE2->before_attack_state);
        switch (BATTLE_STATE2->before_attack_state) {
            case 0: { // Abilities
                if (battle_abilities_before_attack())
                    effect = true;
                BATTLE_STATE2->before_attack_state++;
                if (effect)
                    return;
                break;
            }
            case 1: {
                if (battle_handicap_before_attack_events())
                    effect = true;
                BATTLE_STATE2->before_attack_state++;
                if (effect)
                    return;
                break;
            }
            case 2: {
                if (battle_item_before_attack_attacker())
                    effect = true;
                BATTLE_STATE2->before_attack_state++;
                if (effect)
                    return;
                break;
            }
            case 3: {
                if (battle_item_before_attack_defender())
                    effect = true;
                BATTLE_STATE2->before_attack_state++;
                if (effect)
                    return;
                break;

            }
            default:
                bsc_offset++;
                return;
        }
    }

}
 
void bsc_cmd_x49_attack_done_new() {
    if (battle_scripting.attack_done_state <= 17) {
        bsc_cmd_x49_attack_done();
    }
    // The args of x49 control which states shall be executed: Mode 1 executes only one distinct state
    // Mode 2 executes states smaller than last_state
    u8 mode = bsc_offset[1];
    if (mode == 1) {
        BATTLE_STATE2->attack_done_substate = 255; // Only one state was supposed to be executed whatsoever
    }; 
    u8 last_state = bsc_offset[2];
    // dprintf("mode is %d, arg is %d\n", mode, last_state);
    switch (battle_scripting.attack_done_state) {
        case 0 ... 17: return; // The original function has not terminated 
        case 18: { // We enter this case when the original function whould have terminated
            //dprintf("Initialize new attack done effects.\n");
            BATTLE_STATE2->attack_done_substate = 0;
            BATTLE_STATE2->switch_in_handicap_effects_cnt = 0;
            battle_scripting.attack_done_state++;
            break;
        }
        case 19: {
            // Yeah, this executes all new attack_done effects after all the other, but who cares tbh
            // Just watch out to respect the limits of the original function
            bool effect = false;
            while (!effect) {
                dprintf("Executing substate %d\n", BATTLE_STATE2->attack_done_substate);
                switch(BATTLE_STATE2->attack_done_substate) {
                    case 0: {
                        if (mode != 2 || last_state > 5) { // State 5 is the original attacker abilities (i.e. synchronize)
                            if (battle_abilities_attack_done_attacker_new()) {
                                effect = true;
                            }
                        }
                        BATTLE_STATE2->attack_done_substate++;
                        break;
                    }
                    case 1: {
                        if (mode != 2 || last_state > 3) { // State 3 is the original defender abilities
                            if (battle_abilities_attack_done_defender_new()) {
                                effect = true;
                            }
                        }
                        BATTLE_STATE2->attack_done_substate++;
                        break;
                    }
                    case 2: {
                        if (mode != 2 || last_state > 12) { // 12 is the kings-rock / shell-bell state
                            if (battle_items_attack_done_new()) {
                                effect = true;
                            }
                        }
                        BATTLE_STATE2->attack_done_substate++;
                        break;
                    }
                    case 3: {
                        if (mode != 2 || last_state > 11) { // 11 are battle items for all battlers
                            if (battle_items_attack_done_defender()) {
                                effect = true;
                            }
                        }
                        BATTLE_STATE2->attack_done_substate++;
                        break;
                    }
                    case 4 : {
                        if (mode != 2 || last_state > 16) { // Only if all effects will be executed, we consider gunpowder
                            if (battle_items_gunpowder()) effect = true;
                        }
                        BATTLE_STATE2->attack_done_substate++;
                        break;
                    }
                    case 5 : {
                        if (mode != 2 || last_state > 16) { // Only if all effects will be executed, we consider life-orb
                            if (battle_items_life_orb()) effect = true;
                        }
                        BATTLE_STATE2->attack_done_substate++;
                        break;
                    }
                    case 6: {
                        if ((mode != 2 || last_state > 16) 
                            && BATTLE_STATE2->switch_in_handicap_effects_cnt < 32) { // Only when all attack-end effects are executed, we consider handicaps...
                            if (battle_handicap_attack_done())
                                effect = true;
                            BATTLE_STATE2->switch_in_handicap_effects_cnt++; // Next step -> Next Check next handycap
                        } else {
                            BATTLE_STATE2->attack_done_substate++;
                        }
                        break;
                    }
                    case 255:
                    default: { // Termination
                        bsc_offset += 3;
                        return;
                    }
                }
            }
        }
    }
}

void bsc_teleport_set_outcome() {
    active_battler = attacking_battler;
    if ((battle_flags & BATTLE_DOUBLE) && battler_is_opponent(active_battler) && battler_is_alive(PARTNER(active_battler))) {
        dprintf("Setting teleport outcome s.t. the battle goes on.\n");
        // Teleporting only "removes" the teleported mon, but the battle continues
        battlers_absent |= (u8)int_bitmasks[active_battler];
        bsc_status_flags |= BSC_STATUS_FLAG_FAINTED(active_battler);
        battlers[active_battler].current_hp = 0;
        pokemon_set_attribute(opponent_pokemon + battler_idx_to_party_idx(active_battler), ATTRIBUTE_CURRENT_HP, &battlers[active_battler].current_hp);
        battle_healthbox_set_invisible(battle_healthbox_oams[active_battler]);
        battle_clear_active_battler_data();
    } else if (battler_is_opponent(active_battler)) {
        dprintf("Setting teleport outcome s.t. the opponent fled.\n");
        // TODO: BATTLE_RESULT_OPPONENT_TELEPORTED is not supported by the engine so far, maybe we should?
        battle_result = BATTLE_RESULT_PLAYER_TELEPORTED;
    } else {
        dprintf("Setting teleport outcome s.t. the player fled.\n");
        battle_result = BATTLE_RESULT_PLAYER_TELEPORTED;
    }
}

void bsc_command_x06_typecalc() {
    u8 move_type;
    if (active_attack == ATTACK_VERZWEIFLER) {
        ++bsc_offset;
        return;
    }
    GET_MOVE_TYPE(active_attack, move_type);

    // check stab
    if (IS_BATTLER_OF_TYPE(attacking_battler, move_type)) {
        damage_apply_multiplier(1500);
    }
    if (battlers[defending_battler].ability == SCHWEBE && move_type == TYPE_BODEN) {
        defending_battler_ability = battlers[defending_battler].ability;
        attack_result |= (ATTACK_MISSED | ATTACK_NO_EFFECT);
        battler_last_landed_move[defending_battler] = 0;
        battler_last_hit_by_type[defending_battler] = 0;
        battle_communication[6] = move_type;
        battle_record_ability(defending_battler, defending_battler_ability);
    } else {
        bool no_weakness = false;
        if ((battle_flags & BATTLE_WITH_HANDICAP) && (fmem.battle_handicaps & int_bitmasks[BATTLE_HANDICAP_FLOATING_ROCKS]) &&
            (battlers[defending_battler].type1 == TYPE_GESTEIN || battlers[defending_battler].type2 == TYPE_GESTEIN)) {
                no_weakness = true;
            } 
        for (int i = 0; type_effectivenesses[i].attacker != 0xFF; i++) {
            if (type_effectivenesses[i].attacker == 0xFE) {
                if (battlers[defending_battler].status2 & STATUS2_FORESIGHT)
                    break;
            if (type_effectivenesses[i].multiplicator == 20 && no_weakness)
                continue;
            } else if (type_effectivenesses[i].attacker == move_type) {
                if (type_effectivenesses[i].defender == battlers[defending_battler].type1)
                    battle_add_damage_multiplier_and_update_attack_result(type_effectivenesses[i].multiplicator);
                if (type_effectivenesses[i].defender == battlers[defending_battler].type2 &&
                    battlers[defending_battler].type1 != battlers[defending_battler].type2)
                    battle_add_damage_multiplier_and_update_attack_result(type_effectivenesses[i].multiplicator);
            }
        }
    }
    if (battlers[defending_battler].ability == WUNDERWACHE
        && battler_get_charging_state(attacking_battler, active_attack) == CHARGING_STATE_NOT_CHARGING
        && (!(attack_result & ATTACK_SUPER_EFFECTIVE) || 
            ((attack_result & (ATTACK_SUPER_EFFECTIVE | ATTACK_NOT_EFFECTIVE)) == (ATTACK_SUPER_EFFECTIVE | ATTACK_NOT_EFFECTIVE)))
        && attacks[active_attack].base_power > 0) {
            defending_battler_ability = WUNDERWACHE;
            attack_result |= ATTACK_MISSED;
            battler_last_landed_move[defending_battler] = 0;
            battler_last_hit_by_type[defending_battler] = 0;
            battle_communication[6] = 3;
            battle_record_ability(defending_battler, defending_battler_ability);
    }
    if (attack_result & ATTACK_NO_EFFECT)
        battler_statuses[attacking_battler].target_unaffected = 1;
    if ((attack_result & (ATTACK_SUPER_EFFECTIVE | ATTACK_NOT_EFFECTIVE)) == (ATTACK_SUPER_EFFECTIVE) && !(attack_result | ATTACK_MISSED) 
        && attacks[active_attack].base_power > 0) {
        BATTLE_STATE2->status_custom[attacking_battler] |= CUSTOM_STATUS_ATTACK_WEAKENED_BY_BERRY;
    }
    ++bsc_offset;
}

void bsc_command_x4a_typecalc2() {
    // Does not apply any multipliers
    u8 move_type;
    GET_MOVE_TYPE(active_attack, move_type);

    if (battlers[defending_battler].ability == SCHWEBE && move_type == TYPE_BODEN) {
        defending_battler_ability = battlers[defending_battler].ability;
        attack_result |= ATTACK_MISSED | ATTACK_NO_EFFECT;
        battler_last_landed_move[defending_battler] = 0;
        battler_last_hit_by_type[defending_battler] = 0;
        battle_communication[6] = move_type;
        battle_record_ability(defending_battler, defending_battler_ability);
    } else {
        bool no_weakness = false;
        if ((battle_flags & BATTLE_WITH_HANDICAP) && (fmem.battle_handicaps & int_bitmasks[BATTLE_HANDICAP_FLOATING_ROCKS]) &&
            (battlers[defending_battler].type1 == TYPE_GESTEIN || battlers[defending_battler].type2 == TYPE_GESTEIN)) {
                no_weakness = true;
            } 
        for (int i = 0; type_effectivenesses[i].attacker != 0xFF; i++) {
            if (type_effectivenesses[i].attacker == 0xFE) {
                if (battlers[defending_battler].status2 & STATUS2_FORESIGHT) {
                    break;
                } else {
                    continue;
                }
            }
            if (type_effectivenesses[i].attacker == move_type) {
                if (type_effectivenesses[i].defender == battlers[defending_battler].type1) {
                    if (type_effectivenesses[i].multiplicator == 0) {
                        attack_result |= ATTACK_NO_EFFECT;
                        break;
                    } else if (type_effectivenesses[i].multiplicator == 5) {
                        attack_result |= ATTACK_NOT_EFFECTIVE;
                    } else if (type_effectivenesses[i].multiplicator == 20 && !no_weakness) {
                        attack_result |= ATTACK_SUPER_EFFECTIVE;
                    }
                }
                if (type_effectivenesses[i].defender == battlers[defending_battler].type2 &&
                    battlers[defending_battler].type1 != battlers[defending_battler].type2) {
                    if (type_effectivenesses[i].multiplicator == 0) {
                        attack_result |= ATTACK_NO_EFFECT;
                        break;
                    } else if (type_effectivenesses[i].multiplicator == 5) {
                        attack_result |= ATTACK_NOT_EFFECTIVE;
                    } else if (type_effectivenesses[i].multiplicator == 20 && !no_weakness) {
                        attack_result |= ATTACK_SUPER_EFFECTIVE;
                    }
                }
            }
        }
    }
    if (battlers[defending_battler].ability == WUNDERWACHE
        && battler_get_charging_state(attacking_battler, active_attack) == CHARGING_STATE_NOT_CHARGING
        && (!(attack_result & ATTACK_SUPER_EFFECTIVE) || 
            ((attack_result & (ATTACK_SUPER_EFFECTIVE | ATTACK_NOT_EFFECTIVE)) == (ATTACK_SUPER_EFFECTIVE | ATTACK_NOT_EFFECTIVE)))
        && attacks[active_attack].base_power > 0) {
            defending_battler_ability = WUNDERWACHE;
            attack_result |= ATTACK_MISSED;
            battler_last_landed_move[defending_battler] = 0;
            battler_last_hit_by_type[defending_battler] = 0;
            battle_communication[6] = 3;
            battle_record_ability(defending_battler, defending_battler_ability);
    }
    if (attack_result & ATTACK_NO_EFFECT)
        battler_statuses[attacking_battler].target_unaffected = 1;
    if ((attack_result & (ATTACK_SUPER_EFFECTIVE | ATTACK_NOT_EFFECTIVE)) == (ATTACK_SUPER_EFFECTIVE) && !(attack_result | ATTACK_MISSED) 
        && attacks[active_attack].base_power > 0) {
        BATTLE_STATE2->status_custom[attacking_battler] |= CUSTOM_STATUS_ATTACK_WEAKENED_BY_BERRY;
    }
    bsc_offset++;
}

extern u8 battlescript_gem_used[];
extern u8 battlescript_weakened_by_berry[];

void bsc_command_after_x07_adjustnormaldamage() {
    dprintf("bsc command 0x7: status custom of attacking battler: 0x%x\n", BATTLE_STATE2->status_custom[attacking_battler]);
    if ((BATTLE_STATE2->status_custom[attacking_battler] & CUSTOM_STATUS_GEM_USED)
        && !(attack_result & ATTACK_NO_EFFECT_ANY) && battlers[attacking_battler].item != 0) {
        bsc_last_used_item = battlers[attacking_battler].item;
        battlescript_callstack_push_next_command();
        bsc_offset = battlescript_gem_used;
        BATTLE_STATE2->status_custom[attacking_battler] &= (u32)(~CUSTOM_STATUS_GEM_USED);
    }
    if ((BATTLE_STATE2->status_custom[attacking_battler] & CUSTOM_STATUS_ATTACK_WEAKENED_BY_BERRY)) {
        bsc_last_used_item = battlers[defending_battler].item;
        battlescript_callstack_push_next_command();
        bsc_offset = battlescript_weakened_by_berry;
        BATTLE_STATE2->status_custom[attacking_battler] &= (u32)(~CUSTOM_STATUS_ATTACK_WEAKENED_BY_BERRY);
    }
}

void bsc_command_x06_typecalc_scan_effectiveness_table(u8 move_type) {
    bool no_weakness = false;
    if ((battle_flags & BATTLE_WITH_HANDICAP) && (fmem.battle_handicaps & int_bitmasks[BATTLE_HANDICAP_FLOATING_ROCKS]) &&
        (battlers[defending_battler].type1 == TYPE_GESTEIN || battlers[defending_battler].type2 == TYPE_GESTEIN)) {
            no_weakness = true;
        } 
    for (int i = 0; type_effectivenesses[i].attacker != 0xFF; i++) {
        if (type_effectivenesses[i].attacker == 0xFE) {
            // If the defender is in foresight, ignore entries after the "marker" 0xFE
            if (battlers[defending_battler].status2 & STATUS2_FORESIGHT)
                break;
        } else if (type_effectivenesses[i].attacker == move_type) {
            // Type 1
            if (battlers[defending_battler].type1 == type_effectivenesses[i].defender) {
                if (!(type_effectivenesses[i].multiplicator == 20 && no_weakness))
                    battle_add_damage_multiplier_and_update_attack_result(type_effectivenesses[i].multiplicator);
            }
            // Type 2
            if (battlers[defending_battler].type2 == type_effectivenesses[i].defender &&
                battlers[defending_battler].type2 != battlers[defending_battler].type1) {
                if (!(type_effectivenesses[i].multiplicator == 20 && no_weakness))
                    battle_add_damage_multiplier_and_update_attack_result(type_effectivenesses[i].multiplicator);
            }
        }
    }
}