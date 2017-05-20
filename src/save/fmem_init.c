#include "types.h"
#include "romfuncs.h"
#include "save.h"
#include "data_structures.h"


u8 *dma0_dump = ((floating_memory*) 0x0203CEC4)->dma0_dump;

void fmem_init(){
    fmem->dmap_status &= 0xFC; //clear the lower 2 bits of dmap status indicating that no dmap was generated
    fmem->current_tileset_1 = NULL;
    fmem->current_tileset_2 = NULL;
    
    gp_stack_init();
    
}


