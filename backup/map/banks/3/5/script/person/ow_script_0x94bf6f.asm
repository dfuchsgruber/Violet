.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x94bf6f
ow_script_0x94bf6f:
loadpointer 0x0 str_0x94dddb
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94dddb

str_0x94dddb:
    .string "Hast du je vom berüchtigten\nPiraten Blackbeard gehört?\pEr handelt mit gestohlenen Pokémon\nund karpert Handelsschiffe.\pAuf seine Ergreifung wurde eine\nhohe Belohnung ausgesetzt."
        
        
.elseif LANG_EN

.endif
