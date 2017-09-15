.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8dcf8a
ow_script_movs_0x8dcf8a:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8dcf31
ow_script_movs_0x8dcf31:
.byte STEP_UP
.byte STEP_LEFT
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8dcf2e
ow_script_movs_0x8dcf2e:
.byte STEP_UP
.byte STOP


.global ow_script_0x8dce86
ow_script_0x8dce86:
lockall
loadpointer 0x0 str_0x8dcf8d
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x8de230
callstd MSG_KEEPOPEN
sound 0x15
applymovement 0x28 ow_script_movs_0x8dcf8a
waitmovement 0x0
loadpointer 0x0 str_0x8dcf36
callstd MSG_KEEPOPEN
applymovement 0x28 ow_script_movs_0x8dcf31
waitmovement 0x0
setdooropened 0x2e 0x14
doorchange
applymovement 0x28 ow_script_movs_0x8dcf2e
waitmovement 0x0
hidesprite 0x28
setdoorclosed 0x2e 0x14
doorchange
loadpointer 0x0 str_0x8dcee9
callstd MSG
fadescreen 0x1
hidesprite 0x27
clearflag 0x227
fadescreen 0x0
addvar 0x4054 0x1
releaseall
end
