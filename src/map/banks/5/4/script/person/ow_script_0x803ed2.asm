.include "callstds.s"
.include "species.s"
.include "overworld_script.s"


.global ow_script_0x803ed2
ow_script_0x803ed2:
cry POKEMON_CHANEIRA 0x0
loadpointer 0x0 str_0x80ebe5
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x80ebe5

str_0x80ebe5:
    .string "Chaneira! Chaneira!"
        
        
.elseif LANG_EN

.endif
