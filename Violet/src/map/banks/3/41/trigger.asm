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
.global ow_script_0x8a91b8
.global ow_script_0x8a71a2
.global ow_script_map_3_41_trigger_0
ow_script_movs_0x8a71a0:
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x8a7199:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


ow_script_movs_0x8a7020:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


ow_script_movs_0x8a7006:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


ow_script_movs_0x8a7003:
.byte LOOK_LEFT
.byte STOP


ow_script_movs_0x8a69da:
.byte LOOK_RIGHT
.byte STOP


ow_script_movs_0x8a6ac4:
.byte LOOK_LEFT
.byte SAY_EXCLAM
.byte STOP


ow_script_map_3_41_trigger_0:
lockall
playsong MUS_VIOLET_ENCOUNTER 0x0
sound 0x15
applymovement 0xff ow_script_movs_0x8a71a0
waitmovement 0x0
checksound
special 0x113
applymovement 0x7f ow_script_movs_0x8a7199
waitmovement 0x0

loadpointer 0 str_violet_grunt
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8a7134
callstd MSG
special 0xF

loadpointer 0x0 str_0x8a70a9
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT

loadpointer 0 str_violet_grunt
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8a7027
callstd MSG
special 0xF

applymovement 0x7f ow_script_movs_0x8a7020
waitmovement 0x0
special 0x114
showsprite 0x52
setflag PKMNMENU
getplayerpos 0x8000 0x8001
compare 0x8001 0x37
callif HIGHER ow_script_0x8a7011
compare 0x8001 0x38
callif HIGHER ow_script_0x8a7011
compare 0x8001 0x39
callif HIGHER ow_script_0x8a7011
applymovement 0x52 ow_script_movs_0x8a7006
waitmovement 0x0
applymovement 0xff ow_script_movs_0x8a7003
waitmovement 0x0
loadpointer 0x0 str_0x8a6f8a
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
sound 0x15
applymovement 0x52 ow_script_movs_0x8a71a0
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8a6f16
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
applymovement 0xff ow_script_movs_0x8a69da
waitmovement 0x0
loadpointer 0x0 str_0x8a6bac
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT MSG_FACE
sound 0x15
applymovement 0x2b ow_script_movs_0x8a6ac4
applymovement 0x2c ow_script_movs_0x8a6ac4
applymovement 0x2d ow_script_movs_0x8a6ac4
applymovement 0x2e ow_script_movs_0x8a6ac4
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8a6b82
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT

loadpointer 0 str_violet_grunt
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8a6bfa
callstd MSG
special 0xF

applymovement 0xff ow_script_movs_0x8a7003
waitmovement 0x0
loadpointer 0x0 str_0x8a6b0d
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
    setvar 0x8004 0xFF
    setvar 0x8005 0x13
    setvar 0x8006 0x38
    special SPECIAL_NPC_MOVE_TO
    setvar 0x8004 0x52
    setvar 0x8005 0x14
    setvar 0x8006 0x39
    special SPECIAL_NPC_MOVE_TO
    waitmovement 0
    applymovement 0xFF mov_face_right
    applymovement 0x52 mov_face_right
    waitmovement 0

select:
    setvar SONG_OVERRIDE MUS_VIOLET_ENCOUNTER
    setflag TRANS_DISABLE
    clearflag TRANS_PALETTE_FETCH
    loadpointer 0 str_select
    callstd MSG_KEEPOPEN
    special SPECIAL_SELECT_HALF_PARTY
    waitstate
    clearflag TRANS_DISABLE
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
    special 0xE
    trainerbattleallytwotrainers 0x8 0x164 0x161 43 TRAINER_BACKSPRITE_RIVAL 1 str_0x8a69df str_0x8a6a97 str_after_second_grunt ow_script_0x8a71a2


fire_starter:
    setvar VAR_ALLY 0x160
    special SPECIAL_ALLY_BATTLE_SAVE_AND_SETUP_PARTY
    loadpointer 0 str_violet_grunt
    setvar 0x8000 1
    special 0xE
    trainerbattleallytwotrainers 0x8 0x164 0x160 43 TRAINER_BACKSPRITE_RIVAL 1 str_0x8a69df str_0x8a6a97 str_after_second_grunt ow_script_0x8a71a2


plant_starter:
    setvar VAR_ALLY 0x15F
    special SPECIAL_ALLY_BATTLE_SAVE_AND_SETUP_PARTY
    loadpointer 0 str_violet_grunt
    setvar 0x8000 1
    special 0xE
    trainerbattleallytwotrainers 0x8 0x164 0x15F 43 TRAINER_BACKSPRITE_RIVAL 1 str_0x8a69df ow_script_0x8a71a2 str_after_second_grunt ow_script_0x8a71a2



