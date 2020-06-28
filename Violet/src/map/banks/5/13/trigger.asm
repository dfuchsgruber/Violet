.include "ordinals.s"
.include "vars.s"
.include "battle/battle_handicaps.s"
.include "movements.s"
.include "specials.s"
.include "callstds.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"
.include "difficulties.s"

.global ow_script_0x93d02f
.global ow_script_0x93d210
.global ow_script_0x93cadd
.global ow_script_0x93cacf
.global ow_script_0x93cd2e
.global ow_script_map_5_13_trigger_1
.global ow_script_0x93d40c
.global ow_script_0x93d576
.global ow_script_0x93d077
.global ow_script_0x93cbde
.global ow_script_0x93d4a1
.global ow_script_map_5_13_trigger_0
.global ow_script_0x94b868
.global ow_script_0x93d0a3
.global ow_script_0x93cbd1
.global ow_script_0x93d156
.global ow_script_0x93cbc4
.global ow_script_0x93d358
.global ow_script_0x93d40f
.global ow_script_0x948d14
.global ow_script_0x94903b
.global ow_script_0x93d018
.global ow_script_0x948fc2

ow_script_movs_0x93cb65:
.byte STEP_UP
.byte LOOK_RIGHT
.byte STOP


ow_script_map_5_13_trigger_1:
applymovement 0xff ow_script_movs_0x93cb65
waitmovement 0x0
goto ow_script_map_5_13_trigger_0


ow_script_movs_0x93cd29:
.byte STEP_UP
.byte STOP


ow_script_movs_0x93cd2c:
.byte FACE_DOWN
.byte STOP


ow_script_map_5_13_trigger_0:
lockall
applymovement 0x7 ow_script_movs_0x93cd29
waitmovement 0x0
applymovement 0xff ow_script_movs_0x93cd2c
waitmovement 0x0
checkflag FRBADGE_3
gotoif EQUAL ow_script_0x93cadd
compare DIFFICULTY DIFFICULTY_EASY
callif EQUAL ow_script_0x93cbc4
compare DIFFICULTY DIFFICULTY_NORMAL
callif EQUAL ow_script_0x93cbd1
compare DIFFICULTY DIFFICULTY_HARD
callif EQUAL ow_script_0x93cbde
loadpointer 0x0 str_0x93cbff
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x93cacf
goto ow_script_0x93d018


ow_script_0x93d018:
setvar MERIANA_ARENA_TRAINERS 0x4
settrainerflag 0x80
settrainerflag 0x81
settrainerflag 0x82
settrainerflag 0x83
goto ow_script_0x93d02f


ow_script_movs_0x93d3b2:
.byte LOOK_RIGHT
.byte STOP


ow_script_movs_0x93cb81:
.byte STEP_DOWN
.byte LOOK_UP
.byte STOP


ow_script_0x93d02f:
applymovement 0xff ow_script_movs_0x93d3b2
waitmovement 0x0
applymovement 0x7 ow_script_movs_0x93cb81
waitmovement 0x0
compare MERIANA_ARENA_TRAINERS 0x4
gotoif EQUAL ow_script_0x93d077
compare MERIANA_ARENA_TRAINERS 0x3
gotoif EQUAL ow_script_0x93d0a3
compare MERIANA_ARENA_TRAINERS 0x2
gotoif EQUAL ow_script_0x93d156
compare MERIANA_ARENA_TRAINERS 0x1
gotoif EQUAL ow_script_0x93d210
goto ow_script_0x93d576


ow_script_movs_0x949189:
.byte JUMP_LEFT2
.byte STEP_LEFT_VERY_SLOW
.byte STOP


ow_script_0x93d576:
clearflag PKMNMENU
showsprite 0xa
setflag PKMNMENU
applymovement 0xa ow_script_movs_0x949189
waitmovement 0x0

loadpointer 0 str_manus
setvar 0x8000 0
special 0xE
special SPECIAL_BATTLE_HANDICAP_CLEAR
setvar 0x8004 BATTLE_HANDICAP_ARENA_ENCOURAGEMENT
special SPECIAL_BATTLE_HANDICAP_SET
trainerbattlecont 0x1 0xb8 0x0 str_0x948a7f str_0x948b5a ow_script_0x94b868


ow_script_0x94b868:
setvar 0x8004 2
setvar 0x8005 2
special SPECIAL_BUFFER_BADGE_NAME

loadpointer 0 str_manus
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x94907f
callstd MSG_KEEPOPEN
special 0xF

fanfare 0x104
loadpointer 0x0 str_0x949053
callstd MSG_KEEPOPEN
waitfanfare
setflag FRBADGE_3
setflag MERIANA_CITY_ELISE_VISIBLE

