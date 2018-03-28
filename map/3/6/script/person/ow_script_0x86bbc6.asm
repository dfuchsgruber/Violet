.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86bbc6
ow_script_0x86bbc6:
loadpointer 0x0 str_0x965932
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x965932

str_0x965932:
    .string "Inferior wurde am Fuß des Volcanos\nerbaut.\pDie Legende besagt, dass hier die\nKönigin der Nacht die Pforten zur\lHölle geöffnet hat."
        
        
.elseif LANG_EN

.endif
