#include "types.h"
#include "battle/state.h"
#include "battle/controller.h"
#include "battle/battler.h"
#include "battle/communication.h"
#include "constants/battle/battle_handicaps.h"
#include "vars.h"
#include "abilities.h"
#include "constants/pokemon_types.h"
#include "battle/battlescript.h"
#include "debug.h"
#include "battle/attack.h"
#include "attack.h"
#include "constants/attack_results.h"
#include "prng.h"
#include "battle/battle_string.h"
#include "constants/attacks.h"

extern u8 battlescript_handicap_extreme_heat[];
extern u8 battlescript_handicap_floating_rocks[];
extern u8 battlescript_handicap_grassy_field[];
extern u8 battlescript_handicap_terrifying_atmosphere[];
extern u8 battlescript_handicap_arena_encouragement[];
extern u8 battlescript_handicap_groudon_magnitude[];
extern u8 battlescript_handicap_focused_fighter[];

static u8 *battlescripts_handicap[32] = {
    [BATTLE_HANDICAP_FLOATING_ROCKS] = battlescript_handicap_floating_rocks,
    [BATTLE_HANDICAP_GRASSY_FIELD] = battlescript_handicap_grassy_field,
    [BATTLE_HANDICAP_ARENA_ENCOURAGEMENT] = battlescript_handicap_arena_encouragement,
    [BATTLE_HANDICAP_TERRIFYING_ATMOSPHERE] = battlescript_handicap_terrifying_atmosphere,
    [BATTLE_HANDICAP_EXTREME_HEAT] = battlescript_handicap_extreme_heat,
    [BATTLE_HANDICAP_GROUDON_BATTLE] = battlescript_handicap_groudon_magnitude,
    [BATTLE_HANDICAP_FOCUSED_FIGHTERS] = battlescript_handicap_focused_fighter,
};

void battle_introduce_handicap() {
    if (battler_marked_for_controller_execution)
        return;
    if (battle_flags & BATTLE_WITH_HANDICAP) {
        while (BATTLE_STATE2->handicap_introduced < 32) {
            bool script_initialized = false;
            if (fmem.battle_handicaps & int_bitmasks[BATTLE_STATE2->handicap_introduced]) {
                if (battlescripts_handicap[BATTLE_STATE2->handicap_introduced]) {
                    if (BATTLE_STATE2->handicap_introduced == BATTLE_HANDICAP_GROUDON_BATTLE) {
                        battle_scripting.battler_idx = 1; // Opponent's battler 1
                        battle_animation_move_power = 100;
                    }
                    battlescript_init_and_interrupt_battle(battlescripts_handicap[BATTLE_STATE2->handicap_introduced]);
                    script_initialized = true;
                }
            } 
            BATTLE_STATE2->handicap_introduced++;
            if (script_initialized)
                return;
        }
    }
    // Directly execute switch-in effects for handicaps
    while(BATTLE_STATE2->switch_in_handicap_effects_cnt < battler_cnt) {
        bool script_initialized = false;
        if (battle_handicap_switch_in_effects(BATTLE_STATE2->switch_in_handicap_effects_cnt))
            script_initialized = true;
        BATTLE_STATE2->switch_in_handicap_effects_cnt++;
        if (script_initialized)
            return;
    }

    battle_main_callback = battle_aggresive_battlers_introduce;
}

void battle_handicap_set() {
    fmem.battle_handicaps |= int_bitmasks[*var_access(0x8004)];
}

void battle_handicap_clear() {
    fmem.battle_handicaps = 0;
}

extern u8 battlescript_handicap_extreme_heat_apply[];
extern u8 battlescript_handicap_grassy_field_apply[];
extern u8 battlescript_handicap_focused_fighter_apply[];

