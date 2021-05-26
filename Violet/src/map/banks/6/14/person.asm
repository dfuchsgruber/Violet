.include "callstds.s"
.include "overworld_script.s"
.include "species.s"
.include "flags.s"
.include "ordinals.s"
.include "ingame_trades.s"
.include "vars.s"

.global ow_script_map_6_14_person_0
.global ow_script_map_6_14_person_1
.global ow_script_bruchfels_ingame_trade

ow_script_map_5_11_person_0:
    loadpointer 0x0 str_0
    callstd MSG_FACE
    end
ow_script_map_5_11_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_bruchfels_ingame_trade:
	lock
	faceplayer
	setvar 0x8008, INGAME_TRADE_SEEMOPS
	call ow_script_ingame_trade_get_species_info
	checkflag FLAG_BRUCHFELS_INGAME_TRADE
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
	setflag FLAG_BRUCHFELS_INGAME_TRADE
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


ow_script_map_6_14_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_map_6_14_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Als ich nach Bruchfels gezogen bin, war dieser Ort ein Strandparadies.\pViele Leute haben über diesen Ort wie über Haweiland geredet.\pJetzt ist hier alles völlig zerstörtDOTS"
str_1:
    .autostring 34 2 "Seit dem Unglück scheint hier in Bruchfels auch die Sonne nur noch selten.\pEs ist fast so, als wüsste das Wetter um die Tragödie, die diesen Ort heimgesucht hat."
str_want_to_trade:
    .autostring 34 2 "Als Jugendlicher war ich immer ein großer Bewunderer unseres ehemaligen Arenaleiters Roman.\pBesonders sein Onix hat mir imponiert.\pIch wäre bereit, mein BUFFER_2 gegen ein BUFFER_1 zu tauschen.\pWas sagst du dazu?"
str_decline_trade:
    .autostring 34 2 "Ich wünschte wirklich, ich besäße ein BUFFER_1, so wie Roman damals.\pEr war nichts geringeres als ein Held."
str_wrong_species:
    .autostring 34 2 "Huch, das ist ja ein BUFFER_2.\pIch interessiere mich aber für BUFFER_1, musst du wissen."
str_already_traded:
    .autostring 34 2 "Ich werde alles daran setzten, mein BUFFER_1 zu trainieren, bis es dem von Roman damals ebenbürtig ist."
str_after_trade:
    .autostring 34 2 "BUFFER_1!\pDu bist jetzt mein Andenken an den verstorbenen Arenaleiter Roman, der sich für unsere Stadt geopfert hat.\pDanke, dass du mir das ermöglichst."
.elseif LANG_EN
.endif