.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8777fe
ow_script_0x8777fe:
loadpointer 0x0 str_0x880e00
callstd MSG_FACE
end

.global str_0x880e00

str_0x880e00:
    .string "Im POKESTOP kannst du sowohl deine\nPokémon heilen lassen, als auch\lnützliche Items für den Inventar\lkaufen."
        
        