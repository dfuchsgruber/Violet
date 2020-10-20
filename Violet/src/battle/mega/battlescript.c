#include "types.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "battle/controller.h"
#include "battle/battlescript.h"
#include "constants/battle/battle_results.h"
#include "constants/battle/battle_actions.h"
#include "save.h"
#include "mega.h"
#include "debug.h"
#include "abilities.h"
#include "pokemon/virtual.h"
#include "constants/pokemon_attributes.h"
#include "constants/pokemon_stat_names.h"
#include "pokemon/basestat.h"
#include "battle/battle_string.h"
#include "overworld/pokemon_party_menu.h"
#include "language.h"
#include "text.h"
#include "pokemon/names.h"
#include "vars.h"
#include "trainer/trainer.h"

extern u8 battlescript_mega_evolution[];
extern u8 battlescript_regent_evolution[];

void battler_update_after_form_change(u8 battler_idx) {
    int party_idx = battler_idx_to_party_idx(battler_idx);
    pokemon *mon = !battler_is_opponent(battler_idx) ? player_pokemon + party_idx : opponent_pokemon + party_idx;
    u16 species = (u16) pokemon_get_attribute(mon, ATTRIBUTE_SPECIES, NULL);
    battlers[battler_idx].species = species;
    battlers[battler_idx].current_hp = (u16) pokemon_get_attribute(mon, ATTRIBUTE_CURRENT_HP, NULL);
    battlers[battler_idx].max_hp = (u16) pokemon_get_attribute(mon, ATTRIBUTE_TOTAL_HP, NULL);
    for (int i = 0; i < 5; i++)
        battlers[battler_idx].stats[i] = (u16) pokemon_get_attribute(mon, (u8)(ATTRIBUTE_ATK + i), NULL);
    battlers[battler_idx].type1 = basestats[species].type1;
    battlers[battler_idx].type2 = basestats[species].type2;
    battlers[battler_idx].ability = pokemon_get_ability(mon);
}

void battler_form_change(u8 battler_idx, u16 species) {
    int party_idx = battler_idx_to_party_idx(battler_idx);
    pokemon *mon = !battler_is_opponent(battler_idx) ? player_pokemon + party_idx : opponent_pokemon + party_idx;
    // dprintf("Mon is %x for battler %d\n", mon, battler_idx);
    pokemon_set_attribute(mon, ATTRIBUTE_SPECIES, &species);
    pokemon_calculate_stats(mon);
    battler_update_after_form_change(battler_idx);
    // Emit event for link-consistency: TODO: Which request to emit? Set all mon data should cover everything...
    battle_controller_emit_set_pokemon_data(0, 0, 0, sizeof(battler), battlers + battler_idx); // Request: SET_ALL_MON_DATA ??
    battler_mark_for_controller_execution(battler_idx);
}