bool battle_handicap_switch_in_effects(u8 battler_idx) {
    if (!(battle_flags & BATTLE_WITH_HANDICAP)) 
        return false;
    for (int i = 0; i < 32; i++) {
        if (fmem.battle_handicaps & int_bitmasks[i]) { // Activate the i-th battle handicap for this battler
            switch (i) {
                case BATTLE_HANDICAP_EXTREME_HEAT: {
                    if (battlers[battler_idx].max_hp > 0 && !(battlers[battler_idx].status1 & STATUS1_ANY) &&
                        battlers[battler_idx].ability != AQUAHUELLE && battlers[battler_idx].type1 != TYPE_FEUER && 
                        battlers[battler_idx].type2 != TYPE_FEUER && !battle_side_statuses[battler_idx].status_safeguard
                        && !(BATTLE_STATE2->status_custom_persistent[battler_idx] & CUSTOM_STATUS_PERSISTENT_HANDICAP_APPLIED)) { 
                        // Battler can be affected by extreme heat
                        dprintf("Execute extreme heat for battler %d\n", battler_idx);
                        attacking_battler = battler_idx; // Set those for synchronize I suppose...
                        defending_battler = battler_idx; 
                        battle_scripting.battler_idx = battler_idx;
                        BATTLE_STATE2->status_custom_persistent[battler_idx] |= CUSTOM_STATUS_PERSISTENT_HANDICAP_APPLIED; // Prevent looping
                        battle_communication[BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE] = 0x43;
    	                battlescript_init_and_interrupt_battle(battlescript_handicap_extreme_heat_apply);
                        return true;
                    }
                    break;
                }
                case BATTLE_HANDICAP_GRASSY_FIELD: {
                    if (battlers[battler_idx].max_hp > 0 && !(battler_statuses3[battler_idx] & STATUS3_ROOTED) &&
                        (battlers[battler_idx].type1 == TYPE_PFLANZE || battlers[battler_idx].type2 == TYPE_PFLANZE)
                        && !(BATTLE_STATE2->status_custom_persistent[battler_idx] & CUSTOM_STATUS_PERSISTENT_HANDICAP_APPLIED)) {
                        battler_statuses3[battler_idx] |= STATUS3_ROOTED;
                        attacking_battler = battler_idx;
                        defending_battler = battler_idx; 
                        battle_scripting.battler_idx = battler_idx;
                        BATTLE_STATE2->status_custom_persistent[battler_idx] |= CUSTOM_STATUS_PERSISTENT_HANDICAP_APPLIED; // Prevent looping
    	                battlescript_init_and_interrupt_battle(battlescript_handicap_grassy_field_apply);
                        return true;
                    }
                    break;
                }
            case BATTLE_HANDICAP_FOCUSED_FIGHTERS: {
                if (battlers[battler_idx].max_hp > 0 && (battlers[battler_idx].type1 == TYPE_KAMPF || battlers[battler_idx].type2 == TYPE_KAMPF) && 
                    (battlers[battler_idx].stat_changes[STAT_ATTACK] < 12 || battlers[battler_idx].stat_changes[STAT_ACCURACY] < 12)
                     && !(BATTLE_STATE2->status_custom_persistent[battler_idx] & CUSTOM_STATUS_PERSISTENT_HANDICAP_APPLIED) ) {
                        attacking_battler = battler_idx;
                        defending_battler = battler_idx; 
                        battle_scripting.battler_idx = battler_idx;
                        BATTLE_STATE2->status_custom_persistent[battler_idx] |= CUSTOM_STATUS_PERSISTENT_HANDICAP_APPLIED; // Prevent looping
    	                battlescript_init_and_interrupt_battle(battlescript_handicap_focused_fighter_apply);
                        return true;
                    }
                    break;
                }
            }
        }
    }
    return false;
}

extern u8 battlescript_handicap_floating_rocks_apply[];

bool battle_handicap_before_attack_events() {
    BATTLE_STATE2->status_custom[defending_battler] &= (u32)(~(CUSTOM_STATUS_FLOATING_ROCKS));
    if (!(battle_flags & BATTLE_WITH_HANDICAP)) 
        return false;
    /** 
     * This is not the effect of floating rocks anymore: Instead of lowering all damage, rock type mons have no weakness now
    if (fmem.battle_handicaps & int_bitmasks[BATTLE_HANDICAP_FLOATING_ROCKS] && 
        (battlers[defending_battler].type1 == TYPE_GESTEIN || battlers[defending_battler].type2 == TYPE_GESTEIN)
        && battler_is_opponent(attacking_battler) != battler_is_opponent(defending_battler) && attacks[active_attack].base_power != 0) {
            battle_animation_user = defending_battler;
            battle_animation_target = defending_battler;
            battle_scripting.battler_idx = defending_battler;
            battlescript_callstack_push_next_command();
            BATTLE_STATE2->status_custom[defending_battler] |= CUSTOM_STATUS_FLOATING_ROCKS;
            bsc_offset = battlescript_handicap_floating_rocks_apply;
            return true;
    }
    **/
    return false;
}

