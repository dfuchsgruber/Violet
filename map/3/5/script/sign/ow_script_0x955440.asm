.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x955440
ow_script_0x955440:
loadpointer 0x0 str_0x95547f
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x95547f

str_0x95547f:
    .string "Ein Briefkasten"
        
        
.elseif LANG_EN

.endif
