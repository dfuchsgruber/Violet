.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86bbbd
ow_script_0x86bbbd:
loadpointer 0x0 str_0x86ef43
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x86ef43

str_0x86ef43:
    .string "Du bist der doch der Junge aus dem\nOrina City Museum.\pHat dich Mistral nicht gewarnt,\nihm fernzubleiben?"
        
        
.elseif LANG_EN

.endif
