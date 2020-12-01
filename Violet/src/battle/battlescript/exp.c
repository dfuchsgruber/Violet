#include "types.h"
#include "vars.h"
#include "constants/difficulties.h"
#include "battle/attack.h"
#include "battle/battler.h"
#include "battle/controller.h"
#include "battle/battle_string.h"
#include "pokemon/virtual.h"
#include "battle/state.h"
#include "math.h"
#include "debug.h"

void bsc_cmd_x23_adjust_exp_and_print_string(u16 boosted_string_idx) {
    u8 opponent_level = battlers[fainted_battler].level;
    u8 player_level = (u8)pokemon_get_attribute(player_pokemon + battle_state->exp_getter_idx, ATTRIBUTE_LEVEL, 0);
    dprintf("Exp adjusment: Fainted level %d, player_level %d\n", opponent_level, player_level);
    // damage_to_apply is used as exp for some reason...
    // Difficulty related adjustments
    switch (*var_access(DIFFICULTY)) {
        case DIFFICULTY_EASY:
            damage_to_apply += damage_to_apply / 2;
            break;
        case DIFFICULTY_HARD:
            damage_to_apply = MAX(1, damage_to_apply - damage_to_apply / 2);
            break;
    }
    damage_to_apply = MAX(1, damage_to_apply);
    dprintf("Exp to give party idx %d before level adjustment %d\n", battle_state->exp_getter_idx, damage_to_apply);
    // Calculate ( (2L + 10) / (L + Lp + 10) )^2.5
    FIXED factor = INT_TO_FIXED(2 * opponent_level + 10);
    factor = FIXED_DIV(factor, INT_TO_FIXED(opponent_level + player_level + 10));
    dprintf("Adjustment factor w/o exponentiation is (<<16) 0x%x\n", factor);
    // factor^2.5 = factor^2 * sqrt(factor)
    FIXED sqrt_factor = FIXED_SQRT(factor);
    factor = FIXED_MUL(factor, FIXED_MUL(factor, sqrt_factor));
    dprintf("Adjustment factor with exponentiation is (<<16) 0x%x\n", factor);
    FIXED exp_fixed = INT_TO_FIXED(MIN(10000, damage_to_apply)); // avoid overflow
    damage_to_apply = MAX(1, MIN(0xFFFF, FIXED_TO_INT(FIXED_MUL(factor, exp_fixed))));
    dprintf("Exp to give party idx %d after level adjustment %d\n", battle_state->exp_getter_idx, damage_to_apply);
    BSC_BUFFER_BATTLER_NICKNAME_WITH_PREFIX(bsc_string_buffer0, battle_state->experience_getter_battler_idx, battle_state->exp_getter_idx);
    BSC_BUFFER_STRING(bsc_string_buffer1, boosted_string_idx);
    BSC_BUFFER_NUMBER(bsc_string_buffer2, 5, damage_to_apply);
    battle_print_string_idx(13, battle_state->experience_getter_battler_idx);
}
