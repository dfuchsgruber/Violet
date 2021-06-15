#include "types.h"
#include "save.h"
#include "debug.h"
#include "tile/hidden_item.h"
#include "constants/items.h"
#include "constants/flags.h"
#include "overworld/npc.h"
#include "vars.h"
#include "flags.h"
#include "constants/signpost_types.h"

u8 *singpost_behavior_xBC(){
    //trigger script by block id (since we do not have enough behaviorbytes...)
    coordinate_t pos;
    player_get_facing_position(&pos.x, &pos.y);
    u16 block_id = block_get_by_pos(pos.x, pos.y) & 0x3FF;
    (void)block_id;
    return NULL;
    
}

u16 hidden_flag_by_chunk(u8 flag, u8 hidden_chunk){
    switch(hidden_chunk){
        case 0:
            return (u16)(0x3E8 + flag);
        case 1:
            return (u16)(0xb00 + flag);
        case 2:
            return (u16)(0xc00 + flag);
        case 3:
            return (u16)(0xd00 + flag);
        default:
            err2( ERR_HIDDEN_FLAG_CHUNK_GT_3, hidden_chunk);
            return 0;
    }
}

void _test_flags() {
    for (u16 i = 1000; i < 1100; i++) {
        if (checkflag(i)) {
            dprintf("flag set %d\n", i);
        }
    }
}


int hidden_item_get_field(hidden_item_t hidden_item, u8 field){
    switch(field){
        case HIDDEN_ITEM_IDX:
            return (u16)hidden_item.item;
        case HIDDEN_FLAG:
            return hidden_flag_by_chunk((u8)hidden_item.flag, (u8)hidden_item.chunk);
        case HIDDEN_COUNT:
            return (u8)hidden_item.amount;
        case HIDDEN_UNDERFOOT:
            return (u8)hidden_item.detector_disabled;
        case HIDDEN_CHUNK:
            return (u8)hidden_item.chunk;
        default:
            return 0;
    }
}

extern u8 ow_script_signpost_null[];
extern u8 ow_script_signpost_hidden_item[];

u8 *signpost_get_script(position_t *position, u8 behaviour, u8 direction) {
    map_event_signpost *sign = map_get_signpost_by_position(&mapheader_virtual, (s16)(position->coordinates.x - 7), (s16)(position->coordinates.y - 7), position->height);
    if (!sign) return NULL;
    if (sign->flag && checkflag(sign->flag)) return NULL;
    if (!sign->value.script) return ow_script_signpost_null;
    switch(sign->type) {
        case SIGNPOST_SCRIPT_NORTH:
            if (direction != DIR_UP) return NULL;
            break;
        case SIGNPOST_SCRIPT_SOUTH:
            if (direction != DIR_DOWN) return NULL;
            break;
        case SIGNPOST_SCRIPT_EAST:
            if (direction != DIR_RIGHT) return NULL;
            break;
        case SIGNPOST_SCRIPT_WEST:
            if (direction != DIR_LEFT) return NULL;
            break;
        case SIGNPOST_5:
        case SIGNPOST_6:
        case SIGNPOST_HIDDEN_ITEM: {
            if (hidden_item_get_field(sign->value.hidden_item, HIDDEN_UNDERFOOT)) return NULL;
            *var_access(0x8005) = (u16)hidden_item_get_field(sign->value.hidden_item, HIDDEN_ITEM_IDX);
            *var_access(0x8004) = (u16)hidden_item_get_field(sign->value.hidden_item, HIDDEN_FLAG);
            *var_access(0x8006) = (u16)hidden_item_get_field(sign->value.hidden_item, HIDDEN_COUNT);
            if (checkflag(*var_access(0x8004))) return NULL;
            *var_access(PLAYERFACING) = direction;
            return ow_script_signpost_hidden_item;
        }
    }
    // Signpost scripts
    if (signpost_get_script_type(behaviour, direction) != 255)
        overworld_tbox_set_sign();
    *var_access(PLAYERFACING) = direction;
    return sign->value.script;
}
