.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"

.global ow_script_0x8d3f43
.global ow_script_map_15_0_trigger_0
.global ow_script_0x8e22e1
.global ow_script_0x8bf102
.global ow_script_0x8d402a
.global ow_script_0x8bf01f
.global ow_script_0x8d3f37
.global ow_script_0x8d3691
.global ow_script_map_15_0_trigger_1
.global ow_script_0x8d3734
.global ow_script_0x8bf0c1
.global ow_script_0x8fb459
.global ow_script_0x8f7174
.global ow_script_0x8d35c7
.global ow_script_0x8bf158
.global ow_script_0x8d3f4d
.global ow_script_0x8d4033
.global ow_script_0x8bf0a0
.global ow_script_0x8bf12d

ow_script_0x8f7174:
//copyvarifnotzero 0x8000 ITEM_SONDERBONBON
//copyvarifnotzero 0x8001 ITEM_FINSTERSTEIN
//callstd ITEM_OBTAIN
end

ow_script_map_15_0_trigger_1:
setvar LASTTALKED 0x36
goto ow_script_0x8d35c7


ow_script_movs_0x8d3ef2:
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STOP


ow_script_0x8d35c7:

lockall
sound 0x15
applymovement 0xff mov_0
waitmovement 0x0
applymovement 0xff mov_x62
waitmovement 0x0
playsong MUS_BEGEGNUNG_MIT_TRAINER_GORE 0x0
showsprite 0x32
showsprite 0x33
showsprite 0x34
showsprite 0x35
showsprite 0x36
setvar 0x8004 0x36
special 0x1B
waitmovement 0
setvar LASTTALKED 0x36
faceplayer

setflag PKMNMENU
pause 32
draw_mugshot MUGSHOT_HARRENFELD MUGSHOT_RIGHT
settrainerflag 0x19
trainerbattlecont 0x1 0x19 0x0 str_0 str_1 ow_script_0x8d4033

mov_0:
.byte 0, STOP

mov_x62:
.byte 0x62, STOP

ow_script_0x8d4033:
applymovement 0x32 ow_script_movs_0x8d3ef2
applymovement 0x33 ow_script_movs_0x8d3ef2
applymovement 0x34 ow_script_movs_0x8d3ef2
applymovement 0x35 ow_script_movs_0x8d3ef2
waitmovement 0x0

loadpointer 0 str_police
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_2
callstd MSG
special 0xF

applymovement 0x36 mov_4
loadpointer 0x0 str_3
show_mugshot MUGSHOT_HARRENFELD MUGSHOT_RIGHT MSG
applymovement 0x36 mov_1
loadpointer 0x0 str_4
show_mugshot MUGSHOT_HARRENFELD MUGSHOT_RIGHT MSG
pause 0x40
sound 0x15
applymovement 0x36 mov_x62
waitmovement 0
loadpointer 0x0 str_5
show_mugshot MUGSHOT_HARRENFELD MUGSHOT_RIGHT MSG_YES_NO

compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8d3734
loadpointer 0x0 str_player_yes
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
loadpointer 0x0 str_harrenfeld_yes
show_mugshot MUGSHOT_HARRENFELD MUGSHOT_RIGHT
setvar 0x8006 0xa
goto ow_script_0x8d3691

mov_4:
.byte 4, STOP

mov_1:
.byte 1, STOP

ow_script_movs_0x8d36f5:
.byte FACE_DOWN
.byte STOP


ow_script_movs_0x8d36f1:
.byte STEP_IN_PLACE_UP
.byte STEP_IN_PLACE_UP
.byte STOP


