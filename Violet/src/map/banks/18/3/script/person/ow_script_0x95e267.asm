.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95e267
ow_script_0x95e267:
loadpointer 0x0 str_0x95e271
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95e271

str_0x95e271:
    .string "Ich suche das Pokémon Panzaeron!\nEs heißt, dass es sehr selten ist\lund sich deswegen in den von Asche\lbedeckten Gräsern verstecktDOTS"
        
        
.elseif LANG_EN

.endif
