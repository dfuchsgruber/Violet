.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8a2d6c
ow_script_0x8a2d6c:
loadpointer 0x0 str_0x8a36af
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a36af

str_0x8a36af:
    .string "Hunger! Ich habe Hunger! Mami soll\nendlich Essen machen! Hunger!"
        
        
.elseif LANG_EN

.endif
