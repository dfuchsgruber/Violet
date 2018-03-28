.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e33e4
ow_script_0x8e33e4:
trainerbattlestd 0x0 0x71 0x0 str_0x931930 str_0x9318e0
loadpointer 0x0 str_0x9318e0
callstd MSG_FACE
end

.global str_0x931930

str_0x931930:
    .string "Nja! Du schon wieder!\pDu wirst uns hier nicht auch die\nTour vermasseln!"
        
        
.global str_0x9318e0

str_0x9318e0:
    .string "Was ist dein Antrieb?\pSiehst du nicht, dass wir der Welt\nden Frieden bringen?"
        
        