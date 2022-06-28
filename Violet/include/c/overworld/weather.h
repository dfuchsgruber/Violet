#ifndef H_OVERWORLD_WEATHER
#define H_OVERWORLD_WEATHER

#include "types.h"
#include "color.h"
#include "oam.h"
#include "constants/map_weathers.h"

#define OVERWORLD_WEATHER_PAL_PROCESSING_STATE_CHANGING_WEATHER 0
#define OVERWORLD_WEATHER_PAL_PROCESSING_STATE_FADING_IN 1
#define OVERWORLD_WEATHER_PAL_PROCESSING_STATE_FADING_OUT 2
#define OVERWORLD_WEATHER_PAL_PROCESSING_STATE_IDLE 3

#define OVERWORLD_WEATHER_STATIC_FOG_PALETTE_BLENDING_ALPHA 12

#define MAX_RAIN_SPRITES             24
#define NUM_CLOUD_SPRITES            3
#define NUM_FOG_HORIZONTAL_SPRITES   20
#define NUM_ASH_SPRITES              20
#define NUM_FOG_DIAGONAL_SPRITES     20
#define NUM_SANDSTORM_SPRITES        20
#define NUM_SWIRL_SANDSTORM_SPRITES  5

#define DROUGHT_COLOR_INDEX(color) ((((color) >> 1) & 0xF) | (((color) >> 2) & 0xF0) | (((color) >> 3) & 0xF00))

enum {
    OVERWORLD_WEATHER_CHERRY_TREE_LEAVES_GFX_TAG = 0x1210,
};

color_t drought_colors[6][0x1000];

// Ugly macro to create wrappers that initialize the weather filters

#define WEATHER_FUNCTION_WITH_BLEND(weather_func)        \
    void weather_func##_with_blend() { \
        weather_set_filter(save1->map_weather); \
        weather_func(); \
    }

typedef struct {
    union
    {
        struct
        {
            struct oam_object *rainSprites[MAX_RAIN_SPRITES];
            struct oam_object *snowflakeSprites[51];
            struct oam_object *cherry_tree_sprites[50];
            struct oam_object *cloudSprites[NUM_CLOUD_SPRITES];
        } s1;
        struct
        {
            u8 filler0[0xA0];
            struct oam_object *fogHSprites[NUM_FOG_HORIZONTAL_SPRITES];
            struct oam_object *ashSprites[NUM_ASH_SPRITES];
            struct oam_object *fogDSprites[NUM_FOG_DIAGONAL_SPRITES];
            struct oam_object *sandstormSprites1[NUM_SANDSTORM_SPRITES];
            struct oam_object *sandstormSprites2[NUM_SWIRL_SANDSTORM_SPRITES];
        } s2;
    } sprites;
    u8 gamma_shifts[19][32];
    u8 alternative_gamma_shifts[19][32];
    s8 gamma;
    s8 gamma_to; // Target gamma for the next weather
    u8 gamma_step_delay;
    u8 gamma_step_frame;
    color_t fadescreen_target_color;
    u8 pal_processing_state;
    u8 fadescreen_cnt;
    u8 ready_to_initialize;
    u8 callback_idx;
    u8 is_fade_in_active;
    u8 fade_in_counter;
    u16 init_step;
    u16 finish_step;
    u8 current_weather;
    u8 next_weather;
    u8 weather_gfx_loaded;
    u8 weather_change_done;
    u8 custom_weather_oam_pal_idx;
    u8 alternative_gamma_oam_pal_idx;
    u16 rain_sprite_visible_count;
    u8 current_rain_oam_idx;
    u8 target_rain_oam_count;
    u8 rain_oam_count;
    u8 rain_oam_visible_delay;
    u8 rain_is_downpour;
    u8 rain_strength;
    u8 cloud_sprites_created;
    u16 snowflake_visible_count;
    u16 snowflake_sprites_created; //unknown_6E2;
    u8 snowflake_sprite_count;
    u8 target_snowflake_sprite_count;
    u16 unknown_6E6;
    u16 thunder_cnt;
    u8 unknown_6EA;
    u8 unknown_6EB;
    u8 unknown_6EC;
    u8 is_thunder_triggered;
    u16 fog_x_scroll_position;
    u16 fog_x_scroll_counter;
    u16 fog_x_scroll_offset;
    u8 static_fog_affected_pal_idxs[6]; // These palettes correspond to fog oams and have a different filter
    u8 static_fog_number_affected_pal_idxs;
    u8 fog_h_oams_created;
    u16 ash_base_oam_x;
    u16 unknown_6FE;
    u8 ash_oams_created;
    u32 sandstorm_x_offset;
    u32 sandstorm_y_offset;
    u8 rain_group_head;
    u8 snow_group_head;
    u16 sandstorm_base_oam_x;
    u16 sandstorm_y;
    u16 sandstorm_wave_idx;
    u16 sandstorm_num_waves;
    u8 sandstorm_oams_created;
    u8 sandstorm_swirl_oams_created;
    u16 fog_d_base_sprites_x;
    u16 fog_d_y;
    u16 fog_d_x_scroll;
    u16 fog_d_y_scroll;
    u16 fog_d_x_offset;
    u16 fog_d_y_offset;
    u8 fog_d_oams_created;
    u16 bubbles_delay_cnt;
    u16 bubbles_delay_idx;
    u16 bubbles_coordinates_idx;
    u16 num_bubbles_sprites;
    u8 bubbles_oams_created;
    u16 blend_eva_from;
    u16 blend_evb_from;
    u16 blend_eva_to;
    u16 blend_evb_to;
    u8 blend_update_cnt;
    u8 blend_frame_cnt;
    u8 blend_delay;
    s16 unknown_73C;
    s16 unknown_73E;
    s16 unknown_740;
    s16 unknown_742;
    u8 cherry_tree_num_oams;
    u8 cherry_tree_target_num_oams;
    u8 cherry_tree_new_timer;
    u8 cherry_tree_oam_group_head;
    u8 cherry_tree_num_oams_visible;
    u8 filler_744[0xD-7];
    s8 load_drought_pals_index;
    u8 load_drought_pals_offset;
} overworld_weather_stru;

