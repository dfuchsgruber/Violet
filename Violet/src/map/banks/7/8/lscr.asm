.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"

.global lscr_0x81c4d9

lscr_0x81c4d9:
	.byte 0x4
.word lscr_0x83074b
	.byte 0x2
.word lscr_0x81c541
	.byte 0x0

.align 4
.global lscr_0x83074b

lscr_0x83074b:
	.hword STORY_PROGRESS, 0x1a
	.word ow_script_0x81c512
	.hword 0x0

.align 4
.global lscr_0x81c541

lscr_0x81c541:
	.hword STORY_PROGRESS, 0x1a
	.word ow_script_0x81c406
	.hword 0x0

.global ow_script_0x8ecac3
.global ow_script_0x81c406
.global ow_script_0x81c51d
.global ow_script_0x8f7200
.global ow_script_0x8c7d62
.global ow_script_0x81c512
.global ow_script_0x8fbc6c

ow_script_movs_0x8eca2a:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x8eca0e:
.byte STEP_UP
.byte STOP


ow_script_movs_0x8ec91e:
.byte SAY_QUESTION
.byte STOP

mov_fd_exclam:
	.byte LOOK_DOWN, SAY_EXCLAM, STOP
mov_2u:
	.byte STEP_UP, STEP_UP, STOP
mov_fu:
	.byte LOOK_UP, STOP
mov_fl:
	.byte LOOK_LEFT, STOP
mov_fd:
	.byte LOOK_DOWN, STOP
mov_fr:
	.byte LOOK_RIGHT, STOP
mov_1d:
	.byte STEP_DOWN, STOP
mov_rival_out_of_way:
	.byte STEP_DOWN, STEP_LEFT, LOOK_RIGHT, STOP
mov_away:
	.byte STEP_DOWN, STEP_DOWN, STEP_RIGHT, STEP_DOWN, STOP
mov_rival_away:
	.byte STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_DOWN_FAST, STOP
mov_felix_away:
	.byte STEP_RIGHT, STEP_DOWN, STEP_RIGHT, STEP_DOWN, STOP
mov_rosalie_away:
	.byte STEP_RIGHT, STEP_DOWN, STEP_DOWN, STEP_LEFT, STEP_DOWN, STOP

