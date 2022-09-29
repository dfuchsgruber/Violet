#include "types.h"
#include "pokepad/pokedex/gui.h"
#include "pokepad/pokedex/operator.h"
#include "pokepad/pokedex/scanner.h"
#include "map/header.h"
#include "map/wild_pokemon.h"
#include "save.h"
#include "bg.h"
#include "text.h"
#include "pokemon/sprites.h"
#include "pokemon/names.h"
#include "pokemon/basestat.h"
#include "oam.h"
#include "superstate.h"
#include "math.h"
#include "debug.h"
#include "fading.h"
#include "language.h"
#include "agbmemory.h"
#include "io.h"
#include "bios.h"
#include "music.h"
#include "dma.h"
#include "callbacks.h"


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
                dst[j][1] = (u16)(dst[j][1] + pdf[i]);
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

void pokedex_feature_scanner_entries_add_roamers(pokedex_scanner_state *state) {
    for (int i = 0; i < NUM_ROAMERS; i++) {
        if (cmem.roamers[i].is_present && cmem.roamer_locations[i].bank == save1->bank && cmem.roamer_locations[i].map_idx == save1->map) {
            // 50% probability that the roamer appears, so all percentages must be multiplied by 1/2
            // If multiple roamers were present at this map, only the first roamer appears, so we only list one
            int total_percentage_values = 0;
            for (int j = 0; j < state->num_entries_grass; j++) {
                state->entries_grass[j][1] = (u16)(MAX(1, state->entries_grass[j][1] / 2));
                total_percentage_values += state->entries_grass[j][1];
            }
            state->entries_grass[state->num_entries_grass][0] = roamer_species[i];
            state->entries_grass[state->num_entries_grass][1] = (u16)(100 - total_percentage_values); // Make probabilities sum up to 100 in case of rounding issues
            state->num_entries_grass++;
        }
    }
}

