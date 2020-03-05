.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x88b2bc
ow_script_0x88b2bc:
loadpointer 0x0 str_0x8f6e7f
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x8f6e7f

str_0x8f6e7f:
    .string "DOTSAlte WindmühleDOTS\pDie Schrift ist verblasstDOTS"
        
        
.elseif LANG_EN

.endif
