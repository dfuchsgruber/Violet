.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "map_adjacency_types.s"
.include "callstds.s"
.include "flags.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "items.s"

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
    .string "Die Fossilforschung mag vielen\nsteintrocken erscheinen.\pTatsächlich sind wir aber den\nAnfängen der Mensch-Pokémon\lGeschichte auf der Spur."


.elseif LANG_EN

.endif


ow_script_map_9_15_person_1:
loadpointer 0x0 str_0x95c6e9
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95c6e9:
    .string "Unser Traum war es immer,\nFossilien zum Leben erwecken zu\lkönnen.\pNun, da wir dazu im Stande sind,\nwo führt uns unser Weg hin?"


.elseif LANG_EN

.endif


ow_script_map_9_15_person_3:
loadpointer 0x0 str_0x95c769
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95c769:
    .string "Ist dir der Name Lester ein\nBegriff?\pEr ist ein großer Unterstützer des\nFossilienprojekts der Laz.Corp."


.elseif LANG_EN

.endif


ow_script_map_9_15_person_4:
loadpointer 0x0 str_0x95c7d2
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95c7d2:
    .string "Fossilien häufen sich dort, wo\neine hohe Mineralkonzentration\lvorherrscht.\pAuf diese Weise können wir\neffizienter antike Pokémon\lrestaurieren."


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
special 0x3e
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95c4fb
waitstate
compare LASTRESULT 0x7f
gotoif EQUAL ow_script_0x95c56e
special 0x3f
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
special2 0x800d 0x40
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
    .string "Hallo, junger Trainer!\nDiese Maschine kann Fossilien\lwieder zum Leben erwecken.\pMöchtest du eines deiner Fossilien\nrestaurieren lassen?"



str_0x95c487:
    .string "Sehr wohl, ich werde dein\nBUFFER_1 restaurieren."



str_0x95c4b4:
    .string "Komm in genau einer Stunde wieder\nund die Maschine wird fertig sein."



str_0x95c3e1:
	.autostring 35 2 "Es sieht so aus, als würde die interne Spielzeit nicht voranschreiten.\pBesuche am besten das Haus des Uhrenmachers, ehe du ein Fossil zur Restauration abgeben möchtest."


str_0x95c579:
    .string "Solltest du ein Fossil finden,\nkannst du es hierher bringen und\lwiederherstellen lassen."



str_0x95c509:
    .string "Oh, es sieht so aus, als hättest\ndu kein Fossil bei dir, das ich\lwieder zum Leben erwecken könnte."



str_0x95c2eb:
    .string "Ah, du bist es!\nEs ist uns gelungen, das Fossil zu\lrestaurieren.\pEs hat sich als BUFFER_1 entpuppt.\pDOTS\nDOTS"



str_0x95c2d1:
    .string "PLAYER hat ein BUFFER_1\nerhalten!"



str_0x95c353:
    .string "Sieht so aus, als hättest du auf\ndeinem PC keinen Platz mehr für\lweitere Pokémon.\pKomm wieder, wenn du Platz\ngeschaffen hast."


.elseif LANG_EN

.endif