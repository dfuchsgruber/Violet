#ifndef H_ITEM_BAG_2
#define H_ITEM_BAG_2

#include "types.h"
#include "bg.h"
#include "bag.h"
#include "save.h"
#include "list_menu.h"
#include "constants/item_pockets.h"
#include "text.h"
#include "text.h"

#define BAG_START_TILE_BORDER_BASE (1023 - TBOX_FRAME_STD_NUM_TILES - TBOX_FRAME_SET_STYLE_NUM_TILES - TBOX_FRAME_MESSAGE_NUM_TILES)
#define BAG_START_TILE_BORDER_STD (BAG_START_TILE_BORDER_BASE)
#define BAG_START_TILE_BORDER_SET_STYLE (BAG_START_TILE_BORDER_BASE + TBOX_FRAME_STD_NUM_TILES)
#define BAG_START_TILE_BORDER_MESSAGE (BAG_START_TILE_BORDER_BASE + TBOX_FRAME_STD_NUM_TILES + TBOX_FRAME_SET_STYLE_NUM_TILES)

#define BAG_PAL_IDX_BORDER_MESSAGE 12
#define BAG_PAL_IDX_BORDER_STD 13
#define BAG_PAL_IDX_SET_STYLE 14

enum {
    BAG_OPEN_ITEMS = 0,
    BAG_OPEN_KEYITEMS = 1,
    BAG_OPEN_POKEBALLS = 2,
    BAG_OPEN_LAST = 3,
    BAG_OPEN_TM_HM = 4,
    BAG_OPEN_BERRIES = 5,
    BAG_OPEN_BAIT = 6,
};

enum {
    BAG_CONTEXT_OVERWORLD = 0,
    BAG_CONTEXT_PARTY_GIVE,
    BAG_CONTEXT_SELL,
    BAG_CONTEXT_DEPOSIT,
    BAG_CONTEXT_BOX_GIVE,
    BAG_CONTEXT_BATTLE,
    BAG_CONTEXT_OLD_MAN,
    BAG_CONTEXT_TTVSCR_STATUS,
    BAG_CONTEXT_TTVSCR_CATCHING,
    BAG_CONTEXT_TTVSCR_REGISTER,
    BAG_CONTEXT_TTVSCR_TMS,
    BAG_CONTEXT_LAST,
    BAG_CONTEXT_RECHARGE_TM_HM,
    BAG_CONTEXT_COMPOST,
    BAG_CONTEXT_PLANT_BERRY,
    NUM_BAG_CONTEXTS,
};

enum {
    BAG_TBOX_POCKET_NAME,
    BAG_TBOX_DESCRIPTION,
    BAG_TBOX_HINT,
    BAG_TBOX_LIST,
    BAG_TBOX_MOVE_INFO,
    BAG_TBOX_CONTEXT_MENU_TEXT,
    BAG_TBOX_MESSAGE,
    BAG_TBOX_MESSAGE_WITH_YES_NO,
    NUM_BAG_TBOXES,
};

enum {
    BAG_CONTEXT_MENU_USE,
    BAG_CONTEXT_MENU_GIVE,
    BAG_CONTEXT_MENU_TOSS,
    BAG_CONTEXT_MENU_CANCEL,
    NUM_BAG_CONTEXT_MENU_ITEMS,
};

typedef struct {
    u8 initialization_state;
    u8 gfx_initialization_state;
    void (*internal_continuation)(); // Use this if you want to override the actual continuation (e.g. for giving an item)
    list_menu_item *list_menu_items;
    u8 (*list_menu_item_texts)[40];
    bg_tile (*bg0_map)[32];
    bg_tile (*bg1_map)[32];
    bg_tile (*bg2_map)[32];
    u8 oam_idx_bag;
    u8 oam_idx_item;
    u8 oam_idx_move_item_bar[9];
    u8 pal_idx_item;
    u16 oam_item_base_tile;
    u8 pocket_size[NUM_POCKETS];
    u8 pocket_max_shown[NUM_POCKETS];
    u8 idle_cb_idx;
    u8 list_menu_cb_idx;
    u8 scroll_indicator_items_cb_idx;
    u8 scroll_indicator_pockets_cb_idx;
    u8 pocket_switching_disabled;
    u8 is_moving_item;
    u16 moving_item_original_position;
    u8 context_menu_items[8];
    u8 num_context_menu_items;
    u8 tbox_context_menu;
    u8 tbox_quantity;
    u8 scroll_indicator_quantity_cb_idx;
    u16 toss_max_number;
    u16 toss_current_number;
} bag2_state_t;

#define BAG2_STATE ((bag2_state_t*)fmem.bag2_state)

#define BAG_OAM_TAG 0x3173
#define BAG_ITEM_OAM_TAG 0x3174
#define BAG_INSERT_OAM_TAG 0x3175

