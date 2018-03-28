.include "overworld_script.s"

.include "std.s"

.global ow_script_0x961cf2
ow_script_0x961cf2:
trainerbattlestd 0x0 0xa0 0x0 str_0x96317e str_0x9631b1
loadpointer 0x0 str_0x9631b1
callstd MSG_FACE
end

.global str_0x96317e

str_0x96317e:
    .string "Wanderschaft trainiert den Körper\nausgezeichnet."
        
        
.global str_0x9631b1

str_0x9631b1:
    .string "Oh, du bist wohl auch recht viel\nunterwegs?"
        
        