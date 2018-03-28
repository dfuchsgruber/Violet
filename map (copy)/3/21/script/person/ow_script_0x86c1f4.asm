.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86c1f4
ow_script_0x86c1f4:
loadpointer 0x0 str_0x91ff57
callstd MSG_FACE
end

.global str_0x91ff57

str_0x91ff57:
    .string "Endlich! Nach tagelanger Suche\nhabe ich den Weg nach Kaskada\lwieder gefunden. Nur zögere ich,\lmich erneut in eine Höhle zu\lbegeben..."
        
        