extern u8 battlescript_handicap_arena_encouragement_apply[];

bool battle_handicap_attack_done() {
    if (!(battle_flags & BATTLE_WITH_HANDICAP)) 
        return false;
    battler *attacker = battlers + attacking_battler;
    // Apply handicap rules, step by step, the current state is fmem.gp_value
    if (BATTLE_STATE2->switch_in_handicap_effects_cnt == BATTLE_HANDICAP_ARENA_ENCOURAGEMENT && (fmem.battle_handicaps & int_bitmasks[BATTLE_HANDICAP_ARENA_ENCOURAGEMENT]) &&
            !(attack_result & (ATTACK_MISSED | ATTACK_NO_EFFECT | ATTACK_FAILED)) && 
            attacks[active_attack].base_power &&
            !battler_statuses[attacking_battler].hurt_in_confusion && DAMAGE_CAUSED
            && attacker->stat_changes[1] < 12 && 
            (attacker->type1 == TYPE_KAMPF || attacker->type2 == TYPE_KAMPF) &&
            attacks[active_attack].type == TYPE_KAMPF){
            //dprintf("Handicap attack done with attacker %d\n", attacking_battler);
            attacker->stat_changes[1]++; // attack boost
            battle_scripting.battler_idx = attacking_battler;
            battle_scripting.animation_user = attacking_battler;
            battle_scripting.animation_targets = attacking_battler;
            battle_animation_user = attacking_battler;
            battle_animation_target = attacking_battler;
            effect_battler = attacking_battler;
            battlescript_callstack_push_next_command();
            bsc_offset = battlescript_handicap_arena_encouragement_apply;
            return true;
    }
    return false;
}

static u32 magnitude_p[] = {
    5, 10, 20, 30, 20, 10, 5
};

static u16 groudon_magnitude_magnitude_power[] = {
    10, 20, 25, 30, 50, 65, 80
};

void battle_handicap_groudon_calculate_damage() {
    active_attack = ATTACK_INTENSITAET;
    size_t magnitude = choice(magnitude_p, ARRAY_COUNT(magnitude_p), NULL) + 4;
    // The lower Groudon's health, the higher the magnitude
    size_t increase = (size_t)((battlers[1].max_hp - battlers[1].current_hp) * 4 / battlers[1].max_hp);
    dprintf("Magnitude %d, increase %d, total %d\n", magnitude, increase, MIN(10, magnitude + increase));
    magnitude = MIN(10, magnitude + increase);
    battle_dynamic_base_power = groudon_magnitude_magnitude_power[magnitude - 4];
    // Find a target
    for (defending_battler = 0; defending_battler < battler_cnt; defending_battler++) {
        if (defending_battler != attacking_battler && !(battlers_absent & int_bitmasks[defending_battler])) break;
    }
    BSC_BUFFER_NUMBER(bsc_string_buffer0, 2, magnitude);
}

extern u8 battlescript_handicap_groudon_magnitude_hit[];

bool battle_handicap_end_turn_effects() {
    if (!(battle_flags & BATTLE_WITH_HANDICAP)) 
        return false;
    bool effect = false;
    while (BATTLE_STATE2->end_of_turn_handicap_effects_cnt < 32) {
        if (fmem.battle_handicaps & int_bitmasks[BATTLE_STATE2->end_of_turn_handicap_effects_cnt]) {
            switch (BATTLE_STATE2->end_of_turn_handicap_effects_cnt) {
                case BATTLE_HANDICAP_GROUDON_BATTLE: 
                    if (rnd16() & 1) {
                        attacking_battler = 1; // Groudon
                        battle_scripting.battler_idx = attacking_battler;
                        battlescript_init_and_push_current_callback(battlescript_handicap_groudon_magnitude_hit);
                        effect = true;
                    }
                    break;
            }
        }
        BATTLE_STATE2->end_of_turn_handicap_effects_cnt++;
        if (effect)
            return true;
    }
    return false;
}