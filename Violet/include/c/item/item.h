/*
 * item.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_ITEM_ITEM_H_
#define INCLUDE_C_ITEM_ITEM_H_


#include "constants/items.h"
#include "item/item_effect.h"
#include "constants/item_pockets.h"
#include "oam.h"

typedef struct {
    u8 name[14];
    u16 index;
    u16 price;
    u8 holding_effect_id;
    u8 holding_effect_param;
    const u8 *description;
    u8 importance;
    u8 exit_bag_on_use;
    u8 pocket;
    u8 type;
    void (*field_usage)(u8);
    u8 battle_effect;
    void (*battle_usage)(u8);
    u8 secondary_idx;
} item;

extern const item items[ITEM_CNT];

typedef struct {
    void *sprite_rectangle;
    u32 rare_candy_exp_remaining;
    u8 rare_candy_levels_remaining : 7;
    u8 rare_candy_item_removed : 1;
    u8 rare_candy_exp_leveled_up : 1;
} item_candy_state_t;

extern EWRAM item_candy_state_t item_candy_state;
extern EWRAM u8 item_obtain_oam_id;
extern EWRAM u8 item_obtain_tb_id;

typedef struct {
	u8 hold_effect;
	u8 type;
} item_hold_effect_type_boost_stru;

#define ITEM_HOLD_EFFECT_TYPE_BOOSTS_SIZE 17

extern const item_hold_effect_type_boost_stru item_hold_effect_type_boosts[ITEM_HOLD_EFFECT_TYPE_BOOSTS_SIZE];

extern void (*item_callback_after_pokemon_selected)(u8, void (*)(u8));

extern void (*item_use_continuation)(u8);

extern void (*evolution_continuation)();

#define ITEM_HAS_TABLE_EFFECT(item) ((item) >= ITEM_TRANK && (item) <= (ITEM_ENIGMABEERE))

/**
 * Copies an items name
 * @param item_idx which items name to copy
 * @param dst where to copy the name to
 **/
void item_strcpy(u16 item_idx, u8 *dst);

/**
 * Gets the name of an item.
 * @param item_idx the item to get the name of
 * @return offset of the item's name
 **/
const u8 *item_get_name(u16 item_idx);

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
 * Returns the description effect of an item.
 * @param item_id The item idx
 * @return The description
 */
u8 *item_get_description(u16 item_idx);

/**
 * Select the target of an item effect
 * @param self the own callback id
 */
void item_select_target_pokemon(u8 self);

/**
 * Removes a number of exemplars of items from the player's bag
 * @param item_id the item to remove
 * @param count the number of exemplars to remove
 * @return if the removal was successful
 */
bool item_remove(u16 item_id, u16 count);

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
 * @return if the adding was succesfull
 */
bool item_add(u16 item, u16 cnt);

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
 * @brief Battle effect for items that use table-based effects for medicine
 * 
 * @param self self-reference
 */
void item_battle_effect_medicine(u8 self);

/**
 * Item field function for null syrup.
 * @param self self-reference
 **/
void item_field_null_syrup(u8 self);

/**
 * Gets the price of an item.
 * @param item_idx the item to get the price of
 * @return the item price
 **/
u16 item_get_price(u16 item_idx);

/**
 * Battle function for pokéballs
 * @param self self-reference
 **/
void item_pokeball_battle(u8 self);

/**
 * Gets the pocket of an item
 * @param item the item to get the pocket of
 * @return pocket the pocket of the item
 **/
u8 item_get_pocket(u16 item);

/**
 * Gets the importance of an item
 * @param item the item idx
 * @return the item's importance
 **/
u8 item_get_importance(u16 item);

/**
 * Creates a new oam for an item with the standard template
 * @param tiles_tag which tiles tag to associate with the oam
 * @param pal_tag which pal tag to associate with the oam
 * @param item_idx which item to show
 * @return the oam idx
 **/
u8 item_oam_new(u16 tiles_tag, u16 pal_tag, u16 item_idx);

/**
 * Creates a new oam for an item using a template. Tile and Pal tag are set due to the function's arguments.
 * @param template the oam template used to create the oams
 * @param tiles_tag which tiles tag to associate with the oam
 * @param pal_tag which pal tag to associate with the oam
 * @param item_idx which item to show
 * @return the oam idx
 **/
u8 item_oam_new_by_template(const oam_template *template, u16 tiles_tag, u16 pal_tag, u16 item_idx);

/**
 * Gets the gfx or pal of an item
 * @param item the item to get the resource of
 * @param get_palette a bool indicating if the palette should be retrieved
 * @return the resource
 **/
const u8 *item_get_resource(u16 item, u8 get_palette);

/**
 * Checks how many copies of an item the bag has
 * @param item_idx the item to check
 * @return count the number of copies of this item in the bag
 **/
u16 item_get_count(u16 item_idx);

/**
 * @brief Returns the field function associated with an item
 * 
 * @param item_idx the item
 */
void (*item_get_field_function(u16 item_idx))(u8);

/**
 * @brief Returns the battle function assoicated with an item
 * 
 * @param item_idx the item
 */
