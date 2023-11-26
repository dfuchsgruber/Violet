#include "types.h"
#include "fading.h"
#include "pokepad/pokedex/entry.h"
#include "pokepad/pokedex/pages/move_list.h"
#include "pokemon/moves.h"
#include "agbmemory.h"
#include "language.h"
#include "attack.h"
#include "bios.h"
#include "music.h"
#include "dma.h"
#include "debug.h"
#include "constants/attack_categories.h"
#include "menu_indicators.h"

void pokedex_entry_page_move_list_setup_bg(u8 layer) {
    lz77uncompvram(gfx_pokedex_entry_page_move_list_uiTiles, CHARBASE_PLUS_OFFSET_4BPP(1, 1 + layer * POKEDEX_ENTRY_PAGE_NUM_TILES));
    lz77uncompwram(gfx_pokedex_entry_page_move_list_uiMap, pokedex_entry_state->bg_maps[2 + layer]);
    pal_decompress(gfx_pokedex_entry_page_move_list_uiPal, (u16)(16 * (2 + POKEDEX_ENTRY_PAGE_NUM_PALS * layer)), 16 * sizeof(color_t));
    // Shift the palette and tile indices of the map
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 30; x++) {
            bg_tile tile = pokedex_entry_state->bg_maps[2 + layer][y][x];
            tile.text.tile_number = (u16)((tile.text.tile_number + layer * POKEDEX_ENTRY_PAGE_NUM_TILES) & 0x3FF);
            tile.text.palette = (u16)((2 + layer * POKEDEX_ENTRY_PAGE_NUM_PALS) & 0xF);
            pokedex_entry_state->bg_maps[2 + layer][y][x] = tile;
        }
    }
}


static const tboxdata pokedex_entry_page_move_list_tboxes[NUM_POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOXES + 1] = {
    [POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_LIST] = {.bg_id = 0, .x = 19, .y = 3, .w = 11, .h = 10, .pal = 13, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE},
    [POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_DESCRIPTION] = {.bg_id = 0, .x = 9, .y = 13, .h = 7, .w = 14, .pal = 13, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE + 11 * 10},
    [POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES] = {.bg_id = 0, .x = 9, .y = 3, .h = 10, .w = 5, .pal = 11, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE + 11 * 10 + 14 * 7},
    [POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES] = {.bg_id = 0, .x = 14, .y = 3, .h = 10, .w = 5, .pal = 11, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE + 11 * 10 + 14 * 7 + 6 * 10},
    [NUM_POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOXES] = {.bg_id = 0xFF},
};

static void pokedex_entry_page_move_list_setup_any() {
    switch (pokedex_entry_state->page_initialization_state) {
        case POKEDEX_ENTRY_PAGE_MOVE_LIST_INITIALIZATION_STATE_DATA_SETUP: {
            break;
        }
        case POKEDEX_ENTRY_PAGE_MOVE_LIST_INITIALIZATION_STATE_SETUP_TBOXES:
            pokedex_entry_page_initialize_tboxes(pokedex_entry_page_move_list_tboxes);
            break;
        
        case POKEDEX_ENTRY_PAGE_MOVE_LIST_INITIALIZATION_STATE_SETUP_SCROLL_INDICATORS: {
            break;
        }
    }
}
static void pokedex_entry_page_move_list_print_item_callback(u8 tbox_idx, int idx, u8 y) {
    (void)tbox_idx; (void)idx; (void)y;
}

static const tbox_font_colormap font_colormap_std = {.background = 0, .body = 2, .edge = 3};
static const tbox_font_colormap font_colormap_typechart_pal = {.background = 0, .body = 15, .edge = 14};

static const u8 str_move_no_power[] = PSTRING("---");

