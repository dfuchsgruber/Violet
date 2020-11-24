.align 2
.thumb

.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_flash

ow_script_flash:
    callasm overworld_get_flash_level
    compare LASTRESULT 0
    gotoif EQUAL flash_level_0
    compare LASTRESULT 1
    gotoif EQUAL flash_level_1
    compare LASTRESULT 2
    gotoif EQUAL flash_level_2
    compare LASTRESULT 3
    gotoif EQUAL flash_level_3
    end

flash_level_0:
    lighten 0
    darken 0
    end
flash_level_1:
    lighten 1
    darken 1
    end
flash_level_2:
    lighten 2
    darken 2
    end
flash_level_3:
    lighten 3
    darken 3
    end

