.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x89690b
ow_script_0x89690b:
trainerbattlestd 0x0 0x1a 0x0 str_0x89837f str_0x89989f
loadpointer 0x0 str_0x89989f
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x89837f

str_0x89837f:
    .string "Mach dich auf was gefasst! Meine\nPokémon sind süß und gefährlich!"
        
        
.global str_0x89989f

str_0x89989f:
    .string "Vielleicht sind meine Pokémon auch\ndoch nur süß..."
        
        
.elseif LANG_EN

.endif
