.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95836a
ow_script_0x95836a:
loadpointer 0x0 str_0x959066
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x959066

str_0x959066:
    .string "Mistral war bereits ein Kommandant\nder Revolutionsbewegung.\pEr ist bestens ausgebildet und\nmacht keine halben Sachen.\pNimm dich lieber in Acht, Bursche!"
        
        
.elseif LANG_EN

.endif
