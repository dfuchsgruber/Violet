#ifndef H_BATTLE_ANIMATION
#define H_BATTLE_ANIMATION

#include "types.h"
#include "battle/battler.h"

enum {
    BATTLE_ANIMATION_USER = 0,
    BATTLE_ANIMATION_TARGET,
    BATTLE_ANIMATION_USER_PARTNER,
    BATTLE_ANIMATION_TARGET_PARTNER,
};

/**
 * Gets the oam of a battler if it is visible
 * @param which for which battler to get the oam
 * @return the oam_idx or 0xFF if the battler oam is not visible
 **/
u8 battle_animation_battler_get_oam_idx(u8 which);

#endif