#include "types.h"
#include "basestats.h"
#include "pokemon.h"
#include "battle.h"
#include "romfuncs.h"
#include "pokedex.h"


void bsc_pokemon_caught(){
    //dprintf("Bsc before caught %x\n", *bsc_offset);
    u16 species = (u16)get_pokemons_attribute(&opponent_pokemon[0], ATTRIBUTE_SPECIES, 0);
    u16 dex_id = pokedex_get_id(species);
    u32 pid = get_pokemons_attribute(&opponent_pokemon[0], ATTRIBUTE_PID, 0);
    bool caught = pokedex_operator(species, 1, true);
    if(caught){
        *bsc_offset = (u8*)GET_MISALIGNED_32(++(*bsc_offset));
    }else{
        //catch pokemon
        pokedex_set_caught_and_load_pid(dex_id, 0b11, pid);
        if(checkflag(CAUGHT_POKEDEX_DISABLE)){
            u8 *bsc_off_loc = &((*bsc_offset)[1]);
            int param = GET_MISALIGNED_32(bsc_off_loc);
            *bsc_offset = (u8*)param;         
        }else{
            *bsc_offset = (u8*)((int)(*bsc_offset) + 5);   
        }
    }
    //dprintf("Bsc after caught %x\n", *bsc_offset);
    
}