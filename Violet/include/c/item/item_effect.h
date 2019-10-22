#ifndef H_ITEM_EFFECT
#define H_ITEM_EFFECT

#include "types.h"
#include "constants/items.h"

#define NUMBER_ITEM_EFFECT_FUNCTIONS 9

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

#endif