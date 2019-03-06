.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x743daf
ow_script_0x743daf:
trainerbattlestd 0x0 0x68 0x0 str_0x744635 str_0x7446c2
loadpointer 0x0 str_0x7446c2
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x744635

str_0x744635:
    .string "Als ich mich in der Nähe eines\ngoldenen Kaktusses aufgehalten\lhabe, hat mich ein Tuska\langefallen.\lIch habe es gefangen!"
        
        
.global str_0x7446c2

str_0x7446c2:
    .string "Mein TuskaDOTS."
        
        
.elseif LANG_EN

.endif
