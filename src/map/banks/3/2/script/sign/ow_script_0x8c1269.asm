.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8c1269
ow_script_0x8c1269:
loadpointer 0x0 str_0x8cee15
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x8cee15

str_0x8cee15:
    .string "Aktania - die Stadt des ewigen\nSonnenscheins\p...\p...\pDer Text ist durchgestrichen..."
        
        
.elseif LANG_EN

.endif
