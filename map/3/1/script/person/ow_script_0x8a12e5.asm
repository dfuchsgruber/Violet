.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a12e5
ow_script_0x8a12e5:
loadpointer 0x0 str_0x8a2cd5
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a2cd5

str_0x8a2cd5:
    .string "Route 1 liegt direkt am Fuße des\nWassergebirges. Nördlich von hier,\lüber den Wassertunnel, erreicht\lman die Stadt Kaskada."
        
        
.elseif LANG_EN

.endif
