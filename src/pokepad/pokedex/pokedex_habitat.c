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

bg_config pokedex_bg_habitat_configs [] = {
    {0, 2, 31, 0, 0, 0},
    {1, 0, 30, 0, 0, 2},
    {2, 3, 29, 0, 0, 1},
    {3, 1, 28, 0, 0, 3}
};

tboxdata pokedex_habitat_tboxes [] = {
    {0, 6, 0, 24, 2, 15, 1}, //Title Line := 0x0
    {0, 1, 4, 5, 2, 15, 49}, //Grass := 0x1
    {0, 1, 8, 5, 2, 15, 59}, //Water := 0x2
    {0, 1, 12, 5, 2, 15, 69}, //Rod := 0x3
    {0, 1, 16, 5, 2, 15, 79}, //Radar := 0x4
    {1, 6, 2, 15, 2, 13, 1}, //Namespace := 0x5 on BG 1
    {1, 9, 10, 20, 2, 13, 31}, //Not found := 0x6 on BG 1
    {0xFF, 0, 0, 0, 0, 0, 0},
};

graphic pokedex_habitat_cursor_graphic = {
    (void*) 0x083EED38,
    0x100,
    0xA014
};

graphic pokedex_habitat_male_graphic = {
    (void*) 0x08980C44,
    0x80,
    0xA015
};

graphic pokedex_habitat_female_graphic = {
    (void*) 0x083EEDF4,
    0x80,
    0xA015
};

graphic pokedex_habitat_rarity_graphic = {
    &gfx_pokedex_habitat_rarityTiles,
    0x200,
    0xA016
};

graphic pokedex_habitat_rod_graphic = {
    &gfx_pokedex_habitat_rodTiles,
    0x200,
    0xA017
};

sprite pokedex_habitat_cursor_sprite = {
    0, 0x4000, 0x0, 0
};

sprite pokedex_habitat_head_sprite = {
    0, 0x4000, 0x400, 0
};

gfx_frame pokedex_habitat_cursor_gfx_anim[] = {
    {0, 32}, {4, 32}, {0xFFFE, 0}
};

gfx_frame *pokedex_habitat_cursor_gfx_anim_table[] = {
    pokedex_habitat_cursor_gfx_anim
};

gfx_frame pokedex_habitat_rarity_gfx_frame_0[] = {
    {0, 0}, {0xFFFF, 0}
};

gfx_frame pokedex_habitat_rarity_gfx_frame_1[] = {
    {4, 0}, {0xFFFF, 0}
};

gfx_frame pokedex_habitat_rarity_gfx_frame_2[] = {
    {8, 0}, {0xFFFF, 0}
};

gfx_frame pokedex_habitat_rarity_gfx_frame_3[] = {
    {12, 0}, {0xFFFF, 0}
};

gfx_frame *pokedex_habitat_rarity_gfx_anim_table[] = {
    pokedex_habitat_rarity_gfx_frame_0,
    pokedex_habitat_rarity_gfx_frame_1,
    pokedex_habitat_rarity_gfx_frame_2,
    pokedex_habitat_rarity_gfx_frame_3
};

oam_template pokedex_habitat_cursor_template = {
    0xA014,
    0xA014,
    &pokedex_habitat_cursor_sprite,
    pokedex_habitat_cursor_gfx_anim_table,
    NULL,
    ROTSCALE_TABLE_NULL,
    oam_null_callback
};

oam_template pokedex_habitat_head_template = {
    0xA015,
    0xA015,
    &pokedex_habitat_head_sprite,
    GFX_ANIM_TABLE_NULL,
    NULL,
    ROTSCALE_TABLE_NULL,
    oam_null_callback
};

oam_template pokedex_habitat_rarity_template = {
    0xA016,
    0xA016,
    &pokedex_habitat_cursor_sprite,
    pokedex_habitat_rarity_gfx_anim_table,
    NULL,
    ROTSCALE_TABLE_NULL,
    oam_null_callback
};

