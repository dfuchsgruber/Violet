.include "vars.s"
.include "movements.s"
.include "specials.s"
.include "songs.s"
.include "callstds.s"
.include "trainer_backsprites.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_0x8a6d50
.global ow_script_0x8a6d63
.global ow_script_0x8a6d2a
.global ow_script_0x8a7011
.global ow_script_0x8a6d3d
.global ow_script_0x8a71a2
.global ow_script_map_3_41_trigger_0

mov_say_exclam:
.byte SAY_EXCLAM
.byte STOP

ow_script_movs_0x8a7003:
.byte LOOK_LEFT
.byte STOP


ow_script_movs_0x8a69da:
.byte LOOK_RIGHT
.byte STOP


mov_face_left_and_exclam:
.byte LOOK_LEFT
.byte SAY_EXCLAM
.byte STOP


ow_script_map_3_41_trigger_0:
lockall
playsong MUS_VIOLET_ENCOUNTER 0x0
sound 0x15
waitmovement 0
applymovement 0xFF mov_face_right
waitmovement 0
applymovement 0xff mov_say_exclam
waitmovement 0x0
checksound
msgbox_with_name str_0x8a7134 str_violet_grunt
loadpointer 0x0 str_0x8a70a9
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_SCARED
msgbox_with_name str_0x8a7027 str_violet_grunt
pause 16
showsprite 37
setflag PKMNMENU
sound 0x15
applymovement 0xFF mov_face_left_and_exclam
waitmovement 0
setvar 0x8004 37
special SPECIAL_NPC_MOVE_TO_PLAYER
waitmovement 0
applymovement 37 mov_face_right
waitmovement 0
loadpointer 0x0 str_0x8a6f8a
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
sound 0x15
applymovement 37 mov_say_exclam
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8a6f16
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT emotion=MUGSHOT_SHOCKED
applymovement 0xff ow_script_movs_0x8a69da
waitmovement 0x0
loadpointer 0x0 str_0x8a6bac
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
sound 0x15
applymovement 28 mov_face_left_and_exclam
applymovement 29 mov_face_left_and_exclam
applymovement 30 mov_face_left_and_exclam
applymovement 31 mov_face_left_and_exclam
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8a6b82
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_SCARED

loadpointer 0 str_violet_grunt
msgbox_with_name str_0x8a6bfa str_violet_grunt
applymovement 37 ow_script_movs_0x8a69da
waitmovement 0x0
loadpointer 0x0 str_0x8a6b0d
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT emotion=MUGSHOT_ANGRY
    setvar 0x8004 0xFF
    setvar 0x8005 0x13
    setvar 0x8006 0x39
    special SPECIAL_NPC_MOVE_TO
    setvar 0x8004 37
    setvar 0x8005 0x12
    setvar 0x8006 0x38
    special SPECIAL_NPC_MOVE_TO
    waitmovement 0
    applymovement 0xFF mov_face_right
    applymovement 37 mov_face_right
    waitmovement 0
select:
    setvar SONG_OVERRIDE MUS_VIOLET_ENCOUNTER
    loadpointer 0 str_select
    callstd MSG_KEEPOPEN
    special SPECIAL_SELECT_HALF_PARTY
    waitstate
    compare LASTRESULT 0
    gotoif EQUAL have_to_select
    setvar SONG_OVERRIDE 0
    compare STARTER_SELECTED 0
    gotoif EQUAL plant_starter
    compare STARTER_SELECTED 1
    gotoif EQUAL fire_starter
water_starter:
    setvar VAR_ALLY 0x161
    special SPECIAL_ALLY_BATTLE_SAVE_AND_SETUP_PARTY
    loadpointer 0 str_violet_grunt
    setvar 0x8000 1
    special SPECIAL_NAME_SHOW
    trainerbattleallytwotrainers 0x8 0x164 0x161 44 TRAINER_BACKSPRITE_RIVAL 1 str_0x8a69df str_0x8a6a97 str_after_second_grunt ow_script_0x8a71a2


fire_starter:
    setvar VAR_ALLY 0x160
    special SPECIAL_ALLY_BATTLE_SAVE_AND_SETUP_PARTY
    loadpointer 0 str_violet_grunt
    setvar 0x8000 1
    special SPECIAL_NAME_SHOW
    trainerbattleallytwotrainers 0x8 0x164 0x160 44 TRAINER_BACKSPRITE_RIVAL 1 str_0x8a69df str_0x8a6a97 str_after_second_grunt ow_script_0x8a71a2


plant_starter:
    setvar VAR_ALLY 0x15F
    special SPECIAL_ALLY_BATTLE_SAVE_AND_SETUP_PARTY
    loadpointer 0 str_violet_grunt
    setvar 0x8000 1
    special SPECIAL_NAME_SHOW
    trainerbattleallytwotrainers 0x8 0x164 0x15F 44 TRAINER_BACKSPRITE_RIVAL 1 str_0x8a69df ow_script_0x8a71a2 str_after_second_grunt ow_script_0x8a71a2
