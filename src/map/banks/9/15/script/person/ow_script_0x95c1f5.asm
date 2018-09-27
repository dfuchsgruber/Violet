.include "flags.s"
.include "map_connections.s"
.include "movements.s"
.include "items.s"
.include "callstds.s"
.include "map_adjacency_types.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_movs_0x95c25e
ow_script_movs_0x95c25e:
.byte LOOK_UP
.byte STOP


.global ow_script_0x95c1f5
ow_script_0x95c1f5:
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


.global ow_script_0x95c261
ow_script_0x95c261:
lock
faceplayer
loadpointer 0x0 str_0x95c4b4
callstd MSG
setflag FOSSIL_IS_CURRENTLY_RESTAURATED
release
end


.global ow_script_0x95c3d3
ow_script_0x95c3d3:
loadpointer 0x0 str_0x95c3e1
callstd MSG_KEEPOPEN
goto ow_script_0x95c56e


.global ow_script_0x95c56e
ow_script_0x95c56e:
loadpointer 0x0 str_0x95c579
callstd MSG
release
end


.global ow_script_0x95c4fb
ow_script_0x95c4fb:
loadpointer 0x0 str_0x95c509
callstd MSG_KEEPOPEN
goto ow_script_0x95c56e


.global ow_script_0x95c271
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
call ow_script_0x893bb5
clearflag FOSSIL_IS_CURRENTLY_RESTAURATED
goto ow_script_0x95c56e


.global ow_script_0x95c2c6
ow_script_0x95c2c6:
loadpointer 0x0 str_0x95c353
callstd MSG_FACE
release
end


.ifdef LANG_GER
.global str_0x95c5d4

str_0x95c5d4:
    .string "Hallo, junger Trainer!\nDiese Maschine kann Fossilien\lwieder zum Leben erwecken.\pMöchtest du eines deiner Fossilien\nrestaurieren lassen?"
        
        
.global str_0x95c487

str_0x95c487:
    .string "Sehr wohl, ich werde dein\nBUFFER_1 restaurieren."
        
        
.global str_0x95c4b4

str_0x95c4b4:
    .string "Komm in genau einer Stunde wieder\nund die Maschine wird fertig sein."
        
        
.global str_0x95c3e1

str_0x95c3e1:
	.autostring 35 2 "Es sieht so aus, als würde die interne Spielzeit nicht voranschreiten.\pBesuche am besten das Haus des Uhrenmachers, ehe du ein Fossil zur Restauration abgeben möchtest."

.global str_0x95c579

str_0x95c579:
    .string "Solltest du ein Fossil finden,\nkannst du es hierher bringen und\lwiederherstellen lassen."
        
        
.global str_0x95c509

str_0x95c509:
    .string "Oh, es sieht so aus, als hättest\ndu kein Fossil bei dir, das ich\lwieder zum Leben erwecken könnte."
        
        
.global str_0x95c2eb

str_0x95c2eb:
    .string "Ah, du bist es!\nEs ist uns gelungen, das Fossil zu\lrestaurieren.\pEs hat sich als BUFFER_1 entpuppt.\pDOTS\nDOTS"
        
        
.global str_0x95c2d1

str_0x95c2d1:
    .string "PLAYER hat ein BUFFER_1\nerhalten!"
        
        
.global str_0x95c353

str_0x95c353:
    .string "Sieht so aus, als hättest du auf\ndeinem Pc keinen Platz mehr für\lweitere Pokémon.\pKomm wieder, wenn du Platz\ngeschaffen hast."
        
        
.elseif LANG_EN

.endif
