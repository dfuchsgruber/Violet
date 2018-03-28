.include "flags.s"
.include "songs.s"
.include "movements.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"


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
playsong MUS_ROCKET_HQ_AND_AZURIA_HOHLE_AND_TOP_4_BRUNO 0x0
sound 0x15
applymovement 0xff ow_script_movs_0x8a71a0
waitmovement 0x0
checksound
special 0x113
applymovement 0x7f ow_script_movs_0x8a7199
waitmovement 0x0
loadpointer 0x0 str_0x8a7134
callstd MSG
call ow_script_0x8a7095
loadpointer 0x0 str_0x8a70a9
callstd MSG
special 0x7
loadpointer 0x0 str_0x8a7027
callstd MSG
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
loadpointer 0x0 str_0x8a6bfa
callstd MSG
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
goto ow_script_0x8fbc26


.global ow_script_0x8fbc26
ow_script_0x8fbc26:
getplayerpos 0x8000 0x8001
compare 0x8001 0x37
callif EQUAL ow_script_0x8a6d2a
compare 0x8001 0x38
callif EQUAL ow_script_0x8a6d3d
compare 0x8001 0x39
callif EQUAL ow_script_0x8a6d50
compare 0x8001 0x3a
callif EQUAL ow_script_0x8a6d63
goto ow_script_0x8d42de


.global ow_script_0x8d42de
ow_script_0x8d42de:
trainerbattlecont 0x1 0x8 0x0 str_0x8a69df str_0x8a6a97 ow_script_0x8a71a2


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
.global str_0x8a7134

str_0x8a7134:
    .string "Team Violet Rüpel: Wenn du uns\nnicht sagst, was wir wissen\lwollen, dann wirst du uns\lkennenlernen!"
        
        
.global str_0x8a70a9

str_0x8a70a9:
    .string "Professor  Ich habe doch\nschon mehrfach betont, dass ich\lnichts über einen Zeitstein\lweiß. Ich bin lediglich ein\lArcheologe..."
        
        
.global str_0x8a7027

str_0x8a7027:
    .string "Team Violet Rüpel: Das kaufen wir\ndir aber nicht ab! Los jetzt! Du\lweißt sicherlich, wo er vergraben\lliegt!"
        
        
.global str_0x8a6f8a

str_0x8a6f8a:
    .string "PLAYER! Du bist auch schon hier?\nIch habe mitbekommen, dass diese\lkomischen Leute in Violet meinem\lVater zusetzten wollen."
        
        
.global str_0x8a6f16

str_0x8a6f16:
    .string "Oh nein, diese Leute sind auch\nschon hier! Wir müssen diesen\lVerbrechern das Handwerk legen.\lLos beeilen wir uns!"
        
        
.global str_0x8a6bac

str_0x8a6bac:
    .string "Hey, ihr da, von Team Violet! Hört\nsofort auf, den Professor zu\lbelästigen!"
        
        
.global str_0x8a6b82

str_0x8a6b82:
    .string "RIVAL! PLAYER!\nArceus sei Dank, seid ihr hier!"
        
        
.global str_0x8a6bfa

str_0x8a6bfa:
    .string "Team Violet Rüpel: Hey, das ist\nder Junge, der mich auf dem Weg\lhierher besiegt hat!\lTeam Violet Rüpel: Ja, mich hat er\lauch geschlagen...\lTeam Violet Rüpel: Dann werde ich\lwohl derjenige sein, der ihn\lbesiegt! Kommt her, ihr beiden\lRotzlöffel. Man muss euch wohl\lRespekt vor der Obrigkeit\lbeibringen!"
        
        
.global str_0x8a6b0d

str_0x8a6b0d:
    .string "PLAYER, jeder von uns schnappt\nsich einen dieser Rüpel. Wer\lzuerst gewinnt, darf den Dritten\lin die Mangel nehmen, ok?"
        
        
.global str_0x8a6ac8

str_0x8a6ac8:
    .string "Abgemacht, RIVAL!\nWir müssen deinen Vater vor diesen\lSchurken retten!"
        
        
.global str_0x8a69df

str_0x8a69df:
    .string "Was meine beiden Kollegen nicht\nauf die Reihe gebracht haben,\lwerde ich nun schaffen. Wenn wir\lerst den Zeitstein in unserer\lGewalt haben, wird die Welt vor\lunserer Macht erzittern!"
        
        
.global str_0x8a6a97

str_0x8a6a97:
    .string "Du bist in der Tat ein zähes\nBürschchen..."
        
        
.elseif LANG_EN

.endif
