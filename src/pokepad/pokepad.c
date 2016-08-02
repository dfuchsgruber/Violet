#include "types.h"
#include "stdbool.h"
#include "romfuncs.h"
#include "pokepad.h"
#include "save.h"
#include "bg.h"
#include "utils.h"
#include "gfx.h"

extern pokepad_item *pokepad_items;

bool startmenu_init_pokepad(){
    if(!is_fading()){
        pokepad_memory *mem = (pokepad_memory*)malloc(sizeof(pokepad_memory));
        mem->current_item = (u8)*vardecrypt(VAR_POKEPAD_LASTUSED);
        cmem->pad_mem = mem;
        
        
        save_increment_key(0x29);
        startmenu_close();
        rain_sound_fadeout();
        overworld_free();
        set_callback1(pokepad_callback_init);
        return true;
    }
    return false;
}

void pokepad_callback_init(){
    pokepad_init_components();
    set_io(0x50, 0);
    set_io(0x52, 0);
    set_io(0x54, 0);
    bic_io(0, 0x6000);
}

static bg_config pokepad_bg_cnfgs [] = {
    {0, 2, 31, 0, 0, 0},
    {1, 0, 29, 0, 0, 1}
};

void pokepad_init_components(){
    oam_reset();
    remove_all_big_callbacks();
    pal_fade_cntrl_reset();
    //dma0_cb_reset();
    set_callback3(NULL);
    bg_reset(0);
    bg_setup(0, pokepad_bg_cnfgs, 2);
    
    // load graphics
    void *bg1map = malloc(0x800); 
    cmem->pad_mem->bg1set = malloc_fill(0x1000);
    
    bg_set_tilemap(0, malloc_fill(0x800));
    bg_set_tilemap(1, bg1map);
    
    lz77uncompwram(gfx_pokepad_backgroundMap, bg1map);
    lz77uncompwram(gfx_pokepad_backgroundTiles, cmem->pad_mem->bg1set);
    
    pokepad_build_buttons(bg_get_tilemap(1));
    
    bg_virtual_sync(0);
    bg_virtual_sync(1);
    bg_sync_display_and_show(0);
    bg_sync_display_and_show(1);
    bg_display_sync();
    
    
    bg_copy_vram(1, cmem->pad_mem->bg1set, 0x1000, 0, 1);
    
    //scroll
    bghscrollset(0, 0, 0);
    bgvscrollset(0, 0, 0);
    bghscrollset(1, 0, 0);
    bgvscrollset(1, 0, 0);
    set_io(0x10, (u16)-6);
    
    //pal
    load_comp_pal_into_RAM(gfx_pokepad_backgroundPal, 0, 32);
    
    set_callback1(pokepad_show_components);
}

    u8 teststr[4] = {0xB3, 0xC4, 0xAD, 0xFF};
    
    
void pokepad_build_buttons(void *tilemap){
    pokepad_memory *mem = cmem->pad_mem;
    void *buttonset = malloc(0x800);
    mem->buttonset = buttonset;
    lz77uncompwram(gfx_pokepad_buttonTiles, buttonset);
    bg_copy_vram(1, buttonset, 0x1000, 0x1000, 1);
    
    //Now we build the item list
        int i;
        mem->item_cnt = 0;
        for(i = 0; pokepad_items[i].flag != 0xFFFF; i++){
            if (!pokepad_items[i].flag || checkflag(pokepad_items[i].flag)){
                u8 x = (u8)( 8 + (mem->item_cnt >> 1) * 2 );
                u8 y = (u8)( 5 + (mem->item_cnt & 1) * 12 );
                u16 start_tile = (u16)(1 + mem->item_cnt * 20);
                pokepad_draw_button(tilemap, x, y, pokepad_items[i].string, start_tile);
                mem->items[mem->item_cnt++] = (u8)i;
            }
        }
    
}

u8 pokepad_fontcolmap[] = {0,2,1,0};


void pokepad_draw_button(void *tilemap, u8 x, u8 y, u8*string, u16 start_tile){
    u16 *map = (u16*)tilemap;
    int i, j;
    for (i = 0; i < 2; i++){
        for (j = 0; j < 10; j++){
            u16 tile = (u16)(128 + i*10 + j);
            map[32*(y+i)+j+x] = tile;
        }
    }
    pokepad_memory *mem = cmem->pad_mem;
    u8 boxdata[8];
    translate_text_data_into_box(boxdata, 0, x, y, 10, 2, 15, start_tile);
    u8 boxid = spawn_tbox(boxdata);
    fill_box_bg(boxid, 0);
    prepeare_bg_for_tbox(boxid);
    display_tbox_transbg(boxid, 2, 0, 0, 0, 0, pokepad_fontcolmap, 0x0, string);
    mem->tboxes[mem->item_cnt] = boxid;
}

void pokepad_idle(){
    cb1handling();
}

void pokepad_show_components(){
    free(cmem->pad_mem->bg1set);
    free(cmem->pad_mem->buttonset);
    init_fadescreen(0, 0);
    set_callback1(pokepad_idle);
}
