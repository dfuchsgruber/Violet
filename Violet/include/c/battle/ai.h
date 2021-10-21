#ifndef H_BATTLE_AI
#define H_BATTLE_AI

#include "battle/battler.h"
#include "battle/state.h"
#include "pokemon/virtual.h"
#include "save.h"
#include "types.h"

/**
 * Sets the trainer ai up.
 */
void ai_setup(u16 trainer_idx);

typedef struct {
    u16 moves[4];
    u8 current_pp[4];
    u8 max_pp[4];
    u16 species;
    u8 type1;
    u8 type2;
} trainer_ai_choosing_state_t;

typedef struct {
    u8 state;
    u8 move_idx;
    u16 move_considered;
    s8 scores[4];
    u32 result;
    u32 ai_flags;
    u8 action;
    u8 logic_idx;
    u8 unused[6];
    u8 simulated_rng[4];
    u8 field_1B;
} ai_thinking_state_t;

typedef struct {
    u16 known_moves[4][4]; // For predictions
    u32 ai_flags[4];       // Potentiall increase possible AI scripts to 32
    u8 chosen_item_idxs[4];
} trainer_ai_state2_t;

extern u8 *battle_ai_script;

#define TRAINER_AI_STATE2 ((trainer_ai_state2_t *)fmem.trainer_ai_state2)

#define AI_CHOICE_FLEE 4
#define AI_CHOICE_WATCH 5

/**
 * AI chooses an action (move, flee, ...)
 * @return the move_idx or action the ai took
 */
u8 trainer_ai_choose_move_or_action();

#define AI_CAN_SWITCH_INTO(idx, party, self, partner) ( \
    POKEMON_IS_VIABLE(party + idx) && battler_idx_to_party_idx(self) != idx && battler_idx_to_party_idx(partner) != idx && battle_state->battler_to_switch_into[partner] != idx)

#define TRAINER_AI_SWITCHING_BIAS(x) ((x & 3) << 10)
#define TRAINER_AI_ITEM_BIAS(x) ((x & 3) << 12)

/**
 * AI uses a scoring system to choose a suitable target for switching.
 * @return the idx of the pokemon to switch into.
 */
u8 battle_ai_get_pokemon_to_switch_into();

/**
 * Checks if a battler is able to switch out.
 * @param idx the battler to check
 * @return if the battler can switch out
 */
bool battle_ai_battler_can_switch_out(u8 idx);

/**
 * AI classification of an item.
 * @param item the item to classify
 * @return the item type according to the AI
 */
u16 battle_ai_get_item_type(u16 item);

/**
 * Weights an offensive score and a defensive score value for a pokemon based on its capabilites.
 * @param p the pokemon in question
 * @param offensive_score the offensive score value
 * @param defensive score the defensive score value
 * @return weighted a weighted score value
 */
int battle_ai_switch_weight_scores(pokemon *p, int offensive_score, int defensive_score);

/**
 * Checks if the ai should use an item.
 * @param score the score for choosing an item
 * @return the item idx within the owners items to use
 */
u8 battle_ai_should_use_item(int *score);

/**
 * Checks if the ai should switch.
 * @param score the score for switching.
 * @return the party idx to switch into.
 */
u8 battle_ai_should_switch(int *score);

/**
 * Chooses an action (move, swichting, items) and emits the corresponding return value.
 */
void battle_ai_choose_action();

/**
 * Applies type effectiveness multipliers to some value.
 * @param attack_type attacking type
 * @param defending_ability defender ability
 * @param defender_type1 first defender type
 * @param defender_type2 second defender type
 * @param multiplier the value to multiplier
 */
void battle_ai_attack_apply_effectiveness_multiplier_with_abilities(u8 attack_type, u8 defender_ability, u8 defender_type1, u8 defender_type2,
                                                                    u8 *multiplier);

#endif
