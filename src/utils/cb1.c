#include "types.h"
#include "callbacks.h"
#include "romfuncs.h"

void cb1handling(){
    blend_proceed();
    oam_attributes_proceed();
    oam_attributes_copy();
    graphic_copy_queue_do();
    handle_pals();
    dma3_do();
    tbox_proceed();
    big_callbacks_proceed();
    oam_anim_proceed();
    u16 *hword_x02038604 = (u16*)0x02038604;
    *hword_x02038604 = 0; //no idea why to do this, but needs to be done for some reason
}