oam_template pokedex_habitat_rod_template = {
    0xA017,
    0xA016,
    &pokedex_habitat_cursor_sprite,
    pokedex_habitat_rarity_gfx_anim_table,
    NULL,
    ROTSCALE_TABLE_NULL,
    oam_null_callback
};

u8 pokedex_fontcolmap_namespace[4] = {3,2,1,0};

int *worldmap_tilemaps[4] = {
    (int*)0x09371600,
    (int*)0x083F0354,
    (int*)0x083F0464,
    (int*)0x080C0564
};

const int *gfx_worldmapTiles = (int*)0x09370200;
const void *gfx_worldmapPal = (void*)0x083EEB32;
u8 *namespace_worldmap_associations = (u8*)0x083F12FC;

void test(int a, int b){while(true){}}

void pokedex_init_habitat(){
    cb1handling();
    if(!is_fading()){
        
        //we find the current worldmap
        u8 current_namespace = get_mapheader((*save1)->bank, (*save1)->map)->name_bank;
        int i, j;
        fmem->dex_mem->current_worldmap = 0;
        if (current_namespace >= 0x8F){
            for(i = 0; i < 3; i++){
                j = 0;
                while(namespace_worldmap_associations[30*i+j] != 0xC5){
                    if(namespace_worldmap_associations[30*i+j] == current_namespace)
                        fmem->dex_mem->current_worldmap = (u8)(i+1);
                }
            }
        }
        
        free(bg_get_tilemap(0));
        free(bg_get_tilemap(1));
        free(bg_get_tilemap(2));
        free(bg_get_tilemap(3));
        oam_reset();
        bg_reset(0);
        oam_reset();
        remove_all_big_callbacks();
        pal_fade_cntrl_reset();
        pal_allocation_reset();
        free_all_tboxes();
        set_callback3(NULL);
        bg_reset(0);
        bg_setup(0, pokedex_bg_habitat_configs, 4); //we use same configs as we want to use each bg seperatly
        
        void *bg0map = malloc_fill(0x800);
        void *bg1map = malloc_fill(0x800);
        void *bg2map = malloc_fill(0x800);
        u16 *bg3map = malloc_fill(0x800);
        bg_set_tilemap(0, bg0map);
        bg_set_tilemap(1, bg1map);
        bg_set_tilemap(2, bg2map);
        bg_set_tilemap(3, bg3map);
        
        set_io(0x18, 0);
        set_io(0x1C, (u16)(-24));
        
        u16 *gp_tmp = (u16*)0x0201C000;
        
        lz77uncompvram(gfx_worldmapTiles, (void*)0x06004000);
        lz77uncompwram(worldmap_tilemaps[fmem->dex_mem->current_worldmap], gp_tmp);
        lz77uncompvram(gfx_pokedex_habitat_uiTiles, (void*)0x0600C000);
        lz77uncompwram(gfx_pokedex_habitat_uiMap, bg2map);
        
        pokedex_habitats_load_for_species(gp_tmp);
        
        //unpack the tilemap to 32 width
        for (i = 0; i < 20; i++){
            //line loop
            for(j = 0; j < 32; j++){
                //col loop
                bg3map[i*32+j] = j < 30 ? gp_tmp[i*30+j] : 0;
            }
        }
        
        //Tboxes
        tbox_sync_with_virtual_bg_and_init_all(pokedex_habitat_tboxes);
        
        tbox_flush(0, 0);
        tbox_tilemap_draw(0);
        u8 *title = strcpy(strbuf, str_pokepad_pokedex_habitat_title_ref);
        title = str_append(title, pokemon_names[fmem->dex_mem->current_species]);
        tbox_print_string(0, 2, 0, 0, 0, 0, pokedex_fontcolmap, 0, strbuf);
        tbox_print_string(0, 2, 144, 0, 0, 0, pokedex_fontcolmap, 0, str_pokepad_pokedex_habitat_back_ref);
        
        tbox_flush(1, 0);
        tbox_tilemap_draw(1);
        tbox_print_string(1, 2, 0, 0, 0, 0, pokedex_fontcolmap, 0, str_pokepad_pokedex_habitat_grass_ref);
        
        tbox_flush(2, 0);
        tbox_tilemap_draw(2);
        tbox_print_string(2, 2, 0, 0, 0, 0, pokedex_fontcolmap, 0, str_pokepad_pokedex_habitat_water_ref);
         
        tbox_flush(3, 0);
        tbox_tilemap_draw(3);
        tbox_print_string(3, 2, 0, 0, 0, 0, pokedex_fontcolmap, 0, str_pokepad_pokedex_habitat_rod_ref);
        
        tbox_flush(4, 0);
        tbox_tilemap_draw(4);
        tbox_print_string(4, 2, 0, 0, 0, 0, pokedex_fontcolmap, 0, str_pokepad_pokedex_habitat_radar_ref);
        
        //pal
        load_uncomp_pal_into_RAM(gfx_worldmapPal, 0, 0xA0);
        load_comp_pal_into_RAM(gfx_pokedex_habitat_uiPal, 4 * 16, 32);
        load_uncomp_pal_into_RAM((void*)0x83EEAB2, (u16)((16+allocate_obj_pal(0xA014))*16), 30);
        load_comp_pal_into_RAM(gfx_pokedex_habitat_rarityPal, (u16)((16+allocate_obj_pal(0xA016))*16), 32);
        //load_comp_pal_into_RAM(gfx_pokedex_habitat_rodPal, (u16)((16+allocate_obj_pal(0xA017))*16), 32);
        void *head_pal = (*save2)->player_is_female ? (void*)0x083EEAF2 : (void*)0x083EEAD2;
        load_uncomp_pal_into_RAM(head_pal, (u16)((16+allocate_obj_pal(0xA015))*16), 32);
        load_uncomp_pal_into_RAM(transparency_black_box_pals, 16*13, 32);
        pal_set_all_to_black();
        
        //oam
        s16 origin_x = (s16)((fmem->dex_mem->habitat_cursor_x + 7) * 8 + 4);
        s16 origin_y = (s16)((fmem->dex_mem->habitat_cursor_y + 4) * 8 + 4);
        if((*save2)->player_is_female){
            load_and_alloc_obj_vram_lz77(&pokedex_habitat_female_graphic);
        }else{
            load_and_alloc_obj_vram_lz77(&pokedex_habitat_male_graphic);
        }
        fmem->dex_mem->oam_habitat_head = generate_oam_forward_search(&pokedex_habitat_head_template, origin_x, origin_y, 0);
        load_and_alloc_obj_vram_lz77(&pokedex_habitat_rarity_graphic);
        for (i = 0; i < 4; i++){
            if (i != HABITAT_TYPE_ROD)
                fmem->dex_mem->habitat_oams_rarity[i] = generate_oam_forward_search(&pokedex_habitat_rarity_template, 24, (s16)((6+4*i)*8+6), 0);
        }
        load_and_alloc_obj_vram_lz77(&pokedex_habitat_cursor_graphic);
        fmem->dex_mem->oam_habitat_cursor = generate_oam_forward_search(&pokedex_habitat_cursor_template, origin_x, origin_y, 0);
        
        load_and_alloc_obj_vram_lz77(&pokedex_habitat_rod_graphic);
        for(i = 0; i < 3; i++){
            fmem->dex_mem->habitat_oams_rod[i] = generate_oam_forward_search(&pokedex_habitat_rod_template, (s16)(8+i*16), 118, 0);
        }
                
        pokedex_habitats_update();
        
        set_callback1(pokedex_habitat_callback_idle);
        fmem->dex_mem->habitat_cursor_is_moving = false;
        init_fadescreen(0, 0);
        
        bg_virtual_sync(0);
        bg_virtual_sync(1);
        bg_virtual_sync(2);
        bg_virtual_sync(3);
        
        bg_sync_display_and_show(0);
        bg_sync_display_and_show(1);
        bg_sync_display_and_show(2);
        bg_sync_display_and_show(3);
        
        bg_display_sync();
        
        set_io(0x50, 0x3F42);
        set_io(0x52, 0xA0F);        
    }
}

