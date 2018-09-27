.include "flags.s"
.include "songs.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


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
pause 32
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

loadpointer 0 str_police
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8d38fe
callstd MSG
special 0xF

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
loadpointer 0 str_police
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8d371c
callstd MSG
special 0xF
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


.ifdef LANG_GER
.global str_0x8d3efa

str_0x8d3efa:
    .autostring 35 2 "Halt!\nStehengeblieben!"
        
        
.global str_0x8d3bb9

str_0x8d3bb9:
    .autostring 35 2 "Argh!\nIhr verdammten Team Violet Rüpel!"
        
str_police:
	.string "Polizisten"

        
.global str_0x8d38fe

str_0x8d38fe:
    .autostring 36 2 "Herr Wachtmeister!\pKommen Sie zurecht?"
        
        
.global str_0x8d3f8b

str_0x8d3f8b:
    .autostring 36 2 "Argh!\nDieser Team Violet Rüpel hier ist hartnäckig!"
        
        
.global str_0x8d3be3

str_0x8d3be3:
	.autostring 36 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pHmm DOTS\nDu siehst bei genauerer Betrachtung gar nicht aus, wie ein Mitglied von Team Violet.\pEntschuldige bitte, ich habe dich wohl verwechselt, Kindchen.\pMein Name ist Wachtmeister Harrenfeld und ich bin auf der Jagd nach einer Kommandantin von Team Violet.\pWir haben Informationen erhalten, dass sie mit ihrer Division auf dem Weg nach Silvania ist.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWenn wir sie dingfest machen können, finden wir vielleicht etwas über den Kopf der Organisation heraus DOTS\pUnd da du ein ganz passabler Trainer zu sein scheinst DOTS DOTS DOTS\pWas meinst du?\nWürdest du uns vielleicht helfen, diese Kommandantin aufzuspüren und zu bekämpfen?"
.global str_0x8d3858

str_0x8d3858:
	.autostring 36 2 "Ich bin auch schon mit diesen Rüpel aneinandergeraten.\pAlso werde ich Ihnen selbstverständlich helfen, Herr Wachtmeister!"
        
.global str_0x8d375f

str_0x8d375f:
	.autostring 36 2 "Du bist wirklich ein mutiges Kind, das muss ich dir lassen!\pTreib es aber nicht zu weit.\pSolltest du auf die Kommandantin treffen, überlasse es lieber den Erwachsenen, die Sache zu regeln!"
        
.global str_0x8d36f8

str_0x8d36f8:
    .autostring 36 2 "Wir ziehen ab!\nAuf nach Silvania!"
        
        
.global str_0x8d371c

str_0x8d371c:
    .autostring 36 2 "Ja, Sir!"
        
        
.global str_0x8d3aaf

str_0x8d3aaf:
	.autostring 36 2 "Verlangen Sie allen ernstes, dass ein Kind Ihre Arbeit erledigt und auf Verbrecherjagd geht?\pEs ist Ihre Aufgabe, für Recht und Ordnung zu sorgen, nicht meine!\pAllerdings bin ich selbst auch schon an die Rüpel von Team Violet geraten und werde mich von diesen Leuten sicherlich nicht besiegen lassen."

.global str_0x8d39ed

str_0x8d39ed:
	.autostring 36 2 "Hmpf!\nDu rotzfreches Balg!\pWas meinst du, mit wem du hier sprichst?\pWir brauchen deine Hilfe ohnehin nicht!\pKomm uns ja nicht in die Quere!\pDOTS DOTS DOTS"
        
.elseif LANG_EN

.endif
