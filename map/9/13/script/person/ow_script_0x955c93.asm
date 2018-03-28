.include "overworld_script.s"

.include "std.s"

.global ow_script_0x955c93
ow_script_0x955c93:
loadpointer 0x0 str_0x955c9d
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x955c9d

str_0x955c9d:
    .string "Ich bin der Abteilungsleiter des\nCybernetik-Labors.\pSeit geraumer Zeit entwickeln wir\nein Pokémon, das vollständig am\lComputer entworfen wurde."
        
        
.elseif LANG_EN

.endif
