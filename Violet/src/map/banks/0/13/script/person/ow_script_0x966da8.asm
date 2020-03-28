.include "flags.s"
.include "songs.s"
.include "movements.s"
.include "callstds.s"
.include "species.s"
.include "vars.s"
.include "overworld_script.s"
.include "story_states.s"
.include "mugshot.s"
.include "trainer_backsprites.s"
.include "ordinals.s"
.include "battle/battle_handicaps.s"

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
    setvar SONG_OVERRIDE MUS_MISTRAL
select:
    setflag TRANS_DISABLE
    clearflag TRANS_PALETTE_FETCH
    loadpointer 0 str_select
    callstd MSG_KEEPOPEN
    special SPECIAL_SELECT_HALF_PARTY
    waitstate
    clearflag TRANS_DISABLE
    compare LASTRESULT 0
    gotoif EQUAL have_to_select
    setvar SONG_OVERRIDE 0
    applymovement 0xff ow_script_movs_0x96aba6
    applymovement 0x1 ow_script_movs_0x96abad
    waitmovement 0x0
    settrainerflag 0xb0
    setvar LASTTALKED 0x3
    setvar VAR_ALLY 0x170
    special SPECIAL_ALLY_BATTLE_SAVE_AND_SETUP_PARTY
    trainerbattleallytwotrainers 0xb0 0x171 0x170 3 TRAINER_BACKSPRITE_IGVA 1 str_0x96ab03 str_0x96ab6d str_after0 ow_script_0x96ae42

have_to_select:
    loadpointer 0 str_have_to_select
    show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
    goto select

.global ow_script_0x96ae42
ow_script_0x96ae42:
    applymovement 0xff ow_script_movs_0x96aba6
    applymovement 0x1 ow_script_movs_0x96abad
    waitmovement 0x0
    settrainerflag 0xb1
    setvar LASTTALKED 0x7
    setvar VAR_ALLY 0x170
    special SPECIAL_ALLY_BATTLE_SAVE_AND_SETUP_PARTY
    trainerbattleallytwotrainers 0xb1 0x172 0x170 7 TRAINER_BACKSPRITE_IGVA 0 str_0x96aa55 str_0x96aac6 str_after1 ow_script_0x96eb83


.global ow_script_0x96eb83
ow_script_0x96eb83:
    applymovement 0xff ow_script_movs_0x96aba6
    applymovement 0x1 ow_script_movs_0x96abad
    waitmovement 0x0
    settrainerflag 0xb2
    setvar LASTTALKED 0x5
    setvar VAR_ALLY 0x170
    special SPECIAL_ALLY_BATTLE_SAVE_AND_SETUP_PARTY
    trainerbattleallytwotrainers 0xb2 0x173 0x170 5 TRAINER_BACKSPRITE_IGVA 0 str_0x96a618 str_0x969f24 str_after2 ow_script_0x969e71
    //trainerbattlecont 0x1 0xb2 0x0 str_0x96a618 str_0x969f24 ow_script_0x969e71

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
setvar VAR_ALLY 0x170
special SPECIAL_ALLY_BATTLE_SAVE_AND_SETUP_PARTY
special SPECIAL_BATTLE_HANDICAP_CLEAR
setvar 0x8004 BATTLE_HANDICAP_GROUDON_BATTLE
special SPECIAL_BATTLE_HANDICAP_SET
trainerbattleally 0xaa 0x170 2 TRAINER_BACKSPRITE_IGVA 1 str_0x96f0ee str_0x96f156 ow_script_0x96fbaa


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
str_select:
    .autostring 34 2 "Welche Pokémon möchtest du in den Kampf schicken?"

str_have_to_select:
    .autostring 34 2 "PLAYER!\nWir haben keine Zeit für solche Spielchen!\pWir müssen Mistral stoppen!"

.global str_0x969e0b

str_0x969e0b:
    .autostring 35 2 "Mistral!\nWas hast du vor?\pWeißt du denn, was du hier tust?"
        
        
.global str_0x96a758

str_0x96a758:
    .autostring 34 2 "Igva!\nMit dir hätte ich hier wirklich nicht gerechnet.\pBist du noch immer ein Mitglied bei den Revolutionären?\pDieser Bande von naiven Träumern beizutreten war reinste ZeitverschwendungDOTS"

