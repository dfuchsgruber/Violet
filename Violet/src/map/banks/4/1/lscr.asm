.include "vars.s"

.global lscr_0x71a500

lscr_0x71a500:
	.byte 0x4
.word lscr_0x168c29
	.byte 0x3
.word ow_script_0x84002b
	.byte 0x2
.word lscr_0x720a14
	.byte 0x0


.align 4
.global lscr_0x168c29

lscr_0x168c29:
	.hword AMONIA_PLAYERFACING_INTRO, 0x0
	.word ow_script_0x168c33
	.hword 0x0




.align 4
.global lscr_0x720a14

lscr_0x720a14:
	.hword STORY_PROGRESS, 0x0
	.word ow_script_0x892f40
	.hword 0x0
.include "vars.s"
.include "healingplaces.s"
.include "movements.s"
.include "songs.s"
.include "callstds.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "story_states.s"
.include "time_types.s"

.global ow_script_0x84002b
.global ow_script_0x8faebc
.global ow_script_0x8dcdd2
.global ow_script_0x892f40
.global ow_script_0x84003e
.global ow_script_0x8fadd7
.global ow_script_0x168c33

ow_script_0x168c33:
spriteface 0xff 0x2
setvar AMONIA_PLAYERFACING_INTRO 0x1
end

ow_script_0x84002b:
setflag AMONIA_RIVAL_INSIDE_PLAYER_HOUSE
sethealingplace HEALINGPLACE_AMONIA
compare STORY_PROGRESS 0x0
gotoif EQUAL ow_script_0x84003e
end


ow_script_0x84003e:
playsong2 0xFFFF
end

ow_script_0x892f40:

// Reset all vars, flags etc
callasm custom_memory_init

//init some stuff
special 0x43 //version init
call ow_script_0x8dcdd2
setvar POKEPAD_SHORTCUTS 0xffff
setvar VAR_STORY_STATE STORY_STATE_NONE
// Initialize time system
setvar TIME_TYPE TIME_TYPE_RTC
// Check if the rtc works
special2 LASTRESULT 0x8
compare LASTRESULT 0
callif EQUAL change_time

addvar STORY_PROGRESS 0x1 @//beforehand raise of storyvar to not trigger again at mapreload
setflag MAP_BGN_AUTO_ALIGN_OFF
setvar 0x8004 11
special 0x19
waitstate
loadpointer 0x0 str_0x89553b
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 3
loadpointer 0x0 difficulty_choices
multichoice2 0x3 0x1 0x0 0x2 0x1
copyvar DIFFICULTY LASTRESULT
@//Fading back to black and then, while dark, let the player run to his bed (hacky af, but w/e)

setvar 0x8004 12
special 0x19
waitstate
clearflag MAP_BGN_AUTO_ALIGN_OFF
waitstate //both waitstates are resolved in animation 12
pause 0x20
fadescreen 1
applymovement 0xFF mov_player_to_bed
waitmovement 0
setvar 0x8004 13
special 0x19
waitstate
pause 0x80
loadpointer 0x0 str_after_dream
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT MSG_KEEPOPEN hide_mugshot=0
update_mugshot_emotion MUGSHOT_RUMINATIVE
loadpointer 0x0 str_after_dream2
callstd MSG_KEEPOPEN
update_mugshot_emotion MUGSHOT_NORMAL
loadpointer 0x0 str_after_dream3
callstd MSG_KEEPOPEN
closeonkeypress
hide_mugshot
playsong MUS_ALABASTIA 0
playsong2 MUS_ALABASTIA
end

change_time:
	setvar TIME_TYPE TIME_TYPE_INGAME_CLOCK
	return


ow_script_0x8dcdd2:
setflag AMONIA_RIVAL_INSIDE_PLAYER_HOUSE //rival in same house
setflag 0x221
setflag 0x228
setflag 0x227
setflag 0x236
setflag RUNNING_SHOES //Running shoes
setvar TRAINER_TIPP_CNT 50 //50 steps till first trainer tipp triggers
return


ow_script_0x8fadd7:
compare DIFFICULTY 0x2
gotoif HIGHER ow_script_0x8faebc
return


ow_script_0x8faebc:
callasm remove_potion_from_pc
return


mov_player_to_bed:
.byte STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST
.byte STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST
.byte STOP


.align 4
difficulty_choices:
    .word str_difficulty_easy, 0
    .word str_difficulty_normal, 0
    .word str_difficulty_hard, 0



.ifdef LANG_GER

str_0x89553b:
    .autostring 34 2 "Wähle zunächst den Schwierigkeitsgrad aus, in dem du das Spiel spielen möchtest.\pDiese Entscheidung ist endgültig und kann später nicht wieder verändert werden."
str_difficulty_easy:
    .string "Einfach"
str_difficulty_normal:
    .string "Normal"
str_difficulty_hard:
    .string "Schwer"
str_after_dream:
    .autostring 34 2 "Was für ein seltsamer TraumDOTS\nEr hat sich so real angefühlt!"
str_after_dream2:
    .autostring 34 2 "Was er wohl zu bedeuten hatte?\pIrgendeine Stimme hat zu mir gesprochen, aber ich habe sie nicht erkanntDOTS"
str_after_dream3:
    .autostring 34 2 "Aber ich sollte mir gerade heute darüber nicht den Kopf zerbrechen!\pImmerhin steht meine Abschlussprüfung an!\pUnd ich bin vermutlich schon viel zu spät dran."
.elseif LANG_EN

str_0x89553b:
    .autostring 34 2  "First, select the difficulty in which you want to play the game.\pNote that this decision is final and can't be changed later on."
str_difficulty_easy:
    .string "Easy"
str_difficulty_normal:
    .string "Normal"
str_difficulty_hard:
    .string "Hard"
str_after_dream:
    .autostring 34 2 "What a weird dramDOTS\pIt felt so real!"
str_after_dream2:
    .autostring 34 2 "I wonder what it meaning might have been.\pSome kind of voice seemed to be speaking to me but I didn't recognize it at all!"
str_after_dream3:
    .autostring 34 2 "But I should not let myself get distracted by something like this now.\pMy finals are today and I am probably late already!"

.endif