.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_5_2_sign_0
.global ow_script_map_5_2_sign_1

ow_script_map_5_2_sign_1:
loadpointer 0x0 str_0x80eaf8
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x80eaf8:
    .string "Ein Bücherregal. Ich fasse es\nbesser nicht an."


.elseif LANG_EN

.endif


ow_script_map_5_2_sign_0:
loadpointer 0x0 str_0x80eb27
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x80eb27:
    .string "Ein Fernsehbericht über Theto vor\nüber 1000 Jahren! Wie interessant!"


.elseif LANG_EN

.endif