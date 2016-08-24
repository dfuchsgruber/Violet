#include "types.h"
#include "stdbool.h"
#include "romfuncs.h"
#include "pokepad.h"
#include "pokedex.h"
#include "oams.h"
#include "callbacks.h"
#include "save.h"
#include "utils.h"
#include "bg.h"
#include "gfx.h"
#include "text.h"
#include "mega.h"
#include "pokemon.h"
#include "basestats.h"
#include "color.h"
#include "superstate.h"
#include "utils.h"
#include "transparency.h"

bg_config pokedex_bg_configs [] = {
    {0, 2, 31, 0, 0, 0},
    {1, 0, 30, 0, 0, 1},
    {2, 1, 29, 0, 0, 2},
    {3, 1, 28, 0, 0, 2}
};

tboxdata pokedex_tboxes [] = {
    {0, 11, 0, 3, 2, 15, 1}, //tbox seen
    {0, 11, 2, 3, 2, 15, 7}, //tbox caught
    {0, 14, 5, 8, 14, 15, 13}, //tbox list
    {0, 22, 5, 8, 14, 3, 125}, // type list
    {0, 12, 5, 2, 14, 4, 237}, // capture list
    {0, 7, 5, 5, 14, 14, 265}, // nr list
    
    {0xFF, 0, 0, 0, 0, 0, 0}
};

sprite pokedex_cursor_sprite = {
    0, 0x8000, 0, 0
};

gfx_frame pokedex_cursor_gfx_anim_idle[] = {
    {0,0}, {0xFFFF, 0}
};

gfx_frame pokedex_cursor_gfx_anim_active[] = {
    {0, 32}, {16, 32}, {0xFFFE, 0}
};

gfx_frame *pokedex_cursor_anims[] = {
    pokedex_cursor_gfx_anim_idle,
    pokedex_cursor_gfx_anim_active
};

graphic pokedex_cursor_graphic = {
    &gfx_pokedex_sort_cursorTiles,
    0x400,
    0xA013
};

oam_template pokedex_cursor_template = {
    0xA013,
    0xA013,
    &pokedex_cursor_sprite,
    pokedex_cursor_anims,
    NULL,
    ROTSCALE_TABLE_NULL,
    oam_null_callback
};



u8 pokedex_fontcolmap[] = {0,2,1,0};

u16 pokedex_colors[16] = {0, 0x2927, 0x7FFF, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0};
u16 pokedex_colors_nr[16] = {0, 0x7FFF, 0x2927, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0};

int pokedex_get_first_seen(){
    pokedex_list_element *list = fmem->dex_mem->list;
    int i;
    for(i = 0; i < 386; i++){
        if(pokedex_operator_by_dex_id(list[i].dex_id, 0))
            return i;
    }
    return 0;
}

void test(int a, int b){while(true){}}
int pokedex_get_last_seen(){
    pokedex_list_element *list = fmem->dex_mem->list;
    int i;
    for(i = 385; i >= 0; i--){
        if(pokedex_operator_by_dex_id(list[i].dex_id, 0))
            return i;
    }
    return 0;
}



u16 pokedex_typechart_lo_tile_table [] = {
    0, 64 + 4, 64, 96, 32 + 8, 32 + 4, 64 + 12,
    64 + 8, 96 + 8, 128+4, 4, 8, 12, 32, 96 + 4, 32 + 12,
    128, 96 + 12
};



