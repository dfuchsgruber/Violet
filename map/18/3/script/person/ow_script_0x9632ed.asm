.include "overworld_script.s"

.include "std.s"

.global ow_script_0x9632ed
ow_script_0x9632ed:
checkflag ROUTE_6_ASH_PRESENT
gotoif EQUAL ow_script_0x963590
checkflag ASHBAG_RECEIVED
gotoif LESS ow_script_0x963483
lock
faceplayer
loadpointer 0x0 str_0x9633f9
callstd MSG_KEEPOPEN
compare ASH 0xc15c
gotoif HIGHER ow_script_0x96334b
fanfare 0x13e
loadpointer 0x0 str_0x96332e
callstd MSG_KEEPOPEN
waitfanfare
setflag ROUTE_6_ASH_PRESENT
addvar ASH 0x1f4
goto ow_script_0x963590


.global ow_script_0x963590
ow_script_0x963590:
loadpointer 0x0 str_0x96359a
callstd MSG_FACE
end


.global ow_script_0x96334b
ow_script_0x96334b:
loadpointer 0x0 str_0x963356
callstd MSG
release
end


.global ow_script_0x963483
ow_script_0x963483:
loadpointer 0x0 str_0x96348d
callstd MSG_FACE
end
