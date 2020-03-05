.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8a3c07
ow_script_0x8a3c07:
loadpointer 0x0 str_0x8a3c11
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x8a3c11

str_0x8a3c11:
    .string "Westen: Route 2"
        
        
.elseif LANG_EN

.endif
