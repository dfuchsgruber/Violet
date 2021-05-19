.include "callstds.s"
.include "overworld_script.s"
.include "species.s"
.include "flags.s"
.include "ordinals.s"
.include "ingame_trades.s"
.include "vars.s"
.include "specials.s"

.global ow_script_map_5_11_person_1
.global ow_script_map_5_11_person_0
.global ow_script_bluetenbach_ingame_trade

ow_script_map_5_11_person_0:
    loadpointer 0x0 str_0
    callstd MSG_FACE
    end
ow_script_map_5_11_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_bluetenbach_ingame_trade:
	lock
	faceplayer
	setvar 0x8008, POKEMON_CAMAUB
	call ow_script_ingame_trade_get_species_info
	checkflag FLAG_BLUETENBACH_INGAME_TRADE
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
	setflag FLAG_BLUETENBACH_INGAME_TRADE
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
str_0:
    .autostring 34 2 "Ich erinnere mich noch, als unser Arenaleiter Manuel ein kleiner Junge war.\pEr hat nichts anderes getan, als den ganzen Tag trainiert.\pJetzt ist er einer der stärksten Männer der Region.\pIch bewundere jemanden, der mit solcher Entschlossenheit an seinen Zielen festhält."
str_1:
    .autostring 34 2 "Blütenbach mag ja ganz nett seinDOTS\pAber es ist so öde hier!\pWer will schon den ganzen Tag Ruhe haben?\pWenn ich älter bin, werde ich nach Orina City ziehen.\pDa ist man immer im Zentrum des Geschehens!"
str_want_to_trade:
    .autostring 34 2 "Du bist ein Trainer oder?\pIch bin verrückt nach dem Pokémon BUFFER_1.\pMöchtest du ein BUFFER_1 gegen mein BUFFER_2 tauschen?"
str_decline_trade:
    .autostring 34 2 "Das kann ich dir schlecht übel nehmen.\pImmerhin ist BUFFER_1 ein fantastisches Pokémon."
str_wrong_species:
    .autostring 34 2 "Moment mal!\pDas ist ja ein BUFFER_2.\pDas will ich aber nicht haben.\pIch bin auf der Suche nach BUFFER_1."
str_already_traded:
    .autostring 34 2 "Ich bin ja so glücklich, dass ich jetzt ein BUFFER_1 besitze!"
str_after_trade:
    .autostring 34 2 "Ich kann dir gar nicht sagen, wie glücklich mich das macht!\pVielen Dank!"
.elseif LANG_EN
str_0:
    .autostring 34 2 "I still remember when your gym leader Manuel was just a boy.\pAll day would do nothing but to train.\pNow he is one of the strongest men in this region.\pI really admire people who pursue their goals with that much determination."
str_1:
    .autostring 34 2 "Sure, Petal Creek may be a nice place to liveDOTS\pBut it is so boring here!\pWho wants no action all day anyway?\pWhen I am older I will move to Orina City.\pThere, you are always in the middle of everything!"
.endif