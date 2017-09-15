.include "overworld_script.s"

.include "std.s"

.global ow_script_0x892f40
ow_script_0x892f40:

//init some stuff
special 0x43
call ow_script_0x8dcdd2
setvar POKEPAD_SHORTCUTS 0xffff
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
waitstate //now disable the bg aligment again
setflag MAP_BGN_AUTO_ALIGN_OFF
waitstate
clearflag MAP_BGN_AUTO_ALIGN_OFF
pause 0x80
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8cf12f
callstd MSG_KEEPOPEN
closeonkeypress
special 0x7
playsong MUS_ALABASTIA 0
end


.global ow_script_0x8a1cc9
ow_script_0x8a1cc9:
setvar 0x8000 0x0
setvar 0x8001 0xc
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x8dcdd2
ow_script_0x8dcdd2:
setflag ANOMIA_RIVAL_IN_PLAYER_HOUSE //rival in same house 
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

