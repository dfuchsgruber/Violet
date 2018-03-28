.include "overworld_script.s"

.include "std.s"

.global ow_script_0x862528
ow_script_0x862528:
loadpointer 0x0 str_0x8ef978
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8ef978

str_0x8ef978:
    .string "Team Violet rekrutiert in der\nganzen Region Mitglieder. Sie\lversprechen einem, Teil von etwas\lgroßem, bedeutendem zu sein."
        
        
.elseif LANG_EN

.endif
