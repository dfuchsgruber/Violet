.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x81c4d0
ow_script_0x81c4d0:
loadpointer 0x0 str_0x8772e2
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x8772e2

str_0x8772e2:
    .string "Dieses Feature ist in der Version\nnoch nicht implementiert."
        
        
.elseif LANG_EN

.endif