have_to_select:
    loadpointer 0x0 str_have_to_select
    show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT emotion=MUGSHOT_ANGRY
goto select

mov_face_right:
    .byte LOOK_RIGHT, STOP

ow_script_movs_0x8a7dbc:
.byte JUMP_RIGHT
.byte LOOK_LEFT
.byte STOP


ow_script_movs_0x8a74fc:
.byte FACE_DOWN
.byte STOP


ow_script_movs_0x8a74ff:
.byte LOOK_UP
.byte STOP


ow_script_movs_0x8a73a5:
.byte STEP_RIGHT
.byte LOOK_UP
.byte STOP


ow_script_movs_0x8a73a1:
.byte STEP_RIGHT
.byte STOP


ow_script_0x8a71a2:
msgbox_with_name str_0x8a7502 str_violet_grunt
applymovement 28 ow_script_movs_0x8a74fc
applymovement 29 ow_script_movs_0x8a74ff
waitmovement 0x0
msgbox_with_name str_0x8a74d8 str_violet_grunt
fadescreen 0x1
hidesprite 29
hidesprite 28
hidesprite 31
pause 0x60
fadescreen 0x0
applymovement 0xff ow_script_movs_0x8a73a5
applymovement 37 ow_script_movs_0x8a73a1
waitmovement 0x0
loadpointer 0x0 str_0x8a73a9
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
setvar STORY_PROGRESS 0xe
warp 0x3 0x42 0x0 0x0 0x0
end




ow_script_movs_0x8a6d84:
.byte STEP_UP
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


ow_script_movs_0x8a6d8d:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


ow_script_0x8a6d63:
applymovement 0xff ow_script_movs_0x8a6d84
applymovement 37 ow_script_movs_0x8a6d8d
waitmovement 0x0
return


ow_script_movs_0x8a6d7f:
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


ow_script_movs_0x8a6d8c:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


ow_script_0x8a6d50:
applymovement 0xff ow_script_movs_0x8a6d7f
applymovement 37 ow_script_movs_0x8a6d8c
waitmovement 0x0
return


ow_script_movs_0x8a6d7b:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


ow_script_movs_0x8a6d8b:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


ow_script_0x8a6d3d:
applymovement 0xff ow_script_movs_0x8a6d7b
applymovement 37 ow_script_movs_0x8a6d8b
waitmovement 0x0
return


ow_script_movs_0x8a6d76:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


ow_script_movs_0x8a6d8a:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


ow_script_0x8a6d2a:
applymovement 0xff ow_script_movs_0x8a6d76
applymovement 37 ow_script_movs_0x8a6d8a
waitmovement 0x0
return


ow_script_movs_0x8a701d:
.byte STEP_DOWN
.byte STOP


ow_script_0x8a7011:
applymovement 37 ow_script_movs_0x8a701d
waitmovement 0x0
return


.ifdef LANG_GER

str_violet_grunt:
	.string "Team Violet Rüpel"
str_0x8a7134:
	.autostring 34 2 "Wird's bald, Professor?\pWir werden schon aus dir rauskriegen, was wir wissen möchten.\pDarauf kannst du dich verlassen!"
str_0x8a70a9:
    .autostring 34 2 "Ihr seid völlig verrückt!\pWarum interessiert ihr euch für solche Märchen?"
str_0x8a7027:
    .autostring 34 2 "Was hat dich das zu interessieren?\pDu brauchst nur zu wissen, dass wir den Zeitstein haben wollen.\pUnd deshalb wirst du uns sagen, wo wir ihn finden können, verstanden?"
str_0x8a6f8a:
    .autostring 34 2 "PLAYER!\pPerfektes Timing!\pDas Labor meines Vaters befindet sich hier und ich wollte ihm einen Besuch abstatten."
str_0x8a6f16:
    .autostring 34 2 "Was ist denn hier los?\pWer sind diese Leute und was haben Sie mit meinem Vater zu schaffen?"
str_0x8a6bac:
    .autostring 34 2 "Lasst den Professor in Ruhe!"
str_0x8a6b82:
    .autostring 34 2 "RIVAL! PLAYER!\pHilfe!\nDiese Leute hier wollen mich nicht in Ruhe lassen!"
str_0x8a6bfa:
	.autostring 34 2 "Zwei Kinder, was?\nDas soll uns Angst einjagen?\pDer Professor muss doch nichts weiter tun, als uns das zu verraten, was wir wissen wollen, dann ist dieser ganze Unsinn hier schnell wieder vorbei.\pMischt euch gefälligst nicht in unsere Angelegenheiten ein, ihr Gören!"
