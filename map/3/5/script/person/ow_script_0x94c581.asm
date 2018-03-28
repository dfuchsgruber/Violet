.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x94c581
ow_script_0x94c581:
loadpointer 0x0 str_0x94e0de
callstd MSG
end


.ifdef LANG_GER
.global str_0x94e0de

str_0x94e0de:
    .string "Mit deinem Flug-Pokémon hast du\nkeine Chance!\lVoltilamm, Donnerschock!"
        
        
.elseif LANG_EN

.endif
