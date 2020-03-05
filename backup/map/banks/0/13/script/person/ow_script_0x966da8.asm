.include "flags.s"
.include "songs.s"
.include "movements.s"
.include "callstds.s"
.include "species.s"
.include "vars.s"
.include "overworld_script.s"
.include "story_states.s"
.include "mugshot.s"


.global ow_script_movs_0x96aa3b
ow_script_movs_0x96aa3b:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x969d17
ow_script_movs_0x969d17:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x969d10
ow_script_movs_0x969d10:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x969a0d
ow_script_movs_0x969a0d:
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STOP


.global ow_script_0x966da8
ow_script_0x966da8:
special 0x113
applymovement 0x7f ow_script_movs_0x96aa3b
waitmovement 0x0
playsong MUS_MISTRAL 0x0
loadpointer 0x0 str_0x969e0b
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
pause 0x1
loadpointer 0x0 str_0x96a758
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
pause 0x1
loadpointer 0x0 str_0x96a8cd
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
pause 0x1
loadpointer 0x0 str_0x969d1d
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
pause 0x1
applymovement 0x7f ow_script_movs_0x969d17
waitmovement 0x0
special 0x114
applymovement 0xff ow_script_movs_0x969d10
waitmovement 0x0
loadpointer 0x0 str_0x969a22
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
pause 0x1
special 0x113
applymovement 0x7f ow_script_movs_0x969a0d
waitmovement 0x0
special 0x114
setvar 0x8004 0x5
setvar SONG_OVERRIDE 0x16b
special 0x19
waitstate
pause 0x1
goto ow_script_0x96aa40


.global ow_script_movs_0x966e6b
ow_script_movs_0x966e6b:
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STOP


.global ow_script_0x96aa40
ow_script_0x96aa40:
special 0x113
applymovement 0x7f ow_script_movs_0x966e6b
waitmovement 0x0
special 0x114
goto ow_script_0x96acf2


.global ow_script_movs_0x96ace1
ow_script_movs_0x96ace1:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x96acdb
ow_script_movs_0x96acdb:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x96acde
ow_script_movs_0x96acde:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x96aba6
ow_script_movs_0x96aba6:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x96abad
ow_script_movs_0x96abad:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x96acf2
ow_script_0x96acf2:
loadpointer 0x0 str_0x96eab0
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
applymovement 0x2 ow_script_movs_0x96ace1
waitmovement 0x0
applymovement 0xff ow_script_movs_0x96acdb
applymovement 0x1 ow_script_movs_0x96acde
waitmovement 0x0
loadpointer 0x0 str_0x96abb4
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
applymovement 0xff ow_script_movs_0x96aba6
applymovement 0x1 ow_script_movs_0x96abad
waitmovement 0x0
settrainerflag 0xb0
setvar LASTTALKED 0x3
trainerbattlecont 0x1 0xb0 0x0 str_0x96ab03 str_0x96ab6d ow_script_0x96ae42


.global ow_script_0x96ae42
ow_script_0x96ae42:
applymovement 0xff ow_script_movs_0x96aba6
applymovement 0x1 ow_script_movs_0x96abad
waitmovement 0x0
settrainerflag 0xb1
setvar LASTTALKED 0x7
trainerbattlecont 0x1 0xb1 0x0 str_0x96aa55 str_0x96aac6 ow_script_0x96eb83


.global ow_script_0x96eb83
ow_script_0x96eb83:
applymovement 0xff ow_script_movs_0x96aba6
applymovement 0x1 ow_script_movs_0x96abad
waitmovement 0x0
settrainerflag 0xb2
setvar LASTTALKED 0x5
trainerbattlecont 0x1 0xb2 0x0 str_0x96a618 str_0x969f24 ow_script_0x969e71


.global ow_script_movs_0x96ebaf
ow_script_movs_0x96ebaf:
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x96aeaa
ow_script_movs_0x96aeaa:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x96ada3
ow_script_movs_0x96ada3:
.byte LOOK_UP
.byte STOP


