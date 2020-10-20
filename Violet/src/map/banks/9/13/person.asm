.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "map_adjacency_types.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "species.s"
.include "items.s"

.global ow_script_map_9_13_person_5
.global ow_script_map_9_13_person_6
.global ow_script_map_9_13_person_3
.global ow_script_map_9_13_person_1
.global ow_script_0x9584ba
.global ow_script_map_9_13_person_0
.global ow_script_map_9_13_person_4
.global ow_script_map_9_13_person_2

ow_script_map_9_13_person_0:
loadpointer 0x0 str_0x955c37
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x955c37:
    .string "Hast du je von Team Rocket gehört?\nEs heißt, ihnen sei es gelungen,\lein Pokémon zu klonen."


.elseif LANG_EN

.endif


ow_script_map_9_13_person_6:
loadpointer 0x0 str_0x955c9d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x955c9d:
    .string "Ich bin der Abteilungsleiter des\nCybernetik-Labors.\pSeit geraumer Zeit entwickeln wir\nein Pokémon, das vollständig am\lComputer entworfen wurde."


.elseif LANG_EN

.endif


ow_script_map_9_13_person_3:
loadpointer 0x0 str_0x955d38
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x955d38:
    .string "Das Up-Grade ist eine Software,\nwelche die Kanten des virtuellen\lPokémon glätten kann."


.elseif LANG_EN

.endif


ow_script_map_9_13_person_2:
checkflag ORINA_CITY_UP_GRADE
gotoif EQUAL done
lock
faceplayer
loadpointer 0x0 str_0x957fcc
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_UP_GRADE
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
setflag ORINA_CITY_UP_GRADE

done:
loadpointer 0x0 str_0x9580a7
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x957fcc:
    .string "Eben habe ich eine Software\nfertiggestellt, welche das\lvirtuelle Pokémon Porygon noch\lverbessert."



str_0x9580a7:
    .string "Benutze ein Linkkabel, um das\nUp-Grade auf einem Porygon zu\linstallieren.\pEs wird seine Fähigkeiten deutlich\nverbessern."



.elseif LANG_EN

.endif


ow_script_map_9_13_person_1:
loadpointer 0x0 str_0x958121
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x958121:
    .string "So ein MistDOTS\nEiner von diesen Team Violet\lRüpeln hat mir doch glatt meine\lDubiosdisc geklautDOTS\pDie Software ist noch\nunvollständigDOTS\pIch will mir gar nicht ausmalen,\nwas sie mit Porygon anstellen\lkannDOTS"


.elseif LANG_EN

.endif


ow_script_map_9_13_person_4:
loadpointer 0x0 str_0x9581f2
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9581f2:
    .string "Ich bin dafür verantwortlich, dass\naus den Simuatlionen des\lvirtuellen Pokémons Porygon ein\lmaterielles Objekt entstehtDOTS\pDie Chemie zur Erschaffung eines\nPokémons ist keineswegs trivial."


.elseif LANG_EN

.endif


ow_script_movs_0x9584b7:
.byte LOOK_UP
.byte STOP


ow_script_map_9_13_person_5:
lockall
draw_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
faceplayer
loadpointer 0x0 str_0x958549
callstd MSG_KEEPOPEN
setvar 0x4001 0x85
givepokemon POKEMON_PORYGON 0x1e ITEM_NONE 0x0 0x0 0x0
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x9584ba
hide_mugshot
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
call ow_script_set_nickname
loadpointer 0x0 str_0x95839d
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
addvar STORY_PROGRESS 0x1
setflag ORINA_CITY_MISTRALS_GRUNTS
clearflag FLAG_ELISE_GONE
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
releaseall
end


ow_script_0x9584ba:
loadpointer 0x0 str_0x9584c8
callstd MSG
hide_mugshot
releaseall
end


.ifdef LANG_GER

str_0x958549:
   .autostring 35 2 "Hallo PLAYER!\nIch will dich nicht länger auf die Folter spannen.\pUnserer Forschungsgruppe ist es gelungen, ein Pokémon am Computer zu entwerfen und es dann Realität werden zu lassen.\pWir haben es Porygon genannt, aber über seine Fähigkeiten wissen wir praktisch nichts.\pDu bist der perfekte Kandidat, so ein Pokémon aufzuziehen, finde ich!\pIch werde dir ein Exemplar anvertrauen."


str_0x958498:
    .autostring 35 2 "PLAYER hat ein Porygon\nerhalten."



str_0x95839d:

	.autostring 35 2 "Ich bin mir sicher, dass du Fähigkeiten in diesem Pokémon zum Vorschein bringen kannst, die wir Entwickler uns niemals hätten vorstellen können.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pNun muss ich aber wieder zurück an die Arbeit.\pWir sehen uns, PLAYER."



str_0x9584c8:
    .autostring 35 2 "Wie schade, du scheinst keinen Platz mehr auf deinem PC zu haben.\pKomm doch wieder, wenn du das Porygon entgegennehmen kannst."


.elseif LANG_EN

.endif