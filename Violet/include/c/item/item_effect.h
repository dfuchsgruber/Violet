#ifndef H_ITEM_EFFECT
#define H_ITEM_EFFECT

#include "types.h"
#include "constants/items.h"
#include "pokemon/virtual.h"

#define NUMBER_ITEM_EFFECT_FUNCTIONS 9
#define EFFECT_RESET_EVS 127

typedef struct {
    // 0x0
    u8 x_attack : 4;
    u8 increase_critical_ratio : 2;
    u8 sacred_ash : 1;
    u8 heal_infatuation : 1;
    // 0x1
    u8 x_speed : 4;
    u8 x_defense : 4;
    // 0x2
    u8 x_special_attack : 4;
    u8 x_accuracy : 4;
    // 0x3
    u8 heal_confusion : 1;
    u8 heal_paralysis : 1;
    u8 heal_freeze : 1;
    u8 heal_burn : 1;
    u8 heal_poison : 1;
    u8 heal_sleep : 1;
    u8 increase_level : 1;
    u8 creates_mist : 1;
    // 0x4
    u8 increase_ev_hp : 1;
    u8 increase_ev_attack : 1;
    u8 heal_hp : 1;
    u8 heal_pp : 1;
    u8 heal_pp_one_move : 1;
    u8 pp_up : 1;
    u8 revives : 1;
    u8 trigger_evolution : 1;
    // 0x5
    u8 increase_ev_defense : 1;
    u8 increase_ev_speed : 1;
    u8 increase_ev_special_defense : 1;
    u8 increase_ev_special_attack : 1;
    u8 pp_max : 1;
    u8 increase_friendship_low : 1;
    u8 increase_friendship_mid : 1;
    u8 increase_friendship_high : 1;
    // 0x6 - Arguments
    u8 level;
    s8 evs[6];
    u8 hp;
    u8 pp;
    s8 friendship_low;
    s8 friendship_mid;
    s8 friendship_high;

} item_effect_t;

#define ITEM_EFFECT_HEAL_HP_ALL 255
#define ITEM_EFFECT_HEAL_HP_HALF 254
#define ITEM_EFFECT_HEAL_HP_DYANMIC 253
#define ITEM_EFFECT_HEAL_HP_QUARTER 252
#define ITEM_EFFECT_HEAL_HP_EIGHTH 251
#define ITEM_EFFECT_PP_ALL 127

item_effect_t *item_effects[ITEM_ENIGMABEERE - ITEM_TRANK];

/**
 * Gets the effect type of an item.
 * @param item the item to get the effect type of
 * @return the effect type of the item
 **/
u8 item_get_effect_type(u16 item);

/**
 * Executes status1 heals and applies them to the battler and party pokemon.
 * @param p the party pokemon to apply the status heal to
 * @param item the item used
 * @param battler_idx the battler idx (if present, otherwise pass 4)
 * @param move_idx which move to target (unused)
 * @param party_idx (unused)
 * @param hold_effect (unused)
 * @param effect the item efect
 * @param calcualte_heal_only unused
 * @param if the change is not actually applied, but only checked if it is applicable
 * @return if the item effect was applicable
 **/
bool item_effect_execute_status_heals(pokemon *p, u16 item, u8 battler_idx, u8 move_idx, u8 party_idx, u8 hold_effect, 
    item_effect_t *effect, bool calculate_heal_only, bool check_only);

/**
 * Executes in-battle effects (including status2 heals) and applies them to the battler.
 * @param p the party pokemon to apply the status heal to
 * @param item the item used
 * @param battler_idx the battler idx (if present, otherwise pass 4)
 * @param move_idx which move to target (unused)
 * @param party_idx (unused)
 * @param hold_effect (unused)
 * @param effect the item efect
 * @param calcualte_heal_only unused
 * @param if the change is not actually applied, but only checked if it is applicable
 * @return if the item effect was applicable
 **/
bool item_effect_execute_battle_effects(pokemon *p, u16 item, u8 battler_idx, u8 move_idx, u8 party_idx, u8 hold_effect, 
    item_effect_t *effect, bool calculate_heal_only, bool check_only);

/**
 * Executes healing effects (potion, max restore, ...) and applies them to the battler and party.
 * @param p the party pokemon to apply the status heal to
 * @param item the item used
 * @param battler_idx the battler idx (if present, otherwise pass 4)
 * @param move_idx which move to target (unused)
 * @param party_idx the party idx of the mon
 * @param hold_effect (unused)
 * @param effect the item efect
 * @param calcualte_heal_only if the healing amount is only to be set, but not applied
 * @param if the change is not actually applied, but only checked if it is applicable
 * @return if the item effect was applicable
 **/
bool item_effect_execute_hp_heal(pokemon *p, u16 item, u8 battler_idx, u8 move_idx, u8 party_idx, u8 hold_effect, 
    item_effect_t *effect, bool calculate_heal_only, bool check_only);

/**
 * Executes all item effects (in-battle and non in-battle)
 * @param p the pokemon to apply the item to
 * @param item the item to use
 * @param party_idx the party index?
 * @param move_idx the move to target
 * @param calcualte_heal_only if the amount of hp to heal is only calcualted, but not applied
 * @param check_only if true, no changes are applied whatsoever, only checks if the item is applicable
 * @return if the item is applicable
 **/
bool item_effect(pokemon *p, u16 item, u8 party_idx, u8 move_idx, bool calculate_heal_only, bool check_only);

#endif