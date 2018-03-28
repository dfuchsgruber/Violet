.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94e4f4
ow_script_0x94e4f4:
loadpointer 0x0 str_0x94e4fe
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94e4fe

str_0x94e4fe:
    .string "Die Schurken, die von den Top Vier\nper Steckbrief gesucht werden,\lsind wahre Ganoven."
        
        
.elseif LANG_EN

.endif
