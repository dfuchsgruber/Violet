.global str_river_puzzle_help
.global str_river_puzzle_confirm_exit
.global str_river_puzzle_invalid_configuration
.global str_river_puzzle_solved

.ifdef LANG_GER
str_river_puzzle_help:
	.autostring 34 2 "Bringe alle Pokémon vom West- zum Ostufer.\pDas Boot hat Platz für zwei Pokémon.\pEin Baby-Pokémon fürchtet sich, wenn es von ausgewachsenen Pokémon umgeben ist, also achte darauf, dass ein Baby-Pokémon stets bei einem Elternteil ist oder nur andere Baby-Pokémon in der Nähe sind.PAUSE_UNTIL_PRESS"
str_river_puzzle_confirm_exit:
	.autostring 34 2 "Möchtest du das Rätsel abbrechen?"
str_river_puzzle_invalid_configuration:
	.autostring 34 2 "Aber BUFFER_1 würde sich in der Gegenwart von BUFFER_2 fürchtenDOTSPAUSE_UNTIL_PRESS"
str_river_puzzle_solved:
	.autostring 34 2 "Toll gemacht!\nDu hast alle Pokémon ans Ostufer gebracht!PAUSE_UNTIL_PRESS"

.elseif LANG_EN
str_river_puzzle_help:
	.autostring 34 2 "Bring all Pokémon from the western to the eastern riverside.\pThe boat holds space for two Pokémon.\pAny Baby-Pokémon is afraid if its nearby adult Pokémon. Thus, ensure that either any Baby-Pokémon is right by its parent's side or only other Baby-Pokémon are nearby.PAUSE_UNTIL_PRESS"
str_river_puzzle_confirm_exit:
	.autostring 34 2 "Do you want to exit the puzzle?"
str_river_puzzle_invalid_configuration:
	.autostring 34 2 "But BUFFER_1 would be afraid of BUFFER_2DOTSPAUSE_UNTIL_PRESS"
str_river_puzzle_solved:
	.autostring 34 2 "Very well!\nYou helped all Pokémon get to the eastern riverside!PAUSE_UNTIL_PRESS"

.endif
