.include "flags.s"
.include "map_connections.s"
.include "movements.s"
.include "items.s"
.include "callstds.s"
.include "species.s"
.include "map_adjacency_types.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_movs_0x9584b7
ow_script_movs_0x9584b7:
.byte LOOK_UP
.byte STOP


.global ow_script_0x9588ed
ow_script_0x9588ed:
lockall
call ow_script_0x8a7f80
faceplayer
loadpointer 0x0 str_0x958549
callstd MSG_KEEPOPEN
setvar 0x4001 0x85
givepokemon POKEMON_PORYGON 0x1e ITEM_NONE 0x0 0x0 0x0
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x9584ba
special 0x7
applymovement 0x800f ow_script_movs_0x9584b7
waitmovement 0x0
pause 0x1c
faceplayer
fanfare 0x13e
loadpointer 0x0 str_0x958498
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
bufferpokemon 0x0 POKEMON_PORYGON
call ow_script_0x893bb5
call ow_script_0x8a7f80
loadpointer 0x0 str_0x95839d
callstd MSG
special 0x7
addvar STORY_PROGRESS 0x1
setflag ORINA_CITY_MISTRALS_GRUNTS
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
releaseall
end


.global ow_script_0x9584ba
ow_script_0x9584ba:
loadpointer 0x0 str_0x9584c8
callstd MSG
special 0x7
releaseall
end


.ifdef LANG_GER
.global str_0x958549

str_0x958549:
   .autostring 35 2 "Hallo PLAYER!\nIch will dich nicht länger auf die Folter spannen.\pUnserer Forschungsgruppe ist es gelungen, ein Pokémon am Computer zu entwerfen und es dann Realität werden zu lassen.\pWir haben es Porygon genannt, aber über seine Fähigkeiten wissen wir praktisch nichts.\pDu bist der perfekte Kandidat, so ein Pokémon aufzuziehen, finde ich!\pIch werde dir ein Exemplar anvertrauen."
        
.global str_0x958498

str_0x958498:
    .autostring 35 2 "PLAYER hat ein Porygon\nerhalten."
        
        
.global str_0x95839d

str_0x95839d:

	.autostring 35 2 "Ich bin mir sicher, dass du Fähigkeiten in diesem Pokémon zum Vorschein bringen kannst, die wir Entwickler uns niemals hätten vorstellen können.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pNun muss ich aber wieder zurück an die Arbeit.\pWir sehen uns, PLAYER."
        
        
.global str_0x9584c8

str_0x9584c8:
    .autostring 35 2 "Wie schade, du scheinst keinen Platz mehr auf deinem PC zu haben.\pKomm doch wieder, wenn du das Porygon entgegennehmen kannst."
        
        
.elseif LANG_EN

.endif
