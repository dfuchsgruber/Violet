.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x16f936
ow_script_0x16f936:
loadpointer 0x0 str_0x1a0c6e
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x1a0c6e

str_0x1a0c6e:
    .string "Hallo! Danke für die Erfrischung!"
        
        
.elseif LANG_EN

.endif
