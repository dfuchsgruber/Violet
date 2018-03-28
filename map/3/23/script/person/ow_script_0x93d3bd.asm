.include "overworld_script.s"

.include "std.s"

.global ow_script_0x93d3bd
ow_script_0x93d3bd:
loadpointer 0x0 str_0x949bd4
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x949bd4

str_0x949bd4:
    .string "Wir sind Wolkenpriester und\nWolkenreiter und verehren den\lHimmel.\pUnsere Tradition reicht bis zu den\nAnfängen der Geschichte zurück.\pEines Tages wird der große grüne\nDrache erneut herabsteigen und ein\lneues Zeitalter einläuten."
        
        
.elseif LANG_EN

.endif
