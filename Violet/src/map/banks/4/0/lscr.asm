
.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "songs.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"

.global str_mother

.global lscr_0x719248

lscr_0x719248:
	.byte 0x2
.word lscr_0x719056
	.byte 0x3
.word ow_script_0x83ff26
	.byte 0x0


.align 4
.global lscr_0x719056

lscr_0x719056:
	.hword STORY_PROGRESS, 0x1
	.word ow_script_0x89bb77
	.hword 0x0



.global ow_script_0x8400be
.global ow_script_0x83ff26
.global ow_script_0x89bb77

ow_script_0x83ff26:
compare STORY_PROGRESS 0x1
gotoif EQUAL ow_script_0x8400be
end


ow_script_0x8400be:
movesprite2 0x1 0x6 0x6
spritebehave 0x1 0x7
end


ow_script_movs_0x89ba89:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x89bd3d:
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STOP


ow_script_movs_0x89adc0:
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STOP


ow_script_movs_0x89adbd:
.byte SAY_QUESTION
.byte STOP


ow_script_movs_0x89adba:
.byte LOOK_UP
.byte STOP


ow_script_movs_0x8401ea:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte LOOK_RIGHT
.byte STOP


ow_script_0x89bb77:
lockall
setvar 0x8000 0x0
loadpointer 0x0 str_mother
setvar 0x8000 0
special 0xe
loadpointer 0x0 str_0x89ba97
callstd MSG
special 0xf
playsong MUS_RIVALE_ERSCHEINT_GARY 0x0
clearflag AMONIA_RIVAL_INSIDE_PLAYER_HOUSE
showsprite 0x2
sound 0x9
checksound
sound 0x15
applymovement 0xff ow_script_movs_0x89ba89
applymovement 0x1 ow_script_movs_0x89ba89
waitmovement 0x0
applymovement 0x2 ow_script_movs_0x89bd3d
waitmovement 0x0
loadpointer 0x0 str_0x947c6c
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
applymovement 0x2 ow_script_movs_0x89adc0
waitmovement 0x0
sound 0x9
hidesprite 0x2
setflag AMONIA_RIVAL_INSIDE_PLAYER_HOUSE
fadesong MUS_ALABASTIA
checksound
pause 0x1c
sound 0x15
applymovement 0xff ow_script_movs_0x89adbd
applymovement 0x1 ow_script_movs_0x89adbd
waitmovement 0x0
checksound
setvar 0x8000 0x0
loadpointer 0x0 str_mother
setvar 0x8000 0
special 0xe
loadpointer 0x0 str_0x89ad96
callstd MSG
special 0xf
applymovement 0x1 ow_script_movs_0x89adba
waitmovement 0x0
setvar 0x8000 0x0
loadpointer 0x0 str_mother
setvar 0x8000 0
special 0xe
loadpointer 0x0 str_0x89ad05
callstd MSG
special 0xf
applymovement 0x1 ow_script_movs_0x8401ea
waitmovement 0x0
setvar STORY_PROGRESS 0x2
releaseall
end


.ifdef LANG_GER

str_mother:
    .string "Mutter"
str_0x89ba97:
	.autostring 34 2 "Guten Morgen, PLAYER!\pWie kannst du denn ausgerechnet heute verschlafen?\pDie Abschlussprüfung in der Trainerschule darfst du auf keinen Fall verpassen.\pFür Frühstück ist jetzt keine Zeit mehr, RIVAL wird jeden Moment -"
str_0x947c6c:
    .autostring 34 2 "PLAYER, das ist doch nicht zu fassen!\pDie Prüfung geht gleich los und du bist gerade erst aus den Federn!\pWenn wir zu spät kommen, dürfen wir uns vom alten Faun was anhören.\pUnd da würde ich lieber drauf verzichten!\pAlso gib Gas!\nWir sehen uns gleich draußen!\pBloß nicht trödeln!\nLos, los!"
str_0x89ad96:
    .autostring 34 2 "Typsich RIVALDOTS"
str_0x89ad05:
    .autostring 34 2 "RIVAL ist eben ein Hitzkopf.\pDu lässt ihn lieber nicht warten, PLAYER.\pIch wünsche dir alles Gute für deine Prüfung, Liebling!"
.elseif LANG_EN

str_mother:
    .string "Mom"
str_0x89ba97:
	.autostring 34 2 "Good morning, PLAYER!\pHow could you possibly oversleep on this day?\pYour can't miss your finals in the Trainerschool!\pYou won't have time for breakfest I fear, RIVAl will be here any moment -"
str_0x947c6c:
    .autostring 34 2 "PLAYER, I can't believe it!\pThe exam is starting any moment now and you are just out of bed!\pIf we are late the old Faun will give us a good telling of.\pAnd if you ask me I'd rather avoid that.\pSo hurry up now!\pWe meet outside in one minute!\pDon't you dare to linger around here!\pGo, go!"
str_0x89ad96:
    .autostring 34 2 "That's so like RIVALDOTS"
str_0x89ad05:
    .autostring 34 2 "RIVAL has always been kind of a hothead.\pYou probably shouldn't make him wait, PLAYER.\pI wish you all the best for your exam, honey!"
.endif