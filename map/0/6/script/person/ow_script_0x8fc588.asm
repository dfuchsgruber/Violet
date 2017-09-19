.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fc588
ow_script_0x8fc588:
trainerbattlestd 0x0 0x5a 0x0 str_0x8fec28 str_0x8fec89
loadpointer 0x0 str_0x8fec89
callstd MSG_FACE
end
