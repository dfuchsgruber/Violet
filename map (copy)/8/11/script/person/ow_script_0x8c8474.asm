.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c8474
ow_script_0x8c8474:
loadpointer 0x0 str_0x8c847e
callstd MSG_FACE
end

.global str_0x8c847e

str_0x8c847e:
    .string "Streng genommen ist er natürlich\nverboten, Fallen für Käfer-\lPokémon zu kaufen...\pAndererseits...\pWie sonst soll ich der größte\nKäfersammler aller Zeiten werden?"
        
        