.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fb443
ow_script_0x8fb443:
loadpointer 0x0 str_0x9284d1
callstd MSG_FACE
end

.global str_0x9284d1

str_0x9284d1:
    .string "Immer häufiger sehe ich hier\ndubiouse Gestalten wandeln, die\laus dieser Höhle im Norden zu\lkommen scheinen."
        
        