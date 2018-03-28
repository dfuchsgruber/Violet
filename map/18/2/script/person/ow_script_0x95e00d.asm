.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95e00d
ow_script_0x95e00d:
loadpointer 0x0 str_0x95e017
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95e017

str_0x95e017:
    .string "Route 6 ist ein wirklich\nunangenehm heißer Ort.\pDu solltest dir etwas leichters\nanziehen, bevor du dich dort\lhinbegiebst..."
        
        
.elseif LANG_EN

.endif
