.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "species.s"

.global ow_script_0x959475
.global ow_script_map_9_16_sign_6
.global ow_script_map_9_16_sign_1
.global ow_script_map_9_16_sign_4
.global ow_script_0x95a5a3
.global ow_script_map_9_16_sign_5
.global ow_script_map_9_16_sign_8
.global ow_script_map_9_16_sign_3
.global ow_script_map_9_16_sign_2
.global ow_script_map_9_16_sign_9
.global ow_script_map_9_16_sign_0
.global ow_script_map_9_16_sign_10
.global ow_script_map_9_16_sign_7

ow_script_map_9_16_sign_4:
loadpointer 0x0 str_0x95a700
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x95a700:
    .autostring 34 2 "Das Gemälde zeigt ein von Lava umgebenes rotes monströses Wesen.\pIst das etwa ein antikes Pokémon?"


.elseif LANG_EN

.endif


ow_script_map_9_16_sign_0:
checkflag ORINA_CITY_VIOLET_GRUNTS
gotoif EQUAL ow_script_0x959475
loadpointer 0x0 str_0x95a56d
callstd MSG
end


ow_script_0x959475:
loadpointer 0x0 str_0x95a56d
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x959487
callstd MSG
end


.ifdef LANG_GER

str_0x95a56d:
    .autostring 34 2 "QUOTE_STARTDas Magmaherz\pEntdeckt und ausgegraben von Professor Tann.QUOTE_END"



str_0x959487:
    .autostring 34 2 "Das Schild wurde durchgestrichenDOTS"


.elseif LANG_EN

.endif


ow_script_map_9_16_sign_1:
    loadpointer 0 str_wolkenherz
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_wolkenherz:
    .autostring 34 2 "Wolkengestein.\pEin Federleichtes Mineral, das vor vielen Jahren als Baustoff diente."
.elseif LANG_EN
.endif

ow_script_map_9_16_sign_5:
    loadpointer 0x0 str_0x95a74c
    callstd MSG_SIGN
    end


.ifdef LANG_GER

str_0x95a74c:
    .autostring 34 2 "Eine unwirkliche Anmut geht von diesem Gemälde aus.\pEs zeigt ein in Licht einghülltes Wesen, das von hoch oben auf die Welt herabsieht.\pIst das etwaDOTS?"

.elseif LANG_EN

.endif


ow_script_map_9_16_sign_6:
loadpointer 0x0 str_0x95a7ef
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x95a7ef:
    .autostring 34 2 "Auf diesem Gemälde ist ein blaues riesiges Wesen zu sehen, das gebieterisch über den Meeresboden wacht.\pOb es sich um ein antikes Pokémon handelt?"

.elseif LANG_EN

.endif


ow_script_map_9_16_sign_7:
loadpointer 0x0 str_0x95a873
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x95a873:
    .autostring 34 2 "Ein grünes langes Wesen bricht mit scheinbar atemberaubender Geschwindigkeit durch die Wolkendecke.\pExistieren überhaupt Pokémon, die so groß sind?"


.elseif LANG_EN

.endif


ow_script_map_9_16_sign_8:
loadpointer 0x0 str_0x95a8da
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x95a8da:
    .string "Hinter der Vitrine liegt ein\nFossil, dessen Konturen scharf\lzu sein scheinen.\lDas Fossil ist mit QUOTE_STARTDomfossilQUOTE_END\lbetitelt."


.elseif LANG_EN

.endif


ow_script_map_9_16_sign_9:
loadpointer 0x0 str_0x95a95c
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x95a95c:
    .string "Hinter der Vitrine liegt ein\nFossil, dessen Kontruen eine\lglitschige Wölbung aufweisen.\pEs wurde mit QUOTE_STARTHelixfossilQUOTE_END\nbetitelt."


.elseif LANG_EN

.endif


ow_script_map_9_16_sign_10:
loadpointer 0x0 str_0x95a9e4
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x95a9e4:
    .string "Viele bunt funkelnde Steine und\nBodenproben sind hier ausgestellt.\pKaum vorstellbar, dass derart alte\nDinge noch immer erhalten sind."


.elseif LANG_EN

.endif


ow_script_map_9_16_sign_2:
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

str_0x95a60e:
    .string "Der goldene Nachbau des fossilen\nPokémons Armaldo.\pEs schimmert rötlich im fahlen\nLicht der Museumslampen."


.elseif LANG_EN

.endif


ow_script_map_9_16_sign_3:
special 0x31
pause 0x1
showpokepic POKEMON_AERODACTYL 0x4 0x4
loadpointer 0x0 str_0x95a692
callstd MSG_SIGN
setvar 0x8004 0x8e
special 0x163
hidepokepic
end


.ifdef LANG_GER

str_0x95a692:
    .string "Das Skelett des fossilen Pokémons\nAerodactyl.\pEs breitet seine Schwingen mit\neiner beängstigenden Anmut aus."


.elseif LANG_EN

.endif