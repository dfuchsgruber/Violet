.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x898284
ow_script_0x898284:
loadpointer 0x0 str_0x8a20ee
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a20ee

str_0x8a20ee:
    .string "Mit der versteckten Maschiene\nZertrümmerer kann man diese Felsen\lzerschmetternDOTS Jedoch muss der\lTrainer auch die nötige\lQualifikation besitzen, meine ich."
        
        
.elseif LANG_EN

.endif