void pokedex_update_list(){
    pokedex_list_element *list = fmem->dex_mem->list;
    fmem->dex_mem->current_species = list[fmem->dex_mem->current_list_index].species;
    //find first and last element in list
    int first = fmem->dex_mem->current_list_index - fmem->dex_mem->cursor_anchor - 3;//
    if(first < pokedex_get_first_seen())
        first = pokedex_get_first_seen();
    int last = first + 7;
    if(last > pokedex_get_last_seen())
        //test(pokedex_get_last_seen(),fmem->dex_mem->current_list_index);
        last = pokedex_get_last_seen();
        first = last-7;
        if(first < pokedex_get_first_seen())
            first = pokedex_get_first_seen();
    
    u8 *buf = strbuf;
    *buf = 0xFF;
    
    
    u8 str_none [] = { 0,0xFF};
    u8 str_pokepad_pokedex_cursor [] = {0xEF, 0xFF};
     
    
    u8 *pokemon_names = *pokemon_names_ptr;
        
    tbox_flush(POKEDEX_TBOX_LIST_NAME, 0);
    tbox_flush(POKEDEX_TBOX_LIST_TYPES, 0);
    tbox_flush(POKEDEX_TBOX_LIST_CAPTURE, 0);
    tbox_flush(POKEDEX_TBOX_LIST_NR, 0);
    int i = 0;
    while(first <= last){
        u16 y_pixel = (u16)(14 * i);
        
        //We create the number string
        pokedex_tbox_draw_num(POKEDEX_TBOX_LIST_NR, 0, list[first].species, 0xC, y_pixel);
        
        //buf = str_append(buf, first == fmem->dex_mem->current_list_index ? str_arrow : str_none);
        if (first == fmem->dex_mem->current_list_index){
            buf = str_append(buf, str_pokepad_pokedex_cursor);
        }
        if (list[first].seen){
            buf = str_append(buf, &pokemon_names[list[first].species * 11]);
        }else{
            buf = str_append(buf, str_pokepad_pokedex_unkown_ref);
        }
        buf = str_append(buf, str_pokepad_pokedex_nl_ref);
        
        
        if(list[first].caught){
            //now we draw the types
            u8 type1 = (u8)(basestats[list[first].species].type1 + 1);
            u8 type2 = (u8)(basestats[list[first].species].type2 + 1);
            tbox_draw_type_icon_by_type_p1(POKEDEX_TBOX_LIST_TYPES, type1, 0, y_pixel);
            if(type1 != type2)
                tbox_draw_type_icon_by_type_p1(POKEDEX_TBOX_LIST_TYPES, type2, 0x20, y_pixel);
            tbox_draw_type_icon_by_type_p1(POKEDEX_TBOX_LIST_CAPTURE, 0, 0, y_pixel);
        }else{
            
        }
        
        //Now we draw the typechart (lmostup x = 22, y = 5)
        
        /*
        if(type2 == type1) type2 = 0xFF;
        u8 y = (u8)(5 + 2 * i);
         * */
        first++;
        i++;
    
    }
   
    tbox_tilemap_draw(POKEDEX_TBOX_LIST_NAME);
    tbox_tilemap_draw(POKEDEX_TBOX_LIST_TYPES);
    tbox_tilemap_draw(POKEDEX_TBOX_LIST_CAPTURE);
    tbox_tilemap_draw(POKEDEX_TBOX_LIST_NR);
    tbox_print_string(POKEDEX_TBOX_LIST_NAME, 2, 0, 0, 0, 0, pokedex_fontcolmap, 0, strbuf);
    tbox_print_string(POKEDEX_TBOX_LIST_TYPES, 2, 0, 0, 0, 0, pokedex_fontcolmap, 0, str_none);
    tbox_print_string(POKEDEX_TBOX_LIST_CAPTURE, 2, 0, 0, 0, 0, pokedex_fontcolmap, 0, str_none);
    tbox_print_string(POKEDEX_TBOX_LIST_NR, 2, 0, 0, 0, 0, pokedex_fontcolmap, 0, str_none);
    bg_virtual_sync(0);
    
    //while(true){}
}

void pokedex_free_maps(){
    free(bg_get_tilemap(0));
    free(bg_get_tilemap(1));
    free(bg_get_tilemap(2));
    free(bg_get_tilemap(3));
}

