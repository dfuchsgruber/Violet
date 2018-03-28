.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95f8e4
ow_script_0x95f8e4:
loadpointer 0x0 str_0x95feaf
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95feaf

str_0x95feaf:
    .string "Bist du mit dem Angriff\nHitzekoller vertraut?\pEr gilt als einer der stärksten\nAngriffe des Typs Feuer."
        
        
.elseif LANG_EN

.endif
