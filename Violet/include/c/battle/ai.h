#ifndef H_BATTLE_AI
#define H_BATTLE_AI

#include "types.h"


/**
 * Sets the trainer ai up.
 */
void trainer_load_ai();

typedef struct {
    u16 moves[4];
    u8 current_pp[4];
    u8 max_pp[4];
    u16 species;
    u8 type1;
    u8 type2;
} trainer_ai_choosing_state_t;


#define AI_CHOICE_FLEE 4
#define AI_CHOICE_WATCH 5

/**
 * AI chooses an action (move, flee, ...)
 * @return the move_idx or action the ai took
 **/
u8 trainer_ai_choose_move_or_action();

/**
 * AI chooses an action (switching, item, move...)
**/
void trainer_ai_try_switch_or_choose_item();

/**
 * AI uses a scoring system to choose a suitable target for switching.
 * @return the idx of the pokemon to switch into.
 **/
u8 battle_ai_get_pokemon_to_switch_into();

#endif