.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95cd92
ow_script_0x95cd92:
loadpointer 0x0 str_0x95cd9c
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95cd9c

str_0x95cd9c:
    .string "Im Fernsehen läuft zunehmend mehr\nMüll...\pIch frage mich, wann eine echte\nAlternative dazu aufkommt."
        
        
.elseif LANG_EN

.endif