int pokedex_feature_scanner_build_entries(pokedex_scanner_state *state){
    wild_pokemon_data *wild_pokemon_header = map_wild_pokemon_get_current();
    if(!wild_pokemon_header) return -1;
   
    // Build grass entries
    state->num_entries_grass = 0;
    if(wild_pokemon_header->grass){
        state->num_entries_grass = _pokedex_feature_scanner_build_entries(
                wild_pokemon_header->grass->data, state->entries_grass,
                12, wild_pokemon_grass_pdf);
        _pokedex_feature_scanner_sort_entries(state->entries_grass, 
                state->num_entries_grass);
    }
    pokedex_feature_scanner_entries_add_roamers(state);
    
    // Build the water entries
    state->num_entries_water = 0;
    if(wild_pokemon_header->water){
        state->num_entries_water = _pokedex_feature_scanner_build_entries(
                wild_pokemon_header->water->data, state->entries_water,
                5, wild_pokemon_water_pdf);
        _pokedex_feature_scanner_sort_entries(state->entries_water, 
                state->num_entries_water);
    }
    
    // Build the other entries
    state->num_entries_other = 0;
    if(wild_pokemon_header->other){
        state->num_entries_other = _pokedex_feature_scanner_build_entries(
                wild_pokemon_header->other->data, state->entries_other,
                5, wild_pokemon_other_pdf);
        _pokedex_feature_scanner_sort_entries(state->entries_other, 
                state->num_entries_other);
    }
    
    // Build rod entries
    state->num_entries_rod = 0;
    if(wild_pokemon_header->rod){
        state->num_entries_rod = _pokedex_feature_scanner_build_entries(
                wild_pokemon_header->rod->data, state->entries_rod, 2,
                wild_pokemon_rod_pdf);
        _pokedex_feature_scanner_sort_entries(state->entries_rod, 
                state->num_entries_rod);
    }
    
    // Build good rod entries
    state->num_entries_good_rod = 0;
    if(wild_pokemon_header->rod){
        state->num_entries_good_rod = _pokedex_feature_scanner_build_entries(
                &wild_pokemon_header->rod->data[2],
                state->entries_good_rod, 3, wild_pokemon_good_rod_pdf);
        _pokedex_feature_scanner_sort_entries(state->entries_good_rod, 
                state->num_entries_good_rod);
    }
    
    // Build super rod entries
    state->num_entries_super_rod = 0;
    if(wild_pokemon_header->rod){
        state->num_entries_super_rod = _pokedex_feature_scanner_build_entries(
                &wild_pokemon_header->rod->data[5],
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

color_t pokedex_feature_scanner_text_colors[16] = {
    {0}, {.rgb = {7, 9, 10}}, {.rgb = {31, 31, 31}}, {0}, {0}, {0}, {0}, {0},
    {0}, {.rgb = {20, 24, 30}}, {0}, {0}, {0}, {0}, {0}, {0}
};

void _pokedex_callback_init_feature_scanner(pokedex_scanner_state *state){
    // Disable window feature
    io_set(0, (u16) (io_get(0) &~0x6000));
    oam_reset();
    bg_reset(0);
    fading_cntrl_reset();
    oam_palette_allocation_reset();
    tbox_free_all();
    vblank_handler_set(NULL);
    dma0_reset_callback();
    big_callback_delete_all();
    bg_reset(0);
    
    // Bg setup
    bg_setup(0, pokedex_feature_scanner_bg_cnfgs, 2);
    void *bg0map = malloc_and_clear(0x800);
    void *bg1map = malloc_and_clear(0x800);
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
        u16 tile = oam_vram_alloc(16);
        oam_vram_allocation_table_add(tag, tile, 16);
        oam_template icon_template = {
            tag, 0xFFFF, &pokedex_feature_scanner_icon_sprite, 
            oam_gfx_anim_table_null, NULL, oam_rotscale_anim_table_null, oam_null_callback
        };
        state->oams[i] = oam_new_forward_search(&icon_template,
                (s16)(12 + 118 * box_id), (s16)(48 + 16 * line), (u8)i
                );
        oams[state->oams[i]].final_oam.attr0 |= ATTR0_OBJDISABLE;
    }
    
    // Load the palettes for the poke icons
    for(int i = 0; i < 3; i++){
        state->icon_pals[i] = oam_allocate_palette(
                (u16)(POKEDEX_SCANNER_ICON_BASE_TAG + i));
        pal_copy(icon_pals[i], (u16)(256 + 16 * state->icon_pals[i]), 32);
    }
    u16 pal_black[16] = {0};
    state->icon_pals[3] = oam_allocate_palette(POKEDEX_SCANNER_ICON_BASE_TAG + 3);
    pal_copy(pal_black, (u16)(256 + 16 * state->icon_pals[3]), 32);
    
    // Palette setup
    pal_decompress(gfx_pokedex_scanner_uiPal, 0, 32);
    pal_copy(pokedex_feature_scanner_text_colors, 16 * 15, 32);
    // Set the four mock pals for the selection to their inteded values
    u16 _selection_original_color[4] = {0x5A4B, 0x5A4B, 0x5A4B, 0x5A4B};
    pal_copy(_selection_original_color, 12, 8);
    pal_set_all_to_black();
    
}

tbox_font_colormap pokedex_feature_scanner_fontcolmap = {0, 2, 1, 0};
u8 str_pokedex_feature_scanner_percent[] = PSTRING("%");
u8 str_pokedex_feature_scanner_unseen[] = PSTRING("??????????");


void pokedex_feature_scanner_draw_generic_icons(pokedex_scanner_state *state,
        u16 entries[][2], int size){
    // Load for each entry the respective icon and draw it
    for(int i = 0; i < size; i++){
        u16 species = entries[i][0];
        u16 tile = oam_vram_get_tile((u16)(POKEDEX_SCANNER_ICON_BASE_TAG + i));
        void *dst = (void*)(0x06010000 + 0x20 * tile);
        cpuset(pokemon_icons[species], dst, 
                CPUSET_COPY | CPUSET_HALFWORD | 0x100);
        oams[state->oams[i]].final_oam.attr0 &= (u16)(~ATTR0_OBJDISABLE);
        
        int icon_pal = pokemon_icon_usage[species];
        if(!pokedex_operator(species, POKEDEX_GET | POKEDEX_CAUGHT, 1))
            icon_pal = 3;
        oams[state->oams[i]].final_oam.attr2 &= (u16)(~(0b1111 << 12));
        oams[state->oams[i]].final_oam.attr2 |= (u16)(icon_pal << 12);
    }
}


u8 str_pokedex_feature_scanner_none[] = LANGDEP(PSTRING("Keine Pokémon auffindbar"),
    PSTRING("No Pokémon to find"));


void pokedex_feature_scanner_print_empty_list(){
    // Print a centered "not availible string"
    int pixel_len = string_get_width(2, str_pokedex_feature_scanner_none, 0);
    int x = ((30 * 8) - pixel_len) / 2;
    tbox_flush_set(2, 0);
    tbox_tilemap_draw(2);
    tbox_print_string(2, 2, (u16)x, 0, 0, 0,
            &pokedex_feature_scanner_fontcolmap, 0,
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
                &pokedex_feature_scanner_fontcolmap, 0,
                seen ? pokemon_names[species] : str_pokedex_feature_scanner_unseen);
        
        // Print the probabilty
        itoa(strbuf, prob, 0, 3);
        strcat(strbuf, str_pokedex_feature_scanner_percent);
        tbox_print_string(box_id, 2, 70, (u16)(16 * line), 0, 0,
                &pokedex_feature_scanner_fontcolmap, 0, strbuf);
        
        DEBUG("Printing species %d with p %d\n", species, prob);
    }
    bg_virtual_sync(0);
}

void pokedex_callback_feature_scanner_selection_fade(pokedex_scanner_state *state){
    FIXED period = INT_TO_FIXED(64);
    FIXED fx = INT_TO_FIXED(state->fading_timer++);
    FIXED fy = FIXED_TRIANGLE_COS(FIXED_DIV(fx, period));
    fy = FIXED_MUL(INT_TO_FIXED(-4), fy);
    fy = FIXED_ADD(INT_TO_FIXED(4), fy);
    u8 alpha = (u8)FIXED_TO_INT(fy);
    for(int i = 0; i < 4; i++){
        color_t blended = pal_restore[12 + i];
        color_t white = {.rgb = {31, 31, 31}};
        if(i == state->selected_area){
            blended = color_alpha_blend(pal_restore[12 + i], white, alpha);
        }
        pals[12 + i] = blended;
    }
}

void pokedex_callback_feature_scanner_clear(){
    
    pokedex_scanner_state *state = fmem.dex_mem->scanner_state;
    
    // Clear the oams
    for(int i = 0; i < 13; i++){
        oams[state->oams[i]].final_oam.attr0 |= ATTR0_OBJDISABLE;
    }
    
    // Clear the strings
    bg_hide(0);
    bg_display_sync();
    tbox_flush_set(0, 0);
    tbox_flush_set(1, 0);
    tbox_flush_set(2, 0);
    tbox_tilemap_draw(0);
    tbox_tilemap_draw(1);
    tbox_sync(0, TBOX_SYNC_MAP_AND_SET);
    tbox_sync(1, TBOX_SYNC_MAP_AND_SET);
    tbox_sync(2, TBOX_SYNC_SET);
    
    callback1_set(pokedex_callback_feature_scanner_load);
}


tbox_font_colormap pokedex_feature_scanner_title_fontcolmap = {0, 9, 1, 0};

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
                    &pokedex_feature_scanner_title_fontcolmap, 0, title);
        }else{
            // Print a pokemon
            u16 species = entries[i - pos - 1][0];
            u16 prob = entries[i - pos - 1][1];

            int seen = pokedex_operator(species, POKEDEX_GET | POKEDEX_SEEN, 1);

            // Print the name
            tbox_print_string(box_id, 2, 0, (u16)(16 * line), 0, 0, 
                    &pokedex_feature_scanner_fontcolmap, 0,
                    seen ? pokemon_names[species] : str_pokedex_feature_scanner_unseen);

            // Print the probabilty
            itoa(strbuf, prob, 0, 3);
            strcat(strbuf, str_pokedex_feature_scanner_percent);
            tbox_print_string(box_id, 2, 70, (u16)(16 * line), 0, 0,
                    &pokedex_feature_scanner_fontcolmap, 0, strbuf);
        }
    }
}

