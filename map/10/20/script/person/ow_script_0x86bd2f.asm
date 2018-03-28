.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x86bd2f
ow_script_0x86bd2f:
loadpointer 0x0 str_0x965b49
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x965b49

str_0x965b49:
    .string "Feuerpokémon haben in diesem Haus\nkeinen Zutritt.\pWas soll sonst aus der\nHolzmöblierung werden?"
        
        
.elseif LANG_EN

.endif
