.include "callstds.s"
.include "species.s"
.include "overworld_script.s"


.global ow_script_0x94da56
ow_script_0x94da56:
cry POKEMON_VOLTILAMM 0x0
loadpointer 0x0 str_0x94da65
callstd MSG
end


.ifdef LANG_GER
.global str_0x94da65

str_0x94da65:
    .string "Vol! Voltilamm!"
        
        
.elseif LANG_EN

.endif
