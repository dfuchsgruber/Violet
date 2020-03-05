.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95b70f
ow_script_0x95b70f:
loadpointer 0x0 str_0x95c8bf
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95c8bf

str_0x95c8bf:
    .string "Selbst die Lobby dieser Firma\nstrahlt einen unvergleichlichen\lFuturismus aus."
        
        
.elseif LANG_EN

.endif
