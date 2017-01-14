#include "types.h"
#include "basestats.h"
#include "romfuncs.h"
#include "item.h"
#include "mega.h"

mega_table_entry megas[MEGA_CNT] = {
    {POKEMON_BISAFLOR, ITEM_BISAFLORNIT, POKEMON_BISAFLORM, 0},
    {POKEMON_GLURAK, ITEM_GLURAKNIT, POKEMON_GLURAKM, 0},
    {POKEMON_GROUDON, ITEM_MAGMAHERZ, POKEMON_GROUDON_REGENT, 1},
    {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF}
};

void mega_reset_do(){
    clearflag( FLAG_MEGA_USED);
    int pkmn_cnt = countpokemon();
    int i, j;
    for(i = 0; i < pkmn_cnt; i++){
        u16 species = (u16)get_pokemons_attribute(&player_pokemon[i], ATTRIBUTE_SPECIES, 0);
        for(j = 0; megas[j].species != 0xFFFF; j++){
            if(species == megas[j].target){
                set_pokemons_attribute(&player_pokemon[i], ATTRIBUTE_SPECIES, &(megas[j].species));
                recalculate_stats(&player_pokemon[i]);
                break;
            }else if(species == POKEMON_DURENGARDA){
                u16 species_new = POKEMON_DURENGARD;
                set_pokemons_attribute(&player_pokemon[i], ATTRIBUTE_SPECIES, &species_new);
                recalculate_stats(&player_pokemon[i]);
                break;
            }
        }
    }
}