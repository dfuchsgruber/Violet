#ifndef H_ITEM_FISHING
#define H_ITEM_FISHING

extern u8 ow_script_fishing[];

/**
 * Callback to handle all fishing states.
 * @param self self-reference
 **/
void fishing_big_callback(u8 self);

/**
 * Callback to handle inputs for asking the player if he wants to use a bait.
 * @param self self-reference
 **/
void fishing_big_callback_bait(u8 self);

/**
 * Function that stops the fishing state from waiting and initializes the fishing implementation.
 **/
void fishing_start_after_bait_selection();

#endif