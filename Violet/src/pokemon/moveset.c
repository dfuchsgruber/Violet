#include "types.h"
#include "pokemon/virtual.h"
#include "attack.h"
#include "pokemon/basestat.h"
#include "pokemon/moves.h"
#include "debug.h"
#include "save.h"

static u16 pokemon_attempt_learning_move_by_evolution(pokemon_move *moveset) {
    u8 skip = fmem.pokemon_move_learning_evolution_move_idx;
    for (u16 i = 0; moveset[i].level <= 100; i++) {
        if (moveset[i].level == POKEMON_MOVE_BY_EVOLUTION) {
            if (skip > 0) {
                skip--;
            } else {
                // Learn this new move
                dprintf("Pokemon learns evolution move at index %d\n", fmem.pokemon_move_learning_evolution_move_idx);
                return moveset[i].move_id;
            }
        }
    }
    return 0;
}

u16 pokemon_attempt_learning_move_consider_evolution_moves(pokemon *p, u8 is_first_move) {
    u16 species = (u16)pokemon_get_attribute(p, ATTRIBUTE_SPECIES, 0);
    u8 level = (u8)pokemon_get_attribute(p, ATTRIBUTE_LEVEL, 0);
    pokemon_move *moveset = pokemon_moves[species];
    if (!moveset)
        return 0;

    if (is_first_move) {
        dprintf("Pokemon tries to learn its first move after evolution.\n");
        // First scroll through the moves to find the right idx
        pokemon_move_learning_current_move_idx = 0;
        fmem.pokemon_move_learning_evolution_move_idx = 0;
        while (moveset[pokemon_move_learning_current_move_idx].level != level) {
            if (moveset[pokemon_move_learning_current_move_idx].level > 100) {
                break;
            }
            pokemon_move_learning_current_move_idx++;
        }
        dprintf("First move is at idx %d: 0x%x\n", pokemon_move_learning_current_move_idx, moveset[pokemon_move_learning_current_move_idx].move_id);
    }
    // Check if we have any more evolution moves to learn
    u16 evolution_move = pokemon_attempt_learning_move_by_evolution(moveset);
    if (evolution_move) {
        pokemon_move_learning_learned_move = evolution_move;
        fmem.pokemon_move_learning_evolution_move_idx++;
        return pokemon_append_attack(p, evolution_move);
    }
    // Check if we can learn the current move by level-up
    if (moveset[pokemon_move_learning_current_move_idx].level == level) {
            pokemon_move_learning_learned_move = moveset[pokemon_move_learning_current_move_idx++].move_id;
            return pokemon_append_attack(p, pokemon_move_learning_learned_move);
    }
    return 0; // Pokemon can learn no more moves
}