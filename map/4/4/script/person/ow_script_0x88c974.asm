.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x88c974
ow_script_0x88c974:
loadpointer 0x0 str_0x8a08b0
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a08b0

str_0x8a08b0:
    .string "Einst war ich ein glorreicher\nTrainer. Aber nun .... nun ... bin\lich ein alter Greis..."
        
        
.elseif LANG_EN

.endif
