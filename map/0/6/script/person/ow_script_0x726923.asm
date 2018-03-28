.include "overworld_script.s"

.include "std.s"

.global ow_script_0x726923
ow_script_0x726923:
trainerbattlestd 0x0 0x56 0x0 str_0x8fb7a5 str_0x8fb810
loadpointer 0x0 str_0x8fb810
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8fb7a5

str_0x8fb7a5:
    .string "Ich bin hierher gekommen, um mir\neines der seltenen Fossil-Pokémon\lzu beschaffen."
        
        
.global str_0x8fb810

str_0x8fb810:
    .string "Du wirst sie mir nicht wegnehmen,\ndie Fossil-Pokémon!"
        
        
.elseif LANG_EN

.endif
