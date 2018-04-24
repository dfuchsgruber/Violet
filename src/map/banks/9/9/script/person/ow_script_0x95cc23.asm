.include "flags.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x95cc23
ow_script_0x95cc23:
checkflag ORINA_CITY_DONNERSTEIN
gotoif EQUAL ow_script_0x95cc66
lock
faceplayer
loadpointer 0x0 str_0x95cd1c
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_DONNERSTEIN
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95cc5b
loadpointer 0x0 str_0x95ccac
callstd MSG
setflag ORINA_CITY_DONNERSTEIN
release
end


.global ow_script_0x95cc5b
ow_script_0x95cc5b:
loadpointer 0x0 str_0x95cc70
callstd MSG
release
end


.global ow_script_0x95cc66
ow_script_0x95cc66:
loadpointer 0x0 str_0x95ccac
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95cd1c

str_0x95cd1c:
    .string "Ich bin bei der Laz.Corp im\nBereich Energieforschung\langestellt.\lDieser Stein enthält sehr viel\lelektrische Energie."
        
        
.global str_0x95ccac

str_0x95ccac:
    .string "Der Donnerstein kann durch seine\nhohe energetische Aktivität einem\lElektro-Pokémon zur Entwicklung\lverhelfen."
        
        
.global str_0x95cc70

str_0x95cc70:
    .string "Oh...! Es scheint, du hast keinen\nPlatz in deinem Beutel!"
        
        
.elseif LANG_EN

.endif
