.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a0000
ow_script_0x8a0000:
loadpointer 0x0 str_0x958dc8
callstd MSG_FACE
end

.global str_0x958dc8

str_0x958dc8:
    .string "Es ist wirklich beeindruckend, wie\ngut man ausgestorbene Pokémon\lanhand von Fossilien\lrekonstruieren kann.\pIch frage mich allerdings, ob sie\ntatsächlich wie ihre Nachbildungen\lausgesehen haben."
        
        