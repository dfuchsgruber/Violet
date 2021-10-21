#include "item/pokeball.h"
#include "pokemon/virtual.h"
#include "types.h"
#include "version.h"

void alpha_3_0_fix_pokemon_pokeball(box_pokemon *p) {
    u8 ball = (u8)box_pokemon_get_attribute(p, ATTRIBUTE_CATCH_INFO, NULL);
    ball = item_idx_to_pokeball_idx((u16)(ball >> 1));
    box_pokemon_set_attribute(p, ATTRIBUTE_CATCH_INFO, &ball);
}
