#include "types.h"
#include "stdbool.h"
#include "romfuncs.h"
#include "pokepad.h"
#include "save.h"
#include "bg.h"
#include "utils.h"
#include "color.h"
#include "callbacks.h"
#include "transparency.h"
#include "gfx.h"
#include "oams.h"
#include "superstate.h"
#include "utils.h"
#include "text.h"

u8 pokepad_fontcolmap[] = {0,2,1,0};

tboxdata pokepad_tboxes [] = {
    { 0, 1, 16, 28, 4, 15, 161}, //description box
    { 0, 8, 4, 10, 2, 15, 1}, //item 0
    { 0, 20, 4, 10, 2, 15, 21}, //item 1
    { 0, 8, 7, 10, 2, 15, 41}, //item 2
    { 0, 20, 7, 10, 2, 15, 61}, //item 3
    { 0, 8, 10, 10, 2, 15, 81}, //item 4
    { 0, 20, 10, 10, 2, 15, 101}, //item 5
    { 0, 8, 13, 10, 2, 15, 121}, //item 6
    { 0, 20, 13, 10, 2, 15, 141}, //item 7
};


void leak_test(){
    pokepad_free_components();
    set_callback1(pokepad_callback_init);
}

bool startmenu_init_pokepad(){
    if(!is_fading()){
        
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
    pokepad_memory *mem = (pokepad_memory*)malloc(sizeof(pokepad_memory));
    mem->current_item = 0;//(u8)*vardecrypt(VAR_POKEPAD_LASTUSED);
    fmem->pad_mem = mem;
    //malloc_reset_default();
    pokepad_init_components();
    set_io(0x50, 0);
    set_io(0x52, 0);
    set_io(0x54, 0);
    bic_io(0, 0x6000);
}

bg_config pokepad_bg_cnfgs [] = {
    {0, 2, 31, 0, 0, 0},
    {1, 0, 29, 0, 0, 1}
};

void pokepad_locate_lr(){
    u8 *registered = (u8*)vardecrypt(VAR_POKEPAD_REGISTERED); //we interpret the var offset as 2 bytes
    oams[fmem->pad_mem->l_oam].x = (u16)-16; //move both offscreen
    oams[fmem->pad_mem->r_oam].x = (u16)-16;
    int i;
    for (i = 0; i < fmem->pad_mem->item_cnt; i++){
        if (fmem->pad_mem->items[i] == registered[0]){
            //left match, relocate left icon
            oams[fmem->pad_mem->l_oam].x = (u16)(72 + 96 * (i & 1));
            oams[fmem->pad_mem->l_oam].y = (u16)(31 + (i >> 1) * 24);
        }
        if(fmem->pad_mem->items[i] == registered[1]){
            //left match, relocate left icon
            oams[fmem->pad_mem->r_oam].x = (u16)(136 + 96 * (i & 1));
            oams[fmem->pad_mem->r_oam].y = (u16)(31 + (i >> 1) * 24);
        }
        
    }
}

void pokepad_init_components(){
    dma0_cb_reset();
    oam_reset();
    remove_all_big_callbacks();
    pal_fade_cntrl_reset();
    //dma0_cb_reset();
    set_callback3(NULL);
    bg_reset(1);
    bg_setup(0, pokepad_bg_cnfgs, 2);
    
    
    // load graphics
    void *bg1map = malloc_fill(0x800); 
    void *bg0map = malloc_fill(0x800);
    //fmem->pad_mem->bg0map = bg0map;
    //fmem->pad_mem->bg1map = bg1map;
    bg_set_tilemap(0, bg0map);
    bg_set_tilemap(1, bg1map);
    
    tbox_sync_with_virtual_bg_and_init_all(pokepad_tboxes);
    
    
    bg_sync_display_and_show(0);
    bg_sync_display_and_show(1);
    bg_display_sync();
    
    bg_virtual_map_displace(0, 0, 0);
    bg_virtual_set_displace(0, 0, 0);
    bg_virtual_map_displace(1, 0, 0);
    bg_virtual_set_displace(1, 0, 0);
    set_io(0x10, (u16)-6);
    
    
    lz77uncompwram(gfx_pokepad_backgroundMap, bg1map);
    lz77uncompvram(gfx_pokepad_backgroundTiles, (void*)0x06000000);
    
    //now we setup the description box
    tbox_flush(POKEPAD_DESCRIPTION_TBOX, 0);
    tbox_tilemap_draw(POKEPAD_DESCRIPTION_TBOX);
    
    pokepad_load_description();
    
    
    
    //Now we spawn arrow oam
    load_and_alloc_obj_vram_lz77(&graphic_pokepad_arrow);
    u8 arrow_pal = allocate_obj_pal(0xA001);
    load_comp_pal_into_RAM(gfx_pokepad_arrowPal, (u16)((arrow_pal+16)*16), 32);
    //Now we have to find x and y from the current position
    s16 x = (s16)(56 + 104 * (fmem->pad_mem->current_item & 1));
    s16 y = (s16)(40 + (fmem->pad_mem->current_item >> 1) * 24);
    fmem->pad_mem->arrow_oam = generate_oam_forward_search(&oam_template_pokepad_arrow, x, y, 0);
    oams[fmem->pad_mem->arrow_oam].private[0] = 0;
    oams[fmem->pad_mem->arrow_oam].private[1] = 0;
    
    
    //now we spawn the l&r button
    load_and_alloc_obj_vram_lz77(&graphic_pokepad_l);
    load_and_alloc_obj_vram_lz77(&graphic_pokepad_r);
    u8 lrpal = allocate_obj_pal(0xA002);
    load_comp_pal_into_RAM(gfx_pokepad_lPal, (u16)((lrpal+16)*16), 32);
    fmem->pad_mem->l_oam = generate_oam_forward_search(&oam_template_pokepad_l, -16, 0, 0);
    fmem->pad_mem->r_oam = generate_oam_forward_search(&oam_template_pokepad_r, -16, 0, 0);
    
    pokepad_locate_lr();
    
    
    pokepad_build_buttons(bg_get_tilemap(1));
    
    
    bg_virtual_sync(0);
    bg_virtual_sync(1);
    
    //pal
    load_comp_pal_into_RAM(gfx_pokepad_backgroundPal, 0, 32);
    load_uncomp_pal_into_RAM(transparency_black_box_pals, 15*16, 32);
    
    fmem->pad_mem->color_cb = spawn_big_callback(pokepad_callback_background_anim, 0);
    set_callback1(pokepad_show_components);
}

void pokepad_load_description(){
    tbox_flush(POKEPAD_DESCRIPTION_TBOX, 0);
    //now we need to get the description
    //test(pokepad_items[fmem->pad_mem->items[fmem->pad_mem->current_item]].description);
     tbox_print_string(POKEPAD_DESCRIPTION_TBOX, 2, 0, 0, 0, 0, pokepad_fontcolmap, 0x0,
             pokepad_items[fmem->pad_mem->items[fmem->pad_mem->current_item]].description);
}


void pokepad_callback_background_anim(u8 self){
    if (!is_fading()){
        //do the counting process
        if(big_callbacks[self].params[0]){
            //count down
            big_callbacks[self].params[1]--;
            if (!big_callbacks[self].params[1])
                big_callbacks[self].params[0] = 0;
        }else{
            //count up
            big_callbacks[self].params[1]++;
            if (big_callbacks[self].params[1] == 31)
                big_callbacks[self].params[0] = 1;
        }
        
        int i;
        for (i = 14; i < 16; i++){
            color over = {0x1F};
            pals[i] = alpha_blend(pal_restore[i], over, (u8)(big_callbacks[self].params[1]>>2));
        }
    }
}    
    
void pokepad_build_buttons(void *tilemap){
    pokepad_memory *mem = fmem->pad_mem;
    lz77uncompvram(gfx_pokepad_buttonTiles, (void*)0x06001000);
    
    int last_used = (int)(*vardecrypt(VAR_POKEPAD_LASTUSED));
    
    //Now we build the item list
        int i;
        mem->item_cnt = 0;
        for(i = 0; pokepad_items[i].flag != 0xFFFF; i++){
            if (!pokepad_items[i].flag || checkflag(pokepad_items[i].flag)){
                if (last_used == i){
                    mem->current_item = mem->item_cnt;
                }
                u8 y = (u8)( 4 + (mem->item_cnt >> 1) * 3 );
                u8 x = (u8)( 8 + (mem->item_cnt & 1) * 12 );
                pokepad_draw_button(tilemap, x, y, pokepad_items[i].string);
                mem->items[mem->item_cnt++] = (u8)i;
            }
        }
    
}

void pokepad_draw_button(void *tilemap, u8 x, u8 y, u8*string){
    u16 *map = (u16*)tilemap;
    int i, j;
    for (i = 0; i < 2; i++){
        for (j = 0; j < 10; j++){
            u16 tile = (u16)(128 + i*10 + j);
            map[32*(y+i)+j+x] = tile;
        }
    }
    u8 current = (u8)(fmem->pad_mem->item_cnt + POKEPAD_BUTTON_TBOX_BASE);
    tbox_flush(current, 0);
    tbox_tilemap_draw(current);
    tbox_print_string(current, 2, 0, 0, 0, 0, pokepad_fontcolmap, 0x0, string);
}

void pokepad_free_components(){
    //free(fmem->pad_mem->bg0map);
    //free(fmem->pad_mem->bg1map);
    free(bg_get_tilemap(0));
    free(bg_get_tilemap(1));
    oam_despawn(&oams[fmem->pad_mem->arrow_oam]);
    oam_despawn(&oams[fmem->pad_mem->l_oam]);
    oam_despawn(&oams[fmem->pad_mem->r_oam]);
    free_all_tboxes();
    free(fmem->pad_mem);
}


void pokepad_free_and_return(){
    cb1handling();
    if (!is_fading()){
        pokepad_free_components();
        map_reload();
    }
}


void pokepad_idle(){
    cb1handling();
    if (!is_fading()){  
        bool item_changed = false;
        int lr_relocate = 0;
        u8 *registered = (u8*)vardecrypt(VAR_POKEPAD_REGISTERED);
        if (super->keys_new.keys.right && !(fmem->pad_mem->current_item & 1) 
                && fmem->pad_mem->current_item+1 < fmem->pad_mem->item_cnt){
            //Right press
            item_changed = true;
            fmem->pad_mem->current_item++;
            oams[fmem->pad_mem->arrow_oam].x = (u16)(oams[fmem->pad_mem->arrow_oam].x + 12 * 8);
        }else if (super->keys_new.keys.left && (fmem->pad_mem->current_item & 1)){
            //Left press
            item_changed = true;
            fmem->pad_mem->current_item--;
            oams[fmem->pad_mem->arrow_oam].x = (u16)(oams[fmem->pad_mem->arrow_oam].x - 12 * 8);
        }else if (super->keys_new.keys.up && fmem->pad_mem->current_item > 1){
            //Up press
            item_changed = true;
            fmem->pad_mem->current_item = (u8)(fmem->pad_mem->current_item-2);
            oams[fmem->pad_mem->arrow_oam].y = (u16)(oams[fmem->pad_mem->arrow_oam].y - 3 * 8);
        }else if (super->keys_new.keys.down && fmem->pad_mem->current_item+2 < fmem->pad_mem->item_cnt){
            //Down press
            item_changed = true;
            fmem->pad_mem->current_item = (u8)(fmem->pad_mem->current_item+2);
            oams[fmem->pad_mem->arrow_oam].y = (u16)(oams[fmem->pad_mem->arrow_oam].y + 3 * 8);
        }else if (super->keys_new.keys.l){
            if (registered[0] == fmem->pad_mem->items[fmem->pad_mem->current_item]){
                registered[0] = 0xFF;
                lr_relocate = 3;
            }else{
                registered[0] = fmem->pad_mem->items[fmem->pad_mem->current_item];
                lr_relocate = 1;
            }
        }else if (super->keys_new.keys.r){
            if ( registered[1] == fmem->pad_mem->items[fmem->pad_mem->current_item]){
                registered[1] = 0xFF;
                lr_relocate = 4;
            }else{
                registered[1] = fmem->pad_mem->items[fmem->pad_mem->current_item];
                lr_relocate = 2;
            }
        }else if(super->keys_new.keys.B){
            sound(5);
            set_callback1(pokepad_free_and_return);
            init_fadescreen(1,0);
        }else if(super->keys_new.keys.A){
            sound(5);
            if (pokepad_items[fmem->pad_mem->items[fmem->pad_mem->current_item]].func){
                pokepad_items[fmem->pad_mem->items[fmem->pad_mem->current_item]].func(false);
            }
        }
        if(item_changed){
            sound(5);
            pokepad_load_description();
        }else if(lr_relocate){
            //Print that we relocated the key
            u8 *buffer1 = (u8*)0x02021CF0;
            if(lr_relocate & 1){ //1 or 3
                strcpy(buffer1, str_pokepad_l_ref);
            }else{ //2 or 4
                strcpy(buffer1, str_pokepad_r_ref); 
            }
            u8 *buffer0 = (u8*)0x02021CD0;
            strcpy(buffer0, pokepad_items[fmem->pad_mem->items[fmem->pad_mem->current_item]].string);
            u8 *strbuf = (u8*)0x02021D18;
            if (lr_relocate > 2){
                string_decrypt(strbuf, str_pokepad_deregistered_ref);
            }else{
                string_decrypt(strbuf, str_pokepad_registered_ref);
            }
            
            tbox_flush(POKEPAD_DESCRIPTION_TBOX, 0);
            tbox_print_string(POKEPAD_DESCRIPTION_TBOX, 2, 0, 0, 0, 0, pokepad_fontcolmap, 0x0, strbuf);
            pokepad_locate_lr();
            sound(lr_relocate > 2 ? 3 : 2);
            fmem->pad_mem->lr_countdown = 28;
            set_callback1(pokepad_callback_registered_string);
        }
        
    }
}


void pokepad_callback_registered_string(){
    cb1handling();
    if (fmem->pad_mem->lr_countdown){
        fmem->pad_mem->lr_countdown--;
        return;
    }
    if(super->keys_new.keys.A){
        pokepad_load_description();
        sound(5);
        set_callback1(pokepad_idle);
    }
}

void pokepad_show_components(){
    init_fadescreen(0, 0);
    set_callback1(pokepad_idle);
}

bool pokepad_init_function_outdoor(){
    u8 *registered = (u8*)vardecrypt(VAR_POKEPAD_REGISTERED); //we interpret the var offset as 2 bytes
    if(super->keys_new.keys.l && registered[0] != 0xFF){
        if (pokepad_items[registered[0]].func){
            pokepad_items[registered[0]].func(true);
            return true;
        }
    }else if(super->keys_new.keys.r && registered[1] != 0xFF){
        if (pokepad_items[registered[1]].func){
            pokepad_items[registered[1]].func(true);
            return true;
        }
    }
    return false;
}
