#include "types.h"
#include "overworld/script.h"
#include "item/item.h"
#include "text.h"
#include "language.h"
#include "vars.h"
#include "debug.h"

static u8 str_times[] = PSTRING("FONT_SIZE_SMALL×FONT_SIZE_BIG");

bool overworld_script_command_xd4_bufferitemnameplural(overworld_script_state_t *state) {
    u8 buffer_idx = state->script[0];
    state->script++;
    u16 item_idx =  var_get(overworld_script_read_hword(state));
    u16 cnt = var_get(overworld_script_read_hword(state));
    u8 *dst = ow_script_string_buffers[buffer_idx];
    DEBUG("buffer item name plural for item %d, count %d, buffer %d\n", item_idx, cnt, buffer_idx);
    dst[0] = 0xFF;
    if (cnt > 1) {
        u8 str_cnt[8];
        itoa(str_cnt, cnt, ITOA_NO_PADDING, (u8)((cnt / 10) + 1));
        strcat(dst, str_cnt);
        strcat(dst, str_times);
        strcat(dst, item_get_name(item_idx));
    } else {
        strcpy(dst, item_get_name(item_idx));
    }
    return false;
} 
