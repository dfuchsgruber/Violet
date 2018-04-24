#include "types.h"
#include "stdbool.h"
#include "romfuncs.h"
#include "pokemon/virtual.h"
#include "tile/block.h"
#include "save.h"
#include "debug.h"
#include "constants/abilities.h"
#include "constants/vars.h"
#include "constants/pokemon_attributes.h"

void egg_warm_update(){
    s16 pos[2];
    get_current_tile_position(&pos[0], &pos[1]);
    u8 behavior = (u8)get_block_info_behaviour(pos[0], pos[1]);
    
    u16 *v_hatching_fastened_left = vardecrypt(HATCHING_BOOST_STEPS);
    
    if ((*save1)->bank == 3 && (*save1)->map == 6 && behavior == 0x28){
        //restore 1000 to the var
        *v_hatching_fastened_left = 1000;
    }else{

        if(*v_hatching_fastened_left)
            (*v_hatching_fastened_left)--;
    }
}

bool pokemon_party_has_flamebody(){
    u8 pokemon_cnt = countpokemon();
    while(--pokemon_cnt){
        if(get_pokemons_ability(&player_pokemon[pokemon_cnt]) == FLAMMKOERPER)
            return true;
    }
    return false;
}

void pokemon_hatch_decrement(pokemon *p){
    int cycles = (int)get_pokemons_attribute(p, ATTRIBUTE_HAPPINESS, NULL);
    //get hatch decremnt by different values
    int base = 16;
    int eggs_hatched = save_get_key(0xD); //Eggs hatched
    if (eggs_hatched > 1000){
        base = 48;
    }else if(eggs_hatched > 500){
        base = 40;
    }else if(eggs_hatched > 250){
        base = 32;
    }else if(eggs_hatched > 75){
        base = 24;
    }else if(eggs_hatched > 10){
        base = 20;
    }
    
     base += 49 * (*vardecrypt(HATCHING_BOOST_STEPS)) / 1000;

    
    int cdif = base / 16;
    int cycles_new;
    if (cycles < cdif){
        cycles_new = 0;
    }else{
        cycles_new = cycles - cdif;
    }
    
    set_pokemons_attribute(p, ATTRIBUTE_HAPPINESS, &cycles_new);
}
