.include "callstds.s"
.include "species.s"
.include "overworld_script.s"


.global ow_script_0x87aac1
ow_script_0x87aac1:
cry POKEMON_BIBOR 0x0
showpokepic POKEMON_BIBOR 0x0 0x0
loadpointer 0x0 str_0x87aad8
callstd MSG
hidepokepic
end


.ifdef LANG_GER
.global str_0x87aad8

str_0x87aad8:
    .string "BIBOR! BIBOR!"
        
        
.elseif LANG_EN

.endif
