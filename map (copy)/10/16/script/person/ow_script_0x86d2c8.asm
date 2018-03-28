.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86d2c8
ow_script_0x86d2c8:
trainerbattlestd 0x0 0xac 0x0 str_0x86d2e0 str_0x86d328
loadpointer 0x0 str_0x86d328
callstd MSG_FACE
end

.global str_0x86d2e0

str_0x86d2e0:
    .string "Ich hasse diesen Job. Immer verirre\nich mich bei diesen Pfeilfeldern!"
        
        
.global str_0x86d328

str_0x86d328:
    .string "Ich brauche jeden Tag Stunden bis\nich meinen Platz gefunden habe!"
        
        