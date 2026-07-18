#ifndef H_OVERWORLD_RESTAURANT
#define H_OVERWORLD_RESTAURANT

#include "types.h"
#include "list_menu.h"
#include "constants/restaurant_trainers.h"

#define IS_RESTAURANT_TRAINER(trainer_idx) ((trainer_idx) >= RESTAURANT_TRAINER_BASE && (trainer_idx) <= RESTAURANT_TRAINER_BASE + NUM_RESTAURANT_TRAINERS - 1)

typedef struct {
    list_menu_item menu_items[32];
    u16 prices[32];
    const u8 *descriptions[32];
    u8 effects[32];
    u8 tbox_idx_menu;
    u8 tbox_idx_description;
    u8 list_menu_cb_idx;
    u16 list_menu_cursor_offset;
    u16 list_menu_cursor_row;
    u8 scroll_indicator_cb_idx;
} restaurant_menu_state_t;

typedef struct {
    const u8 *name;
    const u8 *description;
    u16 price;
    u16 flag;
    u8 effect;
} restaurant_menu_item_t;

typedef struct {
    const restaurant_menu_item_t *starters;
    const restaurant_menu_item_t *mains;
    const restaurant_menu_item_t *desserts;
} restaurant_menu_t;

typedef struct {
    u16 species;
    u8 appears_at_level;
} restaurant_species_t;

enum {
    RESTAURANT_BOOST_HP_EV = 1,
    RESTAURANT_BOOST_ATTACK_EV,
    RESTAURANT_BOOST_DEFENSE_EV,
    RESTAURANT_BOOST_SPEED_EV,
    RESTAURANT_BOOST_SP_ATTACK_EV,
    RESTAURANT_BOOST_SP_DEFENSE_EV,
    RESTAURANT_BOOST_EXP,
};

enum {
    RESTAURANT_LEVEL_5,
    RESTAURANT_LEVEL_13,
    RESTAURANT_LEVEL_19,
    RESTAURANT_LEVEL_25,
    RESTAURANT_LEVEL_33,
    RESTAURANT_LEVEL_41,
    RESTAURANT_LEVEL_49,
    RESTAURANT_LEVEL_57,
    RESTAURANT_LEVEL_65,
    RESTAURANT_LEVEL_73,
    RESTAURANT_LEVEL_81,
    RESTAURANT_LEVEL_89,
    RESTAURANT_LEVEL_100,
    NUM_RESTAURANT_LEVELS,
};

#define RESTAURANT_TYPE(type) (RESTAURANT_TYPE_BASE + (type))
#define RESTAURANT_LEVEL(level) (RESTAURANT_LEVEL_BASE + (level))

extern const restaurant_menu_t restaurant_menu;

/**
    * Sets up the trainer party for a restaurant battle
    * @param trainer_idx the index of the trainer to setup
    * @return the number of pokemon in the party
*/
u8 restaurant_setup_trainer_party(u16 trainer_idx);




#endif