.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x94e8a2
ow_script_0x94e8a2:
loadpointer 0x0 str_0x94e8ac
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94e8ac

str_0x94e8ac:
    .string "Diese Schweine von Bankiers haben\nmich bis auf letzten POKEDOLLAR\lausgenommen!"
        
        
.elseif LANG_EN

.endif
