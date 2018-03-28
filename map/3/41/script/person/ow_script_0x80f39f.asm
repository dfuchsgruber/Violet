.include "overworld_script.s"

.include "std.s"

.global ow_script_0x80f39f
ow_script_0x80f39f:
trainerbattlestd 0x0 0x14 0x0 str_0x80f3b7 str_0x80f40b
loadpointer 0x0 str_0x80f40b
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x80f3b7

str_0x80f3b7:
    .string "Als Lady lehne ich keine\nHerausforderung ab! Benimm dich\laber gut!"
        
        
.global str_0x80f40b

str_0x80f40b:
    .string "Du hast dich nicht gut\nbenommen!"
        
        
.elseif LANG_EN

.endif
