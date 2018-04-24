.include "overworld_script.s"
.include "items.s"
.include "callstds.s"
.include "flags.s"

.global ow_script_present_0

present_already_received:
    loadpointer 0 str_present_already_received
    callstd 6
    release
    end

ow_script_present_0:
    checkflag PRESENT_0
    gotoif 1 present_already_received
    loadpointer 0 str_present_0
    callstd 6
    copyvarifnotzero 0x8000 ITEM_SONDERBONBON
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    closeonkeypress
    setflag PRESENT_0
    release
    end



.ifdef LANG_GER

	.global str_present_0

	str_present_0:
		.string "Na siehst du, ganz einfach!\pAls Geschenk erhältst du von mir\ndies hier."


	.global str_present_already_received

	str_present_already_received:
		.string "Es tut mir leid, aber diesen\nGeschenkcode hast du wohl schon\leingelöst!\pEin Geschenkcode kann nur ein\neinziges Mal benutzt werden."

.elseif LANG_EN

	.global str_present_0

	str_present_0:
		.string "Easy going!\pAs reward you will get this here!"

	.global str_present_already_received

	str_present_already_received:
		.string "I am afraid but it seems that you\nalready used this present code.\pEvery single present code can\nonly be used once however."

.endif
    
