/* 
 * File:   worldmap.h
 * Author: Domi
 *
 * Created on 15. März 2017, 17:16
 */

#ifndef WORLDMAP_H
#define	WORLDMAP_H

#ifdef	__cplusplus
extern "C" {
#endif
#define ____ 0xC5
#include "types.h"
#include "constants/map_namespaces.h"
#include "tile/coordinate.h"
#include "map/healing_place.h"
#include "pokepad/pokedex/habitat.h"
#include "pokemon/move_relearner.h"
#include "list_menu.h"

// Width and height without the margin
#define WORLDMAP_WIDTH 22
#define WORLDMAP_HEIGHT 14

// Inacessible coordinates on the worldmap
#define WORLDMAP_X_MARGIN 1
#define WORLDMAP_Y_MARGIN 2

#define WORLDMAP_TOTAL_WIDTH (WORLDMAP_WIDTH + 2 * WORLDMAP_X_MARGIN)
#define WORLDMAP_TOTAL_HEIGHT (WORLDMAP_HEIGHT + 2 * WORLDMAP_Y_MARGIN)

// The habitat widget on the left hides one column of the worldmap (which is why you can scroll "with no left margin")
#define WORLDMAP_X_OFFSET_HABITAT 6
#define WORLDMAP_Y_OFFSET_HABITAT 2
#define WORLDMAP_X_OFFSET_STD 3
#define WORLDMAP_Y_OFFSET_STD 2
#define WORLDMAP_X_OFFSET_INFO 7
#define WORLDMAP_Y_OFFSET_INFO 2


#define WORLDMAP_POKEDEX_HABITAT_INITIAL_LIST_SIZE 64

#define WORLDMAP_BUTTON_SWITCH_MAPS_HABITAT_X 0
#define WORLDMAP_BUTTON_SWITCH_MAPS_HABITAT_Y 13
#define WORLDMAP_BUTTON_SWITCH_MAPS_STD_X 0
#define WORLDMAP_BUTTON_SWITCH_MAPS_STD_Y 13
#define WORLDMAP_BUTTON_SWITCH_MAPS_INFO_X 0
#define WORLDMAP_BUTTON_SWITCH_MAPS_INFO_Y 13

#define WORLDMAP_SWITCH_MAPS_DIALOGE_WIDTH 10
#define WORLDMAP_SWITCH_MAPS_DIALOGE_HEIGHT 10

#define WORLDMAP_SWITCH_MAPS_DIALOGE_X_HABITAT (WORLDMAP_X_OFFSET_HABITAT + (WORLDMAP_TOTAL_WIDTH - WORLDMAP_SWITCH_MAPS_DIALOGE_WIDTH) / 2)
#define WORLDMAP_SWITCH_MAPS_DIALOGE_Y_HABITAT (WORLDMAP_Y_OFFSET_HABITAT + (WORLDMAP_TOTAL_HEIGHT - WORLDMAP_SWITCH_MAPS_DIALOGE_HEIGHT) / 2)
#define WORLDMAP_SWITCH_MAPS_DIALOGE_X_STD (WORLDMAP_X_OFFSET_STD + (WORLDMAP_TOTAL_WIDTH - WORLDMAP_SWITCH_MAPS_DIALOGE_WIDTH) / 2)
#define WORLDMAP_SWITCH_MAPS_DIALOGE_Y_STD (WORLDMAP_Y_OFFSET_STD + (WORLDMAP_TOTAL_HEIGHT - WORLDMAP_SWITCH_MAPS_DIALOGE_HEIGHT) / 2)
#define WORLDMAP_SWITCH_MAPS_DIALOGE_X_INFO (WORLDMAP_X_OFFSET_INFO - 1 + (WORLDMAP_TOTAL_WIDTH - WORLDMAP_SWITCH_MAPS_DIALOGE_WIDTH) / 2)
#define WORLDMAP_SWITCH_MAPS_DIALOGE_Y_INFO (WORLDMAP_Y_OFFSET_INFO + (WORLDMAP_TOTAL_HEIGHT - WORLDMAP_SWITCH_MAPS_DIALOGE_HEIGHT) / 2)

#define WORLDMAP_INFO_ICON_HOUSE_X 0
#define WORLDMAP_INFO_ICON_HOUSE_Y 16
#define WORLDMAP_INFO_ICON_HOUSE_WIDTH 9
#define WORLDMAP_INFO_ICON_HOUSE_HEIGHT 9

#define WORLDMAP_INFO_ICON_POKEBALL_X 16
#define WORLDMAP_INFO_ICON_POKEBALL_Y 16
#define WORLDMAP_INFO_ICON_POKEBALL_WIDTH 9
#define WORLDMAP_INFO_ICON_POKEBALL_HEIGHT 9

#define WORLDMAP_INFO_SEARCH_MAX_ITEMS_SHOWN 7

typedef u8 worldmap_namespace_t[WORLDMAP_HEIGHT][WORLDMAP_WIDTH];

#define NUM_FLIGHT_POSITONS 21

enum worldmap_initialization_state {
    WORLDMAP_UI_INITIALIZATION_STATE_DATA_SETUP = 0,
    WORLDMAP_UI_INITIALIZATION_STATE_RESET,
    WORLDMAP_UI_INITIALIZATION_STATE_SETUP_BGS,
    WORLDMAP_UI_INITIALIZATION_STATE_SETUP_SCANLINE,
    WORLDMAP_UI_INITIALIZATION_STATE_SETUP_TBOXES,
    WORLDMAP_UI_INITIALIZATION_STATE_LOAD_BG_GFX,
    WORLDMAP_UI_INITIALIZATION_STATE_LOAD_OAM_GFX,
    WORLDMAP_UI_INITIALIZATION_STATE_SHOW,
};


// OAM gfx tags
enum worldmap_ui_gfx_tag {
    WORLDMAP_UI_GFX_TAG_ICON_GRASS = 0x1370,
    WORLDMAP_UI_GFX_TAG_ICON_WATER,
    WORLDMAP_UI_GFX_TAG_ICON_RADAR,
    WORLDMAP_UI_GFX_TAG_ICON_ROD,
    WORLDMAP_UI_GFX_TAG_ICON_ROD_TYPES,
    WORLDMAP_UI_GFX_TAG_ICON_SPECIES,
    WORLDMAP_UI_GFX_TAG_ICON_BALL_CAUGHT,
    WORLDMAP_UI_GFX_TAG_ICON_SWITCH_MAPS,
    WORLDMAP_UI_GFX_TAG_PLAYER_HEAD,
    WORLDMAP_UI_GFX_TAG_CURSOR,
    WORLDMAP_UI_GFX_TAG_SWITCH_MAPS_ICON,
    WORLDMAP_UI_GFX_TAG_PERCENTAGE,
    WORLDMAP_UI_GFX_TAG_SWITCH_MAP_MINIMAP,
};

enum {
    WORLDMAP_UI_TBOX_IDX_NAMESPACE = 0,
    WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE,
    WORLDMAP_UI_NUM_TBOXES,
};

enum {
    WORLDMAP_UI_PERCENTAGE_0 = 0,
    WORLDMAP_UI_PERCENTAGE_1,
    WORLDMAP_UI_PERCENTAGE_5,
    WORLDMAP_UI_PERCENTAGE_10,
    WORLDMAP_UI_PERCENTAGE_15,
    WORLDMAP_UI_PERCENTAGE_20,
    WORLDMAP_UI_PERCENTAGE_25,
    WORLDMAP_UI_PERCENTAGE_30,
    WORLDMAP_UI_PERCENTAGE_35,
    WORLDMAP_UI_PERCENTAGE_40,
    WORLDMAP_UI_PERCENTAGE_45,
    WORLDMAP_UI_PERCENTAGE_50,
    WORLDMAP_UI_PERCENTAGE_55,
    WORLDMAP_UI_PERCENTAGE_60,
    WORLDMAP_UI_PERCENTAGE_65,
    WORLDMAP_UI_PERCENTAGE_70,
    WORLDMAP_UI_PERCENTAGE_75,
    WORLDMAP_UI_PERCENTAGE_80,
    WORLDMAP_UI_PERCENTAGE_85,
    WORLDMAP_UI_PERCENTAGE_90,
    WORLDMAP_UI_PERCENTAGE_95,
    WORLDMAP_UI_PERCENTAGE_100,
    WORLDMAP_UI_HABITAT_NUM_PERCENTAGES,
};

enum worldmap_ui_habitat_tbox {
    WORLDMAP_UI_HABITAT_TBOX_HEADER = WORLDMAP_UI_NUM_TBOXES,
    WORLDMAP_UI_HABITAT_TBOX_FOOTER,
    WORLDMAP_UI_HABITAT_TBOX_HABITAT_NAMES,
    WORLDMAP_UI_HABITAT_TBOX_HABITAT_PERCENTAGES = WORLDMAP_UI_HABITAT_TBOX_HABITAT_NAMES + NUM_HABITAT_TYPES - 2,
    WORLDMAP_UI_HABITAT_TBOX_HABITAT_NO_HABITAT = WORLDMAP_UI_HABITAT_TBOX_HABITAT_PERCENTAGES + NUM_HABITAT_TYPES,
    NUM_WORLDMAP_UI_HABITAT_TBOXES,
};

enum worldmap_ui_std_tbox{
    WORLDMAP_UI_STD_TBOX_HEADER = WORLDMAP_UI_NUM_TBOXES,
    WORLDMAP_UI_STD_TBOX_FOOTER,
    NUM_WORLDMAP_UI_STD_TBOXES,
};

enum worldmap_ui_info_tbox{
    WORLDMAP_UI_INFO_TBOX_HEADER = WORLDMAP_UI_NUM_TBOXES,
    WORLDMAP_UI_INFO_TBOX_FOOTER,
    WORLDMAP_UI_INFO_TBOX_HEADER_INFO,
    WORLDMAP_UI_INFO_TBOX_INFO,
    WORLDMAP_UI_INFO_TBOX_SEARCH_CATEGORY,
    WORLDMAP_UI_INFO_TBOX_SEARCH_ITEMS,
    NUM_WORLDMAP_UI_INFO_TBOXES,
};

enum worldmap_person {
    WORLDMAP_PERSON_MOVE_REMINDER = 0,
    WORLDMAP_PERSON_MOVE_DELETER,
    WORLDMAP_PERSON_NICKNAME_RATER,
    NUM_WORLDMAP_PERSONS,
};

enum worldmap_institution{
    WORLDMAP_INSTITUTION_PLAYER_HOUSE = 0,
    WORLDMAP_INSTITUTION_RIVAL_HOUSE,
    WORLDMAP_INSTITUTION_GYM_BASE,
    WORLDMAP_INSTITUTION_TANNS_LAB = WORLDMAP_INSTITUTION_GYM_BASE + 5,
    WORLDMAP_INSTITUTION_LAZ_CORP,
    WORLDMAP_INSTITUTION_LESTER_HOUSE,
    WORLDMAP_INSTITUTION_ROSALIE_HOUSE,
    WORLDMAP_INSTITUTION_CELEBI_SHRINE,
    WORLDMAP_INSTITUTION_TEAHS_HOUSE,
    NUM_WORLDMAP_INSTIUTIONS,
};

enum worldmap_institution_type{
    WORLDMAP_INSTITUTION_TYPE_NONE = 0,
    WORLDMAP_INSTITUTION_TYPE_HOUSE,
    WORLDMAP_INSTITUTION_TYPE_GYM,
};

enum worldmap_info_category{
    WORLDMAP_CATEGORY_PERSON = 0,
    WORLDMAP_CATEGORY_INSTITUTION,
    WORLDMAP_CATEGORY_TUTOR,
    WORLDMAP_CATEGORY_TUTOR_CRYSTAL,
    NUM_WORLDMAP_CATEGORIES,
};

    typedef struct{
        u8 bank;
        u8 map;
        s16 x;
        s16 y;
        u16 field_6;
    } stru_flight_position;
    
    typedef struct {
    	u16 cursor_x, cursor_y;
    	u8 unknown[0x10];
    	u16 player_namespace;
    	u8 unkown2[0xE];
    	u16 tiles[0x80]; // whatever those tiles may be...

    } worldmap_state_t;

    // A pattern consists of multiple shapes, each of which can have displacement from the
    // position anchor and its own rectangular dimension. To associate a map with a shape use
    // the respective field in the mapheader structure
    typedef struct {
    	u8 x, y, width, height;
    } worldmap_shape_t;

    typedef struct {
    	int num_shapes;
    	const worldmap_shape_t *shapes;
    } worldmap_pattern_t;

    typedef struct {
        u8 bank;
        u8 map_idx;
        u8 shape_idx;
    } worldmap_shape_association_t;

    typedef struct {
        move_tutor_t person;
        u16 flag;
        u8 name[13];
    } worldmap_person_t;

    typedef struct {
        u8 bank, map_idx, warp_idx;
        u8 institution_type;
        u16 flag;
        u8 name[13];
    } worldmap_institution_t;

    #define NUM_WORLDMAP_SHAPE_ASSOCIATIONS 6
    extern const worldmap_shape_association_t worldmap_shape_associations[NUM_WORLDMAP_SHAPE_ASSOCIATIONS];

    extern worldmap_state_t *worldmap_state;

    extern const stru_flight_position flight_positions[NUM_HEALING_PLACES]; // Each flight position is associated with a healing place

    typedef struct {
        u8 bank;
        u8 map_idx;
        u8 healing_place_idx;
    } flight_position_association_t;
    
    // Associates map namespaces with healing place idxs
    extern const flight_position_association_t flight_position_associations[MAP_NAMESPACE_NONE - MAP_AMONIA];

    extern const int *const worldmap_tilemaps[4];
    extern const u8 *namespace_worldmap_associations;
    extern const LZ77COMPRESSED gfx_worldmapTiles;
    extern const LZ77COMPRESSED gfx_worldmapMap;
    extern const color_t gfx_worldmapPal[80];

    extern const LZ77COMPRESSED gfx_worldmap_icon_thetoTiles;
    extern const LZ77COMPRESSED gfx_worldmap_icon_theto_cloudsTiles;
    extern const color_t gfx_worldmap_icon_thetoPal[16];
    extern const color_t gfx_worldmap_icon_theto_cloudsPal[16];

    enum worldmap_idx_t {
        WORLDMAP_THETO = 0,
        WORLDMAP_ISLANDS = 1,
        NUM_WORLDMAPS
    };

    enum {
        WORLDMAP_LAYER_GROUND = 0,
        WORLDMAP_LAYER_CLOUDS = 1,
        NUM_WORLDMAP_LAYERS,
    };

    #define WORLDMAP_FLAG_EMPTY_SLOT 0xFFFF

    extern const u8 (*const worldmap_names[NUM_WORLDMAPS]);
    extern const u8 (*const worldmap_layer_names[NUM_WORLDMAP_LAYERS]);

    /**
     * Processes the input of moving the cursor in the "switch maps" dialoge
     * @param self self-reference
     * @return whether the cursors was moved. Note that if this is true, the callback function is overwritten and the `self`-callback should not do anything further
    */
    bool worldmap_ui_switch_maps_dialoge_process_input(u8 self);

    /**
     * Updates the gfx of the worldmap to bg3 and charbase 1
     * @param worldmap_idx the worldmap to show
     * @param layer the layer to show
     * @param x_offset the horizontal offset in tiles of the worldmap
     * @param y_offset the vertical offset in tiles of the worldmap
    */
    void worldmap_ui_update_worldmap_gfx(u8 worldmap_idx, u8 layer, u8 x_offset, u8 y_offset);

    /**
     * Returns the flightposition idx that corresponds to a bank, map tuple
     * @param bank the mapbank
     * @param map the mapid in the bank
     * @return the corresponding flightposition idx + 1 or 0 if none matches
     */
    int map_get_flightposition(u8 bank, u8 map);

    /**
     * Returns the offset on a flight position by its index + 1
     * @param idx_plus_one the index of the flight position plus one
     * @return the flight pos offset
     */
    const stru_flight_position *flightposition_by_id(int idx_plus_one);

    /**
     * Gets the namespace id associated with a position on the worldmap
     * @param worldmap_index which worldmap to use
     * @param layer the town or locality layer
     * @param x the x coordinate (in tiles)
     * @param y the y coordinate (in tiles)
     * @return the namespace id
     */
    u8 worldmap_get_namespace_by_pos(u8 worldmap_index, u8 layer, u16 x, u16 y);

    /**
     * Sets the state corresponding to a worldmapflag (needed as well to set the worldmapflag)
     * @param flag the flag to set
     */
    void worldmap_flag_state_set(u16 flag);

    /**
     * Sets a worldmap flag (the state needs to be set as well!)
     * @param flag the flag to set
     */
    void worldmap_flag_set(u16 flag);

    /**
     * Locates the player on the current worldmap (saves x, y to the worldmap state).
     */
    void worldmap_locate_player();

    /**
     * Returns the worldmap position of a map
     * @param bank the mapbank
     * @param map_idx the mapid in the bank
     * @param x the x coordinate (in tiles)
     * @param y the y coordinate (in tiles)
     * @param dst_x the x coordinate on the worldmap
     * @param dst_y the y coordinate on the worldmap
     * @param dst_worldmap_idx the worldmap index
     * @param dst_layer the layer
     * @return whether the position could be found
     */
    bool map_coordinates_to_worldmap_position(u8 bank, u8 map_idx, s16 x, s16 y, u8 *dst_x, u8 *dst_y, 
		u8 *dst_worldmap_idx, u8 *dst_layer);

    /**
     * Sets the position of the worldmap cursor to the player's cursor.
    */
    void worldmap_set_cursor_to_player();

    /**
     * Updates the position and visibility of the player head on the worldmap
    */
    void worldmap_ui_update_player_head_oam();

    /**
     * Updates the position and visibility of the cursor on the worldmap
    */
    void worldmap_ui_update_cursor_oam();

    /**
     * Performs one step of the base ui initialization callback
     * @return whether the step has finished
    */
    bool worldmap_ui_callback_initialize_base();

    /**
     * Base callback1 for the worldmap ui
    */
    void worldmap_ui_cb1();

    /**
     * Base vblank callback for the worldmap ui
    */
    void worldmap_ui_vblank_callback();

    /**
     * Callback to handle inputs for moving the cursor with the DPAD
     * @param self self-reference
     * @return whether the cursor starts moving
    */
    bool worldmap_ui_handle_inputs_move_cursor(u8 self);

    /**
     * Frees the worldmap ui state. Should always be called last.
    */
    void worldmap_ui_free_base();

    /**
     * Creates a new dialoge to switch maps
     * @param self the idle callback to overwrite
     * @param handle_inputs_callback after the dialoge is created, the `self`-callback will execute this function
    */
    void worldmap_ui_switch_maps_dialoge_new(u8 self, void (*handle_inputs_callback)(u8));

    /**
     * Deletes the dialoge to switch maps
    */
    void worldmap_ui_switch_maps_dialoge_delete();

    /**
     * Initializes the worldmap ui with the habitat of a pokemon. 
     * Should be called once the previous state has been completely freed and the screen is fading to black.
     * Will set `callback1` accordingly and reset.
     * @param species the habitat of which species to show
     * @param from_overworld whether the habitat was opened from the overworld
    */
    void worldmap_ui_habitat_new(u16 species, void (*contuation)());

    /**
     * Initializes the worldmap ui with the info ui
     * Should be called once the previous state has been completely freed and the screen is fading to black.
     * Will set `callback1` accordingly and reset.
     * @param continuation the continuation to call once the ui is finished
    */
    void worldmap_ui_info_new(void (*continuation)());

    typedef struct {
        u8 x, y, idx, layer, namespace;
    } worldmap_cursor_t;

    typedef struct {
        u8 x;
        u8 y;
        u8 width; 
        u8 height;
        u8 worldmap_idx;
        u8 layer;
    } worldmap_position_t;

    // Locates maps exactly on the worldmap
    extern const worldmap_position_t *const worldmap_positions[256];

    enum worldmap_ui_mode_t {
        WORLDMAP_UI_HABITAT = 0,
        WORLDMAP_UI_STD,
    };

    typedef struct {
        u8 initialization_state;
        u8 mode;
        u8 switch_maps_allowed: 1;

        void *bg0_map;
        void *bg1_map;
        void *bg2_map;
        void *bg3_map;

        void (*continuation)();

        u8 worldmap_tile_x, worldmap_tile_y;
        u8 icon_switch_maps_x, icon_switch_maps_y;

        u8 switch_map_dialoge_x, switch_map_dialoge_y;
        u16 switch_map_icon_base_tile;
        u8 switch_map_icon_pal_idx;
        u8 switch_map_icon_oam_idx;
        u8 switch_map_dialoge_scroll_indicator_idx_cb_idx, switch_map_dialoge_scroll_indicator_layer_cb_idx;
        u16 switch_map_dialoge_scroll_indicator_dummy_scroll_offset; // the scroll arrow visibility is actually managed by 

        u8 header_pokemon_name_string_width;
        u8 oam_idx_player, oam_idx_cursor, oam_idx_icon_switch_map, oam_idx_icon_switch_map_frame;
        u8 oam_idx_percentages[NUM_HABITAT_TYPES];
        
        u8 cursor_locked : 1;
        u8 cursor_invisible : 1;
        u8 cursor_moving : 1;

        worldmap_cursor_t player;
        worldmap_cursor_t cursor;
        worldmap_cursor_t cursor_switch_maps;

        void (*callback_cursor_moved)(u8); // triggered after the cursor is finished moving
        void (*callback_cursor_starts_moving)(u8); // triggered once the cursor starts moving

        u8 cb_idx_handle_inputs;

        u16 species;
        u8 current_namespace;
        u8 red_overlay_intensity;
        u8 red_overlay_should_be_active_on_worldmap[NUM_WORLDMAPS][NUM_WORLDMAP_LAYERS];

        pokedex_habitat_list_t *habitats;
        u8 red_overlay_should_be_active : 1;
        u8 red_overlay_is_active : 1;
        u8 other_red_should_be_active : 1;
        u8 other_red_is_active : 1;

        u8 search_category;
        u8 list_menu_search_cb_idx, list_menu_search_items_cb_idx;
        u8 scroll_indicator_search_items_cb_idx;
        u16 search_category_cursor, search_category_items_above;
        u16 search_items_cursor[NUM_WORLDMAP_CATEGORIES];
        u16 search_items_items_above[NUM_WORLDMAP_CATEGORIES];
        union {
            list_menu_item persons[NUM_WORLDMAP_PERSONS];
            list_menu_item tutors[NUM_MOVE_TUTORS];
            list_menu_item tutor_crystals[NUM_TYPES];
            list_menu_item institutions[NUM_WORLDMAP_INSTIUTIONS];
        } search_items;
        union {
            u8 institutions[NUM_WORLDMAP_INSTIUTIONS][20];
        } search_item_strs;

    } worldmap_ui_state_t;

    extern EWRAM worldmap_ui_state_t *worldmap_ui_state;


#define WORLDMAP_FLAG_CHECK_INVALID 0
#define WORLDMAP_FLAG_CHECK_NO_FLAG 1
#define WORLDMAP_FLAG_CHECK_SET 2
#define WORLDMAP_FLAG_CHECK_UNSET 3

#ifdef	__cplusplus
}
#endif

#endif	/* WORLDMAP_H */

