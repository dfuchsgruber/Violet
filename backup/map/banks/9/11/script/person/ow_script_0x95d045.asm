.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95d045
ow_script_0x95d045:
loadpointer 0x0 str_0x95d04f
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95d04f

str_0x95d04f:
    .string "Mein Mann hat insgeheim ein\nProblem mit meinem Vater.\pEr gibt es zwar nicht zu, aber er\nkann ihn nicht ausstehen."
        
        
.elseif LANG_EN

.endif
