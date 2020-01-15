#include "types.h"
#include "mega.h"
#include "pokemon/virtual.h"
#include "constants/species.h"
#include "constants/items.h"
#include "constants/pokemon_attributes.h"
#include "constants/flags.h"
#include "flags.h"

mega_table_entry megas[MEGA_CNT] = {
    {POKEMON_BISAFLOR, ITEM_BISAFLORNIT, POKEMON_BISAFLORM, 0},
    {POKEMON_GLURAK, ITEM_GLURAKNIT, POKEMON_GLURAKM, 0},
    {POKEMON_GROUDON, ITEM_MAGMAHERZ, POKEMON_GROUDON_REGENT, 1},
    {POKEMON_GEOWAZ, ITEM_GEOWAZNIT, POKEMON_MEGA_GEOWAZ, 0},
    {POKEMON_TROPIUS, ITEM_TROPIUSNIT, POKEMON_MEGA_TROPIUS, 0},
    {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF}
};

void mega_reset_do(){
    clearflag(MEGA_EVOLUTION_PERFORMED);
    int pkmn_cnt = pokemon_get_number_in_party();
    int i, j;
    for(i = 0; i < pkmn_cnt; i++){
        u16 species = (u16)pokemon_get_attribute(&player_pokemon[i], ATTRIBUTE_SPECIES, 0);
        for(j = 0; megas[j].species != 0xFFFF; j++){
            if(species == megas[j].target){
                pokemon_set_attribute(&player_pokemon[i], ATTRIBUTE_SPECIES, &(megas[j].species));
                pokemon_calculate_stats(&player_pokemon[i]);
                break;
            }else if(species == POKEMON_DURENGARDA){
                u16 species_new = POKEMON_DURENGARD;
                pokemon_set_attribute(&player_pokemon[i], ATTRIBUTE_SPECIES, &species_new);
                pokemon_calculate_stats(&player_pokemon[i]);
                break;
            }
        }
    }
}

