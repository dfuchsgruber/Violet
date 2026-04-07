#ifndef H_TILE_INTERACTION_FLAVOR_TEXT
#define H_TILE_INTERACTION_FLAVOR_TEXT

#include "types.h"
#include "tile/coordinate.h"

#define NUM_FLAVOR_TEXTS 16 // is a 4-bit field in blocks

const u8 *behaviour_get_flavor_text_script(const UNUSED position_t *pos, u16 behaviour, UNUSED u8 facing_direction);

#endif