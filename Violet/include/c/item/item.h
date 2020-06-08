/*
 * item.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_ITEM_ITEM_H_
#define INCLUDE_C_ITEM_ITEM_H_

#include "item/count.h"
#include "constants/items.h"
#include "item/item_effect.h"

typedef struct {
    u8 name[14];
    u16 index;
    u16 price;
    u8 holding_effect_id;
    u8 holding_effect_param;
    u8 *description_ptr;
    u8 importance;
    u8 exit_bag_on_use;
    u8 pocket;
    u8 type;
    void (*field_usage)(u8);
    void (*battle_usage_1)(u8);
    void (*battle_usage_2)(u8);
    void (*field_28)(u8);
} item;

item items[ITEM_CNT];


typedef struct {
	u8 hold_effect;
	u8 type;
} item_hold_effect_type_boost_stru;

#define ITEM_HOLD_EFFECT_TYPE_BOOSTS_SIZE 17

extern item_hold_effect_type_boost_stru
item_hold_effect_type_boosts[ITEM_HOLD_EFFECT_TYPE_BOOSTS_SIZE];

void (*item_callback_after_pokemon_selected)(u8, void (*)(u8));

#define ITEM_HAS_TABLE_EFFECT(item) ((item) >= ITEM_TRANK && (item) <= (ITEM_ENIGMABEERE))

/**
 * Returns the holding effect parameter of an item.
 * @param item_id The item id
 * @return The effect parameter
 */
u8 item_get_hold_effect_parameter(u16 item_id);
/**
 * Returns the holding effect  of an item.
 * @param item_id The item id
 * @return The effect
 */
u8 item_get_hold_effect(u16 item_id);

/**
 * Select the target of an item effect
 * @param self the own callback id
 */
void item_select_target_pokemon(u8 self);

/**
 * Removes a number of exemplars of items from the player's bag
 * @param item_id the item to remove
 * @param count the number of exemplars to remove
 */
void item_remove(u16 item_id, u16 count);

/**
 * Callback that waits for the text renderer to finish and returns to the bag afterwards
 * @param self the own callback id
 */
void item_callback_wait_for_text_render_and_return_to_bag(u8 self);

/**
 * Callback to execute once the field usage of the item has failed
 * @param self the own callback id
 */
void item_field_usage_failure(u8 self);

/**
 * Item function to print a string (appears in the bag or overworld)
 * @param cb_id the own callback id
 * @param unknown TODO
 * @param unknown2 TODO
 * @param str the string to print
 */
void item_print_string(u8 cb_id, u8 unknown, u8 unknown2, u8 *str);

/**
 * Adds a certain amount of exemplars of an item to the player's bag
 * @param item the item
 * @param cnt the number of exemplars to add
 */
void item_add(u16 item, u16 cnt);

/**
 * Removes an item from the player's pc
 * @param item the item to remove
 * @param quantity the amount of exemplars to remove
 */
void item_remove_from_pc(u16 item, u16 quantity);

/**
 * Checks if the player's bag contains a certain amount if exemplars or an item
 * @param item the item to check
 * @param quantity the amount
 * @return if the player's bag contains the item(s)
 */
bool item_check(u16 item, u16 quantity);
/**
 * Checks if the player's bag has room for item(s).
 * @param item the item to check
 * @param quantity the amount
 * @return if the player's bag can hold this much items
 **/
bool item_has_room(u16 item, u16 quantity);

/**
 * Item function for items that use an effect from the effect table.
 * @param self reference to the callback
 **/
void item_field_by_effect_table(u8 self);

/**
 * Gets the price of an item.
 * @param item_idx the item to get the price of
 * @return the item price
 **/
u16 item_get_price(u16 item_idx);

/**
 * Prints a string in the bag and continues with a contnmuation function.
 * @param callback_idx self-reference
 * @param font the font in which to print
 * @param str the string to print
 * @param continuation the continuation function after printing the string
 **/
void bag_print_string(u8 callback_idx, u8 font, u8 *str, void (*continuation)(u8));

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
 * Initializes fading to dark and then conitinues with the exit continuation of the bag
 * @param self self-reference
 **/
void item_menu_fade_and_continue(u8 self);

/**
 * Battle function for pokéballs
 * @param self self-reference
 **/
void item_pokeball_battle(u8 self);

u16 tm_hm_to_attack[58];

#endif /* INCLUDE_C_ITEM_ITEM_H_ */
