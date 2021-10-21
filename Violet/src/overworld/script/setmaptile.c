#include "overworld/script.h"
#include "tile/block.h"
#include "types.h"

bool overworld_script_command_setmaptile(overworld_script_state_t *state) {
    int x = overworld_script_read_hword(state) + 7;
    int y = overworld_script_read_hword(state) + 7;
    u16 block_and_level = overworld_script_read_hword(state);
    if (overworld_script_read_hword(state) > 0) {
        block_set_by_pos_with_level((s16)x, (s16)y, block_and_level | 0xC00);
    } else {
        block_set_by_pos_with_level((s16)x, (s16)y, block_and_level);
    }
    return false;
}
