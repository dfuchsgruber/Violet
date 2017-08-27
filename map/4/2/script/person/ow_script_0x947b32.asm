.include "overworld_script.s"

.include "std.s"

.global ow_script_0x947b32
ow_script_0x947b32:
checkflag 0x201
callif EQUAL ow_script_0x89be13
loadpointer 0x0 str_0x89be1d
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x85e7fa
closeonkeypress
setflag 0x201
end


.global ow_script_0x85e7fa
ow_script_0x85e7fa:
loadpointer 0x0 str_0x89ae00
callstd MSG
setvar 0x8000 0xfd
special2 0x8000 0xc
return


.global ow_script_0x89be13
ow_script_0x89be13:
loadpointer 0x0 str_0x89be67
callstd MSG
end
