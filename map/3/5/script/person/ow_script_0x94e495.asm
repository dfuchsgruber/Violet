.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94e495
ow_script_0x94e495:
loadpointer 0x0 str_0x94e49f
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94e49f

str_0x94e49f:
    .string "Der Kontrast aus Blumen und Metall\nmacht Orina City zu dem schönen\lOrt, der es ist."
        
        
.elseif LANG_EN

.endif
