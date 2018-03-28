.include "overworld_script.s"

.include "std.s"

.global ow_script_0x84c6f0
ow_script_0x84c6f0:
loadpointer 0x0 str_0x84c6fa
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x84c6fa

str_0x84c6fa:
    .string "Weißt du, mein Bruder schläft gar\nnicht, er tut nur so!"
        
        
.elseif LANG_EN

.endif
