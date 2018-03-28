.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8f5ca0
ow_script_0x8f5ca0:
loadpointer 0x0 str_0x8f5caa
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x8f5caa

str_0x8f5caa:
    .string "Silvania Wald"
        
        
.elseif LANG_EN

.endif