ow_script_0x8d3691:
applymovement 0x36 ow_script_movs_0x8d36f5
waitmovement 0x0
loadpointer 0x0 str_6
show_mugshot MUGSHOT_HARRENFELD MUGSHOT_RIGHT
applymovement 0x32 ow_script_movs_0x8d36f1
applymovement 0x33 ow_script_movs_0x8d36f1
applymovement 0x34 ow_script_movs_0x8d36f1
applymovement 0x35 ow_script_movs_0x8d36f1
loadpointer 0 str_police
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_police2
callstd MSG
special 0xF
waitmovement 0x0
fadescreen 0x1
hidesprite 0x32
hidesprite 0x33
hidesprite 0x34
hidesprite 0x35
hidesprite 0x36
pause 0x20
goto ow_script_0x8d402a


ow_script_0x8d402a:
fadescreen 0x0
addvar STORY_PROGRESS 0x1
releaseall
end


ow_script_0x8d3734:
loadpointer 0x0 str_player_no
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
loadpointer 0x0 str_harrenfeld_no
show_mugshot MUGSHOT_HARRENFELD MUGSHOT_RIGHT
setvar 0x8006 0xfff5
goto ow_script_0x8e22e1


ow_script_0x8e22e1:
goto ow_script_0x8d3691


ow_script_0x8d3f4d:
singlemovement 0x36 0x20
waitmovement 0x0
return


ow_script_0x8d3f43:
singlemovement 0x36 0x1f
waitmovement 0x0
return


ow_script_0x8d3f37:
call ow_script_0x8d3f43
call ow_script_0x8d3f43
return


.ifdef LANG_GER

str_0:
    .autostring 34 2 "Hey du da!\nStehen geblieben!\pIch lasse euch von Team Violet keinen Fuß nach Silvania setzen!"
str_1:
    .autostring 34 2 "Uff!\nIch habe mich von einem Team Violet Rüpel überrumpeln lassenDOTS"
str_police:
	.string "Polizisten"
str_2:
    .autostring 34 2 "Junior-Komissar Harrenfeld, sind Sie verletzt?"
str_3:
    .autostring 34 2 "Dieser Team Violet Rüpel hier ist außerordentlich starkDOTS"
str_4:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pWobei du bei genauerer Betrachtung gar nicht aussiehst, wie ein Mitglied von Team VioletDOTS"
str_5:
    .autostring 34 2 "Wie bitte?\nDu bist gar kein Team Violet Rüpel?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDas tut mir schrecklich leidDOTS\pIch bin neu bei der Polizei von Theto und war wohl etwas übermütig in meiner DienstpflichtDOTS\pWir sind auf der Jagd nach Rin, einer Kommandantin von Team Violet.\pDie Kommandanten dieser Organisation sind nicht zu unterschätzen, musst du wissen.\pUnd wenn wir einen von ihnen dingfest machen können, finden wir vielleicht etwas über den Kopf der Organisation heraus.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDu scheinst ein ganz passabler Trainer zu sein.\pDeine Unterstützung im Kampf gegen diese Rüpel könnte entscheidend sein.\pIch weiß, ich überrumple dich sicherlich mit dieser Bitte, aber würdest du uns helfen, Rin zu bekämpfen?"
str_player_yes:
	.autostring 34 2 "Team Violet ist Professor Tann, den Vater meines besten Freundes angegangen.\pWenn ich helfen kann, diese Bande zu stoppen, kannst du mit meiner Hilfe rechnen."
str_harrenfeld_yes:
    .autostring 34 2 "Du bist wirklich unglaublich!\pDie gesamte Polizei von Theto steht zutiefst in deiner Schuld!"
str_player_no:
    .autostring 34 2 "Erst greifst du mich unüberlegt an und dann hast du die Frechheit, mich um meine Unterstützung zu fragen?"
str_harrenfeld_no:
    .autostring 34 2 "Was?\nDOTS DOTS DOTS\pMit dieser Antwort habe nich nun wirklich nicht gerechnetDOTS\pAber ich verstehe schon!\pIch kann es dir nicht übel nehmen.\pDie Kommandanten von Team Violet sind wirklich angsteinflößende Trainer und es bedarf mutigen Menschen, sie zu stoppen.\pImmerhin ist es ja auch gerade meine Pflicht, diesen Gesetzlosen entgegenzutreten."
