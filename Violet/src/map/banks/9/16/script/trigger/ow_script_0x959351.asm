.include "flags.s"
.include "songs.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "overworld_script.s"


.global ow_script_movs_0x959dfe
ow_script_movs_0x959dfe:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x959a08
ow_script_movs_0x959a08:
.byte LOOK_UP
.byte STOP


.global ow_script_0x959351
ow_script_0x959351:
lockall
fadesong 0
call ow_script_0x936c1c
loadpointer 0x0 str_0x959e02
callstd MSG
special 0x7
sound 0x15
applymovement 0xff ow_script_movs_0x959dfe
waitmovement 0x0
checksound
clearflag PKMNMENU
showsprite 0xd
showsprite 0xe
setflag PKMNMENU
setvar 0x8004 0xd
special 0x1b
setvar 0x8004 0xe
setvar 0x8005 0x9
setvar 0x8006 0x8
special 0x24
waitmovement 0x0
applymovement 0xd ow_script_movs_0x959a08
applymovement 0xe ow_script_movs_0x959a08
waitmovement 0x0
playsong MUS_MISTRAL 0x0
call ow_script_0x936c1c
loadpointer 0x0 str_0x959af2
callstd MSG
special 0x7
setvar 0x8004 0xd
setvar 0x8005 0x9
setvar 0x8006 0x4
special 0x24
waitmovement 0x0
applymovement 0xd ow_script_movs_0x959a08
waitmovement 0x0
setvar 0x8004 0xe
special 0x1b
waitmovement 0x0
setvar LASTTALKED 0xe
trainerbattlecont 0x1 0x91 0x0 str_0x959a4a str_0x959abd ow_script_0x959e29


.global ow_script_movs_0x959a0b
ow_script_movs_0x959a0b:
.byte FACE_DOWN
.byte STOP


.global ow_script_0x959e29
ow_script_0x959e29:
playsong MUS_MISTRAL 0x0
loadpointer 0x0 str_0x959a0e
callstd MSG
applymovement 0xff ow_script_movs_0x959a08
applymovement 0xd ow_script_movs_0x959a0b
waitmovement 0x0
call ow_script_0x936c1c
loadpointer 0x0 str_0x9599ae
callstd MSG
special 0x7
applymovement 0xd ow_script_movs_0x959a08
waitmovement 0x0
sound 0x14
setmaptile 0x9 0x2 0x2d2 0x1
setmaptile 0xa 0x2 0x2d3 0x1
setmaptile 0x9 0x3 0x2da 0x1
setmaptile 0xa 0x3 0x2db 0x1
special 0x8e
pause 0x1c
call ow_script_0x936c1c
loadpointer 0x0 str_0x959981
callstd MSG
special 0x7
setvar 0x8004 0xd
special 0x1b
waitmovement 0x0
faceplayer
call ow_script_0x936c1c
loadpointer 0x0 str_0x959853
callstd MSG
special 0x7
fadescreen 0x1
hidesprite 0xd
hidesprite 0xe
hidesprite 0x9
hidesprite 0xa
hidesprite 0xb
hidesprite 0xc
applymovement 0xff ow_script_movs_0x959a0b
waitmovement 0x0
fadesong MUS_AZURIA_CITY_AND_FEUERHOHLE_AND_FUCHSANIA_CITY
fadescreen 0x0
clearflag PKMNMENU
showsprite 0xf
setvar 0x8004 0xf
special 0x1b
waitmovement 0x0
faceplayer

loadpointer 0 str_director
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x9595b1
callstd MSG_KEEPOPEN
special 0xF


fanfare 0x13e
loadpointer 0x0 str_0x95957f
callstd MSG_KEEPOPEN
waitfanfare

loadpointer 0 str_director
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x9594d2
callstd MSG
special 0xF
setflag PKMNMENU
setflag ORINA_CITY_VIOLET_GRUNTS
addvar STORY_PROGRESS 0x1
warpmuted 0x3 0x5 0x2 0x0 0x0
waitstate
releaseall
end


