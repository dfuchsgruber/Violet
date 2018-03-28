.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8f1dca
ow_script_0x8f1dca:
loadpointer 0x0 str_0x8f1dd4
callstd MSG_FACE
end

.global str_0x8f1dd4

str_0x8f1dd4:
    .string "Diese Frau in dem Kanu...\nSie ist so wunderschön! Aber ich\lkann einfach nicht genug Mut\lfinden, sie anzusprechen!"
        
        