.global ow_script_0x969e71
ow_script_0x969e71:
applymovement 0x1 ow_script_movs_0x96ebaf
applymovement 0xff ow_script_movs_0x96ebaf
waitmovement 0x0
applymovement 0x2 ow_script_movs_0x96aeaa
waitmovement 0x0
loadpointer 0x0 str_0x96ae6e
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
loadpointer 0x0 str_0x96adf1
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
loadpointer 0x0 str_0x96ada6
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
applymovement 0x2 ow_script_movs_0x96ada3
waitmovement 0x0
fadesong 0
sound 0x16
hidesprite 0x9
checksound
pause 0x40
call ow_script_0x96ebb2
loadpointer 0x0 str_0x96ad59
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
call ow_script_0x8d7a10
loadpointer 0x0 str_0x96a698
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
goto ow_script_0x96ebc4


.global ow_script_movs_0x96aeac
ow_script_movs_0x96aeac:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_0x96ebc4
ow_script_0x96ebc4:
setvar 0x8004 0x2
special 0x19
waitstate
special 0x113
applymovement 0x7f ow_script_movs_0x96aeac
waitmovement 0x0
special 0x114
playsong MUS_MERWURDIGE_UND_UNBEKANNTE_MUSIK 0x0
setvar SONG_OVERRIDE 0x149
setvar 0x8004 0x6
setflag TRANS_DISABLE
special 0x19
clearflag INFERIOR_VIOLET_GRUNTS | 0x8000
waitstate
showsprite 0xa
goto ow_script_0x979e62


.global ow_script_0x979e62
ow_script_0x979e62:
movesprite2 0x1 0x11 0xe
clearflag TRANS_DISABLE
clearflag INFERIOR_VIOLET_GRUNTS
pause 0x40
loadpointer 0x0 str_0x96ebfd
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
special 0x113
call ow_script_0x96b124
call ow_script_0x96b124
call ow_script_0x96b124
call ow_script_0x96b124
call ow_script_0x96b124
call ow_script_0x96b124
call ow_script_0x96b124
cry POKEMON_GROUDON 0x1
waitcry
loadpointer 0x0 str_0x96b05d
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
setvar LASTRESULT 0x1
sound 0xd1
setanimation 0x0 0x10
setanimation 0x1 0x2a
setanimation 0x2 0x0
doanimation 0x36
checkanimation 0x36
goto ow_script_0x96ecbf


.global ow_script_0x96ecbf
ow_script_0x96ecbf:
setvar 0x8004 0x7
special 0x19
waitstate
hidesprite 0xa
waitstate
goto ow_script_0x96f088


.global ow_script_movs_0x96f408
ow_script_movs_0x96f408:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x96f1b9
ow_script_movs_0x96f1b9:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x96f1b6
ow_script_movs_0x96f1b6:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x96f088
ow_script_0x96f088:
loadpointer 0x0 str_0x97138c
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
applymovement 0x2 ow_script_movs_0x96f408
waitmovement 0x0
loadpointer 0x0 str_0x96f1be
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
applymovement 0x7f ow_script_movs_0x96f1b9
waitmovement 0x0
special 0x114
applymovement 0x2 ow_script_movs_0x96f1b6
waitmovement 0x0
setvar LASTTALKED 0x2
setvar BATTLE_SONG_OVERRIDE 0x16f
goto ow_script_0x971404


.global ow_script_0x971404
ow_script_0x971404:
special 0x114
setvar SONG_OVERRIDE 0xffff
draw_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
trainerbattlecont 0x1 0xaa 0x0 str_0x96f0ee str_0x96f156 ow_script_0x96fbaa


.global ow_script_movs_0x96fba6
ow_script_movs_0x96fba6:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x9718b4
ow_script_movs_0x9718b4:
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x972fcd
ow_script_movs_0x972fcd:
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_RIGHT_FAST
.byte STEP_DOWN_FAST
.byte HIDE_SPRITE
.byte STOP


.global ow_script_movs_0x972fe0
ow_script_movs_0x972fe0:
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_LEFT_FAST
.byte STEP_DOWN_FAST
.byte HIDE_SPRITE
.byte STOP


