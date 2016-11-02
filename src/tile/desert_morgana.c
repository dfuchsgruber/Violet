#include "types.h"
#include "romfuncs.h"
#include "oams.h"
#include "callbacks.h"
#include "battle.h"
#include "basestats.h"
#include "trainer.h"
#include "item.h"
#include "save.h"
#include <stdbool.h>
#include "unaligned_types.h"



static morgana_anim anims[36] = {
    {
        {0x320, 0x322, 0x324, 0x326}, 0x0},
    {
        {0x321, 0x323, 0x325, 0x327}, 0x0},
    {
        {0x328, 0x32a, 0x32c, 0x32e}, 0xC00},
    {
        {0x329, 0x32b, 0x32d, 0x32f}, 0xC00},
    {
        {0x330, 0x332, 0x334, 0x336}, 0xC00},
    {
        {0x331, 0x333, 0x335, 0x337}, 0xC00},
    {
        {0x338, 0x33a, 0x33c, 0x33e}, 0xC00},
    {
        {0x339, 0x33b, 0x33d, 0x33f}, 0xC00},
    {
        {0x340, 0x342, 0x344, 0x346}, 0xC00},
    {
        {0x341, 0x343, 0x345, 0x347}, 0xC00},

    {
        {0x34e, 0x34c, 0x34a, 0x348}, 0x0},
    {
        {0x34f, 0x34d, 0x34b, 0x349}, 0x0},
    {
        {0x356, 0x354, 0x352, 0x350}, 0x0},
    {
        {0x357, 0x355, 0x353, 0x351}, 0x0},
    {
        {0x35e, 0x35c, 0x35a, 0x358}, 0x0},
    {
        {0x35f, 0x35d, 0x35b, 0x359}, 0x0},
    {
        {0x366, 0x364, 0x362, 0x360}, 0x0},
    {
        {0x367, 0x365, 0x363, 0x361}, 0x0},
    {
        {0x36e, 0x36c, 0x36a, 0x368}, 0x0},
    {
        {0x36f, 0x36d, 0x36b, 0x369}, 0x0},

    {
        {0x376, 0x374, 0x372, 0x370}, 0x0},
    {
        {0x377, 0x375, 0x373, 0x371}, 0x0},
    {
        {0x37e, 0x37c, 0x37a, 0x378}, 0x0},
    {
        {0x37f, 0x37d, 0x37b, 0x379}, 0x0},
    {
        {0x386, 0x384, 0x382, 0x380}, 0x0},
    {
        {0x387, 0x385, 0x383, 0x381}, 0x0},

    {
        {0x38e, 0x38c, 0x38a, 0x388}, 0x0},
    {
        {0x38f, 0x38d, 0x38b, 0x389}, 0x0},
    {
        {0x396, 0x394, 0x392, 0x390}, 0x0},
    {
        {0x397, 0x395, 0x393, 0x391}, 0x0},
    {
        {0x39e, 0x39c, 0x39a, 0x398}, 0x0},
    {
        {0x39f, 0x39d, 0x39b, 0x399}, 0x0},
    {
        {0x3a6, 0x3a4, 0x3a2, 0x3a0}, 0x0},
    {
        {0x3a7, 0x3a5, 0x3a3, 0x3a1}, 0x0},
    {
        {0x3ae, 0x3ac, 0x3aa, 0x3a8}, 0x0},
    {
        {0x3af, 0x3ad, 0x3ab, 0x3a9}, 0x0}
};

void do_fata_morgana() {

    if ((*save1)->map == DESERT_MAP && (*save1)->bank == DESERT_BANK) {
        s16 coordinates[2];
        get_current_tile_position(&coordinates[0], &coordinates[1]);
        bool matched = false;

        //change all tiles within the players vision +1 
        int x;
        for (x = -8; x <= 8; x++) {
            int y;
            for (y = -6; y <= 6; y++) {

                s16 cx = (s16) (x + coordinates[0]);
                s16 cy = (s16) (y + coordinates[1]);
                if (cx >= 0 && cy >= 0) {

                    u16 block = get_block_id(cx, cy);
                    //scanning the anim table if we find matches
                    if (block >= 0x320) {


                        int z = (block & 1) + (((block - 0x320) / 8)*2);

                        if (anims[z].blocks[0] == block || anims[z].blocks[1] == block || anims[z].blocks[2] == block || anims[z].blocks[3] == block) {
                            matched = true;
                            //now we have to find the current index based on the distance to the player (we use a circle as border)
                            int dx = cx - coordinates[0];
                            int dy = cy - coordinates[1];
                            int distance_squared = (dx * dx) + (dy * dy);
                            int frame;
                            if (distance_squared <= 9) {
                                frame = 0;
                            } else if (distance_squared <= 16) {
                                frame = 1;
                            } else if (distance_squared <= 25) {
                                frame = 2;
                            } else {
                                frame = 3;
                            }
                            u16 new_block = anims[z].blocks[frame];
                            if (new_block != block) {
                                set_block_id(cx, cy, (new_block | anims[z].walkfield));
                            }
                        }
                    }

                }
            }
        }
        if (matched) {
            special_x8E_update_map_graphics();
        }


    }

}