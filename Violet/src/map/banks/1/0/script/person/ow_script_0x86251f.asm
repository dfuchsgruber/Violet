.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x86251f
ow_script_0x86251f:
loadpointer 0x0 str_0x8f38f8
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f38f8

str_0x8f38f8:
    .string "Die Revolutionsbewegung fordert\nFreiheit und ein Ende der\lKorruption.\lKeine schlechten Forderungen, wenn\lman bedenkt, wie sich die Welt\lentwickelt hatDOTS"
        
        
.elseif LANG_EN

.endif
