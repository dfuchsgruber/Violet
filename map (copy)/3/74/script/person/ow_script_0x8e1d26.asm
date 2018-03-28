.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e1d26
ow_script_0x8e1d26:
trainerbattlestd 0x0 0x31 0x0 str_0x8e1d3e str_0x8e2ad4
loadpointer 0x0 str_0x8e2ad4
callstd MSG_FACE
end

.global str_0x8e1d3e

str_0x8e1d3e:
    .string "Mein Herz gehört einem Jungen, der\nmich vor langer Zeit allein\lgelassen hat."
        
        
.global str_0x8e2ad4

str_0x8e2ad4:
    .string "In einem Vergnügungspark habe ich\nihn das letzte Mal gesehen..."
        
        