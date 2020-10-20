#include "types.h"
#include "callbacks.h"
#include "io.h"
#include "bios.h"
#include "anim_engine.h"
#include "music.h"
#include "bg.h"

void anim_engine_yin_yang_fade_big_callback(u8 self) {

    switch (big_callbacks[self].params[0]) {
        case 0:
        {
            //fadein
            u16 progress = big_callbacks[self].params[1]++;
            u16 value = (u16) (progress | ((0x1F - progress) << 8)); //coeffizent values for evb and eva
            io_set(0x50, 0x3F41);
            io_set(0x52, value);
            if (progress == 32) {
                big_callbacks[self].params[0]++; //next state
            }
            break;
        }
        case 1:
        {
            //init sound
            io_set(0x52, 0x1f);
            big_callbacks[self].params[0]++; //next state
            big_callbacks[self].params[1] = 80; //sound wait
            play_sound(8);
            break;
        }
        case 2:
        { //wait for sound
            io_set(0x52, 0x1f);
            if (!--big_callbacks[self].params[1]) {
                big_callbacks[self].params[0]++; //next state
            }
            break;
        }
        case 3:
        { //fadeout
            u16 progress = big_callbacks[self].params[1]++;
            u16 value = (u16) ((progress << 8) | (0x1F - progress)); //coeffizent values for evb and eva
            io_set(0x50, 0x3F41);
            io_set(0x52, value);
            if (progress == 32) {
                big_callbacks[self].params[0]++; //next state
            }
            break;
        }
        case 4:
        {
            //bg clear
            io_set(0x50, 0x1E40);
            int n = 0;
            cpuset(&n, bg_get_tilemap(0), 0x5000200); //fill bg with 0
            bg_virtual_sync(0);
            big_callback_delete(self);
            break;
        }
    }

}
