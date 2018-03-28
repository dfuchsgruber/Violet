.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95a5f6
ow_script_0x95a5f6:
loadpointer 0x0 str_0x95aaa5
callstd MSG_FACE
end

.global str_0x95aaa5

str_0x95aaa5:
    .string "Das Wasser in Kaskada ist das\nsauberste der ganzen Theto-Region."
        
        