#include "types.h"
#include "basestats.h"
#include "attack.h"
#include "debug.h"


void _pokemon_get_egg_moves_stub(){
    derrf("Rom called old invalid stub for pokemon_get_egg_moves!\n");
}

u16 *pokemon_get_egg_moves(u16 species, int *size){
    // First find the proper table entry
    *size = 0;
    int i = 0;
    while(egg_moves[i] != 0xFFFF){
        if(egg_moves[i] >= 20000 && egg_moves[i] - 20000 == species)
            break;
        i++;
    }
    // If no match simply return null
    if(egg_moves[i] == 0xFFFF) return NULL;
    while(egg_moves[i + 1 + *size] < 20000)
        (*size)++;
    return &egg_moves[i + 1];
}
