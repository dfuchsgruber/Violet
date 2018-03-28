.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a79e8
ow_script_0x8a79e8:
trainerbattlestd 0x0 0xc 0x0 str_0x8a9ca1 str_0x8a95fb
loadpointer 0x0 str_0x8a95fb
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a9ca1

str_0x8a9ca1:
    .string "Was entspannt mehr als ein\nPicknick in der Sonne?\pEin Kampf natürlich!"
        
        
.global str_0x8a95fb

str_0x8a95fb:
    .string "Mir bleibt immerhin noch das\nPicknicken!"
        
        
.elseif LANG_EN

.endif
