.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x89510a
ow_script_movs_0x89510a:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x895106
ow_script_movs_0x895106:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x894c1d
ow_script_0x894c1d:
lockall
applymovement 0x13 ow_script_movs_0x89510a
applymovement 0x12 ow_script_movs_0x89510a
waitmovement 0x0
applymovement 0x13 ow_script_movs_0x895106
waitmovement 0x0
setvar 0x8000 0x1
setvar 0x8001 0x9
setvar 0x8002 0xe
special 0x6
loadpointer 0x0 str_0x895067
callstd MSG
special 0x7
setvar 0x8000 0x0
setvar 0x8001 0xa
setvar 0x8002 0xe
special 0x6
loadpointer 0x0 str_0x894fc0
callstd MSG
special 0x7
setvar 0x8000 0x1
setvar 0x8001 0x9
setvar 0x8002 0xe
special 0x6
loadpointer 0x0 str_0x894f22
callstd MSG
special 0x7
setvar 0x8000 0x0
setvar 0x8001 0xa
setvar 0x8002 0xe
special 0x6
loadpointer 0x0 str_0x894e61
callstd MSG
special 0x7
sound 0xbd
fadescreen 0x1
fadesong MUS_0
loadpointer 0x0 str_0x894ccb
callstd MSG
fadesong MUS_GLUTBERG_AND_EISKASKADENHOHLE_AND_WANDELHOHLE_AND_VERLORENE_HOHLE_AND_NABELFELS
fadescreen 0x0
goto ow_script_0x8962e8


.global ow_script_movs_0x895326
ow_script_movs_0x895326:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x89526f
ow_script_movs_0x89526f:
.byte STEP_LEFT
.byte STEP_UP
.byte STOP


.global ow_script_0x8962e8
ow_script_0x8962e8:
setvar DYN_MULTICHOICE_ITEM_CNT 0x2
loadpointer 0x0 str_0x89593f
multichoice 0x0 0x0 0x0 0x1
copyvar 0x8000 LASTRESULT
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare 0x8000 0x0
gotoif EQUAL ow_script_0x895493
loadpointer 0x0 str_0x895445
callstd MSG
copyvarifnotzero 0x8000 ITEM_BELEBER
copyvarifnotzero 0x8001 1
callstd ITEM_FIND
call ow_script_0x895abc
setvar 0x8000 0x0
setvar 0x8001 0xa
setvar 0x8002 0xe
special 0x6
loadpointer 0x0 str_0x8953cf
callstd MSG
special 0x7
setvar 0x8000 0x1
setvar 0x8001 0x9
setvar 0x8002 0xe
special 0x6
loadpointer 0x0 str_0x89532f
callstd MSG
special 0x7
applymovement 0x12 ow_script_movs_0x895326
waitmovement 0x0
hidesprite 0x12
setflag ROUTE_2_GIRL_WITH_LOST_ITEM
setvar 0x8000 0x0
setvar 0x8001 0xa
setvar 0x8002 0xe
special 0x6
loadpointer 0x0 str_0x895273
callstd MSG
special 0x7
applymovement 0x13 ow_script_movs_0x89526f
waitmovement 0x0
applymovement 0x13 ow_script_movs_0x895326
waitmovement 0x0
hidesprite 0x13
releaseall
end


.global ow_script_0x895abc
ow_script_0x895abc:
setvar LASTRESULT 0xfa
special2 0x800d 0xc
return


.global ow_script_0x895493
ow_script_0x895493:
goto ow_script_0x89586b


.global ow_script_movs_0x896294
ow_script_movs_0x896294:
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STEP_RIGHT
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x89586b
ow_script_0x89586b:
loadpointer 0x0 str_0x895854
callstd MSG
hidesprite 0x11
applymovement 0x12 ow_script_movs_0x896294
waitmovement 0x0
setvar 0x8000 0x1
setvar 0x8001 0x9
setvar 0x8002 0xe
special 0x6
loadpointer 0x0 str_0x895823
callstd MSG
special 0x7
fanfare 0x13e
loadpointer 0x0 str_0x899fad
callstd MSG
waitfanfare
setvar 0x8000 0x0
setvar 0x8001 0xa
setvar 0x8002 0xe
special 0x6
loadpointer 0x0 str_0x895760
callstd MSG
special 0x7
applymovement 0x13 ow_script_movs_0x89526f
waitmovement 0x0
applymovement 0x13 ow_script_movs_0x895326
waitmovement 0x0
hidesprite 0x13
setvar 0x8000 0x1
setvar 0x8001 0x9
setvar 0x8002 0xe
special 0x6
goto ow_script_0x895913


.global ow_script_movs_0x89629a
ow_script_movs_0x89629a:
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_LEFT
.byte STOP


.global ow_script_0x895913
ow_script_0x895913:
loadpointer 0x0 str_0x89569f
callstd MSG
special 0x7
applymovement 0x12 ow_script_movs_0x89629a
waitmovement 0x0
applymovement 0x12 ow_script_movs_0x895326
waitmovement 0x0
hidesprite 0x12
call ow_script_0x8963a6
releaseall
end


.global ow_script_0x8963a6
ow_script_0x8963a6:
setvar LASTRESULT 0x5
special2 0x800d 0xc
return
