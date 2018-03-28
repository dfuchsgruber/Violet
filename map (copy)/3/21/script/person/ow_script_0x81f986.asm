.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81f986
ow_script_0x81f986:
loadpointer 0x0 str_0x86c9f0
callstd MSG_FACE
end

.global str_0x86c9f0

str_0x86c9f0:
    .string "Ich habe gehört, dass es in dieser\nWüste goldene Kakteen geben soll.\pSchüttelt man an ihnen, so soll\nman Pokémon antreffen können."
        
        