#include "types.h"
#include "pokemon/egg_moves.h"
#include "attack.h"
#include "debug.h"


void _pokemon_get_egg_moves_stub(){
    derrf("Rom called old invalid stub for pokemon_get_egg_moves!\n");
}

u16 *pokemon_get_egg_moves(u16 species, int *size){
    *size = 0;
    u16 *egg_moves = pokemon_egg_moves[species];
    if (egg_moves) {
		while(egg_moves[*size] != 0xFFFF) {
			(*size)++;
		}
    }
    return egg_moves;
}
