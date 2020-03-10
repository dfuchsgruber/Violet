
#include "types.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "pokemon/basestat.h"
#include "battle/attack.h"
#include "math.h"
#include "attack.h"
#include "constants/abilities.h"
#include "constants/pokemon_types.h"
#include "prng.h"
#include "debug.h"
#include "battle/controller.h"
#include "trainer/virtual.h"
#include "trainer/trainer.h"
#include "save.h"
#include "oam.h"
#include "pokemon/sprites.h"
#include "music.h"
#include "battle/ai.h"
#include "abilities.h"
#include "constants/attacks.h"
#include "constants/attack_categories.h"
#include "trainer/trainer.h"
#include "battle/ressources.h"

#define AI_DEBUG_SWITCHING_ON true
#define AI_DEBUG_SWITCHING(str, ...) ({if (AI_DEBUG_SWITCHING_ON) dprintf(str, __VA_ARGS__);})

void battle_ai_attack_apply_effectiveness_multiplier_with_abilities(u8 attack_type, u8 defender_ability, u8 defender_type1, u8 defender_type2, 
    u8 *multiplier) {
    u8 old_multiplier = *multiplier;
    attack_apply_effectiveness_multiplier(attack_type, defender_type1, defender_type2, multiplier);
    if (attack_type == TYPE_BODEN && defender_ability == SCHWEBE) *multiplier = 0;
    if (defender_ability == WUNDERWACHE && *multiplier <= old_multiplier) *multiplier = 0;
    if (defender_ability == FEUERFAENGER && attack_type == TYPE_FEUER) *multiplier = 0;
    if (defender_ability == BLITZFAENGER && attack_type == TYPE_ELEKTRO) *multiplier = 0;
    if (defender_ability == H2O_ABSORBER && attack_type == TYPE_WASSER) *multiplier = 0;
}

bool battle_ai_battler_can_switch_out(u8 idx) {
    bool shadow_tag = ABILITY_ON_TARGET_SIDE(idx, WEGSPERRE);
    bool arena_trap = ABILITY_ON_TARGET_SIDE(idx, AUSWEGSLOS) && battlers[idx].ability != SCHWEBE && battlers[idx].type1 != TYPE_FLUG && battlers[idx].type2 != TYPE_FLUG;
    bool rooted = battler_statuses3[idx] & STATUS3_ROOTED;
    bool escape_prevented_or_wrapped = battlers[idx].status2 & (STATUS2_ESCAPE_PREVENTATION | STATUS2_WRAPPED);
    bool magnet_trap = ABILITY_ON_TARGET_SIDE(idx, MAGNETFALLE) && (battlers[idx].type1 == TYPE_STAHL || battlers[idx].type2 == TYPE_STAHL);
    AI_DEBUG_SWITCHING("Can switch out?\nShadow Tag %d, Arena Trap %d, rooted %d, escape_prevented %d, magnet_trap %d\n",
        shadow_tag, arena_trap, rooted, escape_prevented_or_wrapped, magnet_trap);
    return !(shadow_tag || arena_trap || rooted || escape_prevented_or_wrapped || magnet_trap);
}

bool battler_ai_battler_can_hit_target(u8 battler_idx, u8 target) {
    u8 move_limitations = battler_check_move_limitations(battler_idx, 0, MOVE_LIMITATION_ALL);
    for (int i = 0; i < 4; i++) { // Check if the user has any move that can do damage
        if (!(move_limitations & int_bitmasks[i])) {
            u8 multiplier = 8;
            battle_ai_attack_apply_effectiveness_multiplier_with_abilities(attacks[battlers[battler_idx].moves[i]].type, 
                battlers[target].ability, battlers[target].type1, battlers[target].type2, &multiplier);
            if (multiplier > 0) {
                AI_DEBUG_SWITCHING("Battler %d can hit %d with move idx %d (%d)\n", battler_idx, target, i, battlers[battler_idx].moves[i]);
                return true; // The current battler can hit the target
            }
        }
    }
    AI_DEBUG_SWITCHING("Battler %d can't hit %d with any move.\n", battler_idx, target);
    return false;
}