.global ow_script_0x96fbaa
ow_script_0x96fbaa:
loadpointer 0x0 str_0x9713b5
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
call ow_script_0x8d7a10
fadescreen 0x3
cry POKEMON_GROUDON 0x0
clearflag INFERIOR_VIOLET_GRUNTS | 0x8000
movesprite2 0xa 0x10 0xc
showsprite 0xa
pause 0x1
fadescreen 0x2
playsong MUS_SPIELHALLE_VERSION_3 0x0
sound 0x15
applymovement 0xff ow_script_movs_0x96fba6
applymovement 0x1 ow_script_movs_0x96fba6
applymovement 0x2 ow_script_movs_0x96fba6
call ow_script_0x972ff2
loadpointer 0x0 str_0x96fd16
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
pause 0x1
call ow_script_0x972ff2
loadpointer 0x0 str_0x96fd4a
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
pause 0x1
call ow_script_0x9718a4
applymovement 0x1 ow_script_movs_0x9718b4
applymovement 0x2 ow_script_movs_0x9718b4
hidesprite 0x3
hidesprite 0x4
applymovement 0x5 ow_script_movs_0x972fcd
hidesprite 0x6
hidesprite 0x7
applymovement 0x8 ow_script_movs_0x972fe0
applymovement 0xff ow_script_movs_0x9718b4
call ow_script_0x972ff2
goto ow_script_0x279768


.global ow_script_0x279768
ow_script_0x279768:
call ow_script_0x972ff2
loadpointer 0x0 str_0x96fc90
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
pause 0x1
setvar 0x8004 0x8
special 0x19
waitstate
goto ow_script_0x97305b


.global ow_script_movs_0x971dd2
ow_script_movs_0x971dd2:
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x9730a0
ow_script_movs_0x9730a0:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_0x97305b
ow_script_0x97305b:
movesprite2 0xa 0x10 0x14
showsprite 0xa
call ow_script_0x972ff2
applymovement 0xa ow_script_movs_0x971dd2
pause 0x10
cry POKEMON_GROUDON 0x0
waitcry
loadpointer 0x0 str_0x97300a
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
cry POKEMON_GROUDON 0x0
call ow_script_0x972ff2
applymovement 0xa ow_script_movs_0x9730a0
goto ow_script_0x971dd7


.global ow_script_0x971dd7
ow_script_0x971dd7:
loadpointer 0x0 str_0x972330
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
cry POKEMON_GROUDON 0x0
call ow_script_0x972ff2
waitcry
pause 0x20
fadesong 0
setvar 0x8004 0x9
special 0x19
waitstate
loadpointer 0x0 str_0x972313
show_mugshot MUGSHOT_RUBYS MUGSHOT_LEFT
goto ow_script_0x9730a3


.global ow_script_0x9730a3
ow_script_0x9730a3:
setvar STORY_STATE STORY_STATE_VULCANO_CLEAR
sound 0x64
checksound
setvar 0x8004 0xa
special 0x19
addvar STORY_PROGRESS 0x1
waitstate
goto ow_script_0x966e64


.global ow_script_0x966e64
ow_script_0x966e64:
end


.global ow_script_0x972ff2
ow_script_0x972ff2:
setvar 0x8004 0x4
setvar 0x8005 0x5
setvar 0x8006 0x14
setvar 0x8007 0x4
special 0x136
return


.global ow_script_movs_0x96b13c
ow_script_movs_0x96b13c:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x9718a4
ow_script_0x9718a4:
call ow_script_0x972ff2
applymovement 0xa ow_script_movs_0x96b13c
return


.global ow_script_0x96b124
ow_script_0x96b124:
applymovement 0x7f ow_script_movs_0x96b13c
applymovement 0xa ow_script_movs_0x96b13c
call ow_script_0x8d7a10
pause 0x10
return


.global ow_script_0x96ebb2
ow_script_0x96ebb2:
sound 0x21
setvar 0x8004 0x1
special 0x19
waitstate
call ow_script_0x8d7a10
return


.ifdef LANG_GER
.global str_0x969e0b

str_0x969e0b:
    .autostring 35 2 "Mistral!\nWas hast du vor?\pWeißt du denn, was du hier tust?"
        
        
.global str_0x96a758

str_0x96a758:
	.autostring 35 2 "Igva!\nMit dir hätte ich in tausend Jahren nicht gerechnet.\pBist du immernoch Mitglied bei diesen schwachsinningen Schwärmern von Revolutionären?\pEine Welt, in der Gerechtigkeit die oberste Maxime sein soll DOTS\pDOTS was für ein naiver Unfug DOTS"

.global str_0x96a8cd