ow_script_0x81c406:
	// checkflag SILVANIA_FOREST_FLASHBACK_DONE
	// gotoif EQUAL ow_script_0x8f7200
	loadpointer 0 str_0
	show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY
	loadpointer 0 str_1
	show_mugshot MUGSHOT_FAUN MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
	loadpointer 0 str_2
	show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY
	closeonkeypress
	sound 0x15
	applymovement 1 mov_fd_exclam
	applymovement 2 mov_fd_exclam
	applymovement 3 mov_fd_exclam
	applymovement 4 mov_fd_exclam
	waitmovement 0
	loadpointer 0 str_3
	show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
	closeonkeypress
	applymovement 0xFF mov_2u
	waitmovement 0
	applymovement 3 mov_fu
	applymovement 4 mov_fu
	applymovement 2 mov_fl
	waitmovement 0
	loadpointer 0 str_4
	show_mugshot MUGSHOT_ROSALIE MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
	loadpointer 0 str_5
	show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
	closeonkeypress
	applymovement 3 mov_fr
	waitmovement 0
	loadpointer 0 str_6
	show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANNOYED
	applymovement 4 mov_fl
	waitmovement 0
	loadpointer 0 str_7
	show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY
	loadpointer 0 str_8
	show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY
	applymovement 3 mov_fu
	applymovement 4 mov_fu
	waitmovement 0
	loadpointer 0 str_9
	show_mugshot MUGSHOT_FAUN MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY
	loadpointer 0 str_10
	show_mugshot MUGSHOT_ROSALIE MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
	closeonkeypress
	pause 64
	loadpointer 0 str_11
	show_mugshot MUGSHOT_FAUN MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
	applymovement 2 mov_fd
	waitmovement 0
	loadpointer 0 str_12
	show_mugshot MUGSHOT_ROSALIE MUGSHOT_RIGHT message_type=MSG_KEEPOPEN hide_mugshot=0
	update_mugshot_emotion MUGSHOT_ANGRY
	loadpointer 0 str_13
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	pause 32
	loadpointer 0 str_14
	show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANNOYED
	closeonkeypress
	pause 32
	applymovement 2 mov_fl
	waitmovement 0
	loadpointer 0 str_15
	show_mugshot MUGSHOT_FAUN MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
	loadpointer 0 str_16
	show_mugshot MUGSHOT_ROSALIE MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
	loadpointer 0 str_17
	show_mugshot MUGSHOT_FAUN MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
	closeonkeypress
	applymovement 4 mov_rival_out_of_way
	applymovement 1 mov_away
	waitmovement 4
	applymovement 2 mov_fd
	applymovement 3 mov_fd
	applymovement 0xFF mov_fd
	applymovement 4 mov_fd
	waitmovement 1
	pause 32
	sound 9
	hidesprite 1
	checksound
	pause 24
	applymovement 3 mov_fr
	applymovement 4 mov_fr
	applymovement 2 mov_fl
	applymovement 0xFF mov_fl
	loadpointer 0 str_18
	show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
	closeonkeypress
	applymovement 4 mov_rival_away
	waitmovement 0
	sound 9
	hidesprite 4
	checksound
	pause 16
	loadpointer 0 str_19
	show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANNOYED
	loadpointer 0 str_20
	show_mugshot MUGSHOT_ROSALIE MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
	loadpointer 0 str_21
	show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
	loadpointer 0 str_22
	show_mugshot MUGSHOT_ROSALIE MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_HAPPY
	loadpointer 0 str_23
	show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_HAPPY
	closeonkeypress
	applymovement 3 mov_felix_away
	waitmovement 0
	pause 32
	sound 9
	hidesprite 3
	checksound
	pause 32
	applymovement 0xFF mov_fu
	applymovement 2 mov_fd
	waitmovement 0
	loadpointer 0 str_24
	show_mugshot MUGSHOT_ROSALIE MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
	closeonkeypress
	applymovement 2 mov_rosalie_away
	waitmovement 2
	pause 32
	sound 9
	hidesprite 2
	checksound
	addvar STORY_PROGRESS 0x2
	setflag FLAG_SILVANIA_FOREST_ENTRANCE
	setflag FLAG_SILVANIA_CUT_TREE
	releaseall
	end

/* 
ow_script_movs_0x8f28b5:
.byte LOOK_LEFT
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x8f28b2:
.byte LOOK_RIGHT
.byte STOP


ow_script_movs_0x8f27c8:
.byte FACE_DOWN
.byte STOP


ow_script_movs_0x8f26b0:
.byte LOOK_LEFT
.byte STOP


ow_script_movs_0x8f0a0b:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte FACE_DOWN
.byte STOP


ow_script_movs_0x8f0981:
.byte LOOK_UP
.byte STOP


ow_script_0x8f7200:
loadpointer 0x0 str_0x8f28b9
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0x2 ow_script_movs_0x8f28b5
waitmovement 0x0

loadpointer 0 str_mia
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8f3668
callstd MSG
special 0xF

applymovement 0x1 ow_script_movs_0x8f28b2
waitmovement 0x0
loadpointer 0x0 str_0x8f27cb
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0x1 ow_script_movs_0x8f27c8
applymovement 0x2 ow_script_movs_0x8f27c8
waitmovement 0x0
loadpointer 0x0 str_0x8f276d
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
loadpointer 0x0 str_0x8f26b3
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0x2 ow_script_movs_0x8f26b0
waitmovement 0x0

loadpointer 0 str_mia
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8f2607
callstd MSG
special 0xF

sound 0x63
showsprite 0x3
checksound
sound 0x15
applymovement 0x1 ow_script_movs_0x8eca2a
applymovement 0x2 ow_script_movs_0x8eca2a
applymovement 0xff ow_script_movs_0x8eca2a
waitmovement 0x0

loadpointer 0x0 str_0x8f257b
show_mugshot MUGSHOT_HARRENFELD MUGSHOT_RIGHT

loadpointer 0x0 str_0x8f0b3b
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0x1 ow_script_movs_0x8f28b2
waitmovement 0x0
loadpointer 0x0 str_0x8f0ad6
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0x1 ow_script_movs_0x8f27c8
waitmovement 0x0
loadpointer 0x0 str_0x8f0a28
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT



loadpointer 0x0 str_0x8f0a11
show_mugshot MUGSHOT_HARRENFELD MUGSHOT_RIGHT MSG

applymovement 0x3 ow_script_movs_0x8f27c8
waitmovement 0x0
sound 0x9
hidesprite 0x3
checksound
applymovement 0x1 ow_script_movs_0x8f0a0b
waitmovement 0x0
sound 0x9
hidesprite 0x1
checksound
applymovement 0xff ow_script_movs_0x8f0981
waitmovement 0x0
goto ow_script_0x8c7d62


ow_script_0x8c7d62:
loadpointer 0 str_mia
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8f0984
callstd MSG_KEEPOPEN
special 0xF

fanfare 0x13e
loadpointer 0x0 str_0x8c7f7a
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
additem ITEM_VM01 0x1
loadpointer 0 str_mia
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8c7f9a
callstd MSG
special 0xF

fadescreen 0x1
hidesprite 0x2
fadescreen 0x0
addvar STORY_PROGRESS 0x2
releaseall
end

*/
.ifdef LANG_GER

