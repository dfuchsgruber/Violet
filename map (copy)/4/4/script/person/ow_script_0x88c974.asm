.include "overworld_script.s"

.include "std.s"

.global ow_script_0x88c974
ow_script_0x88c974:
loadpointer 0x0 str_0x8a08b0
callstd MSG_FACE
end

.global str_0x8a08b0

str_0x8a08b0:
    .string "Einst war ich ein glorreicher\nTrainer. Aber nun .... nun ... bin\lich ein alter Greis..."
        
        