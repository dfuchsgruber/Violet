.include "overworld_script.s"

.include "std.s"

.global ow_script_0x89bfa5
ow_script_0x89bfa5:
lockall
playsong MUS_RIVALE_ERSCHEINT_GARY 0x0
pause 0x2c
goto ow_script_0x8f6dec


.global ow_script_movs_0x89c14d
ow_script_movs_0x89c14d:
.byte LOOK_RIGHT
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x89c14a
ow_script_movs_0x89c14a:
.byte LOOK_LEFT
.byte STOP


.global ow_script_0x8f6dec
ow_script_0x8f6dec:
sound 0x15
applymovement 0x1 ow_script_movs_0x89c14d
applymovement 0xff ow_script_movs_0x89c14a
waitmovement 0x0
goto ow_script_0x89c06b
