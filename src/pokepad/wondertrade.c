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
/**
 * Sample of how to do the selection process for wondertrade to return
void wondertrade_callback_init(){
    cb1handling();
    if(!is_fading()){
        set_callback1(cb1handling);
        u8 *flag = (u8*)0x02037AC0;
        *flag |= 0x80;
        void **launch_func = (void **)0x03004F74;
        *launch_func = 0x08128435;
        pokemenu_init(3, 0, 0xB, 0, 0, 0x0811FB5D, pokepad_callback_init); // <---------- This init function is the resume callback from selection
    }
}

void wondertrade_init(){
    init_fadescreen(1, 0);
    //set_callback1(cb1handling);
    //big_callbacks[spawn_big_callback(0x080BFB4D, 10)].params[0] = 3;
    set_callback1(wondertrade_callback_init);
}

void test(){while(true){}}


void ingame_trade_init_test(){
    cb1handling();
    if(!is_fading()){
        void **resume_func = (void**)0x3004F70;
        *resume_func = map_reload;
        set_callback1(0x80505ED);
    }
}

void wondertrade_init(){
    init_fadescreen(1, 0);
    //set_callback1(cb1handling);
    //spawn_big_callback(0x8054491, 10);
    //big_callbacks[].params[0] = 3;
    set_callback1(ingame_trade_init_test);
}

**/
u8 wondertrade_fontcolmap[] = {0,2,1,0};

tboxdata wondertrade_tboxes[] = {
    {0, 10, 1, 10, 2, 15, 1}, //Wondertrade Title
    {0, 1, 4, 5, 2, 15, 21}, //Wondertrade Level Title
    {0, 2, 6, 5, 2, 15, 31}, //Wondertrade Level Text
    {0, 11, 4, 5, 2, 15, 41}, //Wondertrade Cnt Title
    {0, 12, 6, 5, 2, 15, 51}, //Wondertrade Cnt Text
    {0, 19, 4, 7, 2, 15, 61}, //Wondertrade Next Title
    {0, 21, 6, 4, 2, 15, 75}, //Wondertrade Next Text
    {0, 1, 16, 30, 5, 13, 95} //Wondertrade print text for renderer
};

u8 wondertrade_get_level(){
    u16 cnt = *vardecrypt(VAR_POKEPAD_WONDERTRADE_CNT);
    if(cnt < 10){
        return 0;
    }else if(cnt < 50){
        return 1;
    }else if(cnt < 150){
        return 2;
    }else{
        return 3;
    }
}

void wondertrade_bg_scroll_callback(u8 self){
    u16 scroll = big_callbacks[self].params[0]--;
    set_io(0x18, scroll);
}


void wondertrade_callback_idle(){
    cb1handling();
    if(!is_fading()){
        if (fmem->wtrade_mem->usable){
            
        }else{
            if (super->keys_new.keys.A){
                //return to pokepad
                sound(5);
                set_callback1(wondertrade_callback_free_components_and_return);
                init_fadescreen(1, 0);
            }
        }
    }
}

void wondertrade_show_components(){
    bg_sync_display_and_show(0);
    bg_sync_display_and_show(1);
    bg_sync_display_and_show(2);
    bg_display_sync();
    if (fmem->wtrade_mem->usable)
        fmem->wtrade_mem->scroll_cb = spawn_big_callback(wondertrade_bg_scroll_callback, 10);
    init_fadescreen(0, 0);
    set_callback1(wondertrade_callback_idle);
}

bg_config wondertrade_bg_cnfgs [] = {
    {0, 2, 31, 0, 0, 0},
    {1, 0, 29, 0, 0, 1},
    {2, 1, 27, 0, 0, 2}
};

void wondertrade_callback_free_components_and_return(){
    cb1handling();
    if(!is_fading()){
        if(!fmem->wtrade_mem->from_outdoor){
            set_callback1(pokepad_callback_init);
        }else{
            set_callback1(map_reload);
        }
        free(bg_get_tilemap(0));
        free(bg_get_tilemap(1));
        free(bg_get_tilemap(2));
        oam_despawn(&oams[fmem->wtrade_mem->oam_badge]);
        free_all_tboxes();
        free(fmem->wtrade_mem);
        
    }
}

bool wondertrade_failure_texthandler(u8 in){
    if(in == 0xFF){
        if(super->keys_new.keys.A){
            sound(5);
            init_fadescreen(1, 0);
            set_callback1(wondertrade_callback_free_components_and_return);
            return true;
        }
        return false;
    }
    return true;
}

