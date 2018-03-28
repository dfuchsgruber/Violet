.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8fed46
ow_script_0x8fed46:
loadpointer 0x0 str_0x8fffd9
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x8fffd9

str_0x8fffd9:
    .string "Haus des Namensexperten"
        
        
.elseif LANG_EN

.endif
