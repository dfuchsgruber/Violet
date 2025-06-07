/*
 * moves.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEMON_MOVES_H_
#define INCLUDE_C_POKEMON_MOVES_H_
#include "types.h"
#include "pokemon/count.h"
#include "constants/move_tutors.h"
#include "pokemon/virtual.h"

typedef struct {
    u16 move_id : 9;
    u16 level : 7;
} pokemon_move;

#define POKEMON_MOVE_BY_EVOLUTION 0

extern const pokemon_move *const pokemon_moves[POKEMON_CNT];
extern const u8 pokemon_tm_compatibility [POKEMON_CNT][16];
extern const u32 pokemon_move_tutor_compatibility[POKEMON_CNT];
extern const u16 *const pokemon_accessible_moves[POKEMON_CNT];

// Which move idx currently being learned in the moveset
extern u8 pokemon_move_learning_current_move_idx;
// The move that is currently learned
extern u16 pokemon_move_learning_learned_move;

/**
 * Gets the attack associated with a move tutor
 * @param move_tutor the move tutor index
 */
u16 move_tutor_get_attack(u8 move_tutor_idx);

/**
 * Checks if a pokemon can learn a certain tm or hm
    * @param p the pokemon to check
    * @param tm_hm_id the tm or hm id to check
    * @return true if the pokemon can learn the tm/hm, false otherwise
 */
extern bool pokemon_can_learn_tm_hm(pokemon *p, u16 tm_hm_id);

/**
 * Checks if a pokemon can learn a certain move tutor
 * @param p the pokemon to check
 * @param move_tutor_idx the move tutor index to check
 * @return true if the pokemon can learn the move tutor, false otherwise
 */
extern bool move_tutor_is_compatible(u16 species, u8 move_tutor);


/**
 * Checks if a pokemon can learn a certain move tutor
 * @param p the pokemon to check
 * @param move_tutor_idx the move tutor index to check
 * @return true if the pokemon can learn the move tutor, false otherwise
 */
extern bool pokemon_knows_move(pokemon *p, u16 move);

#endif /* INCLUDE_C_POKEMON_MOVES_H_ */
