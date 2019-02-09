.include "flags.s"
.include "songs.s"
.include "movements.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "vars.s"

.global ow_script_movs_0x8a71a0
ow_script_movs_0x8a71a0:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8a7199
ow_script_movs_0x8a7199:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a7020
ow_script_movs_0x8a7020:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x8a7006
ow_script_movs_0x8a7006:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a7003
ow_script_movs_0x8a7003:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8a69da
ow_script_movs_0x8a69da:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8a6ac4
ow_script_movs_0x8a6ac4:
.byte LOOK_LEFT
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8a685c
ow_script_0x8a685c:
lockall
playsong MUS_VIOLET_ENCOUNTER 0x0
sound 0x15
applymovement 0xff ow_script_movs_0x8a71a0
waitmovement 0x0
checksound
special 0x113
applymovement 0x7f ow_script_movs_0x8a7199
waitmovement 0x0

loadpointer 0 str_violet_grunt
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8a7134
callstd MSG
special 0xF

call ow_script_0x8a7095
loadpointer 0x0 str_0x8a70a9
callstd MSG
special 0x7

loadpointer 0 str_violet_grunt
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8a7027
callstd MSG
special 0xF

applymovement 0x7f ow_script_movs_0x8a7020
waitmovement 0x0
special 0x114
showsprite 0x52
setflag PKMNMENU
getplayerpos 0x8000 0x8001
compare 0x8001 0x37
callif HIGHER ow_script_0x8a7011
compare 0x8001 0x38
callif HIGHER ow_script_0x8a7011
compare 0x8001 0x39
callif HIGHER ow_script_0x8a7011
applymovement 0x52 ow_script_movs_0x8a7006
waitmovement 0x0
applymovement 0xff ow_script_movs_0x8a7003
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a6f8a
callstd MSG
special 0x7
sound 0x15
applymovement 0x52 ow_script_movs_0x8a71a0
waitmovement 0x0
checksound
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a6f16
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x8a69da
waitmovement 0x0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8a6bac
callstd MSG_FACE
special 0x7
sound 0x15
applymovement 0x2b ow_script_movs_0x8a6ac4
applymovement 0x2c ow_script_movs_0x8a6ac4
applymovement 0x2d ow_script_movs_0x8a6ac4
applymovement 0x2e ow_script_movs_0x8a6ac4
waitmovement 0x0
checksound
call ow_script_0x8a7095
loadpointer 0x0 str_0x8a6b82
callstd MSG
special 0x7

loadpointer 0 str_violet_grunt
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8a6bfa
callstd MSG
special 0xF

applymovement 0xff ow_script_movs_0x8a7003
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a6b0d
callstd MSG
special 0x7
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8a6ac8
callstd MSG_FACE
special 0x7
getplayerpos 0x8000 0x8001
compare 0x8001 0x37
callif EQUAL ow_script_0x8a6d2a
compare 0x8001 0x38
callif EQUAL ow_script_0x8a6d3d
compare 0x8001 0x39
callif EQUAL ow_script_0x8a6d50
compare 0x8001 0x3a
callif EQUAL ow_script_0x8a6d63
loadpointer 0 str_violet_grunt
setvar 0x8000 1
special 0xE
trainerbattlecont 0x1 0x8 0x0 str_0x8a69df str_0x8a6a97 ow_script_0x8a71a2

.global ow_script_movs_0x8a7dbc
ow_script_movs_0x8a7dbc:
.byte JUMP_RIGHT
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8a74fc
ow_script_movs_0x8a74fc:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8a74ff
ow_script_movs_0x8a74ff:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8a73a5
ow_script_movs_0x8a73a5:
.byte STEP_RIGHT
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x8a73a1
ow_script_movs_0x8a73a1:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8a71a2
ow_script_0x8a71a2:
sound 0xa
applymovement 0x2b ow_script_movs_0x8a7dbc
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8a752d
callstd MSG
sound 0xa
applymovement 0x2c ow_script_movs_0x8a7dbc
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8a7502
callstd MSG
applymovement 0x2b ow_script_movs_0x8a74fc
applymovement 0x2c ow_script_movs_0x8a74ff
waitmovement 0x0
loadpointer 0x0 str_0x8a74d8
callstd MSG
fadescreen 0x1
call ow_script_0x8a91b8
fadescreen 0x0
applymovement 0x52 ow_script_movs_0x8a73a5
applymovement 0xff ow_script_movs_0x8a73a1
waitmovement 0x0
call ow_script_0x8a7095
loadpointer 0x0 str_0x8a73a9
callstd MSG
special 0x7
setvar STORY_PROGRESS 0xe
warp 0x3 0x42 0x0 0x0 0x0
end


.global ow_script_0x8a7095
ow_script_0x8a7095:
setvar 0x8000 0x1
setvar 0x8001 0xb
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x8a91b8
ow_script_0x8a91b8:
hidesprite 0x2c
hidesprite 0x2b
hidesprite 0x2e
pause 0x60
return


.global ow_script_movs_0x8a6d84
ow_script_movs_0x8a6d84:
.byte STEP_UP
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a6d8d
ow_script_movs_0x8a6d8d:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8a6d63
ow_script_0x8a6d63:
applymovement 0xff ow_script_movs_0x8a6d84
applymovement 0x52 ow_script_movs_0x8a6d8d
waitmovement 0x0
return


