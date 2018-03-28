.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a12dc
ow_script_0x8a12dc:
loadpointer 0x0 str_0x8a2c84
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a2c84

str_0x8a2c84:
    .string "Ich trainiere hier so lange, bis\nich in der Lage bin, es mit Manus\laufzunehmen."
        
        
.elseif LANG_EN

.endif
