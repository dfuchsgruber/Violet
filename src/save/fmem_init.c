#include "types.h"
#include "save.h"
#include "data_structures.h"


u8 *dma0_dump = ((floating_memory*) 0x0203CEC4)->dma0_dump;

void fmem_init(){
    fmem->dmap_header_initialized = 0;
    fmem->dmap_blocks_initialized = 0;
    fmem->current_tileset_1 = NULL;
    fmem->current_tileset_2 = NULL;
    
    gp_stack_init();
    
}


