.include "overworld_script.s"

.include "std.s"

.global ow_script_0x878394
ow_script_0x878394:
loadpointer 0x0 str_0x880f63
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x880f63

str_0x880f63:
    .string "Es gibt in jeder Stadt einen\nPOKESTOP. Ich hörte, dass in allen\lPOKESTOPs das Sortiment zwar\lgleich ist, aber laufend erweitert\lwird."
        
        
.elseif LANG_EN

.endif
