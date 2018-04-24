.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x803dab
ow_script_0x803dab:
loadpointer 0x0 str_0x80f654
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x80f654

str_0x80f654:
    .string "In dem Haus dort oben wohnt\nProfessor Tann. Du solltest ihn\lunbedingt mal besuchen!"
        
        
.elseif LANG_EN

.endif