void pokedex_callback_return(){
    cb1handling();
    if(!is_fading()){
       //end pokedex
        *vardecrypt(POKEDEX_VAR_COMPARATOR) = fmem->dex_mem->current_comparator;
        *vardecrypt(POKEDEX_VAR_LAST_SPECIES) = fmem->dex_mem->current_species;
        pokedex_free_maps();
        free(fmem->dex_mem->list);
        if(fmem->dex_mem->from_outdoor){
            set_callback1(map_reload);
        }else{
            set_callback1(pokepad_callback_init);
        }
        free(fmem->dex_mem);
    }
}

void pokedex_callback_group_selection(){
    cb1handling();
    if(!is_fading()){
        
        //first we proceed in fading process of current group
        if (fmem->dex_mem->group_fading_mode){
            //fade count decrease
            if(fmem->dex_mem->group_fading_index){ fmem->dex_mem->group_fading_index--;}
            else {fmem->dex_mem->group_fading_mode = false;}
        }else{
            //fade count increase
            if(fmem->dex_mem->group_fading_index < 16){fmem->dex_mem->group_fading_index++;}
            else {fmem->dex_mem->group_fading_mode = true;}
        }
        
        
        //Progress in input
        if(super->keys_new.keys.A){
            sound(5);
            switch(fmem->dex_mem->current_group){
                case 0:
                    fmem->dex_mem->list_countdown = 0;
                    fmem->dex_mem->list_mode = 0;
                    set_callback1(pokedex_callback_list);
                    fmem->dex_mem->group_fading_index = 16;
                    fmem->dex_mem->group_fading_mode = true;
                    break;
                case 2:
                    fmem->dex_mem->resorting = false;
                    fmem->dex_mem->sort_cursor_pos = fmem->dex_mem->current_comparator & 0x3;
                    fmem->dex_mem->group_fading_index = 16;
                    fmem->dex_mem->group_fading_mode = true;
                    set_callback1(pokedex_callback_sort);
                    oams[fmem->dex_mem->oam_sort_cursor].anim_number = 1;
                    gfx_init_animation (&oams[fmem->dex_mem->oam_sort_cursor], 0);
                    break;
            }
        }else if(super->keys_new.keys.B){
            set_callback1(pokedex_callback_return);
            init_fadescreen(1, 0);
            sound(5);
        }else if(super->keys_new.keys.left && !fmem->dex_mem->current_group){
            //we switch to feature selection
            fmem->dex_mem->current_group = 1;
            pokedex_group_window_set();
            sound(5);
        }else if(super->keys_new.keys.up && fmem->dex_mem->current_group <= 1){
            fmem->dex_mem->current_group = 2;
            pokedex_group_window_set();
            sound(5);
        }else if(super->keys_new.keys.down && fmem->dex_mem->current_group == 2){
            fmem->dex_mem->current_group = 0;
            pokedex_group_window_set();
            sound(5);
        }else if(super->keys_new.keys.right && fmem->dex_mem->current_group == 1){
            fmem->dex_mem->current_group = 0;
            pokedex_group_window_set();
            sound(5);
        }
        color over = {0x7FFF};
        pals[17] = alpha_blend(pal_restore[17], over, fmem->dex_mem->group_fading_index);
        
        
    }
}

void pokedex_group_window_set(){
    set_io(0, get_io(0) | 0x2000); //enable win0
    set_io(0x48, 0x1F1F); //all bgs and obj layer are inside window
    set_io(0x4A, 0x1B1B); //bg2 is excluded from outside the window
    u8 leftmost = 0;
    u8 rightmost = 240;
    u8 topmost = 0;
    u8 bottommost = 160;
    switch(fmem->dex_mem->current_group){
        case 0://list group, we set the window
            topmost = 31;
            leftmost = 63;
            break;
        case 1:
            topmost = 29;
            rightmost = 63;
            break;
        case 2:
            bottommost = 33;
            leftmost = 110;
            break;
    }
    u16 hdim = (u16)(rightmost | (leftmost << 8));
    u16 vdim = (u16)(bottommost | (topmost << 8));
    set_io(0x40, hdim);
    set_io(0x44, vdim);
}

