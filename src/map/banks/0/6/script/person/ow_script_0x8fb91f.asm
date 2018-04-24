.include "flags.s"
.include "movements.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_movs_0x8fe753
ow_script_movs_0x8fe753:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8fe741
ow_script_movs_0x8fe741:
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x8fe73d
ow_script_movs_0x8fe73d:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8fb91f
ow_script_0x8fb91f:
loadpointer 0x0 str_0x8fe75c
callstd MSG
clearflag PKMNMENU
setvar LASTTALKED 0xe
showsprite LASTTALKED
applymovement LASTTALKED ow_script_movs_0x8fe753
waitmovement 0x0
getplayerpos 0x8000 0x8001
compare 0x8000 0x21
callif EQUAL ow_script_0x8fe744
applymovement LASTTALKED ow_script_movs_0x8fe741
waitmovement 0x0
sound 0x15
applymovement 0xff ow_script_movs_0x8fe73d
waitmovement 0x0
checksound
setflag PKMNMENU
trainerbattlecont 0x1 0x58 0x0 str_0x8fe6cd str_0x8fe674 ow_script_0x8fe2d1


.global ow_script_movs_0x8fe783
ow_script_movs_0x8fe783:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8fe47c
ow_script_movs_0x8fe47c:
.byte LOOK_UP
.byte STOP


.global ow_script_0x8fe2d1
ow_script_0x8fe2d1:
loadpointer 0x0 str_0x8fe5f1
callstd MSG
setvar DYN_MULTICHOICE_ITEM_CNT 0x2
loadpointer 0x0 choice1
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8fe785
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8fe57c
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x8fe783
waitmovement 0x0
setvar 0x8005 0xf8
special2 0x8005 0xc
loadpointer 0x0 str_0x8fe51d
callstd MSG
setvar DYN_MULTICHOICE_ITEM_CNT 0x2
loadpointer 0x0 choice2
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
copyvar 0x8006 LASTRESULT
compare 0x8006 0x0
callif EQUAL ow_script_0x9270fb
compare 0x8006 0x1
callif EQUAL ow_script_0x927370
getplayerpos 0x8005 0x8004
compare 0x8005 0x20
callif EQUAL ow_script_0x8fe513
compare 0x8005 0x21
callif EQUAL ow_script_0x8fe518
fanfare 0x13e
loadpointer 0x0 str_0x8fe4dd
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
compare 0x8005 0x20
callif EQUAL ow_script_0x8fe4bb
compare 0x8005 0x21
callif EQUAL ow_script_0x8fe4cc
loadpointer 0x0 str_0x8fe47f
callstd MSG
applymovement LASTTALKED ow_script_movs_0x8fe47c
waitmovement 0x0
sound 0x17
compare 0x8005 0x20
callif EQUAL ow_script_0x8fe518
compare 0x8005 0x21
callif EQUAL ow_script_0x8fe513
loadpointer 0x0 str_0x8fe443
callstd MSG
goto ow_script_0x8fee78

.align 4
choice1:
    .word str_fossil_choice_0, 0
    .word str_fossil_choice_1, 0

.align 4
choice2:
    .word str_fossil_choice_2, 0
    .word str_fossil_choice_3, 0


.global ow_script_0x8fee78
ow_script_0x8fee78:
compare 0x8005 0x20
callif EQUAL ow_script_0x8fe425
compare 0x8005 0x21
callif EQUAL ow_script_0x8fe431
loadpointer 0x0 str_0x8fe3db
callstd MSG
fadescreen 0x1
hidesprite LASTTALKED
fadescreen 0x0
end


.global ow_script_movs_0x8fe440
ow_script_movs_0x8fe440:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x8fe431
ow_script_0x8fe431:
applymovement LASTTALKED ow_script_movs_0x8fe440
waitmovement 0x0
return


.global ow_script_movs_0x8fe43d
ow_script_movs_0x8fe43d:
.byte LOOK_LEFT
.byte STOP


.global ow_script_0x8fe425
ow_script_0x8fe425:
applymovement LASTTALKED ow_script_movs_0x8fe43d
waitmovement 0x0
return


.global ow_script_0x8fe513
ow_script_0x8fe513:
hidesprite 0xc
return


.global ow_script_0x8fe518
ow_script_0x8fe518:
hidesprite 0xd
return


.global ow_script_movs_0x8fe4d8
ow_script_movs_0x8fe4d8:
.byte STEP_LEFT
.byte STEP_UP
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x8fe4cc
ow_script_0x8fe4cc:
applymovement LASTTALKED ow_script_movs_0x8fe4d8
waitmovement 0x0
return


.global ow_script_movs_0x8fe4c7
ow_script_movs_0x8fe4c7:
.byte STEP_RIGHT
.byte STEP_UP
.byte LOOK_LEFT
.byte STOP


.global ow_script_0x8fe4bb
ow_script_0x8fe4bb:
applymovement LASTTALKED ow_script_movs_0x8fe4c7
waitmovement 0x0
return


.global ow_script_0x927370
ow_script_0x927370:
bufferitem 0x0 ITEM_WURZELFOSSIL
checkitemroom ITEM_WURZELFOSSIL 0x1
compare LASTRESULT 0x0
callif EQUAL ow_script_0x92738e
additem ITEM_WURZELFOSSIL 0x1
clearflag CLAW_FOSSIL_TAKEN
return


.global ow_script_0x92738e
ow_script_0x92738e:
loadpointer 0x0 str_0x927398
callstd MSG_SIGN
return


.global ow_script_0x9270fb
ow_script_0x9270fb:
bufferitem 0x0 ITEM_KLAUENFOSSIL
checkitemroom ITEM_KLAUENFOSSIL 0x1
compare LASTRESULT 0x0
callif EQUAL ow_script_0x92738e
additem ITEM_KLAUENFOSSIL 0x1
setflag CLAW_FOSSIL_TAKEN
return


