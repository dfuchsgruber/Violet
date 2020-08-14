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

ow_script_0x8f7174:
end

ow_script_map_15_0_trigger_1:
addvar STORY_PROGRESS 1
end

/**
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
 */


mov_exclam:
    .byte SAY_EXCLAM, STOP
mov_fu:
    .byte LOOK_UP, STOP
mov_cam_down:
    .byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP
mov_cam_up:
    .byte STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_fd:
    .byte LOOK_DOWN, STOP
mov_fl:
    .byte LOOK_LEFT, STOP
mov_fr:
    .byte LOOK_RIGHT, STOP
mov_say_smile:
    .byte SAY_SMILE, STOP
mov_exclam_and_fu:
    .byte LOOK_UP, SAY_EXCLAM, STOP
mov_1u:
    .byte STEP_UP, STOP
mov_1r_fu:
    .byte STEP_RIGHT, LOOK_UP, STOP

.equ PERSON_MAY, 12
.equ PERSON_LARISSA, 60

ow_script_map_15_0_trigger_0:
    lockall
    sound 0x15
    applymovement 0xFF mov_fu
    applymovement PERSON_MAY mov_exclam
    waitmovement 0x0

    loadpointer 0x0 str_may_0
    show_mugshot MUGSHOT_MAY MUGSHOT_LEFT message_type=MSG
    setvar 0x8004 PERSON_MAY
    setvar LASTTALKED PERSON_MAY
    special SPECIAL_NPC_MOVE_TO_PLAYER
    waitmovement 0x0

    faceplayer
    loadpointer 0x0 str_may_1
    show_mugshot MUGSHOT_MAY MUGSHOT_LEFT message_type=MSG_KEEPOPEN hide_mugshot=0
    update_mugshot_emotion MUGSHOT_SAD
    loadpointer 0 str_may_2
    callstd MSG_KEEPOPEN
    multichoice 8 8 0 1
    compare LASTRESULT 1
    gotoif EQUAL said_no
accept_challange:
    update_mugshot_emotion MUGSHOT_NORMAL
    ow_script_0x8bf0c1:
    compare STARTER_SELECTED 0x0
    gotoif EQUAL starter_plant
    compare STARTER_SELECTED 0x1
    gotoif EQUAL starter_fire
starter_water:
    trainerbattlecont 0x1 0x2b 0x0 str_may_before str_may_after may_later
starter_fire:
    trainerbattlecont 0x1 0x2a 0x0 str_may_before str_may_after may_later
starter_plant:
    trainerbattlecont 0x1 0x29 0x0 str_may_before str_may_after may_later

