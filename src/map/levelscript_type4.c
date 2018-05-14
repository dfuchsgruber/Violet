#include "types.h"
#include "overworld/script.h"
#include "map/levelscript.h"
#include "save.h"

void map_init_levelscript_4() {
    u8 *a = fmem->additional_levelscript_4;
    if (a) {
        overworld_script_init_muted(a);
        fmem->additional_levelscript_4 = NULL;
    }
    u8 *s = map_levelscript_get_if_triggered(4);
    if (s) {
        overworld_script_init_muted(s);
    }
}
