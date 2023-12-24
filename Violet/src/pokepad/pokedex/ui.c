
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
#include "menu_indicators.h"

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

extern const LZ77COMPRESSED gfx_pokedex_ui2Tiles;
extern const LZ77COMPRESSED gfx_pokedex_ui2Map;
extern const LZ77COMPRESSED gfx_pokedex_ui2Pal;

static void pokedex_handle_inputs(u8 self);

static const bg_config pokedex_bg_main_configs [] = {
    {0, 2, 31, 0, 0, 1},
    {1, 0, 30, 0, 0, 3},
    {2, 2, 29, 0, 0, 2},
    {3, 2, 28, 0, 0, 0},
};

static const tboxdata pokedex_tboxes[NUM_POKEDEX_TBOXES + 1] = {
    [POKEDEX_TBOX_STATS] = {.bg_id = 0, .x = 0, .y = 16, .w = 9, .h = 4, .pal = 15, .start_tile = 1 + TBOX_FRAME_SET_STYLE_NUM_TILES},
    [POKEDEX_TBOX_TITLE] = {.bg_id = 0, .x = 2, .y = 0, .w = 7, .h = 2, .pal = 15, .start_tile = 1 + TBOX_FRAME_SET_STYLE_NUM_TILES + 9 * 4},
    [POKEDEX_TBOX_LIST_NUMBER] = {.bg_id = 0, .x = 9, .y = 2, .w = POKEDEX_LIST_WIDTH_NUMBER, .h = 18, .pal = 14, .start_tile = 1 + TBOX_FRAME_SET_STYLE_NUM_TILES + 9 * 4 + 7 * 2},
    [POKEDEX_TBOX_LIST_CAUGHT_ICON] = {.bg_id = 2, .x = 9 + POKEDEX_LIST_WIDTH_NUMBER - 1, .y = 2, .w = POKEDEX_LIST_WIDTH_CAUGHT_ICON, .h = 18, .pal = 4, .start_tile = 1 + TBOX_FRAME_SET_STYLE_NUM_TILES + 9 * 4 + 7 * 2 + (POKEDEX_LIST_WIDTH_NUMBER) * 18},
    [POKEDEX_TBOX_LIST_NAME] = {.bg_id = 0, .x = 9 + POKEDEX_LIST_WIDTH_NUMBER, .y = 2, .w = POKEDEX_LIST_WIDTH_NAME, .h = 18, .pal = 4, .start_tile = 1 + TBOX_FRAME_SET_STYLE_NUM_TILES + 9 * 4 + 7 * 2 + (POKEDEX_LIST_WIDTH_NUMBER + POKEDEX_LIST_WIDTH_CAUGHT_ICON) * 18},
    [POKEDEX_TBOX_LIST_TYPE] = {.bg_id = 2, .x = 9 + POKEDEX_LIST_WIDTH_NUMBER + POKEDEX_LIST_WIDTH_NAME - 1, .y = 2, .w = POKEDEX_LIST_WIDTH_TYPE, .h = 18, .pal = 3, .start_tile = 1 + TBOX_FRAME_SET_STYLE_NUM_TILES + 9 * 4 + 7 * 2 + (POKEDEX_LIST_WIDTH_NUMBER + POKEDEX_LIST_WIDTH_CAUGHT_ICON + POKEDEX_LIST_WIDTH_NAME) * 18},
    [POKEDEX_TBOX_HEADER] = {.bg_id = 0, .x = 11, .y = 0, .w = 19, .h = 2, .pal = 15, .start_tile = 1 + TBOX_FRAME_SET_STYLE_NUM_TILES + 9 * 4 + 7 * 2 + (POKEDEX_LIST_WIDTH_NUMBER + POKEDEX_LIST_WIDTH_CAUGHT_ICON + POKEDEX_LIST_WIDTH_NAME + POKEDEX_LIST_WIDTH_TYPE) * 18},
    [POKEDEX_TBOX_CONTEXT_MENU_SORT] = {.bg_id = 3, .x = 20, .y = 11, .w = 9, .h = 8, .pal = 13, .start_tile = 1 + TBOX_FRAME_SET_STYLE_NUM_TILES + 9 * 4 + 7 * 2 + (POKEDEX_LIST_WIDTH_NUMBER + POKEDEX_LIST_WIDTH_CAUGHT_ICON + POKEDEX_LIST_WIDTH_NAME + POKEDEX_LIST_WIDTH_TYPE) * 18 + 19 * 2},
    [NUM_POKEDEX_TBOXES] = {.bg_id = 0xFF},
};


