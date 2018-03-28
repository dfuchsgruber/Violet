.include "overworld_script.s"

.include "std.s"

.global ow_script_0x860201
ow_script_0x860201:
loadpointer 0x0 str_0x86020b
callstd MSG_SIGN
end

.global str_0x86020b

str_0x86020b:
    .string "Arena von Inferior\pTyp: Feuer\nLeiter: Igva"
        
        