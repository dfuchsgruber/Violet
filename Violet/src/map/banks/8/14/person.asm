.include "overworld_script.s"
.include "callstds.s"

.global ow_script_kaskada_black_market_exit_person_0

ow_script_kaskada_black_market_exit_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Wie kommst du denn hierher?\pDieser Geheimgang sollteDOTS\pDOTSnaja, ein Geheimnis bleiben, verstehst du?\pDu erzählst aber keinem hiervon, oder?"
.elseif LANG_EN
.endif