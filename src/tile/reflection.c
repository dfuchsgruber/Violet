#include "types.h"
#include "romfuncs.h"
#include "tile.h"

bool tile_is_reflective(u8 behavior){
    return behavior == 23 || behavior == 0xBA || tile_is_reflective_water(behavior);
}
