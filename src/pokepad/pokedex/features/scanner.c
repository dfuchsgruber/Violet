#include "types.h"
#include "romfuncs.h"
#include "pokedex.h"
#include "map.h"
#include "save.h"
#include "bg.h"
#include "utils.h"
#include "text.h"
#include "basestats.h"
#include "oams.h"
#include "superstate.h"
/*
 * Probability density functions for each type of encounter
 * in percent. (Encounters are actually hardwired with these values)
 */

u8 wild_pokemon_grass_pdf[12] = { 20, 20, 10, 10, 10, 10, 5, 5, 4, 4, 1, 1 };

u8 wild_pokemon_water_pdf[5] = { 60, 30, 5, 4, 1 };

u8 wild_pokemon_rod_pdf[2] = { 70, 30 };

u8 wild_pokemon_good_rod_pdf[3] = { 60, 20, 20 };

u8 wild_pokemon_super_rod_pdf[5] = { 40, 40, 15, 4, 1 }; 

u8 wild_pokemon_other_pdf[5] = { 60, 30, 5, 4, 1 };


void _pokedex_feature_scanner_sort_entries_swap(u16 entries[][2], int i, int j){
    u16 tmp[2];
    tmp[0] = entries[i][0]; tmp[1] = entries[i][1];
    entries[i][0] = entries[j][0]; entries[i][1] = entries[j][1];
    entries[j][0] = tmp[0]; entries[j][1] = tmp[1];
}

void _pokedex_feature_scanner_sort_entries(u16 entries[][2], int size){
    for(int n = size; n > 1; n--){
        for(int i = 0; i < n - 1; i++){
            if(entries[i][1] < entries[i + 1][1])
                _pokedex_feature_scanner_sort_entries_swap(entries, i, i + 1);
        }
    }
}

int _pokedex_feature_scanner_build_entries(wild_pokemon_entry *wild_entries,
        u16 dst[][2], int capacity, u8 pdf[]){
    int num_entries = 0;
    for(int i = 0; i < capacity; i++){
        u16 key = wild_entries[i].species;
        // Check if this key is already in dst
        int in_dst = 0;
        for(int j = 0; j < num_entries; j++){
            if(dst[j][0] == key){
                dst[j][1] += pdf[i];
                in_dst = 1;
                break;
            }
        }
        if(!in_dst){
            dst[num_entries][0] = key;
            dst[num_entries][1] = pdf[i];
            num_entries++;
        }
    }
    
    return num_entries;
}

int pokedex_feature_scanner_build_entries(pokedex_scanner_state *state){
    u16 wild_table_id = map_wild_pokemon_get_current_table_id();
    if(wild_table_id == 0xFFFF) return -1;
   
    // Build grass entries
    state->num_entries_grass = 0;
    if(wild_pokemon[wild_table_id].grass){
        state->num_entries_grass = _pokedex_feature_scanner_build_entries(
                wild_pokemon[wild_table_id].grass->data, state->entries_grass, 
                12, wild_pokemon_grass_pdf);
        _pokedex_feature_scanner_sort_entries(state->entries_grass, 
                state->num_entries_grass);
    }
    
    // Build the water entries
    state->num_entries_water = 0;
    if(wild_pokemon[wild_table_id].water){
        state->num_entries_water = _pokedex_feature_scanner_build_entries(
                wild_pokemon[wild_table_id].water->data, state->entries_water,
                5, wild_pokemon_water_pdf);
        _pokedex_feature_scanner_sort_entries(state->entries_water, 
                state->num_entries_water);
    }
    
    // Build the other entries
    state->num_entries_other = 0;
    if(wild_pokemon[wild_table_id].other){
        state->num_entries_other = _pokedex_feature_scanner_build_entries(
                wild_pokemon[wild_table_id].other->data, state->entries_other,
                5, wild_pokemon_other_pdf);
        _pokedex_feature_scanner_sort_entries(state->entries_other, 
                state->num_entries_other);
    }
    
    // Build rod entries
    state->num_entries_rod = 0;
    if(wild_pokemon[wild_table_id].rod){
        state->num_entries_rod = _pokedex_feature_scanner_build_entries(
                wild_pokemon[wild_table_id].rod->data, state->entries_rod, 2, 
                wild_pokemon_rod_pdf);
        _pokedex_feature_scanner_sort_entries(state->entries_rod, 
                state->num_entries_rod);
    }
    
    // Build good rod entries
    state->num_entries_good_rod = 0;
    if(wild_pokemon[wild_table_id].rod){
        state->num_entries_good_rod = _pokedex_feature_scanner_build_entries(
                &wild_pokemon[wild_table_id].rod->data[2], 
                state->entries_good_rod, 3, wild_pokemon_good_rod_pdf);
        _pokedex_feature_scanner_sort_entries(state->entries_good_rod, 
                state->num_entries_good_rod);
    }
    
    // Build super rod entries
    state->num_entries_super_rod = 0;
    if(wild_pokemon[wild_table_id].rod){
        state->num_entries_super_rod = _pokedex_feature_scanner_build_entries(
                &wild_pokemon[wild_table_id].rod->data[5], 
                state->entries_super_rod, 5, wild_pokemon_super_rod_pdf);
        _pokedex_feature_scanner_sort_entries(state->entries_super_rod, 
                state->num_entries_super_rod);
    }
    return 0;
}
    
    
/* Bg configs for the feature UI */
bg_config pokedex_feature_scanner_bg_cnfgs[] = {
    {0, 2, 31, 0, 0, 0},
    {1, 0, 30, 0, 0, 1}
};

