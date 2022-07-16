.include "callstds.s"
.include "overworld_script.s"
.include "ingame_trades.s"
.include "ordinals.s"
.include "vars.s"
.include "flags.s"

.global ow_script_map_9_11_person_1
.global ow_script_map_9_11_person_2
.global ow_script_map_9_11_person_3
.global ow_script_map_9_11_person_0
.global ow_script_orina_city_ingame_trade

ow_script_map_9_11_person_0:
loadpointer 0x0 str_0x95cf0e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95cf0e:
    .string "Wer du nicht sein kannst, der\nsollst du auch nicht sein.\pDas ist eine Weisheit, die ich\njedem auf den Weg mitgeben will."


.elseif LANG_EN

.endif


ow_script_map_9_11_person_1:
loadpointer 0x0 str_0x95cf92
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95cf92:
    .string "Dass meine Frau ihren Vater bei\nuns wohnen lässt, stört mich\lprinzipiell zwar nichtDOTS\pAber diese schrecklichen\nLebensweisheiten, mit denen er die\lFamilie bei Langeweile hältDOTS"


.elseif LANG_EN

.endif


ow_script_map_9_11_person_3:
loadpointer 0x0 str_0x95d04f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95d04f:
    .string "Mein Mann hat insgeheim ein\nProblem mit meinem Vater.\pEr gibt es zwar nicht zu, aber er\nkann ihn nicht ausstehen."


.elseif LANG_EN

.endif


ow_script_map_9_11_person_2:
    loadpointer 0x0 str_0x95d0cc
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0x95d0cc:
    .string "Papi findet Opi ganz doll öde!\nDer öde Opi! Juhu!"
.elseif LANG_EN
.endif


ow_script_orina_city_ingame_trade:
	lock
	faceplayer
	setvar 0x8008, INGAME_TRADE_MAGNETON
	call ow_script_ingame_trade_get_species_info
	checkflag FLAG_ORINA_CITY_INGAME_TRADE
    gotoif 1 already_traded
    loadpointer 0 str_want_to_trade
    callstd MSG_YES_NO
	compare LASTRESULT, 0
	gotoif EQUAL decline_trade
	call ow_script_ingame_trade_choose_party_idx_to_trade
	compare 0x8004, 6
	gotoif HIGHER_OR_EQUAL decline_trade
	call ow_script_ingame_trade_get_trade_species
	comparevars LASTRESULT, 0x8009
	gotoif NOT_EQUAL wrong_species
	call ow_script_ingame_trade
	loadpointer 0 str_after_trade
	setflag FLAG_ORINA_CITY_INGAME_TRADE
	release
	end

decline_trade:
	call ow_script_ingame_trade_get_species_info
	loadpointer 0 str_decline_trade
    callstd MSG
	release
	end

wrong_species:
	copyvar 0x8000, LASTRESULT
	call ow_script_ingame_trade_get_species_info
	bufferpokemon 1, 0x8000
	loadpointer 0 str_wrong_species
	callstd MSG
	release
	end

already_traded:
	loadpointer 0 str_already_traded
	callstd MSG
	release
	end

.ifdef LANG_GER
str_want_to_trade:
    .autostring 34 2 "Mein Freund ist bei der Laz. Corp. angestellt.\pAber dann hat er angefangen, sich mit meiner besten Freundin zu treffen.\pAus Rache habe ich beschlossen, sein Lieblingspokémon wegzugeben.\pMöchtest du ein BUFFER_1 gegen sein BUFFER_2 tauschen?"
str_decline_trade:
    .autostring 34 2 "Du willst mir nicht helfen?\pDas ist wirklich schade, ich würde meinem Freund zu gerne eins auswischen."
str_wrong_species:
    .autostring 34 2 "Willst du mich vereppeln?\pIch habe dir doch gesagt, dass ich ein BUFFER_1 haben möchte!"
str_already_traded:
    .autostring 34 2 "Da wird sich mein Freund aber freuen, wenn er sieht, dass ich sein geliebtes Pokémon für ein BUFFER_1 weggegeben habe."
str_after_trade:
    .autostring 34 2 "Das wird meinem Freund eine Lehre sein!\pDu musst nämlich wissen, dass mein Freund wirklich überhaupt nichts für das Pokémon BUFFER_1 übrig hat."
.elseif LANG_EN
.endif
