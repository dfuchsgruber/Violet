.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8fe4ff
ow_script_0x8fe4ff:
loadpointer 0x0 str_0x8ffff2
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x8ffff2

str_0x8ffff2:
    .string "Küstenberg"
        
        
.elseif LANG_EN

.endif
