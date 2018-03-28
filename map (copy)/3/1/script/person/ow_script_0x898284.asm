.include "overworld_script.s"

.include "std.s"

.global ow_script_0x898284
ow_script_0x898284:
loadpointer 0x0 str_0x8a20ee
callstd MSG_FACE
end

.global str_0x8a20ee

str_0x8a20ee:
    .string "Mit der versteckten Maschiene\nZertrümmerer kann man diese Felsen\lzerschmettern... Jedoch muss der\lTrainer auch die nötige\lQualifikation besitzen, meine ich."
        
        