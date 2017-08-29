#include "types.h"
#include "romfuncs.h"
#include "multichoice.h"
#include "save.h"

multichoice_t *dynamic_multichoice_get_choices(u8 choice_id){
    u16 *var_dynamic_multichoice_size = vardecrypt(0x4077);
    if(*var_dynamic_multichoice_size){
        //You have to build a new list
        fmem->dynamic_choice.choices = *((u8***)0x03000F14);
        fmem->dynamic_choice.size = *var_dynamic_multichoice_size;
        *var_dynamic_multichoice_size = 0; //only use this once
        return &fmem->dynamic_choice;
    }
    return &multichoices[choice_id];
    
}
