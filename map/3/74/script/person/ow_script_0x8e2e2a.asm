.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e2e2a
ow_script_0x8e2e2a:
trainerbattlestd 0x0 0x38 0x0 str_0x8e6784 str_0x8e67f6
loadpointer 0x0 str_0x8e67f6
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8e6784

str_0x8e6784:
    .string "Viele ziehen ihre Pokémon nur zum\nKämpfen auf. Sie mit Liebe zu\lbehandeln ist allerdings nicht\lweniger wichtig."
        
        
.global str_0x8e67f6

str_0x8e67f6:
    .string "Eine Niederlage ist absolut keine\nSchande. Meine Pokémon haben ihr\lBestes gegeben."
        
        
.elseif LANG_EN

.endif