str_0x8a6b0d:
    .autostring 34 2 "Alles klar PLAYER!\nDiese erbärmlichen Typen erledigen wir gemeinsam, was sagst du?"
str_0x8a6ac8:
    .autostring 34 2 "Wir werden deinem Vater auf jeden Fall helfen, RIVAL."
str_0x8a69df:
    .autostring 34 2 "Ihr traut euch was!\pWisst ihr nicht, mit wem ihr euch hier anlegt?"
str_0x8a6a97:
    .autostring 34 2 "DOTS DOTS DOTS\nDu kleine Rotzgöre!"
str_0x8a752d:
    .autostring 34 2 "Das kann doch nicht sein, dass mich ein Kind fertig machtDOTS"
str_0x8a7502:
    .autostring 34 2 "Verdammt!\pDer Kleine hat mich überrumpelt!"
str_0x8a74d8:
    .autostring 34 2 "Wir sollten uns vom Acker machen!"
str_0x8a73a9:
    .autostring 34 2 "RIVAL, PLAYER!\pIhr seid wirklich genau im richtigen Moment gekommen.\pDiese Typen sind wie aus dem Nichts aufgetaucht.\pTeam Violet nennen sie sich, glaube ich.\pIch habe schon ein paar mal von ihnen gehört, aber dass diese Schurken einmal vor meiner Tür stehen, hätte ich mir nicht träumen lassenDOTS\pAber wir sollten das nicht hier draußen besprechen, kommt doch herein in mein Labor!"
str_select:
    .autostring 34 2 "Wähle die Pokémon aus, mit denen du kämpfen möchtest."
str_have_to_select:
    .autostring 34 2 "Hey PLAYER!\nDu kannst mich doch hier nicht so hängen lassen!\pEs geht hier um meinen Vater!"
str_after_second_grunt:
    .autostring 34 2 "Oh nein, da wird Rin uns den Hintern aufreißenDOTS"
.elseif LANG_EN
str_violet_grunt:
	.string "Team Violet Grunt"
str_0x8a7134:
	.autostring 34 2 "Come on, Professor!\pWe will get you to talk anyway, you can bet on that!"
str_0x8a70a9:
    .autostring 34 2 "You are totally crazy?\pWhat do people like you care about such fairytales?"
str_0x8a7027:
    .autostring 34 2 "What do you care?\pYou just need to know, that we want to get the Time Stone.\pAnd that's why you'll tell us where to find it, got it?"
str_0x8a6f8a:
    .autostring 34 2 "PLAYER!\pPerfect Timing!\pMy dad's lab is arround the corner and I wanted to pay him a visit!\pCome join me!"
str_0x8a6f16:
    .autostring 34 2 "What's going on here?\pWho are these people and what do they have to do with my dad?"
str_0x8a6bac:
    .autostring 34 2 "Leave the professor alone!"
str_0x8a6b82:
    .autostring 34 2 "RIVAL! PLAYER!\pHelp!\pThese guys just won't leave me alone!"
str_0x8a6bfa:
    .autostring 34 2 "Two children, eh?\nThat's supposed to scare us, eh?\pThe professor just has to tell us what we want to know and all of this will be over soon.\pDon't put your noses in affairs that are none of your business, you brats!"
str_0x8a6b0d:
    .autostring 34 2 "Alright, PLAYER!\pWe will teach these pityful guys a lesson, what do you say?"
str_0x8a6ac8:
    .autostring 34 2 "We will definitely help your father, RIVAL!"
str_0x8a69df:
    .autostring 34 2 "Didn't you listen to us?\pDo you even know who you are dealing with?"
str_0x8a6a97:
    .autostring 34 2 "DOTS DOTS DOTS\nYou little brat!"
str_0x8a752d:
    .autostring 34 2 "That can't beDOTs\nI lost to a childDOTS"
str_0x8a7502:
    .autostring 34 2 "Damn!\pThat little one just caught me on suprise!"
str_0x8a74d8:
    .autostring 34 2 "We should get away now, guys!"
str_0x8a73a9:
    .autostring 34 2 "RIVAL, PLAYER!\pYou really just came the very right moment!\pThese guys just came out of nothing.\pTeam Violet is what they call themselves, I think.\pI heard about them a few times, but I would have never imagined encountering them just before the door of my lab.\pBut we shouldn't discuss these affairs outside, right?\pCome in, guys!"
str_select:
    .autostring 34 2 "Select the Pokémon you want to battle with."
str_have_to_select:
    .autostring 34 2 "Hey PLAYER!\nYou can't let me down like that!\pThis is about my father!"
str_after_second_grunt:
    .autostring 34 2 "Rin is going to rip apart our buttsDOTS"

.endif