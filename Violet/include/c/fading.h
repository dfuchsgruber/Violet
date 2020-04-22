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
    u16 alpha : 5;
    u16 target_alpha : 5;
    u16 color : 15;
    u16 active : 1;
    u8 field_8 : 7;
    u8 buffer_transfer_enabled : 1;
    u8 field_9;
    u8 field_A;
    u8 field_B;

} stru_fading_cntrl;

extern stru_fading_cntrl fading_control;

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
 * @param p1
 * @param p2
 * @param p3
 * @param color
 */
void fadescreen(u32 affects, u8 p1, u8 p2, u8 p3, u16 color);

/**
 * Initializes a fadescreen ensuring zeros in the dma3 source.
 **/
void fadescreen_and_clear_dma3_source();

#endif /* INCLUDE_C_FADING_H_ */
