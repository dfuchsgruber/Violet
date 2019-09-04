#include "types.h"
#include "constants/item_effects.h"

u8 item_effect_evolution_stone[7] = {
    [4] = ITEM_EFFECT_FIELD_4_EVOLUTION_STONE
};

u8 item_effect_rare_candy[11] = {
    [3] = ITEM_EFFECT_FIELD_3_LEVEL_UP,
    [4] = ITEM_EFFECT_FIELD_4_REVIVE | ITEM_EFFECT_FIELD_4_HEAL_HP,
    [5] = ITEM_EFFECT_FIELD_5_FRIENDSHIP_LOW | ITEM_EFFECT_FIELD_5_FRIENDSHIP_MID | ITEM_EFFECT_FIELD_5_FRIENDSHIP_HIGH,
    [6] = 0xFD,
    [7] = 5,
    [8] = 3,
    [9] = 2,
    [10] = 1 // The amount of levels to be added
};

u8 item_effect_gold_candy[11] = {
    [3] = ITEM_EFFECT_FIELD_3_LEVEL_UP,
    [4] = ITEM_EFFECT_FIELD_4_REVIVE | ITEM_EFFECT_FIELD_4_HEAL_HP,
    [5] = ITEM_EFFECT_FIELD_5_FRIENDSHIP_LOW | ITEM_EFFECT_FIELD_5_FRIENDSHIP_MID | ITEM_EFFECT_FIELD_5_FRIENDSHIP_HIGH,
    [6] = 0xFD,
    [7] = 5,
    [8] = 3,
    [9] = 2,
    [10] = 3 // The amount of levels to be added
};