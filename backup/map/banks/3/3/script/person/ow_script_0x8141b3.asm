.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8141b3
ow_script_0x8141b3:
loadpointer 0x0 str_0x8e1ba8
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8e1ba8

str_0x8e1ba8:
    .string "Silvania wurde in einer Lichtung\ndes Silvania-Waldes von den\lErkundern dieser Region errichtet.\pIm Wald selbst haben sie auch\neinen Schrein gebaut, um dem darin\lwohnenden Zeitpokemon zu huldigen."
        
        
.elseif LANG_EN

.endif
