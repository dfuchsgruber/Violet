#ifndef H_DIFFICULTY_SETTINGS
#define H_DIFFICULTY_SETTINGS

#include "types.h"
#include "oam.h"
#include "text.h"
#include "constants/difficulties.h"

#define DIFFICULTY_SETTINGS_LINES_CHARBASE_OFFSET 400

typedef struct {
    u8 state;
    u16 list_offset;
    s8 list_pixel_offset;
    u16 difficulty;
    u8 scroll_indicator_list_cb_idx;
    u8 scroll_indicator_difficulty_cb_idx;
    u8 list_num_lines;
    void *bg_0_map;
    void *bg_1_map;
    void *bg_2_map;
    void *bg_3_map;
} difficulty_settings_state_t;

extern EWRAM difficulty_settings_state_t *difficulty_settings_state;

#define DIFFICULTY_SETTINGS_START_TILE_BORDER_BASE (1023 - TBOX_FRAME_MESSAGE_NUM_TILES - TBOX_FRAME_SET_STYLE_NUM_TILES)
#define DIFFICULTY_SETTINGS_START_TILE_BORDER_MESSAGE (DIFFICULTY_SETTINGS_START_TILE_BORDER_BASE)
#define DIFFICULTY_SETTINGS_START_TILE_BORDER_SET_STYLE (DIFFICULTY_SETTINGS_START_TILE_BORDER_BASE + TBOX_FRAME_MESSAGE_NUM_TILES)
#define DIFFICULTY_SETTINGS_SET_STYLE_PAL_IDX 14
#define DIFFICULTY_SETTINGS_MESSAGE_PAL_IDX 15

// BG2 displays the descriptive list in a window.
// DIFFICULTY_LIST_HEIGHT defines the height of the window (WIN0) in pixels
// DIFFICULTY_LIST_MAX_TEXT_HEIGHT is the height of the tbox on bg2 (in tiles)
#define DIFFICULTY_LIST_HEIGHT 80
#define DIFFICULTY_LIST_MAX_TEXT_HEIGHT 32
#define DIFFICULTY_LIST_MAX_ITEMS_SHOWN 5

#endif