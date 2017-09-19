.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8f4252
ow_script_movs_0x8f4252:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8f3dc4
ow_script_0x8f3dc4:
lock
faceplayer
loadpointer 0x0 str_0x8f3e79
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8f3e4a
checkattack ATTACK_NATUR_KRAFT
compare LASTRESULT 0x6
gotoif EQUAL ow_script_0x8f3e54
sound 0x15
applymovement 0x800f ow_script_movs_0x8f4252
waitmovement 0x0
loadpointer 0x0 str_0x8f3f3e
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8f3e5e
loadpointer 0x0 str_0x8f3fd0
callstd MSG
copyvar 0x8012 0x8013
setvar 0x8005 0x9
call ow_script_0x8f3e68
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8f3e5e
loadpointer 0x0 str_0x8f400a
callstd MSG
release
end


.global ow_script_0x8f3e5e
ow_script_0x8f3e5e:
loadpointer 0x0 str_0x8f41db
callstd MSG_FACE
end


.global ow_script_0x8f3e68
ow_script_0x8f3e68:
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
special 0x18d
waitstate
lock
faceplayer
clearflag TRANS_DISABLE
return


.global ow_script_0x8f3e54
ow_script_0x8f3e54:
loadpointer 0x0 str_0x8f4148
callstd MSG_FACE
end


.global ow_script_0x8f3e4a
ow_script_0x8f3e4a:
loadpointer 0x0 str_0x8f40f6
callstd MSG_FACE
end