str_0x96a8cd:
	.autostring 35 2 "Unsere Bemühungen sind sicherlich kein Unfug!\pMit jemandem wie Albus an unserer Seite, wird es uns gelingen, die Welt zu einem besseren Ort zu machen.\pDu hast uns DOTS\nDOTS du hast mich im Stich gelassen, Mistral!\pUnd wofür?\nWas willst du mit diesen Verbrechern von Team Violet?\pIst dir bewusst, welche Ziele sie verfolgen?"

        
.global str_0x969d1d

str_0x969d1d:
	.autostring 35 2 "Ach Igva, ich vergesse immer wieder wie einfältig du doch bist!\pWeißt du nicht, dass meine eigenen Ziele für mich stets im Vordergrund stehen?\pTeam Violet bietet mir eine Möglichkeit, endlich die Macht der legendären Pokémon für mich nutzen zu können.\pDOTS DOTS DOTS\pSieh nur, Igva.\nDein neuer Begleiter ist eingetroffen!"
        
        
.global str_0x969a22

str_0x969a22:
	.autostring 35 2 "Willkommen, PLAYER!\pIch habe dich erwartet!\pDass du hier mit meiner ehemaligen Partnerin eintriffst, hat mich aber überrascht.\pPass nur auf, das Mädchen wird schnell anhänglich.\pDu fragst dich sicherlich, warum ich meine gesamte Divison hierher gebracht habe, nicht?\pDu musst wissen, dass Team Violet hinter einem Artefakt namens Diserakt her ist.\pUrsprünglich sollte das Pokémon Celebi diesen Stein, in dem das Herz der Zeit schlägt, bewachen.\pAllerdings DOTS DOTS DOTS\pDOTS hat es diese Aufgabe in weiser Voraussicht weitaus stärkeren Wächtern anvertraut.\pDer Stein ist nun in drei Teile gespalten, und einer von ihnen befindet sich direkt hier, im Krater des Vulcanos."

        
.global str_0x96eab0

str_0x96eab0:
	.autostring 35 2 "Er ist wunderschön, nicht wahr?\pTeam Violet will die grenzenlose Energie, die der Stein liefern kann, verwenden, um eine vernichtende Waffe zu kreieren.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDoch wenn ich ehrlich sein soll DOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pHabe ich daran kein Interesse.\pMich interessiert das Wesen, welches den Zeitstein bewacht!"
        
        
.global str_0x96abb4

str_0x96abb4:
    .autostring 35 2 "PLAYER!\nWir dürfen das nicht geschehen lassen.\pDas Pokémon, das an diesem Ort schlummert DOTS\pEs ist eine grauenvolle Bestie.\pWenn Mistral sie erzürnt, befinden wir uns alle in höchster Gefahr!"
        
        
.global str_0x96ab03

str_0x96ab03:
    .autostring 35 2 "Mistral ist nicht aufzuhalten.\pDas Fragment des Zeitsteins wird uns zu den Herrschern der Welt\lerheben!"
        
        
.global str_0x96ab6d

str_0x96ab6d:
    .autostring 35 2 "Du kommst viel zu spät, um uns nun noch zu stoppen."
        
        
.global str_0x96aa55

str_0x96aa55:
    .autostring 35 2 "Mistral wird das vollenden, was Rin nicht gelungen ist.\pEr wird alle Teile des Diserakts vereinen und Team Violet wird aufsteigen!"
        
        
.global str_0x96aac6

str_0x96aac6:
    .autostring 35 2 "Stell dich ihm nicht in den Weg, Kindchen, wenn du an deinem Leben hängst."
        
        
.global str_0x96a618

str_0x96a618:
	.autostring 35 2 "Bis hierher und nicht weiter!\pHier ist das Ende der Fahnenstange, du Rotznase!\pIch werde nicht erlauben, in Mistrals Pläne einzugreifen."

        
.global str_0x969f24

str_0x969f24:
    .autostring 35 2 "Unmöglich!\nDu darfst Mistral nicht stoppen!"
        
        
.global str_0x96ae6e

str_0x96ae6e:
	.autostring 35 2 "Ihr kommt zu spät!\pDer Diserakt DOTS DOTS DOTS\nDOTS DOTS DOTS\pDOTS gehört nun mir!"
        
        
.global str_0x96adf1

