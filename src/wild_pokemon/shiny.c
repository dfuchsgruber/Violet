#include "types.h"
#include "stdbool.h"
#include "pokemon/virtual.h"
#include "constants/vars.h"
#include "debug.h"
#include "vars.h"
#include "prng.h"
#include "save.h"

pid_t pid_shinyness_apply(pid_t p){
    if(rnd16() & 1){
        if((rnd16() < (save_get_key(0x1A) & 0xFFF))){
            //Chances for this to happen are SPLASH_CNT & 0xFFF / 65.535 * 2
            p.fields.shinyness = 0;
        }
        p.fields.shinyness = 0x300;
        
    }
    dprintf("Next shinies %d\n", *var_access(NEXT_POKEMON_SHINY));
    if((*var_access(NEXT_POKEMON_SHINY))){
        p.fields.shinyness &= 0x1FF;
        (*var_access(NEXT_POKEMON_SHINY))--;
    }
    return p;
}
