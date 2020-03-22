.include "flags.s"
.include "songs.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "overworld_script.s"
.include "mugshot.s"


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
loadpointer 0x0 str_0x959e02
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT mask_name=1
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
pause 16
setvar 0x8004 3
special SPECIAL_CUTSCENE_SHOW
waitstate
pause 32
playsong MUS_MISTRAL 0x0
loadpointer 0x0 str_0x959af2
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
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
setvar SONG_OVERRIDE MUS_MISTRAL
trainerbattlecont 0x1 0x91 0x0 str_0x959a4a str_0x959abd ow_script_0x959e29


.global ow_script_movs_0x959a0b
ow_script_movs_0x959a0b:
.byte FACE_DOWN
.byte STOP


.global ow_script_0x959e29
ow_script_0x959e29:
setvar SONG_OVERRIDE 0
loadpointer 0x0 str_0x959a0e
callstd MSG
applymovement 0xff ow_script_movs_0x959a08
applymovement 0xd ow_script_movs_0x959a0b
waitmovement 0x0
loadpointer 0x0 str_0x9599ae
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
applymovement 0xd ow_script_movs_0x959a08
waitmovement 0x0
sound 0x14
setmaptile 0x9 0x2 0x2d2 0x1
setmaptile 0xa 0x2 0x2d3 0x1
setmaptile 0x9 0x3 0x2da 0x1
setmaptile 0xa 0x3 0x2db 0x1
special 0x8e
pause 0x1c
loadpointer 0x0 str_0x959981
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
setvar 0x8004 0xd
special 0x1b
waitmovement 0x0
faceplayer
loadpointer 0x0 str_0x959853
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
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
    .autostring 34 2 "Was für ein seltsames Gefühl!\pAls wäre unser Aufeinandertreffen vorherbestimmt.\pMein Name ist Mistral und ich bin der Kommandant der zweiten Division von Team Violet.\pDu musst wohl PLAYER sein, der Rin im Silvania-Wald besiegt hat.\pDu bist tatsächlich so faszinierend, wie ich es mir vorgestellt hatte.\pIch bin mir sicher, dass du hier bist, um zu verhindern, dass ich das Magmaherz aus diesem Museum stehle.\pAber dieses Artefakt ist nicht dafür gemacht, in einer Vitrine zu verstauben.\pEs beinhaltet eine imense Macht, die nur darauf wartet, freigesetzt zu werden.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIch würde gerne an Ort und Stelle gegen dich kämpfen, PLAYERDOTS\pAber das muss noch etwas warten!\pStattdessen darfst du mit einer meiner Elite-Truppen vorlieb nehmen.\pZeig mir, ob du hältst, was dein Ruf verspricht!"


        
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
	.autostring 34 2 "Trotz deines Sieges scheinst du nun verloren zu haben.\pIst das nicht ironisch?\pBei unserem nächsten Treffen, PLAYERDOTS\pDa werde ich dir mit aller Macht entgegentreten.\pDann bekommst du deine Chance auf Rache!"
        
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
