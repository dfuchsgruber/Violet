#include "types.h"
#include "romfuncs.h"

void callback_maintain();

/**
 * Callback to maintain common forwarding functions but do not interfere with animations
 **/
void callback_maintain() {
    generic_callback1();
}
