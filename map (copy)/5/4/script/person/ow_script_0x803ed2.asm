.include "overworld_script.s"

.include "std.s"

.global ow_script_0x803ed2
ow_script_0x803ed2:
cry POKEMON_CHANEIRA 0x0
loadpointer 0x0 str_0x80ebe5
callstd MSG_FACE
end

.global str_0x80ebe5

str_0x80ebe5:
    .string "Chaneira! Chaneira!"
        
        