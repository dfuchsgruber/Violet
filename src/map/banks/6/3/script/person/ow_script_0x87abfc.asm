.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x87abfc
ow_script_0x87abfc:
loadpointer 0x0 str_0x89a7c6
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x89a7c6

str_0x89a7c6:
    .string "Einst war das hier ein schöner\nOrt. Es war grauenvoll: Mein Sohn\l- ein beigeisterter Schwimmer -\lverschwand an diesem Tag spurlos\lzusammen mit anderen Urlaubern.\lMan hat sie nie wieder gesehen..."
        
        
.elseif LANG_EN

.endif
