#ifndef H_OVERWORLD_EFFECT
#define H_OVERWORLD_EFFECT

#include "types.h"
#include "color.h"
#include "constants/overworld/overworld_effects.h"


#include "oam.h"
#include "map/tileset.h"


enum {
    ANY_GRASS_ASH,
    ANY_GRASS_GRAVEYARD,
    ANY_GRASS_HAWEILAND,
    ANY_GRASS_CLOUD,
};

enum {
    TAG_ANY_GRASS_ASH = 0x1080,
    TAG_ANY_GRASS_GRAVEYARD,
    TAG_ANY_GRASS_HAWEILAND,
    TAG_ANY_GRASS_CLOUD,
    TAG_ROCK_CLIMB,
    TAG_ROCK_CLIMB_SKY_ISLANG,
    TAG_PLAYER_PALETTE_VANILLA,
} any_grass_tags;

typedef struct{
    tileset *tileset; // NULL if on all tilesets
    u8 triggered_by_behavior;
    oam_template *temp;
    palette *pal;
    void (*init_func)();
    u8 *(*player_step_cb)();
}any_grass;

typedef struct {
	int x, y;
	int height;
	int bg_priority;
	int target_ow_and_their_map; // (target_ow << 8) | target_ow_map
	int target_ow_bank;
	int origin_map_and_bank; // (map << 8) | bank
	int field_1C;
} overworld_effect_state_t;

extern overworld_effect_state_t overworld_effect_state;

/**
 * Translates coordinates of the overworld effect into screen coordinates
 * @param initial x coordinate
 * @param initial y coordinate
 * @param dx relative x coordinate
 * @param dy relative y coordinate
 **/
void overworld_effect_ow_coordinates_to_screen_coordinates(s16 *x, s16 *y, s16 dx, s16 dy);

/**
 * Callback for overworld effects that are destroyed once their gfx animation has finished.
 * Expects the type of gfx animation to be stored in private[0]
 * @param self self-reference
 **/
void overworld_effect_oam_callback_wait_for_gfx_animation(oam_object *self);

/**
 * Deletes an overworld effect.
 * @param o the oam the effect used
 * @param effect_idx the effect that is to be deleted
 **/
void overworld_effect_delete(oam_object *o, u8 effect_idx);

/**
 * Does a new overworld effect
 * @param effect_idx which effect do to do
 **/
void overworld_effect_new(u8 effect_idx);

/**
 * Removes an overworld effect from the list of active overworld effects.
 * @param effect_idx the effect to remove
 **/
void overworld_effect_remove_from_active_list(u8 effect_idx);

/**
 * Gets the grass effect triggered by stepping on a tile with a certain behaviour on the current map.
 * @param behaviour the behaviour to step on
 * @return the grass effect or NULL if none is associated
 **/
any_grass *any_grass_get_on_current_map_by_behaviour(u8 behaviour);

void rock_climb_step();
void any_grass_step();
u8 *ash_grass_player_step();
u8 *any_grass_player_step_null();

/**
 * Callback for an oam spawned by the overworld effect of grass.
 * @param reference to the oam object
 */
void overworld_effect_oam_callback_grass(oam_object *self);

/**
 * Checks if a palette tag is associated with any ground effect
 * @param tag the tag to check
 * @return if the palette tag is associated with a ground effect
 **/
bool tag_is_ground_effect(u16 tag);

/**
 * Checks if a set of coordinates is outside the camera view.
 * @param x the x coordinate (7 shifted)
 * @param y the y coordinate (7 shifted)
 * @param width the width of the oam in pixels
 * @param height the height of the oam in pixels
 * @return if the oam is outside the camera view
 **/
bool overworld_effect_is_oam_outside_camera_view(s16 x, s16 y, int width, int height);


#define GFX_TAG_OVERWORLD_EFFECT_EXPLOSION 0x1773

extern const u8 gfx_overworld_explosionTiles[];
extern const color_t gfx_overworld_explosionPal[16];

