/*
 * generic_callback1.c
 *
 *  Created on: May 1, 2018
 *      Author: dominik
 */


#include "types.h"
#include "superstate.h"
#include "fading.h"
#include "oam.h"
#include "vram.h"
#include "color.h"
#include "dma.h"
#include "text.h"
#include "callbacks.h"

void generic_callback1(){
    big_callback_proceed();
    fading_proceed();
    tbox_proceed();
    oam_anim_proceed();
    oam_proceed();
    u16 *hword_x02038604 = (u16*)0x02038604;
    *hword_x02038604 = 0; //no idea why to do this, but needs to be done for some reason
}

void generic_vblank_handler() {
    oam_attributes_copy();
    graphic_queue_proceed();
    pal_proceed();
    dma0_proceed();
    dma3_queue_proceed();
}

