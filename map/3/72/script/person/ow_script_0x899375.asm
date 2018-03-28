.include "overworld_script.s"

.include "std.s"

.global ow_script_0x899375
ow_script_0x899375:
call ow_script_0x89e33c
loadpointer 0x0 str_0x899e54
callstd MSG_FACE
special 0x7
end


.ifdef LANG_GER
.global str_0x899e54

str_0x899e54:
    .string "... ... ..."
        
        
.elseif LANG_EN

.endif
