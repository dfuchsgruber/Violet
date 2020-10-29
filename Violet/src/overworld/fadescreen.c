#include "types.h"
#include "color.h"
#include "save.h"
#include "fading.h"
#include "bios.h"
#include "overworld/map_control.h"
#include "vars.h"
#include "debug.h"

typedef struct{
    u8 unkown[8];
    u8 *script;
} ow_script_state;

void script_halt_and_callback(ow_script_state *state, bool (*callback)());

void ow_script_fadescreen_palette_backup() {
    cpuset(pal_restore, pal_tmp, 0x4000100);
}

bool script_cmd_x97_fadescreen(ow_script_state *ow_state){
    //dprintf("Script state is %x\n", ow_state->script);
    u8 type = *(ow_state->script++);
    //dprintf("Script state is %x\n", ow_state->script);
    if(type == FADE_FROM_BLACK || type == FADE_FROM_WHITE){
        //Fade back from black or white
        cpuset(pal_tmp, pal_restore, 0x4000100);
    }else{
        cpuset(pal_restore, pal_tmp, 0x4000100);
    }
    fadescreen_all(type, (u8)(*var_access(VAR_MAP_TRANSITION_FADING_DELAY)));
    script_halt_and_callback(ow_state, fadescreen_is_active);
    return true;
}

void _pal_copy(const void *src, u16 color, u16 bytes){
    cpuset(src, &pal_tmp[color], CPUSET_COPY | CPUSET_HALFWORD | (bytes >> 1));
    cpuset(src, &pal_restore[color], CPUSET_COPY | CPUSET_HALFWORD | (bytes >> 1));
    cpuset(src, &pals[color], CPUSET_COPY | CPUSET_HALFWORD | (bytes >> 1));
}

void _pal_load_comp(const void *src, u16 color, u16 bytes){
    void *tmp = (void*)0x2037ACC;
    lz77uncompwram(src, tmp);
    pal_copy(tmp, color, bytes);
}

void overworld_fadescreen(bool fade_from) {
    u8 delay = (u8)(*var_access(VAR_MAP_TRANSITION_FADING_DELAY));
    dprintf("Overworld fadescreen with delay %d, fade from %d\n", delay, fade_from);
    if (map_transition_is_exit(map_previous_get_type(), map_current_get_type())) {
        if (fade_from) {
            pal_set_all_to_white(); 
            fadescreen_all(FADE_FROM_WHITE, delay);
            pal_set_all_to_white();
        } else {
            fadescreen_all(FADE_TO_WHITE, delay);
        }
    } else {
        if (fade_from) {
            pal_set_all_to_black(); 
            fadescreen_all(FADE_FROM_BLACK, delay);
            pal_set_all_to_black();
        } else {
            fadescreen_all(FADE_TO_BLACK, delay);
        }
    }
}