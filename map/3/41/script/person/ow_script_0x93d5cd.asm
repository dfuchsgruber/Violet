.include "overworld_script.s"


.global ow_script_0x93d5cd
ow_script_0x93d5cd:
bufferstring 0x0 str_0x93d67f
setvar 0x8000 0xef
goto ow_script_0x8d421d


.ifdef LANG_GER
.global str_0x93d67f

str_0x93d67f:
    .string "Eis"
        
        
.elseif LANG_EN

.endif
