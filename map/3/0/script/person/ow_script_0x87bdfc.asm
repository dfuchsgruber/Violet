.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x87bdfc
ow_script_0x87bdfc:
loadpointer 0x0 str_0x89bed9
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x89bed9

str_0x89bed9:
    .string "Sieh mal, ich habe ein Pokémon.\nLos Azurill!\l...\lEs kuschelt lieber mit mir als zu\lkämpfen..."
        
        
.elseif LANG_EN

.endif
