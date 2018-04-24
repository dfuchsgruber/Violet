.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8ded20
ow_script_0x8ded20:
loadpointer 0x0 str_0x8df298
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8df298

str_0x8df298:
    .string "Mia, die Arenaleiterin dieser\nStadt, kümmert sich um den\lSilvania-Wald."
        
        
.elseif LANG_EN

.endif
