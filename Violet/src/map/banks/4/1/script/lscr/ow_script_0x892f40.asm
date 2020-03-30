.include "flags.s"
.include "songs.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "time_types.s"
.include "story_states.s"
.include "mugshot.s"

.global ow_script_0x892f40
ow_script_0x892f40:

// Reset all vars, flags etc
callasm custom_memory_init

//init some stuff
special 0x43 //version init
call ow_script_0x8dcdd2
setvar POKEPAD_SHORTCUTS 0xffff
setvar STORY_STATE STORY_STATE_NONE
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
setvar DYN_MULTICHOICE_ITEM_CNT 0x5
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
draw_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
loadpointer 0x0 str_0x8cf12f
callstd MSG_KEEPOPEN
closeonkeypress
hide_mugshot
playsong MUS_ALABASTIA 0
playsong2 MUS_ALABASTIA
end

change_time:
	setvar TIME_TYPE TIME_TYPE_INGAME_CLOCK
	return


.global ow_script_0x8dcdd2
ow_script_0x8dcdd2:
setflag AMONIA_RIVAL_INSIDE_PLAYER_HOUSE //rival in same house 
setflag 0x221
setflag 0x228
setflag 0x227
setflag 0x236
setflag RUNNING_SHOES //Running shoes
setvar TRAINER_TIPP_CNT 50 //50 steps till first trainer tipp triggers
return


.global ow_script_0x8fadd7
ow_script_0x8fadd7:
compare DIFFICULTY 0x2
gotoif HIGHER ow_script_0x8faebc
return


.global ow_script_0x8faebc
ow_script_0x8faebc:
callasm remove_potion_from_pc
return


mov_player_to_bed:
.byte STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST
.byte STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST
.byte STOP


.align 4
difficulty_choices:
    .word str_difficulty_very_easy, 0
    .word str_difficulty_easy, 0
    .word str_difficulty_normal, 0
    .word str_difficulty_hard, 0
    .word str_difficulty_very_hard, 0



.ifdef LANG_GER
.global str_0x89553b

str_0x89553b:
    .string "Wähle zunächst den\nSchwierigkeitsgrad aus, in dem du\ldas Spiel spielen möchtest.\pAchtung: Diese Entscheidung ist\nendgültig.\pDu kannst sie während\ndes Spielverlaufs nicht ändern!"
        
        
.global str_difficulty_very_easy

str_difficulty_very_easy:
    .string "Sehr einfach"
        
        
.global str_difficulty_easy

str_difficulty_easy:
    .string "Einfach"
        
        
.global str_difficulty_normal

str_difficulty_normal:
    .string "Normal"
        
        
.global str_difficulty_hard

str_difficulty_hard:
    .string "Schwer"
        
        
.global str_difficulty_very_hard

str_difficulty_very_hard:
    .string "Sehr schwer"
        
        

        
.global str_0x8cf12f

str_0x8cf12f:
    .string "Was für ein seltsamer TraumDOTS\nEr hat sich so real angefühlt!\pDOTSund was er wohl zu bedeuten\nhatte?\pUnd wessen Stimme hat zu mir\ngesprochen?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIch sollte mir darüber nicht zu\nviel Kopfzerbrechen bereiten, wo\ldoch heute der große Tag ist.\pUnd ich bin vermutlich schon viel\nzu spät!"
        
        
.elseif LANG_EN

.endif
