.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "specials.s"
.include "songs.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"

.global ow_script_0x8fad58
.global ow_script_0x8a12f1
.global ow_script_0x8e09cc
.global ow_script_map_3_1_trigger_1
.global ow_script_0x8a27ae
.global ow_script_0x8e147c
.global ow_script_0x88c7d7
.global ow_script_0x8a1433
.global ow_script_0x8a1251
.global ow_script_0x8a15f3
.global ow_script_map_3_1_trigger_0
.global ow_script_map_3_1_trigger_2
.global ow_script_0x8e22eb
.global ow_script_map_3_1_trigger_3
.global ow_script_0x8a1311
.global ow_script_0x8a1af3
.global ow_script_0x8e1470
.global ow_script_0x8a1323

ow_script_map_3_1_trigger_0:
goto ow_script_0x8fad58


ow_script_0x8fad58:
lockall
goto ow_script_0x88c7d7


ow_script_movs_0x886b4b:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x8a1332:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


ow_script_movs_0x8a1307:
.byte STEP_UP
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte STOP


ow_script_movs_0x886b48:
.byte STEP_UP
.byte STOP


ow_script_movs_0x886b1b:
.byte STEP_UP
.byte STOP


ow_script_0x88c7d7:
sound 0x15
applymovement 0x1 ow_script_movs_0x886b4b
waitmovement 0x0
checksound
playsong MUS_KOMMT_MIT_SPIELER_WIRD_HERUMGEFUHRT 0x0
call ow_script_0x8a1311
applymovement 0x1 ow_script_movs_0x8a1332
waitmovement 0x0
loadpointer 0x0 str_0x8869ab
callstd MSG
call ow_script_0x8a1251
applymovement 0x1 ow_script_movs_0x8a1307
applymovement 0xff ow_script_movs_0x8a1307
waitmovement 0x0
loadpointer 0x0 str_0x886a80
callstd MSG
setdooropened 0x48 0x1c
doorchange
applymovement 0x1 ow_script_movs_0x886b48
waitmovement 0x0
hidesprite 0x1
applymovement 0xff ow_script_movs_0x886b1b
waitmovement 0x0
applymovement 0xff ow_script_movs_0x886b48
waitmovement 0x0
clearflag PKMNMENU
setvar STORY_PROGRESS 0x9
warp 0x5 0x4 0x0 0x0 0x0
end


ow_script_0x8a1251:
getplayerpos 0x8000 0x8001
compare 0x8000 0x42
callif EQUAL ow_script_0x8a12f1
return


ow_script_movs_0x8a1304:
.byte STEP_RIGHT
.byte STOP


ow_script_0x8a12f1:
applymovement 0x1 ow_script_movs_0x8a1304
applymovement 0xff ow_script_movs_0x8a1304
waitmovement 0x0
return


ow_script_0x8a1311:
getplayerpos 0x8000 0x8001
compare 0x8000 0x42
callif EQUAL ow_script_0x8a1323
return


ow_script_movs_0x8a132f:
.byte STEP_LEFT
.byte STOP


ow_script_0x8a1323:
applymovement 0x1 ow_script_movs_0x8a132f
waitmovement 0x0
return


.ifdef LANG_GER

str_0x8869ab:
    .string "Hallo! Du siehst mir aus wie ein\nTrainer, bist aber offensichtlich\lnoch grün hinter den Ohren. Keine\lSorge, mit etwas Übung wird das\lschon. Komm mit, ich erkläre dir\ldie Welt, die sich dir als Trainer\leröffnet."



str_0x886a80:
    .string "Diesen Ort nennt man Pokéstop.\nJeder Trainer hat sozusagen die\lPflicht dort vorbeizuschauen,\lsobald er eine neue Stadt\lerreicht. Komm, gehen wir hinein."


.elseif LANG_EN

.endif


ow_script_movs_0x8a17e7:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


ow_script_movs_0x8a17e3:
.byte LOOK_RIGHT
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x8a1604:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


ow_script_movs_0x8a1603:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


ow_script_map_3_1_trigger_1:
lockall
playsong MUS_VIOLET_ENCOUNTER 0x0
special SPECIAL_HEAL
applymovement 0x7f ow_script_movs_0x8a17e7
waitmovement 0x0

