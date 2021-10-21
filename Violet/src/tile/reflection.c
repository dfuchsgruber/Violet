#include "tile/block.h"
#include "types.h"

bool tile_is_reflective(u8 behavior) {
    return behavior == 0xBA || behaviour_is_reflective_water(behavior);
}
