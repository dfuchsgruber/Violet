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
setweather 0
doweather
cry POKEMON_STARAPTOR 0x0
waitcry
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
setvar 0x8004 0xf
special 0x19
waitstate
setflag MAP_BGN_AUTO_ALIGN_OFF
waitstate

clearflag TRANS_DISABLE
clearflag MAP_BGN_AUTO_ALIGN_OFF
warpmuted 0xf 0x1 0x1 0x6 0x4
end


.global ow_script_0x8127f3
ow_script_0x8127f3:
loadpointer 0x0 str_0x8127fe
callstd MSG_FACE
release
end
