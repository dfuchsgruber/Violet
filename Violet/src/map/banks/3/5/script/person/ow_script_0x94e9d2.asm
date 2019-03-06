.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x94e9d2
ow_script_0x94e9d2:
loadpointer 0x0 str_0x94e9dc
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94e9dc

str_0x94e9dc:
    .string "Es ist wichtig, einfach einmal\nabzuschalten und den Geist wandern\lzu lassenDOTS"
        
        
.elseif LANG_EN

.endif
