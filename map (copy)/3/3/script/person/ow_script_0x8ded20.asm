.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8ded20
ow_script_0x8ded20:
loadpointer 0x0 str_0x8df298
callstd MSG_FACE
end

.global str_0x8df298

str_0x8df298:
    .string "Mia, die Arenaleiterin dieser\nStadt, kümmert sich um den\lSilvania-Wald."
        
        