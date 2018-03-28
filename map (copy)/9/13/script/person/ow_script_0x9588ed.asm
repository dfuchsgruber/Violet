.include "overworld_script.s"

.include "std.s"

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

.global str_0x958549

str_0x958549:
    .string "Hallo PLAYER!\nIch will dich nicht länger auf die\lFolter spannen.\pEs ist den Forschern hier\ngelungen, ein Pokémon, das am\lComputer gestaltet wurde, in die\lRealität umzusetzten.\pSein Name ist Porygon und da ich\nvon deinen Fähigkeiten als Trainer\lviel halte, konnte ich den\lPräsidenten der Laz.Corp davon\lüberzeugen, dir ein Exemplar\lanzuvertrauen."
        
        
.global str_0x958498

str_0x958498:
    .string "PLAYER hat ein Porygon erhalten."
        
        
.global str_0x95839d

str_0x95839d:
    .string "Ich bin gespannt, welche\nFähigkeiten du in diesem Pokémon\lzum Vorschein bringen wirst.\p...\nNun muss ich aber wieder selbst an\ldie Arbeit.\pEs gibt da noch die ein oder\nandere Feldstudie, die für\lProfssor Tann erledigt werden\lmuss.\pWir sehen uns, PLAYER."
        
        
.global str_0x9584c8

str_0x9584c8:
    .string "Wie schade, du scheinst keinen\nPlatz mehr auf deinem PC zu haben.\pKomm doch wieder, wenn du das\nPorygon entgegennehmen kannst."
        
        