str_0:
	.autostring 34 2 "Aber Opi, Team Violet ist eine Gefahr für die Menschen in dieser Region!"
str_1:
	.autostring 34 2 "Genug jetzt davon, Felix!\pMag ja sein, dass diese Gruppe Ärger macht, aber jemand wie kann sich nicht mit solchen Problemen herumschlangenDOTS"
str_2:
	.autostring 34 2 "Aber was ist denn für ein Mitglied der Top Vier wichtiger, als die Menschen in Theto zu beschützen?"
str_3:
	.autostring 34 2 "Ah, PLAYER!\pDu kommst gerade richtig!\pHier fliegen schon wieder richtig die Fetzen!"
str_4:
	.autostring 34 2 "Wir sollten uns alle etwas beruhigenDOTS\pMit der ganzen Streiterei erreichen wir ja doch nichtsDOTS"
str_5:
	.autostring 34 2 "Ich verstehe sowieso nicht, warum wir uns hier angehen!\pDer alte Faun will uns im Kampf gegen Team Violet nicht helfen.\pNa und?\nWir wollen dieses Pack doch wieso auf eigene Faust zur Strecke bringen.\pSoll er sich seinen anderen Problemen widmen, und wir erledigen diesen Team Violet Kommandanten!"
str_6:
	.autostring 34 2 "RIVAL, du weißt doch gar nicht, was du da sagst.\pDiese Kommandanten sollte man nicht unterschätzen.\pAuch wenn die Polizei diesen Leuten keine besondere Aufmerksamkeit schenken willDOTSTEXT_DELAY_SHORT\pWenn man den Berichten glauben will, sind diese Kommandanten nicht zu unterschätzenDOTS"
str_7:
	.autostring 34 2 "Du hast einfach die Hosen voll!\pWillst du bei jeder Herausforderung deinen Opa um Hilfe bitten?\pDas ist kindischDOTS"
str_8:
	.autostring 34 2 "Was fällt dir ein!\pIm Gegensatz zu dir, bin ich im Stande, eine Gefahr auch richtig einzuschätzen, bevor ichDOTS"
str_9:
	.autostring 34 2 "Ruhe jetzt, ihr beiden!\pEure kindischen Streitereien habe ich satt!\pIhr verschwendet meine Zeit, ihr Bengel!"
str_10:
	.autostring 34 2 "BitteDOTS\nGenug Geschrei, wir sollten uns wirklich beruhigenDOTS"
