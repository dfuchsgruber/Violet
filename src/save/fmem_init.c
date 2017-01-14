#include "types.h"
#include "romfuncs.h"
#include "save.h"

void fmem_init(){
    fmem->dmap_status &= 0xFC; //clear the lower 2 bits of dmap status indicating that no dmap was generated
    fmem->current_tileset_1 = NULL;
    fmem->current_tileset_2 = NULL;
    
}


