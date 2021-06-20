.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "map_adjacency_types.s"
.include "callstds.s"
.include "flags.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "items.s"
.include "specials.s"

.global ow_script_0x95c261
.global ow_script_0x95c4fb
.global ow_script_0x95c3d3
.global ow_script_map_9_15_person_3
.global ow_script_map_9_15_person_2
.global ow_script_map_9_15_person_0
.global ow_script_map_9_15_person_1
.global ow_script_0x95c2c6
.global ow_script_0x95c56e
.global ow_script_0x95c271
.global ow_script_map_9_15_person_4

ow_script_map_9_15_person_2:
loadpointer 0x0 str_0x95c65d
callstd MSG_FACE
end


.ifdef LANG_GER
str_0x95c65d:
    .autostring 34 2 "Unsere Forschung ist unglaublich spannend.\pWir sind quasi den Anfängen der Beziehung zwischen Mensch und Pokémon auf der Spur."
.elseif LANG_EN
.endif


ow_script_map_9_15_person_1:
loadpointer 0x0 str_0x95c6e9
callstd MSG_FACE
end


.ifdef LANG_GER
str_0x95c6e9:
    .autostring 34 2 "Ich habe immer davon geträumt, Fossilien wieder zum Leben erwecken zu können.\pAber nun, da wir dazu im Stande sindDOTS\pIch frage mich, was als nächstes kommt."
.elseif LANG_EN
.endif


ow_script_map_9_15_person_3:
loadpointer 0x0 str_0x95c769
callstd MSG_FACE
end


.ifdef LANG_GER
str_0x95c769:
    .autostring 34 2 "Sagt dir der Name Lester etwas?\pEr ist ein großer Unterstützer unseres Fossilien-Restaurations Projekts.\pEr und sein Vater waren schon immer sehr begeistert von der Arbeit unserer Gruppe."
.elseif LANG_EN
.endif


ow_script_map_9_15_person_4:
loadpointer 0x0 str_0x95c7d2
callstd MSG_FACE
end


.ifdef LANG_GER
str_0x95c7d2:
    .autostring 34 2 "Ein Fossil wieder zu erwecken ist einfacher, als man es sich vorstellt.\pAber scheinbar schwer genug, dass es uns jahrelange Forschung abverlangt hat, die nötige Technologie dafür zu entwickeln."
.elseif LANG_EN
.endif


ow_script_movs_0x95c25e:
.byte LOOK_UP
.byte STOP


ow_script_map_9_15_person_0:
lock
faceplayer
checkflag FOSSIL_IS_CURRENTLY_RESTAURATED
gotoif EQUAL ow_script_0x95c271
loadpointer 0x0 str_0x95c5d4
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95c56e
special SPECIAL_FOSSIL_PRINT_ITEMS
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95c4fb
waitstate
compare LASTRESULT 0x7f
gotoif EQUAL ow_script_0x95c56e
special SPECIAL_FOSSIL_GIVE
compare 0x8004 0
gotoif EQUAL ow_script_0x95c3d3
bufferitem 0x0 0x8004
loadpointer 0x0 str_0x95c487
callstd MSG
applymovement 0x800f ow_script_movs_0x95c25e
waitmovement 0x0
sound 0x22
checksound
pause 0x10
goto ow_script_0x95c261


ow_script_0x95c261:
lock
faceplayer
loadpointer 0x0 str_0x95c4b4
callstd MSG
setflag FOSSIL_IS_CURRENTLY_RESTAURATED
release
end


ow_script_0x95c3d3:
loadpointer 0x0 str_0x95c3e1
callstd MSG_KEEPOPEN
goto ow_script_0x95c56e


ow_script_0x95c56e:
loadpointer 0x0 str_0x95c579
callstd MSG
release
end


ow_script_0x95c4fb:
loadpointer 0x0 str_0x95c509
callstd MSG_KEEPOPEN
goto ow_script_0x95c56e


ow_script_0x95c271:
special2 LASTRESULT 0x40
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95c261
bufferpokemon 0x0 FOSSIL_RESTAURATED_SPECIES
loadpointer 0x0 str_0x95c2eb
callstd MSG_KEEPOPEN
givepokemon FOSSIL_RESTAURATED_SPECIES 0x19 ITEM_NONE 0x0 0x0 0x0
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x95c2c6
fanfare 0x13e
loadpointer 0x0 str_0x95c2d1
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
call ow_script_set_nickname
clearflag FOSSIL_IS_CURRENTLY_RESTAURATED
goto ow_script_0x95c56e


ow_script_0x95c2c6:
loadpointer 0x0 str_0x95c353
callstd MSG_FACE
release
end


.ifdef LANG_GER
str_0x95c5d4:
    .autostring 34 2 "Hallo, junger Trainer!\pDiese Maschine hier kann Fossilien wieder zum Leben erwecken.\pMöchtest du eines deiner Fossilien restaurieren lassen?"
str_0x95c487:
    .autostring 34 2  "Sehr wohl, ich werde dein BUFFER_1 restaurieren."
str_0x95c4b4:
    .autostring 34 2  "Komm in etwa einer Stunde wieder.\pDann wird die Maschine fertig sein."
str_0x95c3e1:
	.autostring 34 2 "Es sieht so aus, als würde die interne Spielzeit nicht voranschreiten.\pBesuche am besten das Haus des Uhrenmachers, ehe du ein Fossil zur Restauration abgeben möchtest."
str_0x95c579:
    .autostring 34 2 "Solltest du ein Fossil finden, kannst du es hierher bringen und wiederherstellen lassen."
str_0x95c509:
    .autostring 34 2 "Oh, es sieht so aus, als hättest du kein Fossil bei dir, das ich wieder zum Leben erwecken könnte."
str_0x95c2eb:
    .autostring 34 2 "Ah, du bist es!\nEs ist uns gelungen, das Fossil zu restaurieren.\pEs hat sich als BUFFER_1 entpuppt.\pDOTS\nDOTS DOTS DOTS"
str_0x95c2d1:
    .autostring 34 2 "PLAYER hat ein BUFFER_1 erhalten!"
str_0x95c353:
    .autostring 34 2 "Sieht so aus, als hättest du auf deinem PC keinen Platz mehr für weitere Pokémon.\pKomm wieder, wenn du Platz geschaffen hast."
.elseif LANG_EN

.endif