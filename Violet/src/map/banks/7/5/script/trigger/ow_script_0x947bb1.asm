.include "movements.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "vars.s"

.global ow_script_movs_0x84ea62
ow_script_movs_0x84ea62:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x84ea73
ow_script_movs_0x84ea73:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_0x947bb1
ow_script_0x947bb1:
lockall
special 0x113
applymovement 0x7f ow_script_movs_0x84ea62
waitmovement 0x0
sound 0x33
setmaptile 0x5 0xe 0x284 0x0
setmaptile 0x5 0xf 0x284 0x0
setmaptile 0x9 0x9 0x284 0x0
setmaptile 0x9 0x8 0x284 0x0
setmaptile 0x7 0xd 0x284 0x0
setmaptile 0xd 0xd 0x284 0x0
setmaptile 0x3 0xb 0x28b 0x0
setmaptile 0x6 0xa 0x28b 0x0
setmaptile 0xb 0xa 0x28b 0x0
setmaptile 0x7 0x10 0x28b 0x0
setmaptile 0xc 0xf 0x28b 0x0
setmaptile 0x4 0x8 0x280 0x0
setmaptile 0x4 0x7 0x280 0x0
special 0x8e
applymovement 0x7f ow_script_movs_0x84ea73
waitmovement 0x0
special 0x114
setvar VAR_SIVLANIA_GYM_SWITCH 2
setvar VAR_SILVANIA_GYM_GOLDEN_SWITCH 1
checksound
release
end


.global ow_script_0x947c67
ow_script_0x947c67:
pause 0x1
releaseall
end
