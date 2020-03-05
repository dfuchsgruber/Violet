.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x819de2
ow_script_0x819de2:
trainerbattlestd 0x0 0x36 0x0 str_0x819dfa str_0x819e42
loadpointer 0x0 str_0x819e42
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x819dfa

str_0x819dfa:
    .string "Pflanzen können so viel gutes tun.\nMan kann sie sogar rauchenDOTS Ahh!"
        
        
.global str_0x819e42

str_0x819e42:
    .string "Nicht, als ob ich diese bestimmten\nPflanzen rauchen würde."
        
        
.elseif LANG_EN

.endif