void wondertrade_init_components(){
    oam_reset();
    remove_all_big_callbacks();
    pal_fade_cntrl_reset();
    //dma0_cb_reset();
    set_callback3(NULL);
    bg_reset(0);
    bg_setup(0, wondertrade_bg_cnfgs, 3);
    
    //now we init the tilesets
    void *bg1map = (void*)malloc(0x800);
    void *bg2map = (void*)malloc(0x800);
    void *bg0map = (void*)malloc_fill(0x800);
    bg_set_tilemap(0, bg0map);
    bg_set_tilemap(1, bg1map);
    bg_set_tilemap(2, bg2map);
    
    tbox_sync_with_virtual_bg_and_init_all(wondertrade_tboxes);
    
    lz77uncompvram(gfx_wondertrade_bg_upperTiles, (void*)0x06000000);
    lz77uncompwram(gfx_wondertrade_bg_upperMap, bg1map);
    lz77uncompvram(gfx_wondertrade_bg_lowerTiles, (void*)0x06004000);
    lz77uncompwram(gfx_wondertrade_bg_lowerMap, bg2map);

    //Now we init the texts
    tbox_flush(POKEPAD_WONDERTRADE_TBOX_TITLE, 0);
    tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_TITLE);
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_TITLE, 2, 0, 0, 0, 0, wondertrade_fontcolmap, 0x0, str_pokepad_wondertrade_ref); //str_pokepad_wondertrade_ref
    
    //Now we spawn the level
    tbox_flush(POKEPAD_WONDERTRADE_TBOX_LEVEL_H, 0);
    tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_LEVEL_H);
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_LEVEL_H, 2, 0, 0, 0, 0, wondertrade_fontcolmap, 0x0, str_wondertrade_level_ref);
    
    tbox_flush(POKEPAD_WONDERTRADE_TBOX_LEVEL_T, 0);
    tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_LEVEL_T);
    u8 *wondertrade_lv_string;
    u8 lvl = wondertrade_get_level();
    switch(lvl){
        case 0:
            wondertrade_lv_string = str_wondertrade_bronze_ref;
            break;
        case 1:
            wondertrade_lv_string = str_wondertrade_silver_ref;
            break;
        case 2:
            wondertrade_lv_string = str_wondertrade_gold_ref;
            break;
        default:
            wondertrade_lv_string = str_wondertrade_platin_ref;
            break;
    }
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_LEVEL_T, 2, 0, 0, 0, 0, wondertrade_fontcolmap, 0x0, wondertrade_lv_string);
   
    //Anzahl
    tbox_flush(POKEPAD_WONDERTRADE_TBOX_CNT_H, 0);
    tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_CNT_H);
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_CNT_H, 2, 0, 0, 0, 0, wondertrade_fontcolmap, 0x0, str_wondertrade_anzahl_ref);
    
    tbox_flush(POKEPAD_WONDERTRADE_TBOX_CNT_T, 0);
    tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_CNT_T);
    u8 *strbuf = (u8*)0x02021D18;
    u16 cnt = *vardecrypt(VAR_POKEPAD_WONDERTRADE_CNT);
    hex_to_dec_String(strbuf, cnt, 0, 3);
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_CNT_T, 2, 0, 0, 0, 0, wondertrade_fontcolmap, 0x0, strbuf);
    
    //Neachster Lv.
    tbox_flush(POKEPAD_WONDERTRADE_TBOX_NEXT_H, 0);
    tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_NEXT_H);
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_NEXT_H, 2, 0, 0, 0, 0, wondertrade_fontcolmap, 0x0, str_wondertrade_next_ref);
    
    u8 *strbuf2 = (u8*)(0x02021D18+10); //We use the same strbuf since we know the number will not exceed 9 chars
    tbox_flush(POKEPAD_WONDERTRADE_TBOX_NEXT_T, 0);
    tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_NEXT_T);
    switch(lvl){
        case 0:
            cnt = (u16)(10-cnt);
            break;
        case 1:
            cnt = (u16)(50-cnt);
            break;
        case 2:
            cnt = (u16)(150-cnt);
            break;
        default:
            cnt = 0xFFFF;
            break;
    }
    if (cnt != 0xFFFF)
        hex_to_dec_String(strbuf2, cnt, 0, 3);
    else
        strcpy(strbuf2, str_wondertrade_none_ref);
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_NEXT_T, 2, 0, 0, 0, 0, wondertrade_fontcolmap, 0x0,strbuf2);
    
    //now we spawn the oam for the badges
    load_and_alloc_obj_vram_lz77(&graphic_wondertrade_badges);
    u8 bpal = allocate_obj_pal(0xA004);
    load_comp_pal_into_RAM(gfx_wondertrade_badgesPal, (u16)((16+bpal)*16), 32);
    fmem->wtrade_mem->oam_badge = generate_oam_forward_search(&oam_template_wondertrade_badges, 64, 50, 0);
    //now we change to the proper graphic
    int displacement = 0;
    switch(lvl){
        case 3:
            displacement += 4;
        case 2:
            displacement += 4;
        case 1:
            displacement += 4;
            break;
    }
    u16 attr2 = oams[fmem->wtrade_mem->oam_badge].final_oam.attr2;
    u16 base = (u16)((attr2 & 0x3FF)+displacement);
    attr2 = (u16)((attr2 & (~0x3FF)) | base);
    oams[fmem->wtrade_mem->oam_badge].final_oam.attr2 = attr2;
    
    //Now we spawn either the not possible text or the two selections
    if(fmem->wtrade_mem->usable){
        
    }else{
        //spawn the not possible text
        wondertrade_load_steps_into_buffer();
        string_decrypt(strbuf, str_wondertrade_not_possible_script_ref);
        tbox_flush(POKEPAD_WONDERTRADE_TBOX_RENDERER, 0);
        tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_RENDERER);
        tbox_print_string(POKEPAD_WONDERTRADE_TBOX_RENDERER, 2, 0, 0, 0, 0, wondertrade_fontcolmap, 0x0, strbuf); 
       
    }
   
    //scroll
    bg_virtual_map_displace(0, 0, 0);
    bg_virtual_set_displace(0, 0, 0);
    bg_virtual_map_displace(1, 0, 0);
    bg_virtual_set_displace(1, 0, 0);
    bg_virtual_map_displace(2, 0, 0);
    bg_virtual_set_displace(2, 0, 0);
    
    //pal
    load_comp_pal_into_RAM(gfx_wondertrade_bg_upperPal, 0, 32);
    load_comp_pal_into_RAM(gfx_wondertrade_bg_lowerPal, 1*16, 32);
    load_uncomp_pal_into_RAM(transparency_black_box_pals, 15*16, 32);
    if (!fmem->wtrade_mem->usable){
        //greyscale all pals
        int i;
        color black = {0};
        for (i = 0; i < 512; i++){
            color n = greyscale(pal_restore[i]);
            n = alpha_blend(n, black, 11);
            pal_restore[i] = n;
        }
    }
    load_uncomp_pal_into_RAM(transparency_black_box_pals, 13*16, 32);
    load_uncomp_pal_into_RAM(transparency_black_box_pals, 14*16, 32);
    
    bg_virtual_sync(0);
    bg_virtual_sync(1);
    bg_virtual_sync(2);
    
}

