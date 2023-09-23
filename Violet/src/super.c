#include "types.h"
#include "superstate.h"

EWRAM int hook_tmp = 0;
EWRAM u8 dma0_dump[4] = {0};
EWRAM int gp_stack_size = 0;
EWRAM int gp_stack[GP_STACK_SIZE]  = {0};