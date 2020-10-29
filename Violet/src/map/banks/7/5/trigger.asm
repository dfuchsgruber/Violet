.include "overworld_script.s"
.include "vars.s"
.include "movements.s"
.include "ordinals.s"
.include "specials.s"
.include "flags.s"

.global ow_script_silvania_gym_trigger_switch
.global ow_script_silvania_gym_trigger_remove_red_trees
.global ow_script_silvania_gym_trigger_remove_purple_trees
.global ow_script_silvania_gym_trigger_remove_golden_trees

ow_script_silvania_gym_trigger_switch:
    lockall
    checkflag FLAG_TMP_SILVANIA_GYM_SWITCH_TOGGLE
    gotoif EQUAL switch1

switch0:
    setflag FLAG_TMP_SILVANIA_GYM_SWITCH_TOGGLE
    goto switch_end

switch1:
    clearflag FLAG_TMP_SILVANIA_GYM_SWITCH_TOGGLE
switch_end:
    callasm silvania_gym_switch
    waitmovement 0
    releaseall
    end


viewport_to_trees:
    fadescreen 1
    setvar 0x8004 4
    setvar 0x8005 0xa
	special SPECIAL_OVERWORLD_VIEWPORT_SET_POSITION
	fadescreen 0
    return

viewport_back:
    fadescreen 1
	special SPECIAL_OVERWORLD_VIEWPORT_SET_TO_PLAYER_POSITION
	callasm ow_script_fadescreen_palette_backup
	fadescreen 0
    return

ow_script_silvania_gym_trigger_remove_red_trees:
    lockall
    pause 48
    call viewport_to_trees
    sound 20
    call ow_script_silvania_gym_remove_red_trees
    special SPECIAL_MAP_UPDATE_BLOCKS
    checksound
    pause 32
    call viewport_back
    setvar VAR_TMP_SILVANIA_GYM_RED_TRIGGER 1
    releaseall
    end
    
ow_script_silvania_gym_trigger_remove_purple_trees:
    lockall
    pause 48
    call viewport_to_trees
    sound 20
    call ow_script_silvania_gym_remove_purple_trees
    special SPECIAL_MAP_UPDATE_BLOCKS
    checksound
    pause 32
    call viewport_back
    setvar VAR_TMP_SILVANIA_GYM_PURPLE_TRIGGER 1
    releaseall
    end

ow_script_silvania_gym_trigger_remove_golden_trees:
    lockall
    pause 48
    call viewport_to_trees
    sound 20
    call ow_script_silvania_gym_remove_golden_trees
    special SPECIAL_MAP_UPDATE_BLOCKS
    checksound
    pause 32
    call viewport_back
    setvar VAR_TMP_SILVANIA_GYM_GOLDEN_TRIGGER 1
    releaseall
    end