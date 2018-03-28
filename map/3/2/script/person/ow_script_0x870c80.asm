.include "overworld_script.s"

.include "std.s"

.global ow_script_0x870c80
ow_script_0x870c80:
loadpointer 0x0 str_0x88034f
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x88034f

str_0x88034f:
    .string "Graben und Minen sind meine\nLeidenschaft! Ich werde bald hier\ldamit beginnen! Warts ab!"
        
        
.elseif LANG_EN

.endif
