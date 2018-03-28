.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8f1e47
ow_script_0x8f1e47:
loadpointer 0x0 str_0x8f1e51
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f1e51

str_0x8f1e51:
    .string "Der Schwarze Devin, von den Top\nVier, hat darauf bestanden, die\lKontrolle über dieses Gebiet zu\lerhalten."
        
        
.elseif LANG_EN

.endif