.global str_0x96a8cd

str_0x96a8cd:
    .autostring 34 2 "Und dann trittst du Team Violet bei?\pIst das etwa dein Verständnis von Gerechtigkeit?\pDie Revolution kämpft für eine freie und gerechte Welt.\pUnd was will Team Violet erreichen?\pIhr bringt der Welt nichts weiter als Leid und Chaos!"

        
.global str_0x969d1d

str_0x969d1d:
    .autostring 34 2 "Ach Igva, ich vergesse immer wieder wie einfältig du doch bist.\pDu solltest mich gut genug kennen, um zu wissen, dass es mich nicht im Geringsten interessiert, welche Ziele Team Violet verfolgt.\pIch habe schon immer einzig in meinem Interesse gehandelt.\pUnd Team Violet bietet mir die Möglichkeit, eine Macht zu erlangen, die bisher kaum ein Mensch kontrollieren konnte.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pSieh nur Igva, hast du etwa einen neuen Begleiter?"
        
        
.global str_0x969a22

str_0x969a22:
    .autostring 34 2 "Willkommen, PLAYER!\pIch hatte gehofft, dich hier anzutreffen.\pDu hast meine ehemalige Partnerin bei den Revolutionären wohl schon kennengelernt.\pSei bloß vorsichtig, PLAYER, denn das Mädchen wird schnell anhänglichDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDu fragst dich sicherlich, was mich an einen solchen Ort treibt, nicht?\pNun, wie du bestimmt schon weißt, verfolgt Team Violet das Ziel, die Macht des legendären Zeitsteins, des Diserakts zu erlangen.\pDafür müssen alle drei Fragmente dieses Steins zusamengeführt werden.\pUnd eines dieser Fragmente befindet sich direkt hier, im Krater des Volcanos."

.global str_0x96eab0

str_0x96eab0:
    .autostring 34 2 "Ein atemberaubender Anblick, nicht wahr?\pMan kann die Energie, die vom Diserakt ausgeht, förmlich spüren.\pKein Wunder, warum Team Violet sich für den Zeitstein interessiertDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pAber um ehrlich zu seinDOTS DOTS DOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pHabe ich es auf etwas anderes abgesehen.\pNämlich das Pokémon, das den Zeitstein bewacht!"
        
        
.global str_0x96abb4

str_0x96abb4:
    .autostring 34 2 "PLAYER!\nWir dürfen Mistral damit nicht durchkommen lassen.\pDas Wesen, das hier schlummert und den Zeitstein bewacht ist eine grauenvolle Bestie, die seit Urzeiten im Erdinneren schlummert.\pWenn Mistral sie erweckt, schweben wir alle in höchster Gefahr!\pWir müssen ihn gemeinsam aufhalten!"

.global str_0x96ab03

str_0x96ab03:
    .autostring 34 2 "Denkt ihr wirklich, dass ihr Mistral aufhalten könnt?\pWenn wir erst im Besitz des Zeitsteins sind, wird uns ganz Theto zu Füßen liegen!"
        
        
.global str_0x96ab6d

str_0x96ab6d:
    .autostring 34 2 "Ihr seid viel zu spät, um uns jetzt noch aufhalten zu können."

str_after0:
    .autostring 34 2 "Mistral wird unseren Plan umsetzten!"
        
        
.global str_0x96aa55

str_0x96aa55:
    .autostring 34 2 "Mistral wird das gelingen, was Rin nicht geschafft hat!\pWir werden den Zeitstein in unsere Finger bekommen!"
        
        
.global str_0x96aac6

str_0x96aac6:
    .autostring 35 2 "Diese Niederlage ist völlig irrelevant für unseren PlanDOTS"
        
str_after1:
    .autostring 34 2 "Ihr solltet euch hier raushalten, wenn euch euer Leben lieb ist!"
        
.global str_0x96a618

str_0x96a618:
	.autostring 35 2 "Bis hierher und nicht weiter, ihr Rotznasen.\pIch lasse euch nicht in Mistrals Pläne eingreifen!"

        
.global str_0x969f24

str_0x969f24:
    .autostring 35 2 "Unmöglich!\nIhr könnt Mistral nicht stoppen!"

str_after2:
    .autostring 34 2 "Selbst die Elite von Team Violet habt ihr besiegt?"
        
