.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8eded7
ow_script_0x8eded7:
loadpointer 0x0 str_0x8f1a7c
callstd MSG_FACE
end

.global str_0x8f1a7c

str_0x8f1a7c:
    .string "Was? Ich habe dieses Kanu nicht\ngestohlen. Ich habe es mir nur auf\lunbestimmte Zeit geliehen!"
        
        