.include "overworld_script.s"
.include "callstds.s"

.global ow_script_flavor_text_laz_corp_secret_power_tree

ow_script_flavor_text_laz_corp_secret_power_tree:
    loadpointer 0x0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Die Bäume hier haben viel Laub verloren und generell wirkt der Boden schmutzig und voller Erde.\pWoran die Forscher wohl arbeiten?"
.elseif LANG_EN
str_0:
    .autostring 34 2 "The trees here have lost a lot of leaves and the ground generally looks dirty and full of soil.\pWhat are the researchers working on?"
.endif