bool battle_execute_action_mega_evolution() {
    // dprintf("Exectute mega in state %d\n", MEGA_STATE.mega_action_state);
    switch (MEGA_STATE.mega_action_state) {
        case MEGA_ACTION_INITIALIZE:
            MEGA_STATE.mega_action_current_slot = 0;
            MEGA_STATE.mega_action_state = MEGA_ACTION_CHECK;
            FALL_THROUGH;
        case MEGA_ACTION_CHECK:
        case MEGA_ACTION_CHECK_MEGA_EVOLUTION_PERFORMED: {
            for (; MEGA_STATE.mega_action_current_slot < battler_cnt; MEGA_STATE.mega_action_current_slot++) {
                u8 battler_idx = battler_attacking_order[MEGA_STATE.mega_action_current_slot];
                if (MEGA_STATE.marked_for_mega_evolution[battler_idx]) {
                    // Perform a mega evolution
                    mega_evolution_t *mega_evolution = battler_get_available_mega_evolution(battler_idx);
                    if (mega_evolution) {
                        // Find the trainer idx of the battler
                        u16 trainer_idx = 0xFFFF;
                        switch (battler_get_position(battler_idx)) {
                            case BATTLE_POSITION_PLAYER_RIGHT:
                                if (battle_flags & BATTLE_ALLY) {
                                    trainer_idx = *var_access(VAR_ALLY);
                                }
                                break;
                            case BATTLE_POSITION_OPPONENT_RIGHT:
                                if (battle_flags & BATTLE_TWO_TRAINERS) {
                                    trainer_idx = fmem.trainer_varsB.trainer_id;
                                    break;
                                }
                                FALL_THROUGH;
                            case BATTLE_POSITION_OPPONENT_LEFT:
                                trainer_idx = trainer_vars.trainer_id;
                                break;
                        }
                        // dprintf("Trainer idx for the string is %d\n", trainer_idx);
                        if (trainer_idx == 0xFFFF) { // Player
                            bsc_string_buffer0[0] = 0xFF; // No trainer class
                            strcpy(bsc_string_buffer1, save2->player_name);
                        } else {
                            u8 *dst = strcpy(bsc_string_buffer0, trainer_class_names[trainers[trainer_idx].trainerclass]);
                            dst[0] = 0; dst[1] = 0xFF; // Spacing between two buffers
                            strcpy(bsc_string_buffer1, trainers[trainer_idx].name);
                        }
                        bsc_last_used_item = mega_evolution->mega_item;
                        battle_scripting.battler_idx = battler_idx; // Target for non-buffer-strings (after species transform)
                        battler_form_change(battler_idx, mega_evolution->mega_species);
                        if (mega_evolution->type == MEGA_EVOLUTION)
                            MEGA_STATE.owner_mega_evolved[battler_get_owner(battler_idx)] = 1;
                        if (MEGA_STATE.marked_for_mega_evolution[battler_idx] == MEGA_EVOLUTION)
                            battlescript_init_and_interrupt_battle(battlescript_mega_evolution);
                        else if (MEGA_STATE.marked_for_mega_evolution[battler_idx] == REGENT_EVOLUTION) {
                            battlescript_init_and_interrupt_battle(battlescript_regent_evolution);
                        } else {
                            derrf("Unkown mega type for script initialization %d\n", MEGA_STATE.marked_for_mega_evolution[battler_idx]);
                        }
                    } else {
                        dprintf("Battler %d appearently was marked for mega evolution but has no available mega evolution. That is weird and should not happen...", battler_idx);
                    }
                    active_battler = battler_idx;
                    MEGA_STATE.mega_action_state = MEGA_ACTION_BATTLE_ENTER_ABILITIES;
                    MEGA_STATE.marked_for_mega_evolution[battler_idx] = 0;
                    // dprintf("Returning true\n");
                    return true;
                }
            }
            // No battler did perform any more mega evolutions
            MEGA_STATE.mega_action_state = MEGA_ACTION_INTIMIDATE;
            break;
        }
        case MEGA_ACTION_BATTLE_ENTER_ABILITIES: {
            u8 battler_idx = battler_attacking_order[MEGA_STATE.mega_action_current_slot];
            ability_execute(ABILITY_CONTEXT_ENTER, battler_idx, 0, 0, 0);
            MEGA_STATE.mega_action_state = MEGA_ACTION_CHECK;
            break;
        }
        case MEGA_ACTION_INTIMIDATE: {
            if (ability_execute(ABILITY_CONTEXT_INTIMIDATE_1, 0, 0, 0, 0))
                break;
            if (ability_execute(ABILITY_CONTEXT_INTIMIDATE_2, 0, 0, 0, 0))
                break;
            MEGA_STATE.mega_action_current_slot = 0;
            MEGA_STATE.mega_action_state = MEGA_ACTION_DONE; // Check the next battler for a potential mega evolution
            break;
        }
        case MEGA_ACTION_DONE: { // No more mega evolutions to perform
            MEGA_STATE.mega_action_state = MEGA_ACTION_INITIALIZE;
            return false;
        }
    }
    return true;
}


