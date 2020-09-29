/*
 * fading.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_FADING_H_
#define INCLUDE_C_FADING_H_

typedef struct {
    u32 affects;
    u8 delay : 6;
    u16 alpha : 5;
    u16 target_alpha : 5;
    u16 color : 15;
    u16 active : 1;
    u16 gp :6;
    u16 alpha_is_deacreasing:1; // whether blend coefficient is decreasing
    u16 buffer_transfer_disabled:1;
    u16 mode:2;
    u16 should_reset_bld_registers:1;
    u16 hardware_fade_finishing:1;
    u16 software_fade_finishing_counter:5;
    u16 software_fade_finishing:1;
    u16 oam_palette_toggle:1;
    u8 delta_alpha:4; // rate of change of blend coefficient
    u32 unused;
} stru_fading_cntrl;

extern stru_fading_cntrl fading_control;

/**
 * Updates all blending registers based on the values in the fading control
 **/
void fading_update_blending();

/**
 * Resets the entire fading control
 **/
void fading_control_reset();

/**
 * Checks if the fading control reports an active fading.
 * @return Weather fading is active
 */
bool fading_is_active();

/**
 * Initilaizes fadescreen.
 * @param type Fadescreen type
 * @param unkown TODO
 */
void fadescreen_all(u8 type, u8 unkown);

/**
 * Executes the next frame of the fading
 */
void fading_proceed();

/**
 * Resets the fading control
 */
void fading_cntrl_reset();

/**
 * Checks if fadescreen is active (should be equivalent to fading_is_active)
 * @return if fadescreen is active
 */
bool fadescreen_is_active();
/**
 *
 * @param affects bits 0-15 bg pals, bit 15-31 obj pals
 * @param duration delay between fading steps
 * @param from from which alpha to blend
 * @param to which alpha to blend
 * @param color the color to alpha blend over all palettes
 */
void fadescreen(u32 affects, u8 delay, u8 from, u8 to, u16 color);

/**
 * Initializes a fadescreen ensuring zeros in the dma3 source.
 **/
void fadescreen_and_clear_dma3_source();

#endif /* INCLUDE_C_FADING_H_ */