const sprite pokedex_cursor_sprite = {
    0, 0x8000, 0, 0
};

static const sprite pokedex_pokemon_sprite = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_64_64, .attr2 = ATTR2_PRIO(0),
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

static const oam_template pokedex_pokemon_template = {
    .tiles_tag = POKEDEX_UI_POKEMON_TAG, .pal_tag = POKEDEX_UI_POKEMON_TAG,
    .oam = &pokedex_pokemon_sprite, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback
};

const tbox_font_colormap pokedex_fontcolmap = {0, 2, 1, 0};
const tbox_font_colormap pokedex_features_active_fontcolmap = {0, 15, 13, 1};
const tbox_font_colormap pokedex_features_fontcolmap = {0, 10, 13, 1};

const u16 pokedex_colors[16] = {0, 0x2927, 0x7FFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u16 pokedex_colors_nr[16] = {0, 0x7FFF, 0x2927, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void pokedex_cb1() {
    tbox_proceed();
    oam_animations_proceed();
    oam_proceed();
    big_callback_proceed(); // important that the input handling (big_callback) is done after the oam proceeds
    bg_virtual_sync_reqeust_proceed();
    fading_proceed();
}

static const u8 str_sorting_numeric[] = LANGDEP(PSTRING("Nummer"), PSTRING("Number"));
static const u8 str_sorting_alphabetic[] = LANGDEP(PSTRING("Name (A-Z)"), PSTRING("Name (A-Z)"));
static const u8 str_sorting_size[] = LANGDEP(PSTRING("Größe"), PSTRING("Size"));
static const u8 str_sorting_weight[] = LANGDEP(PSTRING("Gewicht"), PSTRING("Weight"));

static const list_menu_item list_menu_context_menu_sort_items[NUM_POKEDEX_SORTINGS] = {
    [POKEDEX_SORTING_NUMERIC] = {.idx = POKEDEX_SORTING_NUMERIC, .text = str_sorting_numeric},
    [POKEDEX_SORTING_ALPHABETIC] = {.idx = POKEDEX_SORTING_ALPHABETIC, .text = str_sorting_alphabetic},
    [POKEDEX_SORTING_SIZE] = {.idx = POKEDEX_SORTING_SIZE, .text = str_sorting_size},
    [POKEDEX_SORTING_WEIGHT] = {.idx = POKEDEX_SORTING_WEIGHT, .text = str_sorting_weight},
};

static void list_menu_print_callback_null(u8 __attribute__((unused)) tbox_idx, int __attribute__((unused)) idx, u8 __attribute__((unused)) y) { } 

static void pokedex_context_menu_sorting_continuation(u8 self) {
    pokedex_list_scroll_indicators_new();
    big_callbacks[self].function = pokedex_handle_inputs;
}

void pokedex_context_menu_sort_handle_inputs(u8 self) {
    (void)self;
    if (fading_control.active || dma3_busy(-1))
        return;
    int input = list_menu_process_input(pokedex_state->context_menu_sort_list_menu_cb_idx);
    switch (input) {
        default: {
            if (csave.pokedex_sorting != input) {
                play_sound(6);
                csave.pokedex_sorting = (u8)input;
                big_callbacks[self].params[0] = 0;
                tbox_flush_map_and_frame(POKEDEX_TBOX_CONTEXT_MENU_SORT);
                bg_virtual_sync_reqeust_push(pokedex_tboxes[POKEDEX_TBOX_CONTEXT_MENU_SORT].bg_id);
                pokedex_resort_list(self, pokedex_context_menu_sorting_continuation);
                return;
            }
            FALL_THROUGH;
        }
        case LIST_MENU_B_PRESSED: {
            play_sound(5);
            tbox_flush_map_and_frame(POKEDEX_TBOX_CONTEXT_MENU_SORT);
            bg_virtual_sync_reqeust_push(pokedex_tboxes[POKEDEX_TBOX_CONTEXT_MENU_SORT].bg_id);
            pokedex_list_scroll_indicators_new();
            big_callbacks[self].function = pokedex_handle_inputs;
            break;
        }
        case LIST_MENU_NOTHING_CHOSEN:
            return;
    }
}

static const list_menu_template list_menu_context_menu_sort = {
    .items = list_menu_context_menu_sort_items,
    .cursor_moved_callback = list_menu_generic_cursor_callback,
    .item_print_callback = list_menu_print_callback_null,
    .item_cnt = NUM_POKEDEX_SORTINGS, .max_items_showed = NUM_POKEDEX_SORTINGS, .tbox_idx = POKEDEX_TBOX_CONTEXT_MENU_SORT,
    .header_x = 0, .item_x = 12, .cursor_x = 4, .up_text_y = 2, .cursor_pal = 2, .fill_value = 1,
    .cursor_shadow_color = 3, .letter_spacing = 1, .item_vertical_padding = 2, .scroll_multiple = 0,
    .font = 2
};

static void pokedex_context_menu_sort_new(u8 self) {
    tbox_flush_set(POKEDEX_TBOX_CONTEXT_MENU_SORT, 0x11);
    tbox_tilemap_draw(POKEDEX_TBOX_CONTEXT_MENU_SORT);
    tbox_frame_draw_outer(POKEDEX_TBOX_CONTEXT_MENU_SORT, 1, 13);
    tbox_sync(POKEDEX_TBOX_CONTEXT_MENU_SORT, TBOX_SYNC_SET);
    tbox_copy_to_vram(POKEDEX_TBOX_CONTEXT_MENU_SORT, TBOX_COPY_TILEMAP);
    scroll_indicator_delete(pokedex_state->list_scroll_indicator_cb_idx);
    pokedex_state->context_menu_sort_list_menu_cb_idx =  list_menu_new(&list_menu_context_menu_sort, 0, csave.pokedex_sorting);
    big_callbacks[self].function = pokedex_context_menu_sort_handle_inputs;
}

static void pokedex_free_all_except_state() {
    tbox_free_all();
    for (u8 i = 0; i < 4; i++)
        free(pokedex_state->bg_maps[i]);
}

static void pokedex_callback_return(u8 self) {
    if (fading_control.active || dma3_busy(-1))
        return;
    if (pokedex_state->from_outdoor)
        callback1_set(map_reload);
    else
        callback1_set(pokepad2_callback_initialize);
    pokedex_free_all_except_state();
    free(pokedex_state);
    big_callback_delete(self);
}

static void pokedex_callback_scanner(u8 self) {
    if (fading_control.active || dma3_busy(-1))
        return;
    callback1_set(pokedex_callback_initialize_feature_scanner);
    pokedex_free_all_except_state();
    big_callback_delete(self);
}

static void pokedex_callback_entry(u8 self) {
    if (fading_control.active || dma3_busy(-1))
        return;
    color_t black = {.rgb = {.red = 0, .blue = 0, .green = 0}};
    pokedex_entry_initialize(pokedex_state->list[pokedex_state->current_list_index].species, 
        POKEDEX_ENTRY_PAGE_CONTEXT_POKEDEX, pokedex_callback_initialize, true, black);
    pokedex_free_all_except_state();
    big_callback_delete(self);
}

static void pokedex_handle_inputs(u8 self) {
    (void)self;
    if (fading_control.active || dma3_busy(-1))
        return;
    int offset = 0;
    u8 scrolling_down = false;
    if (super.keys_new_and_repeated.keys.right) {
        offset = POKEDEX_LIST_MAX_NUM_VISIBLE;
        scrolling_down = true;
    } else if (super.keys_new_and_repeated.keys.down) {
        offset = 1;
        scrolling_down = true;
    } else if (super.keys_new_and_repeated.keys.left) {
        offset = -POKEDEX_LIST_MAX_NUM_VISIBLE;
    } else if (super.keys_new_and_repeated.keys.up) {
        offset = -1;
    } else if (super.keys_new.keys.select) {
        play_sound(5);
        pokedex_context_menu_sort_new(self);
        return;
    } else if (super.keys_new.keys.A && pokedex_state->list[pokedex_state->current_list_index].seen) {
        play_sound(5);
        fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
        big_callbacks[self].function = pokedex_callback_entry;
    } else if (super.keys_new.keys.B) {
        fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
        big_callbacks[self].function = pokedex_callback_return;
    } else if (super.keys_new.keys.start && checkflag(FLAG_POKEDEX_SCANNER)) {
        play_sound(5);
        fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
        big_callbacks[self].function = pokedex_callback_scanner;
    }
    if (offset != 0) {
        u16 index = (u16)MIN(pokedex_state->last_idx, MAX(pokedex_state->first_idx, pokedex_state->current_list_index + offset));
        if (index != pokedex_state->current_list_index) {
            play_sound(5);
            pokedex_state->current_list_index = index;
            pokedex_state->list_is_scrolling_down = (u8)(scrolling_down & 1);
            pokedex_update_list(scrolling_down);
        }
    }
}

static const u8 str_seen[] = LANGDEP(PSTRING("Ges."), PSTRING("Seen"));
static const u8 str_caught[] = LANGDEP(PSTRING("Gef."), PSTRING("Caught"));

void pokedex_callback_initialize_state_machine() {
    DEBUG("Pokedex initialization state: %d\n", pokedex_state->initialization_state);
    pokedex_cb1();
    if (fading_control.active || dma3_busy(-1))
        return;
    
    switch (pokedex_state->initialization_state) {
        case POKEDEX_SETUP_STATE_DATA_SETUP:
            keys_repeated_start_delay = 20;
            keys_repeated_continue_delay = 1;
            pokedex_build_list();
            pokedex_quicksort_list((u8) csave.pokedex_sorting, 0, POKEDEX_CNT - 1); //resort list
            pokedex_list_update_bounds();
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
            FALL_THROUGH;
        case POKEDEX_SETUP_STATE_SETUP_BGS:
            bg_reset(0);
            bg_setup(0, pokedex_bg_main_configs, ARRAY_COUNT(pokedex_bg_main_configs));
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
            FALL_THROUGH;
        case POKEDEX_SETUP_STATE_SETUP_TBOXES: {
            tbox_free_all();
            tbox_sync_with_virtual_bg_and_init_all(pokedex_tboxes);
            tbox_init_frame_set_style(POKEDEX_TBOX_CONTEXT_MENU_SORT, 1, 13 * 16);
            u16 seen = pokedex_get_number_seen_or_caught(false);
            u16 caught = pokedex_get_number_seen_or_caught(true);
            tbox_flush_set(POKEDEX_TBOX_STATS, 0x00);
            tbox_tilemap_draw(POKEDEX_TBOX_STATS);
            tbox_print_string(POKEDEX_TBOX_STATS, 2, 4, 0, 0, 0, &pokedex_fontcolmap, 0xFF, str_seen);
            tbox_print_string(POKEDEX_TBOX_STATS, 2, 4, 16, 0, 0, &pokedex_fontcolmap, 0xFF, str_caught);
            itoa(strbuf, seen, ITOA_PAD_SPACES, 3);
            tbox_print_string(POKEDEX_TBOX_STATS, 2, 46, 0, 0, 0, &pokedex_fontcolmap, 0xFF, strbuf);
            itoa(strbuf, caught, ITOA_PAD_SPACES, 3);
            tbox_print_string(POKEDEX_TBOX_STATS, 2, 46, 16, 0, 0, &pokedex_fontcolmap, 0, strbuf);
            u8 str_header[] = PSTRING("Pokédex");
            tbox_flush_set(POKEDEX_TBOX_TITLE, 0x00);
            tbox_tilemap_draw(POKEDEX_TBOX_TITLE);
            tbox_print_string(POKEDEX_TBOX_TITLE, 2, 
                (u16)(1 + (pokedex_tboxes[POKEDEX_TBOX_TITLE].w * 8 - string_get_width(2, str_header, 0)) / 2), 
                0, 0, 0,  &pokedex_fontcolmap, 0, str_header);
            tbox_flush_set(POKEDEX_TBOX_HEADER, 0x00);
            tbox_tilemap_draw(POKEDEX_TBOX_HEADER);
            u8 str_title[] = LANGDEP(PSTRING("KEY_ASKIP\x01InfoSKIP\x02KEY_SELECTSKIP\x01Sort."), 
                                        PSTRING("KEY_ASKIP\x01InfoSKIP\x02KEY_SELECTSKIP\x01Sort"));
            strcpy(strbuf, str_title);
            if (checkflag(FLAG_POKEDEX_SCANNER)) {
                u8 str_scanner[] = LANGDEP(PSTRING("SKIP\x02KEY_STARTSKIP\x01Scan"), 
                                            PSTRING("SKIP\x02KEY_STARTSKIP\x01Scan"));
                strcat(strbuf, str_scanner);
            }
            tbox_print_string(POKEDEX_TBOX_HEADER, 2, 2, 1, 0, 0,  &pokedex_fontcolmap, 0, strbuf);
            tbox_flush_set(POKEDEX_TBOX_CONTEXT_MENU_SORT, 0x00);
            tbox_flush_map(POKEDEX_TBOX_CONTEXT_MENU_SORT);
            tbox_sync(POKEDEX_TBOX_CONTEXT_MENU_SORT, TBOX_SYNC_MAP_AND_SET);
            pokedex_state->initialization_state++;
            break;
        }
        case POKEDEX_SETUP_STATE_LOAD_GFX: {
            lz77uncompwram(gfx_pokedex_ui2Map, pokedex_state->bg_maps[1]);
            lz77uncompvram(gfx_pokedex_ui2Tiles, CHARBASE(0));
            u8 cursor_pal = (u8) (oam_allocate_palette(POKEDEX_CURSOR_GFX_TAG) + 0x10);
            pal_decompress(gfx_pokedex_sort_cursorPal, (u16) (cursor_pal * 16), 32);
            pal_decompress(gfx_pokedex_ui2Pal, 0, 16 * sizeof(color_t));
            color_t backdrop = {.rgb = {.red = 7, .blue = 9, .green = 10}};
            pal_copy(&backdrop, 0, sizeof(color_t));
            pal_copy(pokedex_colors, 15 * 16, 16 * sizeof(color_t));
            pal_copy(pokedex_colors_nr, 14 * 16, 16 * sizeof(color_t));
            pal_copy(typechart_icon_pal, 3 * 16, 16 * sizeof(color_t));
            pal_copy(tbox_pokeball_pal, 4 * 16, 16 * sizeof(color_t));
            pokedex_state->initialization_state++;
            break;
        }
        case POKEDEX_SETUP_STATE_SETUP_OAM: {
            pokedex_state->base_tile_pokemon = oam_vram_alloc(GRAPHIC_SIZE_4BPP_TO_NUM_TILES(64, 64));
            oam_vram_allocation_table_add(POKEDEX_UI_POKEMON_TAG, pokedex_state->base_tile_pokemon, 
                GRAPHIC_SIZE_4BPP_TO_NUM_TILES(64, 64));
            pokedex_state->pal_idx_pokemon = oam_allocate_palette(POKEDEX_UI_POKEMON_TAG);
            pokedex_state->oam_idx_pokemon = oam_new_backward_search(&pokedex_pokemon_template, 34, 72, 0);
            pokedex_state->initialization_state++;
            FALL_THROUGH;
        }
        case POKEDEX_SETUP_STATE_UPDATE_LIST:
            pokedex_update_list(pokedex_state->list_is_scrolling_down);
            pokedex_state->initialization_state++;
            break;
        case POKEDEX_SETUP_SCROLL_INDICATORS: {
            pokedex_list_scroll_indicators_new();
            pokedex_state->initialization_state++;
            break;
        }
        case POKEDEX_SETUP_SHOW: {
            pal_set_all_to_black();
            fading_control.buffer_transfer_disabled = false;   
                
            // pokedex_group_window_set();
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
            big_callback_new(pokedex_handle_inputs, 0);
        }
    }
}

void pokedex_callback_initialize() {
    pokedex_state->initialization_state = 0;
    callback1_set(pokedex_callback_initialize_state_machine);
}

static void pokedex_callback_free_previous_context_and_initialize() {
    pokedex_cb1();
    if (fading_control.active || dma3_busy(-1))
        return;
    if (pokedex_state->from_outdoor) {
        overworld_free();
    } else {
        pokepad2_free();
    }
    callback1_set(pokedex_callback_initialize);
}

void pokedex_initialize(bool from_outdoor) {
    overworld_rain_sound_fade_out();
    pokedex_state = malloc_and_clear(sizeof (pokedex_state_t));
    pokedex_state->from_outdoor = from_outdoor;
    callback1_set(pokedex_callback_free_previous_context_and_initialize);
    if (from_outdoor)
        fadescreen_all(1, 0);
    else
        fadescreen(0xFFFFFFFF, 0, 0, 16, 0x0);
}