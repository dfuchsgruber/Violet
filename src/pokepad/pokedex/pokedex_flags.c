#include "types.h"
#include "save.h"
#include "pokedex.h"

bool pokedex_operator(u16 val, u8 op, bool is_species_id){

    if(is_species_id)
        val = pokedex_get_id(val);
    if(!val)
        return false;
    val--;
    u8 mask = (u8)(1 << (val & 7));
    u16 index = val / 8;
    saveblock2 *s2 = *save2;
    switch(op){
        case 0:{
            //is seen
            if(s2->pokedex_seen_flags[index] & mask)
                return true;
            break;
        }
        case 1:{
            //is caught
            if(s2->pokedex_caught_flags[index] & mask)
                return true;
            break;
        }
        case 2:{
            //set seen
            s2->pokedex_seen_flags[index] |= mask;
            break;
        }
        case 3:{
            //set caught
            s2->pokedex_caught_flags[index] |= mask;
            break;
        }
    }
    return false;
    
}

u16 pokedex_get_number_seen_or_caught(bool caught){
   
    u16 cnt = 0;
    u16 i;
    for(i = 1; i <= POKEDEX_CNT; i++){
        if(pokedex_operator_by_dex_id(i, caught ? 1 : 0))
            cnt++;
            
    }
    return cnt;
}

