#include "types.h"
#include "pokemon.h"
#include "romfuncs.h"
#include "debug.h"

pid pid_shinyness_apply(pid p){
    if(random_change_seed() & 1){
        if((random_change_seed() < (save_get_key(0x1A) & 0xFFF))){
            //Chances for this to happen are SPLASH_CNT & 0xFFF / 65.535 * 2
            p.fields.shinyness = 0;
        }
        p.fields.shinyness = 0x300;
        
    }
    dprintf("Next shinies %d\n", *vardecrypt(NEXT_POKEMON_SHINY));
    if((*vardecrypt(NEXT_POKEMON_SHINY))){
        p.fields.shinyness &= 0x1FF;
        (*vardecrypt(NEXT_POKEMON_SHINY))--;
    }
    return p;
}
