.include "overworld_script.s"

.include "std.s"

.global ow_script_0x93d668
ow_script_0x93d668:
trainerbattlestd 0x0 0x86 0x0 str_0x948c85 str_0x9497f6
loadpointer 0x0 str_0x9497f6
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x948c85

str_0x948c85:
    .string "Es tut mir im Herzen weh, wie ihr\njungen Leute das Vermächtnis\lmeiner Generation vernichtet."
        
        
.global str_0x9497f6

str_0x9497f6:
    .string "Dass du nicht einmal den Anstand\nhast, zu verlieren..."
        
        
.elseif LANG_EN

.endif
