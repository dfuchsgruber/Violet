#include "types.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "battle/ai.h"
#include "battle/attack.h"
#include "item/item_effect.h"
#include "item/item.h"
#include "constants/item_effect_types.h"
#include "constants/items.h"
#include "constants/item_effects.h"
#include "constants/battle/battle_ai_item_types.h"
#include "debug.h"
#include "constants/abilities.h"
#include "constants/attacks.h"
#include "battle/ressources.h"

#define AI_DEBUG_ITEMS_ON true
#define AI_DEBUG_ITEMS(str, ...) ({if (AI_DEBUG_ITEMS_ON) dprintf(str, __VA_ARGS__);})

u8 battle_ai_should_use_item(int *score) {
    u8 first = 0, last = 0, partner = 0, foe = 0, foe_partner = 0;
    battler_get_partner_and_foes(active_battler, &partner, &foe, &foe_partner);
    pokemon *party = battler_load_party_range(active_battler, &first, &last);


    // Check how many items the AI has still left in relation to the number of battlers
    u8 owner = battler_get_owner(active_battler);
    int num_items = 0, num_viable_pokemon = 0, party_size = 0;
    for (u8 i = 0; i < BATTLE_STATE2->num_items[owner]; i++) {
        if (BATTLE_STATE2->items[owner][i]) num_items++; 
    }
    AI_DEBUG_ITEMS("Battle ai for battler %d has %d items.\n", active_battler, num_items);
    if (num_items == 0)
        return 4;
    for (u8 i = first; i < last; i++) {
        if (POKEMON_IS_VIABLE(party + i)) num_viable_pokemon++;
        if (pokemon_get_attribute(party + i, ATTRIBUTE_SPECIES2, 0) != 0 && pokemon_get_attribute(party + i, ATTRIBUTE_SPECIES2, 0) != POKEMON_EGG &&
            !pokemon_get_attribute(party + i, ATTRIBUTE_IS_EGG, 0)) party_size++;
    }
    // Compare the ratios of pokemon in the party that are viable to items left
    // Negative bias towards item use, if the ratio of mons in the team exceeds the ratio of items
    *score = -(num_viable_pokemon * BATTLE_STATE2->num_items[owner] / num_items / party_size);
    AI_DEBUG_ITEMS("Viable Mons %d, Party Size %d, Num Items %d, Total Items %d\n", num_viable_pokemon, party_size, num_items, BATTLE_STATE2->num_items[owner]);
    AI_DEBUG_ITEMS("Bias towards items %d for owner %d\n", *score, owner);


    // Check if the item is eligible anyways
    u8 item_idx_to_choose = 4;
    int best_item_score = INT_MIN;;
    for (u8 i = 0; i < BATTLE_STATE2->num_items[owner]; i++) {
        AI_DEBUG_ITEMS("Checking if item %d is applicable...\n", i);
        u16 item = BATTLE_STATE2->items[owner][i];
        if (item == 0 || item < ITEM_TRANK) continue;
        item_effect_t *effect = item_effects[item - ITEM_TRANK];
        int item_score = 0;
        if (item == ITEM_TOP_GENESUNG) goto check_heal_hp;
        switch (item_get_effect_type(item)) {
            case ITEM_EFFECT_X_ITEM: {
                int stat_change_current = 6;
                int increase = 0;
                if (effect->x_attack) {
                    stat_change_current = battlers[active_battler].stat_changes[STAT_ATTACK];
                    increase = effect->x_attack;
                } else if (effect->x_defense) {
                    stat_change_current = battlers[active_battler].stat_changes[STAT_DEFENSE];
                    increase = effect->x_defense;
                } else if (effect->x_speed) {
                    stat_change_current = battlers[active_battler].stat_changes[STAT_SPEED];
                    increase = effect->x_speed;
                } else if (effect->x_special_attack) {
                    stat_change_current = battlers[active_battler].stat_changes[STAT_SPECIAL_ATTACK];
                    increase = effect->x_special_attack;
                } else if (effect->x_accuracy) {
                    stat_change_current = battlers[active_battler].stat_changes[STAT_ACCURACY];
                    increase = effect->x_accuracy;
                } else if (effect->creates_mist && battle_side_timers[battler_is_opponent(active_battler)].mist_turns == 0) {
                    item_score = battle_ai_switch_weight_scores(party + battler_idx_to_party_idx(active_battler), 0, 5);
                    break;
                } else if (effect->increase_critical_ratio && !(battlers[active_battler].status2 & STATUS2_FOCUS_ENERGY)) {
                    item_score = battle_ai_switch_weight_scores(party + battler_idx_to_party_idx(active_battler), 5, 0);
                    break;
                }
                if (stat_change_current + increase >= 12) 
                    increase = 12 - stat_change_current;
                if (increase <= 0) 
                    continue;
                int stat_change_score = increase * (12 - stat_change_current) / 2;
                AI_DEBUG_ITEMS("Stat change score for item %d is %d\n", i, stat_change_score);
                if (effect->x_defense) { // Weighted defensively
                    item_score = battle_ai_switch_weight_scores(party + battler_idx_to_party_idx(active_battler), 0, stat_change_score);
                } else { // Weighted offensively
                    item_score = battle_ai_switch_weight_scores(party + battler_idx_to_party_idx(active_battler), stat_change_score, 0);
                }
                break;
            }
            case ITEM_EFFECT_HEAL_POISON: {
            check_poison:
                if (battlers[active_battler].status1 & STATUS1_POISONED) {
                    item_score = 4;
                } else if (battlers[active_battler].status1 & STATUS1_BADLY_POISONED) {
                    item_score = 6;
                } else {
                    continue;
                }
                if (battlers[active_battler].ability == GIFTWAHN) continue;
                if (battlers[active_battler].ability == NOTSCHUTZ || battlers[attacking_battler].ability == EXPIDERMIS)
                    item_score /= 2;
                break;
            }
            case ITEM_EFFECT_HEAL_SLEEP: {
            check_sleep:
                if (battlers[active_battler].status1 & STATUS1_SLEEPING) {
                    item_score = 4;
                } else continue;
                // Check if the battler can use sleep talk
                u8 move_limitations = battler_check_move_limitations(active_battler, 0, MOVE_LIMITATION_ALL);
                bool can_sleep_talk = false;
                for (int j = 0; j < 4; j++) {
                    if (!(move_limitations & int_bitmasks[j]) && battlers[active_battler].moves[j] == ATTACK_SCHLAFREDE) can_sleep_talk = true; 
                }
                if (can_sleep_talk) continue;
                if (battlers[active_battler].ability == NOTSCHUTZ || battlers[attacking_battler].ability == EXPIDERMIS || battlers[attacking_battler].ability == FRUEHWECKER)
                    item_score /= 2;
                break;
            }
            case ITEM_EFFECT_HEAL_BURN: {
            check_burn:
                if (battlers[active_battler].status1 & STATUS1_BURNED) {
                    item_score = 4;
                } else continue;
                if (battlers[active_battler].ability == HITZEWAHN) continue;
                if (battlers[active_battler].ability == NOTSCHUTZ || battlers[attacking_battler].ability == EXPIDERMIS)
                    item_score /= 2;
                break;
            }
            case ITEM_EFFECT_HEAL_FREEZE: {
            check_freeze:
                if (battlers[active_battler].status1 & STATUS1_FROZEN) {
                    item_score = 6;
                } else continue;
                if (battlers[active_battler].ability == NOTSCHUTZ || battlers[attacking_battler].ability == EXPIDERMIS)
                    item_score /= 2;
                break;
            } case ITEM_EFFECT_HEAL_PARALYSIS: {
            check_paralysis:
                if (battlers[active_battler].status1 & STATUS1_PARALYZED) {
                    item_score = 4;
                } else continue;
                if (battlers[active_battler].ability == NOTSCHUTZ || battlers[attacking_battler].ability == EXPIDERMIS)
                    item_score /= 2;
                break;
            } case ITEM_EFFECT_HEAL_CONFUSION: {
            check_confusion:
                if (battlers[active_battler].status2 & STATUS2_CONFUSED) {
                    item_score = 4;
                } else continue;
                break;
            } case ITEM_EFFECT_HEAL_INFATUATION: {
            check_infatuation:
                if (battlers[active_battler].status2 & STATUS2_INFATUATION) {
                    item_score = 4;
                } else continue;
                break;
            } case ITEM_EFFECT_HEAL_ALL_STATUS: {
                if (battlers[active_battler].status1 & STATUS1_POISONED_ANY) goto check_poison;
                if (battlers[active_battler].status1 & STATUS1_SLEEPING) goto check_sleep;
                if (battlers[active_battler].status1 & STATUS1_BURNED) goto check_burn;
                if (battlers[active_battler].status1 & STATUS1_FROZEN) goto check_freeze;
                if (battlers[active_battler].status1 & STATUS1_PARALYZED) goto check_paralysis;
                if (battlers[active_battler].status2 & STATUS2_CONFUSED) goto check_confusion;
                if (battlers[active_battler].status2 & STATUS2_INFATUATION) goto check_infatuation;
                continue;
            } case ITEM_EFFECT_HEAL_HP:
            check_heal_hp: {
                int amount = battlers[active_battler].max_hp - battlers[active_battler].current_hp;
                if (amount <= 0) continue;
                if (battlers[active_battler].current_hp < battlers[active_battler].max_hp / 4) {
                    item_score = 2 - (battlers[active_battler].current_hp * 4 / battlers[active_battler].max_hp);
                    AI_DEBUG_ITEMS("Healing hp item score %d\n", item_score);
                } else {
                    item_score = -16; // Do not waste healing items...
                }
                break;
            }
            default: continue; // AI can't use item of this type...
        }
        if (item_score > best_item_score) {
            item_idx_to_choose = i;
            best_item_score = item_score;
        }
    }
    if (item_idx_to_choose < 4) {
        AI_DEBUG_ITEMS("Chose item idx %d (is %d) with an item score of %d\n", item_idx_to_choose, BATTLE_STATE2->items[owner][item_idx_to_choose], best_item_score);
        *score += best_item_score;
        *score += (int)((battle_ressources->ai->ai_flags >> 12) & 3);
        AI_DEBUG_ITEMS("Item bias is %d\n", (battle_ressources->ai->ai_flags >> 12) & 3);
    }
    *score = MIN(16, MAX(-16, *score));
    AI_DEBUG_ITEMS("Chosen item idx %d with a score of %d\n", item_idx_to_choose, *score);
    return item_idx_to_choose;
}