extern LZ77COMPRESSED gfx_bag_backgroundTiles;
extern LZ77COMPRESSED gfx_bag_backgroundMap;
extern LZ77COMPRESSED gfx_bag_backgroundPal;
extern LZ77COMPRESSED gfx_bag2Tiles;
extern LZ77COMPRESSED gfx_bag2Pal;
extern LZ77COMPRESSED gfx_bag_insert_barTiles;
extern LZ77COMPRESSED gfx_bag_insert_barPal;

// Textboxes in the bag ui
tboxdata bag_tboxes[NUM_BAG_TBOXES + 1];

graphic bag_graphic_bag;
graphic bag_graphic_insert_bar;
oam_template bag_oam_template;
oam_template bag_oam_template_item;

tbox_font_colormap bag_font_colormap_pocket_hint;
tbox_font_colormap bag_font_colormap_description;
tbox_font_colormap bag_font_colormap_std;

// Callbacks for selecting an item in a given bag context
void (*bag_item_selected_by_context[NUM_BAG_CONTEXTS])(u8);

/**
 * @brief Opens the bag menu
 * 
 * @param context In which context the bag is opened
 * @param open_which which pocket to open
 * @param continuation the continuation on close
 */
void bag_open(u8 context, u8 open_which, void (*continuation)());

/**
 * @brief Initializes the cursor positions for all pockets in the bag.
 * 
 */
void bag_initialize_list_cursor_positions();

/**
 * @brief Checks if items can be moved in the bag
 * 
 * @return true 
 * @return false 
 */
bool bag_can_items_be_moved();

/**
 * @brief Gets the current pocket in the bag. This is consistent with the constants (i.e. 1-based)
 * 
 * @return u8 The current pocket (1-based)
 */
u8 bag_get_current_pocket();

/**
 * @brief Prints the cursor of the item list in a pocket at a given position
 * 
 * @param y Where to print the cursor
 * @param color_idx In which color. 0xFF clears the cursor
 */
void bag_item_list_print_cursor_at(u16 y, u8 color_idx);

/**
 * @brief Prints the cursor of the item list at the cursor position of a list menu
 * 
 * @param list_menu_cb_idx The list menu
 * @param color_idx In which color. 0xFF clears the cursor
 */
void bag_item_list_print_cursor(u8 list_menu_cb_idx, u8 color_idx);

/**
 * @brief Starts moving a selected item (i.e. changing its slot / position)
 * 
 * @param cb_idx The input handling idle callback to replace
 * @param position The position of the item to move
 */
void bag_start_moving_item(u8 cb_idx, u16 position);

/**
 * @brief Callback1 that initializes the back step-wise (and is interrupted by link transfers)
 * 
 */
void bag_cb_initialize();

/**
 * @brief Callback to do the win0 animation for opening / closing the bag
 * 
 * @param self self-reference
 */
void bag_win0_animation(u8 self);

/**
 * @brief Deletes the scroll indicators for the items list
 * 
 */
void bag_delete_scroll_indicators_items();

/**
 * @brief Delets the scroll indicators for the pocket switching
 * 
 */
void bag_delete_scroll_indicators_pockets();

/**
 * @brief Gets the hint to display for the current bag context
 * 
 * @return u8* The hint
 */
u8 *bag_get_context_hint();

/**
 * @brief Default idle callback for handling bag input to scroll through a pocket etc.
 * 
 * @param self self-reference
 */
void bag_idle_callback_default(u8 self);

/**
 * @brief Standard callback1 for the bag
 * 
 */
void bag_cb1();

/**
 * @brief Standard vblank handler for the bag
 * 
 */
void bag_vblank_handler();

/**
 * @brief Gets the name of an item formatted to display in the bag list
 * 
 * @param dst where to put the string
 * @param item_idx the item to get, 0xFFFF corresponds to "cancel"
 */
void bag_format_item_string(u8 *dst, u16 item_idx);

/**
 * @brief Shakes the bag oam
 * 
 */
void bag_shake_oam();

/**
 * @brief Creates new scroll indicators for scrolling through items
 * 
 */
void bag_new_scroll_indicators_items();

/**
 * @brief Creates new scroll indicators for scrolling through pockets
 * 
 */
void bag_new_scroll_indicators_pockets();

/**
 * @brief Reloads an entire bag bocket (re-builds the item list and scroll indicators, etc.)
 * 
 */
void bag_load_pocket();

/**
 * @brief Switches to a bag pocket
 * 
 * @param self self-reference of the idle callback
 * @param pocket_idx_to the pocket to switch to (0-based)
 */
void bag_switch_pockets(u8 self, int pocket_idx_to);