u8 battle_ai_should_switch_if_wonderguard(int *score) {
    u8 first = 0, last = 0, partner = 0, foe = 0, foe_partner = 0;
    battler_get_partner_and_foes(active_battler, &partner, &foe, &foe_partner);
    pokemon *party = battler_load_party_range(active_battler, &first, &last);
    u8 targets[2] = {foe, foe_partner};
    u8 wonderguard_present[2] = {4, 4};
    for (int j = 0; j < 2; j++) {
        u8 target = targets[j];
        if (battlers[target].ability == WUNDERWACHE) {
            wonderguard_present[j] = target;
            if (battler_ai_battler_can_hit_target(active_battler, target)) return 6;
        }
    }
    // If there's any wonderguard battler on the opposing side, active_battler can't hit it, check if a party member can
    for(int j = 0; j < 2; j++) { 
        if (wonderguard_present[j] != 4) {
            u8 target = wonderguard_present[j];
            for (u8 i = first; i < last; i++) {
                if (AI_CAN_SWITCH_INTO(i, party, active_battler, partner)) {
                    for (int l = 0; l < 4; l++) {
                        u16 attack = (u16) pokemon_get_attribute(party + i, (u8)(ATTRIBUTE_ATTACK1 + l), 0);
                        if (attack != 0 && pokemon_get_attribute(party + i, (u8)(ATTRIBUTE_PP1 + l), 0) > 0) {
                            u8 multiplier = 8;
                            battle_ai_attack_apply_effectiveness_multiplier_with_abilities(attacks[attack].type, battlers[target].ability,
                                battlers[target].type1, battlers[target].type2, &multiplier);
                            if (multiplier > 0) {
                                *score += 32; // Switch is urgent
                                AI_DEBUG_SWITCHING("Party member %d of battler %d can hit wonderguard foe %d with attack %d (%d)\n", i, active_battler, target, l, attack);
                                return i;
                            }
                        }
                    }
                }
            }
        }
    }
    AI_DEBUG_SWITCHING("No wonderguard foe present or unable to hit wonderguard foe with %d\n", active_battler);
    // Either no foe has wonderguard, or no party member can hit any of the wonderguard foes the active_battler can't hit
    return 6;
}

void battle_ai_should_switch_if_perish_song(int *score) {
    if (battler_statuses3[active_battler] & STATUS3_PERISH_SONG) { // Urgency to switch increases the less time a battler has
        *score += 8 - 2 * battler_disable[active_battler].perish_song_timer;
        AI_DEBUG_SWITCHING("Switching, affected by perish song, new score is %d\n", *score);
    }
}

void battle_ai_should_switch_if_natural_cure(int *score) {
    if (battlers[active_battler].ability == INNERE_KRAFT && battlers[active_battler].status1 & STATUS1_ANY) {
        if (battlers[active_battler].status1 & (STATUS1_SLEEPING | STATUS1_FROZEN))
            *score += 4;
        else if (battlers[active_battler].status1 & (STATUS1_BADLY_POISONED))
            *score += 3;
        else if (battlers[active_battler].status1 & (STATUS1_POISONED | STATUS1_PARALYZED | STATUS1_BURNED))
            *score += 2;
        else return;
        // If the battler likes to attack physically, burning is also a more severy condition
        if (battlers[active_battler].status1 & STATUS1_BURNED) {
            for (int i = 0; i < 4; i++) {
                if (battlers[active_battler].moves[i] != 0 && attacks[battlers[active_battler].moves[i]].category == CATEGORY_PHYSICAL) {
                    (*score)++;
                }
            };
        }
        // Check if we expect to be hit by a move that does not damage
        if (battler_last_landed_move[active_battler] == 0 || battler_last_landed_move[active_battler] == 0xFFFF) {
            *score += 1;
        } else if (attacks[battler_last_landed_move[active_battler]].base_power == 0) {
            *score += 1;
        }
        // Check if it is worth restoring the status of this pokemon
        if (battlers[active_battler].current_hp < battlers[active_battler].max_hp / 4) {
            *score -= 3;
        } else if (battlers[active_battler].current_hp < battlers[active_battler].max_hp / 2) {
            *score -= 1;
        }
        AI_DEBUG_SWITCHING("Switching: Considered natural cure and score is now %d\n", *score);
    }
}

