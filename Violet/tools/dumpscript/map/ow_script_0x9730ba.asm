.include "vars.s"
.include "callstds.s"
.include "movements.s"
.include "songs.s"
.include "flags.s"


.global ow_script_0x9730ba

ow_script_0x9730ba:
call ow_script_0x936c1c
loadpointer 0x0 str_0x971e16
callstd MSG
special 0x7
pause 0x1
call ow_script_0x97231c
loadpointer 0x0 str_0x971d73
callstd MSG
special 0x7
pause 0x1
setvar SONG_OVERRIDE 0x0
playsong MUS_PUNKTLOCH_AND_TANIBOSCHLUSSEL_AND_ICOGNITO_KAMMERN 0x0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x971d60
callstd MSG
special 0x7
pause 0x1
applymovement 0x1 ow_moves_0x971d5d
waitmovement 0x0
call ow_script_0x97231c
loadpointer 0x0 str_0x971c82
callstd MSG
special 0x7
pause 0x1
call ow_script_0x936c1c
loadpointer 0x0 str_0x971c05
callstd MSG
special 0x7
call ow_script_0x97231c
loadpointer 0x0 str_0x953d08
callstd MSG
special 0x7
pause 0x1
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x9718d8
callstd MSG
special 0x7
pause 0x1
call ow_script_0x97231c
loadpointer 0x0 str_0x9717c3
callstd MSG
special 0x7
pause 0x1
playsong MUS_SPIELHALLE_VERSION_3 0x0
fadescreen 0x1
call ow_script_0x97231c
loadpointer 0x0 str_0x971424
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x96fd7a
callstd MSG
special 0x7
pause 0x1
fadesong MUS_PUNKTLOCH_AND_TANIBOSCHLUSSEL_AND_ICOGNITO_KAMMERN
fadescreen 0x0
call ow_script_0x936c1c
loadpointer 0x0 str_0x96fa81
callstd MSG
special 0x7
pause 0x1
call ow_script_0x97231c
loadpointer 0x0 str_0x96f811
callstd MSG
special 0x7
pause 0x1
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x96f680
callstd MSG
special 0x7
pause 0x1
call ow_script_0x97231c
loadpointer 0x0 str_0x96f55c
callstd MSG
special 0x7
pause 0x1
call ow_script_0x936c1c
loadpointer 0x0 str_0x96f427
callstd MSG
special 0x7
applymovement 0xff ow_moves_0x96eff0
waitmovement 0x0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x96ef94
callstd MSG
special 0x7
pause 0x1
applymovement 0xff ow_moves_0x96ef91
waitmovement 0x0
call ow_script_0x97231c
loadpointer 0x0 str_0x96edc1
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x96ef26
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x96ef5f
callstd MSG
special 0x7
pause 0x1
addvar STORY_PROGRESS 0x1
setflag PKMNMENU
setflag PKMNMENU
goto ow_script_0x953cf2


.global ow_script_0x953cf2

ow_script_0x953cf2:
clearflag 0x896d
setvar SONG_OVERRIDE 0xffff
sound 0x64
checksound
warpmuted 0x0 0xd 0xff 0x11 0x1a
waitstate
end


.global ow_script_0x97231c

ow_script_0x97231c:
setvar 0x8000 0x1
setvar 0x8001 0x11
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x8a1cc9

ow_script_0x8a1cc9:
setvar 0x8000 0x0
setvar 0x8001 0xc
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x936c1c

ow_script_0x936c1c:
setvar 0x8000 0x0
setvar 0x8001 0x2
setvar 0x8002 0xe
special 0x6
return


.global ow_moves_0x971d5d

ow_moves_0x971d5d:
	.byte FACE_DOWN
	.byte STOP


.global ow_moves_0x96eff0

ow_moves_0x96eff0:
	.byte LOOK_RIGHT
	.byte STOP


.global ow_moves_0x96ef91

ow_moves_0x96ef91:
	.byte LOOK_UP
	.byte STOP


.global str_0x971e16

str_0x971e16:
.string GER "Mistral: Was um alles in der Welt?\n... ... ...\pWas ist geschehen?\nWo bin ich hier?"


.global str_0x971d73

str_0x971d73:
.string GER "???: PLAYER, Mistral.\nEndlich begegne ich euch."


.global str_0x971d60

str_0x971d60:
.string GER "PLAYER: Wer bist du?"


.global str_0x971c82

str_0x971c82:
.string GER "???: Verzeiht bitte, dass ich es\nversäumt habe, mich vorzustellen.\lMein Name ist Rubys, und ich bin\lder Retter eurer Leben.\pDer Ausbruch des Vulcanos und der\nAmoklauf des legendären Pokémons\lGroudon wurde verhindert."


.global str_0x971c05

str_0x971c05:
.string GER "Mistral: Ich verstehe es nicht.\nHast du das getan?\lIst es dein Werk, dass wir am\lLeben sind?\lHast du uns hierher gebracht?"


.global str_0x953d08

str_0x953d08:
.string GER "Rubys: Das ist korrekt.\nIch habe euch beide bereits seit\llangem beobachtet.\pWir befinden uns hier in einer\nDimension, die über der euch\lbekannten Raumzeit liegt.\pDieses Reich trägt den Namen Arc.\nIhr befindet euch in der Festung\lArc Skrim, meiner Residenz.\pDie Arc wird von höherdimensionalen\nWesen wie mir bewohnt, den\lChronen.\pEin Chron besizt ein viel\numfassenderes Verständnis für das\lZeitgefüge als ihr Menschen.\pIch kenne die Zukunft und die\nVergangenheit, der\lGegenwartsbegriff hat für mich\lkeine Bedeutung.\pZeit ist für mich eine Dimension\nwie Höhe oder Breite."


