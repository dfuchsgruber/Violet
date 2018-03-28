.include "overworld_script.s"

.include "std.s"

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
call ow_script_0x92f097
loadpointer 0x0 str_0x969e0b
callstd MSG
special 0x7
pause 0x1
call ow_script_0x936c1c
loadpointer 0x0 str_0x96a758
callstd MSG
special 0x7
pause 0x1
call ow_script_0x92f097
loadpointer 0x0 str_0x96a8cd
callstd MSG
special 0x7
pause 0x1
call ow_script_0x936c1c
loadpointer 0x0 str_0x969d1d
callstd MSG
special 0x7
pause 0x1
applymovement 0x7f ow_script_movs_0x969d17
waitmovement 0x0
special 0x114
applymovement 0xff ow_script_movs_0x969d10
waitmovement 0x0
call ow_script_0x936c1c
loadpointer 0x0 str_0x969a22
callstd MSG
special 0x7
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
call ow_script_0x936c1c
loadpointer 0x0 str_0x96eab0
callstd MSG
special 0x7
applymovement 0x2 ow_script_movs_0x96ace1
waitmovement 0x0
applymovement 0xff ow_script_movs_0x96acdb
applymovement 0x1 ow_script_movs_0x96acde
waitmovement 0x0
call ow_script_0x92f097
loadpointer 0x0 str_0x96abb4
callstd MSG
special 0x7
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
call ow_script_0x936c1c
loadpointer 0x0 str_0x96ae6e
callstd MSG
special 0x7
call ow_script_0x92f097
loadpointer 0x0 str_0x96adf1
callstd MSG
special 0x7
call ow_script_0x936c1c
loadpointer 0x0 str_0x96ada6
callstd MSG
special 0x7
applymovement 0x2 ow_script_movs_0x96ada3
waitmovement 0x0
fadesong MUS_0
sound 0x16
hidesprite 0x9
checksound
pause 0x40
call ow_script_0x96ebb2
call ow_script_0x92f097
loadpointer 0x0 str_0x96ad59
callstd MSG
special 0x7
call ow_script_0x8d7a10
call ow_script_0x936c1c
loadpointer 0x0 str_0x96a698
callstd MSG
special 0x7
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
call ow_script_0x92f097
loadpointer 0x0 str_0x96ebfd
callstd MSG
special 0x7
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
call ow_script_0x936c1c
loadpointer 0x0 str_0x96b05d
callstd MSG
special 0x7
setvar LASTRESULT 0x1
sound 0xd1
setanimation 0x0 0x10
setanimation 0x1 0x2a
setanimation 0x2 0x0
doanimation 0x36
nop
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
call ow_script_0x92f097
loadpointer 0x0 str_0x97138c
callstd MSG
special 0x7
applymovement 0x2 ow_script_movs_0x96f408
waitmovement 0x0
call ow_script_0x936c1c
loadpointer 0x0 str_0x96f1be
callstd MSG
special 0x7
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
call ow_script_0x936c1c
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
call ow_script_0x936c1c
loadpointer 0x0 str_0x9713b5
callstd MSG
special 0x7
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
call ow_script_0x936c1c
loadpointer 0x0 str_0x96fd16
callstd MSG
special 0x7
pause 0x1
call ow_script_0x972ff2
call ow_script_0x92f097
loadpointer 0x0 str_0x96fd4a
callstd MSG
special 0x7
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
call ow_script_0x92f097
loadpointer 0x0 str_0x96fc90
callstd MSG
special 0x7
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
call ow_script_0x936c1c
loadpointer 0x0 str_0x97300a
callstd MSG
special 0x7
cry POKEMON_GROUDON 0x0
call ow_script_0x972ff2
applymovement 0xa ow_script_movs_0x9730a0
goto ow_script_0x971dd7


.global ow_script_0x971dd7
ow_script_0x971dd7:
call ow_script_0x92f097
loadpointer 0x0 str_0x972330
callstd MSG
special 0x7
cry POKEMON_GROUDON 0x0
call ow_script_0x972ff2
waitcry
pause 0x20
fadesong MUS_0
setvar 0x8004 0x9
special 0x19
waitstate
call ow_script_0x97231c
loadpointer 0x0 str_0x972313
callstd MSG
special 0x7
goto ow_script_0x9730a3


.global ow_script_0x9730a3
ow_script_0x9730a3:
sound 0x64
checksound
setvar 0x8004 0xa
special 0x19
addvar STORY_PROGRESS 0x1
waitstate
goto ow_script_0x966e64


