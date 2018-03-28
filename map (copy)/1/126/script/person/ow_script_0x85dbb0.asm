.include "overworld_script.s"

.include "std.s"

.global ow_script_0x85dbb0
ow_script_0x85dbb0:
trainerbattlestd 0x0 0xab 0x0 str_0x96628c str_0x9662f7
loadpointer 0x0 str_0x9662f7
callstd MSG_FACE
end

.global str_0x96628c

str_0x96628c:
    .string "Keke! Was ein kleiner Junge in\neinem Vulkan zu suchen hat?\pWas hat ein großer Junge hier\nverloren? Keke!"
        
        
.global str_0x9662f7

str_0x9662f7:
    .string "Na gut, ich gehe nach Hause..."
        
        