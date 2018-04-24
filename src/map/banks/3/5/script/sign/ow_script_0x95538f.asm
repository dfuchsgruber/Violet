.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95538f
ow_script_0x95538f:
loadpointer 0x0 str_0x9553f8
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x9553f8

str_0x9553f8:
    .string "Orina City Museum"
        
        
.elseif LANG_EN

.endif
