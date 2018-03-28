.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81fcb7
ow_script_0x81fcb7:
loadpointer 0x0 str_0x86c1ad
callstd MSG_FACE
end

.global str_0x86c1ad

str_0x86c1ad:
    .string "An Brunnen wie diesen können\nTrainer ihre erschöpften Pokémon\lheilen."
        
        