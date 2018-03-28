.include "overworld_script.s"

.include "std.s"

.global ow_script_0x813b0a
ow_script_0x813b0a:
loadpointer 0x0 str_0x81ab8e
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x81ab8e

str_0x81ab8e:
    .string "Ich bin hierhergekommen, um die\nWaldluft zu genießen. Anordnung\lmeines Hausarztes."
        
        
.elseif LANG_EN

.endif
