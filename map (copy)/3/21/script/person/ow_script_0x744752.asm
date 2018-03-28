.include "overworld_script.s"

.include "std.s"

.global ow_script_0x744752
ow_script_0x744752:
trainerbattlestd 0x0 0x5f 0x0 str_0x74476a str_0x7453a9
loadpointer 0x0 str_0x7453a9
callstd MSG_FACE
end

.global str_0x74476a

str_0x74476a:
    .string "Meine kleine, rebellische Schwester\nist vor kurzem auch Trainer\lgeworden! ... Sie trainiert auf\lRoute 2!"
        
        
.global str_0x7453a9

str_0x7453a9:
    .string "Hmpf... Ich dachte, ich hätte eine\nChance!"
        
        