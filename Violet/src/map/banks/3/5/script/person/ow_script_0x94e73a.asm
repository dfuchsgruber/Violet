.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x94e73a
ow_script_0x94e73a:
loadpointer 0x0 str_0x94e744
callstd MSG
end


.ifdef LANG_GER
.global str_0x94e744

str_0x94e744:
    .string "Verkatert und pleiteDOTS\nIch fühle mich fast wieder wie ein\lStudentDOTS"
        
        
.elseif LANG_EN

.endif
