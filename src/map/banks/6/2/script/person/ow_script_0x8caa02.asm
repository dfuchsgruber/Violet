.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x8caa02
ow_script_0x8caa02:
checkflag FRBADGE_1
gotoif EQUAL ow_script_0x8caa15
loadpointer 0x0 str_0x8caa1f
callstd MSG_FACE
end


.global ow_script_0x8caa15
ow_script_0x8caa15:
loadpointer 0x0 str_0x8cab11
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8caa1f

str_0x8caa1f:
    .string "Oh, hallo. Ich bin der Aufseher\ndieser Arena und zuständig dafür,\ldass es bei den Kämpfen stets mit\lrechten Dingen zugeht.\lLester, der Arenaleiter, benutzt\lStein-Pokémon im Kampf. Begegne\lihm mit Wasser, Pflanzen aber auch\lKampf-Angriffen."
        
        
.global str_0x8cab11

str_0x8cab11:
    .string "Glückwunsch zu deinem Sieg! Du\nhast gezeigt, dass du es mit einem\lArenaleiter aufnehmen kannst."
        
        
.elseif LANG_EN

.endif
