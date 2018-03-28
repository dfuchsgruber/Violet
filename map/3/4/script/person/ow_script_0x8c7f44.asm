.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c7f44
ow_script_0x8c7f44:
loadpointer 0x0 str_0x8f13dc
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f13dc

str_0x8f13dc:
    .string "Seit geraumer Zeit schon frage ich\nmich, was sich wohl in dieser\lHöhle befindet..."
        
        
.elseif LANG_EN

.endif