void pokedex_show_components(){
    bg_sync_display_and_show(0);
    bg_sync_display_and_show(1);
    bg_sync_display_and_show(2);
    bg_sync_display_and_show(3);
    bg_display_sync();
    pokedex_group_window_set();
    set_callback1(pokedex_callback_group_selection);
}

void pokedex_sort_locate_cursor(){;
    oams[fmem->dex_mem->oam_sort_cursor].x2 = (s16)(fmem->dex_mem->sort_cursor_pos * 32);
}

void pokedex_init_components(){
    oam_reset();
    remove_all_big_callbacks();
    pal_fade_cntrl_reset();
    //dma0_cb_reset();
    set_callback3(NULL);
    bg_reset(0);
    bg_setup(0, pokedex_bg_configs, 4);
    
    void *bg0map = malloc_fill(0x800);
    void *bg1map = malloc(0x800);
    void *bg2map = malloc(0x800);
    void *bg3map = malloc(0x800);
    bg_set_tilemap(0, bg0map);
    bg_set_tilemap(1, bg1map);
    bg_set_tilemap(2, bg2map);
    bg_set_tilemap(3, bg3map);
    
    //Load graphics
    lz77uncompwram(gfx_pokedex_uiMap, bg1map);
    lz77uncompvram(gfx_pokedex_uiTiles, (void*)0x06000000);
    lz77uncompwram(gfx_pokedex_bottom_1Map, bg2map);
    lz77uncompvram(gfx_pokedex_bottom_1Tiles, (void*)0x06004000);
    lz77uncompwram(gfx_pokedex_bottom_0Map, bg3map);
    cpuset((void*)0x08E95DFC, (void*)0x0600a000, 0xc00);
    
    //TODO: textbox load
    tbox_sync_with_virtual_bg_and_init_all(pokedex_tboxes);
    
    u16 seen = pokedex_get_number_seen_or_caught(false);
    u16 caught = pokedex_get_number_seen_or_caught(true);
    hex_to_dec_String(strbuf, seen, 0, 3);
    tbox_flush(POKEDEX_TBOX_SEEN, 0);
    tbox_tilemap_draw(POKEDEX_TBOX_SEEN);
    tbox_print_string(POKEDEX_TBOX_SEEN, 2, 0, 0, 0, 0, pokedex_fontcolmap, 0, strbuf);
    hex_to_dec_String(strbuf, caught, 0, 3);
    tbox_flush(POKEDEX_TBOX_CAUGHT, 0);
    tbox_tilemap_draw(POKEDEX_TBOX_CAUGHT);
    tbox_print_string(POKEDEX_TBOX_CAUGHT, 2, 0, 0, 0, 0, pokedex_fontcolmap, 0, strbuf);
    
    //Displacements
    bg_virtual_map_displace(0, 0, 0);
    bg_virtual_set_displace(0, 0, 0);
    bg_virtual_map_displace(1, 0, 0);
    bg_virtual_set_displace(1, 0, 0);
    bg_virtual_map_displace(2, 0, 0);
    bg_virtual_set_displace(2, 0, 0);
    bg_virtual_map_displace(3, 0, 0);
    bg_virtual_set_displace(3, 0, 0);
    
    //Now we load the oam
    load_and_alloc_obj_vram_lz77(&pokedex_cursor_graphic);
    
    u8 cursor_pal = (u8)(allocate_obj_pal(0xA013) + 0x10);
    load_comp_pal_into_RAM(gfx_pokedex_sort_cursorPal, (u16)(cursor_pal*16), 32);
    fmem->dex_mem->oam_sort_cursor = generate_oam_forward_search(&pokedex_cursor_template, 128, 16, 0);
    fmem->dex_mem->sort_cursor_pos = fmem->dex_mem->current_comparator & 3;
    pokedex_sort_locate_cursor();
    
    load_comp_pal_into_RAM(gfx_pokedex_uiPal, 0, 32);
    load_comp_pal_into_RAM(gfx_pokedex_bottom_1Pal, 16, 32);
    load_comp_pal_into_RAM(gfx_pokedex_bottom_0Pal, 32, 32);
    load_uncomp_pal_into_RAM(pokedex_colors, 15*16, 16);
    load_uncomp_pal_into_RAM(pokedex_colors_nr, 14*16, 32);
    load_uncomp_pal_into_RAM((void*)0x08E95DDC, 3*16, 32);
    load_uncomp_pal_into_RAM((void*)0x08E95DBC, 4*16, 32);
    pal_set_all_to_black();
    
    init_fadescreen(0, 0);
    set_callback1(pokedex_show_components);
    
    bg_virtual_sync(0);
    bg_virtual_sync(1);
    bg_virtual_sync(2);
    bg_virtual_sync(3);
    
    
}
/**
void pokedex_big_callback_quicksort_parallel(u8 self){
    
    if(!big_callbacks[self].params[0]){
        //init quicksort
        int *stack = (int*)malloc(386);
        int top = -1;
        stack[++top] = 0;
        stack[++top] = 385;
        big_callback_set_int(self, 2, (int)stack);
        big_callback_set_int(self, 4, top);
        big_callbacks[self].params[0] = 1;
    }else{
        //Now we proceed with quicksort
        int *stack  = (int*)big_callback_get_int(self, 2);
        int top = big_callback_get_int(self, 4);
        int it, l ,r;
        u8 comparator = fmem->dex_mem->current_comparator;
        for (it = 0; it < 4; it++){ //4 recursions per frame as maximum
            if(top >= 0){
                r = stack[top--];
                l = stack[top--];
                if (l < r){
                    int i = l-1;
                    int j = r;
                    do{ //split array
                        do{i++;}while(pokedex_quicksort_list_compare(comparator, i, r) < 0);
                        do{j--;}while(j >= l && pokedex_quicksort_list_compare(comparator, j, r) > 0);
                        if (i < j)
                            pokedex_quicksort_list_swap(i, j);
                    }while(i < j);
                    pokedex_quicksort_list_swap(i, r);
                    stack[++top] = l;
                    stack[++top] = i-1;
                    stack[++top] = i+1;
                    stack[++top] = r;
                }
            }else{
                //list is sorted -> we remove the big callback
                int i;
                for(i = 0; i <386; i++){
                    if(fmem->dex_mem->current_species){
                        if(fmem->dex_mem->list[i].species == fmem->dex_mem->current_species){
                            fmem->dex_mem->current_list_index = (u16)i;
                            break;
                        }
                    }else{
                        if(fmem->dex_mem->list[i].seen){
                            fmem->dex_mem->current_list_index = (u16)i;
                            break;   
                        }
                    }
                }
                free(stack);
                remove_big_callback(self);
                return;
            }
        }
        //we reached this point, so we store our current results
        big_callback_set_int(self, 2, (int)stack);
        big_callback_set_int(self, 4, top);
    }
}
 **/

