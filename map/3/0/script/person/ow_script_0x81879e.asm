.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81879e
ow_script_0x81879e:
fadesong 0x0
loadpointer 0x0 str_0x818854
callstd MSG
sound 0x23
checksound
loadpointer 0x0 str_0x8187f5
callstd MSG
call ow_script_0x85f911
end


.global ow_script_0x85f911
ow_script_0x85f911:
call ow_script_0x85e900
fadescreen 0x1
sound 0x64
loadpointer 0x0 str_0x8187d3
callstd MSG
checksound
writebytetooffset 0x2 0x2036e28
warpmuted 0x6 0x8 0x0 0x9 0xc
end


.global ow_script_0x85e900
ow_script_0x85e900:
return
