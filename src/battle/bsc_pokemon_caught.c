#include "types.h"
#include "battle/battlescript.h"
#include "pokemon/virtual.h"
#include "pokepad/pokedex/operator.h"
#include "constants/pokemon_attributes.h"
#include "constants/flags.h"
#include "flags.h"
#include "debug.h"

void bsc_pokemon_caught(){
    //dprintf("Bsc before caught %x\n", bsc_offset);
    u16 species = (u16)pokemon_get_attribute(&opponent_pokemon[0], ATTRIBUTE_SPECIES, 0);
    u16 dex_id = pokedex_get_id(species);
    pid_t pid = {.value = (u32)pokemon_get_attribute(&opponent_pokemon[0], ATTRIBUTE_PID, 0)};
    bool caught = pokedex_operator(species,POKEDEX_GET | POKEDEX_CAUGHT, true);
    if(caught){
      u8 *bsc_off_loc = &((bsc_offset)[1]);
      int target = GET_MISALIGNED_32(bsc_off_loc);
      bsc_offset = (u8*)target;
    }else{
        //catch pokemon
        pokedex_set_caught_and_load_pid(dex_id, 0b11, pid);
        if(checkflag(CAUGHT_POKEDEX_DISABLE)){
            u8 *bsc_off_loc = &((bsc_offset)[1]);
            int target = GET_MISALIGNED_32(bsc_off_loc);
            bsc_offset = (u8*)target;
        }else{
            bsc_offset = (u8*)((int)(bsc_offset) + 5);   
        }
    }
    //dprintf("Bsc after caught %x\n", bsc_offset);
}
