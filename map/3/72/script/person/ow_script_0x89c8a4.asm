.include "overworld_script.s"

.include "std.s"

.global ow_script_0x89c8a4
ow_script_0x89c8a4:
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8a0824
callstd MSG_FACE
special 0x7
end


.ifdef LANG_GER
.global str_0x8a0824

str_0x8a0824:
    .string "Und? Hattest du ein gutes Gefühl\nbei den Fragen?\pIch wollte euch die\nAngelegenheit nicht allzu leicht\lmachen, aber keine Sorge, der\lpraktische Teil kann den\ltheoretischen immer noch ausgleichen!"
        
        
.elseif LANG_EN

.endif
