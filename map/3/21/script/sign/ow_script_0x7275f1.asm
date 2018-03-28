.include "overworld_script.s"

.include "std.s"

.global ow_script_0x7275f1
ow_script_0x7275f1:
loadpointer 0x0 str_0x926b0a
callstd MSG
fadescreen 0x1
fanfare 0x100
waitfanfare
fadescreen 0x0
special 0x0
loadpointer 0x0 str_0x926b6d
callstd MSG
end


.ifdef LANG_GER
.global str_0x926b0a

str_0x926b0a:
    .string "Ein Brunnen! Das frische Wasser\nwird den erschöpften Pokémon\lhelfen."
        
        
.global str_0x926b6d

str_0x926b6d:
    .string "Die Pokémon von PLAYER wurden\nvollständig geheilt."
        
        
.elseif LANG_EN

.endif
