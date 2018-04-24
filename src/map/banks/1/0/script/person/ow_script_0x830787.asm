.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x830787
ow_script_0x830787:
loadpointer 0x0 str_0x8ef678
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8ef678

str_0x8ef678:
    .string "Ich bin hierher gekommen, um dem\nlegendären Zeitpokemon zu\lbegegnen. Wo es sich wohl\lversteckt?"
        
        
.elseif LANG_EN

.endif
