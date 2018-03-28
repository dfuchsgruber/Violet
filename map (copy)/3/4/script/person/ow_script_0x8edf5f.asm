.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8edf5f
ow_script_0x8edf5f:
loadpointer 0x0 str_0x8f1adb
callstd MSG_FACE
end

.global str_0x8f1adb

str_0x8f1adb:
    .string "Was soll das heißen, ich kann hier\nnicht angeln?\pWas denkst du, was ich hier seit\nStunden treibe?"
        
        