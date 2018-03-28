.include "overworld_script.s"

.include "std.s"

.global ow_script_0x85d390
ow_script_0x85d390:
trainerbattlestd 0x0 0xa4 0x0 str_0x864949 str_0x86453a
loadpointer 0x0 str_0x86453a
callstd MSG_FACE
end

.global str_0x864949

str_0x864949:
    .string "Du denkst also tatsächlich, dass\ndu es aufhalten könntest?"
        
        
.global str_0x86453a

str_0x86453a:
    .string "Deine Versuche werden spätestens\nan Mistral scheitern..."
        
        