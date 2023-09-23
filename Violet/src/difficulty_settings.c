#include "types.h"
#include "oam.h"
#include "bg.h"
#include "text.h"
#include "callbacks.h"
#include "fading.h"
#include "save.h"
#include "agbmemory.h"
#include "difficulty_settings.h"
#include "overworld/map_control.h"
#include "dma.h"
#include "bios.h"
#include "vars.h"
#include "debug.h"
#include "language.h"
#include "io.h"
#include "menu_indicators.h"
#include "music.h"
#include "list_menu.h"
#include "new_game.h"

EWRAM difficulty_settings_state_t *difficulty_settings_state = NULL;

enum {
    TBOX_TEXT,
    TBOX_DIFFICULTY,
    TBOX_LIST,
    NUM_TBOXES,
};

static const bg_config bg_configs[] = {
    {.bg_id = 0, .char_base = 0, .map_base = 31, .priority = 0, .size = 0, .color_mode = 0,},
    {.bg_id = 1, .char_base = 2, .map_base = 30, .priority = 1, .size = 0, .color_mode = 0,},
    {.bg_id = 2, .char_base = 0, .map_base = 29, .priority = 2, .size = 0, .color_mode = 0,},
    {.bg_id = 3, .char_base = 1, .map_base = 28, .priority = 3, .size = 0, .color_mode = 0,},
};

static const tboxdata difficulty_settings_tboxes[NUM_TBOXES + 1] = {
    [TBOX_LIST] = {.bg_id = 2, .x = 2, .y = 1, .w = 18, .h = DIFFICULTY_LIST_MAX_TEXT_HEIGHT, .start_tile = 1, .pal = DIFFICULTY_SETTINGS_MESSAGE_PAL_IDX},
    [TBOX_DIFFICULTY] = {.bg_id = 0, .x = 21, .y = 5, .w = 7, .h = 2, .pal = DIFFICULTY_SETTINGS_MESSAGE_PAL_IDX, .start_tile = 1 + 18 * DIFFICULTY_LIST_MAX_TEXT_HEIGHT},   
    [TBOX_TEXT] = {.bg_id = 0, .x = 2, .y = 15, .w = 26, .h = 5, .pal = DIFFICULTY_SETTINGS_SET_STYLE_PAL_IDX, .start_tile = 1 + 18 * DIFFICULTY_LIST_MAX_TEXT_HEIGHT + 7 * 2},
    [NUM_TBOXES] = TBOX_SETUP_TAIL,    
};

extern const LZ77COMPRESSED gfx_difficulty_settingTiles;
extern const LZ77COMPRESSED gfx_difficulty_settingMap;
extern const LZ77COMPRESSED gfx_difficulty_settingPal;
extern const LZ77COMPRESSED gfx_difficulty_setting_linesTiles;
extern const LZ77COMPRESSED gfx_difficulty_setting_linesMap;
extern const LZ77COMPRESSED gfx_difficulty_setting_linesPal;

static void difficulty_settings_list_set_bg_v_offset() {
    io_set(IO_BGVOFS(2), (u16)((difficulty_settings_state->list_offset * 16 + difficulty_settings_state->list_pixel_offset)));
    io_set(IO_BGVOFS(3), (u16)(16 + difficulty_settings_state->list_pixel_offset));
}

static void difficulty_settings_cb1(){
    big_callback_proceed();
    tbox_proceed();
    oam_animations_proceed();
    oam_proceed();
    bg_virtual_sync_reqeust_proceed();
    fading_proceed();
    difficulty_settings_list_set_bg_v_offset();
}

static void difficulty_settings_vblank_handler() {
    oam_attributes_copy();
    graphic_queue_proceed();
    pal_proceed();
    dma0_proceed();
    dma3_queue_proceed();
}


const u8 str_description[] = LANGDEP(
    PSTRING("Wähle den Schwierigkeitsgrad aus, in\ndem du das Spiel spielen möchtest."),
    PSTRING("Choose the difficulty in which to\nplay the game.")
);

static const tbox_font_colormap font_colors_text = {.background = 0, .body = 1, .edge = 2}; 

static void difficulty_settings_print_description() {
    tbox_flush_set(TBOX_TEXT, 0x00);
    tbox_print_string(TBOX_TEXT, 2, 0, 6, 0, 0, &font_colors_text, 0, str_description);
}

static const u8 str_easy[] = LANGDEP(PSTRING("Leicht"), PSTRING("Easy"));
static const u8 str_normal[] = LANGDEP(PSTRING("Normal"), PSTRING("Normal"));
static const u8 str_hard[] = LANGDEP(PSTRING("Schwer"), PSTRING("Hard"));

