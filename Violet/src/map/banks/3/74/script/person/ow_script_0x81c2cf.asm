.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x81c2cf
ow_script_0x81c2cf:
trainerbattlestd 0x0 0x3b 0x0 str_0x81c2e7 str_0x81c32b
loadpointer 0x0 str_0x81c32b
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x81c2e7

str_0x81c2e7:
    .string "Ein Ass-Trainer hat seine Pokémon\nstets ausgewogen zu trainieren!"
        
        
.global str_0x81c32b

str_0x81c32b:
    .string "Ein ausgewogenes Training ist der\nSchlüssel zum Erfolg!"
        
        
.elseif LANG_EN

.endif
