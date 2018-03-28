.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c7f3b
ow_script_0x8c7f3b:
loadpointer 0x0 str_0x8c910d
callstd MSG_FACE
end

.global str_0x8c910d

str_0x8c910d:
    .string "Ich beobachte gerne Menschen in\nihren Kanus.\p...\pDas Wasser ist zweifellos das\nElement des Lebens!"
        
        