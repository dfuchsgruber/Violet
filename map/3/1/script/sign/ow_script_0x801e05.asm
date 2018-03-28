.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x801e05
ow_script_0x801e05:
loadpointer 0x0 str_0x8dea7d
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x8dea7d

str_0x8dea7d:
    .string "Arena von Meriana City\pTyp: Kampf\nLeiter: Manus"
        
        
.elseif LANG_EN

.endif
