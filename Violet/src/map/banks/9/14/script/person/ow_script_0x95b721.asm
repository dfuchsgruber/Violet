.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95b721
ow_script_0x95b721:
loadpointer 0x0 str_0x95c9cb
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95c9cb

str_0x95c9cb:
    .string "Wusstest du, dass sich jede\nBeziehung zwischen Teilchen auf\lvier fundamentale Kräfte\lzurückführen lässt?\pDa wären die Gravitation und die\nelektromagnetische Kraft.\lDazu kommen die mysterösen starken\lund schwachen KernkräfteDOTS"
        
        
.elseif LANG_EN

.endif
