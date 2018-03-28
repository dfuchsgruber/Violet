.include "callstds.s"
.include "flags.s"
.include "overworld_script.s"


.global ow_script_0x8cee6b
ow_script_0x8cee6b:
setflag TRANS_DISABLE
loadpointer 0x0 str_0x8cb5e0
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8cb5e0

str_0x8cb5e0:
    .string "Bonus"
        
        
.elseif LANG_EN

.endif
