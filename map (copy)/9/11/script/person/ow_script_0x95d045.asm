.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95d045
ow_script_0x95d045:
loadpointer 0x0 str_0x95d04f
callstd MSG_FACE
end

.global str_0x95d04f

str_0x95d04f:
    .string "Mein Mann hat insgeheim ein\nProblem mit meinem Vater.\pEr gibt es zwar nicht zu, aber er\nkann ihn nicht ausstehen."
        
        