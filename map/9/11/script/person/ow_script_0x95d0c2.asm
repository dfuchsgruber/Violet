.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95d0c2
ow_script_0x95d0c2:
loadpointer 0x0 str_0x95d0cc
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95d0cc

str_0x95d0cc:
    .string "Papi findet Opi ganz doll öde!\nDer öde Opi! Juhu!"
        
        
.elseif LANG_EN

.endif
