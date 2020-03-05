.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8e2b15
ow_script_0x8e2b15:
trainerbattlestd 0x0 0x32 0x0 str_0x8e2b2d str_0x8e2ba1
loadpointer 0x0 str_0x8e2ba1
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8e2b2d

str_0x8e2b2d:
    .string "Viele Wanderer treten den\nbeschwerlichen Pfad durch die\lÖdnis und Wüste nach Kaskada an.\pDas zeugt von Fähigkeit."
        
        
.global str_0x8e2ba1

str_0x8e2ba1:
    .string "In Kaskada erwarten einen die\nreinsten Wasserquellen der ganzen\lRegion, so sagt man."
        
        
.elseif LANG_EN

.endif
