#include "types.h"
#include "map/wild_pokemon.h"
#include "save.h"


u16 map_wild_pokemon_get_current_table_id(){
    u16 i = 0;
    while(wild_pokemon[i].bank != 0xFF){
        if(wild_pokemon[i].bank == (*save1)->bank &&
                wild_pokemon[i].map == (*save1)->map)
            return i;
        i++;
    }
    return 0xFFFF;
}
