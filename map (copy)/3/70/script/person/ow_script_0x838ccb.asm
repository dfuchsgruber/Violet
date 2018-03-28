.include "overworld_script.s"

.include "std.s"

.global ow_script_0x838ccb
ow_script_0x838ccb:
loadpointer 0x0 str_0x83f669
callstd MSG_FACE
end

.global str_0x83f669

str_0x83f669:
    .string "Entschuldigung, aber der Zutritt zu\ndiesem Bereich, steht nicht allen\lLeuten zu."
        
        