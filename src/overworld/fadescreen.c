#include "types.h"
#include "romfuncs.h"
#include "color.h"
#include "save.h"


typedef struct{
    u8 unkown[8];
    u8 *script;
} ow_script_state;

void script_halt_and_callback(ow_script_state *state, bool (*callback)());

bool script_cmd_x97_fadescreen(ow_script_state *ow_state){
    dprintf("Script state is %x\n", ow_state->script);
    u8 type = *(ow_state->script++);
    dprintf("Script state is %x\n", ow_state->script);
    if(type == 0 || type == 2){
        //Fade back from black or white
        cpuset(pal_tmp, pal_restore, 0x4000100);
    }else{
        cpuset(pal_restore, pal_tmp, 0x4000100);
    }
    init_fadescreen(type, 0);
    script_halt_and_callback(ow_state, fadescreen_is_active);
    return true;
}
