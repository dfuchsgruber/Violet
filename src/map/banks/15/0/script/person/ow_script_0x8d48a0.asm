.include "overworld_script.s"


.global ow_script_0x8d48a0
ow_script_0x8d48a0:
bufferstring 0x0 str_0x947d7a
setvar 0x8000 0x19
call ow_script_0x8d421d
end


.ifdef LANG_GER
.global str_0x947d7a

str_0x947d7a:
    .string "Elektro"
        
        
.elseif LANG_EN

.endif