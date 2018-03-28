.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a3b85
ow_script_0x8a3b85:
loadpointer 0x0 str_0x8a3b8f
callstd MSG_FACE
end

.global str_0x8a3b8f

str_0x8a3b8f:
    .string "Magst du Gedichte? Ich finde\nThomas Dylan fantastisch. Do not\lgo gentle into that good night...\lEin Meisterwerk, oder?"
        
        