may_later:
    loadpointer 0 str_may_4
    show_mugshot MUGSHOT_MAY MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_SAD
    pause 24
    loadpointer 0 str_larissa_1
    show_mugshot MUGSHOT_LARISSA MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_HAPPY
    sound 0x15
    applymovement 0xFF mov_exclam_and_fu
    applymovement PERSON_MAY mov_exclam_and_fu
    waitmovement 0
    checksound
    pause 16
    special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
    applymovement 0xFF mov_1u
    applymovement PERSON_MAY mov_1r_fu
    applymovement 0x7F mov_cam_up
    waitmovement 0
    pause 16
    applymovement 0x7F mov_cam_down
    setvar 0x8004 PERSON_LARISSA
    special SPECIAL_NPC_MOVE_TO_PLAYER
    waitmovement 0
    setvar LASTTALKED PERSON_LARISSA
    faceplayer
    special SPECIAL_OVERWORLD_VIEWPORT_LOCK
    loadpointer 0 str_larissa_2
    show_mugshot MUGSHOT_LARISSA MUGSHOT_LEFT message_type=MSG
    applymovement PERSON_MAY mov_fl
    waitmovement 0
    loadpointer 0 str_may_5
    show_mugshot MUGSHOT_MAY MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_ANNOYED
    applymovement PERSON_MAY mov_fu
    waitmovement 0
    loadpointer 0 str_larissa_3
    show_mugshot MUGSHOT_LARISSA MUGSHOT_LEFT message_type=MSG
    loadpointer 0 str_may_6
    show_mugshot MUGSHOT_MAY MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_SAD
    loadpointer 0 str_may_7
    show_mugshot MUGSHOT_MAY MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_ANGRY
    loadpointer 0 str_larissa_4
    show_mugshot MUGSHOT_LARISSA MUGSHOT_LEFT message_type=MSG_KEEPOPEN hide_mugshot=0 emotion=MUGSHOT_ANGRY
    update_mugshot_emotion MUGSHOT_NORMAL
    loadpointer 0 str_larissa_5
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_RUMINATIVE
    loadpointer 0 str_larissa_6
    callstd MSG_KEEPOPEN
    hide_mugshot
    closeonkeypress
    pause 16
    fanfare 0x13E
    loadpointer 0 str_karte
    callstd MSG_KEEPOPEN
    waitfanfare
    pause 16
    loadpointer 0 str_larissa_7
    show_mugshot MUGSHOT_LARISSA MUGSHOT_LEFT message_type=MSG_KEEPOPEN hide_mugshot=0 emotion=MUGSHOT_NORMAL
    update_mugshot_emotion MUGSHOT_HAPPY
    loadpointer 0 str_larissa_8
    callstd MSG_KEEPOPEN
    hide_mugshot
    closeonkeypress
    pause 32
    sound 0x15
    applymovement PERSON_LARISSA mov_say_smile
    waitmovement 0
    checksound
    loadpointer 0 str_larissa_9
    show_mugshot MUGSHOT_LARISSA MUGSHOT_LEFT message_type=MSG hide_mugshot=1 emotion=MUGSHOT_HAPPY
    pause 16
    setvar 0x8004 PERSON_LARISSA
    setvar 0x8005 0x2d
    setvar 0x8006 0x3f
    special SPECIAL_NPC_MOVE_TO
    waitmovement 0
    applymovement 0xFF mov_fd
    applymovement PERSON_MAY mov_fd
    waitmovement 0
    applymovement PERSON_LARISSA mov_cam_down
    waitmovement 0
    hidesprite PERSON_LARISSA
    pause 32
    applymovement 0xFF mov_fr
    applymovement PERSON_MAY mov_fl
    waitmovement 0
    loadpointer 0 str_may_8
    show_mugshot MUGSHOT_MAY MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY hide_mugshot=0
    update_mugshot_emotion MUGSHOT_ANNOYED
    loadpointer 0 str_may_9
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_NORMAL
    loadpointer 0 str_may_10
    callstd MSG_KEEPOPEN
    hide_mugshot
    closeonkeypress
    applymovement PERSON_MAY mov_cam_up
    waitmovement 0
    hidesprite PERSON_MAY
    addvar STORY_PROGRESS 1
    releaseall
    end    

said_no:
    update_mugshot_emotion MUGSHOT_SHOCKED
    loadpointer 0 str_may_decline
    callstd MSG_KEEPOPEN
    multichoice 8 8 0 1
    compare LASTRESULT 1
    gotoif EQUAL said_no
    goto accept_challange


.ifdef LANG_GER

str_may_0:
    .string "PLAYER!"
str_may_1:
    .autostring 34 2 "Es ist wirklich schön, dich endlich wiederzusehen.\pSeit wir die Trainerschule abgeschlossen haben, ist einiges passiert, was?\pDu bist bestimmt sehr stark geworden!"
str_may_2:
    .autostring 34 2 "Ich habe wirklich hart an mir gearbeitet, PLAYER.\pIch habe viel trainiert, um endlich zu dir und all den anderen aufzuholen.\pIch würde gerne gegen dich kämpfen, was sagst du, PLAYER?"
str_may_decline:
    .autostring 34 2 "Was, wirklich?\pEs würde mir wirklich viel bedeuten, wenn du gegen mich antreten könntest, PLAYER.\pWas sagst du?"
str_may_before:
    .autostring 35 2 "Jetzt muss ich mich beweisen!\pIch werde alles geben und dir zeigen, dass auch ich das Zeug zum Trainer habe!"
str_may_after:
    .autostring 35 2 "DOTS DOTS DOTS\nEine NiederlageDOTS"