void pokedex_big_callback_resort(u8 self){
    switch(big_callbacks[self].params[0]){
        case 0:{ //init resort (win1 feature)
            sound(6);
            u16 dispcnt = get_io(0) | 0x4000;
            set_io(0, dispcnt);
            set_io(0x48, 0x81F); //everything is in window 0 but nothing is in window 1
            set_io(0x42, 0x40F0); //leftmost = 64, rightmost = 240
            set_io(0x46, 0xa0A0); //topmost = 33, bottommost = 160
            big_callbacks[self].params[0] = 1;
            big_callbacks[self].params[1] = 160;
            //spawn_big_callback(pokedex_big_callback_quicksort_parallel, 0);
            break;
        }
        case 1:{
            //move window upwards
            if(big_callbacks[self].params[1] <= 33){
                big_callbacks[self].params[1] = 33;
                big_callbacks[self].params[0] = 2;
            }else{
                big_callbacks[self].params[1] = (u16)(big_callbacks[self].params[1] - 8);
            }   
            u16 topmost_new = (u16)(big_callbacks[self].params[1] << 8);
            set_io(0x46, topmost_new | 0xA0);
            break;
        }
        case 2:{
            //sound(4);
            //while(true){}
            if(fmem->dex_mem->reverse_req){
                pokedex_quicksort_revert(0, 386);
            }else{
                pokedex_quicksort_list(fmem->dex_mem->current_comparator, 0, 385);
            }
            pokedex_update_list();
            big_callbacks[self].params[0] = 3;
            sound(6);
            break;
        }
        case 3:{
            //move window downwards
            if(big_callbacks[self].params[1] >= 232){

                u16 dispcnt = (u16)(get_io(0) & (~0x4000));
                set_io(0, dispcnt);
                fmem->dex_mem->resorting = false;
                remove_big_callback(self);
            }else{
                big_callbacks[self].params[1] = (u16)(big_callbacks[self].params[1] + 8);
            }
            u16 topmost_new = (u16)(big_callbacks[self].params[1] << 8);
            if(topmost_new > 0xA000) topmost_new = 0xA000;
            set_io(0x46, topmost_new | 0xA0);
            break;
        }
        
    }
    /*
    pokedex_quicksort_list(fmem->dex_mem->current_comparator, 0, 385);
    pokedex_update_list();
    fmem->dex_mem->resorting = false;
    remove_big_callback(self);
     */
}

