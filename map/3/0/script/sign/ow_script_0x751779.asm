.include "overworld_script.s"

.include "std.s"

.global ow_script_0x751779
ow_script_0x751779:
checkflag 0x21c
callif LESS ow_script_0x7758df
checkflag 0x21e
callif EQUAL ow_script_0x756d9e
fanfare 0x13e
loadpointer 0x0 str_0x751875
callstd MSG
waitfanfare
setflag 0x21e
end


.global ow_script_0x756d9e
ow_script_0x756d9e:
loadpointer 0x0 str_0x772ee8
callstd MSG
end


.global ow_script_0x7758df
ow_script_0x7758df:
loadpointer 0x0 str_0x775933
callstd MSG
end
