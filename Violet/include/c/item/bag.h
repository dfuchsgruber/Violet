#ifndef H_ITEM_BAG
#define H_ITEM_BAG

#include "types.h"

typedef struct {
    void (*callback)();
    u8 location;
    u8 is_open;
    u16 pocket;
    u16 items_above[3];
    u16 cursor_position[3];
} bag_state_t;

// Theoretically, there is now space for 8 pockets
#define MAX_NUM_POCKETS 8

extern bag_state_t bag_state;

typedef struct {
    u16 item_idx;
    u16 quantity;
} bag_item_t;

typedef struct {
    bag_item_t *items;
    u8 capacity;
} bag_pocket_t; 

extern bag_pocket_t bag_pockets[MAX_NUM_POCKETS];

#define POCKET_TO_BAG_POCKETS_IDX(pocket) ((u8)(pocket - 1))

#define MAX_NUM_PC_ITEMS      30
#define MAX_NUM_BAG_ITEMS     50
#define MAX_NUM_BAG_KEY_ITEMS  30
#define MAX_NUM_BAG_POKEBALLS 20
#define MAX_NUM_BAG_TM_HMS     58
#define MAX_NUM_BAG_BERRIES   44
#define MAX_NUM_BAG_MEDICINE 32
#define MAX_NUM_BAG_BAIT   8 

/**
 * @brief Applies a new encryption key to an quantity encrypted with save1->encryption_key
 * 
 * @param dst the quantity to re-encrypt
 * @param key the key to encrypt with
 */
void bag_item_apply_new_encryption_key(u16 *dst, u32 key);

/**
 * Prints a string in the bag and continues with a contnmuation function.
 * @param callback_idx self-reference
 * @param font the font in which to print
 * @param str the string to print
 * @param continuation the continuation function after printing the string
 **/
void bag_print_string(u8 callback_idx, u8 font, const u8 *str, void (*continuation)(u8));

/**
 * Callback function that continues the bag functionality after a context menu has been executed
 * @param self self-reference
 **/
void bag_return_from_context_menu(u8 self);

/**
 * Initializes the animation for closing the bag, i.e. closing Win0
 **/
void bag_initialize_close_animation();

/**
 * @brief Clears bag slots
 * 
 * @param slots The bag slots to clear
 * @param count How many slots to clear
 */
void bag_clear_slots(bag_item_t *slots, u8 count);

/**
 * Initializes fading to dark and then conitinues with the exit continuation of the bag
 * @param self self-reference
 **/
void item_menu_fade_and_continue(u8 self);

/**
 * Gets the item idx thats at a certain position in a pocket
 * @param pocket in which pocket
 * @param which position in the pocket
 **/
u16 item_get_idx_by_pocket_position(u16 pocket, u16 idx);

/**
 * @brief Gets the number of items in a given position in a pocket
 * 
 * @param pocket The pocket in which to find the item
 * @param idx The slot in the pocket
 * @return u16 The quantity
 */
u16 item_get_quantity_by_pocket_position(u16 pocket, u16 idx);

/**
 * @brief Gets the quantity of an encrypted bag item slot
 * 
 * @param encrypted the encrypted quantity
 * @return u16 The quantity
 */
u16 item_slot_get_quantity(const u16 *encrypted);

/**
 * @brief Sets the quantity of an item in an encrypted bag slot
 * 
 * @param dst Where to put the quantity
 * @param quantity The quantity to set
 */
void item_slot_set_quantity(u16 *dst, u16 quantity);

/**
 * Closes the bag and returns to the overworld, where a continuation is executed
 * @param self self-reference
 **/
void item_close_bag_and_return_to_overworld(u8 self);

/**
 * Prints a string and executes a continuation afterwards
 * @param self self-reference
 * @param font in which font to print the text
 * @param str the string to print
 * @param continuation the function to invoke after printing the text
 **/
void bag_print_string_with_continuation(u8 self, u8 font, const u8 *str, void (*continuation)(u8));

/**
 * Waits for A to be pressed and then ends the current context (e.g. give, give from pc, ...)
 * @param self self-reference
 **/
void bag_wait_for_a_press_and_close_context_menu(u8 self);

/**
 * Sets a function to be invoked after the bag closes
 * @param cont the function to be invoked after the bag closes
 **/
void bag_set_continuation(void (*cont)());

/**
 * Initializes the berry pouch with the context to give an item and return to the bag afterwards
 **/
void bag_initialize_berry_pouch_with_context_give_item();

/**
 * Initializes the berry pouch with the context to give an item from the pc and return to the bag afterwards
 **/
void bag_initialize_berry_pouch_with_context_give_item_from_pc();

/**
 * Fades out to black and then runs the continuation after the bag closes
 * @param self self-reference
 **/
void bag_fade_out_and_continuation(u8 self);

/**
 * Closes the bag using the win0 animation
 **/
void bag_close_with_win0_animation();

/**
 * Prints a string that an item can't be held in the bag
 * @param self self-reference
 **/
void bag_print_string_item_cant_be_held(u8 self);

/**
 * Initializes the bag after selecting it in the start menu as an option
 **/
void bag_initialize_from_start_menu();

/**
 * @brief Moves an item in a pocket
 * 
 * @param slots The pocket
 * @param from The index of the item to move
 * @param to Where to put the item
 */
void item_move_in_pocket(bag_item_t *slots, u32 from, u32 to);

/**
 * @brief Compacts the a bag pocket
 * 
 * @param slots the slots to compact 
 * @param capacity the capacity of the pocket
 */
void bag_pocket_compact(bag_item_t *slots, size_t capacity);

#endif