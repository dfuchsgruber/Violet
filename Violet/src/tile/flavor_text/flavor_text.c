

#include "tile/block.h"
#include "types.h"
#include "tile/coordinate.h"
#include "constants/block_arguments.h"
#include "constants/block_behaviour.h"

extern const u8 ow_script_flavor_text_inside_piano[];

static const u8 *flavor_text_scripts_inside[] = {
    [FLAVOR_TEXT_INSIDE_PIANO] = ow_script_flavor_text_inside_piano,
};


const u8 *behaviour_get_flavor_text_script(UNUSED position_t *pos, u16 behaviour, UNUSED u8 facing_direction) {
    position_t faced_position;
	player_get_position_faced(&faced_position);
    switch (behaviour) {
        case MB_FLAVOR_TEXT_INSIDE: {
            return flavor_text_scripts_inside[block_get_field_by_pos(faced_position.coordinates.x, faced_position.coordinates.y, FIELD_ARGUMENT)];
        }
    }
    return NULL;
}