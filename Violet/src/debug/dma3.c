#include "types.h"
#include "debug.h"
#include "superstate.h"
#include "prng.h"

void dma3_debug(u8 *src, u8 *dst, u16 size) {
    dprintf("Dma3copy 0x%x to 0x%x size 0x%x cnt %d\n", src, dst, size, _main_rnd);
}