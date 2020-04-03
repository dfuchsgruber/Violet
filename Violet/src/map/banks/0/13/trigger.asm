.include "overworld_script.s"
.include "flags.s"

.global ow_script_map_0_13_trigger_0

ow_script_map_0_13_trigger_0:
clearflag VOLCANO_DISERAKT
showsprite 0x9
lockall
goto ow_script_0x94772b