.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81afdd
ow_script_0x81afdd:
trainerbattlestd 0x0 0x3f 0x0 str_0x81aff5 str_0x81b06e
loadpointer 0x0 str_0x81b06e
callstd MSG_FACE
end

.global str_0x81aff5

str_0x81aff5:
    .string "Mia legt großen Wert auf\nNatürlichkeit. Deswegen ist in der\lArena auch alles aus natürlichen\lRohstoffen hergestellt."
        
        
.global str_0x81b06e

str_0x81b06e:
    .string "Sogar die Wände sind aus Holz aus\ndem Silvania-Wald."
        
        