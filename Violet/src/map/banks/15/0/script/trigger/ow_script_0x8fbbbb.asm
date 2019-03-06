.include "movements.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x8fbbbb
ow_script_0x8fbbbb:
lockall
sound 0x15
applymovement 0x48 ow_script_movs_0x8fbc24
waitmovement 0x0
goto ow_script_0x8bf01f


.global ow_script_movs_0x8fbc24
ow_script_movs_0x8fbc24:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8bf01f
ow_script_0x8bf01f:
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bf724
callstd MSG
special 0x7
setvar 0x8004 0x48
setvar LASTTALKED 0x48
special 0x1b
waitmovement 0x0
faceplayer
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bf610
callstd MSG_KEEPOPEN
multichoice 8 8 0 1
special 0x7
compare LASTRESULT 0x1
callif EQUAL ow_script_0x8bf0a0
goto ow_script_0x8bf0c1


.global ow_script_0x8bf0c1
ow_script_0x8bf0c1:
compare STARTER_SELECTED 0x0
gotoif EQUAL ow_script_0x8bf102
compare STARTER_SELECTED 0x1
gotoif EQUAL ow_script_0x8bf12d
call ow_script_0x8bf7fb
trainerbattlecont 0x1 0x2b 0x0 str_0x8bf5bc str_0x8bf5d1 ow_script_0x8bf158


.global ow_script_0x8bf158
ow_script_0x8bf158:
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bf3f9
callstd MSG
special 0x7
additem ITEM_KARTE 0x1
fanfare 0x13e
loadpointer 0x0 str_0x8bf3dc
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bf2f0
callstd MSG
special 0x7
fadescreen 0x1
hidesprite 0x48
fadescreen 0x0
goto ow_script_0x8fb459


.global ow_script_0x8fb459
ow_script_0x8fb459:
addvar STORY_PROGRESS 0x1
releaseall
end


.global ow_script_0x8bf7fb
ow_script_0x8bf7fb:
setvar 0x8000 0x0
setvar 0x8001 0x8
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x8bf12d
ow_script_0x8bf12d:
call ow_script_0x8bf7fb
trainerbattlecont 0x1 0x2a 0x0 str_0x8bf5bc str_0x8bf5d1 ow_script_0x8bf158


.global ow_script_0x8bf102
ow_script_0x8bf102:
call ow_script_0x8bf7fb
trainerbattlecont 0x1 0x29 0x0 str_0x8bf5bc str_0x8bf5d1 ow_script_0x8bf158


.global ow_script_0x8bf0a0
ow_script_0x8bf0a0:
call ow_script_0x8bf7fb
loop:
loadpointer 0x0 str_0x8bf745
callstd MSG_KEEPOPEN
multichoice 8 8 0 1
compare LASTRESULT 0x1
gotoif EQUAL loop
goto ow_script_0x8bf0c1


.ifdef LANG_GER
.global str_0x8bf724

str_0x8bf724:
    .string "PLAYER!"
        
        
.global str_0x8bf610

str_0x8bf610:
	.autostring 35 2 "Bist du etwa auf dem Weg nach Silvania?\pDa wirst du dich etwas gedulden müssen, denn aus der Farm im Norden sind die Voltilamm entlaufen und blockieren den Weg.\pDOTS DOTS DOTS\pAber weißt duDOTS\pDOTSwir könnten doch solangeDOTS\pDOTS einen Kampf austragen, meinst du nicht?"

.global str_0x8bfe09

str_0x8bf5bc:
    .autostring 35 2 "Vielleicht bin ich ja diesmal stark genug, einen schwierigen Kampf zu gewinnenDOTS"
        
        
.global str_0x8bf5d1

str_0x8bf5d1:
    .autostring 35 2 "DOTS DOTS DOTS\nErneut eine NiederlageDOTS"
        
        
.global str_0x8bf3f9

str_0x8bf3f9:
    .autostring 35 2 "Irgendwie hatte ich schon erwartet, dass du mich besiegst, PLAYERDOTS\pIch bin einfach ein lausiger TrainerDOTS DOTS DOTS\pAnstatt hier zu warten, bis die Farmer ihre Voltilamm wieder eingefangen haben, könntest du einen Abstecher in Aktania machen.\pDie Leute von der Farm betreiben einen Flugservice, sodass du die Insel leicht erreichen kannst.\pSieh dir am besten auf dieser Karte an, wohin sie dich bringen."
        
.global str_0x8bf3dc

str_0x8bf3dc:
    .autostring 35 2 "PLAYER erhält eine Karte."
        
        
.global str_0x8bf2f0

str_0x8bf2f0:
    .autostring 35 2 "Aktania liegt nördlich von hier.\pMit dem Flugservice der Farmer solltest du die Insel sehr schnell erreichen.\pDort befindet sich auch eine Arena, die du herausfordern kannst.\pIch traue mir das allerdings nach meiner Niederlage nicht mehr zuDOTS\pIch weiß wirklich nicht, ob ich das Zeug zum Trainer habe, PLAYERDOTS\pUnd ich will meinen Freund aus Hoenn nicht enttäuschen, weißt duDOTS DOTS DOTS\pDer Druck istDOTS DOTS DOTS\pEgal, lassen wir dasDOTS\pDOTS DOTS DOTS\pEs war schön, dich wiederzusehen, PLAYER.\pHalt die Ohren steif!"
        
        
.global str_0x8bf745

str_0x8bf745:
	.autostring 35 2 "PLAYERDOTS DOTS DOTS\pBitte, dieser Kampf könnte mir ein bisschen Selbstvertrauen verschaffenDOTS\pUnd das kann ich sehr gut gebrauchenDOTS"

.elseif LANG_EN

.endif
