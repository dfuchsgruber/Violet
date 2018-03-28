.include "overworld_script.s"

.include "std.s"

.global ow_script_0x858dda
ow_script_0x858dda:
loadpointer 0x0 str_0x965fe1
callstd MSG_FACE
end

.global str_0x965fe1

str_0x965fe1:
    .string "Ich traue mich nicht, den Vulkan\nzu besteigen...\pWas, wenn er gerade dann\nausbricht, während ich vor dem\lSchlot stehe?"
        
        