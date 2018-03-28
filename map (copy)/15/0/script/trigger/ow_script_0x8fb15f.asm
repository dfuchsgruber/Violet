.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fb15f
ow_script_0x8fb15f:
setvar LASTTALKED 0x36
goto ow_script_0x8d35c7


.global ow_script_movs_0x8d3ef2
ow_script_movs_0x8d3ef2:
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STOP


.global ow_script_0x8d35c7
ow_script_0x8d35c7:

lockall
sound 0x15
applymovement 0xff mov_0
waitmovement 0x0
applymovement 0xff mov_x62
waitmovement 0x0
playsong MUS_BEGEGNUNG_MIT_TRAINER_GORE 0x0
showsprite 0x32
showsprite 0x33
showsprite 0x34
showsprite 0x35
showsprite 0x36
setvar 0x8004 0x36
special 0x1B
waitmovement 0
setvar LASTTALKED 0x36
faceplayer

setflag PKMNMENU
pause 0x40
call ow_script_0x8d3f23
settrainerflag 0x19
trainerbattlecont 0x1 0x19 0x0 str_0x8d3efa str_0x8d3bb9 ow_script_0x8d4033

mov_0:
.byte 0, STOP

mov_x62:
.byte 0x62, STOP

.global ow_script_0x8d4033
ow_script_0x8d4033:
applymovement 0x32 ow_script_movs_0x8d3ef2
applymovement 0x33 ow_script_movs_0x8d3ef2
applymovement 0x34 ow_script_movs_0x8d3ef2
applymovement 0x35 ow_script_movs_0x8d3ef2
waitmovement 0x0
loadpointer 0x0 str_0x8d38fe
callstd MSG
applymovement 0x36 mov_4
call ow_script_0x8d3f23
loadpointer 0x0 str_0x8d3f8b
callstd MSG
special 0x7
applymovement 0x36 mov_1
call ow_script_0x8d3f23
loadpointer 0x0 str_0x8d3be3
callstd MSG_YES_NO
special 0x7
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8d3734
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8d3858
callstd MSG
special 0x7
call ow_script_0x8d3f23
loadpointer 0x0 str_0x8d375f
callstd MSG
special 0x7
setvar 0x8006 0xa
goto ow_script_0x8d3691

mov_4:
.byte 4, STOP

mov_1:
.byte 1, STOP

.global ow_script_movs_0x8d36f5
ow_script_movs_0x8d36f5:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8d36f1
ow_script_movs_0x8d36f1:
.byte STEP_IN_PLACE_UP
.byte STEP_IN_PLACE_UP
.byte STOP


.global ow_script_0x8d3691
ow_script_0x8d3691:
special2 0x8006 0xc
applymovement 0x36 ow_script_movs_0x8d36f5
waitmovement 0x0
call ow_script_0x8d3f23
loadpointer 0x0 str_0x8d36f8
callstd MSG
special 0x7
applymovement 0x32 ow_script_movs_0x8d36f1
applymovement 0x33 ow_script_movs_0x8d36f1
applymovement 0x34 ow_script_movs_0x8d36f1
applymovement 0x35 ow_script_movs_0x8d36f1
loadpointer 0x0 str_0x8d371c
callstd MSG
waitmovement 0x0
fadescreen 0x1
hidesprite 0x32
hidesprite 0x33
hidesprite 0x34
hidesprite 0x35
hidesprite 0x36
pause 0x20
goto ow_script_0x8d402a


.global ow_script_0x8d402a
ow_script_0x8d402a:
fadescreen 0x0
addvar STORY_PROGRESS 0x1
releaseall
end


.global ow_script_0x8d3f23
ow_script_0x8d3f23:
setvar 0x8000 0x1
setvar 0x8001 0x13
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x8d3734
ow_script_0x8d3734:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8d3aaf
callstd MSG
special 0x7
call ow_script_0x8d3f23
loadpointer 0x0 str_0x8d39ed
callstd MSG
special 0x7
setvar 0x8006 0xfff5
goto ow_script_0x8e22e1


