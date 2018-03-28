.include "overworld_script.s"

.include "std.s"

.global ow_script_0x87e9dc
ow_script_0x87e9dc:
loadpointer 0x0 str_0x87f2d9
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x87f2d9

str_0x87f2d9:
    .string "Bist du mit den Entscheidungen,\ndie du getroffen hast, zufrieden?\lStehst du hinter dem, was du getan\lhast? Hättest du mehr tun sollen?"
        
        
.elseif LANG_EN

.endif
