.include "overworld_script.s"
.include "callstds.s"

.global ow_script_bluetenbach_referee

ow_script_bluetenbach_referee:
    loadpointer 0 str_bluetenbach_gym_referee
    callstd MSG_FACE
    end
