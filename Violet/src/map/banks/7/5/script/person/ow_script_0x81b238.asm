.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x81b238
ow_script_0x81b238:
trainerbattlestd 0x0 0x3a 0x0 str_0x81b250 str_0x81b289
loadpointer 0x0 str_0x81b289
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x81b250

str_0x81b250:
    .string "An den Hecken hier wachsen manchmal\nsogar rote Beeren!"
        
        
.global str_0x81b289

str_0x81b289:
    .string "Erzähl es nicht Mia, aber manchmal\nesse ich diese Beeren, wenn ich\lhungrig werde."
        
        
.elseif LANG_EN

.endif
