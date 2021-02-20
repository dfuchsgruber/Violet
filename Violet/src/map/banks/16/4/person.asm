.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "items.s"

.global ow_script_map_16_4_person_0
.global ow_script_0x937886

ow_script_map_16_4_person_0:
checkflag ROUTE_4_HM_FLY
gotoif EQUAL ow_script_0x937886
lock
faceplayer
loadpointer 0x0 str_0x937a0a
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_VM02
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x937917
callstd MSG_KEEPOPEN
closeonkeypress
setflag ROUTE_4_HM_FLY
end


ow_script_0x937886:
loadpointer 0x0 str_0x937890
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x937a0a:
    .autostring 34 2 "Ich glaube es nicht!\pDu hast mein Haus gefunden?\pDabei habe ich mir doch so viel Mühe gegeben, es an einem abgelegenen Ort zu bauenDOTS\pDu darfst niemanden hiervon erzählen ja?\pAls Gegenleistung für dein Schweigen gebe ich dir diese Versteckte Maschine."
str_0x937917:
    .autostring 34 2 "Sie enthält Fliegen, einen Angriff für Flug-Pokémon.\pHast du erst einmal den Arenaorden von Blütenbach errungen, kannst du damit bequem zwischen Städten reisen."
str_0x937890:
    .autostring 34 2 "Weißt du, warum ich mir dieses Haus gebaut habe?\pIch hatte die Hoffnung, hier etwas Abgeschiedenheit von der Welt da draußen zu bekommenDOTS\pKeine Pokémon-Liga, keine RevolutionsbewegungDOTS\pEinfach nur die friedliche Stille der NaturDOTS"
.elseif LANG_EN

.endif