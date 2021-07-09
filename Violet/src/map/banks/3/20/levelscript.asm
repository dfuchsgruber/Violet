.include "vars.s"
.include "levelscript_types.s"
.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"
.include "person_behaviours.s"

.global map_power_plant_levelscripts

.align 4

map_power_plant_levelscripts:
    .byte LEVELSCRIPT_TYPE_ON_TRANSITION
    .word transition_script
	.byte 0x0
    
transition_script:
    checkflag FLAG_POWER_PLANT_WINGULL_QUEST_TAKEN
    gotoif NOT_EQUAL end_transition_script
    checkflag FLAG_POWER_PLANT_WINGULL_FOUND
    gotoif EQUAL move_old_man_to_talk_to_scientist
    movesprite2 3 0x15 0x18
    spritebehave 3 BEHAVIOUR_LOOK_AROUND
end_transition_script:
    end
move_old_man_to_talk_to_scientist:
    movesprite2 3 0x15 0x18
    spritebehave 3 BEHAVIOUR_FACE_RIGHT
    end