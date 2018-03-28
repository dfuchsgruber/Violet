.include "overworld_script.s"

.include "std.s"

.global ow_script_0x71ab78
ow_script_0x71ab78:
trainerbattlestd 0x0 0x50 0x0 str_0x71ab90 str_0x71abf9
loadpointer 0x0 str_0x71abf9
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x71ab90

str_0x71ab90:
    .string "Ich war schon am anderen Ausgang!\nDu willst wissen was dort ist? Ich\lsags dir, wenn du mich besiegst!"
        
        
.global str_0x71abf9

str_0x71abf9:
    .string "Dort ist eine grauenhafte Wüste!"
        
        
.elseif LANG_EN

.endif
