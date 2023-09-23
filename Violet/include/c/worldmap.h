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
#include "constants/map_namespaces.h"
#include "tile/coordinate.h"
#include "map/healing_place.h"
#include "pokepad/pokedex/habitat.h"

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

#define WORLDMAP_POKEDEX_HABITAT_INITIAL_LIST_SIZE 64

#define WORLDMAP_BUTTON_SWITCH_MAPS_HABITAT_X 0
#define WORLDMAP_BUTTON_SWITCH_MAPS_HABITAT_Y 13

typedef u8 worldmap_namespace_t[WORLDMAP_HEIGHT][WORLDMAP_WIDTH];

#define NUM_FLIGHT_POSITONS 21

enum {
    WORLDMAP_UI_INITIALIZATION_STATE_DATA_SETUP = 0,
    WORLDMAP_UI_INITIALIZATION_STATE_RESET,
    WORLDMAP_UI_INITIALIZATION_STATE_SETUP_BGS,
    WORLDMAP_UI_INITIALIZATION_STATE_SETUP_SCANLINE,
    WORLDMAP_UI_INITIALIZATION_STATE_SETUP_TBOXES,
    WORLDMAP_UI_INITIALIZATION_STATE_LOAD_BG_GFX,
    WORLDMAP_UI_INITIALIZATION_STATE_LOAD_OAM_GFX,
    WORLDMAP_UI_INITIALIZATION_STATE_SHOW,
} worldmap_initialization_state;


// OAM gfx tags
enum {
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
} worldmap_ui_gfx_tag;

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
    extern const color_t gfx_worldmap_icon_thetoPal[16];

    enum {
        WORLDMAP_THETO = 0,
        WORLDMAP_ISLANDS = 1,
        NUM_WORLDMAPS
    } worldmap_idx;

    enum {
        WORLDMAP_LAYER_GROUND = 0,
        WORLDMAP_LAYER_CLOUDS = 1,
        NUM_WORLDMAP_LAYERS,
    };

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
    extern const worldmap_position_t *worldmap_positions[256];

#define WORLDMAP_FLAG_CHECK_INVALID 0
#define WORLDMAP_FLAG_CHECK_NO_FLAG 1
#define WORLDMAP_FLAG_CHECK_SET 2
#define WORLDMAP_FLAG_CHECK_UNSET 3

#ifdef	__cplusplus
}
#endif

#endif	/* WORLDMAP_H */

