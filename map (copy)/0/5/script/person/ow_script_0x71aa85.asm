.include "overworld_script.s"

.include "std.s"

.global ow_script_0x71aa85
ow_script_0x71aa85:
trainerbattlestd 0x0 0x4e 0x0 str_0x71aa9d str_0x71aae0
loadpointer 0x0 str_0x71aae0
callstd MSG_FACE
end

.global str_0x71aa9d

str_0x71aa9d:
    .string "In dieser Höhle gibt es allerlei\ninteressante Pokémon."
        
        
.global str_0x71aae0

str_0x71aae0:
    .string "So viele Pokémon..."
        
        