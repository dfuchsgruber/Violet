.include "overworld_script.s"

.include "std.s"

.global ow_script_0x72409e
ow_script_0x72409e:
trainerbattlestd 0x0 0x66 0x0 str_0x72458c str_0x7245ea
loadpointer 0x0 str_0x7245ea
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x72458c

str_0x72458c:
    .string "Soll ich dir ein Geheimnis über\ndiese Wüste verraten? Ich sags dir,\lwenn du mich besiegst!"
        
        
.global str_0x7245ea

str_0x7245ea:
    .string "Gut, das Geheimnis ist, dass es\nhier 2 Brunnen geben soll! Bisher\lhabe ich aber noch keinen\lgefunden..."
        
        
.elseif LANG_EN

.endif
