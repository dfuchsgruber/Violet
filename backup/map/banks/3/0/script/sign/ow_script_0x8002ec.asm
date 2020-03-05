.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8002ec
ow_script_0x8002ec:
loadpointer 0x0 str_0x80062f
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x80062f

str_0x80062f:
    .string "Amonia - Das Dorf der Ruhe"
        
        
.elseif LANG_EN

.endif