static const u8 *const str_difficulties[NUM_DIFFICULTIES]  = {
    [DIFFICULTY_NORMAL] = str_normal,
    [DIFFICULTY_EASY] = str_easy,
    [DIFFICULTY_HARD] = str_hard,
};

static const u8 str_description_hard[] = LANGDEP(
    PSTRING("× Wilde PKMN können fliehen\n× Radar PKMN fliehen oft\n× Höherer Geldverlust\n× Weniger Preisgeld\n× Weniger EP\n× Größeres Arenaleiter-Team\n× Höheres Gegnerlevel\n× Zusätzliche Trainer-Items\n× Zufällige Teamreihenfolge\n× Mehr Fleiß-Punkte (Genger)"),
    PSTRING("× Wild PKMN may flee\n× Radar PKMN flee more ofen\n× Higher money loss on defeat\n× Less price money\n× Less experience points\n× Bigger gym leader parties\n× Higher foe level\n× Additional trainer items\n× Shuffled trainer parties\n× Foes use more effort values")
);

static const u8 str_description_easy[] = LANGDEP(
    PSTRING("× Geringerer Geldverlust\n× Mehr Preisgeld\n× Mehr EP\n× Keine Arena-Rückkämpfe\n× Schwächere Arenaleiter"),
    PSTRING("× Lower money loss on defeat\n× More price money\n× More experience points\n× No gym rematches\n× Weaker gym leader parties")
);

static const u8 str_description_normal[] = LANGDEP(
    PSTRING("\n\n    Keine Modifkationen"),
    PSTRING("\n\n    No modifications")
);

static const u8 *const str_descriptions[NUM_DIFFICULTIES] = {
    [DIFFICULTY_NORMAL] = str_description_normal,
    [DIFFICULTY_EASY] = str_description_easy,
    [DIFFICULTY_HARD] = str_description_hard,
};

static const tbox_font_colormap font_colors_difficulty = {.background = 0, .body = 2, .edge = 3};

static void difficulty_settings_print_difficulty() {
    tbox_flush_set(TBOX_DIFFICULTY, 0x00);
    const u8 *str = str_difficulties[*var_access(DIFFICULTY)];
    int pos = (8 * difficulty_settings_tboxes[TBOX_DIFFICULTY].w - string_get_width(2, str, 0)) / 2;
    tbox_print_string(TBOX_DIFFICULTY, 2, (u16)pos, 3, 0, 0, &font_colors_difficulty, 0, str);
}

static const u8 *difficulty_settings_get_list() {
    return str_descriptions[*var_access(DIFFICULTY)];
}

static void difficulty_settings_print_list() {
    tbox_flush_set(TBOX_LIST, 0x00);
    tbox_print_string(TBOX_LIST, 0, 0, 2, 0, 3, &font_colors_difficulty, 0, difficulty_settings_get_list());
}

static u16 difficulty_settings_list_count_lines(const u8 *str) {
    u16 num_lines = 1;
    for (int i = 0; str[i] != 0xFF; i++)
        if (str[i] == 0xFE)
            num_lines++;
    return num_lines;
}

static void difficulty_settings_scroll_indicators_list_new() {
    scroll_indicator_template template_list = {
        .arrow0_threshold = 0, 
        .arrow1_threshold = (u16)MAX(0, difficulty_settings_state->list_num_lines - DIFFICULTY_LIST_MAX_ITEMS_SHOWN), 
        .arrow0_type = SCROLL_ARROW_UP, .arrow1_type = SCROLL_ARROW_DOWN,
        .arrow0_x = 86, .arrow1_x = 86,
        .arrow0_y = 7, .arrow1_y = 92,
        .pal_tag = 112, .tiles_tag = 112,
    };
    DEBUG("List num lines %d\n", difficulty_settings_state->list_num_lines);
    difficulty_settings_state->scroll_indicator_list_cb_idx = scroll_indicator_new(&template_list,
        &difficulty_settings_state->list_offset);
}

static void difficulty_settings_scroll_indicators_difficulty_new() {
    scroll_indicator_template template_difficulty = {
        .arrow0_threshold = 0, .arrow1_threshold = NUM_DIFFICULTIES - 1, 
        .arrow0_type = SCROLL_ARROW_LEFT, .arrow1_type = SCROLL_ARROW_RIGHT,
        .arrow0_x = 165, .arrow1_x = 226,
        .arrow0_y = 50, .arrow1_y = 50,
        .pal_tag = 112, .tiles_tag = 112,
    };
    difficulty_settings_state->scroll_indicator_difficulty_cb_idx = scroll_indicator_new(&template_difficulty,
        &difficulty_settings_state->difficulty);

}

