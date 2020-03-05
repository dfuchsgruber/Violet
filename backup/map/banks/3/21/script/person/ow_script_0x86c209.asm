.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x86c209
ow_script_0x86c209:
loadpointer 0x0 str_0x86ca74
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x86ca74

str_0x86ca74:
    .string "Verdammt, immer wenn ich dem\nBrunnen zu nahe komme,\lverschwindet er wieder!"
        
        
.elseif LANG_EN

.endif
