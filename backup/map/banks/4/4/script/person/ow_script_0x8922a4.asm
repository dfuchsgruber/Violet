.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8922a4
ow_script_0x8922a4:
loadpointer 0x0 str_0x8a0909
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a0909

str_0x8a0909:
    .string "Amonia ist der perfekte Ort für\nTrainer, die sich zur Ruhe setzten\lwollen."
        
        
.elseif LANG_EN

.endif
