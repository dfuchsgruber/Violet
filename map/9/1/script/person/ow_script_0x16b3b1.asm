.include "overworld_script.s"

.include "std.s"

.global ow_script_0x16b3b1
ow_script_0x16b3b1:
loadpointer 0x0 str_0x19675c
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x19675c

str_0x19675c:
    .string "Es ist wirklich eine Schande, dass\ndiese Stadt kein ordentliches\lEinkaufszentrum besitzt."
        
        
.elseif LANG_EN

.endif
