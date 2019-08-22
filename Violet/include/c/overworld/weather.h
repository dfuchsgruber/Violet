#ifndef H_OVERWORLD_WEATHER
#define H_OVERWORLD_WEATHER

#include "types.h"
#include "color.h"

#define OVERWORLD_WEATHER_PAL_PROCESSING_STATE_CHANGING_WEATHER 0
#define OVERWORLD_WEATHER_PAL_PROCESSING_STATE_FADING_IN 1
#define OVERWORLD_WEATHER_PAL_PROCESSING_STATE_FADING_OUT 2
#define OVERWORLD_WEATHER_PAL_PROCESSING_STATE_IDLE 3

#define OVERWORLD_WEATHER_STATIC_FOG_PALETTE_BLENDING_ALPHA 12

typedef struct {
    u8 unknown[1728];
    s8 gamma;
    u8 field_1729;
    u8 field_1730;
    u8 field_1731;
    color_t fadescreen_target_color;
    u8 pal_processing_state;
    u8 fadescreen_cnt;
    u8 ready_to_initialize;
    u8 callback_idx;
    u8 field_1738;
    u8 field_1739;
    u16 init_step;
    u16 finish_step;
    u8 current_weather;
    u8 next_weather;
    u8 weather_gfx_loaded;
    u8 unknown2[33];
    u8 static_fog_affected_pal_idxs[6]; // These palettes correspond to fog oams and have a different filter
    u8 static_fot_number_affected_pal_idxs;
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

#endif