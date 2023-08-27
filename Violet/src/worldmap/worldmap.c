#include "types.h"
#include "worldmap.h"
#include "debug.h"

extern LZ77COMPRESSED gfx_worldmapTiles;
extern LZ77COMPRESSED gfx_worldmapMap;
extern color_t gfx_worldmapPal[80];

extern u8 worldmap0_position_data[WORLDMAP_HEIGHT][WORLDMAP_WIDTH];

u8 (*worldmap_namespaces[NUM_WORLDMAPS][NUM_WORLDMAP_LAYERS])[WORLDMAP_WIDTH] = {
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