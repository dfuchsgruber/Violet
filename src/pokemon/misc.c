#include "types.h"
#include "romfuncs.h"
#include "pokemon/virtual.h"
#include "constants/pokemon_attributes.h"


void pokemon_team_remove(){
    int index = *vardecrypt(0x8004);
    int n = 0;
    cpuset(&n, &player_pokemon[index], 25 | CPUSET_FILL | CPUSET_WORD);
    int i;
    for(i = index; i < 5; i++){
        cpuset(&player_pokemon[i+1], &player_pokemon[i], 25 | CPUSET_COPY | CPUSET_WORD);
    }
}

void pokemon_team_knows_hm(){
    int index = *vardecrypt(0x8004);
    *vardecrypt(0x800D) = pokemon_knows_hm(&player_pokemon[index]);
    
}

bool pokemon_knows_hm(pokemon *p){
    int i;
    for(i = 0; i < 4; i++){
        if(move_is_hm((u16)get_pokemons_attribute(p, (u8)(ATTRIBUTE_ATTACK1+i), NULL)))
            return true;
    }
    return false;
}
