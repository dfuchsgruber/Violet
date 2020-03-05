.include "overworld_script.s"

.global script_wondertrade_failure

script_wondertrade_failure:
    loadpointer 0 str_wondertrade_not_possible_script
    callstd 6
    end




@ // Strings

.global str_wondertrade_not_possible_script

.ifdef LANG_GER

	str_wondertrade_not_possible_script:
    	.string "Verbindung zum Wundertausch-\nNetzwerk fehlgeschlagen (BUFFER_1/250)."

.elseif LANG_EN

	str_wondertrade_not_possible_script:
		.string "Failed to connect to the\nWondertrade-Network (BUFFER_1/250)."

.endif
