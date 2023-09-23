#include "types.h"
#include "worldmap.h"
#include "debug.h"

extern LZ77COMPRESSED gfx_worldmapTiles;
extern LZ77COMPRESSED gfx_worldmapMap;
extern color_t gfx_worldmapPal[80];

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

void worldmap_locate_player() {
	u8 bank = save1->bank;
	u8 map_idx = save1->map;
	s16 x = save1->x_cam_orig;
	s16 y = save1->y_cam_orig;
	const map_header_t *header = get_mapheader(bank, map_idx);
	int width = (int)(header->footer->width);
	int height = (int)(header->footer->height);
	
	worldmap_state->player_namespace = get_mapheader(bank, map_idx)->map_namespace;
	int segment_width = MAX(1, width / worldmap_positions[bank][map_idx].width);
	int segment_height = MAX(1, height / worldmap_positions[bank][map_idx].height);
	int segment_x = x / segment_width;
	int segment_y = y / segment_height;
	worldmap_state->cursor_x = (u16)(worldmap_positions[bank][map_idx].x + segment_x);
	worldmap_state->cursor_y = (u16)(worldmap_positions[bank][map_idx].y + segment_y);
	// DEBUG("Map width %d, height %d\n", width, height);
	// DEBUG("Segment width %d, height %d\n", segment_width, segment_height);
	// DEBUG("Segment x %d, y %d\n", segment_x, segment_y);
}