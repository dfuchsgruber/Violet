.include "vars.s"
.include "overworld_script.s"
.include "specials.s"

.global ow_script_ceometria_gym_waiting_room_person_0
.global ow_script_ceometria_gym_waiting_room_person_1
.global ow_script_ceometria_gym_waiting_room_person_2
.global ow_script_ceometria_gym_waiting_room_person_3

ow_script_ceometria_gym_waiting_room_person_0:
    setvar 0x8004 0
    goto continue_virtual
ow_script_ceometria_gym_waiting_room_person_1:
    setvar 0x8004 1
    goto continue_virtual
ow_script_ceometria_gym_waiting_room_person_2:
    setvar 0x8004 2
    goto continue_virtual
ow_script_ceometria_gym_waiting_room_person_3:
    setvar 0x8004 3
    goto continue_virtual

continue_virtual:
    special SPECIAL_CEOMETRIA_GYM_PERSON_GET_SCRIPT
    jumpram

