.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8e6a33
ow_script_movs_0x8e6a33:
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STOP


.global ow_script_movs_0x81c5a4
ow_script_movs_0x81c5a4:
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x87e927
ow_script_movs_0x87e927:
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STOP


.global ow_script_0x81c55e
ow_script_0x81c55e:
lockall
special 0x113
applymovement 0x7f ow_script_movs_0x8e6a33
waitmovement 0x0
loadpointer 0x0 str_0x87762b
callstd MSG
applymovement 0x1 ow_script_movs_0x81c5a4
applymovement 0x2 ow_script_movs_0x81c5a4
waitmovement 0x0
sound 0x9
hidesprite 0x1
hidesprite 0x2
checksound
applymovement 0x7f ow_script_movs_0x87e927
waitmovement 0x0
special 0x114
addvar STORY_PROGRESS 0x1
releaseall
end

.global str_0x87762b

str_0x87762b:
    .string "Rüpel: Wir müssen uns beeilen, Rin\nwartet sicherlich schon im Wald.\pRüpel: Ja, und sie kann launisch\nwerden... Los jetzt! "
        
        