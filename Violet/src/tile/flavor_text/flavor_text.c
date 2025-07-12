

#include "constants/block_arguments.h"
#include "constants/block_behaviour.h"
#include "tile/block.h"
#include "tile/coordinate.h"
#include "types.h"

extern const u8 ow_script_flavor_text_inside_piano[];
extern const u8 ow_script_flavor_text_inside_fridge[];
extern const u8 ow_script_flavor_text_inside_bookshelf_0[];
extern const u8 ow_script_flavor_text_inside_bookshelf_1[];
extern const u8 ow_script_flavor_text_inside_bookshelf_2[];
extern const u8 ow_script_flavor_text_inside_bookshelf_3[];
extern const u8 ow_script_flavor_text_inside_showcase[];
extern const u8 ow_script_flavor_text_inside_clock[];
extern const u8 ow_script_flavor_text_inside_vase[];
extern const u8 ow_script_flavor_text_inside_picture_frame_0[];
extern const u8 ow_script_flavor_text_inside_picture_frame_1[];
extern const u8 ow_script_flavor_text_inside_picture_frame_2[];
extern const u8 ow_script_flavor_text_inside_picture_frame_3[];
extern const u8 ow_script_flavor_text_inside_picture_waves[];
extern const u8 ow_script_flavor_text_inside_sink[];
extern const u8 ow_script_flavor_text_inside_stove[];
extern const u8 ow_script_flavor_text_inside_kitchen_cupboard[];
extern const u8 ow_script_flavor_text_inside_wardrobe[];
extern const u8 ow_script_flavor_text_inside_bed[];
extern const u8 ow_script_flavor_text_inside_drawers[];
extern const u8 ow_script_flavor_text_inside_flower_pot[];
extern const u8 ow_script_flavor_text_inside_lamp[];

static const u8 *flavor_text_scripts_inside[] = {
    [FLAVOR_TEXT_INSIDE_PIANO] = ow_script_flavor_text_inside_piano,
    [FLAVOR_TEXT_INSIDE_FRIDGE] = ow_script_flavor_text_inside_fridge,
    [FLAVOR_TEXT_INSIDE_BOOKSHELF_0] = ow_script_flavor_text_inside_bookshelf_0,
    [FLAVOR_TEXT_INSIDE_BOOKSHELF_1] = ow_script_flavor_text_inside_bookshelf_1,
    [FLAVOR_TEXT_INSIDE_BOOKSHELF_2] = ow_script_flavor_text_inside_bookshelf_2,
    [FLAVOR_TEXT_INSIDE_BOOKSHELF_3] = ow_script_flavor_text_inside_bookshelf_3,
    [FLAVOR_TEXT_INSIDE_SHOWCASE] = ow_script_flavor_text_inside_showcase,
    [FLAVOR_TEXT_INSIDE_CLOCK] = ow_script_flavor_text_inside_clock,
    [FLAVOR_TEXT_INSIDE_VASE] = ow_script_flavor_text_inside_vase,
    [FLAVOR_TEXT_INSIDE_PICTURE_FRAME_0] = ow_script_flavor_text_inside_picture_frame_0,
    [FLAVOR_TEXT_INSIDE_PICTURE_FRAME_1] = ow_script_flavor_text_inside_picture_frame_1,
    [FLAVOR_TEXT_INSIDE_PICTURE_FRAME_2] = ow_script_flavor_text_inside_picture_frame_2,
    [FLAVOR_TEXT_INSIDE_PICTURE_FRAME_3] = ow_script_flavor_text_inside_picture_frame_3,
    [FLAVOR_TEXT_INSIDE_PICTURE_WAVES] = ow_script_flavor_text_inside_picture_waves,
    [FLAVOR_TEXT_INSIDE_SINK] = ow_script_flavor_text_inside_sink,
    [FLAVOR_TEXT_INSIDE_STOVE] = ow_script_flavor_text_inside_stove,
};

static const u8 *flavor_text_scripts_inside_2[] = {
    [FLAVOR_TEXT_INSIDE_KITCHEN_CUPBOARD] = ow_script_flavor_text_inside_kitchen_cupboard,
    [FLAVOR_TEXT_INSIDE_WARDROBE] = ow_script_flavor_text_inside_wardrobe,
    [FLAVOR_TEXT_INSIDE_BED] = ow_script_flavor_text_inside_bed,
    [FLAVOR_TEXT_INSIDE_DRAWERS] = ow_script_flavor_text_inside_drawers,
    [FLAVOR_TEXT_INSIDE_FLOWER_POT] = ow_script_flavor_text_inside_flower_pot,
    [FLAVOR_TEXT_INSIDE_LAMP] = ow_script_flavor_text_inside_lamp

};

const u8 *behaviour_get_flavor_text_script(UNUSED position_t *pos, u16 behaviour, UNUSED u8 facing_direction) {
    position_t faced_position;
    player_get_position_faced(&faced_position);
    switch (behaviour) {
        case MB_FLAVOR_TEXT_INSIDE: {
            return flavor_text_scripts_inside[block_get_field_by_pos(faced_position.coordinates.x, faced_position.coordinates.y, FIELD_ARGUMENT)];
        }
        case MB_FLAVOR_TEXT_INSIDE_2: {
            return flavor_text_scripts_inside_2[block_get_field_by_pos(faced_position.coordinates.x, faced_position.coordinates.y, FIELD_ARGUMENT)];
        }
    }
    return NULL;
}