/*
 * Textbox data
 */

tboxdata pokedex_feature_scanner_tboxes[] = {
    {0, 3, 6, 12, 12, 15, 1},
    {0, 18, 6, 12, 14, 15, 12 * 12 + 1},
    {0, 0, 10, 30, 2, 15, 12 * 12 + 1 + 12 * 14},
    {0xFF, 0, 0, 0, 0, 0, 0}
};

extern u8 gfx_pokedex_scanner_uiTiles[];
extern u8 gfx_pokedex_scanner_uiMap[];
extern u8 gfx_pokedex_scanner_uiPal[];


sprite pokedex_feature_scanner_icon_sprite = {
    ATTR0_SHAPE_SQUARE, ATTR1_SIZE_32_32, 0, 0
};

color pokedex_feature_scanner_text_colors[16] = {
    {0}, {.rgb = {7, 9, 10}}, {.rgb = {31, 31, 31}}, {0}, {0}, {0}, {0}, {0},
    {0}, {.rgb = {20, 24, 30}}, {0}, {0}, {0}, {0}, {0}, {0}
};

void _pokedex_callback_init_feature_scanner(pokedex_scanner_state *state){
    // Disable window feature
    set_io(0, (u16) (get_io(0) &~0x6000));
    oam_reset();
    bg_reset(0);
    pal_fade_cntrl_reset();
    pal_allocation_reset();
    free_all_tboxes();
    set_callback3(NULL);
    dma0_cb_reset();
    remove_all_big_callbacks();
    bg_reset(0);
    
    // Bg setup
    bg_setup(0, pokedex_feature_scanner_bg_cnfgs, 2);
    void *bg0map = cmalloc(0x800);
    void *bg1map = cmalloc(0x800);
    bg_set_tilemap(0, bg0map);
    bg_set_tilemap(1, bg1map);
    lz77uncompwram(gfx_pokedex_scanner_uiMap, bg1map);
    lz77uncompvram(gfx_pokedex_scanner_uiTiles, (void*)(0x06000000));
    bg_virtual_sync(1);
    bg_sync_display_and_show(0);
    bg_sync_display_and_show(1);
    bg_display_sync();
    
    // Textbox setup
    tbox_sync_with_virtual_bg_and_init_all(pokedex_feature_scanner_tboxes);
    
    // Oam setup
    // Spawn 13 oams that could possibly represent a pokemon
    for(int i = 0; i < 13; i++){
        int box_id = i < 6 ? 0 : 1;
        int line = i < 6 ? i : i - 6;
        
        u16 tag = (u16)(POKEDEX_SCANNER_ICON_BASE_TAG + i);
        u16 tile = obj_vram_allocate(16);
        obj_vram_add_tile_tag_to_allocation_table(tag, tile, 16);
        oam_template icon_template = {
            tag, 0xFFFF, &pokedex_feature_scanner_icon_sprite, 
            GFX_ANIM_TABLE_NULL, NULL, ROTSCALE_TABLE_NULL, oam_null_callback
        };
        state->oams[i] = generate_oam_forward_search(&icon_template,
                (s16)(12 + 118 * box_id), (s16)(48 + 16 * line), (u8)i
                );
        oams[state->oams[i]].final_oam.attr0 |= ATTR0_OBJDISABLE;
    }
    
    // Load the palettes for the poke icons
    for(int i = 0; i < 3; i++){
        state->icon_pals[i] = allocate_obj_pal(
                (u16)(POKEDEX_SCANNER_ICON_BASE_TAG + i));
        pal_load_uncomp(icon_pals[i], 256 + 16 * state->icon_pals[i], 32);
    }
    u16 pal_black[16] = {0};
    state->icon_pals[3] = allocate_obj_pal(POKEDEX_SCANNER_ICON_BASE_TAG + 3);
    pal_load_uncomp(pal_black, 256 + 16 * state->icon_pals[3], 32);
    
    // Palette setup
    pal_load_comp(gfx_pokedex_scanner_uiPal, 0, 32);
    pal_load_uncomp(pokedex_feature_scanner_text_colors, 16 * 15, 32);
    // Set the four mock pals for the selection to their inteded values
    u16 _selection_original_color[4] = {0x5A4B, 0x5A4B, 0x5A4B, 0x5A4B};
    pal_load_uncomp(_selection_original_color, 12, 8);
    pal_set_all_to_black();
    
}


