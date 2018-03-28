.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x94ea35
ow_script_0x94ea35:
loadpointer 0x0 str_0x953b28
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x953b28

str_0x953b28:
    .string "Eigentlich ist es mir verboten,\ndarüber zu sprechen, aber ich bin\lso aufgeregt!\pDie Laz.Corp arbeitet seit langem\nan der Synthese künstlicher\lPokémon und vor einigen Tagen ist\luns endlich der Durchbruch\lgelungen."
        
        
.elseif LANG_EN

.endif
