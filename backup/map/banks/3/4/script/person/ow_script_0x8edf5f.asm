.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8edf5f
ow_script_0x8edf5f:
loadpointer 0x0 str_0x8f1adb
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f1adb

str_0x8f1adb:
    .string "Was soll das heißen, ich kann hier\nnicht angeln?\pWas denkst du, was ich hier seit\nStunden treibe?"
        
        
.elseif LANG_EN

.endif
