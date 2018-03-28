.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8c8f73
ow_script_0x8c8f73:
loadpointer 0x0 str_0x8f172d
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f172d

str_0x8f172d:
    .string "Manche sagen, dass alle unsere\nEntscheidungen Auswirkungen\lhätten. Sie reden von Karma.\lGlaubst du an das Karma?"
        
        
.elseif LANG_EN

.endif
