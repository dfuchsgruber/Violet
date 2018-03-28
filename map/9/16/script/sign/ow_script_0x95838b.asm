.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95838b
ow_script_0x95838b:
loadpointer 0x0 str_0x95a700
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x95a700

str_0x95a700:
    .string "Das Gemälde zeigt ein rotes\nMonster, das von Flammen und Lava\lumgeben ist."
        
        
.elseif LANG_EN

.endif
