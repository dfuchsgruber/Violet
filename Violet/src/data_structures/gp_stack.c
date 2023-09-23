#include "types.h"
#include "stdbool.h"
#include "save.h"
#include "debug.h"

void gp_stack_init(){
    gp_stack_size = 0;
}

bool gp_stack_push(int val){
    if(gp_stack_size < GP_STACK_SIZE){
        gp_stack[gp_stack_size] = val;
        gp_stack_size++;
        return true;
    }
    return false;
}

int gp_stack_peek(){
    if(gp_stack_size > 0){
        return gp_stack[gp_stack_size - 1];
    }
    ERROR("Trying to peek from empty gp stack\n");
    return -1;
}

int gp_stack_pop(){
    if(gp_stack_size > 0){
        return gp_stack[--(gp_stack_size)];
    }
    ERROR("Trying to pop from empty gp stack\n");
    return -1;
}