u8 pokedex_feature_scanner_fontcolmap[4] = {0, 2, 1, 0};
extern u8 str_pokedex_feature_scanner_percent[];
extern u8 str_pokedex_feature_scanner_unseen[];


void pokedex_feature_scanner_draw_generic_icons(pokedex_scanner_state *state,
        u16 entries[][2], int size){
    // Load for each entry the respective icon and draw it
    for(int i = 0; i < size; i++){
        u16 species = entries[i][0];
        u16 tile = get_obj_tile_by_tag((u16)(POKEDEX_SCANNER_ICON_BASE_TAG + i));
        void *dst = (void*)(0x06010000 + 0x20 * tile);
        cpuset(pokemon_icons[species], dst, 
                CPUSET_COPY | CPUSET_HALFWORD | 0x100);
        oams[state->oams[i]].final_oam.attr0 &= (u16)(~ATTR0_OBJDISABLE);
        
        int icon_pal = pokemon_icon_usage[species];
        if(!pokedex_operator(species, POKEDEX_GET | POKEDEX_CAUGHT, 1))
            icon_pal = 3;
        oams[state->oams[i]].final_oam.attr2 &= ~(0b1111 << 12);
        oams[state->oams[i]].final_oam.attr2 |= icon_pal << 12;
    }
}


extern u8 str_pokedex_feature_scanner_none[];


void pokedex_feature_scanner_print_empty_list(){
    // Print a centered "not availible string"
    int pixel_len = string_get_width(2, str_pokedex_feature_scanner_none, 0);
    int x = ((30 * 8) - pixel_len) / 2;
    tbox_flush(2, 0);
    tbox_tilemap_draw(2);
    tbox_print_string(2, 2, (u16)x, 0, 0, 0,
            pokedex_feature_scanner_fontcolmap, 0, 
            str_pokedex_feature_scanner_none);
    tbox_sync(2, TBOX_SYNC_MAP_AND_SET);
}

void pokedex_feature_scanner_print_generic_list(u16 entries[][2], int size){
    
    if(!size){
        pokedex_feature_scanner_print_empty_list();
        return;
    }
    
    // Draw each entry
    for(int i = 0; i < size; i++){
        // Get the box
        u8 box_id = (u8)(i / 6);
        int line = i % 6;
        
        u16 species = entries[i][0];
        u16 prob = entries[i][1];
        
        int seen = pokedex_operator(species, POKEDEX_GET | POKEDEX_SEEN, 1);
        
        // Print the name
        tbox_print_string(box_id, 2, 0, (u16)(16 * line), 0, 0, 
                pokedex_feature_scanner_fontcolmap, 0, 
                seen ? pokemon_names[species] : str_pokedex_feature_scanner_unseen);
        
        // Print the probabilty
        itoa(strbuf, prob, 0, 3);
        strcat(strbuf, str_pokedex_feature_scanner_percent);
        tbox_print_string(box_id, 2, 70, (u16)(16 * line), 0, 0,
                pokedex_feature_scanner_fontcolmap, 0, strbuf);
        
        
        dprintf("Printing species %d with p %d\n", species, prob);
    }
    bg_virtual_sync(0);
}

