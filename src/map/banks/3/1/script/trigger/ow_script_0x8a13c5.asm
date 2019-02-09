.include "songs.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_movs_0x8a17e7
ow_script_movs_0x8a17e7:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x8a17e3
ow_script_movs_0x8a17e3:
.byte LOOK_RIGHT
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8a1604
ow_script_movs_0x8a1604:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a1603
ow_script_movs_0x8a1603:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8a13c5
ow_script_0x8a13c5:
lockall
playsong MUS_VIOLET_ENCOUNTER 0x0
special 0x0
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
trainerbattlecont 0x1 0x4 0x0 str_0x8a158f str_0x8a15bf ow_script_0x8a1433


.global ow_script_movs_0x8a14a9
ow_script_movs_0x8a14a9:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_0x8a1433
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


.global ow_script_movs_0x8a27a5
ow_script_movs_0x8a27a5:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8a1e5c
ow_script_movs_0x8a1e5c:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8a1cc6
ow_script_movs_0x8a1cc6:
.byte SAY_SMILE
.byte STOP


.global ow_script_movs_0x8a1c28
ow_script_movs_0x8a1c28:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_0x8a1af3
ow_script_0x8a1af3:
showsprite 0x5
getplayerpos 0x8000 0x8001
compare 0x8001 0x1a
callif EQUAL ow_script_0x8a27ae
applymovement 0x5 ow_script_movs_0x8a27a5
waitmovement 0x0
call ow_script_0x8a2791
loadpointer 0x0 str_0x8f2375
callstd MSG
special 0x7
sound 0x15
applymovement 0x5 ow_script_movs_0x8a1e5c
waitmovement 0x0
checksound
call ow_script_0x8a2791
loadpointer 0x0 str_0x8f2c1e
callstd MSG
special 0x7
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8a1cdd
callstd MSG
special 0x7
sound 0x5
applymovement 0x5 ow_script_movs_0x8a1cc6
waitmovement 0x0
checksound
call ow_script_0x8a2791
loadpointer 0x0 str_0x8f2c62
callstd MSG
special 0x7
applymovement 0x5 ow_script_movs_0x8a1c28
waitmovement 0x0
hidesprite 0x5
setvar STORY_PROGRESS 0xc
releaseall
end


.global ow_script_0x8a2791
ow_script_0x8a2791:
setvar 0x8000 0x1
setvar 0x8001 0x17
setvar 0x8002 0xe
special 0x6
return


.global ow_script_movs_0x8a27ba
ow_script_movs_0x8a27ba:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x8a27ae
ow_script_0x8a27ae:
applymovement 0x5 ow_script_movs_0x8a27ba
waitmovement 0x0
return


.global ow_script_movs_0x8a15ff
ow_script_movs_0x8a15ff:
.byte STEP_DOWN
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x8a15f3
ow_script_0x8a15f3:
applymovement 0x3 ow_script_movs_0x8a15ff
waitmovement 0x0
return


.ifdef LANG_GER
.global str_0x8a17ec

str_0x8a17ec:
    .autostring 35 2 "Beeilung jetzt!\pDie anderen sind längst in Silvania. Rin wird uns fertig machen, wenn wir noch mehr trödeln.\pAber mir kommt da eine geniale Idee.\pAuf dem Weg nach Silvania liegt das Labor von Professor Tann.\pAls Archäologe wird er sicher etwas über den Stein wissen, an dem Rin so interessiert ist.\pVielleicht bekommen wir aus ihm etwas nützliches heraus.\pDann hätten wir eine Entschuldigung, wenn Rin uns die Hölle heiß machtDOTS"

        
.global str_0x8a1608

str_0x8a1608:
    .autostring 35 2 "Hey, du Rotzlöffel!\pHast du uns etwa belauscht?\pHast du denn überhaupt eine Ahnung, wer wir sind?\pWir, vom Team Violet, werden in Zukunft über Theto herrschen.\pDu solltest dich uns besser nicht in den Weg stellen!"
        
.global str_0x8a158f

str_0x8a158f:
	.autostring 35 2 "Ich gebe dir einen Vorgeschmack darauf, was passiert, wenn man sich mit Team Violet anlegt!"
        
        
.global str_0x8a15bf

str_0x8a15bf:
    .string "Ein Kind hat mich geschlagen?\nWie erniedrigend!"
        
        
.global str_0x8a14b2

str_0x8a14b2:
	.autostring 35 2 "Ich DOTS DOTS!\pWie konnte ich gegen einen Grünschnabel wie dich verlieren?\pDOTS DOTS DOTS\pDu hast uns schon zu viel Zeit gekostet.\pMerk dir unseren Namen!"
        
.global str_0x8a146b

str_0x8a146b:
	.autostring 35 2 "Und DOTS DOTS DOTS\nIch habe keine Zeit, mich mit dir herumzuschlagen!"
        
        
.global str_0x8f2375

str_0x8f2375:
	.autostring 35 2 "Eleganz, Anmut, Stärke!\pDu hast Talent, junger Trainer.\pTrotzdem bist du noch ein Neuling, werde nicht zu übermütig, dich mit den Schergen von Team Violet anzulegen.\pErlaube mir, mich vorzustellen.\pMein Name ist Larissa und zur Zeit bereise ich die Region, um mich mit ihr vertraut zu machen.\pDiese Leute, die du eben getroffen hast, gehören einer verbrecherischen Organisation namens Team Violet an.\pVor einiger Zeit sind sie wie aus dem Nichts erschienen und haben begonnen, Leute zu rekrutieren.\pIhre Versprechungen sind zahlreich und oft auch widersprüchlich.\pMancherorts werben sie mit der Herrschaft über die Region, anderswo versprechen sie Frieden.\pGefährlich ist diese Truppe aber allemal, findest du nicht?"
        
.global str_0x8f2c1e

str_0x8f2c1e:
	.autostring 35 2 "Zögerst du etwa mit deiner Antwort?\pHabe ich mich wohl in dir getäuscht, als ich gemeint habe, etwas Heldenmut in deinen Augen aufleuchten zu sehen?"
        
        
.global str_0x8a1cdd

str_0x8a1cdd:
	.autostring 35 2 "Nachdem ich ohnehin auch bereits in ihr Visier geraten bin, werde auch ich mich diesen Rüpeln von Team Violet in den Weg stellen, wo immer sie mir begegnen."
        
.global str_0x8f2c62

str_0x8f2c62:
	.autostring 35 2 "Wie nobel!\pAber sei vorsichtig, nicht alle Mitglieder von Team Violet sind so erbärmliche Gestalten wie die beiden eben.\pDie Kommandanten der Divisionen sind enorm gefährlich.\pÜberlasse diese Kaliber lieben der Polizei oder den Top Vier, verstanden?\pIch bin gespannt, ob wir uns wiedersehen, junger Trainer.\pWer weiß, vielleicht bringst du es zu wahrer Größe!"
        
str_violet_grunt:
	.string "Team Violet Rüpel"

.elseif LANG_EN

.endif
