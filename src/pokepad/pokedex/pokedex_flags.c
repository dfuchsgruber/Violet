#include "types.h"
#include "save.h"
#include "pokedex.h"

u8* pokedex_flag_access (u16 flag, bool seen){
    if (flag < 416){
        saveblock2 *s2 = *save2;
        //std access
        int index = flag / 8;
        return seen ?  &(s2->pokedex_seen_flags[index]) :  &(s2->pokedex_caught_flags[index]);
    }else{
        int index = (416-flag) / 8;
        return seen ? &(cmem->pokedex_seen_extension[index]) : &(cmem->pokedex_caught_extension[index]);
    }
}

bool pokedex_operator(u16 val, u8 op, bool is_species_id){

    if(is_species_id)
        val = pokedex_get_id(val);
    if(!val)
        return false;
    val--;
    u8 mask = (u8)(1 << (val & 7));
    bool seen = !(op & 1);
    bool apply = op & 2;
    u8 *field = pokedex_flag_access(val, seen);
    if(apply){
        *field |= mask;
    }else{
        if (*field & mask)
            return true;
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

