.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8aa963
ow_script_0x8aa963:
trainerbattlestd 0x0 0x11 0x0 str_0x8ab8e2 str_0x8abf92
loadpointer 0x0 str_0x8abf92
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8ab8e2

str_0x8ab8e2:
    .string "Mein Konkurent dort drüben meint,\ner würde es in Manus Arena\lschaffen. Dabei bin ich es, der\ldiesen Posten ergattern wird! Sieh\ldir nur an, wie viel ich trainiert\lhabe!"
        
        
.global str_0x8abf92

str_0x8abf92:
    .string "Dann muss ich wohl noch härter an\nmir und meinen Pokémon arbeiten!"
        
        
.elseif LANG_EN

.endif