void pokedex_callback_sort(){
    cb1handling();
    if(fmem->dex_mem->resorting)
        return;
    if(super->keys_new.keys.B){
        //return to group selection
        oams[fmem->dex_mem->oam_sort_cursor].anim_number = 0;
        gfx_init_animation (&oams[fmem->dex_mem->oam_sort_cursor], 0);
        set_callback1(pokedex_callback_group_selection);
        sound(5);
        return;
    }else if(super->keys_new.keys.A){
        //log new sorting
        u8 old_sorting = fmem->dex_mem->current_comparator & 3;
        u8 new_sorting = fmem->dex_mem->sort_cursor_pos;
        if(old_sorting == new_sorting){
            fmem->dex_mem->current_comparator ^= 4;
            fmem->dex_mem->reverse_req = true;
        }else{
            fmem->dex_mem->current_comparator = new_sorting;
            fmem->dex_mem->reverse_req = false;
        }
        fmem->dex_mem->resorting = true;
        sound(5);
        big_callbacks[spawn_big_callback(pokedex_big_callback_resort, 0)].params[0] = 0;
    }else if(super->keys_new.keys.left && fmem->dex_mem->sort_cursor_pos > 0){
        fmem->dex_mem->sort_cursor_pos--;
        pokedex_sort_locate_cursor();
        sound(5);
    }else if(super->keys_new.keys.right && fmem->dex_mem->sort_cursor_pos < 3){
        fmem->dex_mem->sort_cursor_pos++;
        pokedex_sort_locate_cursor();
        sound(5);
    }
    
}

bool pokedex_callback_list_mode_proceed(){
    switch(fmem->dex_mem->list_mode){
        case 1:
            if(super->keys.keys.down){
                if(super->keys_new_rst.keys.down)
                    fmem->dex_mem->list_fast_mode = true;
                return true;
            }
            break;
        case 2:
            if(super->keys.keys.up){
                if(super->keys_new_rst.keys.up)
                    fmem->dex_mem->list_fast_mode = true;
                return true;
            }
            break;
        case 3:
            if(super->keys.keys.right){
                if(super->keys_new_rst.keys.right)
                    fmem->dex_mem->list_fast_mode = true;
                return true;
            }
            break;
        case 4:
            if(super->keys.keys.left){
                if(super->keys_new_rst.keys.left)
                    fmem->dex_mem->list_fast_mode = true;
                return true;
            }
            break;
    }
    return false;
}

