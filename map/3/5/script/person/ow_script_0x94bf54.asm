.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94bf54
ow_script_0x94bf54:
loadpointer 0x0 str_0x94dc4d
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94dc4d

str_0x94dc4d:
    .string "Selbst nach den vielen Jahren, die\nich nun in Orina City lebe, bin\lich von den Hochhausschluchten\lnoch immmer fasziniert."
        
        
.elseif LANG_EN

.endif
