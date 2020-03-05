.include "overworld_script.s"
.include "callstds.s"

.global ow_script_laubdorf_ruins_sign

ow_script_laubdorf_ruins_sign:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "QUOTE_STARTAls die Königin des Himmelreiches wähnte sich mächtig genug, die Götter dieser Welt herauszufordern.QUOTE_END"
.elseif LANG_EN
str_0:
    .autostring 34 2 "QUOTE_STARTThe queen of this realm thought herself powerful enough to challange the gods of this world.QUOTE_END"
.endif