static void difficulty_settings_initialize_difficulty(u16 difficulty) {
    *var_access(DIFFICULTY) = difficulty;
    difficulty_settings_state->list_offset = 0;
    difficulty_settings_state->list_pixel_offset = 0;
    difficulty_settings_state->difficulty = difficulty;
    difficulty_settings_state->list_num_lines = (u8)difficulty_settings_list_count_lines(difficulty_settings_get_list());
    difficulty_settings_print_list();
    difficulty_settings_print_difficulty();
}
static void difficulity_settings_handle_input(u8 self);

static void difficulty_settings_scroll_list(u8 self) {
    if (big_callbacks[self].params[0]) { // Scroll down
        difficulty_settings_state->list_pixel_offset = (s8)(
            difficulty_settings_state->list_pixel_offset + 2);
    } else { // Scroll up
        difficulty_settings_state->list_pixel_offset = (s8)(
            difficulty_settings_state->list_pixel_offset - 2);
    }
    DEBUG("List offset %d, pixel offset %d\n", difficulty_settings_state->list_offset, difficulty_settings_state->list_pixel_offset);
    if (difficulty_settings_state->list_pixel_offset >= 16) {
        difficulty_settings_state->list_offset++;
        difficulty_settings_state->list_pixel_offset = 0;
        big_callbacks[self].function = difficulity_settings_handle_input;
    } else if (difficulty_settings_state->list_pixel_offset <= -16) {
        difficulty_settings_state->list_offset--;
        difficulty_settings_state->list_pixel_offset = 0;
        big_callbacks[self].function = difficulity_settings_handle_input;
    }
}

static void difficulty_settings_update_difficulty(u8 self) {
    u16 *state = big_callbacks[self].params + 1;
    switch (*state) {
        case 0:
            difficulty_settings_initialize_difficulty(difficulty_settings_state->difficulty);
            (*state)++;
            break;
        case 1:
            if (!dma3_busy(-1)) {
                bg_update_and_show(2);
                bg_display_sync();
                difficulty_settings_scroll_indicators_list_new();
                big_callbacks[self].function = difficulity_settings_handle_input;
                (*state)++;
            }
            break;
    }
}

static void difficulty_settings_free() {
    scroll_indicator_delete(difficulty_settings_state->scroll_indicator_difficulty_cb_idx);
    scroll_indicator_delete(difficulty_settings_state->scroll_indicator_list_cb_idx);
    free(difficulty_settings_state->bg_0_map);
    free(difficulty_settings_state->bg_1_map);
    free(difficulty_settings_state->bg_2_map);
    free(difficulty_settings_state->bg_3_map);
    free(difficulty_settings_state);
}

static void difficulty_settings_wait_fadescreen_and_free_and_new_game(u8 self) {
    if (!fading_control.active) {
        difficulty_settings_free();
        callback1_set(new_game_callback1);
        big_callback_delete(self);
    }
}

static void difficulty_settings_confirm_yes(u8 self) {
    fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
    big_callbacks[self].function = difficulty_settings_wait_fadescreen_and_free_and_new_game;
}

static void difficulty_settings_confirm_no(u8 self) {
    difficulty_settings_print_description();
    big_callbacks[self].function = difficulity_settings_handle_input;
}

static const yes_no_box_callbacks_t yes_no_menu_confirmation = {
    .no_callback = difficulty_settings_confirm_no,
    .yes_callback = difficulty_settings_confirm_yes,
};


static void difficulty_settings_wait_for_confirmation_text(u8 self) {
    if (!tbox_printer_is_active(TBOX_TEXT)) {
        const tboxdata template = {.bg_id = 0, .h = 2 * 2, .w = 5, .x = 30 - 5 - 1, .y = (u8)(20 - 1 - (2 * 2) - 5), .pal = 14, .start_tile = 320};
        gp_list_menu_yes_no_new_with_callbacks(self, &template, 2, 0, 0, DIFFICULTY_SETTINGS_START_TILE_BORDER_SET_STYLE, DIFFICULTY_SETTINGS_SET_STYLE_PAL_IDX, 
            &yes_no_menu_confirmation);
    }
}

