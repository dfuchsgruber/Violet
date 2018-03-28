.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81fcc0
ow_script_0x81fcc0:
trainerbattlestd 0x0 0x65 0x0 str_0x90ff68 str_0x91ff1b
loadpointer 0x0 str_0x91ff1b
callstd MSG_FACE
end

.global str_0x90ff68

str_0x90ff68:
    .string "Ich habe gehört, dass sich\nirgendwo in dieser Wüste das\lGrabmal eines legendären Pokémon\lbefindet. Ob an diesen Geschichten\letwas dran ist?"
        
        
.global str_0x91ff1b

str_0x91ff1b:
    .string "Ich würde gerne einemal einem\nlegendären Pokémon begegnen."
        
        