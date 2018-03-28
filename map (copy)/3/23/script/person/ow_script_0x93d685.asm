.include "overworld_script.s"

.include "std.s"

.global ow_script_0x93d685
ow_script_0x93d685:
trainerbattlestd 0x0 0x87 0x0 str_0x9498a0 str_0x94994a
loadpointer 0x0 str_0x94994a
callstd MSG_FACE
end

.global str_0x9498a0

str_0x9498a0:
    .string "Hast du es schon gehört?\pDie Laz.Corp will diesen Monat\nnoch ein Produkt namens Poképad\lauf den Markt bringen.\pAls Ass-Trainer muss ich mir das\nauf jeden Fall ansehen."
        
        
.global str_0x94994a

str_0x94994a:
    .string "Wie, du besitzt bereits ein\nPoképad?"
        
        