static const u8 str_confirm[] = LANGDEP(
    PSTRING("Diese Einstellung ist endgültig und\nkann später nicht verändert werden.\pDas Spiel auf BUFFER_1 spielen?"),
    PSTRING("This setting is final and can not\nbe changed later on.\pPlay the game on BUFFER_1?")
);

static void difficulity_settings_handle_input(u8 self) {
    if (fading_control.active)
        return;
    if (super.keys.keys.down && 
            difficulty_settings_state->list_offset < difficulty_settings_state->list_num_lines - DIFFICULTY_LIST_MAX_ITEMS_SHOWN) {
        big_callbacks[self].function = difficulty_settings_scroll_list;
        big_callbacks[self].params[0] = true;
        
    } else if (super.keys.keys.up &&
            difficulty_settings_state->list_offset > 0) {
        big_callbacks[self].function = difficulty_settings_scroll_list;
        big_callbacks[self].params[0] = false;
    } else if (super.keys_new.keys.left && difficulty_settings_state->difficulty > 0) {
        play_sound(5);
        bg_hide(2);
        bg_display_sync();
        scroll_indicator_delete(difficulty_settings_state->scroll_indicator_list_cb_idx);
        difficulty_settings_state->difficulty--;
        big_callbacks[self].function = difficulty_settings_update_difficulty;
        big_callbacks[self].params[1] = 0;
    } else if (super.keys_new.keys.right && difficulty_settings_state->difficulty < NUM_DIFFICULTIES - 1) {
        play_sound(5);
        bg_hide(2);
        bg_display_sync();
        scroll_indicator_delete(difficulty_settings_state->scroll_indicator_list_cb_idx);
        difficulty_settings_state->difficulty++;
        big_callbacks[self].function = difficulty_settings_update_difficulty;
        big_callbacks[self].params[1] = 0;
    } else if (super.keys_new.keys.A) {
        strcpy(buffer0, str_difficulties[*var_access(DIFFICULTY)]);
        string_decrypt(strbuf, str_confirm);
        tbox_flush_set(TBOX_TEXT, 0x00);
        tbox_print_string(TBOX_TEXT, 2, 0, 6, 0, 0, &font_colors_text, tbox_get_set_speed(), strbuf);
        big_callbacks[self].function = difficulty_settings_wait_for_confirmation_text;
    }
}


enum {
    FREE_OVERWORLD = 0,
    SETUP_DATA,
    SETUP_TBOXES,
    LOAD_GFX,
    LOAD_DIFFICULTY,
    LOAD_SCROLL_INDICATORS,
    SHOW_BGS,
    FADE_IN,
};