extern overworld_weather_stru overworld_weather;

/**
 * Adds a palette idx that is affected by fog, i.e. it is blended with an average color of the fog oams.
 * @param pal_idx the palette idx to add
 **/ 
void overworld_weather_static_fog_add_affected_pal_idx(u8 pal_idx);

/**
 * Checks if a palette is affected by fog, i.e. it is supposed to be blended with an average color of the fog oams.
 * @param pal_idx the palette idx to check
 * @return if the palette is affected by fog
 **/
bool overworld_weather_static_fog_is_pal_affected(u8 pal_idx);

/**
 * Gets the average color of fog oams to blend over other oam palettes (since the fx of the GBA can not blend oams over oams).
 * @return the average color of fog oams, considering filters due to dns
 **/
color_t overworld_weather_static_fog_get_overlay_color();

/**
 * Checks if any overworld fading effect is active (e.g. weather)
 * @return if no overworld effect is active
 **/
bool overworld_fading_effect_finished();

/**
 * (Probably) a callback that handles overworld weather...
 * @param self self-reference
 **/
void overworld_weather_callback(u8 self);

/**
 * Callback for palette processing while the screen is fading in.
 * Sets-up gamma values and applies the correct gamma shift
 **/
void overworld_weather_fade_in();

/**
 * Sets the map filters according to a weather
 * @param weather The weather according to which to set filters
 **/
void weather_set_filter(u8 weather);

/**
 * @brief Sets the alpha blending coefficients of the overworld weather state
 * 
 * @param eva the a coefficient
 * @param evb the b coefficient
 */
void overworld_weather_set_blend_coefficients(u8 eva, u8 evb);

/**
 * @brief Sets the target alpha blending coefficients to "transtion" to
 * 
 * @param eva the a coefficient
 * @param evb the b coefficient
 * @param delay the step delay
 */
void overworld_weather_set_target_blend_coefficients(u8 eva, u8 evb, u8 delay);

/**
 * @brief Updates the current alpha blending coefficients towards the target coefficients
 * 
 * @return true if the target coefficients have been reached
 * @return false 
 */
bool overworld_weather_update_blend();

/**
 * @brief Fade-in with a fixed gamma value
 * 
 * @param gamma the gamma value
 * @return if the fading is still ongoing
 */
bool overworld_weather_fade_in_with_gamma(s8 gamma);

/**
 * @brief Fade-in with a fixed gamma value and the extreme sun filter
 * 
 * @param gamma the gamma value
 * @return if the fading is still ongoing
 */
bool overworld_weather_fade_in_with_gamma_and_drought(s8 gamma);

/**
 * @brief Fade-in with the static fog filter
 * 
 * @param gamma the gamma value
 * @return if the fading is still ongoing
 */
bool overworld_weather_fade_in_static_fog();

/**
 * @brief Applies a gamma shift and blending to all palettes and the extreme sun effect (drought)
 * 
 * @param gamma the gamma coefficient
 * @param alpha the alpha blending coefficient
 * @param target_color the target color to blend into
 */
void pal_gamma_shift_and_blend_and_drought(s8 gamma, u8 alpha, color_t target_color);

/**
 * @brief Applies fog alpha blending to all affected pals
 * 
 * @param alpha the coefficient
 * @param target_color the overlay color
 */
void pal_fog_blend_apply(u8 alpha, color_t target_color);

