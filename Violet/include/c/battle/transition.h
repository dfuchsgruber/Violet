#ifndef H_BATTLE_TRANSITION
#define H_BATTLE_TRANSITION

#include "callbacks.h"
#include "constants/battle/battle_transitions.h"
#include "types.h"

typedef struct {
    vu8 vblank_dma;
    u16 win_in;
    u16 win_out;
    u16 win0H;
    u16 win0V;
    u16 win1H; // not used
    u16 win1V;
    u16 bld_cnt;
    u16 bld_alpha;
    u16 bld_y;
    s16 bg123HOfs;
    s16 bg123VOfs;
    s16 bg0HOfsOpponent;
    s16 bg0HOfsPlayer;
    s16 bg0VOfs;
    s16 unused_1E;
    s16 counter;
    s16 unused_22;
    s16 data[11]; // for multiple purposes
} battle_transition_state_t;

extern battle_transition_state_t *battle_transition_state;

/**
 * Draws a circle at a given coordinate and radius into a buffer.
 * @param buffer where to put the win values
 * @param x center x coordinate
 * @param y center y coordinate
 * @param radius radius of the circle
 */
void battle_transition_generate_circle(u16 *buffer, s16 x, s16 y, s16 radius);

/**
 * Generates a wave into the dma0 buffer.
 * @param buffer where to put the values
 * @param offset offset of the wave
 * @param theta the current angle
 * @param frequency frequency of the sine wave
 * @param aplitude aplitude of the wave
 * @param buffer_size size of the buffer
 */
void battle_transition_generate_wave(u16 *buffer, s16 offset, s16 theta, s16 frequency, s16 aplitude, size_t buffer_size);

/**
 * Fades all palettes to black.
 */
void battle_transition_fade_pals_to_black();

/**
 * Gets the bg0 resources for the battle transition.
 * @param tilemap where to put the tilemap
 * @param tileset where to put the tileset
 */
void battle_transition_get_bg0_tilemap_and_tileset(u16 **tilemap, void **tileset);

/**
 * Gets the current map's transition type.
 * @return transition type the map's transition type
 */
u8 battle_transition_type_get_by_map();

/**
 * Callback function for the first phase of battle transition: Blinking
 * @param self self-reference
 */
void battle_transition_phase_1_blink(u8 self);

void battle_transition_phase_2_blur(u8 self);
void battle_transition_phase_2_distorted_wave(u8 self);
void battle_transition_phase_2_horizontal_corrugate(u8 self);
void battle_transition_phase_2_big_pokeball(u8 self);
void battle_transition_phase_2_sliding_pokeballs(u8 self);
void battle_transition_phase_2_clockwise_blackfade(u8 self);
void battle_transition_phase_2_fullscreen_wave(u8 self);
void battle_transition_phase_2_black_wave_to_right(u8 self);
void battle_transition_phase_2_sliced_screen(u8 self);
void battle_transition_phase_2_whitefade_in_stripes(u8 self);
void battle_transition_phase_2_grid_squares(u8 self);
void battle_transition_phase_2_black_doodles(u8 self);
void battle_transition_phase_2_lorelei(u8 self);
void battle_transition_phase_2_bruno(u8 self);
void battle_transition_phase_2_agatha(u8 self);
void battle_transition_phase_2_lance(u8 self);
void battle_transition_phase_2_blue(u8 self);
void battle_transition_phase_2_anti_clockwise_spiral(u8 self);

// Steps for the big pokeball battle transition
bool battle_transition_big_pokeball_phase_2_initialize(big_callback *self);
bool battle_transition_big_pokeball_phase_2_initialize_tilemap_and_wave(big_callback *self);
bool battle_transition_big_pokeball_phase_2_wave_1_increment_eva(big_callback *self);
bool battle_transition_big_pokeball_phase_2_wave_2_increment_evb(big_callback *self);
bool battle_transition_big_pokeball_phase_2_wave_3(big_callback *self);
bool battle_transition_big_pokeball_phase_2_circle_effect(big_callback *self);

/**
 * Vblank handler after the circle effect of the big pokeball battle transition has finished.
 */
void battle_transition_big_pokeball_vblank_handler_after_circle();

#endif