.ifdef LANG_GER
.global str_0x959e02

str_0x959e02:
	.autostring 35 2 "Halt, keinen Schritt weiter!"
        
        
.global str_0x959af2

str_0x959af2:
	.autostring 35 2 "Hallo, PLAYER.\pWie überaus unglücklich, dass wir uns an diesem Ort wieder begegnen.\pJa, ich bin ein Kommandant von Team Violet.\pAlso bist du mein Feind.\pUnd dennoch DOTS DOTS DOTS\pWerde ich nicht gegen dich kämpfen.\pNoch nicht zumindest.\nDas Magmaherz, welches in dieser Vitrine hier nur verstaubt, wird mir die Macht geben, die ich benötige, um jeden besiegen zu können.\pEhe ich diese Macht aber besitze DOTS\pDOTS wirst du es mit meinen Untergeben aufnehmen müssen.\pAllerdings wirst du überrascht sein, wie mächtig die Mitglieder meiner Division sind."


        
.global str_0x959a4a

str_0x959a4a:
    .autostring 35 2 "Du magst es zwar bisher mit ein paar Rüpeln aufgenommen haben.\pDer Elite von Team Violet bist du allerdings nicht gewachsen."
        
        
.global str_0x959abd

str_0x959abd:
    .autostring 35 2 "Argh!\nIch habe gegen ein Kind verloren.\pWas für eine Schande!"
        
        
.global str_0x959a0e

str_0x959a0e:
    .autostring 35 2 "Mistral, vergebt mir.\pIch konnte das Kind nicht aufhalten DOTS"
        
        
.global str_0x9599ae

str_0x9599ae:
	.autostring 35 2 "Das ist auch gar nicht nötig.\pDu hast mir genügend Zeit verschafft."
        
        
.global str_0x959981

str_0x959981:
    .autostring 35 2 "Endlich!\nDas Magmaherz gehört nun mir DOTS"
        
        
.global str_0x959853

str_0x959853:
	.autostring 35 2 "Überaus schade, dass du das Magmaherz nicht beschützen konntest.\pAber gegen mich zu gewinnen, ist ein Ding der Unmöglichkeit.\pIch setze immer meinen Willen durch.\pTrotzdem will ich dir einen kleinen Sieg lassen DOTS\pIch werde das Museum unversehrt lassen.\pImmerhin konntest du einen Elitekämpfer aus meiner Division schlagen DOTS\pAllerdings DOTS\nDOTS werde ich dir bei unserer nächsten Begegnung mit ganzer Macht gegenübertreten."
        
.global str_0x9595b1

str_director:
	.string "Direktor"

str_0x9595b1:
	.autostring 35 2 "Meine Güte!\nIch hatte Todesangst!\pEin Kommandant von Team Violet DOTS\pDOTS in meinem Museum!\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pVerzeih bitte, ich habe mich noch nicht vorgestellt.\pIch bin der Direktor des Museums und stehe wohl tief in deiner Schuld.\pDas Magmaherz wurde zwar entwendet, aber sonst scheint dem Museum nichts weiter geschehen zu sein.\pTausendfachen Dank!\nWie kann ich mich nur erkenntlich zeigen?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pOh, ich weiß!\nDu bist ein Trainer, nicht wahr?\pSeit einiger Zeit arbeiten wir mit der Laz.Corp an der Restauration ausgestorbener Pokémon durch Fossilien.\pIch werde deine Zugangsberechtigungen entsprechend erweitern, sodass du deine Fossilien dort wiederherstellen lassen kannst."

.global str_0x95957f

str_0x95957f:
    .autostring 35 2 "PLAYER wurde der Zugang zum\nFossilienlabor gewährt!"
        
        
.global str_0x9594d2

str_0x9594d2:
    .autostring 35 2 "Es ist natürlich ein schwerer Schlag, dass wir das Magmaherz verloren haben.\pNichtsdestotrotz bist du der Held des Tages!"
        
.elseif LANG_EN

.endif
