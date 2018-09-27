.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8784c5
ow_script_0x8784c5:
loadpointer 0x0 str_0x881901
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x881901

str_0x881901:
    .string "Oh, hallo PLAYER! Wie geht es dir?\nDOTS\lFreut mich! Grüße doch bitte deine\lMutter von mir."
        
        
.elseif LANG_EN

.endif