void (*item_get_battle_function(u16 item_idx))(u8);

/**
 * @brief Gets the item type of an item
 * 
 * @param item_idx the item
 * @return u16 the item type
 */
u16 item_get_type(u16 item_idx);

/**
 * Fades to a scene that fits the item to use (either overworld or party menu) and executes the item callback there.
 * @param self self-reference
 **/
void item_field_fade_to_scene_and_execute_callback(u8 self);

/**
 * Item callback for executing rare candy.
 * @param self self-reference
 * @param failure_continuation where to continue in case of a failure
 **/
void item_callback_rare_candy(u8 self, void (*failure_continuation)(u8));

/**
 * Item callback for executing rare candy step (after it has already been ensured it can be applied).
 * @param self self-reference
 * @param failure_continuation where to continue in case of a failure
 **/
void item_callback_rare_candy_step(u8 self, void (*failure_continuation)(u8));

/**
 * Field effect callback for the gold candy.
 * @param self self-reference
 **/
void item_gold_candy_field_effect(u8 self);

/**
 * @brief Field effect callback for the rare candy.
 * 
 * @param self self-reference
 */
void item_rare_candy_field_effect(u8 self);

/**
 * @brief Field effect callback for the exp candy s
 * 
 * @param self self-reference
 */
void item_exp_candy_s_field_effect(u8 self);

/**
 * @brief Field effect callback for the exp candy m
 * 
 * @param self self-reference
 */
void item_exp_candy_m_field_effect(u8 self);

/**
 * @brief Field effect callback for the exp candy l
 * 
 * @param self self-reference
 */
void item_exp_candy_l_field_effect(u8 self);

/**
 * @brief Field effect callback for the exp candy xl
 * 
 * @param self self-reference
 */
void item_exp_candy_xl_field_effect(u8 self);

/**
 * Prints the string that an item can not be used currently (oak says that)
 * @param self self-reference
 * @param from_overworld if the item was used in the overworld (or in the bag)
 **/
void item_print_string_can_not_be_used_by_oak(u8 self, u8 from_overworld);

/**
 * Item effect for mulch
 * @param self self-reference
 **/
void item_effect_mulch(u8 self);

/**
 * Item effect for abra doll
 * @param self self-reference
 **/
void item_field_effect_abra_doll(u8 self);

/**
 * Checks if an item is a mail and can be written here in this context
 * @param item_idx the item to check
 * @return if the item is a mail and can be written
 **/
bool item_is_mail_and_can_be_written(u16 item_idx);

/**
 * @brief Checks if any more rare candy level-ups / exp gains are issued
 * 
 * @return if any more exp gains are issued
 */
bool item_rare_candy_is_issued();

typedef struct {
    const u8 *gfx;
    const u8 *pal;
} item_gfx_pair;

/**
 * @brief Checks if an item can be tossed
 * 
 * @param item_idx the item to check
 * @return true 
 * @return false 
 */
bool item_can_be_tossed(u16 item_idx);

/**
 * @brief Adds an item to the item pc
 * 
 * @param item_idx the item to add
 * @param quantity how many exemplars to add
 * @return if there was space
 */
bool item_add_to_pc(u16 item_idx, u16 quantity);

/**
 * @brief Prints the string that an item can't be used. `big_callbacks[self].params[3]` is interpreted as "from overworld" (if true, from overworld, if false, from bag)
 * 
 * @param self self-reference
 */
void item_field_function_print_string_can_not_be_used(u8 self);

/**
 * @brief Item callback for evolution stones
 * 
 * @param self self-reference
 */
void item_field_function_evolution_stone(u8 self);

/**
 * @brief Modifies the nature of a pokemon according to a nature stone (mint)
 * 
 * @param nature the nature to modify
 * @param item_idx the nature stone / mint
 * @return u32 the modified nature
 */
u32 item_nature_stone_modify_nature(u8 nature, u16 item_idx);

/**
 * @brief Item callback for ability patch
 * 
 * @param self self-reference
 */
void item_ability_patch_field_effect(u8 self);

/**
 * @brief Item callback for anti ability patch
 * 
 * @param self self-reference
 */
void item_anti_ability_patch_field_effect(u8 self);

/**
 * @brief Item callback for the ability capsule
 * 
 * @param self self-reference
 */
void item_ability_capsule_field_effect(u8 self);

enum {
    ITEM_EVOLUTION_OR_TM_NONE = 0,
    ITEM_EVOLUTION_OR_TM_TM,
    ITEM_EVOLUTION_OR_TM_EVOLUTION,
};

/**
 * @brief Checks if an item is a tm or an evolution stone
 * 
 * @param item_idx the item to check
 * @return u8 if the item is an evolution stone (`ITEM_EVOLUTION_OR_TM_EVOLUTION`) or a tm (`ITEM_EVOLUTION_OR_TM_TM`) or none of these (`ITEM_EVOLUTION_OR_TM_NONE`)
 */
u8 item_is_tm_or_evolution_stone(u16 item_idx);

#endif /* INCLUDE_C_ITEM_ITEM_H_ */
