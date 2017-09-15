.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86dd9c
ow_script_0x86dd9c:
checkflag 0x1e5
gotoif LESS ow_script_0x87afc7
end


.global ow_script_0x87afc7
ow_script_0x87afc7:
checkflag 0x1e4
gotoif EQUAL ow_script_0x87c9f4
loadpointer 0x0 str_0x87cae0
callstd MSG
end


.global ow_script_movs_0x87cadd
ow_script_movs_0x87cadd:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x87c9f4
ow_script_0x87c9f4:
checkflag 0x1e3
gotoif EQUAL ow_script_0x87ca4c
loadpointer 0x0 str_0x87caba
callstd MSG
pause 0x40
sound 0x15
applymovement 0xff ow_script_movs_0x87cadd
waitmovement 0x0
loadpointer 0x0 str_0x87ca86
callstd MSG
cry POKEMON_KLEINSTEIN 0x0
loadpointer 0x0 str_0x87ca4e
callstd MSG
waitcry
setvar 0x407c 0x1
setwildbattle POKEMON_KLEINSTEIN 0xc ITEM_NUGGET
dowildbattle
setmaptile 0x7 0x7 0x2fc 0x0
fadescreen 0x1
special 0x8e
fadescreen 0x0
setflag 0x1e3
end


.global ow_script_0x87ca4c
ow_script_0x87ca4c:
end