void pokedex_habitat_big_callback_cursor_movement(u8 self){
    oam_object *obj = &oams[fmem->dex_mem->oam_habitat_cursor];
    switch(big_callbacks[self].params[0]){
        case 0: //down
            obj->y2 = (s16)(obj->y2+2);
            break;
        case 1:
            obj->y2 = (s16)(obj->y2-2);
            break;
        case 2:
            obj->x2 = (s16)(obj->x2-2);
            break;
        case 3:
            obj->x2 = (s16)(obj->x2+2);
            break;
    }
    if(!--big_callbacks[self].params[1]){
        pokedex_habitats_update();
        fmem->dex_mem->habitat_cursor_is_moving = false;
        remove_big_callback(self);
    }
    
}

void pokedex_habitat_callback_idle(){
    cb1handling();
    if(!is_fading() && !fmem->dex_mem->habitat_cursor_is_moving){
        if(fmem->dex_mem->habitat_fading_countdown){
            fmem->dex_mem->habitat_fading_countdown--;
        }else{
            //process the habitat fading
            if(fmem->dex_mem->habitat_fading_mode){
                if(!--fmem->dex_mem->habitat_fading_index)
                    fmem->dex_mem->habitat_fading_mode = 0;
            }else{
                if(++fmem->dex_mem->habitat_fading_index == 8)
                    fmem->dex_mem->habitat_fading_mode = 1;
            }
            int i;
            for (i = 0; i < 32; i++){
                color over = {0x001F};
                pals[32+i] = alpha_blend(pal_restore[32+i], over, fmem->dex_mem->habitat_fading_index);
            }
            fmem->dex_mem->habitat_fading_countdown = 2;
        }
        
        u8 cb_id;
        if(super->keys.keys.down && fmem->dex_mem->habitat_cursor_y < 14){
            cb_id = spawn_big_callback(pokedex_habitat_big_callback_cursor_movement, 0);
            big_callbacks[cb_id].params[1] = 4;
            big_callbacks[cb_id].params[0] = 0;
            fmem->dex_mem->habitat_cursor_is_moving = true;
            fmem->dex_mem->habitat_cursor_y++;
        }else if(super->keys.keys.up && fmem->dex_mem->habitat_cursor_y){
            cb_id = spawn_big_callback(pokedex_habitat_big_callback_cursor_movement, 0);
            big_callbacks[cb_id].params[1] = 4;
            big_callbacks[cb_id].params[0] = 1;
            fmem->dex_mem->habitat_cursor_is_moving = true;
            fmem->dex_mem->habitat_cursor_y--;
        }else if(super->keys.keys.left && fmem->dex_mem->habitat_cursor_x){
            cb_id = spawn_big_callback(pokedex_habitat_big_callback_cursor_movement, 0);
            big_callbacks[cb_id].params[1] = 4;
            big_callbacks[cb_id].params[0] = 2;
            fmem->dex_mem->habitat_cursor_is_moving = true;
            fmem->dex_mem->habitat_cursor_x--;
        }else if(super->keys.keys.right && fmem->dex_mem->habitat_cursor_x < 21){
            cb_id = spawn_big_callback(pokedex_habitat_big_callback_cursor_movement, 0);
            big_callbacks[cb_id].params[1] = 4;
            big_callbacks[cb_id].params[0] = 3;
            fmem->dex_mem->habitat_cursor_is_moving = true;
            fmem->dex_mem->habitat_cursor_x++;
        }else if(super->keys.keys.B){
            init_fadescreen(1, 0);
            free(fmem->dex_mem->habitats);
            fmem->dex_mem->entry_skip_cry = true;
            set_callback1(pokedex_callback_init_entry);
        }
    }
}

