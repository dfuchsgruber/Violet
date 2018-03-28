.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8e903e
ow_script_0x8e903e:
trainerbattlestd 0x0 0x47 0x0 str_0x8f4388 str_0x8f43ce
loadpointer 0x0 str_0x8f43ce
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f4388

str_0x8f4388:
    .string "In diesem Wald kann man Pokémon\ndes Typs Flug exzellent\ltrainieren!"
        
        
.global str_0x8f43ce

str_0x8f43ce:
    .string "Huch, du bist ein stärkerer Gegner\nals die wilden Pokémon in diesem\lWald."
        
        
.elseif LANG_EN

.endif
