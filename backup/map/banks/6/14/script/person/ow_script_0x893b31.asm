.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x893b31
ow_script_0x893b31:
loadpointer 0x0 str_0x8ced64
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8ced64

str_0x8ced64:
    .string "Es heißt, dass die ersten Menschen\nüberhaupt den Tempel auf dieser\lInsel erbaut haben sollen.\pEine Schande, dass er nun mehr in\neinem derartigen Zustand verweilt."
        
        
.elseif LANG_EN

.endif
