.include "overworld_script.s"

.include "std.s"

.global ow_script_0x948ce3
ow_script_0x948ce3:
trainerbattlestd 0x0 0x8a 0x0 str_0x94c11f str_0x94c18b
loadpointer 0x0 str_0x94c18b
callstd MSG_FACE
end

.global str_0x94c11f

str_0x94c11f:
    .string "Willst du wissen, wie man wieder\nzum Boden zurückkehrt?\pIch werde es dir verraten, wenn du\nmich besiegst!"
        
        
.global str_0x94c18b

str_0x94c18b:
    .string "Also gut! An einer Stelle, an\nwelcher die Wolken wieder\ldurchlässig sind, kannst du zum\lBoden zurückkehren.\pDu erkennst die Stellen an dunklen\nFlecken im Wolkengrund."
        
        