.global ow_script_movs_0x8a6d7f
ow_script_movs_0x8a6d7f:
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a6d8c
ow_script_movs_0x8a6d8c:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8a6d50
ow_script_0x8a6d50:
applymovement 0xff ow_script_movs_0x8a6d7f
applymovement 0x52 ow_script_movs_0x8a6d8c
waitmovement 0x0
return


.global ow_script_movs_0x8a6d7b
ow_script_movs_0x8a6d7b:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a6d8b
ow_script_movs_0x8a6d8b:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8a6d3d
ow_script_0x8a6d3d:
applymovement 0xff ow_script_movs_0x8a6d7b
applymovement 0x52 ow_script_movs_0x8a6d8b
waitmovement 0x0
return


.global ow_script_movs_0x8a6d76
ow_script_movs_0x8a6d76:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a6d8a
ow_script_movs_0x8a6d8a:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8a6d2a
ow_script_0x8a6d2a:
applymovement 0xff ow_script_movs_0x8a6d76
applymovement 0x52 ow_script_movs_0x8a6d8a
waitmovement 0x0
return


.global ow_script_movs_0x8a701d
ow_script_movs_0x8a701d:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x8a7011
ow_script_0x8a7011:
applymovement 0x52 ow_script_movs_0x8a701d
waitmovement 0x0
return


.ifdef LANG_GER

str_violet_grunt:
	.string "Team Violet Rüpel"

.global str_0x8a7134

str_0x8a7134:
	.autostring 35 2 "Spiel hier nicht den Dummen!\pWenn du uns nicht verrätst, was wir wissen wollen, wirst du uns kennenlernen!"
        
        
.global str_0x8a70a9

str_0x8a70a9:
    .autostring 35 2 "Ich habe es euch doch schon gesagt!\pIch bin zwar ein Archäologe, aber von einem Zeistein habe ich noch nie zuvor gehört!"
        
        
.global str_0x8a7027

str_0x8a7027:
    .autostring 35 2 "Das kaufen wir dir aber nicht ab!\pDu willst es also wirklich darauf ankommen lassen?"
        
        
.global str_0x8a6f8a

str_0x8a6f8a:
    .autostring 35 2 "PLAYER!\pPerfektes Timing!\pDas Labor meines Vaters befindet sich hier und ich wollte ihm einen Besuch abstatten."
        
        
.global str_0x8a6f16

str_0x8a6f16:
    .autostring 35 2 "Was ist denn hier los?\pWer sind diese Leute und was haben Sie mit meinem Vater zu schaffen?"
        
        
.global str_0x8a6bac

str_0x8a6bac:
    .autostring 35 2 "Lasst den Professor in Ruhe!"
        
        
.global str_0x8a6b82

str_0x8a6b82:
    .autostring 35 2 "RIVAL! PLAYER!\nIhr seid meine Retter in der Not!"
        
        
.global str_0x8a6bfa

str_0x8a6bfa:
	.autostring 35 2 "Dieses Kind schon wieder!\pHast du deine Lektion noch nicht gelernt, dich nicht mit uns anzulegen?\pDu wirst noch einsehen, dass man sich nicht in Angelegenheiten einmischen sollte, die einen nichts angehen!"
        
.global str_0x8a6b0d

str_0x8a6b0d:
    .autostring 35 2 "Alles klar PLAYER!\pJeder von uns nimmt sich einen dieser Idioten vor.\pWer schneller fertig ist, bekommt den Dritten ab!"
        
        
.global str_0x8a6ac8

str_0x8a6ac8:
    .autostring 35 2 "Wir werden deinen Vater auf jeden Fall retten!"
        
        
.global str_0x8a69df

str_0x8a69df:
    .autostring 35 2 "Du Rotzlöffel!\pJetzt wirst du aufgemischt!"
.global str_0x8a6a97

str_0x8a6a97:
    .autostring 35 2 "DOTS DOTS DOTS\nDu kleiner RotzlöffelDOTS"

str_0x8a752d:
    .autostring 35 2 "Das kann doch nicht sein, dass ich von so einem Balg besiegt werde!"


.global str_0x8a7502

str_0x8a7502:
    .autostring 35 2 "Verdammt!\pDer Kleine hat mich überrumpelt!"


.global str_0x8a74d8

str_0x8a74d8:
    .autostring 35 2 "Wir sollten uns vom Acker machen!"


.global str_0x8a73a9

str_0x8a73a9:
    .autostring 35 2 "RIVAL, PLAYERDOTS\pIhr seid wirklich genau richtig gekommen.\pWer weiß, was mir diese Schergen angetan hätten, wenn ihr nicht eingeschritten wärt.\pSie haben darauf bestanden, dass ich ihnen verrate, wo man einen gewissen Zeitstein findet.\pIch wollte ihnen klar machen, dass ich von einem solchen Zeitstein noch nie etwas gehört habe, aber diese Rüpel wollten nicht hören.\pAber lasst uns das nicht hier draußen besprechen, kommt doch mit in mein Labor."
        
.elseif LANG_EN

.endif
