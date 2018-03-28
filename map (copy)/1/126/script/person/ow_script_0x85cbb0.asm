.include "overworld_script.s"

.include "std.s"

.global ow_script_0x85cbb0
ow_script_0x85cbb0:
loadpointer 0x0 str_0x864574
callstd MSG_FACE
end

.global str_0x864574

str_0x864574:
    .string "Ich würde dir nicht empfehlen,\nnoch tiefer in den Vulkan zu\lwandern.\pNicht, dass es einen Weg gäbe..."
        
        