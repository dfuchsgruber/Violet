#ifndef H_MENU_INDICATORS
#define H_MENU_INDICATORS

#include "types.h"

enum {
    SCROLL_ARROW_LEFT,
    SCROLL_ARROW_RIGHT,
    SCROLL_ARROW_UP,
    SCROLL_ARROW_DOWN,
};

typedef struct {
    u8 arrow0_type;
    u8 arrow0_x;
    u8 arrow0_y;
    u8 arrow1_type;
    u8 arrow1_x;
    u8 arrow1_y;
    u16 arrow0_threshold;
    u16 arrow1_threshold;
    u16 tiles_tag;
    u16 pal_tag;
    u8 pal_num;
} scroll_indicator_template;

typedef struct {
    u8 field_0;
    u16 *cursor_position;
    u16 arrow0_threshold;
    u16 arrow1_threshold;
    u8 arrow0_oam_idx;
    u8 arrow1_oam_idx;
    u16 tiles_tag;
    u16 pal_tag;
} scroll_indicator_state;

/**
 * Removes a scroll indicator arrow pair
 * @param callback_idx the callback of the scroll indicators
 */
void scroll_indicator_delete(u8 callback_idx);

/**
 * Creates indicators for scrolling (oams) and a task that animates them
 * @param template the template that describes how to create the indicators
 * @param cursor_position offset of the cursor position
 * @return the idx of the created callback
 */
u8 scroll_indicator_new(const scroll_indicator_template *temp, u16 *cursor_position);

/**
 * Sets the priority of the scroll indicator sprites
 * @param callback_idx calllback for the scroll indicators
 * @param arrow0_priority the priority for the first arrow
 * @param arrow1_priority the priority for the second arrow
 */
void scroll_indicator_set_oam_priority(u8 callback_idx, u8 arrow0_priority, u8 arrow1_priority);

#endif
