.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95f8ed
ow_script_0x95f8ed:
loadpointer 0x0 str_0x960444
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x960444

str_0x960444:
    .string "Der nette Herr in dem Haus dort\nist ein Künstler.\pEr stellt Flöten aus Asche her.\nDu solltest ihn besuchen."
        
        
.elseif LANG_EN

.endif
