.include "overworld_script.s"
.include "flags.s"
.include "items.s"
.include "species.s"
.include "ordinals.s"
.include "callstds.s"
.include "movements.s"
.include "vars.s"

.global ow_script_aktania_gengarnite
ow_script_aktania_gengarnite:
checkflag AKTANIA_GENGARNITE
gotoif 1 done
lock
faceplayer
loadpointer 0 str_intro
callstd MSG
setvar 0x8004 POKEMON_BANETTE
special2 LASTRESULT 0x4D
compare LASTRESULT 6
gotoif EQUAL no_gengar_in_party
sound 0x15
singlemovement LASTTALKED SAY_EXCLAM
waitmovement 0
loadpointer 0 str_give_gengarnite
callstd MSG_KEEPOPEN
bufferitem 0x0 ITEM_BANETTENIT
copyvarifnotzero 0x8000 ITEM_BANETTENIT
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL no_space
loadpointer 0 str_explaination
callstd MSG
setflag AKTANIA_GENGARNITE
no_gengar_in_party:
release
end

done:
loadpointer 0 str_done
callstd MSG_FACE
end

no_space:
loadpointer 0 str_no_space
callstd MSG
release
end


.ifdef LANG_GER
str_done:
	.autostring 34 2 "Der Banetteonit kann Banettes wahres Potenzial entfaltenDOTS"
str_intro:
	.autostring 34 2 "Banette ist ein Geist-Pokémon, das von vielen Hexen ignoriert wird.\pIch aber kenne einen Weg, seine wahres Potential zu entfalten.\pWenn du mir ein Banette zeigen könntestDOTS"
str_give_gengarnite:
	.autostring 34 2 "Du besitzt ein Banette!\nFantastisch! Mit diesem Item kannst du seine wahre Kräfte entfesseln!"
str_explaination:
	.autostring 34 2 "Der Banetteonit enthüllt Banettes Stärke, wenn es im Kampf von ihm getragen wird."
str_no_space:
	.autostring 34 2 "Du hast keinen Platz in deinem Beutel!\pKomm wieder und zeig mir dein Banette, wenn du den Banetteonit entgegennehmen kannst."
.elseif LANG_EN
str_intro:
	.autostring 34 2 "Witches often neglect the Ghost-type Pokémon Banette.\pBut I myself know a way to unleash its true potential.\pIf you could show me a BanetteDOTS"
str_give_gengarnite:
	.autostring 34 2 "Fantastic!\nYou own a Banette!\pWith this item you can unlock its true powers!"
str_done:
	.autostring 34 2 "The Banettenite can unleash Banette's true potentialDOTS"
str_explaination:
	.autostring 34 2 "The Banettenite unveils Banette's power when its held in battle."
str_no_space:
	.autostring 34 2 "Seems like you don't have space in your bag for this item.\pCome again and show me your Banette, if you can take the Banettenite."
.endif