void pokedex_callback_feature_scanner_selection_fade(pokedex_scanner_state *state){
    int y = -linear_cos(state->fading_timer++, 64, 4);
    u8 alpha = (u8)(4 + y);
    for(int i = 0; i < 4; i++){
        color blended = pal_restore[12 + i];
        color white = {.rgb = {31, 31, 31}};
        if(i == state->selected_area){
            blended = alpha_blend(pal_restore[12 + i], white, alpha);
        }
        pals[12 + i] = blended;
    }
}

void pokedex_callback_feature_scanner_clear(){
    
    pokedex_scanner_state *state = fmem->dex_mem->scanner_state;
    
    // Clear the oams
    for(int i = 0; i < 13; i++){
        oams[state->oams[i]].final_oam.attr0 |= ATTR0_OBJDISABLE;
    }
    
    // Clear the strings
    bg_hide(0);
    bg_display_sync();
    tbox_flush(0, 0);
    tbox_flush(1, 0);
    tbox_flush(2, 0);
    tbox_tilemap_draw(0);
    tbox_tilemap_draw(1);
    tbox_sync(0, TBOX_SYNC_MAP_AND_SET);
    tbox_sync(1, TBOX_SYNC_MAP_AND_SET);
    tbox_sync(2, TBOX_SYNC_SET);
    
    set_callback1(pokedex_callback_feature_scanner_load);
}


u8 pokedex_feature_scanner_title_fontcolmap[4] = {0, 9, 1, 0};

void pokedex_feature_scanner_print_generic_titled_list_at(int pos, u8 *title,
        u16 entries[][2], int size){
    
    if(!size){
        pokedex_feature_scanner_print_empty_list();
        return;
    }
    
    for(int i = pos; i <= pos + size; i++){
        
        // Get the box
        u8 box_id = (u8)(i / 6);
        int line = i % 6;
       
        if(i == pos){
            // Print the title
            tbox_print_string(box_id, 2, 12, (u16)(16 * line), 0, 0, 
                    pokedex_feature_scanner_title_fontcolmap, 0, title);
        }else{
            // Print a pokemon
            u16 species = entries[i - pos - 1][0];
            u16 prob = entries[i - pos - 1][1];

            int seen = pokedex_operator(species, POKEDEX_GET | POKEDEX_SEEN, 1);

            // Print the name
            tbox_print_string(box_id, 2, 0, (u16)(16 * line), 0, 0, 
                    pokedex_feature_scanner_fontcolmap, 0, 
                    seen ? pokemon_names[species] : str_pokedex_feature_scanner_unseen);

            // Print the probabilty
            itoa(strbuf, prob, 0, 3);
            strcat(strbuf, str_pokedex_feature_scanner_percent);
            tbox_print_string(box_id, 2, 70, (u16)(16 * line), 0, 0,
                    pokedex_feature_scanner_fontcolmap, 0, strbuf);
        }
    }
}

void pokedex_feature_scanner_draw_generic_icons_at(pokedex_scanner_state *state,
        int pos, u16 entries[][2], int size){
    for(int i = pos; i < pos + size; i++){
        
        u16 species = entries[i - pos][0];
        u16 tile = get_obj_tile_by_tag((u16)(POKEDEX_SCANNER_ICON_BASE_TAG + i));
        void *dst = (void*)(0x06010000 + 0x20 * tile);
        cpuset(pokemon_icons[species], dst, 
                CPUSET_COPY | CPUSET_HALFWORD | 0x100);
        oams[state->oams[i]].final_oam.attr0 &= (u16)(~ATTR0_OBJDISABLE);
        
        int icon_pal = pokemon_icon_usage[species];
        if(!pokedex_operator(species, POKEDEX_GET | POKEDEX_CAUGHT, 1))
            icon_pal = 3;
        oams[state->oams[i]].final_oam.attr2 &= ~(0b1111 << 12);
        oams[state->oams[i]].final_oam.attr2 |= icon_pal << 12;
    }
}

extern u8 str_pokedex_feature_scanner_rod[];
extern u8 str_pokedex_feature_scanner_good_rod[];
extern u8 str_pokedex_feature_scanner_super_rod[];

