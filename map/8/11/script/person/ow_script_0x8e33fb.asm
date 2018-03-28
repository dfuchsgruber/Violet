.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e33fb
ow_script_0x8e33fb:
trainerbattlestd 0x0 0x72 0x0 str_0x931a72 str_0x92df3b
loadpointer 0x0 str_0x92df3b
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x931a72

str_0x931a72:
    .string "Lord Albus ist der Bringer einer\nneuen Welt! Heil ihm!"
        
        
.global str_0x92df3b

str_0x92df3b:
    .string "Hast du nicht genug gesehen?\pStellst du dich uns wieder in die\nQuere?"
        
        
.elseif LANG_EN

.endif