str_11:
	.autostring 34 2 "Rosalie hat Recht.\pSo erreichen wir nichts.\pLasst es mich euch also in aller Deutlichkeit erklären.\pIch bin nicht einfach rein zufällig hierher gekommen.\pEs gibt hier Dinge, die ich erledigen muss, die viel wichtiger sind, als ein paar Punks zurechtzuweisen.\pUnd es ist klug von dir, Felix, dass du dieses Problem nicht unüberlegt angehen willst.\pAber du bist jetzt Teil der Polizei von Theto.\pDu musst auch etwas Mut beweisen, und dich solchen Herausforderungen entgegenstellen, ja?\pAußerdem habe ich ja auch gar nicht vor, euch allein mit dieser Aufgabe zu betrauenDOTS"
str_12:
	.autostring 34 2 "Das ist richtig.\pAls Arenaleiterin von Kranzdorf werde ich euch selbstverständlich unterstützen, wenn eine Bande von Verbrechern in meinem Wald ihr Unwesen treibt."
str_13:
	.autostring 34 2 "Ich lasse niemanden, der den Frieden in meinem wunderbaren Kranzwald bedroht, einfach so davonkommen!"
str_14:
	.string "DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT"
str_15:
	.autostring 34 2 "Na, seht ihr?\pSo kriegen wir Dinge doch noch geregelt!\pDamit ist es ausgemacht.\pRosalie wird euch helfen, diese Unruhestifter zurechtzuweisen.\pUnd ich kann mich darauf konzentrieren, wichtigere Angelegenheiten zu regeln."
str_16:
	.autostring 34 2 "Wie schön, dass wir uns doch noch einig geworden sind!"
str_17:
	.autostring 34 2 "Ich habe vollstes Vertrauen in meine ehemaligen Schüler!\pDas mögen zwar verzogene Gören sein, aber immerhin haben sie von mir gelernt, wie man kämpft!\pUnd das will schon 'was heißen!\pIhr werdet das schon schaukeln!"
str_18:
	.autostring 34 2 "So ist's mir sowieso lieber!\pDiesen Team Violet Leuten zeig ich schon, wo's lang geht!\pSteh uns bloß nicht im Weg herum, Rosalie!"
str_19:
	.autostring 34 2 "Aber RIVAL weiß doch nicht einmal, wo es lang gehtDOTS\pDas ist nicht auszuhaltenDOTS"
str_20:
	.autostring 34 2 "Der Junge ist wirklich ein HitzkopfDOTS\pAber ich bin froh, dass wir gemeinsam kämpfen können!\pUm eines muss ich euch aber bittenDOTS\pDer Kranzwald bedeutet mir sehr viel.\pEs gibt dort einen Ort, der mir sehr wichtig ist.\pBitte versucht trotz allem, diesem wunderschönen Wald würdevoll zu begegnen.\pNehmt bitte Rücksicht auf die Pflanzen und Pokémon, die im Kranzwald leben, ja?"
str_21:
	.autostring 34 2 "Das werden wir, Rosalie!\pIch denke, ich spreche auch im Namen von PLAYER, wenn ich sage, dass wir alles daran setzen, den Kranzwald zu beschützen.\pImmerhin stellen wir uns ja auch deswegen diesem Kommandanten von Team Violet, um Orte wie diesen vor Bösem zu bewahren."
str_22:
	.autostring 34 2 "Das freut mich außerordentlich!\pIhr habt gute Herzen, Kinder!\pWenn man mit sich selbst im Reinen ist, kann man gar nicht mehr verlieren.\pIch würde vorschlagen, wir treffen uns im Norden von Kranzdorf, wo sich der Eingang in den Kranzwald befindet, ja?"
str_23:
	.autostring 34 2 "Abgemacht!\pAber lasst euch nicht zu viel Zeit, sonst geht uns dieser Kommandant noch durch die Lappen!"
str_24:
	.autostring 34 2 "Dein Name war PLAYER, ja?\pDu machst einen entschlossenen Eindruck auf mich!\pDas ist gut, Entschlossenheit können wir im Kampf gegen böse Menschen gebrauchen!\pWir sehen uns am Waldeingang!"

.elseif LANG_EN

.endif


ow_script_0x81c512:
checkflag SILVANIA_FOREST_FLASHBACK_DONE
gotoif EQUAL ow_script_0x81c51d
end


ow_script_0x81c51d:
spriteface 0xff 0x2
spriteface 0x1 0x0
spriteface 0x2 0x0
end