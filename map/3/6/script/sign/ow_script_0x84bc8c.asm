.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x84bc8c
ow_script_0x84bc8c:
loadpointer 0x0 str_0x8601de
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x8601de

str_0x8601de:
    .string "Der Volcano - das Herz des Feuers"
        
        
.elseif LANG_EN

.endif