loadpointer 0 str_violet_grunt
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8a17ec
callstd MSG
special 0xF

sound 0x15
applymovement 0x3 ow_script_movs_0x8a17e3
applymovement 0x4 ow_script_movs_0x8a17e3
waitmovement 0x0

loadpointer 0 str_violet_grunt
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8a1608
callstd MSG
special 0xF
applymovement 0x3 ow_script_movs_0x8a1604
applymovement 0x7f ow_script_movs_0x8a1603
waitmovement 0x0
special 0x113
getplayerpos 0x8000 0x8001
compare 0x8001 0x1a
callif EQUAL ow_script_0x8a15f3
loadpointer 0 str_violet_grunt
setvar 0x8000 0
special 0xE
trainerbattlecont 0x1 0x4 0x3 str_before1 str_after1 ow_script_0x8a1433


ow_script_movs_0x8a14a9:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


ow_script_0x8a1433:
loadpointer 0 str_violet_grunt
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8a14b2
callstd MSG
special 0xF
applymovement 0x3 ow_script_movs_0x8a14a9
waitmovement 0x0
hidesprite 0x3
loadpointer 0 str_violet_grunt
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8a146b
callstd MSG
special 0xF
applymovement 0x4 ow_script_movs_0x8a14a9
waitmovement 0x0
hidesprite 0x4
goto ow_script_0x8a1af3


ow_script_movs_0x8a27a5:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STOP


ow_script_movs_0x8a1e5c:
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x8a1cc6:
.byte SAY_SMILE
.byte STOP


ow_script_movs_0x8a1c28:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


ow_script_0x8a1af3:
showsprite 0x5
getplayerpos 0x8000 0x8001
compare 0x8001 0x1a
callif EQUAL ow_script_0x8a27ae
applymovement 0x5 ow_script_movs_0x8a27a5
waitmovement 0x0
loadpointer 0x0 str_0x8f2375
show_mugshot MUGSHOT_LARISSA MUGSHOT_RIGHT
sound 0x15
applymovement 0x5 ow_script_movs_0x8a1e5c
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8f2c1e
show_mugshot MUGSHOT_LARISSA MUGSHOT_RIGHT
loadpointer 0x0 str_0x8a1cdd
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
sound 0x5
applymovement 0x5 ow_script_movs_0x8a1cc6
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8f2c62
show_mugshot MUGSHOT_LARISSA MUGSHOT_RIGHT
applymovement 0x5 ow_script_movs_0x8a1c28
waitmovement 0x0
hidesprite 0x5
setvar STORY_PROGRESS 0xc
releaseall
end


ow_script_movs_0x8a27ba:
.byte STEP_DOWN
.byte STOP


ow_script_0x8a27ae:
applymovement 0x5 ow_script_movs_0x8a27ba
waitmovement 0x0
return


ow_script_movs_0x8a15ff:
.byte STEP_DOWN
.byte LOOK_RIGHT
.byte STOP


ow_script_0x8a15f3:
applymovement 0x3 ow_script_movs_0x8a15ff
waitmovement 0x0
return


.ifdef LANG_GER

str_0x8a17ec:
    .autostring 35 2 "Beeilung jetzt!\pDie anderen sind längst in Silvania. Rin wird uns fertig machen, wenn wir noch mehr trödeln.\pAber mir kommt da eine geniale Idee.\pAuf dem Weg nach Silvania liegt das Labor von Professor Tann.\pAls Archäologe wird er sicher etwas über den Stein wissen, an dem Rin so interessiert ist.\pVielleicht bekommen wir aus ihm etwas nützliches heraus.\pDann hätten wir eine Entschuldigung, wenn Rin uns die Hölle heiß machtDOTS"



str_0x8a1608:
    .autostring 35 2 "Hey, du Rotzlöffel!\pHast du uns etwa belauscht?\pHast du denn überhaupt eine Ahnung, wer wir sind?\pWir, vom Team Violet, werden in Zukunft über Theto herrschen.\pDu solltest dich uns besser nicht in den Weg stellen!"


str_before1:
	.autostring 35 2 "Ich gebe dir einen Vorgeschmack darauf, was passiert, wenn man sich mit Team Violet anlegt!"



str_after1:
    .string "Ein Kind hat mich geschlagen?\nWie erniedrigend!"



