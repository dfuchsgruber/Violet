.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95f7d6
ow_script_0x95f7d6:
loadpointer 0x0 str_0x95f7e0
callstd MSG_FACE
end

.global str_0x95f7e0

str_0x95f7e0:
    .string "Im Aschhain lebt ein alter Mann,\nder aus Asche Flöten herstellen\lkann.\pEs heißt, dass er der Schüler\neines Meisters aus Hoenn ist."
        
        