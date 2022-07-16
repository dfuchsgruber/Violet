.include "overworld_script.s"
.include "callstds.s"
.include "ingame_trades.s"
.include "ordinals.s"
.include "vars.s"
.include "flags.s"

.global ow_script_kuestenberg_clouds_person_0
.global ow_script_kuestenberg_clouds_person_1
.global ow_script_kuestenberg_clouds_person_2
.global ow_script_kuestenberg_clouds_person_3
.global ow_script_kuestenberg_clouds_ingame_trade

ow_script_kuestenberg_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_kuestenberg_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_kuestenberg_clouds_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_kuestenberg_clouds_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end

ow_script_kuestenberg_clouds_ingame_trade:
	lock
	faceplayer
	setvar 0x8008, INGAME_TRADE_SEEMON
	call ow_script_ingame_trade_get_species_info
	checkflag FLAG_KUESTENBERG_CLOUDS_INGAME_TRADE
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
	setflag FLAG_KUESTENBERG_CLOUDS_INGAME_TRADE
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
    .autostring 34 2 "Als Angler hat man nicht viel Auswahl, was die Pokémon im eigenen Team betrifft.\pDabei hätte ich so gerne ein Elektro-Pokémon.\pGanz besonders ein BUFFER_1 würde mir sehr gut gefallen!\pMöchtest du vielleicht deines gegen mein BUFFER_2 tauschen?"
str_decline_trade:
    .autostring 34 2 "Nein?\pWie ärgerlich!\pDabei sind die Pokémon die ich an Land ziehe von höchster Qualität!"
str_wrong_species:
    .autostring 34 2 "Moment!\pSo was das aber nicht ausgemacht.\pIch wollte doch ein BUFFER_1 habenDOTS"
str_already_traded:
    .autostring 34 2 "Vielen Dank!\pDu hast mir wirklich zu großem Glück verholfen, indem du mir ein BUFFER_1 gegeben hast.\pDamit besiege ich jetzt meine Angler Konkurrenten bestimmt."
str_after_trade:
    .autostring 34 2 "Das ist ausgezeichnet!\pMit diesem BUFFER_1 haben meine Konkurrenten aus der Anglerszene keine Chance mehr.\pDanke vielmals!"
str_0:
    .autostring 34 2 "Ach, die Seeluft über dem Küstenberg ist wirklich unvergleichlich.\pAm liebsten würde ich mir hier ein Haus bauen.\pAber wie komme ich hier oben an die Materialien?"
str_1:
    .autostring 34 2 "Hast du schonmal von der versunkenen Stadt Atlantea gehört?\pMan erzählt sich, dass sie die Hauptstadt dieses untergangenen Königreichs im Himmel gewesen sein soll."
str_2:
    .autostring 34 2 "Ich frage mich, was die Menschen, die einmal hier oben gelebt haben, wohl gegessen habenDOTS"
str_3:
    .autostring 34 2 "Man kommt gar nicht hinterher, einem Flug-Pokémon beim Fliegen zuzuschauen!\pFantastisch!"
.elseif LANG_EN
str_0:
    .autostring 34 2 "Ah, the salty air above the Shore Hill really is unique.\pIf I could I would build myself a house up here."
str_1:
    .autostring 34 2 "Did you ever hear about the sunken city?\pIt is said that it once served as bridge to the world above the clouds."
.endif
