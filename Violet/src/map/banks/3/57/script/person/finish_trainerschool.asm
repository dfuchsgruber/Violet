.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "flags.s"

.global ow_script_trainerschool_finish
ow_script_trainerschool_finish:
compare TRAINERSCHOOL_GOODBYE_CNT 3
gotoif EQUAL finish
end

finish:
@ Trainerschool done
addvar TRAINERSCHOOL_PROGRESS 1
addvar STORY_PROGRESS 1
setvar TRAINERSCHOOL_ALLOWED_TO_ENTER_GRASS 1
setvar TRAINERSCHOOL_DONE 1
end
