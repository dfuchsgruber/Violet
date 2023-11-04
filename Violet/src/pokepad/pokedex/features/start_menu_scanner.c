#include "types.h"
#include "pokepad/pokedex/scanner.h"
#include "agbmemory.h"
#include "pokemon/sprites.h"
#include "debug.h"
#include "bios.h"
#include "language.h"
#include "pokepad/pokedex/operator.h"
#include "menu_indicators.h"
#include "music.h"
#include "options.h"
#include "flags.h"

#define PAL_TAG_GFX_MENU_SCANNER 0xC29B
#define START_MENU_SCANNER_MAX_NUM_ICONS_PER_LINE 9

EWRAM u8 start_menu_scanner_tbox_idx = 0xFF;
EWRAM u8 start_menu_scanner_title_tbox_idx = 0xFF;
EWRAM __attribute__((aligned(2))) u16 start_menu_scanner_tbox_cursor = 0;
EWRAM u8 start_menu_scanner_cb_idx_scroll_indicators = 0xFF;
EWRAM __attribute__((aligned(4))) pokedex_scanner_unique_species_list_t *start_menu_scanner_list = NULL;

static const tboxdata tbox_template_start_menu_scanner = {
    .bg_id = 0, .x = 0, .y = 16, .w = 30, .h = 4, .pal = 13, .start_tile = 542 + 11 * 2,
};

static const tboxdata tbox_template_start_menu_scanner_title = {
    .bg_id = 0, .x = 1, .y = 13, .w = 11, .h = 2, .pal = 15, .start_tile = 542,
};

static const u8 str_scanner_header[] = LANGDEP(
    PSTRING("Gefangen: FONT_SIZE_SMALLBUFFER_1SKIP\x01/SKIP\x01BUFFER_2"),
    PSTRING("Caught: FONT_SIZE_SMALLBUFFER_1SKIP\x01/SKIP\x01BUFFER_2")
);

static const tbox_font_colormap fontcolmap_scanner_header = {
    .background = 1, .body = 2, .shadow = 3,
};

extern const u8 gfx_start_menu_scanner_frameTiles[];
extern const u8 gfx_start_menu_scanner_pokeballTiles[];
extern const u8 gfx_start_menu_scanner_framePal[];

static bool start_menu_scanner_available() {
    return checkflag(FLAG_POKEDEX_SCANNER) && options[OPTION_START_MENU_SCANNER].getter() == OPTION_ON;
}

static void start_menu_redraw_scanner() {
    // tbox_flush_set(start_menu_scanner_tbox_idx, 0xFF);
    tbox_blit(start_menu_scanner_tbox_idx, gfx_start_menu_scanner_frameTiles, 0, 0, 240, 32, 0, 0, 240, 32);
    if (start_menu_scanner_list) {
        for (size_t i = start_menu_scanner_tbox_cursor; 
                i < (size_t)(start_menu_scanner_tbox_cursor + START_MENU_SCANNER_MAX_NUM_ICONS_PER_LINE) &&
                i < start_menu_scanner_list->size; i++) {
            u16 species = start_menu_scanner_list->list[i].species;
            DEBUG("At %d, species %d\n", i, species);
            if (!start_menu_scanner_list->list[i].is_seen)
                species = 0;
            u16 x = (u16)(((i - start_menu_scanner_tbox_cursor) % START_MENU_SCANNER_MAX_NUM_ICONS_PER_LINE) * 24 + 6);
            u16 y = (u16)(((i - start_menu_scanner_tbox_cursor) / START_MENU_SCANNER_MAX_NUM_ICONS_PER_LINE) * 16 + 6);
            tbox_blit(start_menu_scanner_tbox_idx, pokemon_icons_greyscale[species], 0, 8, 32, 24,
                x, y, 32, 32);
            if (start_menu_scanner_list->list[i].is_caught || true) {
                tbox_blit(start_menu_scanner_tbox_idx, gfx_start_menu_scanner_pokeballTiles, 0, 0, 16, 16, 
                (u16)(x + 16), (u16)(y + 14), 16, 16);
            }
        }
    }
    tbox_copy_to_vram(start_menu_scanner_tbox_idx, TBOX_COPY_TILESET);
}

void start_menu_scanner_move_cursor(s8 delta) {
    if (!start_menu_scanner_active() || !start_menu_scanner_list)
        return;
    int cursor_new = MIN(MAX(0, start_menu_scanner_tbox_cursor + delta), 
        (int)start_menu_scanner_list->size - START_MENU_SCANNER_MAX_NUM_ICONS_PER_LINE);
    if (cursor_new != start_menu_scanner_tbox_cursor) {
        start_menu_scanner_tbox_cursor = (u16)cursor_new;
        start_menu_redraw_scanner();
        play_sound(5);
    }
    DEBUG("Cursor now at %d. Threshold %d\n", start_menu_scanner_tbox_cursor, 
        (u16)MAX(0, (int)start_menu_scanner_list->size - START_MENU_SCANNER_MAX_NUM_ICONS_PER_LINE));
}