void pokedex_habitats_load_for_species(u16 *unpacked_map){
    pokedex_habitat_pair *habitats = malloc(0x1000);
     fmem->dex_mem->habitats = habitats;
     int habitat_size = pokedex_get_namespaces_of_species(habitats, fmem->dex_mem->current_species);
     fmem->dex_mem->habitat_size = habitat_size;
     fmem->dex_mem->habitat_found = false;
     u8 current_namespace = get_mapheader((*save1)->bank, (*save1)->map)->name_bank;
     
     //test(habitats, habitat_size);
     
     u8 i, j, k, l;
     for(i = 0; i < 18; i++){
         for(j = 0; j < 22; j++){
             for (k = 0; k < 1; k++){
                 u8 namespace = worldmap_get_position_namespace(fmem->dex_mem->current_worldmap, (u8)k, (u16)i, (u16)j);
                 if(namespace != 0xC5){
                     //Lets check if the namespace is present in our list
                     if(namespace == current_namespace){
                         fmem->dex_mem->habitat_cursor_x = j;
                         fmem->dex_mem->habitat_cursor_y = i;
                     }
                     for(l = 0; l < habitat_size; l++){
                         if(habitats[l].namespace == namespace){
                             //now we need to change the palette of the corresponding tile
                             unpacked_map[(i+4)*30+j+4] |= 0x2000;
                             fmem->dex_mem->habitat_found = true;
                             break;
                         }
                     }
                 }
             }
         }
     }
}