.global ow_script_0x8fe785
ow_script_0x8fe785:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8fee9e
callstd MSG
special 0x7
loadpointer 0x0 str_0x8fea2c
callstd MSG
applymovement 0xff ow_script_movs_0x8fe783
waitmovement 0x0
setvar 0x8005 0x8
special2 0x8005 0xc
loadpointer 0x0 str_0x8fe51d
callstd MSG
setvar DYN_MULTICHOICE_ITEM_CNT 0x2
loadpointer 0x0 choice2
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
copyvar 0x8006 LASTRESULT
compare 0x8006 0x0
callif EQUAL ow_script_0x9270fb
compare 0x8006 0x1
callif EQUAL ow_script_0x927370
getplayerpos 0x8005 0x8004
compare 0x8005 0x20
callif EQUAL ow_script_0x8fe513
compare 0x8005 0x21
callif EQUAL ow_script_0x8fe518
fanfare 0x13e
loadpointer 0x0 str_0x8fe4dd
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
compare 0x8005 0x20
callif EQUAL ow_script_0x8fe4bb
compare 0x8005 0x21
callif EQUAL ow_script_0x8fe4cc
sound 0x17
compare 0x8005 0x20
callif EQUAL ow_script_0x8fe518
compare 0x8005 0x21
callif EQUAL ow_script_0x8fe513
loadpointer 0x0 str_0x8fe443
callstd MSG
compare 0x8005 0x20
callif EQUAL ow_script_0x8fe425
compare 0x8005 0x21
callif EQUAL ow_script_0x8fe431
loadpointer 0x0 str_0x8fe8d0
callstd MSG
fadescreen 0x1
hidesprite LASTTALKED
fadescreen 0x0
end


.global ow_script_movs_0x8fe750
ow_script_movs_0x8fe750:
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8fe744
ow_script_0x8fe744:
applymovement LASTTALKED ow_script_movs_0x8fe750
waitmovement 0x0
return


.ifdef LANG_GER
.global str_0x8fe75c

str_0x8fe75c:
    .string "Der Stein sieht aus wie ein\nFossil..."
        
        
.global str_0x8fe6cd

str_0x8fe6cd:
    .string "Du da! Stop! Diese Fossilien dort\nhabe ich schon seit Jahren\lgesucht, also stehen sie auch mir\lzu, nicht dir!"
        
        
.global str_0x8fe674

str_0x8fe674:
    .string "Das ... das ist nicht möglich!\nMein Leben lang habe ich nach\ldiesen Fossilien gesucht."
        
        
.global str_0x8fe5f1

str_0x8fe5f1:
    .string "Mein ganzes Leben habe ich der\nSuche nach Fossilien gewidmet und\ljetzt, da ich sie gefunden habe,\lkommt ein anderer mir zuvor..."
        
        
.global str_0x8fe5b8

str_0x8fe5b8:
    .string "GqゼËbqゼË"
        
        
.global str_0x8fe57c

str_0x8fe57c:
    .string "Diese Fossilien gehören mir, du\nhast kein Anrecht darauf!"
        
        
.global str_0x8fe51d

str_0x8fe51d:
    .string "Welches der Fossilien möchtest du\nzuerst aufnehmen?"
        
        
.global str_fossil_choice_0

str_fossil_choice_0:
    .string "Ein Fossil abgeben"
        
        
.global str_fossil_choice_1

str_fossil_choice_1:
    .string "Beide Fossilien behalten"
        
        
.global str_fossil_choice_2

str_fossil_choice_2:
    .string "Klauenfossil"
        
        
.global str_fossil_choice_3

str_fossil_choice_3:
    .string "Wurzelfossil"
        
        
.global str_0x8fe4dd

str_0x8fe4dd:
    .string "PLAYER hat das BUFFER_1\nerhalten!"
        
        
.global str_0x8fe47f

str_0x8fe47f:
    .string "Von dir lasse ich mir meinen Traum\nnicht zunichte machen!"
        
        
.global str_0x8fe443

str_0x8fe443:
    .string "Der Ruinenmaniac hat das\nverbleidende Fossil genommen!"
        
        
.global str_0x8fe3db

str_0x8fe3db:
    .string "Adios, du frecher Bengel! Hättest\nmir beinahe den Lebenstraum\lzerstört!"
        
        
.global str_0x927398

str_0x927398:
    .string "Das BUFFER_1 zerbröselte,\nda kein Platz im Beutel ist."
        
        
.global str_0x8fee9e

str_0x8fee9e:
    .string "Ich will dir deinen Lebenstraum\nnicht zunichte machen.\pGlücklicherweise sind dort zwei\nFossilien, ich schlage vor, dass\ljeder von uns eines für sich\lbehalten darf."
        
        
.global str_0x8fea2c

str_0x8fea2c:
    .string "Du bist sehr großzügig. Dein\nAngebot will ich gerne annehmen.\pUnd weil du mir gegenüber so\nfreundlich bist, darfst du zuerst\leines der Fossilien auswählen."
        
        
.global str_0x8fe8d0

str_0x8fe8d0:
    .string "Endlich konnte ich meinen großen\nTraum in Erfüllung gehen lassen!\pFossilien sind versteinerte\nPokémon und mittels hoch\lentwickelter Technologie kann man\lsie sogar wieder zu neuem Leben\lerwecken.\pDie Laz.Corp betreibt aufwändige\nForschungen in diesem Bereich.\lIhren Hauptsitz hat sie in Orina\lCity. Ein Besuch kann nicht\lschaden.\pAuf Wiedersehen!"
        
        
.elseif LANG_EN

.endif
