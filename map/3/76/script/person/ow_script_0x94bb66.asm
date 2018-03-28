.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94bb66
ow_script_0x94bb66:
bufferstring 0x0 str_0x94dbd3
setvar 0x8000 0xe3
goto ow_script_0x8d421d


.ifdef LANG_GER
.global str_0x94dbd3

str_0x94dbd3:
    .string "Stahl"
        
        
.elseif LANG_EN

.endif
