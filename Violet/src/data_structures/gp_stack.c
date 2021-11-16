#include "types.h"
#include "stdbool.h"
#include "save.h"
#include "debug.h"

void gp_stack_init(){
    fmem.gp_stack_size = 0;
}

bool gp_stack_push(int val){
    if(fmem.gp_stack_size < GP_STACK_SIZE){
        fmem.gp_stack[fmem.gp_stack_size] = val;
        fmem.gp_stack_size++;
        return true;
    }
    return false;
}

int gp_stack_peek(){
    if(fmem.gp_stack_size > 0){
        return fmem.gp_stack[fmem.gp_stack_size - 1];
    }
    ERROR("Trying to peek from empty gp stack\n");
    return -1;
}

int gp_stack_pop(){
    if(fmem.gp_stack_size > 0){
        return fmem.gp_stack[--(fmem.gp_stack_size)];
    }
    ERROR("Trying to pop from empty gp stack\n");
    return -1;
}