/**
 * @brief Loads an uncompressed palette and applies weather effects
 * 
 * @param pal The palette to load
 */
void overworld_weather_load_palette(const color_t *pal);

typedef struct {
    void (*initialize_variables)();
    void (*main)();
    void (*initialize_all)();
    bool (*closure)();
} weather_callbacks_t;

/**
 * @brief Main callback for executing the weather
 * 
 * @param self self-reference
 */
void overworld_weather_main(u8 self);

/**
 * @brief Computes the lookup tables for gamma shift effects
 * 
 */
void overworld_weather_build_gamma_shift_lookup_tables();

/**
 * @brief Callback for the initialization step of the weather callback
 * 
 * @param self self-reference
 */
void overworld_weather_callback_initialize(u8 self);

extern sprite overworld_weather_snow_sprite;
extern gfx_frame *overworld_weather_snow_animations[];
extern graphic overworld_weather_snow_graphics[];


extern color_t gfx_weather_defaultPal[16];

void weather_inside_initialize_variables();
void weather_inside_main();
void weather_inside_initialize_all();
bool weather_inside_closure();
void weather_sunny_with_cloud_reflection_initialize_variables();
void weather_sunny_with_cloud_reflection_main();
void weather_sunny_with_cloud_reflection_initialize_all();
bool weather_sunny_with_cloud_reflection_closure();
void weather_outside_initialize_variables();
void weather_outside_main();
void weather_outside_initialize_all();
bool weather_outside_closure();
void weather_rain_initialize_variables();
void weather_rain_main();
void weather_rain_initialize_all();
bool weather_rain_closure();
void weather_snow_initialize_variables();
void weather_snow_main();
void weather_snow_initialize_all();
bool weather_snow_closure();
void weather_thunder_initialize_variables();
void weather_thunder_main();
void weather_thunder_initialize_all();
bool weather_thunder_closure();
void weather_static_fog_initialize_variables();
void weather_static_fog_main();
void weather_static_fog_initialize_all();
bool weather_static_fog_closure();
void weather_ash_initialize_variables();
void weather_ash_main();
void weather_ash_initialize_all();
bool weather_ash_closure();
void weather_sandstorm_initialize_variables();
void weather_sandstorm_main();
void weather_sandstorm_initialize_all();
bool weather_sandstorm_closure();
void weather_dynamic_fog_initialize_variables();
void weather_dynamic_fog_main();
void weather_dynamic_fog_initialize_all();
bool weather_dynamic_fog_closure();
void weather_dense_fog_initialize_variables();
void weather_dense_fog_main();
void weather_dense_fog_initialize_all();
bool weather_dense_fog_closure();
void weather_cloudy_initialize_variables();
void weather_cloudy_main();
void weather_cloudy_initialize_all();
bool weather_cloudy_closure();
void weather_extreme_sun_initialize_variables();
void weather_extreme_sun_main();
void weather_extreme_sun_initialize_all();
bool weather_extreme_sun_closure();
void weather_extreme_thunder_initialize_variables();
void weather_extreme_thunder_main();
void weather_extreme_thunder_initialize_all();
bool weather_extreme_thunder_closure();
void weather_underwater_initialize_variables();
void weather_underwater_main();
void weather_underwater_initialize_all();
bool weather_underwater_closure();
void weather_weather_0f_initialize_variables();
void weather_weather_0f_main();
void weather_weather_0f_initialize_all();
bool weather_weather_0f_closure();
void weather_cherry_tree_leaves_initialize_variables();
void weather_cherry_tree_leaves_main();
void weather_cherry_tree_leaves_initialize_all();
bool weather_cherry_tree_leaves_closure();
void weather_light_static_fog_main();
void weather_light_static_fog_initialize_all();

/**
 * Waits for the sandstorm oam delay to finish and then runs the normal sandstorm callback
 * @param self self-reference
 **/
void overworld_weather_sandstorm_oam_callback_wait_for_delay(oam_object *self);

/**
 * Starts rain fall for a rain weather oam
 * @param o the oam
 **/
void overworld_weather_rain_oam_start_fall(oam_object *o);

/**
 * Starts the movement of a rain weather oam
 * @param o the oam
 * @param seed the seed
 **/
void overworld_weather_rain_oam_start_movement(oam_object *o, u16 seed);

/**
 * Waits for the rain delay to finish
 * @param self self-reference
 **/
void overworld_weather_rain_oam_callback_wait_for_delay(oam_object *self);

/**
 * Updates the rain oam after its delay is finished
 * @param self self-reference
 **/
void overworld_weather_rain_oam_callback_update(oam_object *self);

/**
 * Initializes the movement of a snowflake oam
 * @param self self-reference
 **/
void overworld_weather_snowflake_initialize(oam_object *self);

#endif