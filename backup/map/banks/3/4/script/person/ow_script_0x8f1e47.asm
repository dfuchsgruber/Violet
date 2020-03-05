.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8f1e47
ow_script_0x8f1e47:
loadpointer 0x0 str_0x8f1e51
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f1e51

str_0x8f1e51:
    .autostring 34 2 "Zwar wird dieses Gebiet offiziell vom Pinken Faun regiertDOTS\pAber in Wirklichkeit zieht der Schwarze Devin hier die FädenDOTS"
        
        
.elseif LANG_EN

.endif