u8 battle_ai_should_switch_into_pokemon_to_absorb_move(int *score) {
    u8 first = 0, last = 0, partner = 0, foe = 0, foe_partner = 0;
    battler_get_partner_and_foes(active_battler, &partner, &foe, &foe_partner);
    pokemon *party = battler_load_party_range(active_battler, &first, &last);
    if (battler_last_landed_move[active_battler] == 0 || battler_last_landed_move[active_battler] == 0xFFFF ||
        attacks[battler_last_landed_move[active_battler]].base_power == 0) return 6;
    u8 best_target = 6;
    int best_score = 0;
    for (u8 i = first; i < last; i++) {
        if (AI_CAN_SWITCH_INTO(i, party, active_battler, partner)) {
            // Check if the pokemon can absorb the move
            u8 multiplier = 4;
            u16 species = (u16) pokemon_get_attribute(party + i, ATTRIBUTE_SPECIES, 0);
            battle_ai_attack_apply_effectiveness_multiplier_with_abilities(attacks[battler_last_landed_move[active_battler]].type, 
                pokemon_get_ability(party + i), basestats[species].type1, basestats[species].type2, &multiplier);
            if (multiplier == 0) {
                if (best_score < 12) {
                    best_score = 12;
                    best_target = i;
                }
            } else if (multiplier == 1) {
                if (best_score < 10) {
                    best_score = 10;
                    best_target = i;
                }
            } else if (multiplier == 2) {
                if (best_score < 1) {
                    best_score = 1;
                    best_target = i;
                }
            }
        }
    }
    if (best_target != 6) {
        AI_DEBUG_SWITCHING("Party target %d absorbs last landed attack with a score of %d\n", best_target, best_score);
        *score = best_score;
    }
    return best_target;
}

void battle_ai_should_switch_stat_changes(int *score) {
    for (int i = 0; i < 8; i++) {
        score += battlers[active_battler].stat_changes[i] - 6;
    }
}

// How well does a mon resist the opponents battlers
int battle_ai_score_resists_foes(pokemon *p, u8 foe, u8 foe_partner) {
    if (POKEMON_IS_VIABLE(p)) {
        u8 multiplier;
        u16 species = (u16) pokemon_get_attribute(p, ATTRIBUTE_SPECIES, 0);
        u8 ability = pokemon_get_ability(p);
        u8 type1 = basestats[species].type1;
        u8 type2 = basestats[species].type2;
        int score = 0;
        if (!(battlers_absent & int_bitmasks[foe])) {
            multiplier = 4;
            battle_ai_attack_apply_effectiveness_multiplier_with_abilities(battlers[foe].type1, ability, type1, type2, &multiplier);
            score += 2 - msb_index(multiplier);
            multiplier = 4;
            battle_ai_attack_apply_effectiveness_multiplier_with_abilities(battlers[foe].type2, ability, type1, type2, &multiplier);
            score += 2 - msb_index(multiplier);
        }
        if (!(battlers_absent & int_bitmasks[foe_partner]) && foe_partner != foe) {
            multiplier = 4;
            battle_ai_attack_apply_effectiveness_multiplier_with_abilities(battlers[foe_partner].type1, ability, type1, type2, &multiplier);
            score += 2 - msb_index(multiplier);
            multiplier = 4;
            battle_ai_attack_apply_effectiveness_multiplier_with_abilities(battlers[foe_partner].type2, ability, type1, type2, &multiplier);
            score += 2 - msb_index(multiplier);
        }
        // AI_DEBUG_SWITCHING("Defensive Score for %x with foes %d, %d: %d\n", p, foe, foe_partner, score);
        return score; // [-16, 20] (20 is only reached when immune against all STABs of all foes...)
    }
    return 0;
}

// Checks how well a pokemon attacks opponent battlers. Considers only it's best move.
int battle_ai_score_attacks_foes(pokemon *p, u8 foe, u8 foe_partner) {
    if (POKEMON_IS_VIABLE(p)) {
        int best_score_foe = -3, best_score_foe_partner = -3;
        // Check all moves
        for (int i = 0; i < 4; i++) {
            u8 multiplier1 = 4, multiplier2 = 4;
            int attack = pokemon_get_attribute(p, (u8)(ATTRIBUTE_ATTACK1 + i), 0);
            if (attack != 0 && pokemon_get_attribute(p, (u8)(ATTRIBUTE_PP1 + i), 0) > 0 && attacks[attack].base_power) {
                if (!(battlers_absent & int_bitmasks[foe])) {
                    battle_ai_attack_apply_effectiveness_multiplier_with_abilities(attacks[attack].type, battlers[foe].type1, battlers[foe].type2, 
                        battlers[foe].ability, &multiplier1);
                }
                if (!(battlers_absent & int_bitmasks[foe_partner]) && foe_partner != foe) {
                    battle_ai_attack_apply_effectiveness_multiplier_with_abilities(attacks[attack].type, battlers[foe_partner].type1, 
                        battlers[foe_partner].type2, battlers[foe_partner].ability, &multiplier2);
                }
                int score_foe = msb_index(multiplier1) - 2; // Score in [-3, 2]
                int score_foe_partner = msb_index(multiplier2) - 2; // Score in [-3, 2]
                // AI_DEBUG_SWITCHING("Move %d has a score: %d on foe; %d on foe partner\n", i, score_foe, score_foe_partner);
                best_score_foe = MAX(best_score_foe, score_foe);
                best_score_foe_partner = MAX(best_score_foe_partner, score_foe_partner);
            }
        }
        // AI_DEBUG_SWITCHING("Offensive Score for %x with foes %d, %d: %d\n", p, foe, foe_partner, 4 * (best_score_foe + best_score_foe_partner));
        // AI_DEBUG_SWITCHING("Best Score on foe %d, Best Score on foe's partner %d, total %d\n", best_score_foe, best_score_foe_partner,4 * (best_score_foe + best_score_foe_partner));
        return 4 * (best_score_foe + best_score_foe_partner); // Score in range [-18, 16]
    }
    return 0;
}

