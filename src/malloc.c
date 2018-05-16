#include "types.h"
#include "debug.h"


void *malloc_tail(void *head, u32 size);

void *malloc_debug(void *head, u32 size, int callee){
    void *block = malloc_tail(head, size);
    dprintf("Allocated 0x%x of size 0x%x from callee 0x%x\n", block, size, callee);
    return block;
}

void free_tail(void *head, void *block);

void free_debug(void *head, void *block, int callee){
    free_tail(head, block);
    dprintf("Freed 0x%x from callee 0x%x\n", block, callee);
}