.global ow_script_0x966e64
ow_script_0x966e64:
addvar STORY_PROGRESS 0x1
end


.global ow_script_0x97231c
ow_script_0x97231c:
setvar 0x8000 0x1
setvar 0x8001 0x11
setvar 0x8002 0xe
special 0x6
return


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
    .string "Mistral!\nWas hast du vor?\lWeißt du denn, was du hier tust?"
        
        
.global str_0x96a758

str_0x96a758:
    .string "Igva, du bist naiv wie eh\nund je.\pDass ihr Revolutionäre immer noch\nexistiert, ist mir ein Rätsel.\pEuer Anführer hat außer schön\nklingenden Sprüchen und Krieg doch\lnichts zu bieten?\pIhr redet von Aufstand und\nNeuerung, aber habt keine Lösungen\lanzubieten.\pIhr führt die Menschen in einen\nKrieg, der ihnen nichts bringt.\pUnd dann nennst du mich einen\nUnmenschen?"
        
        
.global str_0x96a8cd

str_0x96a8cd:
    .string "Nein, du irrst dich!\nUnser Kampf ist nobel, deiner nur\legoistisch!\pDu hast uns im Stich gelassen, um\nMacht zu finden.\pUnd nun willst du den Zeitstein\nrauben, wissend, dass du damit den\lWächter der Landmassen erweckst\lund seinen Zorn über dieses Land\lschickst?\pIst dir bewusst, was das legendäre\nPokémon Groudon für eine\lschrecklich vernichtende Kreatur\list?"
        
        
.global str_0x969d1d

str_0x969d1d:
    .string "Hahaha!\nUnd dir ist nie in den Sinn\lgekommen, dass ich genau das\lprovozieren will?\pDass es mir mehr um die\nWiedererweckung Groudons geht, als\ldiesen dummen Stein?\l...\pAber sieh nur, Igva.\nDein neuer Begleiter ist\leingetroffen."
        
        
.global str_0x969a22

str_0x969a22:
    .string "Herzlich willkommen,\nPLAYER!\pUns scheint doch etwas zu\nverbinden, wenn ich dich hier mit\lmeiner alten Partnerin treffe.\pEinst war ich Teil ihrer\neinfältigen Revolustionsbewegung,\lehe ich erkannt habe, dass ich so\lniemals Macht erlangen kann.\pNun stehen wir hier schicksalshaft\neinander gegenüber.\pVor uns der Schlot eines Vulkans,\nin dessen Herzen eine der\lmächtigsten Kreaturen der Welt\lschlummert.\pAm Ende des Weges ein Teil des\nlegendären Steins der Zeit, des\lDiserakts.\pWas Rin nicht in Erfahrung bringen\nkonnte, weiß ich längst:\pIn drei Teile wurde der Zeitstein\ngespalten, den drei Wächtern der\lWelt anvertraut.\pSieh ihn dir an, den Zeitstein,\ndiese überwältigende Aura der\lMacht, dieses pulsierende\lSchimmern.\lEs ist fast bezaubernd..."
        
        
.global str_0x96eab0

str_0x96eab0:
    .string "Der Stein wird sich bald im Besitz\ndes Teams Violet befinden und\leine Waffe erschaffen, deren Macht\lunvergleichlich groß sein soll.\lUnd ich werde mich weder von euch\lnoch sonst irgendjemandem\laufhalten lassen."
        
        
.global str_0x96abb4

str_0x96abb4:
    .string "Wir dürfen das nicht\ngeschehen lassen.\lDer Diserakt hält den Fluss der\lZeit aufrecht - wer ihm die\lEnerige entzieht, lähmt die\lZeitstruktur.\lAußerdem wird das Entfernen des\lDiserakts das Wächterpokémon\lGroudon auf den Plan rufen.\lInferior wird diese Katastrophe\lnicht überstehen können."
        
        
.global str_0x96ab03

str_0x96ab03:
    .string "Mistral ist nicht aufzuhalten.\nDas Fragment des Zeitsteins wird\luns zu den Herrschern der Welt\lerheben!"
        
        
.global str_0x96ab6d

str_0x96ab6d:
    .string "Du kommst ohnehin zu spät, um uns\nnun noch zu stoppen."
        
        
.global str_0x96aa55

str_0x96aa55:
    .string "Mistral vollbringt, was Rin nicht\nerreichen konnte.\pEr wird alle drei Teile des\nDiserakts finden und vereinen."
        
        
