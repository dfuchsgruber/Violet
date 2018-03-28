.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x8c8f85
ow_script_0x8c8f85:
lock
faceplayer
loadpointer 0x0 str_0x8f18a8
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8f185a
loadpointer 0x0 str_0x8f1821
callstd MSG
release
end


.global ow_script_0x8f185a
ow_script_0x8f185a:
loadpointer 0x0 str_0x8f1865
callstd MSG
release
end


.ifdef LANG_GER
.global str_0x8f18a8

str_0x8f18a8:
    .string "Guten Tag!\nHast du Lust auf eine Fahrt mit\leinem unserer Kanus? Ein Tag\lkostet dich gerade einmal\p...\neine MILLION POKEDOLLAR!\pWas sagst du?"
        
        
.global str_0x8f1821

str_0x8f1821:
    .string "...\pDu hast nicht genügend Geld?\nPah! Armer Schlucker!"
        
        
.global str_0x8f1865

str_0x8f1865:
    .string "Wiebitte? Warum denn nicht?\pDer Preis?\p...\pPah! Armer Schlucker!"
        
        
.elseif LANG_EN

.endif