.global str_0x9718d8

str_0x9718d8:
.string GER "PLAYER: Entschuldige, dass ich dich\nunterbrechen muss.\pSelbst, wenn das, was du uns\nerzählst, wahr ist...\pWenn du wirklich das gottähnliche\nWesen bist, das du beschreibst...\pWieso hast du uns gerettet?\nWieso hast du den Vulkanausbruch\lverhindert?"


.global str_0x9717c3

str_0x9717c3:
.string GER "Rubys: Natürlich.\nIch werde versuchen, euch so viel\lwie möglich zu erklären.\lDazu aber muss ich sehr weit\lausholen."


.global str_0x971424

str_0x971424:
.string GER "Rubys: Vor Äonen, als das\nUniversum erst wenige\lJahrmillionen alt war, entstand in\lunendlichen Weiten das erste\lLeben.\pBegeistert von der Tragweite des\nEreignisses beschloss ich, ihm\lbeizuwohnen.\pDen Chronen ist es verboten, die\nArc zu verlassen, unsere Aufgabe\ldient der Wahrung einer Zeitlinie,\ldie als geltend deklariert wurde.\pJedes Eingreifen unsererseits\ngefährdet diese perfekte,\lallgemein anerkannte Zeitlinie.\pDoch ich ignorierte jenes\nheiligste Gesetz im Glabuen, dass\lmeine Anwesenheit keinen Einfluss\lauf die Geschichte haben sollte.\pIch irrte.\pMeine Anwesenheit allein kreierte\nwohl einen Ablauf, der schließlich\lin einem Ereignis mündete, das ihr\lals die Katastrophe von Aktania\lkennt.\pMeine Anwesenheit bei der\nEntstehung des ersten Lebens also\lwar es, die den Meteor leztlich\lauf diese Welt schickte und damit\leine Zeitlinie schuf, welche wir\lChronen nicht vorhersehen können.\pNichts ist, wie es sein sollte."


.global str_0x96fd7a

str_0x96fd7a:
.string GER "Ich schickte euch beiden Visionen,\ndie sowohl die Vergangenheit als\lauch die Zukunft dieser neuen\lZeitlinie portraitieren sollten.\pIch wollte euch beiden bewusst\nmachen, welche Wichtigkeit euer\lGelingen für diese Zeit hat.\pEure Aufgabe ist es einzig, meine\nFehler zu korrigieren.\pIhr sollt die Zeitlinie zurück in\nihre angedachten Bahnen lenken."


.global str_0x96fa81

str_0x96fa81:
.string GER "Mistral: Du warst also für diese\nBilder verantwortlich?\lFür die Zerstörung Aktanias und\ldie dunkle Welt der Zukunft?\pWarum ich? Warum PLAYER?"


.global str_0x96f811

str_0x96f811:
.string GER "Rubys: Das ist eine Frage, die ich\nzu beantworten nicht im Stande\lbin.\pDiese Zeitlinie entbehrt jeder\nKontrolle durch mich, ich kann sie\lnicht lenken oder maßgeblich\lbeeinflussen.\pDer Grund dafür ist eure Existenz.\pIhr seid in keiner Zeit\nvorgesehen, in keiner Rechnung\ltaucht euer Name auf.\pIhr seid mir ein Mysterium, nicht\nzuletzt, weil euer Schicksal nicht\lder Kontrolle der Chronen\lunterliegt.\pIhr seid die einzigen Menschen,\ndie wir nicht erschaffen oder\lauslöschen können.\pUnd ich weiß, dass diese Tatsache\neine Bedeutung hat.\pIch weiß, dass unter allen\nMenschen nur ihr in der Lage seid,\ldie Zeitlinie zu richten."


.global str_0x96f680

str_0x96f680:
.string GER "PLAYER: Mistral und ich..\nWir sind...?"


.global str_0x96f55c

str_0x96f55c:
.string GER "Rubys: Ich weiß nicht was ihr\nseid.\pWie Licht und Dunkelheit scheint\nihr neue Elemente einer Welt zu\lsein, die nie hätte sein dürfen.\pMistral, PLAYER.\pDer Diserakt muss wieder vereint\nwerden.\pEr muss zurück zu Celebi, dem\nZeitpokémon gebracht werden, wo er\lsicher bis ans Ende der Zeit\llagert."


.global str_0x96f427

str_0x96f427:
.string GER "Mistral: Was kümmert es mich?\nDer Diserakt besitzt die Macht,\leine Waffe zu erschaffen, deren\lZerstörungsausmaß unendlich ist.\pWenn ich so mächtig bin, wie du\nmir glauben machen willst, dann\lwerde ich diese Waffe benutzen,\ldie Welt zu unterwerfen.\pDann hat deine ach so dunkle\nZukunft keine Bedeutung mehr."


.global str_0x96ef94

str_0x96ef94:
.string GER "PLAYER: Das kann nicht dein\nErnst sein?\lWas, wenn deine Waffe genau jene\lZukunft herbeiführt?"


.global str_0x96edc1

str_0x96edc1:
.string GER "Rubys: Schweigt.\nIch weiß nicht, welche Handlung\lwelche Folgen verursachen.\lIch kann nicht ausschließen, dass\lMistrals Herangehensweise falsch\list.\lIch kann euch nicht helfen.\lIch habe euch gerettet, weil es in\lmeiner Macht stand.\lDoch ich fürchte, dass die anderen\lChronen mir dies künftig\luntersagen werden.\lUnter Umständen wird meine\lExistenz getilgt."


.global str_0x96ef26

str_0x96ef26:
.string GER "Ich werde euch nun wieder in eure\nWelt zurückschicken."


.global str_0x96ef5f

str_0x96ef5f:
.string GER "Hoffentlich begegnen wir einander\nnicht wieder."