have_to_select:
    loadpointer 0x0 str_have_to_select
    show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
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
loadpointer 0 str_violet_grunt
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8a7502
callstd MSG
special 0xF
applymovement 0x2b ow_script_movs_0x8a74fc
applymovement 0x2c ow_script_movs_0x8a74ff
waitmovement 0x0
loadpointer 0 str_violet_grunt
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8a74d8
callstd MSG
special 0xF
fadescreen 0x1
call ow_script_0x8a91b8
fadescreen 0x0
applymovement 0x52 ow_script_movs_0x8a73a5
applymovement 0xff ow_script_movs_0x8a73a1
waitmovement 0x0
loadpointer 0x0 str_0x8a73a9
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
setvar STORY_PROGRESS 0xe
warp 0x3 0x42 0x0 0x0 0x0
end


ow_script_0x8a91b8:
hidesprite 0x2c
hidesprite 0x2b
hidesprite 0x2e
pause 0x60
return


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
applymovement 0x52 ow_script_movs_0x8a6d8d
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
applymovement 0x52 ow_script_movs_0x8a6d8c
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
applymovement 0x52 ow_script_movs_0x8a6d8b
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
applymovement 0x52 ow_script_movs_0x8a6d8a
waitmovement 0x0
return


ow_script_movs_0x8a701d:
.byte STEP_DOWN
.byte STOP


ow_script_0x8a7011:
applymovement 0x52 ow_script_movs_0x8a701d
waitmovement 0x0
return


.ifdef LANG_GER

str_violet_grunt:
	.string "Team Violet Rüpel"


str_0x8a7134:
	.autostring 34 2 "Spiel hier nicht den Dummen!\pWenn du uns nicht verrätst, was wir wissen wollen, wirst du uns kennenlernen!"



str_0x8a70a9:
    .autostring 34 2 "Ich habe es euch doch schon gesagt!\pIch bin zwar ein Archäologe, aber von einem Zeistein habe ich noch nie zuvor gehört!"



str_0x8a7027:
    .autostring 34 2 "Das kaufen wir dir aber nicht ab!\pDu willst es also wirklich darauf ankommen lassen?"



str_0x8a6f8a:
    .autostring 34 2 "PLAYER!\pPerfektes Timing!\pDas Labor meines Vaters befindet sich hier und ich wollte ihm einen Besuch abstatten."



str_0x8a6f16:
    .autostring 34 2 "Was ist denn hier los?\pWer sind diese Leute und was haben Sie mit meinem Vater zu schaffen?"



str_0x8a6bac:
    .autostring 34 2 "Lasst den Professor in Ruhe!"



str_0x8a6b82:
    .autostring 34 2 "RIVAL! PLAYER!\nIhr seid meine Retter in der Not!"



str_0x8a6bfa:
	.autostring 34 2 "Dieses Kind schon wieder!\pHast du deine Lektion noch nicht gelernt, dich nicht mit uns anzulegen?\pDu wirst noch einsehen, dass man sich nicht in Angelegenheiten einmischen sollte, die einen nichts angehen!"


str_0x8a6b0d:
    .autostring 34 2 "Alles klar PLAYER!\nDiese erbärmlichen Typen erledigen wir gemeinsam, was sagst du?"



str_0x8a6ac8:
    .autostring 34 2 "Wir werden deinen Vater auf jeden Fall retten!"



str_0x8a69df:
    .autostring 34 2 "Du Rotzlöffel!\pJetzt wirst du aufgemischt!"

str_0x8a6a97:
    .autostring 34 2 "DOTS DOTS DOTS\nDu kleiner RotzlöffelDOTS"

str_0x8a752d:
    .autostring 34 2 "Das kann doch nicht sein, dass ich von so einem Balg besiegt werde!"



str_0x8a7502:
    .autostring 34 2 "Verdammt!\pDer Kleine hat mich überrumpelt!"



str_0x8a74d8:
    .autostring 34 2 "Wir sollten uns vom Acker machen!"



str_0x8a73a9:
    .autostring 34 2 "RIVAL, PLAYERDOTS\pIhr seid wirklich genau richtig gekommen.\pWer weiß, was mir diese Schergen angetan hätten, wenn ihr nicht eingeschritten wärt.\pSie haben darauf bestanden, dass ich ihnen verrate, wo man einen gewissen Zeitstein findet.\pIch wollte ihnen klar machen, dass ich von einem solchen Zeitstein noch nie etwas gehört habe, aber diese Rüpel wollten nicht hören.\pAber lasst uns das nicht hier draußen besprechen, kommt doch mit in mein Labor."

str_select:
    .autostring 34 2 "Wähle die Pokémon aus, mit denen du kämpfen möchtest."

str_have_to_select:
    .autostring 34 2 "Hey PLAYER!\nDu kannst mich doch hier nicht so hängen lassen!\pEs geht hier um meinen Vater!"

str_after_second_grunt:
    .autostring 34 2 "Rin wird uns den Hintern aufreißenDOTS"
.elseif LANG_EN
str_select:
    .autostring 34 2 "Select the Pokémon you want to battle with."
str_have_to_select:
    .autostring 34 2 "Hey PLAYER!\nYou can't let me down like that!\pThis is about my father!"
str_after_second_grunt:
    .autostring 34 2 "Rin is going to rip apart our buttsDOTS"

.endif