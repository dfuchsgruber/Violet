.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a19d4
ow_script_0x8a19d4:
loadpointer 0x0 str_0x94568f
callstd MSG_FACE
call ow_script_0x945619
callif EQUAL ow_script_0x8faec2
end


.global ow_script_movs_0x8f511a
ow_script_movs_0x8f511a:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8faec2
ow_script_0x8faec2:
applymovement 0x800f ow_script_movs_0x8f511a
waitmovement 0x0
loadpointer 0x0 str_0x945eb7
callstd MSG_YES_NO
compare LASTRESULT 0x1
callif LESS ow_script_0x8a1a57
loadpointer 0x0 str_0x8a1be6
callstd MSG
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
setvar 0x8005 0x12
call ow_script_0x1c9086
clearflag TRANS_DISABLE
compare LASTRESULT 0x0
callif EQUAL ow_script_0x8a1a57
call ow_script_0x9455aa
loadpointer 0x0 str_0x94618b
callstd MSG
end


.global ow_script_0x9455aa
ow_script_0x9455aa:
setvar 0x8000 0x69
setvar 0x8001 0x1
checkitem ITEM_RIESENPILZ 0x3
compare LASTRESULT 0x1
callif LESS ow_script_0x9455d9
setvar 0x8000 0x68
setvar 0x8001 0x3
removeitem ITEM_RIESENPILZ 0x3
goto ow_script_0x9455e4


.global ow_script_0x9455e4
ow_script_0x9455e4:
bufferitem 0x0 0x8000
buffernumber 0x1 0x8001
return


.global ow_script_0x9455d9
ow_script_0x9455d9:
removeitem ITEM_SPV_ORB_N 0x1
goto ow_script_0x9455e4


.global ow_script_0x8a1a57
ow_script_0x8a1a57:
loadpointer 0x0 str_0x945830
callstd MSG
end


.global ow_script_0x1c9086
ow_script_0x1c9086:
special 0x18d
waitstate
lock
faceplayer
return


.global ow_script_0x945619
ow_script_0x945619:
setvar 0x8000 0x67
setvar 0x8001 0x3
checkitem ITEM_MINIPILZ 0x3
compare LASTRESULT 0x1
callif EQUAL ow_script_0x9455ee
setvar 0x8000 0x68
setvar 0x8001 0x1
checkitem ITEM_RIESENPILZ 0x1
compare LASTRESULT 0x1
callif EQUAL ow_script_0x9455ee
setvar LASTRESULT 0x0
goto ow_script_0x945662


.global ow_script_0x945662
ow_script_0x945662:
bufferitem 0x0 0x8000
buffernumber 0x1 0x8001
return


.global ow_script_0x9455ee
ow_script_0x9455ee:
setvar LASTRESULT 0x1
goto ow_script_0x945662
