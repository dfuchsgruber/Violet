#include "types.h"
#include "vars.h"
#include "multichoice.h"
#include "save.h"
#include "overworld/script.h"

multichoice_t *dynamic_multichoice_get_choices(u8 choice_id){
    u16 *var_dynamic_multichoice_size = var_access(0x4077);
    if(*var_dynamic_multichoice_size){
        //You have to build a new list
        fmem.dynamic_choice.choices = (u8**)(overworld_script_state->pointer_banks[0]);
        fmem.dynamic_choice.size = *var_dynamic_multichoice_size;
        *var_dynamic_multichoice_size = 0; //only use this once
        return &fmem.dynamic_choice;
    }
    return &multichoices[choice_id];
    
}