void pokedex_callback_feature_scanner_load(){
    
    pokedex_scanner_state *state = fmem->dex_mem->scanner_state;
    
    // Print the selected entry list
    switch(state->selected_area){
        case 0:
            // Grass
            pokedex_feature_scanner_print_generic_list(state->entries_grass,
                    state->num_entries_grass);
            pokedex_feature_scanner_draw_generic_icons(state,
                    state->entries_grass, state->num_entries_grass);
            break;
        case 1:
            // Water
            pokedex_feature_scanner_print_generic_list(state->entries_water,
                    state->num_entries_water);
            pokedex_feature_scanner_draw_generic_icons(state,
                    state->entries_water, state->num_entries_water);
            break;
        case 3:
            // Radar
            pokedex_feature_scanner_print_generic_list(state->entries_other,
                    state->num_entries_other);
            pokedex_feature_scanner_draw_generic_icons(state,
                    state->entries_other, state->num_entries_other);
            break;
        case 2:
            // Rod
            // Print super rod
            pokedex_feature_scanner_print_generic_titled_list_at(0,
                    str_pokedex_feature_scanner_super_rod,
                    state->entries_super_rod, state->num_entries_super_rod);
            pokedex_feature_scanner_draw_generic_icons_at(state, 1, 
                    state->entries_super_rod, state->num_entries_super_rod);
            
            // First print odd rod
            pokedex_feature_scanner_print_generic_titled_list_at(6,
                    str_pokedex_feature_scanner_rod, state->entries_rod,
                    state->num_entries_rod);
            pokedex_feature_scanner_draw_generic_icons_at(state, 7, 
                    state->entries_rod, state->num_entries_rod);
                    
            // Print good rod
            pokedex_feature_scanner_print_generic_titled_list_at(9,
                    str_pokedex_feature_scanner_good_rod,
                    state->entries_good_rod, state->num_entries_good_rod);
            pokedex_feature_scanner_draw_generic_icons_at(state, 10, 
                    state->entries_good_rod, state->num_entries_good_rod);
            
            /* TODO */
            break;
        default: return;
    }
    bg_update_and_show(0);
    bg_display_sync();
    set_callback1(pokedex_callback_feature_scanner_idle);
}

void pokedex_callback_feature_scanner_return(){
    cb1handling();
    if (!is_fading()) {
        // Free maps and tboxes
        free(bg_get_tilemap(0));
        free(bg_get_tilemap(1));
        free_all_tboxes();
        
        free(fmem->dex_mem->scanner_state);
        
        pokedex_init_components();
        pokedex_update_list();
        set_io(0x50, 0);
        set_io(0x52, 0);
        set_io(0x54, 0);
        bic_io(0, 0x6000);
    }
}

void pokedex_callback_feature_scanner_idle(){
    cb1handling();
    if(!is_fading()){
        pokedex_scanner_state *state = fmem->dex_mem->scanner_state;
        pokedex_callback_feature_scanner_selection_fade(state);
        if(super->keys_new.keys.right){
            state->selected_area++;
            state->selected_area %= 4;
            set_callback1(pokedex_callback_feature_scanner_clear);
            sound(5);
        }else if(super->keys_new.keys.left){
            state->selected_area += 3;
            state->selected_area %= 4;
            set_callback1(pokedex_callback_feature_scanner_clear);
            sound(5);
        }else if(super->keys_new.keys.B){
            sound(5);
            set_callback1(pokedex_callback_feature_scanner_return);
            init_fadescreen(1, 0);
        }
        
    }
}

void pokedex_callback_init_feature_scanner() {
    cb1handling();
    if (!is_fading()) {
        pokedex_scanner_state *state = cmalloc(sizeof(pokedex_scanner_state));
        fmem->dex_mem->scanner_state = state;
        pokedex_free_maps();
        pokedex_feature_scanner_build_entries(state);
        _pokedex_callback_init_feature_scanner(state);
        pokedex_feature_scanner_print_generic_list(state->entries_grass, state->num_entries_grass);
        pokedex_feature_scanner_draw_generic_icons(state, state->entries_grass, state->num_entries_grass);
        set_callback1(pokedex_callback_feature_scanner_clear);
        init_fadescreen(0, 0);
    }
}