str_6:
    .autostring 34 2 "Alles klar!\nAuf nach Silvania!\pRin von Team Violet muss gestoppt werden!\pWir dürfen keine Zeit verlieren!"
str_police2:
    .autostring 34 2 "Verstanden, Junior-Kommissar Harrenfeld!"

.elseif LANG_EN
str_0:
    .autostring 34 2 "Hey you!\nHalt immediately!\pI won't let you Team Violet guys set a foot into Silvania!"
str_1:
    .autostring 34 2 "Yikes!\nI have been defeated by one of those Violet guysDOTS"
str_police:
    .string "Policemen"
str_2:
    .autostring 34 2 "Junior comissioner Harrenfield, are you injured?"
str_3:
    .autostring 34 2 "This Team Violet grunt is pretty strongDOTS"
str_4:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pThen again you do not look like a member of Team Violet on second glanceDOTS"
str_5:
    .autostring 34 2 "Come again?\nYou are not a member of Team Violet?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pI am so terribly sorryDOTS\pI am new at the police of Theto and probably too reckless in my new dutiesDOTS\pWe are currently chasing down Rin, a commander of Team Violet.\pThe commanders of this organization are not to be underestimated.\pAnd if we can hunt down on of them we might get information on the head of this group.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pYou seem to be a somewhat passable trainer.\pYour help in fighting against those grunts could be decisive.\pI know I am overwhelming you probably with this request but would maybe help us to fight Rin?"
str_player_yes:
    .autostring 34 2 "Team Violet already attacked Professor Tann, the father of my best friend.\pIf I can help stopping these guys you can count on my help."
str_harrenfeld_yes:
    .autostring 34 2 "You really are amazing!\pThe entire police of Theto is deeply indebted to you!"
str_player_no:
    .autostring 34 2 "First you attack me without second consideration and then you have the audacity to request my support?"
str_harrenfeld_no:
    .autostring 34 2 "What?\nDOTS DOTS DOTS\pI did not expect this answer.\pBut I do understand.\pI have to admit that you are right.\pThe commanders of Team Violet really are fearsome trainers and it demands a bold and brave man to stop them.\pFurthermore, it even is my very duty to put a hold to the crimes of those people."
str_6:
    .autostring 34 2 "All set!\nLet's go to Silvania!\pRin of Team Violet has to be stopped.\pWe mustn't lose any more time!"
str_police2:
    .autostring 34 2 "Alright, junior comissioner Harrenfield!"

.endif


ow_script_map_15_0_trigger_0:
lockall
sound 0x15
applymovement 0x48 ow_script_movs_0x8fbc24
waitmovement 0x0
goto ow_script_0x8bf01f


ow_script_movs_0x8fbc24:
.byte SAY_EXCLAM
.byte STOP


ow_script_0x8bf01f:
loadpointer 0x0 str_0x8bf724
show_mugshot MUGSHOT_MAY MUGSHOT_LEFT
setvar 0x8004 0x48
setvar LASTTALKED 0x48
special 0x1b
waitmovement 0x0
faceplayer
draw_mugshot MUGSHOT_MAY MUGSHOT_LEFT
loadpointer 0x0 str_0x8bf610
callstd MSG_KEEPOPEN
multichoice 8 8 0 1
hide_mugshot
compare LASTRESULT 0x1
callif EQUAL ow_script_0x8bf0a0
goto ow_script_0x8bf0c1


ow_script_0x8bf0c1:
compare STARTER_SELECTED 0x0
gotoif EQUAL ow_script_0x8bf102
compare STARTER_SELECTED 0x1
gotoif EQUAL ow_script_0x8bf12d
draw_mugshot MUGSHOT_MAY MUGSHOT_LEFT
trainerbattlecont 0x1 0x2b 0x0 str_0x8bf5bc str_0x8bf5d1 ow_script_0x8bf158


