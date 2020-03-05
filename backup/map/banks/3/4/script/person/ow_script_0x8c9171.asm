.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8c9171
ow_script_0x8c9171:
loadpointer 0x0 str_0x8f192d
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f192d

str_0x8f192d:
    .string "Wenn meine Pokémon Kaskada\nbeherrschten, könnte ich mit ihnen\ldie Wasserfälle erklimmen."
        
        
.elseif LANG_EN

.endif
