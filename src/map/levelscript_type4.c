#include "types.h"
#include "romfuncs.h"
#include "save.h"
#include "map.h"

void map_init_levelscript_4(){
    script a = fmem->additional_levelscript_4;
    if(a){
        script_init_muted(a);
        fmem->additional_levelscript_4 = NULL;
    }
    script s = map_get_levelscript_if_triggered(4);
    if(s){
        script_init_muted(s);
    }
}
