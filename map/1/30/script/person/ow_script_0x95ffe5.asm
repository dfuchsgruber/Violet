.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95ffe5
ow_script_0x95ffe5:
trainerbattlestd 0x0 0x9d 0x0 str_0x962cce str_0x962d24
loadpointer 0x0 str_0x962d24
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x962cce

str_0x962cce:
    .string "Ich bin eine Lady von hoher\nGeburt. Es geziemt sich, dass du\ldich kampflos ergibst."
        
        
.global str_0x962d24

str_0x962d24:
    .string "Dir fehlt die Gallanz!\nRüpelhaftes Benehmen..."
        
        
.elseif LANG_EN

.endif
