#include "types.h"
#include "save.h"

void c (int a){while(true){}}

u8 *flag_access_ext(u16 flag){
    int index = (flag-0x900) / 8;
    return &(cmem->flag_extension[index]);
}

u16 *var_access_ext(u16 var){
    int index = var-0x5000;
    return &(cmem->var_extension[index]);
}