str_0x8a14b2:
	.autostring 35 2 "Ich DOTS DOTS!\pWie konnte ich gegen einen Grünschnabel wie dich verlieren?\pDOTS DOTS DOTS\pDu hast uns schon zu viel Zeit gekostet.\pMerk dir unseren Namen!"


str_0x8a146b:
	.autostring 35 2 "Und DOTS DOTS DOTS\nIch habe keine Zeit, mich mit dir herumzuschlagen!"



str_0x8f2375:
	.autostring 35 2 "Eleganz, Anmut, Stärke!\pDu hast Talent, junger Trainer.\pTrotzdem bist du noch ein Neuling, werde nicht zu übermütig, dich mit den Schergen von Team Violet anzulegen.\pErlaube mir, mich vorzustellen.\pMein Name ist Larissa und zur Zeit bereise ich die Region, um mich mit ihr vertraut zu machen.\pDiese Leute, die du eben getroffen hast, gehören einer verbrecherischen Organisation namens Team Violet an.\pVor einiger Zeit sind sie wie aus dem Nichts erschienen und haben begonnen, Leute zu rekrutieren.\pIhre Versprechungen sind zahlreich und oft auch widersprüchlich.\pMancherorts werben sie mit der Herrschaft über die Region, anderswo versprechen sie Frieden.\pGefährlich ist diese Truppe aber allemal, findest du nicht?"


str_0x8f2c1e:
	.autostring 35 2 "Zögerst du etwa mit deiner Antwort?\pHabe ich mich wohl in dir getäuscht, als ich gemeint habe, etwas Heldenmut in deinen Augen aufleuchten zu sehen?"



str_0x8a1cdd:
	.autostring 35 2 "Nachdem ich ohnehin auch bereits in ihr Visier geraten bin, werde auch ich mich diesen Rüpeln von Team Violet in den Weg stellen, wo immer sie mir begegnen."


str_0x8f2c62:
	.autostring 35 2 "Wie nobel!\pAber sei vorsichtig, nicht alle Mitglieder von Team Violet sind so erbärmliche Gestalten wie die beiden eben.\pDie Kommandanten der Divisionen sind enorm gefährlich.\pÜberlasse diese Kaliber lieben der Polizei oder den Top Vier, verstanden?\pIch bin gespannt, ob wir uns wiedersehen, junger Trainer.\pWer weiß, vielleicht bringst du es zu wahrer Größe!"

str_violet_grunt:
	.string "Team Violet Rüpel"

.elseif LANG_EN

.endif


ow_script_movs_0x8dcf8a:
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x8dcf31:
.byte STEP_UP
.byte STEP_LEFT
.byte LOOK_UP
.byte STOP


ow_script_movs_0x8dcf2e:
.byte STEP_UP
.byte STOP


ow_script_map_3_1_trigger_2:
lockall
loadpointer 0 str_bewohner
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8dcf8d
callstd MSG_KEEPOPEN
special 0xF
loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8de230
callstd MSG_KEEPOPEN
special 0xF
sound 0x15
applymovement 0x28 ow_script_movs_0x8dcf8a
waitmovement 0x0
loadpointer 0 str_bewohner
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8dcf36
callstd MSG_KEEPOPEN
special 0xF
applymovement 0x28 ow_script_movs_0x8dcf31
waitmovement 0x0
setdooropened 0x2e 0x14
doorchange
applymovement 0x28 ow_script_movs_0x8dcf2e
waitmovement 0x0
hidesprite 0x28
setdoorclosed 0x2e 0x14
doorchange
loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8dcee9
callstd MSG
special 0xF
fadescreen 0x1
hidesprite 0x27
clearflag MERIANA_CITY_DUDE
fadescreen 0x0
addvar MERIANA_CITY_REVOLUTIONARY 0x1
releaseall
end


.ifdef LANG_GER


str_0x8dcf8d:
	.autostring 35 2 "Denken Sie, dass Sie damit durchkommen?\pWenn die Top Vier von Ihren schmutzigen Geschäften erfahrenDOTS"



str_0x8de230:
	.autostring 35 2 "Sie unterstellen der Polizei hier Ungeheuerliches!\pIch könnte Sie inhaftieren lassen für solche Anschuldingen!"


