.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fb3c3
ow_script_0x8fb3c3:
bufferstring 0x0 str_0x8fb3d5
setvar 0x8000 0xec
call ow_script_0x8d421d
end


.ifdef LANG_GER
.global str_0x8fb3d5

str_0x8fb3d5:
    .string "Kampf-"
        
        
.elseif LANG_EN

.endif
