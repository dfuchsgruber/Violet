#include "types.h"
#include "pokemon/virtual.h"
#include "constants/pokemon_attributes.h"
#include "bios.h"
#include "vars.h"
#include "attack.h"
#include "pokemon/basestat.h"
#include "debug.h"

void pokemon_team_remove(){
    int index = *var_access(0x8004);
    int n = 0;
    cpuset(&n, &player_pokemon[index], 25 | CPUSET_FILL | CPUSET_WORD);
    int i;
    for(i = index; i < 5; i++){
        cpuset(&player_pokemon[i+1], &player_pokemon[i], 25 | CPUSET_COPY | CPUSET_WORD);
    }
}

void pokemon_team_knows_hm(){
    int index = *var_access(0x8004);
    *var_access(0x800D) = pokemon_knows_hm(&player_pokemon[index]);
    
}

bool pokemon_knows_hm(pokemon *p){
    int i;
    for(i = 0; i < 4; i++){
        if(attack_is_hidden_machine((u16)pokemon_get_attribute(p, (u8)(ATTRIBUTE_ATTACK1+i), NULL)))
            return true;
    }
    return false;
}

u16 player_party_contains_species() {
  u16 species = *var_access(0x8004);
  for (u16 i = 0; i < player_pokemon_cnt; i++) {
    if (pokemon_get_attribute(&player_pokemon[i], ATTRIBUTE_SPECIES, 0) == species)
      return i;
  }
  return 6;
}

bool pokemon_has_type() {
    int index = *var_access(0x8004);
    int type = *var_access(0x8005);
    if (pokemon_get_attribute(player_pokemon + index, ATTRIBUTE_IS_EGG, 0)) return false;
    int species = pokemon_get_attribute(player_pokemon + index, ATTRIBUTE_SPECIES, 0);
    dprintf("Species %d, type %d\n");
    return basestats[species].type1 == type || basestats[species].type2 == type;
}