str_0x8dcf36:
    .autostring 35 2 "Inhaftieren?\pDOTS DOTS\pSchon gut, schon gut.\nSie haben gewonnen.\pIch lasse Sie in Ruhe!"



str_0x8dcee9:
    .autostring 35 2 "Dieser KerlDOTS\pIch sollte mich vielleicht um ihn kümmernDOTS"


.elseif LANG_EN

.endif


ow_script_movs_0x8e1841:
.byte LOOK_LEFT
.byte STOP


ow_script_movs_0x8e1745:
.byte LOOK_UP
.byte STOP


ow_script_movs_0x8e1742:
.byte FACE_DOWN
.byte STOP


ow_script_movs_0x8e162b:
.byte LOOK_RIGHT
.byte STOP


ow_script_movs_0x8e1521:
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x8e146d:
.byte STEP_RIGHT
.byte STOP


ow_script_map_3_1_trigger_3:
lockall
applymovement 0xff ow_script_movs_0x8e1841
waitmovement 0x0

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e17bd
callstd MSG_KEEPOPEN
special 0xF

loadpointer 0 str_revo
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8e1748
callstd MSG_KEEPOPEN
special 0xF

applymovement 0x2b ow_script_movs_0x8e1745
applymovement 0x29 ow_script_movs_0x8e1742
waitmovement 0x0

loadpointer 0 str_revo
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e1702
callstd MSG_KEEPOPEN
special 0xF

loadpointer 0 str_revo
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8e167c
callstd MSG_KEEPOPEN
special 0xF

loadpointer 0 str_revo
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e162e
callstd MSG_KEEPOPEN
special 0xF

applymovement 0x2b ow_script_movs_0x8e162b
applymovement 0x29 ow_script_movs_0x8e162b
waitmovement 0x0

loadpointer 0 str_revo
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8e15cc
callstd MSG_KEEPOPEN
special 0xF

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0 str_police_laughs
callstd MSG_KEEPOPEN
special 0xF

sound 0x15
applymovement 0x2a ow_script_movs_0x8e162b
waitmovement 0x0
applymovement 0x29 ow_script_movs_0x8e1521
applymovement 0x2a ow_script_movs_0x8e1521
applymovement 0x2b ow_script_movs_0x8e1521
waitmovement 0x0

loadpointer 0 str_revo
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e14fb
callstd MSG_KEEPOPEN
special 0xF

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e148e
callstd MSG_KEEPOPEN
special 0xF

getplayerpos 0x8000 0x8001
compare 0x8001 0x1e
callif EQUAL ow_script_0x8e1470
compare 0x8001 0x20
callif EQUAL ow_script_0x8e147c
applymovement 0x2a ow_script_movs_0x8e146d
waitmovement 0x0

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e12f8
callstd MSG_KEEPOPEN
special 0xF

applymovement 0x2a ow_script_movs_0x8e1841
waitmovement 0x0

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e11b9
callstd MSG_KEEPOPEN
special 0xF

applymovement 0x2a ow_script_movs_0x8e162b

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e0f79
callstd MSG_KEEPOPEN
special 0xF


loadpointer 0x0 str_0x8e0cdc
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT MSG_KEEPOPEN

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
trainerbattlecont 0x1 0x2c 0x0 str_0x8e0c9c str_0x8e0c71 ow_script_0x8e09cc

.align 4
meriana_revo_choice:
    .word str_meriana_revo_choice_0, 0
    .word str_meriana_revo_choice_1, 0



ow_script_movs_0x8e0c56:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


ow_script_0x8e09cc:

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e0c5e
callstd MSG_KEEPOPEN
special 0xF

showsprite 0x2c
showsprite 0x2d
applymovement 0x2c ow_script_movs_0x8e0c56
applymovement 0x2d ow_script_movs_0x8e0c56
waitmovement 0x0
applymovement 0x2a ow_script_movs_0x8e162b
waitmovement 0x0
sound 0x15
applymovement 0x29 ow_script_movs_0x8e1521
applymovement 0x2a ow_script_movs_0x8e1521
applymovement 0x2b ow_script_movs_0x8e1521
applymovement 0xff ow_script_movs_0x8e1521
waitmovement 0x0

loadpointer 0 str_polizist
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8e0b99
callstd MSG_KEEPOPEN
special 0xF

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e0b24
callstd MSG
special 0xF

