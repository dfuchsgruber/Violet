.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8f088f
ow_script_0x8f088f:
checkflag SILVANIA_FOREST_RIN
gotoif EQUAL ow_script_0x8f4675
loadpointer 0x0 str_0x8f461a
callstd MSG_FACE
end


.global ow_script_0x8f4675
ow_script_0x8f4675:
loadpointer 0x0 str_0x8f4d9d
callstd MSG_FACE
end

.global str_0x8f461a

str_0x8f461a:
    .string "Ich muss hier so lange Wache\nhalten, bis Rin ihre Mission im\lSilvania-Wald erledigt hat!"
        
        
.global str_0x8f4d9d

str_0x8f4d9d:
    .string "... Äh ... in dieser Version bin\nich zwar noch hier, in der\lnächsten aber werde ich dir den\lWeg schon freigemacht haben!"
        
        