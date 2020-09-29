#ifndef H_DNS
#define H_DNS

#include "types.h"
#include "color.h"

#define CEOMETRIA_GYM_PUNISHMENT_ROOM_BANK 19
#define CEOMETRIA_GYM_PUNISHMENT_ROOM_MAP_IDX 7

enum {
    DAYTIME_DAY = 0,
    DAYTIME_MORNING,
    DAYTIME_EVENING,
    DAYTIME_NIGHT,
}; 

/**
 * Gets the current daytime (even if the dns is inactive)
 **/
u8 dns_get_daytime();

enum {
    PAL_FILTER_NONE = 0,
    PAL_FILTER_ALPHA_BLENDING,
    PAL_FILTER_COLOR_MULTIPLIY,
    PAL_FILTER_SUBTRACTION,
};

/**
 * Applies dns and weather filters to the filtered palset
 **/
void pal_filters_apply();

/**
 * Returns the color that is as alpha blending filter depending on a shader state.
 * @param shader_state the shader state
 * @return the overlay color for alpha blending
 **/
color_t dns_get_overlay(u8 shader_state);

/**
 * Returns the alpha value for the alpha blending filter depending on the shader state
 * @param shader_state the shader state
 * @rerutn the alpha value
 **/
u8 dns_get_alpha(u8 shader_state);

/**
 * Applies the filter given by the DNS system to pal_restore if it is on
 * @param start_color the first color to affect
 * @param number_colors the number of colors to affect
 * @param overlay the color of the upper layer for alpha blending
 * @param alpha the alpha value of the alpha blending
 **/ 
void dns_blend_colors(u16 start_col, u16 col_cnt, color_t overlay, u8 alpha);

void battle_bg_load(u8 bg_id);


void callback_switch_timezone();
void update_timezone();
bool is_inside_map(u8 bank, u8 map);

/**
 * Checks if a dns shader is to be applied or not.
 * @return if dns shaders are to be applied
 **/
bool dns_on();

extern u8 pal_shaders;

#endif
