#include "types.h"
#include "worldmap.h"
#include "debug.h"

extern const LZ77COMPRESSED gfx_worldmapTiles;
extern const LZ77COMPRESSED gfx_worldmapMap;
extern const color_t gfx_worldmapPal[80];

extern const u8 worldmap0_position_data[WORLDMAP_HEIGHT][WORLDMAP_WIDTH];

const u8 (*const worldmap_namespaces[NUM_WORLDMAPS][NUM_WORLDMAP_LAYERS])[WORLDMAP_WIDTH] = {
    [WORLDMAP_THETO] = {
        [WORLDMAP_LAYER_GROUND] = worldmap0_position_data,
        [WORLDMAP_LAYER_CLOUDS] = worldmap0_position_data,
    },
    [WORLDMAP_ISLANDS] = {
        [WORLDMAP_LAYER_GROUND] = worldmap0_position_data,
        [WORLDMAP_LAYER_CLOUDS] = worldmap0_position_data,
    },
};

u8 worldmap_get_namespace_by_pos(u8 worldmap_index, u8 layer, u16 x, u16 y) {
    return worldmap_namespaces[worldmap_index][layer][y][x];
}

bool map_coordinates_to_worldmap_position(u8 bank, u8 map_idx, s16 x, s16 y, u8 *dst_x, u8 *dst_y, 
		u8 *dst_worldmap_idx, u8 *dst_layer) {
	const worldmap_position_t *position = &worldmap_positions[bank][map_idx];
	const map_header_t *header = get_mapheader(bank, map_idx);
	if (position && header) {
		u32 segment_width = MAX(1, header->footer->width / position->width);
        u32 segment_height = MAX(1, header->footer->height / position->height);
        *dst_x = (u8)(position->x + ((u32)x / segment_width));
        *dst_y = (u8)(position->y + ((u32)y / segment_height));
        *dst_worldmap_idx = position->worldmap_idx;
		*dst_layer = position->layer;
		DEBUG("Converted map coordinates %d, %d to worldmap position %d, %d, %d, %d", x, y, *dst_x, *dst_y, 
			*dst_worldmap_idx, *dst_layer);
		return true;
	}
	return false;
}

void worldmap_locate_player() {
	map_coordinates_to_worldmap_position(save1->bank, save1->map, save1->x_cam_orig, save1->y_cam_orig, 
		&worldmap_ui_state->player.x, &worldmap_ui_state->player.y, &worldmap_ui_state->player.idx, 
		&worldmap_ui_state->player.layer);
	DEBUG("Located player to %d, %d, %d, %d", worldmap_ui_state->player.x, worldmap_ui_state->player.y, 
		worldmap_ui_state->player.idx, worldmap_ui_state->player.layer);
}