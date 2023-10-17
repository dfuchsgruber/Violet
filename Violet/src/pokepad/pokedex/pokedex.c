
#include "types.h"
#include "stdbool.h"
#include "pokepad/pokepad2.h"
#include "pokepad/pokedex/gui.h"
#include "pokepad/pokedex/operator.h"
#include "oam.h"
#include "callbacks.h"
#include "save.h"
#include "bg.h"
#include "text.h"
#include "mega.h"
#include "pokemon/basestat.h"
#include "color.h"
#include "superstate.h"
#include "transparency.h"
#include "fading.h"
#include "debug.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "language.h"
#include "io.h"
#include "flags.h"
#include "vars.h"
#include "music.h"
#include "bios.h"
#include "agbmemory.h"
#include "overworld/map_control.h"
#include "pokepad/pokedex/state.h"
#include "dma.h"

EWRAM pokedex_state_t *pokedex_state = NULL;

extern const unsigned short gfx_pokedex_sort_cursorTiles[];
extern const unsigned short gfx_pokedex_uiMap[];
extern const unsigned short gfx_pokedex_uiTiles[];
extern const unsigned short gfx_pokedex_bottom_1Map[];
extern const unsigned short gfx_pokedex_bottom_1Tiles[];
extern const unsigned short gfx_pokedex_bottom_0Map[];
extern const unsigned short gfx_pokedex_sort_cursorPal[];
extern const unsigned short gfx_pokedex_uiPal[];
extern const unsigned short gfx_pokedex_bottom_1Pal[];
extern const unsigned short gfx_pokedex_bottom_0Pal[];

static void pokedex_handle_inputs_group_selection(u8 self);
static void pokedex_group_window_set();

static const bg_config pokedex_bg_main_configs [] = {
    {0, 2, 31, 0, 0, 0},
    {1, 0, 30, 0, 0, 1},
    {2, 1, 29, 0, 0, 2},
    {3, 1, 28, 0, 0, 2}
};

static const tboxdata pokedex_tboxes [] = {
    {0, 11, 0, 3, 2, 15, 1}, //tbox seen
    {0, 11, 2, 3, 2, 15, 7}, //tbox caught
    {0, 14, 5, 8, 14, 15, 13}, //tbox list
    {0, 22, 5, 8, 14, 3, 125}, // type list
    {0, 12, 5, 2, 14, 4, 237}, // capture list
    {0, 7, 5, 5, 14, 14, 265}, // nr list
    {0, 1, 5, 6, 2, 3, 335}, // feature 0: scanner
    {0, 1, 10, 6, 2, 3, 347}, // feature 1: scanner
    {0, 1, 15, 6, 2, 3, 359}, // feature 1: scanner
    {0xFF, 0, 0, 0, 0, 0, 0}
};


const sprite pokedex_cursor_sprite = {
    0, 0x8000, 0, 0
};

const gfx_frame pokedex_cursor_gfx_anim_idle[] = {
    {0, 0},
    {0xFFFF, 0}
};

const gfx_frame pokedex_cursor_gfx_anim_active[] = {
    {0, 32},
    {16, 32},
    {0xFFFE, 0}
};

const gfx_frame *const pokedex_cursor_anims[] = {
    pokedex_cursor_gfx_anim_idle,
    pokedex_cursor_gfx_anim_active
};

const graphic pokedex_cursor_graphic = {
    &gfx_pokedex_sort_cursorTiles,
    0x400,
    POKEDEX_CURSOR_GFX_TAG
};

const oam_template pokedex_cursor_template = {
    POKEDEX_CURSOR_GFX_TAG,
    POKEDEX_CURSOR_GFX_TAG,
    &pokedex_cursor_sprite,
    pokedex_cursor_anims,
    NULL,
    oam_rotscale_anim_table_null,
    oam_null_callback
};

const tbox_font_colormap pokedex_fontcolmap = {0, 2, 1, 0};
const tbox_font_colormap pokedex_features_active_fontcolmap = {0, 15, 13, 1};
const tbox_font_colormap pokedex_features_fontcolmap = {0, 10, 13, 1};

