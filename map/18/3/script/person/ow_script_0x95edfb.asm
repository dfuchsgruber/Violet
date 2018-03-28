.include "overworld_script.s"


.global ow_script_0x95edfb
ow_script_0x95edfb:
bufferstring 0x0 str_0x95ee0c
setvar 0x8000 0x9b
goto ow_script_0x8d421d


.ifdef LANG_GER
.global str_0x95ee0c

str_0x95ee0c:
    .string "Feuer"
        
        
.elseif LANG_EN

.endif
