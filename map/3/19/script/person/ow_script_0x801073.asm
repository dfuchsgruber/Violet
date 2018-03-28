.include "overworld_script.s"

.include "std.s"

.global ow_script_0x801073
ow_script_0x801073:
lock
faceplayer
loadpointer 0x0 str_0x804215
callstd MSG
release
end


.ifdef LANG_GER
.global str_0x804215

str_0x804215:
    .string "Ich bin kein Trainer. Da ich kein\nPokémon besitze, können wir auch\lnicht kämpfen."
        
        
.elseif LANG_EN

.endif
