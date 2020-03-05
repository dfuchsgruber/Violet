.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8f1dca
ow_script_0x8f1dca:
loadpointer 0x0 str_0x8f1dd4
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f1dd4

str_0x8f1dd4:
    .string "Diese Frau in dem KanuDOTS\nSie ist so wunderschön! Aber ich\lkann einfach nicht genug Mut\lfinden, sie anzusprechen!"
        
        
.elseif LANG_EN

.endif