.global str_0x96ae6e

str_0x96ae6e:
	.autostring 35 2 "Ihr kommt zu spät!\pDer Diserakt DOTS DOTS DOTS\nDOTS DOTS DOTS\pDOTS gehört nun mir!"
        
        
.global str_0x96adf1

str_0x96adf1:
    .autostring 34 2 "Mistral, bitte!\pWenn dir unsere gemeinsame Zeit auch nur irgendetwas bedeutet hat, dann hör jetzt auf!\pEs ist noch nicht zu spät!\pErkennst du in deinem Wahn nicht, was du hier tust?"
        
        
.global str_0x96ada6

str_0x96ada6:
    .autostring 34 2 "Igva, sei endlich still!\pNichts was du sagst, kann mich jetzt noch von meinem Vorhaben abbringen!"
        
        
.global str_0x96ad59

str_0x96ad59:
    .autostring 35 2 "Oh nein, das Wächterpokémon\nDOTS DOTS DOTS"
        
        
.global str_0x96a698

str_0x96a698:
    .autostring 35 2 "DOTS DOTS DOTS ist aus seinem Schlaf erwacht!"
        
        
.global str_0x96ebfd

str_0x96ebfd:
    .autostring 35 2 "Das ist unser Ende!\pEs wird jeden von uns erledigenDOTS"
        
        
.global str_0x96b05d

str_0x96b05d:
    .autostring 34 2 "Komm zu mir, Groudon!\pIch fürchte mich nicht vor dir!\pDas Magmaherz macht mich zu deinem neuen Gebieter!\pIch werde deine uralte Kraft nach all den Jahren ein weiteres Mal entfesseln!"
        
.global str_0x97138c

str_0x97138c:
    .autostring 35 2 "Es DOTS DOTS DOTS\nDOTS DOTS DOTS\pDOTS ist verschwunden?"
        
        
.global str_0x96f1be

str_0x96f1be:
    .autostring 34 2 "Du bist wirklich schwer von Begriff, Igva!\pDas Magmaherz aus dem Museum von Orina City ermöglicht mir absolute Kontrolle über das antike Pokémon Groudon.\pUnd darüber hinaus erlangt es seine wahre Stärke als Herrscher über die Erde!\pIn seiner Kaiserform ist Groudon nicht zu stoppen!\pHaha!\nHahaha! Hahaha!\pIch bin unbesiegbar!"
 
.global str_0x96f0ee

str_0x96f0ee:
    .autostring 34 2 "Denkt ihr wirklich, dass ihr eine Chance gegen Groudon habt?\pIch bewundere euren Heldenmut!\pAber alles, was er euch nun bringen wird, ist ein qualvolles Ende!\pIch werde jeden, der sich mir in den Weg stellt, vernichten!"
        
        
.global str_0x96f156

str_0x96f156:
	.autostring 35 2 "DOTS Das ist vollkommen DOTS absurd!\pDu hast DOTS DOTS DOTS\pIhr habt Groudon besiegt?\nIn seiner Kaiserform?"
        
        
.global str_0x9713b5

str_0x9713b5:
    .string "DOTS\nDOTS DOTS DOTS DOTS\pDas DOTS ist DOTS\nDOTS\pDOTS ihr habt Groudon besiegt?"
        
        
.global str_0x96fd16

str_0x96fd16:
    .autostring 34 2 "Was?\nUnmöglich!\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIch verliere die Kontrolle über Groudon!"
        
        
.global str_0x96fd4a

str_0x96fd4a:
    .autostring 34 2 "Es wird alles in Schutt und Asche legen!\pWir müssen sofort hier weg!"
        
        
.global str_0x96fc90

str_0x96fc90:
    .autostring 34 2 "Wir können es unmöglich rechtzeitig schaffen!\pDas hier istDOTS\nDOTSunser Untergang!"
        
        
.global str_0x97300a

str_0x97300a:
    .autostring 35 2 "Ich verstehe nicht DOTS\pWieso DOTS DOTS DOTS\pIch kann nicht sterben!"
        
        
.global str_0x972330

str_0x972330:
    .autostring 35 2 "Das ist unser Ende!"
        
        
.global str_0x972313

str_0x972313:
    .autostring 35 2 "Ist das so?"
        
        
.elseif LANG_EN

.endif
