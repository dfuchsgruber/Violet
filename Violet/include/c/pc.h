#ifndef H_PC
#define H_PC

#include "constants/pc/pc_context_menu_items.h"
#include "constants/pc/pc_context_text_formats.h"
#include "constants/pc/pc_context_texts.h"
#include "constants/pc/pc_modes.h"
#include "constants/pc/pc_selection_contexts.h"
#include "list_menu.h"
#include "text.h"
#include "types.h"

typedef struct {
    u8 state;
    u8 mode;
    u8 continuation_type;
    u8 field_3;
    u8 callback_idx;
    u8 field_5[3171]; // TODO
    tboxdata context_menu_boxdata;
    list_menu_item context_menu_items[7];
    u8 context_menu_item_cnt;
    u8 context_menu_width;
    u8 field_3242[2];
    u8 context_menu_tbox_idx;
    u8 field_3245[53];
    u16 field_3298;
    u8 field_3300[5402];
    struct {
        u8 field_0[16];
    } field_8702[3];
    u8 field_8750[16526];

} pc_state_t;

extern pc_state_t *pc_state;

typedef struct {
    u8 *text;
    int format;
} pc_context_text_t;

extern u8 pc_slot_in_box;
extern u8 pc_last_used_mode;

/**
 * Initializes the pc.
 * @param mode the mode the pc is initialized with.
 */
void pc_initialize(u8 mode);

/**
 * Handles the context for the cursor being on a box pokémon.
 */
void pc_handle_context_on_pokemon();

/**
 * Prints the text to the current context menu.
 * @param text the text to print
 */
void pc_context_menu_print_text(u8 text);

/**
 * Adds a new item to the context list
 * @param item the item to add
 */
void pc_context_menu_add_item(u8 item);

/**
 * TODO
 * @return TODO
 */
bool sub_0808f370();

/**
 * TODO
 * @return TODO
 */
bool sub_08096284();

/**
 * Resets the parameters for the context menu.
 */
void pc_context_menu_reset();

/**
 * Builds the context menu when A is pressed on a pokémon and the mode is moving items.
 * @return if the context menu was set up
 */
bool pc_context_menu_build_context_on_pokemon_move_items();

/**
 * Builds the context menu when A is pressed on a pokémon and the mode is not moving items
 * @return if the context menu was set up
 */
bool pc_context_menu_build_context_on_pokemon_dont_move_items();

/**
 * Uses the gplist_menu to show the pc's context menu.
 */
void pc_show_context_menu();

/**
 * Handles the inputs of the pc context menu and returns the index of the selected item.
 * @return the idx of the selected item, -1 on "back" and -2 on "no action"
 */
int pc_context_menu_handle_inputs();

/**
 * Flushes the context menu.
 */
void pc_context_menu_flush();

/**
 * Sets the callback that handles the pc state
 * @param callback the callback that handles the pc state
 */
void pc_set_callback(void (*callback)(u8));

/**
 * Standard callback for the pc state.
 * @param self self-reference
 */
void pc_callback(u8 self);

/**
 * Callback that initializes the summary of a pokémon.
 * @param self self-reference
 */
void pc_callback_show_summary(u8 self);

/**
 * Shows a yes / no context menu using the gplist.
 * @param cursor_delta how much the cursor is supposed to be moved, (starting position is always "No", i.e. idx 1)
 */
void pc_show_yes_no(int cursor_delta);

/**
 * Gets the index of the last used / current pc box
 * @return index of the last used / current pc box
 */
u8 pc_box_idx_get();

/**
 * Starts the closing animation for the pc
 * @param a TODO
 * @param b TODO
 * @param c TODO
 */
void pc_close_animation_start(u16 a, u16 b, u8 c);

/**
 * Checks if the pc close animation is currently active.
 * @return if the close animation is currently running.
 */
bool pc_close_animation_is_running();

/**
 * Updates flags and vars when closing the pc.
 */
void pc_close_update_flags_and_vars();

/**
 * Executes a continuation based on the continuation type and state of the pc
 * after it was closed.
 * @param self self-reference
 */
void pc_close_continuation(u8 self);

/**
 * Callback1 that exits the pc and reloads the overworld.
 */
void pc_exit();

/**
 * Gets the mode the pc was launched in
 * @return the pc mode
 */
u8 pc_get_mode();

/**
 * Overworld continuation after the pc was exited, that reinitializes the selection to which pc mode to enter
 */
void pc_reinitialize_selection();

/**
 * Gets the species of the slot currently selected in the pc (may be in the team or on the box).
 * @return the currently selected species
 */
u16 pc_get_current_species();

#endif
