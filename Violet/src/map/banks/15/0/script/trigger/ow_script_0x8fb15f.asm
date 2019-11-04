.include "flags.s"
.include "songs.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "mugshot.s"

.global ow_script_0x8fb15f
ow_script_0x8fb15f:
setvar LASTTALKED 0x36
goto ow_script_0x8d35c7


.global ow_script_movs_0x8d3ef2
ow_script_movs_0x8d3ef2:
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STOP


.global ow_script_0x8d35c7
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

.global ow_script_0x8d4033
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

.global ow_script_movs_0x8d36f5
ow_script_movs_0x8d36f5:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8d36f1
ow_script_movs_0x8d36f1:
.byte STEP_IN_PLACE_UP
.byte STEP_IN_PLACE_UP
.byte STOP


.global ow_script_0x8d3691
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


.global ow_script_0x8d402a
ow_script_0x8d402a:
fadescreen 0x0
addvar STORY_PROGRESS 0x1
releaseall
end


.global ow_script_0x8d3734
ow_script_0x8d3734:
loadpointer 0x0 str_player_no
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
loadpointer 0x0 str_harrenfeld_no
show_mugshot MUGSHOT_HARRENFELD MUGSHOT_RIGHT
setvar 0x8006 0xfff5
goto ow_script_0x8e22e1


.global ow_script_0x8e22e1
ow_script_0x8e22e1:
goto ow_script_0x8d3691


.global ow_script_0x8d3f4d
ow_script_0x8d3f4d:
singlemovement 0x36 0x20
waitmovement 0x0
return


.global ow_script_0x8d3f43
ow_script_0x8d3f43:
singlemovement 0x36 0x1f
waitmovement 0x0
return


.global ow_script_0x8d3f37
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
