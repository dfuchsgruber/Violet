.include "flags.s"
.include "overworld_script.s"


.global ow_script_0x9454ec
ow_script_0x9454ec:
clearflag VOLCANO_DISERAKT
showsprite 0x9
lockall
goto ow_script_0x966da8
