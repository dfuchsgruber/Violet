.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c8e05
ow_script_0x8c8e05:
loadpointer 0x0 str_0x931979
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x931979

str_0x931979:
    .string "Du machst dir also die Mühe, mit\nallen Statisten zu sprechen?\pNein im Ernst, das ist toll!\pIch verrate dir im Gegenzug ein\nGeheimnis. Viele der Stände hier\lwerden erst in späteren Versionen\lsinnvoll besetzt sein.\pGedulde dich einfach ein bisschen!"
        
        
.elseif LANG_EN

.endif