const u16 pokedex_colors[16] = {0, 0x2927, 0x7FFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u16 pokedex_colors_nr[16] = {0, 0x7FFF, 0x2927, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static void pokedex_cb1() {
    big_callback_proceed();
    tbox_proceed();
    oam_animations_proceed();
    oam_proceed();
    bg_virtual_sync_reqeust_proceed();
    fading_proceed();
}

int pokedex_get_first_seen() {
    pokedex_list_element *list = pokedex_state->list;
    int i;
    for (i = 0; i < POKEDEX_CNT; i++) {
        if (pokedex_operator_by_dex_id(list[i].dex_id, 0))
            return i;
    }
    return 0;
}

int pokedex_get_last_seen() {
    pokedex_list_element *list = pokedex_state->list;
    int i;
    for (i = POKEDEX_CNT - 1; i >= 0; i--) {
        if (pokedex_operator_by_dex_id(list[i].dex_id, 0))
            return i;
    }
    return 0;
}

void pokedex_free_maps() {
    free(bg_get_tilemap(0));
    free(bg_get_tilemap(1));
    free(bg_get_tilemap(2));
    free(bg_get_tilemap(3));
}

void pokedex_callback_return() {
    pokedex_cb1();
    if (!fading_is_active()) {
        //end pokedex
        tbox_free_all();
        *var_access(POKEDEX_ACTIVE_COMPARATOR) = pokedex_state->current_comparator;
        *var_access(POKEDEX_LAST_SPECIES) = pokedex_state->current_species;
        pokedex_free_maps();
        free(pokedex_state->list);
        if (pokedex_state->from_outdoor) {
            callback1_set(map_reload);
        } else {
            callback1_set(pokepad2_callback_initialize);
        }
        free(pokedex_state);
    }
}

static void pokedex_print_feature_strings(){
    
    if(checkflag(POKEDEX_FEATURE_0)){
        u8 str_feature_0[] = LANGDEP(PSTRING("Scanner"), PSTRING("Scanner"));
        tbox_flush_set(POKEDEX_TBOX_FEATURE_0, 0);
        tbox_tilemap_draw(POKEDEX_TBOX_FEATURE_0);
        tbox_print_string(POKEDEX_TBOX_FEATURE_0, 2, 2, 4, 0, 0,
                pokedex_state->current_feature == 0 ? 
                    &pokedex_features_active_fontcolmap :
                    &pokedex_features_fontcolmap, 0, str_feature_0);
    }
    if(checkflag(POKEDEX_FEATURE_1)){
      u8 str_feature_1[] = LANGDEP(PSTRING("Scanner2"), PSTRING("Scanner2"));
        tbox_flush_set(POKEDEX_TBOX_FEATURE_1, 0);
        tbox_tilemap_draw(POKEDEX_TBOX_FEATURE_1);
        tbox_print_string(POKEDEX_TBOX_FEATURE_1, 2, 2, 2, 0, 0,
                pokedex_state->current_feature == 1 ? 
                    &pokedex_features_active_fontcolmap :
                    &pokedex_features_fontcolmap, 0, str_feature_1);
    }
    if(checkflag(POKEDEX_FEATURE_2)){
      u8 str_feature_2[] = LANGDEP(PSTRING("Scanner3"), PSTRING("Scanner3"));
        tbox_flush_set(POKEDEX_TBOX_FEATURE_2, 0);
        tbox_tilemap_draw(POKEDEX_TBOX_FEATURE_2);
        tbox_print_string(POKEDEX_TBOX_FEATURE_2, 2, 2, 2, 0, 0,
                pokedex_state->current_feature == 2 ? 
                    &pokedex_features_active_fontcolmap :
                    &pokedex_features_fontcolmap, 0, str_feature_2);
    }
}

static const u16 feature_flags[] = {
    POKEDEX_FEATURE_0,
    POKEDEX_FEATURE_1,
    POKEDEX_FEATURE_2
};

void pokedex_callback_feature_selection(){
    pokedex_cb1();
    if(super.keys_new.keys.down || super.keys_new.keys.up){
        // Select next availble feature
        u8 next_feature = pokedex_state->current_feature;
        do{
            if(super.keys_new.keys.down)
                next_feature++;
            else
                next_feature = (u8)(next_feature + 3 - 1);
            next_feature %= 3;
        }while(!checkflag(feature_flags[next_feature]));
        if(next_feature == pokedex_state->current_feature) return;
        pokedex_state->current_feature = next_feature;
        play_sound(5);
        pokedex_print_feature_strings();
    }else if(super.keys_new.keys.B){
        // Return to group selection
        pokedex_state->current_feature = 0xFF;
        pokedex_print_feature_strings();
        callback1_set(pokedex_callback_group_selection);
        play_sound(5);
    }else if(super.keys_new.keys.A){
        // Open the scanner UI
        play_sound(5);
        callback1_set(pokedex_callback_init_feature_scanner);
        fadescreen_all(1, 0);
        return;
    }
}

void pokedex_callback_group_selection() {
    pokedex_cb1();
    if (!fading_is_active()) {

        //Progress in input
        if (super.keys_new.keys.A) {
        
        } else if (super.keys_new.keys.B) {
            callback1_set(pokedex_callback_return);
            fadescreen_all(1, 0);
            play_sound(5);
        } else if (super.keys_new.keys.left && !pokedex_state->current_group) {
            //we switch to feature selection
            pokedex_state->current_group = 1;
            pokedex_group_window_set();
            play_sound(5);
        } else if (super.keys_new.keys.up && pokedex_state->current_group <= 1) {
            pokedex_state->current_group = 2;
            pokedex_group_window_set();
            play_sound(5);
        } else if (super.keys_new.keys.down && pokedex_state->current_group == 2) {
            pokedex_state->current_group = 0;
            pokedex_group_window_set();
            play_sound(5);
        } else if (super.keys_new.keys.right && pokedex_state->current_group == 1) {
            pokedex_state->current_group = 0;
            pokedex_group_window_set();
            play_sound(5);
        }
        color_t over = {0x7FFF};
        pals[17] = color_alpha_blend(pal_restore[17], over, pokedex_state->group_fading_index);


    }
}

static void pokedex_group_window_set() {
    io_set(0, io_get(0) | 0x2000); //enable win0
    io_set(0x48, 0x1F1F); //all bgs and obj layer are inside window
    io_set(0x4A, 0x1B1B); //bg2 is excluded from outside the window
    u8 leftmost = 0;
    u8 rightmost = 240;
    u8 topmost = 0;
    u8 bottommost = 160;
    switch (pokedex_state->current_group) {
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
    u16 hdim = (u16) (rightmost | (leftmost << 8));
    u16 vdim = (u16) (bottommost | (topmost << 8));
    io_set(0x40, hdim);
    io_set(0x44, vdim);
}

static void pokedex_group_selection_fading_proceed() {
    if (pokedex_state->group_fading_mode) {
        //fade count decrease
        if (pokedex_state->group_fading_index) {
            pokedex_state->group_fading_index--;
        } else {
            pokedex_state->group_fading_mode = false;
        }
    } else {
        //fade count increase
        if (pokedex_state->group_fading_index < 16) {
            pokedex_state->group_fading_index++;
        } else {
            pokedex_state->group_fading_mode = true;
        }
    }
}

static void pokedex_handle_inputs_list(u8 self) {
    (void)self;
}

static void pokedex_handle_inputs_features(u8 self) {
    (void)self;
}

static void pokedex_resort(u8 self) {
    (void)self;
}


static void pokedex_handle_inputs_group_selection(u8 self) {
    if (fading_control.active || dma3_busy(-1))
        return;
    pokedex_group_selection_fading_proceed();
    if (super.keys_new.keys.A) {
        switch (pokedex_state->current_group) {
            case POKEDEX_GROUP_LIST: {
                play_sound(5);
                pokedex_state->list_countdown = 0;
                pokedex_state->list_mode = 0;
                pokedex_state->in_list = true;
                pokedex_state->group_fading_index = 16;
                pokedex_state->group_fading_mode = true;
                big_callbacks[self].function = pokedex_handle_inputs_list;
                break;
            }
            case POKEDEX_GROUP_FEATURES: {
                if (checkflag(POKEDEX_FEATURE_0) || checkflag(POKEDEX_FEATURE_1)
                    || checkflag(POKEDEX_FEATURE_2)) {
                    play_sound(5);
                    // Find a valid feature
                    for(u8 i = 0; i < 3; i++){
                        if(checkflag(feature_flags[i])){
                            pokedex_state->current_feature = i;
                            break;
                        }
                    }
                    pokedex_print_feature_strings();
                    pokedex_state->group_fading_index = 16;
                    pokedex_state->group_fading_mode = true;
                    big_callbacks[self].function = pokedex_handle_inputs_features;
                } else {
                    play_sound(26);
                }
                break;
            }
            case POKEDEX_GROUP_SORTING: {
                play_sound(5);
                pokedex_state->resorting = false;
                pokedex_state->sort_cursor_pos = pokedex_state->current_comparator & 0x3;
                pokedex_state->group_fading_index = 16;
                pokedex_state->group_fading_mode = true;
                oams[pokedex_state->oam_sort_cursor].anim_number = 1;
                oam_gfx_anim_init(&oams[pokedex_state->oam_sort_cursor], 0);
                big_callbacks[self].function = pokedex_resort;
                break;   
            }
        }
    }


}

void pokedex_callback_initialize() {
    pokedex_cb1();
    if (fading_control.active || dma3_busy(-1))
        return;
    
    switch (pokedex_state->initialization_state) {
        case POKEDEX_SETUP_STATE_FREE_PREVIOUS_STATE: 
            if (pokedex_state->from_outdoor) {
            overworld_free();
            } else {
                pokepad2_free();
            }
            pokedex_state->initialization_state++;
            break;
        case POKEDEX_SETUP_STATE_DATA_SETUP:
            pokedex_build_list();
            pokedex_quicksort_list((u8) pokedex_state->current_comparator, 0, POKEDEX_CNT - 1); //resort list
            pokedex_state->initialization_state++;
            break;
        case POKEDEX_SETUP_STATE_RESET:
            oam_reset();
            big_callback_delete_all();
            fading_cntrl_reset(); 
            fading_control.buffer_transfer_disabled = true;
            oam_palette_allocation_reset();
            dma0_reset_callback();
            reset_hblank_and_vblank_callbacks();
            pokedex_state->initialization_state++;
            break;
        case POKEDEX_SETUP_STATE_SETUP_BGS:
            bg_reset(0);
            bg_setup(0, pokedex_bg_main_configs, 4);
            bg_display_sync();
            for (u8 i = 0; i < 4; i++) {
                pokedex_state->bg_maps[i] = malloc_and_clear(32 * 32 * sizeof(bg_tile));
                bg_set_tilemap(i, pokedex_state->bg_maps[i]);
                bg_virtual_map_displace(i, 0, 0);
                bg_virtual_set_displace(i, 0, 0);
                bg_virtual_sync(i);
            }
            io_set(IO_DISPCNT, IO_DISPCNT_OAM_CHARACTER_MAPPING_ONE_DIMENSIONAL | IO_DISPCNT_OBJ | IO_DISPCNT_WIN0);
            io_set(IO_BLDCNT, IO_BLDCNT_NONE);
            pokedex_state->initialization_state++;
            break;
        case POKEDEX_SETUP_STATE_SETUP_TBOXES: {
            tbox_free_all();
            tbox_sync_with_virtual_bg_and_init_all(pokedex_tboxes);
            u16 seen = pokedex_get_number_seen_or_caught(false);
            u16 caught = pokedex_get_number_seen_or_caught(true);
            itoa(strbuf, seen, 0, 3);
            tbox_flush_set(POKEDEX_TBOX_SEEN, 0);
            tbox_tilemap_draw(POKEDEX_TBOX_SEEN);
            tbox_print_string(POKEDEX_TBOX_SEEN, 2, 0, 0, 0, 0, &pokedex_fontcolmap, 0, strbuf);
            itoa(strbuf, caught, 0, 3);
            tbox_flush_set(POKEDEX_TBOX_CAUGHT, 0);
            tbox_tilemap_draw(POKEDEX_TBOX_CAUGHT);
            tbox_print_string(POKEDEX_TBOX_CAUGHT, 2, 0, 0, 0, 0, &pokedex_fontcolmap, 0, strbuf);
            pokedex_print_feature_strings();
            pokedex_state->initialization_state++;
            break;
        }
        case POKEDEX_SETUP_STATE_LOAD_GFX: {
            lz77uncompwram(gfx_pokedex_uiMap, pokedex_state->bg_maps[1]);
            lz77uncompvram(gfx_pokedex_uiTiles, CHARBASE(0));
            lz77uncompwram(gfx_pokedex_bottom_1Map, pokedex_state->bg_maps[2]);
            lz77uncompvram(gfx_pokedex_bottom_1Tiles, CHARBASE(1));
            lz77uncompwram(gfx_pokedex_bottom_0Map, pokedex_state->bg_maps[3]);
            oam_load_graphic(&pokedex_cursor_graphic);
            u8 cursor_pal = (u8) (oam_allocate_palette(POKEDEX_CURSOR_GFX_TAG) + 0x10);
            pal_decompress(gfx_pokedex_sort_cursorPal, (u16) (cursor_pal * 16), 32);
            pal_decompress(gfx_pokedex_uiPal, 0, 32);
            const color_t cols_active [2] = {
                {0x6754},
                {0x56D0}};
            const color_t cols_inactive [2] = {
                {0x3E0C},
                {0x35E8}};
            if (checkflag(POKEDEX_FEATURE_0)) {
                pal_copy(cols_active, 10, 4);
            } else {
                pal_copy(cols_inactive, 10, 4);
            }
            if (checkflag(POKEDEX_FEATURE_1)) {
                pal_copy(cols_active, 12, 4);
            } else {
                pal_copy(cols_inactive, 12, 4);
            }
            if (checkflag(POKEDEX_FEATURE_2)) {
                pal_copy(cols_active, 14, 4);
            } else {
                pal_copy(cols_inactive, 14, 4);
            }
            pal_decompress(gfx_pokedex_bottom_1Pal, 16, 32);
            pal_decompress(gfx_pokedex_bottom_0Pal, 32, 32);
            pal_copy(pokedex_colors, 15 * 16, 16);
            pal_copy(pokedex_colors_nr, 14 * 16, 32);
            pal_copy(typechart_icon_pal, 3 * 16, 32);
            pal_copy(tbox_pokeball_pal, 4 * 16, 32);
            pokedex_state->initialization_state++;
            break;
        }
        case POKEDEX_SETUP_STATE_SETUP_OAM: {
            pokedex_state->oam_sort_cursor = oam_new_forward_search(&pokedex_cursor_template, 128, 16, 0);
            pokedex_state->sort_cursor_pos = pokedex_state->current_comparator & 3;
            pokedex_sort_locate_cursor();
            pokedex_state->initialization_state++;
            break;
        }
        case POKEDEX_SETUP_STATE_UPDATE_LIST:
            pokedex_update_list();
            pokedex_state->initialization_state++;
            break;
        case POKEDEX_SETUP_SHOW: {
            pal_set_all_to_black();
            fading_control.buffer_transfer_disabled = false;   
                
            pokedex_group_window_set();
            // Those requests are picked up by the vblank callback and copies the tilemaps
            bg_virtual_sync_reqeust_push(0);
            bg_virtual_sync_reqeust_push(1);
            bg_virtual_sync_reqeust_push(2);
            bg_virtual_sync_reqeust_push(3);
            pokedex_state->initialization_state++;
            break;
        }
        default: {
            bg_sync_display_and_show(0);
            bg_sync_display_and_show(1);
            bg_sync_display_and_show(2);
            bg_sync_display_and_show(3);  
            bg_display_sync();
            io_set(IO_BLDCNT, 0);
            io_set(IO_BLDALPHA, 0);
            io_set(IO_BLDY, 0);
            io_bic(IO_DISPCNT, IO_DISPCNT_WIN0 | IO_DISPCNT_WIN1);
            fadescreen(0xFFFFFFFF, 0, 16, 0, 0);
            callback1_set(pokedex_cb1);
            vblank_handler_set(generic_vblank_handler);
            big_callback_new(pokedex_handle_inputs_group_selection, 0);
        }
    }
}

void pokedex_initialize(bool from_outdoor) {
    overworld_rain_sound_fade_out();
    pokedex_state = malloc_and_clear(sizeof (pokedex_state_t));
    pokedex_state->from_outdoor = from_outdoor;
    pokedex_state->current_group = 0;
    pokedex_state->current_species = *var_access(POKEDEX_LAST_SPECIES);
    pokedex_state->current_comparator = (u8) * var_access(POKEDEX_ACTIVE_COMPARATOR);
    pokedex_state->cursor_anchor = 0;
    pokedex_state->current_feature = 0xFF;
    callback1_set(pokedex_callback_initialize);
    if (from_outdoor)
        fadescreen_all(1, 0);
    else
        fadescreen(0xFFFFFFFF, 0, 0, 16, 0x0);
}