static void start_menu_setup_scroll_indicators() {
    scroll_indicator_template scroll_indicator_template_scanner = {
        .arrow0_threshold = 0, 
        .arrow1_threshold = (u16)MAX(0, (int)start_menu_scanner_list->size - START_MENU_SCANNER_MAX_NUM_ICONS_PER_LINE), 
        .arrow0_type = SCROLL_ARROW_LEFT, .arrow1_type = SCROLL_ARROW_RIGHT,
        .arrow0_x = 8, .arrow1_x = 232,
        .arrow0_y = 146, .arrow1_y = 146,
        .pal_tag = 112, .tiles_tag = 112,
    };
    DEBUG("Setup with threshold %d\n", scroll_indicator_template_scanner.arrow1_threshold);
    start_menu_scanner_cb_idx_scroll_indicators = scroll_indicator_new(&scroll_indicator_template_scanner, &start_menu_scanner_tbox_cursor);
}

static void start_menu_scanner_sort_list(pokedex_scanner_unique_species_list_t *list) {
    // Insertion sort to prioritze uncaught over unseen over other species
    for (int i = 1; i < (int)list->size; i++) {
        pokedex_scanner_unique_species_entry_t key = list->list[i];
        int j = i - 1;
        while (j >= 0 && list->list[j].is_caught && !key.is_caught) {
            list->list[j + 1] = list->list[j];
            j--;
        }
        while (j >= 0 && list->list[j].is_seen && !key.is_seen) {
            list->list[j + 1] = list->list[j];
            j--;
        }
        list->list[j + 1] = key;
    }
}

void start_menu_print_scanner() {
    start_menu_scanner_tbox_idx = 0xFF;
    start_menu_scanner_title_tbox_idx = 0xFF;
    start_menu_scanner_cb_idx_scroll_indicators = 0xFF;
    start_menu_scanner_tbox_cursor = 0;
    start_menu_scanner_list = NULL;
    if (!start_menu_scanner_available())
        return;
    pokedex_scanner_data_t *data = malloc(sizeof(pokedex_scanner_data_t));
    if (data) {
        start_menu_scanner_list = malloc(sizeof(pokedex_scanner_unique_species_list_t));
        DEBUG("Scanner list at 0x%x, of size %d\n", start_menu_scanner_list, sizeof(pokedex_scanner_unique_species_list_t));
        if (start_menu_scanner_list) {
            pokedex_feature_scanner_build_all_entries(data, map_wild_pokemon_get_current());
            pokedex_scanner_build_unique_species(start_menu_scanner_list, data);
            if (start_menu_scanner_list->size) {
                start_menu_scanner_sort_list(start_menu_scanner_list);
                start_menu_setup_scroll_indicators();
                pal_copy(gfx_start_menu_scanner_framePal, 13 * 16, 16 * sizeof(color_t));
                start_menu_scanner_tbox_idx = tbox_new(&tbox_template_start_menu_scanner);
                tbox_tilemap_draw(start_menu_scanner_tbox_idx);
                start_menu_redraw_scanner();
                start_menu_scanner_title_tbox_idx = tbox_new(&tbox_template_start_menu_scanner_title);
                tbox_flush_set(start_menu_scanner_title_tbox_idx, 0x11);
                tbox_tilemap_draw(start_menu_scanner_title_tbox_idx);
                size_t num_caught = 0;
                for (size_t i = 0; i < start_menu_scanner_list->size; i++) {
                    if (start_menu_scanner_list->list[i].is_caught)
                        num_caught++;
                }
                itoa(buffer0, (int)num_caught, ITOA_NO_PADDING, 3);
                itoa(buffer1, (int)start_menu_scanner_list->size, ITOA_NO_PADDING, 3);
                string_decrypt(strbuf, str_scanner_header);
                tbox_print_std_frame(start_menu_scanner_title_tbox_idx, false);
                tbox_print_string(start_menu_scanner_title_tbox_idx, 2, 
                    (u16)((8 * tbox_template_start_menu_scanner_title.w - string_get_width(2, strbuf, 0)) / 2), 
                    0, 0, 0, &fontcolmap_scanner_header, 0, strbuf);
            } else {
                free(start_menu_scanner_list);
                start_menu_scanner_list = NULL;
            }
        }
        free(data);
    }
}

void start_menu_clear_scanner() {
    if (start_menu_scanner_tbox_idx != 0xFF) {
        tbox_flush_map(start_menu_scanner_tbox_idx);
        tbox_free(start_menu_scanner_tbox_idx);
        start_menu_scanner_tbox_idx = 0xFF;
    }
    if (start_menu_scanner_title_tbox_idx != 0xFF) {
        tbox_flush_map_and_frame(start_menu_scanner_title_tbox_idx);
        tbox_free(start_menu_scanner_title_tbox_idx);
        start_menu_scanner_title_tbox_idx = 0xFF;
    }
    if (start_menu_scanner_cb_idx_scroll_indicators != 0xFF) {
        scroll_indicator_delete(start_menu_scanner_cb_idx_scroll_indicators);
        start_menu_scanner_cb_idx_scroll_indicators = 0xFF;
    }
    if (start_menu_scanner_list) {
        free(start_menu_scanner_list);
        start_menu_scanner_list = NULL;
    }
}

bool start_menu_scanner_active() {
    if (!start_menu_scanner_available())
        return false;
    bool has_entries = false;
    if (start_menu_scanner_list)
        has_entries = start_menu_scanner_list->size > 0;
    return has_entries;
}