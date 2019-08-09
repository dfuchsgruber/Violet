.include "overworld_script.s"
.include "levelscript_types.s"

.global lscr_ceometria_gym_waiting_room

.align 4
lscr_ceometria_gym_waiting_room:
    .byte LEVELSCRIPT_TYPE_ON_TRANSITION
    .word initialize_rooms
    .byte 0

initialize_rooms:
    callasm ceometria_gym_next_waiting_room
    end