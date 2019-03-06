.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x93d311
ow_script_0x93d311:
trainerbattlestd 0x0 0x85 0x0 str_0x949732 str_0x9497bd
loadpointer 0x0 str_0x9497bd
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x949732

str_0x949732:
    .string "Diese Ruinen entstammen der Kultur\neines antiken Volkes.\pSie haben die Wolken und das\nsymbolisch dafür stehende Pokémon\lAltaria verehrt."
        
        
.global str_0x9497bd

str_0x9497bd:
    .string "Noch heute findet der Kult der\nWolkenmenschen Anhänger."
        
        
.elseif LANG_EN

.endif
