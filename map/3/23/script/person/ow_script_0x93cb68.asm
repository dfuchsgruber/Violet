.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x93cb68
ow_script_0x93cb68:
compare KARMA_VALUE 0x7fff
gotoif HIGHER ow_script_0x93d65f
loadpointer 0x0 str_0x93d5fd
callstd MSG_FACE
end


.global ow_script_0x93d65f
ow_script_0x93d65f:
loadpointer 0x0 str_0x948bab
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x93d5fd

str_0x93d5fd:
    .string "Ich habe gehört, dass Menschen,\ndie sich dem Himmel verbunden\lfühlen, auf Wolken reiten können."
        
        
.global str_0x948bab

str_0x948bab:
    .string "Was machst du denn so einen\ngrimmigen Gesichtsausdruck?\lHat dir irgendetwas die Laune am\lLeben verdorben?"
        
        
.elseif LANG_EN

.endif
