.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8efcec
ow_script_0x8efcec:
goto ow_script_0x9458b6


.global ow_script_movs_0x947b30
ow_script_movs_0x947b30:
.byte STEP_LEFT
.byte STOP


.global ow_script_0x9458b6
ow_script_0x9458b6:
special 0x44
comparevars 0x8004 0x8005
gotoif EQUAL ow_script_0x86ef25
buffernumber 0x0 0x8004
buffernumber 0x1 0x8005
callstd MSG_FACE
applymovement 0x800f ow_script_movs_0x947b30
waitmovement 0x0
releaseall
end


.global ow_script_0x86ef25
ow_script_0x86ef25:
loadpointer 0x0 str_0x971e6a
callstd MSG_FACE
end