void pokedex_callback_list_enter_mode(u8 mode){
    if(mode == 1 || mode == 3){
        fmem->dex_mem->cursor_anchor = true;
    }else if(mode == 2 || mode == 4){
        fmem->dex_mem->cursor_anchor = false;
    }
    fmem->dex_mem->list_mode = mode;
    fmem->dex_mem->list_fast_mode = false;
}

void pokedex_callback_list(){
    cb1handling();
    
    if(super->keys_new.keys.down){
        pokedex_callback_list_enter_mode(1);
    }else if(super->keys_new.keys.up){
        pokedex_callback_list_enter_mode(2);
    }else if(super->keys_new.keys.right){
        pokedex_callback_list_enter_mode(3);
    }else if(super->keys_new.keys.left){
        pokedex_callback_list_enter_mode(4);
    }else if(super->keys_new.keys.A){
        //Todo enter page
        return;
    }else if(super->keys_new.keys.B){
        //Todo return to group selection
        set_callback1(pokedex_callback_group_selection);
        sound(5);
        return;
    }
    //No new key was pressed, check if we stay in mode
    if(pokedex_callback_list_mode_proceed()){
        //We stay in mode (maybe we just enabled fast mode)
        if(fmem->dex_mem->list_countdown){
            fmem->dex_mem->list_countdown--;
        }else{
            int mode_lo[] = {0, 1, -1, 8, -8};
            u16 index_old = fmem->dex_mem->current_list_index;
            int index_new = index_old + mode_lo[fmem->dex_mem->list_mode];
            if(index_new < pokedex_get_first_seen())
                index_new = pokedex_get_first_seen();
            if(index_new > pokedex_get_last_seen())
                index_new = pokedex_get_last_seen();
            if(index_new != index_old){
                sound(5);
                fmem->dex_mem->current_list_index = (u16)index_new;
                fmem->dex_mem->list_countdown = fmem->dex_mem->list_fast_mode ? 0 : 8;
                pokedex_update_list();
            }
        }
    }
    
}

void pokedex_build_list(){
    pokedex_list_element *list = (pokedex_list_element*)malloc(386*sizeof(pokedex_list_element));
    fmem->dex_mem->list = list;
    int list_size = 0;
    u16 i;
    int j;
    for (i = 0; i < POKEMON_CNT; i++){
        //check if pokemon is a mega target
        bool is_mega_target = (i > 251 && i < 277) || !i;
        j = 0;
        while(megas[j].species != 0xFFFF){
            if(megas[j].target == i){
                is_mega_target = true;
                break;
            }
            j++;
        }
        if(!is_mega_target){
            //Add the pokemon to list with its dex number
            list[list_size].species = i;
            u16 dex_id = pokedex_get_id(i);
            list[list_size].dex_id = dex_id;
            list[list_size].seen = pokedex_operator_by_dex_id(dex_id, 0);
            list[list_size].caught = pokedex_operator_by_dex_id(dex_id, 1);
            list_size++;
        }
    }
    if(list_size > 386){
        while(true){}//Debuging exit
    }
}

void pokedex_quicksort_list_swap(int a, int b){
   pokedex_list_element *list = fmem->dex_mem->list;
   pokedex_list_element tmp;
   memcopy(&tmp, &list[a], sizeof(pokedex_list_element));
   memcopy(&list[a], &list[b], sizeof(pokedex_list_element));
   memcopy(&list[b], &tmp, sizeof(pokedex_list_element));
}

void pokedex_quicksort_revert(int from, int to){
    do{
        pokedex_quicksort_list_swap(from++, --to);
    }while(to > from);
}