fadescreen 0x1
hidesprite 0x29
hidesprite 0x2a
hidesprite 0x2b
hidesprite 0x2d
fadescreen 0x0
applymovement 0xff ow_script_movs_0x8e1d9e
waitmovement 0x0
applymovement 0x2c ow_script_movs_0x8e0b21
waitmovement 0x0

loadpointer 0 str_bewohner
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8e0aa8
callstd MSG
special 0xF

fadescreen 0x1
hidesprite 0x2c
fadescreen 0x0
setvar MERIANA_CITY_REVOLUTIONARY 3
setflag MERIANA_CITY_BLOCKING_REVOLUTIONARIES
releaseall
end


ow_script_movs_0x8e1d9e:
.byte LOOK_RIGHT
.byte STOP




ow_script_movs_0x8e0b21:
.byte STEP_LEFT
.byte STOP





ow_script_0x8e22eb:
loadpointer 0x0 str_0x8e0f0b
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT MSG_KEEPOPEN

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e0ef0
callstd MSG
special 0xF

pause 64

loadpointer 0 str_polizist
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8e0e4f
callstd MSG
special 0xF

fadescreen 0x1
hidesprite 0x2a
fadescreen 0x0
applymovement 0x2b ow_script_movs_0x8e1745
applymovement 0x29 ow_script_movs_0x8e1742
waitmovement 0x0

loadpointer 0 str_revo
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8e0e17
callstd MSG
special 0xF
fadescreen 0x1
hidesprite 0x2b
hidesprite 0x29
fadescreen 0x0
setvar MERIANA_CITY_REVOLUTIONARY 0x4
setflag MERIANA_CITY_BLOCKING_REVOLUTIONARIES
releaseall
end


ow_script_movs_0x8e148b:
.byte STEP_DOWN
.byte STOP


ow_script_0x8e147c:
applymovement 0x2a ow_script_movs_0x8e148b
waitmovement 0x0
return


ow_script_movs_0x8e1488:
.byte STEP_UP
.byte STOP


ow_script_0x8e1470:
applymovement 0x2a ow_script_movs_0x8e1488
waitmovement 0x0
return


.ifdef LANG_GER

str_polizist:
	.string "Polizist"

str_revo:
	.string "Revolutionär"

str_bewohner:
	.string "Bewohner"

str_0x8e17bd:
	.autostring 35 2 "Revolutionsbewegung, was?\pDass ihr mir in die Arme lauft, ist wirklich Glück!\pIch werde euch festnehmen und hinter Gitter bringen!\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pEs sei denn, natürlich, wir können uns auf anderen Wegen einig werdenDOTS"



str_0x8e1748:
	.autostring 35 2 "Bestechung?\nNiemals!\pWir sind Teil der Revolutionsbewegung und würden niemals unsere Ideale für Geld verkaufen!\pEher wandern wir ins Gefängnis, als selbst Teil dieser korrupten Welt zu werden!"


str_0x8e1702:
	.autostring 35 2 "Moment, Moment!\nIst das dein Ernst?\pWillst du wirklich ins Gefängnis gehen?\pWas würde deine Familie denken?"



str_0x8e167c:
	.autostring 35 2 "NunjaDOTS DOTS DOTS\pAber treten wir nicht für eine gerechtere Welt ein?\pWollen wir das alles aufgeben, um uns selbst zu retten?"



str_0x8e162e:
    .autostring 35 2 "Wir sind normale Bürger, keine HeldenDOTS\pSoll jemand anderes sein Leben irgendwelchen Idealen opfernDOTS\pIch will nicht den Rest meines Lebens eingesperrt verbringen."



str_0x8e15cc:
    .autostring 35 2 "In Ordnung, Polizist!\nWir nehmen dein Angebot an.\pWenn du uns laufen lässt, werden wir dich dafür entlohnen!"

str_police_laughs:
	.autostring 35 2 "Haha! So weit ist es also her mit euren noblen Zielen.\pWer kann es euch verübeln?\pDas ist, wie die Welt funktioniertDOTS DOTS DOTS"



str_0x8e14fb:
    .autostring 35 2 "He! Da belauscht uns jemand!"



