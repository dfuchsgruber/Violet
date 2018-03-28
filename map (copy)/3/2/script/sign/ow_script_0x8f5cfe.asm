.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8f5cfe
ow_script_0x8f5cfe:
loadpointer 0x0 str_0x8f60c7
callstd MSG_SIGN
end

.global str_0x8f60c7

str_0x8f60c7:
    .string "Ein Pokémon könnte hier bestimmt\nhochkraxeln ..."
        
        