static void pokedex_entry_page_move_list_update(int idx) {
    tbox_flush_set(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_DESCRIPTION], 0x00);
    tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_DESCRIPTION], 
        0, 0, 0, 0, 0, &font_colormap_std, 0, attack_descriptions[idx - 1]);
    tbox_flush_set(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES], 0x00);
    if (attacks[idx].base_power == 0 || attacks[idx].category == CATEGORY_STATUS) {
        strcpy(strbuf, str_move_no_power);
    } else {
        itoa(strbuf, attacks[idx].base_power, ITOA_NO_PADDING, 3);
    }
    tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES], 
        2, 4, 2, 0, 0, &font_colormap_typechart_pal, 0xFF, strbuf);
    tbox_blit_move_info_icon(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES], 
        (u8)(MOVE_INFO_TYPE_BASE + attacks[idx].type), 4, 1 * 13 + 2);
    tbox_blit_move_info_icon(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES], 
        (u8)(MOVE_INFO_PHYSICAL + attacks[idx].category), 2, 2 * 13 + 2);
    if (attacks[idx].accuracy == 0) {
        strcpy(strbuf, str_move_no_power);
    } else {
        itoa(strbuf, attacks[idx].accuracy, ITOA_NO_PADDING, 3);
    }
    tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES], 
            2, 4, 2 + 3 * 13, 0, 0, &font_colormap_typechart_pal, 0xFF, strbuf);
    itoa(strbuf, attacks[idx].pp, ITOA_NO_PADDING, 3);
    tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES], 
            2, 4, 2 + 4 * 13, 0, 0, &font_colormap_typechart_pal, 0xFF, strbuf);
    tbox_sync(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES], TBOX_SYNC_SET);
}

static void pokedex_entry_page_move_list_cursor_move_callback(int idx, u8 on_initialize, list_menu *list) {
    (void)list;
    DEBUG("Cursor move callback on initialize: %d\n", on_initialize);
    if (!on_initialize)
        play_sound(5);
    pokedex_entry_page_move_list_update(idx);
}

static const list_menu_template move_list_list_menu_template = {
    .header_x = 0, .item_x = 9, .cursor_x = 1, .font = 0,
    .max_items_showed = POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_SHOWN,
    .cursor_pal = 2, .cursor_shadow_color = 3,
    .cursor_moved_callback = pokedex_entry_page_move_list_cursor_move_callback,
    .item_print_callback = pokedex_entry_page_move_list_print_item_callback,
};

static const u8 str_move_move_list_level[] = LANGDEP(PSTRING("BUFFER_1CLEAR_TO\x10BUFFER_2"), PSTRING("BUFFER_1CLEAR_TO\x10BUFFER_2"));
static const u8 str_move_move_list_evolution[] = LANGDEP(PSTRING("EvoCLEAR_TO\x10BUFFER_2"), PSTRING("EvoCLEAR_TO\x10BUFFER_2"));
// static const u8 str_move_list_header[] = LANGDEP(PSTRING("LvCLEAR_TO\x0CName"), PSTRING("LvlCLEAR_TO\x0CName"));

