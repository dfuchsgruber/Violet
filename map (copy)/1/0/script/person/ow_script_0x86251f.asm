.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86251f
ow_script_0x86251f:
loadpointer 0x0 str_0x8f38f8
callstd MSG_FACE
end

.global str_0x8f38f8

str_0x8f38f8:
    .string "Die Revolutionsbewegung fordert\nFreiheit und ein Ende der\lKorruption.\lKeine schlechten Forderungen, wenn\lman bedenkt, wie sich die Welt\lentwickelt hat..."
        
        