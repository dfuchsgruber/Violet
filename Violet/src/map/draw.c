#include "types.h"
#include "map/footer.h"
#include "bg.h"

void map_draw_block_to_bg(u8 layer_type, u16 *blocks, u16 offset) {
    // The layer priority (bottom to top) is 3, 1, 2
    if (layer_type == 0xFF) { // Doors, TODO        
        overworld_bg3_tilemap[offset] = blocks[0];
        overworld_bg3_tilemap[offset + 1] = blocks[1];
        overworld_bg3_tilemap[offset + 32] = blocks[2];
        overworld_bg3_tilemap[offset + 32 + 1] = blocks[3];
        
        overworld_bg1_tilemap[offset] = 0;
        overworld_bg1_tilemap[offset + 1] = 0;
        overworld_bg1_tilemap[offset + 32] = 0;
        overworld_bg1_tilemap[offset + 32 + 1] = 0;

        overworld_bg2_tilemap[offset] = blocks[4];
        overworld_bg2_tilemap[offset + 1] = blocks[5];
        overworld_bg2_tilemap[offset + 32] = blocks[6];
        overworld_bg2_tilemap[offset + 32 + 1] = blocks[7];
    } else {
        overworld_bg3_tilemap[offset] = blocks[0];
        overworld_bg3_tilemap[offset + 1] = blocks[1];
        overworld_bg3_tilemap[offset + 32] = blocks[2];
        overworld_bg3_tilemap[offset + 32 + 1] = blocks[3];
        
        overworld_bg1_tilemap[offset] = blocks[4];
        overworld_bg1_tilemap[offset + 1] = blocks[5];
        overworld_bg1_tilemap[offset + 32] = blocks[6];
        overworld_bg1_tilemap[offset + 32 + 1] = blocks[7];

        overworld_bg2_tilemap[offset] = blocks[8];
        overworld_bg2_tilemap[offset + 1] = blocks[9];
        overworld_bg2_tilemap[offset + 32] = blocks[10];
        overworld_bg2_tilemap[offset + 32 + 1] = blocks[11];
    }
    bg_virtual_sync_reqeust_push(1);
    bg_virtual_sync_reqeust_push(2);
    bg_virtual_sync_reqeust_push(3);
}