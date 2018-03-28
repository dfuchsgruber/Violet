.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c7f4d
ow_script_0x8c7f4d:
loadpointer 0x0 str_0x8f1430
callstd MSG_FACE
end

.global str_0x8f1430

str_0x8f1430:
    .string "Das Wasser, das diese Stadt\numgibt, entspringt dem Küstenberg.\lViele nennen ihn auch den Berg des\lUrquells."
        
        