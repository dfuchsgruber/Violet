.include "overworld_script.s"

.include "std.s"

.global ow_script_0x811307
ow_script_0x811307:
loadpointer 0x0 str_0x8cb3d6
callstd MSG_FACE
end

.global str_0x8cb3d6

str_0x8cb3d6:
    .string "Wusstest du, dass sich in Muscheln\nwertvolle Perlen verstecken\lkönnen?"
        
        