.include "vars.s"
.include "move_tutor.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "movements.s"

.global ow_script_map_9_12_person_2
.global ow_script_map_9_12_person_3
.global ow_script_0x94610c
.global ow_script_0x9460a5
.global ow_script_map_9_12_person_1
.global ow_script_map_9_12_person_0

ow_script_map_9_12_person_0:
loadpointer 0x0 str_0x95d460
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95d460:
    .string "Mit einem Wissenschaftler\nverheiratet zu sein, ist nicht\limmer einfach.\pDen ganzen Tag redet er vom\nWellencharakter des Lichts.\lOder waren es doch Teilchen?"


.elseif LANG_EN

.endif


ow_script_map_9_12_person_3:
loadpointer 0x0 str_0x84c6c3
callstd MSG
end


.ifdef LANG_GER

str_0x84c6c3:
    .string "ZzzDOTS Schnarch DOTS\nGraaähDOTS ZzzDOTS ZzzDOTS"


.elseif LANG_EN

.endif


ow_script_map_9_12_person_2:
loadpointer 0x0 str_0x84c6fa
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x84c6fa:
    .string "Weißt du, mein Bruder schläft gar\nnicht, er tut nur so!"


.elseif LANG_EN

.endif

ow_script_map_9_12_person_1:
lock
faceplayer
setvar 0x8004 MOVE_TUTOR_LICHTKANONE
callasm move_tutor_set_flag
loadpointer 0x0 str_0x945f3c
callstd MSG_KEEPOPEN
call move_tutor_item_check
compare LASTRESULT 0
gotoif NOT_EQUAL ow_script_0x9460a5
closeonkeypress
release
end


ow_script_0x9460a5:
applymovement 0x800f mov_exclam
waitmovement 0x0
lock
faceplayer
loadpointer 0x0 str_0x946118
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif LESS ow_script_0x94610c
loadpointer 0x0 str_0x9461a3
callstd MSG
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
setvar 0x8005 MOVE_TUTOR_LICHTKANONE
call ow_script_move_tutor_do
clearflag TRANS_DISABLE
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x94610c
call ow_script_move_tutor_pay_items
loadpointer 0x0 str_move_tutor_pay_items
callstd MSG
end


ow_script_0x94610c:
loadpointer 0x0 str_0x9461dd
callstd MSG_KEEPOPEN
closeonkeypress
release
end

mov_exclam:
    .byte SAY_EXCLAM, STOP

.ifdef LANG_GER

str_0x945f3c:
    .string "Ich bin ein Forscher der Laz.Corp\nund fasziniert von der\lBeschaffenheit des Lichts.\pDie Lichtkanone ist der Angriff\nmeiner Wahl!\pAber ich bin auch sein Sammler.\nWenn du mir entweder 3 Minipilze\loder einen Riesenpilz bringst,\lkann ich im Gegenzug dafür einem\ldeiner Pokémon Lichtkanone\lbeibringen."



str_0x946118:
    .string "Vorzüglich!\nDu hast BUFFER_2-mal\lBUFFER_1 dabei!\pSoll ich nun einem deiner Pokémon\ndie Lichtkanone beibringen?"



str_0x9461a3:
    .string "Welchem deiner Pokémon soll ich\nLichtkanone beibringen?"



str_0x9461dd:
    .string "Wie unverhofft!\nSolltest du deine Einstellung\ländern und meine Faszination für\lLicht teilen, weißt du ja, wo du\lmich findest!"


.elseif LANG_EN

.endif