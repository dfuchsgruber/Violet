.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x744752
ow_script_0x744752:
trainerbattlestd 0x0 0x5f 0x0 str_0x74476a str_0x7453a9
loadpointer 0x0 str_0x7453a9
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x74476a

str_0x74476a:
    .string "Meine kleine, rebellische Schwester\nist vor kurzem auch Trainer\lgeworden! DOTS Sie trainiert auf\lRoute 2!"
        
        
.global str_0x7453a9

str_0x7453a9:
    .string "HmpfDOTS Ich dachte, ich hätte eine\nChance!"
        
        
.elseif LANG_EN

.endif
