.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8f2219
ow_script_movs_0x8f2219:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8ed0b2
ow_script_movs_0x8ed0b2:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8ed0b5
ow_script_movs_0x8ed0b5:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8ed0af
ow_script_movs_0x8ed0af:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8ed069
ow_script_movs_0x8ed069:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8ecfe7
ow_script_movs_0x8ecfe7:
.byte SAY_QUESTION
.byte STOP


.global ow_script_0x8f2223
ow_script_0x8f2223:
pause 0x48
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8ed116
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x8f2219
waitmovement 0x0
call ow_script_0x8ed19a
loadpointer 0x0 str_0x8ed0b8
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x8ed0b2
waitmovement 0x0
pause 0x20
applymovement 0x1 ow_script_movs_0x8ed0b5
waitmovement 0x0
pause 0x20
applymovement 0x1 ow_script_movs_0x8ed0af
waitmovement 0x0
call ow_script_0x8ed19a
loadpointer 0x0 str_0x8ed06c
callstd MSG
special 0x7
cry POKEMON_CELEBI 0x0
waitcry
sound 0x15
applymovement 0x1 ow_script_movs_0x8ed069
waitmovement 0x0
call ow_script_0x8ed19a
loadpointer 0x0 str_0x8ed049
callstd MSG
special 0x7
cry POKEMON_CELEBI 0x0
waitcry
pause 0x18
cry POKEMON_CELEBI 0x0
waitcry
fadescreen 0x3
showsprite 0x2
fadescreen 0x2
cry POKEMON_CELEBI 0x0
waitcry
sound 0x15
applymovement 0x1 ow_script_movs_0x8ed069
waitmovement 0x0
call ow_script_0x8ed19a
loadpointer 0x0 str_0x8ed00c
callstd MSG
special 0x7
cry POKEMON_CELEBI 0x0
call ow_script_0x8f2206
loadpointer 0x0 str_0x8ecfea
callstd MSG
special 0x7
waitcry
sound 0x15
applymovement 0x1 ow_script_movs_0x8ecfe7
waitmovement 0x0
call ow_script_0x8ed19a
loadpointer 0x0 str_0x8ecfd8
callstd MSG
special 0x7
cry POKEMON_CELEBI 0x0
call ow_script_0x8f2206
loadpointer 0x0 str_0x8ecfb4
callstd MSG
special 0x7
waitcry
call ow_script_0x8ed19a
loadpointer 0x0 str_0x8ecf8a
callstd MSG
special 0x7
cry POKEMON_CELEBI 0x0
call ow_script_0x8f2206
loadpointer 0x0 str_0x8ecdda
callstd MSG
special 0x7
waitcry
cry POKEMON_CELEBI 0x0
waitcry
pause 0x38
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8ecd2c
callstd MSG
special 0x7
subvar STORY_PROGRESS 0x1
setflag SILVANIA_FOREST_FLASHBACK_DONE
goto ow_script_0x8f21ef


.global ow_script_0x8f21ef
ow_script_0x8f21ef:
fadescreen 0x1
callasm 0x919d791
writebytetooffset 0x0 0x2036e28
warpmuted 0x7 0x8 0xff 0x6 0x6
releaseall
end


.global ow_script_0x8f2206
ow_script_0x8f2206:
setvar 0x8000 0x0
setvar 0x8001 0x16
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x8ed19a
ow_script_0x8ed19a:
setvar 0x8000 0x1
setvar 0x8001 0x15
setvar 0x8002 0xe
special 0x6
return
