.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8ef6d9
ow_script_0x8ef6d9:
loadpointer 0x0 str_0x8f455c
callstd MSG_FACE
end

.global str_0x8f455c

str_0x8f455c:
    .string "Ich suche hier nach Knilz, einem\nPilz-Pokémon. Ob ich es finden\lkann?"
        
        