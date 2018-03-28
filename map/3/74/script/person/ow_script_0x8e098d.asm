.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8e098d
ow_script_0x8e098d:
trainerbattlestd 0x0 0x2f 0x0 str_0x8e10e9 str_0x8e18e8
loadpointer 0x0 str_0x8e18e8
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8e10e9

str_0x8e10e9:
    .string "Ein enges Band zu seinen Pokémon\nist für Erfolg essentiell."
        
        
.global str_0x8e18e8

str_0x8e18e8:
    .string "Mir scheint, du pfelgst eine sehr\ninnige Beziehung zu deinen\lPokémon."
        
        
.elseif LANG_EN

.endif
