.include "overworld_script.s"
.include "flags.s"
.include "callstds.s"
.include "ordinals.s"

.global ow_script_antike_ruine_regirock_braille

ow_script_antike_ruine_regirock_braille:
    lock
    checkflag FLAG_REGIROCK_PUZZLE_SOLVED
    gotoif EQUAL opened
    braille braille1
    waitkeypress
    braille_close
    release
    end

opened:
    loadpointer 0 str_0
    callstd MSG_SIGN
    release
    end

.ifdef LANG_GER
braille1:
    .autostring 12 2 "BRAILLE_LBRAILLE_EBRAILLE_UBRAILLE_CBRAILLE_HBRAILLE_TBRAILLE_E BRAILLE_IBRAILLE_M BRAILLE_ZBRAILLE_EBRAILLE_NBRAILLE_TBRAILLE_RBRAILLE_UBRAILLE_M"
str_0:
    .autostring 12 2 "Ein Eingang ist erschienen!"

.elseif LANG_EN
braille1:
    .autostring 12 2 "BRAILLE_SBRAILLE_HBRAILLE_IBRAILLE_NBRAILLE_E BRAILLE_IBRAILLE_N BRAILLE_TBRAILLE_HBRAILLE_E BRAILLE_CBRAILLE_EBRAILLE_NBRAILLE_TBRAILLE_EBRAILLE_R"
str_0:
    .autostring 12 2 "An entrance has appeared!"
.endif