str_0x8e148e:
    .autostring 35 2 "Oh je! Ein Zeuge!\nDOTS DOTS DOTS\pWas mache ich nun bloß mit dir?"



str_0x8e12f8:
	.autostring 35 2 "Du bist noch ein Kind, also lass mich dir begreiflch machen, wie unsere Welt eigentlich funktioniert.\pGanz oben stehen die Mächte, die Top Vier und ihr Champion.\pGemeinsam herrschen sie über Theto, wie immer es ihnen beliebt.\pUnd wir, die Polizei, bieten den Menschen im Gegenzug für diese Macht unseren Schutz.\pIst das nicht auch eine Form von Gerechtigkeit?\pSelbstverständlich, ist nicht alles in diesem System perfekt.\pSicherlich gibt es Ungerechtigkeiten hier und da."


str_0x8e11b9:
    .autostring 35 2 "Allerdings, wie sähe eine Welt aus, wie diese beiden Revolutionskämpfer sie sich wünschen?\pJeder dürfte tun und lassen, was immer er möchte.\pNiemand wäre mehr sicher.\nDOTS DOTS DOTS\pAnarchie und Chaos würden über unsere Welt hereinbrechen."


str_0x8e0f79:
	.autostring 35 2 "Und jetzt sag mir ehrlich, ob Menschen wie ich wirklich das Übel in dieser Welt sind oder nicht ein viel größeres Übel verhindern.\pWas sagst du, Kind?"



str_meriana_revo_choice_0:
    .string "Zustimmen"



str_meriana_revo_choice_1:
    .string "Widersprechen"



str_0x8e0cdc:
    .autostring 35 2 "Sie haben Unrecht!\nSich einfach hilflos dem System auszuliefern, ist keine Lösung.\pJeder muss selbst daran arbeiten, die Welt zu einem besseren Ort zu machen.\pIch werde Sie nicht mit ihren korrupten Geschäften durchkommen lassen!"



str_0x8e0c9c:
    .autostring 35 2 "Verdammtes Gör!\nDu bist eben doch nur ein naives Kind!\pAlso muss ich doch wohl oder übel bekämpfen!"



str_0x8e0c71:
    .autostring 35 2 "Verflucht! DOTS DOTS DOTS"



str_0x8e0c5e:
    .autostring 35 2 "Du einfältiges Kind!\pDenkst du, dass es klug ist, sich mit der Polizei anzulegen!"



str_0x8e0b99:
	.autostring 35 2 "Wachtmeister!\pIch wurde über Ihre korrupten Aktivitäten unterrichtet und wollte es nicht fassen.\pJetzt muss ich es jedoch mit eigenen Augen sehen!\pUngeheuerlich!\pSie sind verhaftet, alle drei!"


str_0x8e0b24:
    .autostring 35 2 "Verlogener Kerl!\pAls hättest du nicht selbst genauso viel Dreck am Stecken!\pAber ich werde keinen Widerstand leisten.\pSoll doch jemand anders sich um diese Welt kümmern DOTS DOTS DOTS"


str_0x8e0aa8:
    .autostring 35 2 "Danke dir tausend Mal!\pEndlich hat jemand diesen korrupten Wachtmeister zur Strecke gebracht.\pWenn es auch ein kleiner Beitrag war, hast du diese Stadt zu einem besseren Ort gemacht.\pWir Bewohner stehen alle in deiner Schuld."



str_0x8e0f0b:
    .autostring 35 2 "Vermutlich haben Sie RechtDOTS\pLassen Sie wenigstens die Revolutionäre laufen, wenn Sie selbst nicht den Schneid aufbringen können, etwas zum Besseren wenden zu wollen."



str_0x8e0ef0:
    .autostring 35 2 "Du bist nicht dumm, Kind.\pDu wirst sicher auch irgendwann merken, dass es nicht immer leicht ist, etwas zum Besseren zu wenden."


str_0x8e0e4f:
    .autostring 35 2 "Ganz im VertrauenDOTS\pEs ist nicht ratsam, sich mit den Top Vier oder denen, die ihnen unterstellt sind, anzulegen.\pSei klug genug, meinen Rat zu beherzigenDOTS DOTS DOTS"


str_0x8e0e17:
    .autostring 35 2 "Schnell, machen wir nuns aus dem Staub!"


.elseif LANG_EN

.endif