.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x16a24d
ow_script_0x16a24d:
loadpointer 0x0 str_0x192a92
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x192a92

str_0x192a92:
    .autostring 36 2 "In der Ecke steht der PC.\pDort kannst du Pokémon lagern, solltest du keinen Platz in deinem Team haben."
        
        
.elseif LANG_EN

.endif
