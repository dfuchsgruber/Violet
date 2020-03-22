.include "flags.s"
.include "movements.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "mugshot.s"


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

loadpointer 0 str_maniac
setvar 0x8000 1
special 0xE
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


loadpointer 0 str_maniac
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8fe5f1
callstd MSG
special 0xF
goto ow_script_0x8fe785

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

loadpointer 0 str_maniac
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8fe3db
callstd MSG
special 0xF

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
loadpointer 0x0 str_0x8fee9e
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT


loadpointer 0 str_maniac
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8fea2c
callstd MSG
special 0xF

applymovement 0xff ow_script_movs_0x8fe783
waitmovement 0x0

loadpointer 0x0 str_0x8fe51d
callstd MSG_KEEPOPEN

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
checksound
pause 32
compare 0x8005 0x20
callif EQUAL ow_script_0x8fe518
compare 0x8005 0x21
callif EQUAL ow_script_0x8fe513


loadpointer 0 str_maniac
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8fe443
callstd MSG
special 0xF

compare 0x8005 0x20
callif EQUAL ow_script_0x8fe425
compare 0x8005 0x21
callif EQUAL ow_script_0x8fe431


loadpointer 0 str_maniac
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8fe8d0
callstd MSG
special 0xF
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

str_maniac:
	.string "Ruinenmaniac"

.global str_0x8fe75c

str_0x8fe75c:
    .autostring 35 2 "Der Stein sieht aus wie ein FossilDOTS"
        
        
.global str_0x8fe6cd

str_0x8fe6cd:
    .autostring 35 2 "Du da! Halt!\nDiese Fossilien habe ich bereits seit Jahren gesucht!\pSie stehen mir zu, nicht dir!"
        
        
.global str_0x8fe674

str_0x8fe674:
    .autostring 35 2 "Das DOTS das ist nicht möglich!\pMein Leben lang habe ich nach diesen Fossilien gesucht."
        
        
.global str_0x8fe5f1

str_0x8fe5f1:
    .autostring 35 2  "Mein ganzes Leben habe ich der Suche nach Fossilien gewidmet und jetzt, da ich sie gefunden habe, kommt ein anderer mir zuvorDOTS"
        

        
.global str_0x8fe57c

str_0x8fe57c:
    .autostring 35 2 "Diese Fossilien gehören mir, du hast kein Anrecht darauf!"
        
        
.global str_0x8fe51d

str_0x8fe51d:
    .autostring 35 2 "Welches der Fossilien möchtest du\nzuerst aufnehmen?"
        
        
        
.global str_fossil_choice_2

str_fossil_choice_2:
    .string "Klauenfossil"
        
        
.global str_fossil_choice_3

str_fossil_choice_3:
    .string "Wurzelfossil"
        
        
.global str_0x8fe4dd

str_0x8fe4dd:
    .autostring 35 2 "PLAYER hat das BUFFER_1\nerhalten!"
        
        
.global str_0x8fe47f

str_0x8fe47f:
    .autostring 35 2 "Von dir lasse mich mir die Fossilien nicht wegnehmen!"
        
        
.global str_0x8fe443

str_0x8fe443:
    .autostring 35 2 "Der Ruinenmaniac hat das verbleidende Fossil genommen!"
        
        
.global str_0x8fe3db

str_0x8fe3db:
    .autostring 35 2 "Du freches Kind!\pDass du die Frechheit besitzt, auch nur eines der Fossilien zu beanspruchen DOTS"
        
        
.global str_0x927398

str_0x927398:
    .autostring 35 2 "Das BUFFER_1 zerbröselte, da kein Platz im Beutel ist."
        
        
.global str_0x8fee9e

str_0x8fee9e:
    .autostring 35 2 "Ich war vor dir hier, also habe ich auch ein Recht auf die Fossilien.\pAllerdings befinden sich dort ohnehin zwei Stück.\pWie wäre es, wenn jeder ein Fossil erhält?"
        
        
.global str_0x8fea2c

str_0x8fea2c:
	.autostring 35 2 "Ah, ich sehe, du lässt mit dir reden.\pAlso gut, dann nimmt jeder ein Fossil.\pIch lasse dir gerne den Vortritt, Kindchen!"
        
.global str_0x8fe8d0

str_0x8fe8d0:
	.autostring 35 2 "Endlich habe ich ein Fossil gefunden!\pDie Laz.Corp in Orina City arbeitet an einem Projekt, bei dem es darum geht, Pokémon aus Fossilien zu restaurieren.\pDu solltest der Firma einen Besuch abstatten!"
        
.elseif LANG_EN

.endif
