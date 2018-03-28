.include "overworld_script.s"

.include "std.s"

.global ow_script_0x949db1
ow_script_0x949db1:
loadpointer 0x0 str_0x94dabc
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94dabc

str_0x94dabc:
    .string "Hast du je von Lucius, dem\nDrachentöter gehört?\pEs heißt, er hat sein Leben der\nJagd nach der großen Schlange, die\lin den Wolken wohnt, gewidmet."
        
        
.elseif LANG_EN

.endif
