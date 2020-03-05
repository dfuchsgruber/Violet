.include "flags.s"
.include "movements.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "move_tutor.s"
.include "specials.s"

.global ow_script_0x8a19d4
ow_script_0x8a19d4:
loadpointer 0x0 str_0x94568f
callstd MSG_FACE
call move_tutor_item_check
gotoif EQUAL ow_script_0x8faec2
end


.global ow_script_movs_0x8f511a
ow_script_movs_0x8f511a:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8faec2
ow_script_0x8faec2:
applymovement 0x800f ow_script_movs_0x8f511a
waitmovement 0x0
loadpointer 0x0 str_0x945eb7
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif LESS ow_script_0x8a1a57
loadpointer 0x0 str_0x8a1be6
callstd MSG
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
setvar 0x8005 MOVE_TUTOR_STEINHAGEL
call ow_script_move_tutor_do
clearflag TRANS_DISABLE
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8a1a57
call ow_script_move_tutor_pay_items
loadpointer 0x0 str_move_tutor_pay_items
callstd MSG
end


.global ow_script_move_tutor_pay_items
ow_script_move_tutor_pay_items:
setvar 0x8000 ITEM_RIESENPILZ
setvar 0x8001 0x1
checkitem ITEM_MINIPILZ 0x3
compare LASTRESULT 0x1
gotoif LESS ow_script_0x9455d9
setvar 0x8000 ITEM_MINIPILZ
setvar 0x8001 0x3
removeitem ITEM_MINIPILZ 0x3
goto ow_script_0x9455e4


.global ow_script_0x9455e4
ow_script_0x9455e4:
bufferitem 0x0 0x8000
buffernumber 0x1 0x8001
return


.global ow_script_0x9455d9
ow_script_0x9455d9:
removeitem ITEM_RIESENPILZ 0x1
goto ow_script_0x9455e4


.global ow_script_0x8a1a57
ow_script_0x8a1a57:
loadpointer 0x0 str_0x945830
callstd MSG
end


.global ow_script_move_tutor_do
ow_script_move_tutor_do:
special SPECIAL_MOVE_TUTOR_SELECT_POKEMON
waitstate
lock
faceplayer
return


.global move_tutor_item_check
move_tutor_item_check:
setvar 0x8000 ITEM_MINIPILZ
setvar 0x8001 0x3
checkitem ITEM_MINIPILZ 0x3
compare LASTRESULT 0x1
gotoif EQUAL buffer_move_tutor_item
setvar 0x8000 ITEM_RIESENPILZ
setvar 0x8001 0x1
checkitem ITEM_RIESENPILZ 0x1
compare LASTRESULT 0x1
gotoif EQUAL buffer_move_tutor_item
setvar LASTRESULT 0x0
item_check_return:
return


buffer_move_tutor_item:
bufferitem 0x0 0x8000
buffernumber 0x1 0x8001
setvar LASTRESULT 0x1
goto item_check_return


.ifdef LANG_GER
.global str_0x94568f

str_0x94568f:
    .string "Hyaa! Hajajaja!\nIn vielen Jahren des harten\lTraining habe ich meine\lKampftechnik so sehr verfeinert,\ldass ich Steine regnen lassen\lkann!\pSoll ich einem deiner Pokémon den\nSteinhagel beibringen?\pDann will ich einen Riesenpilz\noder drei Minipilze als\lGegenleistung!"
        
        
.global str_0x945eb7

str_0x945eb7:
    .string "Hyaa! Vortrefflich!\nDu hast BUFFER_2-mal BUFFER_1\lbei dir!\lAls Gegenleistung bringe ich einem\ldeiner Pokémon Steinhagel bei!\lWas sagst du dazu?"
        
        
.global str_0x8a1be6

str_0x8a1be6:
    .string "Schön, schön!\nWelches deiner Pokémon soll\lSteinhagel lernen?"
        
        
.global str_move_tutor_pay_items
str_move_tutor_pay_items:
    .string "PLAYER übergibt\nBUFFER_2-mal BUFFER_1."
        
        
.global str_0x945830

str_0x945830:
    .string "Hyaa! Wie schade!\pWenn ich einem deiner Pokémon\nSteinhagel beibringen soll, dann\lkomm mit 3 Minipilzen oder einem\lRiesenpilz wieder!"
        
        
.elseif LANG_EN

.endif
