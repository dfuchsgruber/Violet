#include "types.h"
#include "tile/block.h"

bool tile_is_reflective(u8 behavior){
    return behavior == 23 || behavior == 0xBA || tile_is_reflective_water(behavior);
}
