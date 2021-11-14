#ifndef H_OVERWORLD_UPSTREAM
#define H_OVERWORLD_UPSTREAM

#include "types.h"
#include "oam.h"

#define NUM_OVERWORLD_STATIC_EFFECTS 8
#define OVERWORLD_STATIC_EFFECT_EMPTY 0xFF

typedef struct {
    // This is where the effect currently is, it may shift position on map change
    u8 bank;
    u8 map_idx;
    s16 x;
    s16 y;
    u8 idx;
    u8 oam_idx;
    u8 height;
    u8 width;
    u8 collision : 1;
} overworld_static_effect_t;

typedef struct {
    u8 idx;
    u8 collision : 1;
    s16 x;
    s16 y;
    u8 width;
    u8 height;
    oam_template template_;
    palette uncompressed_palette;
} overworld_static_effect_template_t;

/**
 * Creates static overworld effects that are within the viewport
 * @param camera_dx camera offset
 * @param camera_dy camera offset
 **/
void overworld_static_effect_create_within_viewport(s16 camera_dx, s16 camera_dy);

/**
 * Deletes all static overworld effects that are outside the viewport
 **/
void overworld_static_effect_delete_outside_viewport();

/**
 * Initializes static overworld effects (on map return)
 **/
void overworld_static_effects_initialize();

/**
 * Gets an overworld effect
 * @param idx the idx of the effect to get
 * @param bank on which bank
 * @param map on which map
 * @return the idx of the effect in `fmem.overworld_static_effects`
 **/
int overworld_static_effect_get(int idx, int bank, int map_idx);

#endif