void pokedex_feature_scanner_draw_generic_icons_at(pokedex_scanner_state *state,
        int pos, u16 entries[][2], int size){
    for(int i = pos; i < pos + size; i++){
        
        u16 species = entries[i - pos][0];
        u16 tile = oam_vram_get_tile((u16)(POKEDEX_SCANNER_ICON_BASE_TAG + i));
        void *dst = (void*)(0x06010000 + 0x20 * tile);
        cpuset(pokemon_icons[species], dst, 
                CPUSET_COPY | CPUSET_HALFWORD | 0x100);
        oams[state->oams[i]].final_oam.attr0 &= (u16)(~ATTR0_OBJDISABLE);
        
        int icon_pal = pokemon_icon_usage[species];
        if(!pokedex_operator(species, POKEDEX_GET | POKEDEX_CAUGHT, 1))
            icon_pal = 3;
        oams[state->oams[i]].final_oam.attr2 &= (u16)(~(0b1111 << 12));
        oams[state->oams[i]].final_oam.attr2 |= (u16)(icon_pal << 12);
    }
}
u8 str_pokedex_feature_scanner_rod[] = LANGDEP(PSTRING("Angel"), PSTRING("Rod"));
u8 str_pokedex_feature_scanner_good_rod[] = LANGDEP(PSTRING("Profiangel"), PSTRING("Good Rod"));
u8 str_pokedex_feature_scanner_super_rod[] = LANGDEP(PSTRING("Superangel"), PSTRING("Super Rod"));

