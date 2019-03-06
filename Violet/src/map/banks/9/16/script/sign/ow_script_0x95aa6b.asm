.include "callstds.s"
.include "species.s"
.include "overworld_script.s"


.global ow_script_0x95aa6b
ow_script_0x95aa6b:
special 0x31
pause 0x1
showpokepic POKEMON_ARMALDO 0x4 0x4
loadpointer 0x0 str_0x95a60e
callstd MSG_SIGN
setvar 0x8004 0x187
special 0x163
hidepokepic
end


.ifdef LANG_GER
.global str_0x95a60e

str_0x95a60e:
    .string "Der goldene Nachbau des fossilen\nPokémons Armaldo.\pEs schimmert rötlich im fahlen\nLicht der Museumslampen."
        
        
.elseif LANG_EN

.endif