bool pokedex_entry_page_move_list_setup() {
    pokedex_entry_page_move_list_setup_any();
    switch (pokedex_entry_state->page_initialization_state) {
        case POKEDEX_ENTRY_PAGE_MOVE_LIST_INITIALIZATION_STATE_DATA_SETUP: {
            pokedex_entry_state->page_initialization_state++;
            break;
        }
        case POKEDEX_ENTRY_PAGE_MOVE_LIST_INITIALIZATION_STATE_SETUP_TBOXES: {
            // tbox_flush_set(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_HEADER], 0x00);
            // tbox_tilemap_draw(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_HEADER]);
            // tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_HEADER], 
            //     0, 12, 2, 0, 0, &font_colormap_std, 0, str_move_list_header);
            tbox_flush_set(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_DESCRIPTION], 0x00);
            tbox_tilemap_draw(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_DESCRIPTION]);
            tbox_flush_set(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES], 0x00);
            tbox_tilemap_draw(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES]);
            tbox_tilemap_draw(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES]);
            tbox_blit_move_info_icon(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES], 
                MOVE_INFO_POWER, 2, 0 * 13 + 2);
            tbox_blit_move_info_icon(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES], 
                MOVE_INFO_TYPE, 2, 1 * 13 + 2);
            tbox_blit_move_info_icon(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES], 
                MOVE_INFO_CATEGORY, 2, 2 * 13 + 2);
            tbox_blit_move_info_icon(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES], 
                MOVE_INFO_ACCURACY, 2, 3 * 13 + 2);
            tbox_blit_move_info_icon(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES], 
                MOVE_INFO_PP, 2, 4 * 13 + 2);
            tbox_blit_move_info_icon(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES], 
                MOVE_INFO_EFFECT, 2, 5 * 13 + 2);
            tbox_sync(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES], TBOX_SYNC_SET);
            pokedex_entry_state->page_initialization_state++;
            break;
        }
        case POKEDEX_ENTRY_PAGE_MOVE_LIST_INITIALIZATION_STATE_SETUP_LIST: {
            // Set up the level-up move list of a pokemon
            u16 num_moves = 0;
            const pokemon_move *moves = pokemon_moves[pokedex_entry_state->species];
            while(moves[num_moves].move_id != 511) {
                num_moves++;
            }
            pokedex_entry_state->move_list_size = num_moves;
            pokedex_entry_state->move_list_items = malloc(sizeof(list_menu_item) * (num_moves));
            pokedex_entry_state->move_list_strs = malloc(sizeof(u8) * (num_moves * POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_CHARS));
            for (size_t i = 0; i < num_moves; i++) {
                itoa(buffer0, moves[i].level,
                    ITOA_PAD_SPACES, 2);
                strcpy(buffer1, attack_names[moves[i].move_id]);
                string_decrypt(pokedex_entry_state->move_list_strs + i * POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_CHARS, 
                    moves[i].level == 0 ? str_move_move_list_evolution : str_move_move_list_level);
                pokedex_entry_state->move_list_items[i] = (list_menu_item) {
                    .idx = moves[i].move_id,
                    .text = pokedex_entry_state->move_list_strs + i * POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_CHARS,
                };
            }
            gp_list_menu_template = move_list_list_menu_template;
            gp_list_menu_template.items = pokedex_entry_state->move_list_items;
            gp_list_menu_template.item_cnt = num_moves;
            gp_list_menu_template.tbox_idx = pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_LIST];
            DEBUG("List menu template at tbox idx %d\n", gp_list_menu_template.tbox_idx);
            pokedex_entry_state->list_menu_move_list_cb_idx = list_menu_new(&gp_list_menu_template, pokedex_entry_state->cursor_position_move_list, 0);
            pokedex_entry_state->page_initialization_state++;
            break;
        }
        case POKEDEX_ENTRY_PAGE_MOVE_LIST_INITIALIZATION_STATE_SETUP_SCROLL_INDICATORS: {
            scroll_indicator_template crafting_ui_scroll_indicator_template_up_down = {
                .arrow0_type = SCROLL_ARROW_UP, .arrow0_x = 25 * 8, .arrow0_y = 24,
                .arrow1_type = SCROLL_ARROW_DOWN, .arrow1_x = 25 * 8, .arrow1_y = 24 + 8 * 10,
                .arrow0_threshold = 0, 
                .arrow1_threshold = (u16) MAX(0, (pokedex_entry_state->move_list_size - 
                    move_list_list_menu_template.max_items_showed)),
                .tiles_tag = 111,
                .pal_tag = 111,
            };
            pokedex_entry_state->move_list_scroll_indicators_cb_idx = scroll_indicator_new(&crafting_ui_scroll_indicator_template_up_down, 
                &pokedex_entry_state->cursor_position_move_list);
            pokedex_entry_state->page_initialization_state++;
            FALL_THROUGH;
        }
        default:
            return false;
    }
    return true;
}

void pokedex_entry_page_move_list_destroy() {
    pokedex_entry_page_free_tboxes();
    free(pokedex_entry_state->move_list_items);
    free(pokedex_entry_state->move_list_strs);
    if (pokedex_entry_state->move_list_scroll_indicators_cb_idx != 0xFF) {
        scroll_indicator_delete(pokedex_entry_state->move_list_scroll_indicators_cb_idx);
        pokedex_entry_state->move_list_scroll_indicators_cb_idx = 0xFF;
    }
}

bool pokedex_entry_page_move_list_handle_inputs(u8 self) {
    if (fading_control.active || dma3_busy(-1)) {
        return false;
    }
    int input = list_menu_process_input(pokedex_entry_state->list_menu_move_list_cb_idx);
    list_menu_get_scroll_and_row(pokedex_entry_state->list_menu_move_list_cb_idx, 
        &pokedex_entry_state->cursor_position_move_list, &pokedex_entry_state->items_above_move_list);
    switch (input) {
        case -2:
        case -1:
            return false;
        default:
            return true;
    }
    (void)self;
}