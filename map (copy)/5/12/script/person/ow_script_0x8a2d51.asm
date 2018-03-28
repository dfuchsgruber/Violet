.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a2d51
ow_script_0x8a2d51:
loadpointer 0x0 str_0x8a3523
callstd MSG_FACE
end

.global str_0x8a3523

str_0x8a3523:
    .string "Wir leben hier zusammen mit den\nEltern meines Mannes. Eine große\lFamilie um sich zu haben, ist doch\letwas tolles, nicht?"
        
        