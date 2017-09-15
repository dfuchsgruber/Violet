.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8127a9
ow_script_0x8127a9:
lock
faceplayer
loadpointer 0x0 str_0x8127cb
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8127f3
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x89bda0
end


.global ow_script_0x89bda0
ow_script_0x89bda0:
loadpointer 0x0 str_0x8dc0e4
callstd MSG_KEEPOPEN
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
loadpointer 0x0 str_0x118d600
callasm 0x9190001
goto ow_script_0x8faf29


.global ow_script_0x8faf29
ow_script_0x8faf29:
callasm 0x919d791
clearflag TRANS_DISABLE
warpmuted 0xf 0x1 0x1 0x6 0x4
end


.global ow_script_0x8127f3
ow_script_0x8127f3:
loadpointer 0x0 str_0x8127fe
callstd MSG_FACE
release
end