.global ow_script_0x8e22e1
ow_script_0x8e22e1:
addvar DIFFICULTY_LEVEL_RANGE 0x1
goto ow_script_0x8d3691


.global ow_script_0x8d3f4d
ow_script_0x8d3f4d:
singlemovement 0x36 0x20
waitmovement 0x0
return


.global ow_script_0x8d3f43
ow_script_0x8d3f43:
singlemovement 0x36 0x1f
waitmovement 0x0
return


.global ow_script_0x8d3f37
ow_script_0x8d3f37:
call ow_script_0x8d3f43
call ow_script_0x8d3f43
return

.global str_0x8d3efa

str_0x8d3efa:
    .string "Polizist: Hey du da!\nStehen geblieben!"
        
        
.global str_0x8d3bb9

str_0x8d3bb9:
    .string "Argh! Ihr verdammten Team Violet\nRüpel!"
        
        
.global str_0x8d38fe

str_0x8d38fe:
    .string "Polizisten: Herr Wachtmeister!\nWir stehen Ihnen zur Seite!"
        
        
.global str_0x8d3f8b

str_0x8d3f8b:
    .string "Polizist: Nicht nötig, Männer. Ich\nhabe die Situation im Griff."
        
        
.global str_0x8d3be3

str_0x8d3be3:
    .string "Polizist: ... ... ... ...\n... ... ... ... ... ...\pNein, du siehst nicht aus, wie\neiner von denen. Du bist kein\lMitglied von Team Violet.\lEntschuldige bitte, Junge. Mein\lName ist Oberwachtmeister\lHarrenfeld, ich kommandiere die\lPolizei in diesem Bezirk Thetos.\pWir haben Informationen erhalten,\ndass eine ganze Division der\lOrganisation Team Violet auf den\lWeg nach Silvania ist.\p... ... ...\n.... .... ....\pNun, wir haben alle verfügbaren\nKräfte angefordert, aber ich bin\lmir nicht sicher, ob wir es mit\leiner ganzen Division aufnehmen\lkönnen. Sollte einer der drei\lKommandanten die Gruppe\leskortieren, könnte das Probleme\lbedeuten.\p... ... ...\n... ... ...\pNun, du machst den Eindruck, ein\nganz passabler Trainer zu sein.\lKönntest du uns nicht helfen, Team\lViolet zu bekämpfen?"
        
        
.global str_0x8d3858

str_0x8d3858:
    .string "Team Violet ist auch mein Feind.\pSie haben den Vater meines besten\nFreundes bedroht und werden dafür\lbezahlen. Sie können auf meine\lHilfe zählen, Herr Wachtmeister!"
        
        
.global str_0x8d375f

str_0x8d375f:
    .string "Wachtmeister  Ha!\pSehr schön, du bist ein\nausgesprochen herzlicher Mensch.\pIm Kampf gegen diese\nVerbrecherbande können wir jede\lUnterstützung gebrauchen.\pWir werden uns auf den Weg nach\nSilvania machen, wo du dann zu uns\lstoßen kannst."
        
        
.global str_0x8d36f8

str_0x8d36f8:
    .string "Wir ziehen ab! Auf nach Silvania!"
        
        
.global str_0x8d371c

str_0x8d371c:
    .string "Polizisten: Aye, Sir!"
        
        
.global str_0x8d3aaf

str_0x8d3aaf:
    .string "Nein, ich werde nicht Ihre Arbeit\nerldigen. Sie sind Wachtmeister\ldieses Bezirks und verpflichtet,\lfür Ordnung zu sorgen.\pIch habe selbst Angelegenheiten\nmit Team Violet zu regeln und\lwerde Ihnen daher nicht im Weg\lstehen. Rechnen dürfen Sie mit mir\ljedoch nicht."
        
        
.global str_0x8d39ed

str_0x8d39ed:
    .string "Wachmeister  Hmpf!\pDu scheinst keinen Funken Anstand\nzu besitzen. Wie dem auch sei, wir\lsind auf deine Hilfe nicht\langewiesen. Wir werden der Team\lViolet Division Einhalt gebieten."
        
        