ow_script_0x8bf158:
loadpointer 0x0 str_0x8bf3f9
show_mugshot MUGSHOT_MAY MUGSHOT_LEFT
additem ITEM_KARTE 0x1
fanfare 0x13e
loadpointer 0x0 str_0x8bf3dc
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
loadpointer 0x0 str_0x8bf2f0
show_mugshot MUGSHOT_MAY MUGSHOT_LEFT
fadescreen 0x1
hidesprite 0x48
fadescreen 0x0
goto ow_script_0x8fb459


ow_script_0x8fb459:
addvar STORY_PROGRESS 0x1
releaseall
end


ow_script_0x8bf12d:
draw_mugshot MUGSHOT_MAY MUGSHOT_LEFT
trainerbattlecont 0x1 0x2a 0x0 str_0x8bf5bc str_0x8bf5d1 ow_script_0x8bf158


ow_script_0x8bf102:
draw_mugshot MUGSHOT_MAY MUGSHOT_LEFT
trainerbattlecont 0x1 0x29 0x0 str_0x8bf5bc str_0x8bf5d1 ow_script_0x8bf158


ow_script_0x8bf0a0:
draw_mugshot MUGSHOT_MAY MUGSHOT_LEFT
loop:
loadpointer 0x0 str_0x8bf745
callstd MSG_KEEPOPEN
multichoice 8 8 0 1
compare LASTRESULT 0x1
gotoif EQUAL loop
goto ow_script_0x8bf0c1


.ifdef LANG_GER

str_0x8bf724:
    .string "PLAYER!"



str_0x8bf610:
	.autostring 35 2 "Bist du etwa auf dem Weg nach Silvania?\pDa wirst du dich etwas gedulden müssen, denn aus der Farm im Norden sind die Voltilamm entlaufen und blockieren den Weg.\pDOTS DOTS DOTS\pAber weißt duDOTS\pDOTSwir könnten doch solangeDOTS\pDOTS einen Kampf austragen, meinst du nicht?"


str_0x8bf5bc:
    .autostring 35 2 "Vielleicht bin ich ja diesmal stark genug, einen schwierigen Kampf zu gewinnenDOTS"



str_0x8bf5d1:
    .autostring 35 2 "DOTS DOTS DOTS\nErneut eine NiederlageDOTS"



str_0x8bf3f9:
    .autostring 35 2 "Irgendwie hatte ich schon erwartet, dass du mich besiegst, PLAYERDOTS\pIch bin einfach ein lausiger TrainerDOTS DOTS DOTS\pAnstatt hier zu warten, bis die Farmer ihre Voltilamm wieder eingefangen haben, könntest du einen Abstecher in Aktania machen.\pDie Leute von der Farm betreiben einen Flugservice, sodass du die Insel leicht erreichen kannst.\pSieh dir am besten auf dieser Karte an, wohin sie dich bringen."


str_0x8bf3dc:
    .autostring 35 2 "PLAYER erhält eine Karte."



str_0x8bf2f0:
    .autostring 35 2 "Aktania liegt nördlich von hier.\pMit dem Flugservice der Farmer solltest du die Insel sehr schnell erreichen.\pDort befindet sich auch eine Arena, die du herausfordern kannst.\pIch traue mir das allerdings nach meiner Niederlage nicht mehr zuDOTS\pIch weiß wirklich nicht, ob ich das Zeug zum Trainer habe, PLAYERDOTS\pUnd ich will meinen Freund aus Hoenn nicht enttäuschen, weißt duDOTS DOTS DOTS\pDer Druck istDOTS DOTS DOTS\pEgal, lassen wir dasDOTS\pDOTS DOTS DOTS\pEs war schön, dich wiederzusehen, PLAYER.\pHalt die Ohren steif!"



str_0x8bf745:
	.autostring 35 2 "PLAYERDOTS DOTS DOTS\pBitte, dieser Kampf könnte mir ein bisschen Selbstvertrauen verschaffenDOTS\pUnd das kann ich sehr gut gebrauchenDOTS"

.elseif LANG_EN

.endif