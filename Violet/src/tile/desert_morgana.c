#include "types.h"
#include "callbacks.h"
#include "save.h"
#include "tile/fata_morgana.h"
#include "overworld/map_control.h"
#include "map/header.h"
#include "debug.h"

static void fata_morgana_setmaptiles(bool redraw) {
    if (save1->map == DESERT_MAP && save1->bank == DESERT_BANK) {
        s16 coordinates[2];
        player_get_coordinates(&coordinates[0], &coordinates[1]);
        // Binary Search to find the first block that needs to be considered
        int low = 0;
        int high = fata_morgana_blocks_cnt[0];
        while(low != high){
            int mid = (low + high) / 2;
            if(fata_morgana_blocks[mid][1] < coordinates[1]  - 8 ||
                    (fata_morgana_blocks[mid][1] == coordinates[1]  - 8 && 
                    fata_morgana_blocks[mid][0] < coordinates[0] - 8)){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        int i = low;
        while(i < fata_morgana_blocks_cnt[0] &&
                fata_morgana_blocks[i][1] <= coordinates[1] + 8){
            // Update blocks until a block out of sight-range is reached
            if(fata_morgana_blocks[i][0] <= coordinates[0] + 8){
                //Block must be changed
                int dx = coordinates[0] - fata_morgana_blocks[i][0];
                int dy = coordinates[1] - fata_morgana_blocks[i][1];
                int l2_norm_sqr = (dx * dx) + (dy * dy); // L2 squared norm as distance metric (circle)
                int anim_index = fata_morgana_index_by_block(fata_morgana_blocks[i][2]);
                int frame;
                if(l2_norm_sqr <= 9) frame = 0;
                else if(l2_norm_sqr <= 16) frame = 1;
                else if(l2_norm_sqr <= 25) frame = 2;
                else frame = 3;
                block_set_by_pos((s16)fata_morgana_blocks[i][0], (s16)fata_morgana_blocks[i][1],
                        morgana_anims[anim_index].blocks[frame] | morgana_anims[anim_index].walkfield);
                if (redraw) 
                    map_redraw_block_at_position((s16)fata_morgana_blocks[i][0], (s16)fata_morgana_blocks[i][1]);
            }
            i++;
        }
    }
}

void do_fata_morgana(){
    fata_morgana_setmaptiles(true);
}

void fata_morgana_update_blocks_dont_redraw() {
    fata_morgana_setmaptiles(true);
    s16 coordinates[2];
    player_get_coordinates(&coordinates[0], &coordinates[1]);
    dprintf("Fata morgana player at %d, %d\n", coordinates[0], coordinates[1]);
}