extern const u8 overworld_effect_script_exclamation_mark_icon[];
extern const u8 overworld_effect_script_use_cut_on_grass[];
extern const u8 overworld_effect_script_use_cut_on_tree[];
extern const u8 overworld_effect_script_shadow[];
extern const u8 overworld_effect_script_tall_grass[];
extern const u8 overworld_effect_script_ripple[];
extern const u8 overworld_effect_script_field_move_show_mon[];
extern const u8 overworld_effect_script_ash[];
extern const u8 overworld_effect_script_surf_blob[];
extern const u8 overworld_effect_script_use_surf[];
extern const u8 overworld_effect_script_dust[];
extern const u8 overworld_effect_script_use_secret_power_cave[];
extern const u8 overworld_effect_script_jump_tall_grass[];
extern const u8 overworld_effect_script_sand_footprints[];
extern const u8 overworld_effect_script_jump_big_splash[];
extern const u8 overworld_effect_script_splash[];
extern const u8 overworld_effect_script_jump_small_splash[];
extern const u8 overworld_effect_script_long_grass[];
extern const u8 overworld_effect_script_jump_long_grass[];
extern const u8 overworld_effect_script_unknown_19[];
extern const u8 overworld_effect_script_unknown_20[];
extern const u8 overworld_effect_script_unknown_21[];
extern const u8 overworld_effect_script_unknown_22[];
extern const u8 overworld_effect_script_berry_tree_growth_sparkle[];
extern const u8 overworld_effect_script_deep_sand_footprints[];
extern const u8 overworld_effect_script_pokecenter_heal[];
extern const u8 overworld_effect_script_use_secret_power_tree[];
extern const u8 overworld_effect_script_use_secret_power_shrub[];
extern const u8 overworld_effect_script_tree_disguise[];
extern const u8 overworld_effect_script_mountain_disguise[];
extern const u8 overworld_effect_script_npcfly_out[];
extern const u8 overworld_effect_script_use_fly[];
extern const u8 overworld_effect_script_fly_in[];
extern const u8 overworld_effect_script_question_mark_icon[];
extern const u8 overworld_effect_script_feet_in_flowing_water[];
extern const u8 overworld_effect_script_bike_tire_tracks[];
extern const u8 overworld_effect_script_sand_disguise[];
extern const u8 overworld_effect_script_use_rock_smash[];
extern const u8 overworld_effect_script_use_dig[];
extern const u8 overworld_effect_script_sand_pile[];
extern const u8 overworld_effect_script_use_strength[];
extern const u8 overworld_effect_script_short_grass[];
extern const u8 overworld_effect_script_hot_springs_water[];
extern const u8 overworld_effect_script_use_waterfall[];
extern const u8 overworld_effect_script_use_dive[];
extern const u8 overworld_effect_script_pokeball[];
extern const u8 overworld_effect_script_x_icon[];
extern const u8 overworld_effect_script_nop_47[];
extern const u8 overworld_effect_script_nop_48[];
extern const u8 overworld_effect_script_pop_out_of_ash[];
extern const u8 overworld_effect_script_lavaridge_gym_warp[];
extern const u8 overworld_effect_script_sweet_scent[];
extern const u8 overworld_effect_script_sand_pillar[];
extern const u8 overworld_effect_script_bubbles[];
extern const u8 overworld_effect_script_sparkle[];
extern const u8 overworld_effect_script_secret_power_cave[];
extern const u8 overworld_effect_script_secret_power_tree[];
extern const u8 overworld_effect_script_secret_power_shrub[];
extern const u8 overworld_effect_script_cut_grass[];
extern const u8 overworld_effect_script_field_move_show_mon_init[];
extern const u8 overworld_effect_script_use_fly_ancient_tomb[];
extern const u8 overworld_effect_script_pcturn_on[];
extern const u8 overworld_effect_script_hall_of_fame_record[];
extern const u8 overworld_effect_script_use_teleport[];
extern const u8 overworld_effect_script_smiley_face_icon[];
extern const u8 overworld_effect_script_use_vs_seeker[];
extern const u8 overworld_effect_script_double_excl_mark_icon[];
extern const u8 overworld_effect_script_move_deoxys_rock[];
extern const u8 overworld_effect_script_unk_44[];
extern const u8 overworld_effect_script_unk_45[];
extern const u8 overworld_effect_script_explosion[];
extern const u8 overworld_effect_script_npc_transparent_flicker[];
extern const u8 overworld_effect_script_npc_transparent_fade[];

#endif