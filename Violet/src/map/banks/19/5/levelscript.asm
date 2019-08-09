.include "overworld_script.s"
.include "levelscript_types.s"

.global lscr_ceometria_gym_entrance

lscr_ceometria_gym_entrance:
    .byte LEVELSCRIPT_TYPE_ON_TRANSITION
    .word initialize_rooms
    .byte 0

initialize_rooms:
    callasm ceometria_gym_initialize
    end