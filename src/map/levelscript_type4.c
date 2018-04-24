#include "types.h"
#include "romfuncs.h"
#include "save.h"

void map_init_levelscript_4() {
    u8 *a = fmem->additional_levelscript_4;
    if (a) {
        script_init_muted(a);
        fmem->additional_levelscript_4 = NULL;
    }
    u8 *s = map_get_levelscript_if_triggered(4);
    if (s) {
        script_init_muted(s);
    }
}