.global str_0x96aac6

str_0x96aac6:
    .string "Stell dich ihm nicht in den Weg,\noder du wirst vernichtet!"
        
        
.global str_0x96a618

str_0x96a618:
    .string "Ich bin der Punkt, an dem du\nscheitern wirst.\pMistrals Aufgabe ist zu wichtig,\nals dass ich dir erlauben könnte,\leinzugreifen."
        
        
.global str_0x969f24

str_0x969f24:
    .string "Unmöglich.\nDu kannst ihn nicht stoppen!"
        
        
.global str_0x96ae6e

str_0x96ae6e:
    .string "Ihr beiden kommt zu spät.\nDer Diserakt ist mein."
        
        
.global str_0x96adf1

str_0x96adf1:
    .string "Mistral, bitte!\pWenn ich dir je etwas bedeutet\nhabe, tu es nicht!"
        
        
.global str_0x96ada6

str_0x96ada6:
    .string "Schweig!\nDummes Mädchen!\pErzittert vor der Kraft des\nDiserakts!"
        
        
.global str_0x96ad59

str_0x96ad59:
    .string "Oh bei Arceus!\nDas ist das Wächterpokémon\lGroudon...\lEs... es ..."
        
        
.global str_0x96a698

str_0x96a698:
    .string "Es ist endlich aus seinem\nSchlaf erwacht!"
        
        
.global str_0x96ebfd

str_0x96ebfd:
    .string "Das ist unser aller Ende!\nGroudon wird alles verwüsten und\lzerstören!"
        
        
.global str_0x96b05d

str_0x96b05d:
    .string "Da stehst du vor mir,\ndu mächtiges, mächtiges Wesen!\pDeine Kraft soll fortan an mich\ngebunden sein.\pHier erhebe ich das Magmaherz, das\nuralte Artefakt, um deine wahre\lKraft zu entfesseln!"
        
        
.global str_0x97138c

str_0x97138c:
    .string "Was? Groudon ist...\nVerschwunden?"
        
        
.global str_0x96f1be

str_0x96f1be:
    .string "Törrichtes Gör!\nGroudon ist nicht verschwunden...\pEs ist unter meiner Kontrolle!\pDas Magmaherz, welches ich aus dem\nMuseum von Orina City gestohlen\lhabe, verleiht Groudon seine\lursprüngliche Macht...\pEs erhebt es in seine Kaiserform!\pMein Wort ist Groudons Befehl!\pMein Wille seine Handlung!\pMein Geist seine Macht!\pGroudons Kaiserform birgt ein\nunvorstellbares Maß an Vernichtung\lund Chaos - Planeten werden wie\lKäferpokémon zerschmettert und\lHimmel wie Kerzen in Brand\lgesetzt!\pHahaha! Hahaha!\pAlso!\pPLAYER!\pIch fordere dich heraus!\pBrenne! Schreie!\pIch werde dich vernichten!"
        
        
.global str_0x96f0ee

str_0x96f0ee:
    .string "Dieser Kampf wird über das\nSchicksal dieser Welt entscheiden!\pWer darf herrschen, wer muss\ngehorchen?"
        
        
.global str_0x96f156

str_0x96f156:
    .string "... Das ist ... völlig ...\nabsurd! ...\pDu hast ... Groudon ... besiegt?\nIn seiner Kaiserform?"
        
        
.global str_0x9713b5

str_0x9713b5:
    .string "...\n... ... ... ...\pDas ... ist ...\n...\p... du hast Groudon besiegt?"
        
        
.global str_0x96fd16

str_0x96fd16:
    .string "Nein!\nEs entzieht sich meiner Kontrolle!"
        
        
.global str_0x96fd4a

str_0x96fd4a:
    .string "Es wird alles und jeden hier\nvernichten!"
        
        
.global str_0x96fc90

str_0x96fc90:
    .string "Wir werden es nicht\nschaffen!\lDer Vulkan ist im Begriff\lauszubrechen.\lDer Abstieg wird ein heißer Tod!\lWir sind am Ende!"
        
        
.global str_0x97300a

str_0x97300a:
    .string "Was habe ich getan?\nJetzt werden wir...\lWerden wir...\pAlle...\nsterben!"
        
        
.global str_0x972330

str_0x972330:
    .string "Wir sind geliefert.\nDer Tod, er hat uns gefunden!"
        
        
.global str_0x972313

str_0x972313:
    .string "Nicht."
        
        
.elseif LANG_EN

.endif
