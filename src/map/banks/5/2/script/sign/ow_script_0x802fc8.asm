.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x802fc8
ow_script_0x802fc8:
loadpointer 0x0 str_0x80eb27
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x80eb27

str_0x80eb27:
    .string "Ein Fernsehbericht über Theto vor\nüber 1000 Jahren! Wie interessant!"
        
        
.elseif LANG_EN

.endif
