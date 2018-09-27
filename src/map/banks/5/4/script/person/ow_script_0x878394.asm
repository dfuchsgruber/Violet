.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"


.global ow_script_0x878394
ow_script_0x878394:
loadpointer 0x0 str_0x880f63
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x880f63

str_0x880f63:
    .string "Es gibt in jeder Stadt einen\Pokéstop. Ich hörte, dass in allen\lPokéstops das Sortiment zwar\lgleich ist, aber laufend erweitert\lwird."
        
        
.elseif LANG_EN

.endif