void pokedex_habitats_load_namespace(){
    u8 str_blank [] = {0, 0, 0xFF};
    u8 namespace = worldmap_get_position_namespace(fmem->dex_mem->current_worldmap, 0, fmem->dex_mem->habitat_cursor_y, fmem->dex_mem->habitat_cursor_x);
    if(namespace != 0xC5){
        str_append(str_append(strcpy(strbuf, str_blank), map_namespaces[namespace-0x58]), str_blank);     
    }else{
        *strbuf = 0xFF;
    }
    tbox_flush(5, 0);
    tbox_tilemap_draw(5);
    tbox_print_string(5, 2, 0, 1, 0, 0, pokedex_fontcolmap_namespace, 0, strbuf);
    
    //print the not found string
    if(!fmem->dex_mem->habitat_found){
        str_append(str_append(strcpy(strbuf, str_blank), str_pokepad_pokedex_habitat_none_ref), str_blank);
        tbox_flush(6, 0);
        tbox_tilemap_draw(6);
        tbox_print_string(6, 2, 0, 0, 0, 0, pokedex_fontcolmap_namespace, 0, strbuf);
    }
}

void pokedex_habitats_update(){
    pokedex_habitats_load_namespace();
    //update the rarity oams
    u8 i;
    u8 namespace = worldmap_get_position_namespace(fmem->dex_mem->current_worldmap, 0, fmem->dex_mem->habitat_cursor_y, fmem->dex_mem->habitat_cursor_x);
    pokedex_habitat_pair *habitats = fmem->dex_mem->habitats;
    for (i = 0; i < 4; i++){
        if (i == HABITAT_TYPE_ROD){
            //special case : rod
            int j;
            for(j = 0; j < 3; j++){
                oams[fmem->dex_mem->habitat_oams_rod[j]].anim_number = 3; //all rod oams show nothing
                
            }
            for(j = 0; j < fmem->dex_mem->habitat_size; j++){
                if(habitats[j].namespace == namespace && habitats[j].type == HABITAT_TYPE_ROD){
                    u8 rod_type = habitats[j].propabilty;
                    oams[fmem->dex_mem->habitat_oams_rod[rod_type]].anim_number = rod_type;
                }
            }
            for(j = 0; j < 3; j++){
                gfx_init_animation(&oams[fmem->dex_mem->habitat_oams_rod[j]], 0); //all rod oams take their animation
            }
            
        }else{
            //we check the rarity level of the pokemon on this namespace
            u8 propability = 3;
            int j;
            for(j = 0; j < fmem->dex_mem->habitat_size; j++){
                if(habitats[j].namespace == namespace && habitats[j].type == i){
                   // test(habitats, &habitats[j]);
                    propability = habitats[j].propabilty;
                    break;
                }
            }
            oams[fmem->dex_mem->habitat_oams_rarity[i]].anim_number = propability;
            gfx_init_animation(&oams[fmem->dex_mem->habitat_oams_rarity[i]], 0);
        }
    }
}

