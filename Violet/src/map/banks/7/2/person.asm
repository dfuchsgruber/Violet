.include "callstds.s"
.include "overworld_script.s"
.include "species.s"
.include "flags.s"
.include "ordinals.s"
.include "ingame_trades.s"
.include "vars.s"

.global ow_script_map_7_2_person_0
.global ow_script_kranzdorf_ingame_trade

ow_script_map_7_2_person_0:
    loadpointer 0x0 str_0x8df230
    callstd MSG_FACE
    end

ow_script_kranzdorf_ingame_trade:
	lock
	faceplayer
	setvar 0x8008, INGAME_TRADE_ZWIRRLICHT
	call ow_script_ingame_trade_get_species_info
	checkflag FLAG_KRANZDORF_INGAME_TRADE
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
	setflag FLAG_KRANZDORF_INGAME_TRADE
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
str_0x8df230:
    .autostring 34 2 "Im Kranzwald soll ein Pokémon leben, das durch die Zeit reisen kann.\pDas ist doch spannend, oder?"
str_want_to_trade:
    .autostring 34 2 "Mein seltsamer Onkel aus Ceometria hat mir ein Pokémon geschenktDOTS\pAber um ehrlich zu sein, jagt es mir Angst ein.\pWillst du mir ein BUFFER_1 für mein BUFFER_2 geben?"
str_decline_trade:
    .autostring 34 2 "Oh manDOTS\pEin BUFFER_1 würde mir viel weniger Angst einjagenDOTS"
str_wrong_species:
    .autostring 34 2 "Ich will ja nicht wählerisch wirkenDOTS\pAber ich habe mir schon lange ein BUFFER_1 gewünscht, ja?"
str_already_traded:
    .autostring 34 2 "Dieses BUFFER_1 ist wirklich knuffig!\pDu hast mir wirklich einen Stein vom Herzen genommen."
str_after_trade:
    .autostring 34 2 "Endlich bin ich dieses gruselige Pokémon losDOTS"
.elseif LANG_EN

.endif