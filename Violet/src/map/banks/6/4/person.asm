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
setvar 0x8004 POKEMON_GENGAR
special2 LASTRESULT 0x4D
compare LASTRESULT 6
gotoif EQUAL no_gengar_in_party
sound 0x15
singlemovement LASTTALKED SAY_EXCLAM
waitmovement 0
loadpointer 0 str_give_gengarnite
callstd MSG_KEEPOPEN
bufferitem 0x0 ITEM_GENGARNIT
copyvarifnotzero 0x8000 ITEM_GENGARNIT
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
	.autostring 34 2 "Der Gengarnit kann Gengars wahres Potenzial entfaltenDOTS"
str_intro:
	.autostring 34 2 "Unter den Hexen hält sich die Meinung, dass Gengar das stärkste aller Geist-Pokémon sei.\pAber ich kenne einen Weg, es noch mächtiger werden zu lassenDOTS"
str_give_gengarnite:
	.autostring 34 2 "Du besitzt ein Gengar!\nFantastisch! Mit diesem Item kannst du Gengars wahre Kräfte entfesseln!"
str_explaination:
	.autostring 34 2 "Der Gengarnit enthüllt Gengars Stärke, wenn es im Kampf von ihm getragen wird."
str_no_space:
	.autostring 34 2 "Du hast keinen Platz in deinem Beutel!\pKomm wieder und zeig mir dein Gengar, wenn du den Gengarnit entgegennehmen kannst."
.elseif LANG_EN
str_intro:
	.autostring 34 2 "Witches tell themselves that Gengar is most powerful amongst all Ghost-Pokémon.\pBut I know a way to make it even strongerDOTS"
str_give_gengarnite:
	.autostring 34 2 "Fantastic!\nYou own a Gengar!\pWith this item you can unlock its true powers!"
str_done:
	.autostring 34 2 "The Gengarnite can unleash Gengar's true potentialDOTS"
str_explaination:
	.autostring 34 2 "The Gengarnite unveils Gengar's power when its held in battle."
str_no_space:
	.autostring 34 2 "Seems like you don't have space in your bag for this item.\pCome again and show me your Gengar, if you can take the Gengarnite."
.endif
