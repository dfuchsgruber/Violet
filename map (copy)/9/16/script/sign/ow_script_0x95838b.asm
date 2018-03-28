.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95838b
ow_script_0x95838b:
loadpointer 0x0 str_0x95a700
callstd MSG_SIGN
end

.global str_0x95a700

str_0x95a700:
    .string "Das Gemälde zeigt ein rotes\nMonster, das von Flammen und Lava\lumgeben ist."
        
        