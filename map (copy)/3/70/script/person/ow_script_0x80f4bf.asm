.include "overworld_script.s"

.include "std.s"

.global ow_script_0x80f4bf
ow_script_0x80f4bf:
trainerbattlestd 0x0 0x7 0x0 str_0x80f4d7 str_0x80f517
loadpointer 0x0 str_0x80f517
callstd MSG_FACE
end

.global str_0x80f4d7

str_0x80f4d7:
    .string "Ich respektiere die Natur und das\nselbe solltest du auch tun!"
        
        
.global str_0x80f517

str_0x80f517:
    .string "Du hast die Natur respektiert, das\nwar der Grund für deinen Sieg."
        
        