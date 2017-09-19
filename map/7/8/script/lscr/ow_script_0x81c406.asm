.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8eca2a
ow_script_movs_0x8eca2a:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8eca0e
ow_script_movs_0x8eca0e:
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x8ec91e
ow_script_movs_0x8ec91e:
.byte SAY_QUESTION
.byte STOP


.global ow_script_0x81c406
ow_script_0x81c406:
checkflag SILVANIA_FOREST_FLASHBACK_DONE
gotoif EQUAL ow_script_0x8f7200
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8eca2e
callstd MSG
special 0x7
sound 0x15
applymovement 0x2 ow_script_movs_0x8eca2a
applymovement 0x1 ow_script_movs_0x8eca2a
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8eca11
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x8eca0e
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8ec9d0
callstd MSG
special 0x7
loadpointer 0x0 str_0x8ec921
callstd MSG
sound 0x15
applymovement 0xff ow_script_movs_0x8ec91e
waitmovement 0x0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8ec8fc
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8ec8ab
callstd MSG
special 0x7
loadpointer 0x0 str_0x8ec84d
callstd MSG
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8ec7d7
callstd MSG
special 0x7
loadpointer 0x0 str_0x8ec6df
callstd MSG
call ow_script_0x89c5ee
loadpointer 0x0 str_0x87e807
callstd MSG
special 0x7
goto ow_script_0x8ecac3


.global ow_script_0x8ecac3
ow_script_0x8ecac3:
goto ow_script_0x8fbc6c


.global ow_script_0x8fbc6c
ow_script_0x8fbc6c:
writebytetooffset 0x2 0x2036e28
warpmuted 0x1 0x0 0x8 0x0 0x0
addvar STORY_PROGRESS 0x1
waitstate
end


.global ow_script_movs_0x8f28b5
ow_script_movs_0x8f28b5:
.byte LOOK_LEFT
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8f28b2
ow_script_movs_0x8f28b2:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8f27c8
ow_script_movs_0x8f27c8:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8f26b0
ow_script_movs_0x8f26b0:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8f0a0b
ow_script_movs_0x8f0a0b:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8f0981
ow_script_movs_0x8f0981:
.byte LOOK_UP
.byte STOP


.global ow_script_0x8f7200
ow_script_0x8f7200:
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8f28b9
callstd MSG
special 0x7
applymovement 0x2 ow_script_movs_0x8f28b5
waitmovement 0x0
loadpointer 0x0 str_0x8f3668
callstd MSG
applymovement 0x1 ow_script_movs_0x8f28b2
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8f27cb
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x8f27c8
applymovement 0x2 ow_script_movs_0x8f27c8
waitmovement 0x0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8f276d
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8f26b3
callstd MSG
special 0x7
applymovement 0x2 ow_script_movs_0x8f26b0
waitmovement 0x0
loadpointer 0x0 str_0x8f2607
callstd MSG
sound 0x63
showsprite 0x3
checksound
sound 0x15
applymovement 0x1 ow_script_movs_0x8eca2a
applymovement 0x2 ow_script_movs_0x8eca2a
applymovement 0xff ow_script_movs_0x8eca2a
waitmovement 0x0
loadpointer 0x0 str_0x8f257b
callstd MSG
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8f0b3b
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x8f28b2
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8f0ad6
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x8f27c8
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8f0a28
callstd MSG
special 0x7
loadpointer 0x0 str_0x8f0a11
callstd MSG
applymovement 0x3 ow_script_movs_0x8f27c8
waitmovement 0x0
sound 0x9
hidesprite 0x3
checksound
applymovement 0x1 ow_script_movs_0x8f0a0b
waitmovement 0x0
sound 0x9
hidesprite 0x1
checksound
applymovement 0xff ow_script_movs_0x8f0981
waitmovement 0x0
goto ow_script_0x8c7d62


.global ow_script_0x8c7d62
ow_script_0x8c7d62:
loadpointer 0x0 str_0x8f0984
callstd MSG_KEEPOPEN
fanfare 0x13e
loadpointer 0x0 str_0x8c7f7a
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
additem ITEM_VM01 0x1
loadpointer 0x0 str_0x8c7f9a
callstd MSG
fadescreen 0x1
hidesprite 0x2
fadescreen 0x0
addvar STORY_PROGRESS 0x2
releaseall
end
