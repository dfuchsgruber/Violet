#ifndef H_CRAFTING
#define H_CRAFTING

#include "types.h"
#include "save.h"
#include "constants/crafting_ingredient_types.h"
#include "list_menu.h"

#define MAX_NUM_INGREDIENTS 4
#define CRAFTING_OAM_BASE_TAG 0x1534

enum {
    CRAFTING_HEALING,
    CRAFTING_BATTLE,
    CRAFTING_POKEBALLS,
    CRAFTING_JEWELS,
    CRAFTING_EVOLUTION,
    CRAFTING_MINTS,
    CRAFTING_NUTRIENTS,
    CRAFTING_TYPE_CNT,
};

// The count for ash as an ingredient is in multiples of 50
#define CRAFTING_INGREDIENT_ASH_MULTIPLIER 50
#define CRAFTING_INGREDIENT_ASH_TO_COUNT(x) ((x) / CRAFTING_INGREDIENT_ASH_MULTIPLIER)

typedef struct {
    u8 count;
    u8 type;
    u16 item;
} crafting_ingredient;

typedef struct {
    crafting_ingredient ingredients[MAX_NUM_INGREDIENTS];
    u16 item;
    u16 flag;
    u8 count;
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
    u8 **list_menu_item_strings[CRAFTING_TYPE_CNT];
    u8 recipe_selection_list_menu_callback;
    list_menu_template recipe_selection_list_menu_template;
    u16 list_menu_cursor_positions[CRAFTING_TYPE_CNT]; // Remember where the cursor was for each category
    u16 list_menu_cursor_above[CRAFTING_TYPE_CNT]; // Remember where the cursor was for each category
    u8 oam_item;
    u8 message_callback;
    u8 callback_scroll_indicators_up_down;
    u8 callback_scroll_indicators_left_right;
    void (*exit_continuation)();
    u8 initialized_from_overworld;
    u16 max_quantity; // How exemplars many can be crafted at max
    u16 quantity; // How many exemplars will be crafted currently

} crafting_ui_state;

/**
 * Reinitializes the ui state.
 * @param type which recipe type to initialize it with
 * @param list_menu_cursor_positions where the cursors where put
 * @param list_menu_curosr_above items above the cursor
 **/
void crafting_ui_reinitialize(u16 type, u16 list_menu_cursor_positions[CRAFTING_TYPE_CNT], u16 list_menu_cursor_above[CRAFTING_TYPE_CNT]);


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
 * @param count how many exemplars to craft
 * @return if the player has this ingredient, bascially
 **/
bool ingredient_requirements_fulfilled(crafting_ingredient *ingredient, u16 count);

/**
 * Checks if the player's bag fulfils the requirements of a recipe
 * @param recipe the recipe to check
 * @param count how many exemplars to craft
 * @return if the player has all ingredients, bascially
 **/
bool recipe_requirements_fulfilled(crafting_recipe *r, u16 count);

/**
 * Uses a crafting recipe, i.e. deletes the ingredients and adds the target item
 * @param r the recipe to use
 * @param count how many exemplars to craft
 * @return if the recipe was used sucessfully (fails when requirements are not met or no room)
 **/
bool recipe_use(crafting_recipe *r, u16 count);

/**
 * Checks how many exemplars of a recipe can be crafted at most with the igredients in the bag
 * @param r the recipe to check
 * @return how many exemplars can be crafted at most
 **/
u16 recipe_max_count_with_requirements_fulfilled(crafting_recipe *r);

#define CRAFTING_UI_STATE ((crafting_ui_state*)fmem.gp_state)

#define CAULDRON_ITEM_BASE_TAG 0x1111
#define CAULDRON_LIGHT_TAG 0x7663

typedef struct {
    u16 frame;
    u8 state;
    crafting_recipe recipe;
    u16 count;
    s16 bg_horizontal_scrolling[4];
    s16 bg_vertical_scrolling[4];
    s16 bg_horizontal_origin;
    s16 bg_vertical_origin;
    u8 oams_lights[3];
    u8 oams_items[4];
    u8 lights_color_state;
    u8 lights_number_active;
    u8 shaking_intensity;
    void (*step_callback)(u16);
    struct {
        u16 type;
        u16 list_menu_cursor_positions[CRAFTING_TYPE_CNT]; // Remember where the cursor was for each category
        u16 list_menu_cursor_above[CRAFTING_TYPE_CNT]; // Remember where the cursor was for each category
    } saved_ui_state; // For reinitialization
} cauldron_scene_state;

#define CAULDRON_SCENE_STATE ((cauldron_scene_state*)fmem.gp_state)

/**
 * Initializes the cauldron scene with a recipe. Assumes that the screen is already faded and the previous scene has freed its additional allocated memory
 * @param recipe with which recipe the cauldron scene is initializes
 * @param ui_state form which ui the cauldron is initialized, this is needed to backup the cursor positions
 **/
void cauldron_scene_initialize(crafting_recipe *recipe, crafting_ui_state *ui_state);


// Crafting UI gfx
extern const u8 gfx_crafting_menu_bg3Tiles[];
extern const u8 gfx_crafting_menu_bg3Map[];
extern const u8 gfx_crafting_menu_bg3Pal[];
extern const u8 gfx_crafting_menu_bg2Tiles[];
extern const u16 gfx_crafting_menu_bg2Map[56 / 8][136 / 8];
extern const u8 gfx_crafting_menu_bg2Pal[];

// Cauldron scene gfx
extern const u8 gfx_crafting_cauldronTiles[]; // 8bpp
extern const u8 gfx_crafting_cauldronMap[];
extern const u8 gfx_crafting_cauldronPal[]; // up to 256 colors
extern const u8 gfx_crafting_cauldron_overlayTiles[];
extern const u8 gfx_crafting_cauldron_overlayMap[];
extern const u8 gfx_crafting_cauldron_topTiles[];
extern const u8 gfx_crafting_cauldron_topMap[];
extern const u8 gfx_crafting_cauldron_lightsTiles[]; // 6 oam graphics of shape 32x32, 0-2 for the center, 3-5 for the left (and right if flipped)
extern const u8 gfx_crafting_cauldron_lightsPal[];


#endif