/**
 * @brief Closes the bag and sets the continuation as callback1
 * 
 * @param cb_idx self-reference to the idle callback
 * @param item_result the item that was selected, executed, given, ...
 * @param set_bag_closed if the bag is closed (or just exited temporarily, e.g. for giving an item)
 */
void bag_close(u8 cb_idx, u16 item_result, bool set_bag_closed);

/**
 * @brief Prints a text in the hint textbox
 * 
 * @param hint The text to print
 */
void bag_print_hint(u8 *hint);

/**
 * @brief Prints the desription of an item based on where the cursor is
 * 
 * @param slot Where the cursor is
 */
void bag_print_item_description(u16 slot);

/**
 * @brief Updates the bag item based on where the cursor is
 * 
 * @param slot Where the cursor is
 */
void bag_update_item(u16 slot);

/**
 * @brief Builds the item list of the current bag pocket
 * 
 */
void bag_build_item_list();

/**
 * @brief Frees all resources of the bag.
 * 
 */
void bag_free();

/**
 * @brief Computes how many items there are in each pocket and also 
 * many items should be shown in the corresponding list menu
 * 
 */
void bag_initialize_compute_item_counts();

/**
 * @brief Starts the oam animation for switching bag pockets
 * 
 * @param pocket which pocket to switch to (1-based)
 */
void bag_oam_switch_pockets(u8 pocket);

/**
 * @brief Sorts a pocket (item list) using insertion sort (efficient on nearly-sorted arrays)
 * 
 * @param list the list to sort
 * @param size the size of the list
 * @param cmp a comparator that compares two item idxs a, b and outputs negative values if a < b, zero if a == b and positive values if a > b
 */
static inline void bag_sort_pocket(bag_item_t *list, size_t size, int (*cmp)(u16, u16)) {
	// This array is almost always nearly sorted -> insertion sort
	bag_item_t tmp;
	size_t j;
	for (size_t i = 1; i < size; i++) {
		tmp = list[i];
		j = i;
		while (j > 0 && cmp(list[j - 1].item_idx, tmp.item_idx) > 0) {
			list[j] = list[j - 1];
			j--;
		}
		list[j] = tmp;
	}
}

/**
 * @brief Sorts the tm/hm pocket.
 * 
 */
void bag_tm_hm_sort();

/**
 * @brief Gets the string of tms and hms to print in the bag
 * 
 * @param dst where to put the string
 * @param item_idx the item to query the name of
 */
void tm_hm_get_str_number_and_name(u8 *dst, u16 item_idx);

/**
 * @brief Prints the move info icons in the tm hm box
 * 
 */
void bag_tm_hm_pocket_load_move_info_icons();

/**
 * @brief Hides the move info icons int he tm hm box
 * 
 */
void bag_tm_hm_pocket_delete_move_info_icons();

/**
 * @brief Prints the move info values in the tm hm box
 * 
 * @param slot the slot in the pocket
 */
void bag_tm_hm_pocket_load_move_info(u16 slot);

/**
 * @brief Sorts the berries pocket.
 * 
 */
void bag_berries_sort();

/**
 * @brief Gets the name and number of a berry
 * 
 * @param dst where to put the string
 * @þaram item_idx the idx of the berry to get the number of 
 */
void berry_get_str_number_and_name(u8 *dst, u16 item_idx);

/**
 * @brief Function that reinitializes scroll menu indicators and then resumes the standard overworld (item use) idle callback
 * 
 * @param self self-reference
 */
void bag_reinitialize_scroll_menu_indicators_and_return_to_idle_callback(u8 self);

/**
 * @brief Reinitializes the list menu (also calculates the cursor positions), then calls `bag_reinitialize_scroll_menu_indicators_and_return_to_idle_callback`
 * 
 * @param self self-reference
 */
void bag_reinitialize_list_and_scroll_menu_indicators_and_return_to_idle_callback(u8 self);

/**
 * @brief Waits for the player to press A, plays the corresponding sound effect and then calls `bag_reinitialize_list_and_scroll_menu_indicators_and_return_to_idle_callback`
 * 
 * @param self self-reference
 */
void bag_wait_a_button_and_close_message_and_return_to_idle_callback(u8 self);

/**
 * @brief Redraws the description, then redraws the scroll menu indicators and then returns to the idle callback.
 * 
 * @param self 
 */
void bag_menu_cancel_redraw_description_and_scroll_menu_indicators_and_return_to_idle_callback(u8 self);

/**
 * @brief Gets the slot in the current pocket in the bag
 * 
 * @return u16 the slot
 */
u16 bag_get_current_slot_in_current_pocket() ;

/**
 * @brief Callback1 that initializes the bag2 at the last pocket in the last used context
 * 
 */
void bag2_return_to_last();

#endif