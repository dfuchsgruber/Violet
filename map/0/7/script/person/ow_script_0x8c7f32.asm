.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8c7f32
ow_script_0x8c7f32:
loadpointer 0x0 str_0x8c8e19
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8c8e19

str_0x8c8e19:
    .string "Diese Höhle hat sich im Laufe der\nJahre mit Meereswasser gefüllt.\pSie liegt direkt unterhalb von\nKaskada, der Stadt der Quellen und\ldes Wassers."
        
        
.elseif LANG_EN

.endif