str_0x96adf1:
    .autostring 35 2 "Mistral, bitte!\pWenn ich dir je auch nur irgendetwas bedeutet habe, dann hör jetzt auf!\pEs ist noch nicht zu spät!\pMerkst du denn nicht, dass du von Machtsucht völlig zerfressen bist?"
        
        
.global str_0x96ada6

str_0x96ada6:
    .autostring 35 2 "Du dummes Mädchen, halt endlich deinen Mund!\pDeine herzerwärmenden Ansprachen werden mich nicht von meinem Vorhaben abbringen."
        
        
.global str_0x96ad59

str_0x96ad59:
    .autostring 35 2 "Oh nein, der Wächter\nDOTS DOTS DOTS"
        
        
.global str_0x96a698

str_0x96a698:
    .autostring 35 2 "DOTS DOTS DOTS ist endlich aus seinem Schlaf erwacht!"
        
        
.global str_0x96ebfd

str_0x96ebfd:
    .autostring 35 2 "Das ist unser Ende!\pDas Monster wird jeden von uns vernichten DOTS"
        
        
.global str_0x96b05d

str_0x96b05d:
	.autostring 35 2 "Komm her, Groudon!\pIch habe keine Angst vor dir!\pKomm zu mir, deinem neuen Gebieter!\pIch bin der Besitzer deiner Seele, des Magmeherzes!\pIch werde deine uralte Kraft erneut entfesseln!"
        
.global str_0x97138c

str_0x97138c:
    .autostring 35 2 "Es DOTS DOTS DOTS\nDOTS DOTS DOTS\pDOTS ist verschwunden?"
        
        
.global str_0x96f1be

str_0x96f1be:
	.autostring 35 2 "Dummes Mädchen!\nHast du es nicht begriffen?\pDuch das Magmaherz, das ich aus dem Museum von Orina City gestohlen habe, habe ich nun die Kontrolle über das legendäre Pokémon Groudon.\pUnd da es nun wieder mit seinem Herzen vereint ist, wird es sich in seine eigentliche Kaiserform erheben!\pHahaha!\nHahaha! Haha!\pIch bin unbesiegbar!\pIch werde alles und jeden verbrennen, der sich mir in den Weg stellt.\pDie Welt wird einen Terror erleben, wie es ihn bislang noch nie gegeben hat!\pHahaha!\nHahaha!\pAlso!\pPLAYER!\pEs ist nun endlich an der Zeit, dich herauszufordern!"
        
.global str_0x96f0ee

str_0x96f0ee:
    .autostring 35 2 "Betrachte es als Ehre, mein erstes Opfer zu werden.\pHahaha!\nHahaha!\pIch werde dich vernichten, PLAYER!\pSchreie! Schreie!\pBrenne!"
        
        
.global str_0x96f156

str_0x96f156:
	.autostring 35 2 "DOTS Das ist vollkommen DOTS absurd!\pDu hast DOTS DOTS DOTS\pDu hast Groudon besiegt?\nIn seiner Kaiserform?"
        
        
.global str_0x9713b5

str_0x9713b5:
    .string "DOTS\nDOTS DOTS DOTS DOTS\pDas DOTS ist DOTS\nDOTS\pDOTS du hast Groudon besiegt?"
        
        
.global str_0x96fd16

str_0x96fd16:
    .autostring 35 2 "Wie kann das sein?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pGroudon entzieht sich meiner Kontrolle?"
        
        
.global str_0x96fd4a

str_0x96fd4a:
    .autostring 35 2 "Unmöglich!\pEs wird alles in Schutt und Asche legen!\pWir müssen von hier weg!"
        
        
.global str_0x96fc90

str_0x96fc90:
    .autostring 35 2 "Wir werden es niemals rechtzeitig schaffen.\pDieser Ort wird unser Grab!\pWir werden lebendig verbrennen!"
        
        
.global str_0x97300a

str_0x97300a:
    .autostring 35 2 "Ich verstehe nicht DOTS\pWieso DOTS DOTS DOTS\pIch darf noch nicht sterben!"
        
        
.global str_0x972330

str_0x972330:
    .autostring 35 2 "Das ist das Ende!"
        
        
.global str_0x972313

str_0x972313:
    .autostring 35 2 "Nein."
        
        
.elseif LANG_EN

.endif
