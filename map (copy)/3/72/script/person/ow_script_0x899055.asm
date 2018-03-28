.include "overworld_script.s"

.include "std.s"

.global ow_script_0x899055
ow_script_0x899055:
call ow_script_0x89db71
loadpointer 0x0 str_0x89f18d
callstd MSG_FACE
special 0x7
end

.global ow_script_0x89db71
ow_script_0x89db71:
setvar 0x8000 0x1
setvar 0x8001 0x8
special 0x6
return
.global str_0x89f18d

str_0x89f18d:
    .string "Oh... ich habe kein gutes\nGefühl bei dem Test..."
        
        