int pokedex_quicksort_list_compare(u8 comparator, int a, int b){
    pokedex_list_element *list = fmem->dex_mem->list;
    u8 *pokemon_names = *pokemon_names_ptr;
    int reverse = comparator > 3 ? -1 : 1;
    comparator &= 3;
    switch(comparator){
        case 0://by number
            return (list[a].dex_id - list[b].dex_id)*reverse;
            break;
        case 1:{//by name
            u8 *name_a = &pokemon_names[11 *list[a].species];
            u8 *name_b = &pokemon_names[11 *list[b].species];
            int i = 0;
            while(true){
                if(name_a[i]-name_b[i])
                    return (name_a[i] - name_b[i])*reverse;
                if(name_a[i] == 0xFF)
                    
                    return 0;
                i++;
            }
            break;
        }
        case 2:{//by height
            int dif = (pokedex_get_data(list[a].dex_id)->height - pokedex_get_data(list[b].dex_id)->height)*reverse;
            if(dif) return dif;
            return (list[a].dex_id - list[b].dex_id)*reverse;
        }
        case 3:{
            int dif = (pokedex_get_data(list[a].dex_id)->weight - pokedex_get_data(list[b].dex_id)->weight)*reverse;
            if(dif) return dif;
            return (list[a].dex_id - list[b].dex_id)*reverse;
        }
    }
    return a-b;
}

void pokedex_quicksort_list(u8 comparator, int l, int r){
    //we do an iteratiive implementation of quicksort
    int *stack = (int*)malloc((u32)(r-l+1)*sizeof(int));
    int top = -1;
    stack[++top] = l;
    stack[++top] = r;
    
    while(top >= 0){
        r = stack[top--];
        l = stack[top--];
        if (l < r){
            int i = l-1;
            int j = r;
            do{ //split array
                do{i++;}while(pokedex_quicksort_list_compare(comparator, i, r) < 0);
                do{j--;}while(j >= l && pokedex_quicksort_list_compare(comparator, j, r) > 0);
                if (i < j)
                    pokedex_quicksort_list_swap(i, j);
            }while(i < j);
            pokedex_quicksort_list_swap(i, r);
            stack[++top] = l;
            stack[++top] = i-1;
            stack[++top] = i+1;
            stack[++top] = r;
        }
    }
    //now we find the index in the list of current species
    int i;
    for(i = 0; i <386; i++){
        if(fmem->dex_mem->current_species){
            if(fmem->dex_mem->list[i].species == fmem->dex_mem->current_species){
                fmem->dex_mem->current_list_index = (u16)i;
                break;
            }
        }else{
            if(fmem->dex_mem->list[i].seen){
                fmem->dex_mem->current_list_index = (u16)i;
                break;   
            }
        }
    }
    
    free(stack);
}

void pokedex_callback_init(){
    cb1handling();
    if(!is_fading()){
        if(fmem->dex_mem->from_outdoor){
            overworld_free();
        }else{
            pokepad_free_components();
        }
        pokedex_init_components();
        pokedex_build_list();
        pokedex_quicksort_list((u8)fmem->dex_mem->current_comparator, 0, 385); //resort list
        pokedex_update_list();
        set_io(0x50, 0);
        set_io(0x52, 0);
        set_io(0x54, 0);
        
        bic_io(0, 0x6000);
    }
}

void pokedex_init(bool from_outdoor){
    fmem->dex_mem = (pokedex_memory*)malloc(sizeof(pokedex_memory));
    fmem->dex_mem->from_outdoor = from_outdoor;
    fmem->dex_mem->current_group = 0;
    fmem->dex_mem->current_species = *vardecrypt(POKEDEX_VAR_LAST_SPECIES);
    fmem->dex_mem->current_comparator = (u8)*vardecrypt(POKEDEX_VAR_COMPARATOR);
    fmem->dex_mem->cursor_anchor = 0;
    set_callback1(pokedex_callback_init);
    init_fadescreen(1, 0);
}