int battle_ai_switch_weight_scores(pokemon *p, int offensive_score, int defensive_score) {
    // dprintf("Weighting scores off %d, def %d for %x\n", offensive_score, defensive_score, p);
    int attack = pokemon_get_attribute(p, ATTRIBUTE_ATK, 0);
    int special_attack = pokemon_get_attribute(p, ATTRIBUTE_SATK, 0);
    int defense = pokemon_get_attribute(p, ATTRIBUTE_DEF, 0);
    int special_defense = pokemon_get_attribute(p, ATTRIBUTE_SDEF, 0);
    int speed = pokemon_get_attribute(p, ATTRIBUTE_INIT, 0);
    int hp = pokemon_get_attribute(p, ATTRIBUTE_TOTAL_HP, 0);

    // Calculate the defensive weight using relative importance of HP to offensive stats
    int defensive_weight = (3 * ((hp - hp / 4) << 8) / (attack + special_attack + speed));
    // Calculate the offensive weight using the relative importance of speed to defensive stats
    int offensive_weight = (3 * (speed << 8) / (hp + defense + special_defense));
    // AI_DEBUG_SWITCHING("Weights: off %d, def %d\n", offensive_weight, defensive_weight);

    // The highest offensive / defensive stat also gives a weighting factor
    int highest_offensive_stat = MAX(attack, special_attack);
    int highest_defensive_stat = MAX(defense, special_defense);
    offensive_weight *= highest_offensive_stat;
    offensive_weight /= highest_offensive_stat + highest_defensive_stat;
    defensive_weight *= highest_defensive_stat;
    defensive_weight /= highest_offensive_stat + highest_defensive_stat;

    // Use quadratic weighting, this increases the discrepancy between two stats (watch out for overflows...)
    offensive_weight = MIN(offensive_weight * offensive_weight, 1 << 20);
    defensive_weight = MIN(defensive_weight * defensive_weight, 1 << 20);

    // Scale weights to sum up to 2 (i.e. 512)
    int normalization = (offensive_weight + defensive_weight) / 2;
    offensive_weight = offensive_weight * 256 / normalization;
    defensive_weight = defensive_weight * 256 / normalization;
    // AI_DEBUG_SWITCHING("Normalized stat-based weights: off %d, def %d, sum %d\n", offensive_weight, defensive_weight, offensive_weight + defensive_weight);
    // AI_DEBUG_SWITCHING("Unwighted scores: off %d, def %d\n", offensive_score, defensive_score);
    offensive_score *= offensive_weight;
    defensive_score *= defensive_weight;
    int score = offensive_score + defensive_score;
    // AI_DEBUG_SWITCHING("Weighted scores: off %d, def %d, sum %d\n", offensive_score, defensive_score, offensive_score + defensive_score);
    return score >> 8;
}

