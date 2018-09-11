#include "types.h"
#include "save.h"
#include "debug.h"
#include "tile/hidden_item.h"
#include "tile/trash.h"
#include "constants/items.h"
#include "constants/flags.h"
#include "overworld/npc.h"
#include "vars.h"
#include "flags.h"

u8 *singpost_behavior_xBC(){
    //trigger script by block id (since we do not have enough behaviorbytes...)
    s16 x, y;
    u8 facing = player_get_facing();
    player_get_position(&x, &y);
    x = (s16)(x + walking_directions[facing].x);
    y = (s16)(y + walking_directions[facing].y);
    u16 block_id = block_get_by_pos(x, y) & 0x3FF;
    switch(block_id){
        case 0x00F:
            //mushroom
            if (!get_tile_hash_by_facing(facing, 3)){
                //1/4 chance that a mushroom yields something
                u32 hash = get_tile_hash_by_facing(facing, 127);
                u16 flag = (u16)(0xD80 + hash);
                if(checkflag(flag))
                    return NULL;
                //mushroom can be found, we decide which one
                *var_access(0x8004) = flag;
                if(get_tile_hash_by_facing(facing, 3)){
                    //2/3 chance for mini mushroom
                    *var_access(0x8005) = ITEM_MINIPILZ;
                }else{
                    *var_access(0x8005) = ITEM_RIESENPILZ;
                }
                *var_access(0x8006) = 1;
                if(!checkflag( TRAINER_TIPP_MUSHROOM)){
                    setflag(TRAINER_TIPP_MUSHROOM);
                    return script_hidden_item_trainer_tipp_mushroom;
                }
                
                return script_hidden_item_add;
            }
            break;
        case 0x1E1:
            //shell
            if(!get_tile_hash_by_facing(facing, 5)){
                //1/5 chance that shell yields something
                u32 hash = get_tile_hash_by_facing(facing, 127);
                u16 flag = (u16)(0xD80 + hash);
                if(checkflag(flag))
                    return NULL;
                *var_access(0x8004) = flag;
                //shell yields something, we decide on item
                u32 v = get_tile_hash_by_facing(facing, 7);
                if(v <= 1){
                    //2/7 chance for heartscale
                    *var_access(0x8005) = ITEM_HERZSCHUPPE;
                }else if(v <= 4){
                    //2/7 chance for big pearl
                    *var_access(0x8005) = ITEM_RIESENPERLE;
                }else{
                    //3/7 chance for mini pearl
                    *var_access(0x8005) = ITEM_PERLE;
                }
                *var_access(0x8006) = 1;
                if(!checkflag(TRAINER_TIPP_SHELL)){
                    setflag(TRAINER_TIPP_SHELL);
                    return script_hidden_item_trainer_tipp_shell;
                }
                return script_hidden_item_add;
            }
            break;
            
    }
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


u16 singpost_get_flag(u32 fields, u8 field_id){
    u32 hidden_chunk = (fields >> 29) & 3;
    switch(field_id){
        case 0:
            //item id
            return (u16) fields;
        case 1:
            //hidden flag
            return hidden_flag_by_chunk((u8)(fields >> 16) & 0xFF, (u8)hidden_chunk);
        case 2:
            //cnt
            return (u8)(fields >> 24) & 0x1F;
        case 3:
            //detector disable
            return (u8)(fields >> 31) & 1;
        case 4:
            //hidden chunk
            return (u8)hidden_chunk;
        default:
            return 0;
    }
    
}

void mushroom_create(){
    s16 pos[2];
    player_get_position(&pos[0], &pos[1]);
    u32 seq[4] = {(u32)pos[0], (u32)pos[1], (u32)(save1->bank), (u32)(save1->map)};
    u32 h = tmp_hash(seq, 4) % 3;
    if(h){
        *var_access(0x8005) = ITEM_MINIPILZ;
    }else{
        *var_access(0x8005) = ITEM_RIESENPILZ;
    }
    
}
