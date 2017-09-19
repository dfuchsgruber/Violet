.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8f3bfa
ow_script_movs_0x8f3bfa:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8f3d64
ow_script_0x8f3d64:
lock
faceplayer
checkflag POKERADAR
gotoif EQUAL ow_script_0x8efcd3
loadpointer 0x0 str_0x8f3c00
callstd MSG
setvar 0x8004 0x1
special2 0x800d 0xd4
buffernumber 0x2 0x8006
compare 0x8006 0xa
gotoif LESS ow_script_0x8f3bfd
sound 0x15
applymovement 0x800f ow_script_movs_0x8f3bfa
waitmovement 0x0
loadpointer 0x0 str_0x8f3cd9
callstd MSG
fanfare 0x13e
lock
faceplayer
loadpointer 0x0 str_0x8f3bc4
callstd MSG_KEEPOPEN
lock
faceplayer
waitfanfare
lock
faceplayer
loadpointer 0x0 str_0x8f3a57
callstd MSG
setflag POKERADAR
release
end


.global ow_script_0x8f3bfd
ow_script_0x8f3bfd:
release
end


.global ow_script_0x8efcd3
ow_script_0x8efcd3:
loadpointer 0x0 str_0x8f39d8
callstd MSG_FACE
end
