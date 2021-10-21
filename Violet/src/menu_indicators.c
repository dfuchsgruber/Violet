#include "menu_indicators.h"
#include "callbacks.h"
#include "oam.h"
#include "types.h"

void scroll_indicator_set_oam_priority(u8 callback_idx, u8 arrow0_priority, u8 arrow1_priority) {
    scroll_indicator_state *state = (scroll_indicator_state *)(big_callbacks[callback_idx].params);
    oams[state->arrow0_oam_idx].final_oam.attr2 &= (u16)(~ATTR2_PRIO(3));
    oams[state->arrow0_oam_idx].final_oam.attr2 |= (u16)(ATTR2_PRIO(arrow0_priority));
    oams[state->arrow1_oam_idx].final_oam.attr2 &= (u16)(~ATTR2_PRIO(3));
    oams[state->arrow1_oam_idx].final_oam.attr2 |= (u16)(ATTR2_PRIO(arrow1_priority));
}
