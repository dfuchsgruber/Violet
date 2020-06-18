#ifndef H_CRAFTING
#define H_CRAFTING

#include "types.h"
#include "save.h"
#include "constants/crafting_ingredient_types.h"
#include "list_menu.h"

#define MAX_NUM_INGREDIENTS 4
#define CRAFTING_OAM_BASE_TAG 0x1534
#define CRAFTING_ARROW_TAG 0x1533

enum {
    CRAFTING_HEALING,
    CRAFTING_POKEBALLS,
    CRAFTING_JEWELS,
    CRAFTING_EVOLUTION,
    CRAFTING_MINTS,
    CRAFTING_NUTRIENTS,
    CRAFTING_TYPE_CNT,
};

// The count for ash as an ingredient is in multiples of 50
#define CRAFTING_INGREDIENT_ASH_MULTIPLIER 50

typedef struct {
    u8 count;
    u8 type;
    u16 item;
} crafting_ingredient;

typedef struct {
    crafting_ingredient ingredients[MAX_NUM_INGREDIENTS];
    u16 item;
    u16 flag;
} crafting_recipe;

typedef struct {
    u8 setup_state;
    u8 current_recipe_idx; // Which recipe is currently visible
    u16 type;
    u16 type_to_switch_to; // To which type to switch to
    u8 oams_ingredients[MAX_NUM_INGREDIENTS];
    crafting_recipe *recipies[CRAFTING_TYPE_CNT]; // A list of all available recipies
    u8 num_crafting_recipies[CRAFTING_TYPE_CNT]; // How many of each category are available
    list_menu_item *list_menu_items[CRAFTING_TYPE_CNT]; // List menus for each category
    u8 recipe_selection_list_menu_callback;
    list_menu_template recipe_selection_list_menu_template;
    u16 list_menu_cursor_positions[CRAFTING_TYPE_CNT]; // Remember where the cursor was for each category
    u16 list_menu_cursor_above[CRAFTING_TYPE_CNT]; // Remember where the cursor was for each category
    u8 oam_item;
    u8 message_callback;
    u8 callback_scroll_indicators_up_down;
    u8 callback_scroll_indicators_left_right;

} crafting_ui_state;


/**
 * Gets how many recipies there are in total per category
 * @param type the category of crafting items to check
 * @return size the number of recipies in this category
 **/
size_t crafting_get_num_recipies_by_type(u16 type);

/**
 * Gets all recipies for a certain category
 * @param type the category of crafting items to get
 * @return recipies all recipies associated with this category
 **/
crafting_recipe *crafting_recipies_get_by_type(u16 type);

/**
 * Checks if the player's bag fulfils the requirements of a single ingredient
 * @param ingredient the ingredient to check
 * @return if the player has this ingredient, bascially
 **/
bool ingredient_requirements_fulfilled(crafting_ingredient *ingredient);

/**
 * Checks if the player's bag fulfils the requirements of a recipe
 * @param recipe the recipe to check
 * @return if the player has all ingredients, bascially
 **/
bool recipe_requirements_fulfilled(crafting_recipe *r);

#define CRAFTING_UI_STATE ((crafting_ui_state*)fmem.gp_state)


extern const u8 gfx_crafting_menu_bg3Tiles[];
extern const u8 gfx_crafting_menu_bg3Map[];
extern const u8 gfx_crafting_menu_bg3Pal[];
extern const u8 gfx_crafting_menu_bg2Tiles[];
extern const u16 gfx_crafting_menu_bg2Map[56 / 8][136 / 8];
extern const u8 gfx_crafting_menu_bg2Pal[];

#endif