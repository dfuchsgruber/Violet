.include "overworld_script.s"

.include "std.s"

.global ow_script_0x93a689
ow_script_0x93a689:
loadpointer 0x0 str_0x93c17a
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x93c17a

str_0x93c17a:
    .string "Woher Manus nur all die Mittel\nhat, ein derart gewaltiges Dojo zu\lerrichten?"
        
        
.elseif LANG_EN

.endif
