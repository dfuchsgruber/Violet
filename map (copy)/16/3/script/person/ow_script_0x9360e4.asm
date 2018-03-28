.include "overworld_script.s"

.include "std.s"

.global ow_script_0x9360e4
ow_script_0x9360e4:
trainerbattlestd 0x0 0x7d 0x0 str_0x93baf6 str_0x93bb5e
loadpointer 0x0 str_0x93bb5e
callstd MSG_FACE
end

.global str_0x93baf6

str_0x93baf6:
    .string "Hey! Diese Waren hat die\nRevolution in Kaskada erworben.\lIch werde sie dir nicht kampflos\lüberlassen!"
        
        
.global str_0x93bb5e

str_0x93bb5e:
    .string "Diese Waren sind sehr wertvoll für\nuns, bitte respektiere das!"
        
        