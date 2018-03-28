.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c8f61
ow_script_0x8c8f61:
loadpointer 0x0 str_0x8f1665
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f1665

str_0x8f1665:
    .string "Das Wasser hier ist so sauber,\ndass man direkt davon trinken\lkönnte."
        
        
.elseif LANG_EN

.endif