loadpointer 0 str_manus
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x948eb4
callstd MSG_KEEPOPEN
special 0xF

copyvarifnotzero 0x8000 ITEM_TM01
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN

loadpointer 0 str_manus
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x948d53
callstd MSG_KEEPOPEN
special 0xF
closeonkeypress
addvar STORY_PROGRESS 0x1
warpmuted 0x3 0x1 0x2 0x0 0x0
release
end


ow_script_movs_0x93d563:
.byte STEP_LEFT
.byte JUMP_LEFT2
.byte STOP


ow_script_0x93d210:
setvar 0x800A 0x8
clearflag PKMNMENU
showsprite 0x800A
setflag PKMNMENU
applymovement 0x800A ow_script_movs_0x93d563
waitmovement 0x0
trainerbattlecont 0x1 0x83 0x0 str_0x948a18 str_0x948c44 ow_script_0x93d358


ow_script_movs_0x93d567:
.byte STEP_RIGHT
.byte JUMP_RIGHT2
.byte STOP


ow_script_0x93d358:
applymovement 0x800A ow_script_movs_0x93d567
waitmovement 0x0
hidesprite 0x800A
applymovement 0x7 ow_script_movs_0x93cd29
waitmovement 0x0
applymovement 0xff ow_script_movs_0x93cd2c
waitmovement 0x0
subvar MERIANA_ARENA_TRAINERS 0x1
compare MERIANA_ARENA_TRAINERS 0x0
callif EQUAL ow_script_0x93d40f
compare MERIANA_ARENA_TRAINERS 0x0
callif HIGHER ow_script_0x93d4a1
compare MERIANA_ARENA_HEALS 0x0
callif EQUAL ow_script_0x93d40c
compare MERIANA_ARENA_HEALS 0x0
callif HIGHER ow_script_0x94903b
goto ow_script_0x93d02f


ow_script_0x94903b:
loadpointer 0x0 str_0x93d3ca
callstd MSG_YES_NO
compare LASTRESULT 0x1
callif EQUAL ow_script_0x948d14
closeonkeypress
clearflag TRANS_DISABLE
return


ow_script_0x948d14:
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
loadpointer 0x0 str_0x949015
callstd MSG_KEEPOPEN
special 0x9f
waitstate
lock
faceplayer
compare 0x8004 0x6
gotoif HIGHER_OR_EQUAL ow_script_0x948fc2
special 0x26
loadpointer 0x0 str_0x948f99
callstd MSG_KEEPOPEN
subvar MERIANA_ARENA_HEALS 0x1
return


ow_script_0x948fc2:
loadpointer 0x0 str_0x948fcc
callstd MSG_KEEPOPEN
return


ow_script_0x93d40c:
closeonkeypress
return


ow_script_0x93d4a1:
loadpointer 0x0 str_0x93d4ab
callstd MSG_KEEPOPEN
return


ow_script_0x93d40f:
loadpointer 0x0 str_0x93d419
callstd MSG_KEEPOPEN
return


ow_script_0x93d156:
setvar 0x800A 0x9
clearflag PKMNMENU
showsprite 0x800A
setflag PKMNMENU
applymovement 0x800A ow_script_movs_0x93d563
waitmovement 0x0
trainerbattlecont 0x1 0x82 0x0 str_0x93d182 str_0x93d1dd ow_script_0x93d358


ow_script_0x93d0a3:
setvar 0x800A 0x8
clearflag PKMNMENU
showsprite 0x800A
setflag PKMNMENU
applymovement 0x800A ow_script_movs_0x93d563
waitmovement 0x0
trainerbattlecont 0x1 0x81 0x0 str_0x93d0cf str_0x93d123 ow_script_0x93d358


ow_script_0x93d077:
setvar 0x800A 0x9
clearflag PKMNMENU
showsprite 0x800A
setflag PKMNMENU
applymovement 0x800A ow_script_movs_0x93d563
waitmovement 0x0
trainerbattlecont 0x1 0x80 0x0 str_0x93d4e4 str_0x93d52c ow_script_0x93d358


ow_script_0x93cacf:
loadpointer 0x0 str_0x93cb85
callstd MSG
goto ow_script_0x93cd2e


ow_script_movs_0x93cb7d:
.byte JUMP_LEFT2
.byte STEP_LEFT
.byte STOP


ow_script_0x93cd2e:
applymovement 0x7 ow_script_movs_0x93cb81
waitmovement 0x0
sound 0xa
applymovement 0xff ow_script_movs_0x93cb7d
waitmovement 0x0
releaseall
end


ow_script_0x93cbde:
bufferstring 0x0 str_0x93cbf8
setvar MERIANA_ARENA_HEALS 0x0
return


ow_script_0x93cbd1:
bufferstring 0x0 str_0x93cbf2
setvar MERIANA_ARENA_HEALS 0x1
return


