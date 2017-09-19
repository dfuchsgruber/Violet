.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8ec5cb
ow_script_movs_0x8ec5cb:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8e6a88
ow_script_0x8e6a88:
lockall
sound 0x15
applymovement 0x800f ow_script_movs_0x8ec5cb
waitmovement 0x0
faceplayer
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8ec458
callstd MSG_FACE
special 0x7
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8e8f9d
callstd MSG_FACE
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8e8da8
callstd MSG_FACE
special 0x7
fadescreen 0x1
hidesprite 0x800f
clearflag SILVANIA_FAUN_AND_MIA
addvar STORY_PROGRESS 0x1
fadescreen 0x0
releaseall
end