void pokedex_callback_feature_scanner_load(){
    
    pokedex_scanner_state *state = fmem.dex_mem->scanner_state;
    
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
    callback1_set(pokedex_callback_feature_scanner_idle);
}

void pokedex_callback_feature_scanner_return(){
    generic_callback1();
    if (!fading_is_active()) {
        // Free maps and tboxes
        free(bg_get_tilemap(0));
        free(bg_get_tilemap(1));
        tbox_free_all();
        
        free(fmem.dex_mem->scanner_state);
        
        pokedex_init_components();
        pokedex_update_list();
        io_set(0x50, 0);
        io_set(0x52, 0);
        io_set(0x54, 0);
        io_bic(0, 0x6000);
    }
}

void pokedex_callback_feature_scanner_idle(){
    generic_callback1();
    if(!fading_is_active()){
        pokedex_scanner_state *state = fmem.dex_mem->scanner_state;
        pokedex_callback_feature_scanner_selection_fade(state);
        if(super.keys_new.keys.right){
            state->selected_area++;
            state->selected_area %= 4;
            callback1_set(pokedex_callback_feature_scanner_clear);
            play_sound(5);
        }else if(super.keys_new.keys.left){
            state->selected_area = (u8)(state->selected_area + 3);
            state->selected_area %= 4;
            callback1_set(pokedex_callback_feature_scanner_clear);
            play_sound(5);
        }else if(super.keys_new.keys.B){
            play_sound(5);
            callback1_set(pokedex_callback_feature_scanner_return);
            fadescreen_all(1, 0);
        }
        
    }
}

void pokedex_callback_init_feature_scanner() {
    generic_callback1();
    if (!fading_is_active()) {
        pokedex_scanner_state *state = malloc_and_clear(sizeof(pokedex_scanner_state));
        fmem.dex_mem->scanner_state = state;
        pokedex_free_maps();
        pokedex_feature_scanner_build_entries(state);
        _pokedex_callback_init_feature_scanner(state);
        pokedex_feature_scanner_print_generic_list(state->entries_grass, state->num_entries_grass);
        pokedex_feature_scanner_draw_generic_icons(state, state->entries_grass, state->num_entries_grass);
        callback1_set(pokedex_callback_feature_scanner_clear);
        vblank_handler_set(generic_vblank_handler);
        fadescreen_all(0, 0);
    }
}
