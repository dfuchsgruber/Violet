.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95b70f
ow_script_0x95b70f:
loadpointer 0x0 str_0x95c8bf
callstd MSG_FACE
end

.global str_0x95c8bf

str_0x95c8bf:
    .string "Selbst die Lobby dieser Firma\nstrahlt einen unvergleichlichen\lFuturismus aus."
        
        