str_may_3:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pTrotz meiner harten Arbeit habe ich gegen dich verlorenDOTS"
str_may_4:
    .autostring 34 2 "Es bleibt wohl alles so, wie es immer gewesen ist, was?\pEgal wie sehr ich mich auch anstrenge, ich werde niemals zu RIVAL oder dir aufholen können.\pIch habe einfach nicht das gewisse Etwas, das einen großartigen Trainer ausmacht, schätze ich."
str_larissa_1:
    .autostring 34 2 "Bravo!\nBravissimo!"
str_larissa_2:
    .autostring 34 2 "Ihr beiden habt wirklich fantastisch gekämpft.\pIch wusste doch gleich, als ich dich in Blütenbach getroffen habe, PLAYER, dass du Talent besitzt.\pUnd du, Mädchen, solltest dich nicht selbst so fertig machen, nur weil du einen Kampf verloren hast.\pNiederlagen gehören zum Alltag eines Trainers.\pNur aus ihnen lernen wir und können besser werden.\pNoch dazu hast du dich sehr gut geschlagen.\pUnd ich weiß, wovon ich rede."
str_may_5:
    .autostring 34 2 "Wer ist das, PLAYER?\pKennst du die Frau?"
str_larissa_3:
    .autostring 34 2 "Natürlich, wie unhöflich von mir.\pMein Name ist Larissa und dein Freund PLAYER und ich sind uns erst vor Kurzem ganz zufällig in Blütenbach begegnet.\pIch wusste damals gleich, dass er das Zeug zum Trainer hat.\pUnd du, Kleine, hättest auch Potential, wenn du etwas mehr an deine eigenen Fähigkeiten glauben würdest!"
str_may_6:
    .autostring 34 2 "Wer's glaubtDOTS"
str_may_7:
    .autostring 34 2 "Ich habe meine schwierigen Kämpfe immer in den Sand gesetzt.\pWas willst du schon davon wissen, wer das Zeug zum Trainer hat und wer nicht?"
str_larissa_4:
    .autostring 34 2 "Du solltest mir nicht widersprechen, Kindchen, ja?\pMach dich nicht schlechter, als du bist!"
str_larissa_5:
    .autostring 34 2 "Wenn du ein wenig Selbstvertrauen brauchst, solltest du dich auf machen, die Arenaleiter dieser Region herauszuforden.\pAn ihnen müssen sich Trainer messen.\pUnd weißt du, Mädchen, da wirst auch du bemerken, dass in dir mehr steckt, als du vielleicht gerade glaubst."
str_larissa_6:
    .autostring 34 2 "Silvania liegt zum Beispiel ganz in der Nähe, da könnt ihr Mara herausfordern.\pAllerdingsDOTS\pDen Farmern hier sind einige Pokémon ausgebüchst und es könnte etwas dauern, bis sie ihre Voltilamm-Herde wieder zusammengescheucht haben.\pWarum versucht ihr nicht stattdessen nach Aktania zu gelangen?"
str_karte:
    .autostring 34 2 "PLAYER hat eine Karte erhalten."
str_larissa_7:
    .autostring 34 2 "Hier habt ihr beide eine Karte.\pWie ihr sehen könnt, liegt Aktania weit im Norden.\pUm dorthinzugelangen müsst ihr irgendwie das Meer passieren."
str_larissa_8:
    .autostring 34 2 "Aber keine Sorge, das ist kinderleicht.\pIch lasse euch den Spaß, es selbst herauszufinden!"
str_larissa_9:
    .autostring 34 2 "Es ist wirklich eine riesige Freude, euch beiden so zuzusehen, wo mir doch in letzter Zeit so langweilig war.\pLasst euch von mir nicht weiter aufhalten, ja?"
str_may_8:
    .autostring 34 2 "Diese Frau hat wirklich Nerven!"
str_may_9:
    .autostring 34 2 "Uns einfach so zu belehren und uns dann Anweisungen zu erteilen.\pWirklich unfassbar!"
str_may_10:
    .autostring 34 2 "Aber irgendwie hat mir das, was sie gesagt hat, schon ein wenig geholfenDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pVielleicht sollten wir ja wirklich versuchen, irgendwie diese seltsame Stadt zu erreichen, von der Larissa gesprochen hat.\pAktania, war der Name, richtig?\pAm Besten sehen wir uns hier etwas um, PLAYER."

.elseif LANG_EN

.endif