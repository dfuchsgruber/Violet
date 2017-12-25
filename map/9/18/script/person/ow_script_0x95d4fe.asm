.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x95d7ea
ow_script_movs_0x95d7ea:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x95d4fe
ow_script_0x95d4fe:
lock
faceplayer
loadpointer 0x0 str_0x95d7f0
callstd MSG
checkitem ITEM_HERZSCHUPPE 0x1
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95d7ed
sound 0x15
applymovement 0x800f ow_script_movs_0x95d7ea
waitmovement 0x0
loadpointer 0x0 str_0x95d771
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95d703
goto ow_script_0x95d53e


.global ow_script_0x95d53e
ow_script_0x95d53e:
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
loadpointer 0x0 str_0x95d618
callstd MSG_KEEPOPEN
special 0xdb
waitstate
clearflag TRANS_DISABLE
compare 0x8004 0x6
gotoif HIGHER_OR_EQUAL ow_script_0x95d703
special 0x148
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x95d6af
compare 0x8005 0x0
gotoif EQUAL ow_script_0x95d64e
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
loadpointer 0x0 str_0x95d5ee
callstd MSG_KEEPOPEN
special 0xe0
waitstate
clearflag TRANS_DISABLE
compare 0x8004 0x0
gotoif EQUAL ow_script_0x95d53e
removeitem ITEM_HERZSCHUPPE 0x1
loadpointer 0x0 str_0x95d5a7
callstd MSG
release
end


.global ow_script_0x95d64e
ow_script_0x95d64e:
loadpointer 0x0 str_0x95d659
callstd MSG
release
end


.global ow_script_0x95d6af
ow_script_0x95d6af:
loadpointer 0x0 str_0x95d6ba
callstd MSG
release
end


.global ow_script_0x95d703
ow_script_0x95d703:
loadpointer 0x0 str_0x95d70e
callstd MSG
release
end


.global ow_script_0x95d7ed
ow_script_0x95d7ed:
release
end