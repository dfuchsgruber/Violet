.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"

.global ow_script_route_8_npc_0
.global ow_script_route_8_npc_1
.global ow_script_route_8_npc_2
.global ow_script_route_8_npc_3
.global ow_script_route_8_npc_4
.global ow_script_route_8_npc_river_puzzle

ow_script_route_8_npc_0:
	loadpointer 0 str_npc_0
	callstd MSG_FACE
	end
ow_script_route_8_npc_1:
	loadpointer 0 str_npc_1
	callstd MSG_FACE
	end
ow_script_route_8_npc_2:
	loadpointer 0 str_npc_2
	callstd MSG_FACE
	end
ow_script_route_8_npc_3:
	loadpointer 0 str_npc_3
	callstd MSG_FACE
	end
ow_script_route_8_npc_4:
	loadpointer 0 str_npc_4
	callstd MSG_FACE
	end
ow_script_route_8_npc_river_puzzle:
	checkflag RIVER_PUZZLE_DONE
	gotoif EQUAL river_puzzle_done
	lock
	faceplayer
	loadpointer 0 str_ask_river_puzzle
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif EQUAL no_said
	loadpointer 0 str_explain
	callstd MSG_KEEPOPEN
	setflag TRANS_DISABLE
	callasm river_puzzle_initialize
	waitstate
	clearflag TRANS_DISABLE
	pause 32
	compare LASTRESULT 0
	gotoif EQUAL unsolved
	setflag RIVER_PUZZLE_DONE
	loadpointer 0 str_solved
	callstd MSG_KEEPOPEN
river_puzzle_done:
	loadpointer 0 str_done
	callstd MSG
	release
	end

no_said:
	loadpointer 0 str_no_said
	callstd MSG
	release
	end
unsolved:
	loadpointer 0 str_unsolved
	callstd MSG
	release
	end


.ifdef LANG_GER
str_npc_0:
	.autostring 34 2 "Die Leute werfen die seltsamsten Dinge wegDOTS\pOft findet man in Mülleimern Beeren."
str_npc_1:
	.autostring 34 2 "Wusstest du, dass Pokémon bestimmte Angriffe an ihre Nachkommen vererben können?"
str_npc_2:
	.autostring 34 2 "Die Welt dreht sich immer schneller, habe ich machmal das GefühlDOTS\pWie soll man da noch mithalten?"
str_npc_3:
	.autostring 34 2 "Es erzählen immer wieder Menschen, dass sie auf diesem Hügel einem Sen-Long begegnet sind.\pDieses Pokémon zeigt sich nur denen, welche hilfsbereit sind."
str_npc_4:
	.autostring 34 2 "Wusstest du, dass Eier schneller ausgebrütet werden können, wenn man den heißen Quellen von Inferior einen Besuch abstattet?"
str_ask_river_puzzle:
	.autostring 34 2 "Hallo junger Trainer.\nIch habe hier ein kniffliges Problem.\pDrei Pokémon Familien wollen mit diesem Boot den Fluss überqueren, aber die Baby-Pokémon haben ohne ihre Eltern zu viel AngstDOTS\pKannst du mir vielleicht dabei helfen?"
str_no_said:
	.autostring 34 2 "Das ist wirklich schade.\nDabei hast du so einen hilfsbereiten Eindruck auf mich gemachtDOTS"
str_explain:
	.autostring 34 2 "Die Pokémon müssen vom West- ans Ostufer.\pDas Boot hat nur Platz für höchstens zwei Pokémon.\pAußerdem fürchtet sich ein Baby-Pokémon vor ausgewachsenen Pokémon, solange nicht zumindest ein Elternteil es beschützen kannDOTS"
str_unsolved:
	.autostring 34 2 "Es ist wirklich zum Verrücktwerden, nicht?\pDie armen PokémonDOTS"
str_solved:
	.autostring 34 2 "Fantastisch!\nDu bist wirklich sehr clever!\pUnd noch dazu hast du ein Herz für Pokémon.\pAls Gegenleistung werde ich dir ein Geheimnis verraten."
str_done:
	.autostring 34 2 "Weiter nördlich von hier, auf einem Hügel, erscheint manchmal ein Sen-Long.\pEs zeigt sich nur denen, die hilfsbereit sind, aber dass das auf dich zutrifft, hast du ja bereits bewiesen!"

.elseif LANG_EN
str_npc_0:
	.autostring 34 2 "People throw away the most strange thingsDOTS\pOften you find berries in trash cans."
str_npc_1:
	.autostring 34 2 "Did you know that pokemon are able to pass down certain moves to their offspring?"
str_npc_2:
	.autostring 34 2 "The world is spinning faster and faster I feelDOTS\pHow are you supposed to keep up with that?"
str_npc_3:
	.autostring 34 2 "People claim to have seem a Drampa at this hill.\pThis Pokémon only reveals itself to those who are eager to help others."
str_npc_4:
	.autostring 34 2 "Did you know that eggs hatch faster when you were in the hot springs of Inferior previously?"
str_ask_river_puzzle:
	.autostring 34 2 "Hello, young trainer.\pI got a fierce problem here it seems.\pThree Pokémon families want to cross the river with this boat, but the Baby-Pokémon are too afraid without their parents.\pCould you help me maybe?"
str_no_said:
	.autostring 34 2 "What a pity!\pYou really did make an helpful impression to meDOTS"
str_explain:
	.autostring 34 2 "The Pokémon must go from the western to the eastern riverside.\pThe boat only has room for at most two Pokémon.\pAdditionally, any Baby-Pokémon is afraid of a grown up Pokémon if it is without its parent."
str_unsolved:
	.autostring 34 2 "It really drives one mad, doesn't it?\pThe poor PokémonDOTS"
str_solved:
	.autostring 34 2 "Fantastic!\nYou really are clever!\pAnd also you have a heart for Pokémon.\pIn return I will tell you a little secret!"
str_done:
	.autostring 34 2 "A bit up the hill sometimes a Drampa appears.\pIt is said to only reveal itself to those who are eager to help, but I guess that you already proofed yourself to be such a person, didn't you?"

.endif
