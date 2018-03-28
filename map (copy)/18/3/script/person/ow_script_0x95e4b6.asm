.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95e4b6
ow_script_0x95e4b6:
loadpointer 0x0 str_0x95e4c0
callstd MSG_FACE
end

.global str_0x95e4c0

str_0x95e4c0:
    .string "Es mag zwar nicht so aussehen,\naber der Boden in der Nähe eines\lVulkans ist sehr nährstoffhaltig.\pPokémon und Menschen siedeln seit\nJahrhunderten an diesen Orten."
        
        