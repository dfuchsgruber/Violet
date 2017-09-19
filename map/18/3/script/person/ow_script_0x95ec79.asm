.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95ec79
ow_script_0x95ec79:
trainerbattlestd 0x0 0x97 0x0 str_0x95ec91 str_0x95ecf7
loadpointer 0x0 str_0x95ecf7
callstd MSG_FACE
end
