#include "types.h"
#include "superstate.h"

void callback_maintain();

/**
 * Callback to maintain common forwarding functions but do not interfere with animations
 **/
void callback_maintain() {
    vblank_handler_set(generic_vblank_handler);
    callback1_set(generic_callback1);
}
