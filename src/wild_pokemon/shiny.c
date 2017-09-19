#include "types.h"
#include "pokemon.h"
#include "romfuncs.h"

pid pid_shinyness_apply(pid p){
    if(random_change_seed() & 1){
        if((random_change_seed() < (save_get_key(0x1A) & 0xFFF)) ||
                (*vardecrypt(NEXT_POKEMON_SHINY))--){
            //Chances for this to happen are SPLASH_CNT & 0xFFF / 65.535 * 2
            p.fields.shinyness = 0;
        }
        p.fields.shinyness = 0x300;
        
    }
    return p;
}
