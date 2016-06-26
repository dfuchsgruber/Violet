#include "types.h"
#include "stdbool.h"
#include "romfuncs.h"
#include "pokepad.h"
#include "save.h"
#include "utils.h"


pokepad_item pokepad_items[] = {{0xFFFF, NULL, NULL, NULL}};

void startmenu_init_pokepad(){
    if(!is_fading()){
     
        pokepad_memory *mem = (pokepad_memory*)malloc(sizeof(pokepad_memory));
        mem->current_item = (u8)*vardecrypt(VAR_POKEPAD_LASTUSED);
        mem->status = 0;
        cmem->pad_mem = mem;
        
        //Now we build the item list
        int i;
        int item_cnt = 0;
        for(i = 0; pokepad_items[i].flag != 0xFFFF; i++){
            if (!pokepad_items[i].flag || checkflag(pokepad_items[i].flag)){
                mem->items[item_cnt++] = (u8)i;
            }
        }
        save_increment_key(0x29);
        startmenu_close();
        rain_sound_fadeout();
        set_callback1(pokepad_callback);
    }
}

void pokepad_callback(){
    if(!is_fading()){
        switch(cmem->pad_mem->status){
            case 0:
                break;
        }
    }
}

void pokepad_init_components(){
    oam_reset();
    remove_all_big_callbacks();
    bg_reset(0);
}