u8 battle_ai_get_pokemon_to_switch_into() {
    AI_DEBUG_SWITCHING("Find suitable switching target for %d\n", active_battler);
    if (battle_state->battler_to_switch_into[active_battler] != 6) {
        // A pokemon to switch into was already selected
        return battle_state->battler_to_switch_into[active_battler];
    }
    u8 first = 0, last = 0, partner = 0, foe = 0, foe_partner = 0;
    battler_get_partner_and_foes(active_battler, &partner, &foe, &foe_partner);
    pokemon *party = battler_load_party_range(active_battler, &first, &last);
    int scores[6] = {0};
    u8 targets[6] = {0};
    int num_viable_targets = 0;

    for (u8 i = first; i < last; i++) {
        if (AI_CAN_SWITCH_INTO(i, party, active_battler, partner)) {
            int offensive_score = battle_ai_score_attacks_foes(party + i, foe, foe_partner);
            int defensive_score = battle_ai_score_resists_foes(party + i, foe, foe_partner);
            scores[num_viable_targets] = MIN(48, MAX(-48, battle_ai_switch_weight_scores(party + i, offensive_score, defensive_score)));
            targets[num_viable_targets] = i;
            AI_DEBUG_SWITCHING("Party member %d (@0x%x) has an offensive score of %d, defensive score of %d, weighted %d\n", i, party + i, offensive_score, defensive_score, scores[num_viable_targets]);
            num_viable_targets++;
        }
    }
    if (num_viable_targets == 0) return 6;
    u8 target = targets[softmax_choice(scores, num_viable_targets, -48, 48, NULL)];
    AI_DEBUG_SWITCHING("Ai chose party idx %d from battler %d, partner %d as most suitable mon to switch into.\n", target, active_battler, partner);
    return target;
}


void battle_ai_should_switch_consider_battler_viablility(int *score, u8 target) {
    u8 first = 0, last = 0, partner = 0, foe = 0, foe_partner = 0;
    battler_get_partner_and_foes(active_battler, &partner, &foe, &foe_partner);
    pokemon *party = battler_load_party_range(active_battler, &first, &last);
    int defensive_score = battle_ai_score_resists_foes(party + battler_idx_to_party_idx(active_battler), foe, foe_partner);
    int offensive_score = battle_ai_score_attacks_foes(party + battler_idx_to_party_idx(active_battler), foe, foe_partner);
    int viablility = battle_ai_switch_weight_scores(party + battler_idx_to_party_idx(active_battler), offensive_score, defensive_score);
    AI_DEBUG_SWITCHING("Battler %d has a viability of %d against foes (off %d, def %d).\n", active_battler, viablility, offensive_score, defensive_score);

    // Check how viable the target is
    int defensive_score_target = battle_ai_score_resists_foes(party + target, foe, foe_partner);
    int offensive_score_target = battle_ai_score_attacks_foes(party + target, foe, foe_partner);
    int viablility_target = battle_ai_switch_weight_scores(party + target, offensive_score_target, defensive_score_target);
    AI_DEBUG_SWITCHING("Party target %d (@0x%x) has a viability of %d against foes (off %d, def %d).\n", target, party + target, viablility_target, offensive_score_target, defensive_score_target);


    // Compare the viablities of the current battler and the switching target
    // Switching in general is disfavored: Only if the target's viablity is at least 3 higher than the current mon's viablility
    // the swichting score will be >= 0. Also the target's viability needs to be positive (the current battler's viability is overestimated
    // by clamping with a zero value).
    *score += viablility_target - MAX(0, viablility) - 7;
}

u8 battle_ai_should_switch(int *score) {
    // Check if we need to switch into a pokemon that can deal with wonderguard
    if (!battle_ai_battler_can_switch_out(active_battler)) return 6;
    AI_DEBUG_SWITCHING("Battler %d eligible to switching\n", active_battler);
    *score = 0;
    u8 target = battle_ai_should_switch_if_wonderguard(score);
    if (target == 6) {
        *score = 0;
        target = battle_ai_should_switch_into_pokemon_to_absorb_move(score);
    }
    if (target == 6) { // There is no distinct target for either wonderguard or absorbing, choose the best suitable target
        *score = 0;
        target = battle_ai_get_pokemon_to_switch_into();
    }
    if (target == 6) {
        return target; // Shouldn't happen...
    }
    // Now either we have a target for wonderguard or to absorb a move, calculate the score of swichting considering contexts
    battle_ai_should_switch_if_natural_cure(score);
    battle_ai_should_switch_if_perish_song(score);
    battle_ai_should_switch_stat_changes(score);
    battle_ai_should_switch_consider_battler_viablility(score, target);
    // Does the trainer favor switching?
    *score += (int)((battle_ressources->ai->ai_flags >> 10) & 3);
    AI_DEBUG_SWITCHING("Switching bias is %d\n", (battle_ressources->ai->ai_flags >> 10) & 3);
    *score = MIN(16, MAX(-16, *score));
    AI_DEBUG_SWITCHING("Switching has a score of %d\n", *score);
    return target;
}