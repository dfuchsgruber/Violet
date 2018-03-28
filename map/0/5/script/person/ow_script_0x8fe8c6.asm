.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fe8c6
ow_script_0x8fe8c6:
loadpointer 0x0 str_0x8fecef
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8fecef

str_0x8fecef:
    .string "Man kann die Hitze der Wüste\nförmlich spüren. Der Ausgang muss\lnah sein."
        
        
.elseif LANG_EN

.endif
