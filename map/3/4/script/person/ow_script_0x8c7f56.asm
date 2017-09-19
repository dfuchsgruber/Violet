.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c7f56
ow_script_0x8c7f56:
compare KARMA_VALUE 0x7fff
gotoif HIGHER ow_script_0x8f154f
compare KARMA_VALUE 0x60
gotoif LESS_OR_EQUAL ow_script_0x8f1564
loadpointer 0x0 str_0x8f14e8
callstd MSG_FACE
end


.global ow_script_0x8f1564
ow_script_0x8f1564:
loadpointer 0x0 str_0x8f156e
callstd MSG_FACE
end


.global ow_script_0x8f154f
ow_script_0x8f154f:
compare KARMA_VALUE 0xffa0
gotoif HIGHER_OR_EQUAL ow_script_0x8f1564
loadpointer 0x0 str_0x8f15df
callstd MSG_FACE
end
