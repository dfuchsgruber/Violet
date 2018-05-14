#include "types.h"
#include "callbacks.h"
#include "save.h"
#include "tile/fata_morgana.h"
#include "overworld/map_control.h"
#include "map/header.h"
#include <stdbool.h>


morgana_anim morgana_anims[36];
int fata_morgana_index_by_block(u16 block);
extern u16 fata_morgana_blocks[][3];
extern int fata_morgana_blocks_cnt[1];

void do_fata_morgana(){
    if ((*save1)->map == DESERT_MAP && (*save1)->bank == DESERT_BANK) {
        s16 coordinates[2];
        player_get_position(&coordinates[0], &coordinates[1]);
        //dprintf("Player at x %x, y %x\n", coordinates[0], coordinates[1]);
        
        
        //Perform binary search to identify the first block within range
        int low = 0;
        int high = fata_morgana_blocks_cnt[0];
        while(low != high){
            int mid = (low + high) / 2;
            //dprintf("Binsea low %d, mid %d, high %d\n", low, mid, high);
            if(fata_morgana_blocks[mid][1] < coordinates[1]  - 6 ||
                    (fata_morgana_blocks[mid][1] == coordinates[1]  - 6 && 
                    fata_morgana_blocks[mid][0] < coordinates[0] - 6)){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        int i = low;
        //dprintf("Binary search provided first candidate for morgana at %x, %x\n", fata_morgana_blocks[i][0] - 7, fata_morgana_blocks[i][1] - 7);
        
        while(i < fata_morgana_blocks_cnt[0] &&
                fata_morgana_blocks[i][1] <= coordinates[1] + 6){
            //dprintf("Iterating over i %d (of %d) at %x, %x\n", i, fata_morgana_blocks_cnt[0], fata_morgana_blocks[i][0] - 7, fata_morgana_blocks[i][1] - 7);
                //Iterate over all visible tiles (we need to scan only distinct lines)
                if(fata_morgana_blocks[i][0] <= coordinates[0] + 6){;
                //Block must be changed
                int dx = coordinates[0] - fata_morgana_blocks[i][0];
                int dy = coordinates[1] - fata_morgana_blocks[i][1];
                int l2_norm_sqr = (dx * dx) + (dy * dy); //L2 squared norm as distance metric (circle)
                int anim_index = fata_morgana_index_by_block(fata_morgana_blocks[i][2]);
                int frame;
                if(l2_norm_sqr <= 9) frame = 0;
                else if(l2_norm_sqr <= 16) frame = 1;
                else if(l2_norm_sqr <= 25) frame = 2;
                else frame = 3;
                //dprintf("Block at %x, %x with id %d, frame %d\n", fata_morgana_blocks[i][0], fata_morgana_blocks[i][1], anim_index, frame);
                block_set_by_pos((s16)fata_morgana_blocks[i][0], (s16)fata_morgana_blocks[i][1],
                        morgana_anims[anim_index].blocks[frame] | morgana_anims[anim_index].walkfield);
                map_draw_block((s16)fata_morgana_blocks[i][0], (s16)fata_morgana_blocks[i][1]);
                    //special_x8E_update_map_graphics();
            }
            i++;
        }
    }
}

void map_draw_block(s16 x, s16 y){
    int i = 2 * (x - (*save1)->x_cam_orig);
    int j = 2 * (y - (*save1)->y_cam_orig);
    if(i >= 0 && i < 0x20 && j >= 0 && j < 0x20){
        int x_tile = map_displ_cntrl->x_start + i;
        int y_tile = map_displ_cntrl->y_start + j;
        if(x_tile >= 0x20) x_tile -= 0x20;
        if(y_tile >= 0x20) y_tile -= 0x20;
        map_delta_to_map_tile(mapheader_virtual->footer, (u16)(0x20 * y_tile + x_tile),
                x, y);
    }
}