void difficulty_settings_ui_initialize_callback() {
    switch (difficulty_settings_state->state) {
        case FREE_OVERWORLD:
            fading_control.buffer_transfer_disabled = true;
            // overworld_free();
            big_callback_delete_all();
            oam_reset();
            oam_palette_allocation_reset();
            dma0_reset_callback();
            tbox_free_all();
            bg_vritual_sync_reset();
            difficulty_settings_state->state++;
            break;
        case SETUP_DATA:
            *var_access(DIFFICULTY) = DIFFICULTY_NORMAL;
            bg_reset_control_and_displacement();
            bg_reset_scroll();
            bg_reset(0);
            bg_setup(0, bg_configs, ARRAY_COUNT(bg_configs));
            difficulty_settings_state->bg_0_map = malloc_and_clear(0x800);
            difficulty_settings_state->bg_1_map = malloc_and_clear(0x800);
            difficulty_settings_state->bg_2_map = malloc_and_clear(0x800);
            difficulty_settings_state->bg_3_map = malloc_and_clear(0x800);
            bg_set_tilemap(0, difficulty_settings_state->bg_0_map);
            bg_set_tilemap(1, difficulty_settings_state->bg_1_map);
            bg_set_tilemap(2, difficulty_settings_state->bg_2_map);
            bg_set_tilemap(3, difficulty_settings_state->bg_3_map);
            // io_set(IO_DISPCNT, (u16)(io_get(IO_DISPCNT) | IO_DISPCNT_WIN0));
            // io_set(IO_WIN0H, 
            //     (u16)IO_WINH(8 * difficulty_settings_tboxes[TBOX_LIST].x, 
            //             8 * (difficulty_settings_tboxes[TBOX_LIST].x + difficulty_settings_tboxes[TBOX_LIST].w)));
            // io_set(IO_WIN0V, (u16)IO_WINH(8 * difficulty_settings_tboxes[TBOX_LIST].y + 2, 
            //             8 * difficulty_settings_tboxes[TBOX_LIST].x + DIFFICULTY_LIST_HEIGHT - 6));
            // io_set(IO_WININ, 
            //     IO_WININOUT_BG(0, 0) | IO_WININOUT_BG(0, 1) | IO_WININOUT_BG(0, 2) | 
            //     IO_WININOUT_BG(0, 3) | IO_WININOUT_OBJ(0)  | IO_WININOUT_FX(0)); // All in window 0
            // io_set(IO_WINOUT,
            //     IO_WININOUT_BG(0, 0) | IO_WININOUT_BG(0, 1) | 
            //     IO_WININOUT_OBJ(0)  | IO_WININOUT_FX(0)); // All but bg2 and bg3 in window 0
            difficulty_settings_state->state++;
            break;
        case SETUP_TBOXES:
            tbox_sync_with_virtual_bg_and_init_all(difficulty_settings_tboxes);
            tbox_init_frame_set_style(TBOX_TEXT, DIFFICULTY_SETTINGS_START_TILE_BORDER_SET_STYLE, DIFFICULTY_SETTINGS_SET_STYLE_PAL_IDX);
            tbox_init_frame_message(TBOX_TEXT, DIFFICULTY_SETTINGS_START_TILE_BORDER_MESSAGE, DIFFICULTY_SETTINGS_MESSAGE_PAL_IDX);
            tbox_tilemap_draw(TBOX_TEXT);
            tbox_tilemap_draw(TBOX_DIFFICULTY);
            tbox_tilemap_draw(TBOX_LIST);
            difficulty_settings_state->state++;
            break;
        case LOAD_GFX:
            lz77uncompwram(gfx_difficulty_settingMap, difficulty_settings_state->bg_1_map);
            lz77uncompvram(gfx_difficulty_settingTiles, CHARBASE(2));
            pal_decompress(gfx_difficulty_settingPal, 0, 16 * sizeof(color_t));
            lz77uncompwram(gfx_difficulty_setting_linesMap, difficulty_settings_state->bg_3_map);
            lz77uncompvram(gfx_difficulty_setting_linesTiles, CHARBASE_PLUS_OFFSET_4BPP(1, DIFFICULTY_SETTINGS_LINES_CHARBASE_OFFSET));
            pal_decompress(gfx_difficulty_setting_linesPal, 16, 16 * sizeof(color_t));
            difficulty_settings_state->state++;
            break;
        case LOAD_DIFFICULTY:
            difficulty_settings_initialize_difficulty(DIFFICULTY_NORMAL);
            difficulty_settings_print_description();
            difficulty_settings_state->state++;
            break;
        case SHOW_BGS:
            bg_virtual_sync(0);
            bg_virtual_sync(1);
            bg_virtual_sync(2);
            bg_virtual_sync(3);
            bg_sync_display_and_show(0);
            bg_sync_display_and_show(1);
            bg_sync_display_and_show(2);
            bg_sync_display_and_show(3);
            io_set(IO_DISPCNT, IO_DISPCNT_OAM_CHARACTER_MAPPING_ONE_DIMENSIONAL | IO_DISPCNT_OBJ);
            bg_display_sync();
            difficulty_settings_state->state++;
            break;
        case LOAD_SCROLL_INDICATORS: {
            difficulty_settings_scroll_indicators_list_new();
            difficulty_settings_scroll_indicators_difficulty_new();
            difficulty_settings_state->state++;
            break;
        }
        case FADE_IN:
            big_callback_new(difficulity_settings_handle_input, 0);
            pal_set_all_to_black();
            fading_control.buffer_transfer_disabled = false;
            fadescreen(0xFFFFFFFF, 0, 16, 0, 0);
            callback1_set(difficulty_settings_cb1);
            difficulty_settings_state->state++;
            break;
    }
}

void difficulty_settings_ui_initialize() {
    difficulty_settings_state = (difficulty_settings_state_t*) malloc_and_clear(sizeof(difficulty_settings_state_t));
    difficulty_settings_state->state = FREE_OVERWORLD;
    vblank_handler_set(difficulty_settings_vblank_handler);
    callback1_set(difficulty_settings_ui_initialize_callback);
}

void difficulty_settings_wait_fadescreen_and_initialize() {
    generic_callback1();
    if (!fading_control.active)
        difficulty_settings_ui_initialize();
}

void difficulty_settings_ui_test() {
    fadescreen_all(FADE_TO_BLACK, 0);
    callback1_set(difficulty_settings_wait_fadescreen_and_initialize);
}