ow_script_0x93cbc4:
bufferstring 0x0 str_0x93cbeb
setvar MERIANA_ARENA_HEALS 0x2
return


ow_script_0x93cadd:
loadpointer 0x0 str_0x93caeb
callstd MSG
goto ow_script_0x93cd2e


.ifdef LANG_GER

str_manus:
	.string "Manus"


str_0x93cbff:
    .string "Halt!\nBevor du dich der Herausforderung\ldieser Arena stellst, solltest du\lwissen, wie hier gekämpft wird.\pDu kämpfst gegen vier Gegner in\nFolge und schließlich gegen Manus,\lden Arenaleiter.\pZwischen den Kämpfen erlauben wir\ndir BUFFER_1 Mal eines deiner Pokémon\lzu heilen.\pBist du damit einverstanden?"



str_0x948a7f:
	.autostring 35 2 "Sieht an!\nDass du es bis hierher schaffen würdest, war mir klar.\pJetzt aber beginnt die wahre Kraftprobe!\pWie zähl bist du wirklich?\pKannst du dich gegen meinen Schläge zur Wehr setzten?\pUnd viel wichtiger, kannst du auch zurückschlagen?"



str_0x948b5a:
	.autostring 35 2 "Starke Sache!\nDu hast meiner rohen Muskelkraft widerstanden!"



str_0x94907f:
	.autostring 35 2 "Außerordentlich stark!\pDu hast einen verbissen Kampfstil!\pDas gefällt mir!\pDen BUFFER_3 hast du dir redlich verdient!"


str_0x949053:
    .autostring 35 2 "PLAYER hat den BUFFER_3 von Manus erhalten."



str_0x948eb4:
	.autostring 35 2 "Der BUFFER_3 erlaubt es dir, die Versteckte Maschine Fliegen außerhalb des Kampfes einzusetzten.\pAußerdem gehorchen dir alle Pokémon bis Level 50.\pZudem möchte ich dir das hier überreichen."



str_0x948d53:
	.autostring 35 2 "Diese Tm enthält Power-Punch, den mächtigsten aller Schläge!\pAllerdings erfordert es Fokus, um diesen Schlag auszuführen.\pNur ein wahrer Kämpfer weiß diese Technik richtig einzusetzten.\pUnd nun Kindchen, verlasse diesen Kampfring und halte an deinem verbissenen Kampfgeist fest."


str_0x948a18:
    .string "Du denkst, dass du Manus\nherausfordern kannst?\pFalsch gedacht! An mir scheitern\nsie alle schließlich!"



str_0x948c44:
    .string "Ich ziehe mein Stirnband vor dir!\nZeig dem Boss, was du kannst!"



str_0x93d3ca:
    .string "Möchtest du eines deiner Pokémon\nvor dem nächsten Kampf heilen?"



str_0x949015:
    .string "Welches Pokémon soll geheilt\nwerden?"



str_0x948f99:
    .string "Das Pokémon wurde vollständig\ngeheilt."



str_0x948fcc:
    .string "Dann fahren wir einfach fort!\nMach dich bereit für den nächsten\lKampf!"



str_0x93d4ab:
    .string "Fantastisch! Dein nächster Gegner\nerwartet dich schon."



str_0x93d419:
    .string "Atemberaubend! Meisterlich!\nDu hast es geschafft, vier Kämpfe\lin Folge zu gewinnen.\lNun wird dir Leiter Manus selbst\lgegenübertreten."



str_0x93d182:
    .string "Eines Tages werde ich Manus\nheiraten und wir werden\lwunderschöne Kämpferkinder\lbekommen!"



str_0x93d1dd:
    .string "Soll das heißen, er wird meinen\nAntrag ablehnen?"



str_0x93d0cf:
    .string "Manus ist niemand, der es gerne\nmit Schwachmaten aufnimmt.\lIch werde dich prüfen!"



str_0x93d123:
    .string "Oh, du scheinst einiges auf dem\nKasten zu haben."



str_0x93d4e4:
    .string "Unterschätze niemals die Tritte\neiner Frau!\lIch werde dich zermalmen!"



str_0x93d52c:
    .string "Was? Unmöglich!\nWie konnte ich gegen dich\lverlieren?"



str_0x93cb85:
    .string "Komm wieder, wenn du für diese Art\ndes Kämpfens bereit bist!"



str_0x93cbf8:
    .string "kein"



str_0x93cbf2:
    .string "ein"



str_0x93cbeb:
    .string "zwei"



str_0x93caeb:
    .string "Du hast diese Arena bereits\nbezwungen, mach dich auf die Suche\lnach neuen Abenteuern anstatt\lErinnerungen nachzutrauern!"


.elseif LANG_EN

.endif