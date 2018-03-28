.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8cef34
ow_script_0x8cef34:
loadpointer 0x0 str_0x8d41a0
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8d41a0

str_0x8d41a0:
    .string "Die Region Theto wird von vier\nvoneinander unabhängigen Trainern\lregiert, den Top Vier. Über ihnen\lsteht bloß der Champion."
        
        
.elseif LANG_EN

.endif
