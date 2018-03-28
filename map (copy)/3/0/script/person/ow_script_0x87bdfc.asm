.include "overworld_script.s"

.include "std.s"

.global ow_script_0x87bdfc
ow_script_0x87bdfc:
loadpointer 0x0 str_0x89bed9
callstd MSG_FACE
end

.global str_0x89bed9

str_0x89bed9:
    .string "Sieh mal, ich habe ein Pokémon.\nLos Azurill!\l...\lEs kuschelt lieber mit mir als zu\lkämpfen..."
        
        