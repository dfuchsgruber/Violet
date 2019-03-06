.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8e2bf7
ow_script_0x8e2bf7:
trainerbattlestd 0x0 0x33 0x0 str_0x8e2c0f str_0x8e2c5c
loadpointer 0x0 str_0x8e2c5c
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8e2c0f

str_0x8e2c0f:
    .string "In körperlicher Form zu bleiben\nhat höchste Priorität für uns\lTriathleten!"
        
        
.global str_0x8e2c5c

str_0x8e2c5c:
    .string "Ich und meine Pokémon müssen\nhärter an uns arbeiten!"
        
        
.elseif LANG_EN

.endif
