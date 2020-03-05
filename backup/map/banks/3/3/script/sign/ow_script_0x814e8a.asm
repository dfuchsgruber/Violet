.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x814e8a
ow_script_0x814e8a:
loadpointer 0x0 str_0x81af29
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x81af29

str_0x81af29:
    .string "Silvania\pDie Stadt der Natur"
        
        
.elseif LANG_EN

.endif