void wondertrade_init_callback(){
    cb1handling();
    if(!is_fading()){
        if(fmem->wtrade_mem->from_outdoor){
            overworld_free();
        }else{
            pokepad_free_components();
        }
        //Now we initilize the graphic components
        wondertrade_init_components();
        set_io(0x50, 0);
        set_io(0x52, 0);
        set_io(0x54, 0);
        bic_io(0, 0x6000);
        set_callback1(wondertrade_show_components);
    }
}

void wondertrade_load_steps_into_buffer(){
    u8 *buffer0 = (u8*)0x02021CD0;
    hex_to_dec_String(buffer0, *vardecrypt(VAR_POKEPAD_WONDERTRADE_STEP_CNT), 0, 3);
}

void wondertrade_init(bool is_outdoor){
    bool is_usable = false;//*vardecrypt(VAR_POKEPAD_WONDERTRADE_STEP_CNT) >= 250;
    if (is_outdoor && !is_usable){
        wondertrade_load_steps_into_buffer();
        init_script(script_wondertrade_failure);
        return;
    }
    
    init_fadescreen(1, 0);
    fmem->wtrade_mem = (wondertrade_memory*)malloc(sizeof(wondertrade_memory));
    fmem->wtrade_mem->from_outdoor = is_outdoor;
    fmem->wtrade_mem->usable = is_usable;
    set_callback1(wondertrade_init_callback);
    
}