.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a7379
ow_script_0x8a7379:
trainerbattlestd 0x0 0xb 0x0 str_0x8a9536 str_0x8a959f
loadpointer 0x0 str_0x8a959f
callstd MSG_FACE
end

.global str_0x8a9536

str_0x8a9536:
    .string "Unsere Sitten verkommen, die\nJugend verliert den Respekt. Bist\ldu auch eine solche rüpelhafte\lGestalt?"
        
        
.global str_0x8a959f

str_0x8a959f:
    .string "Ohne Zweifel leben in dir\nSittlichkeit und Anstand weiter.\lPass gut auf dich auf, Bursche."
        
        