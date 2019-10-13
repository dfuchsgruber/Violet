.include "overworld_script.s"
.include "callstds.s"

.global ow_script_aktania_ruins_sign

ow_script_aktania_ruins_sign:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "QUOTE_STARTEin uraltes Volk lebte einst hier und huldigte in diesen Tempel den legendären Pokémon.QUOTE_END"
.elseif LANG_EN
str_0:
    .autostring 34 2 "QUOTE_STARTThe ancient people that lived here used these temples to whoreship the legendary pokémon.QUOTE_END"
.endif