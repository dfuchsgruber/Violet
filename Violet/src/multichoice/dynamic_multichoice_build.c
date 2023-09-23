#include "types.h"
#include "vars.h"
#include "multichoice.h"
#include "save.h"
#include "overworld/script.h"

EWRAM multichoice_t dynamic_multichoice = {0};

const multichoice_t *dynamic_multichoice_get_choices(u8 choice_id){
    u16 *var_dynamic_multichoice_size = var_access(0x4077);
    if(*var_dynamic_multichoice_size){
        //You have to build a new list
        dynamic_multichoice.choices = (const u8**)(overworld_script_state.pointer_banks[0]);
        dynamic_multichoice.size = *var_dynamic_multichoice_size;
        *var_dynamic_multichoice_size = 0; //only use this once
        return &dynamic_multichoice;
    }
    return &multichoices[choice_id];
    
}
