#include "types.h"
#include "language.h"
u8 trainer_class_names[][13] = {
	LANGDEP(PSTRING("PKMN-Trainer"), PSTRING("PKMN Trainer")),
	LANGDEP(PSTRING("PKMN-Trainer"), PSTRING("PKMN Trainer")),
	LANGDEP(PSTRING("Polizist"), PSTRING("Aqua Leader")),
	LANGDEP(PSTRING("Revolutionär"), PSTRING("Team Aqua")),
	LANGDEP(PSTRING("Aromalady"), PSTRING("Aroma Lady")),
	LANGDEP(PSTRING("Ruinenmaniac"), PSTRING("Ruin Maniac")),
	LANGDEP(PSTRING("Forscherin"), PSTRING("Interviewer")),
	LANGDEP(PSTRING("Planscher"), PSTRING("Tuber")),
	LANGDEP(PSTRING("Butler"), PSTRING("Butler")),
	LANGDEP(PSTRING("Ass-Trainer"), PSTRING("Cooltrainer")),
	LANGDEP(PSTRING("Hexe"), PSTRING("Hex Maniac")),
	LANGDEP(PSTRING("Lady"), PSTRING("Lady")),
	LANGDEP(PSTRING("Schönheit"), PSTRING("Beauty")),
	LANGDEP(PSTRING("Schnösel"), PSTRING("Rich Boy")),
	LANGDEP(PSTRING("Pokémaniac"), PSTRING("Pokémaniac")),
	LANGDEP(PSTRING("Schwimmer"), PSTRING("SwimmerSTRING5")),
	LANGDEP(PSTRING("Schwarzgurt"), PSTRING("Black Belt")),
	LANGDEP(PSTRING("Gitarrist"), PSTRING("Guitarist")),
	LANGDEP(PSTRING("Hitzkopf"), PSTRING("Kindler")),
	LANGDEP(PSTRING("Camper"), PSTRING("Camper")),
	LANGDEP(PSTRING("Käfermaniac"), PSTRING("Bug Maniac")),
	LANGDEP(PSTRING("Psycho"), PSTRING("Psychic")),
	LANGDEP(PSTRING("Gentleman"), PSTRING("Gentleman")),
	LANGDEP(PSTRING("Top Vier"), PSTRING("Elite Four")),
	LANGDEP(PSTRING("Leiterald"), PSTRING("Leader")),
	LANGDEP(PSTRING("Schulkind"), PSTRING("School Kid")),
	LANGDEP(PSTRING("Sen. & Jun."), PSTRING("Sr. And Jr.")),
	LANGDEP(PSTRING("Pokéfan"), PSTRING("Pokéfan")),
	LANGDEP(PSTRING("Experte"), PSTRING("Expert")),
	LANGDEP(PSTRING("Teenager"), PSTRING("Youngster")),
	LANGDEP(PSTRING("Champ"), PSTRING("Champion")),
	LANGDEP(PSTRING("Angler"), PSTRING("Fisherman")),
	LANGDEP(PSTRING("Triathlet"), PSTRING("Triathlete")),
	LANGDEP(PSTRING("Drachenprofi"), PSTRING("Dragon Tamer")),
	LANGDEP(PSTRING("Vogelfänger"), PSTRING("Bird Keeper")),
	LANGDEP(PSTRING("Ninjajunge"), PSTRING("Ninja Boy")),
	LANGDEP(PSTRING("Kämpferin"), PSTRING("Battle Girl")),
	LANGDEP(PSTRING("Schirmdame"), PSTRING("Parasol Lady")),
	LANGDEP(PSTRING("Schwimmerin"), PSTRING("SwimmerSTRING6")),
	LANGDEP(PSTRING("Picknicker"), PSTRING("Picnicker")),
	LANGDEP(PSTRING("Zwil."), PSTRING("Twins")),
	LANGDEP(PSTRING("Matrose"), PSTRING("Sailor")),
	LANGDEP(PSTRING("Snowboarder"), PSTRING("Boarder")),
	LANGDEP(PSTRING("PKMN-Sammler"), PSTRING("Collector")),
	LANGDEP(PSTRING("PKMN-Trainer"), PSTRING("PKMN Trainer")),
	LANGDEP(PSTRING("PKMN-Züchter"), PSTRING("PKMN Breeder")),
	LANGDEP(PSTRING("PKMN-Ranger"), PSTRING("PKMN Ranger")),
	LANGDEP(PSTRING("Magma Boss"), PSTRING("Magma Leader")),
	LANGDEP(PSTRING("Pirat"), PSTRING("Pirate")),
	LANGDEP(PSTRING("Göre"), PSTRING("Lass")),
	LANGDEP(PSTRING("Käfersammler"), PSTRING("Bug Catcher")),
	LANGDEP(PSTRING("Picknicker"), PSTRING("Hiker")),
	LANGDEP(PSTRING("Junges Glück"), PSTRING("Young Couple")),
	LANGDEP(PSTRING("Altes Paar"), PSTRING("Old Couple")),
	LANGDEP(PSTRING("Geschwister"), PSTRING("Sis And Bro")),
	LANGDEP(PSTRING("Wolkenreiter"), PSTRING("Cloud Rider")),
	LANGDEP(PSTRING("Violet Vors."), PSTRING("Violet Admin")),
	LANGDEP(PSTRING("Teenager"), PSTRING("Youngster")),
	LANGDEP(PSTRING("Käfersammler"), PSTRING("Bug Catcher")),
	LANGDEP(PSTRING("Göre"), PSTRING("Lass")),
	LANGDEP(PSTRING("Matrose"), PSTRING("Sailor")),
	LANGDEP(PSTRING("Camper"), PSTRING("Camper")),
	LANGDEP(PSTRING("Picknicker"), PSTRING("Picnicker")),
	LANGDEP(PSTRING("Pokémaniac"), PSTRING("Pokémaniac")),
	LANGDEP(PSTRING("Streber"), PSTRING("Super Nerd")),
	LANGDEP(PSTRING("Wanderer"), PSTRING("Hiker")),
	LANGDEP(PSTRING("Biker"), PSTRING("Biker")),
	LANGDEP(PSTRING("Dieb"), PSTRING("Burglar")),
	LANGDEP(PSTRING("Mechaniker"), PSTRING("Engineer")),
	LANGDEP(PSTRING("Angler"), PSTRING("Fisherman")),
	LANGDEP(PSTRING("Schwimmer"), PSTRING("SwimmerSTRING5")),
	LANGDEP(PSTRING("Glatzkopf"), PSTRING("Cue Ball")),
	LANGDEP(PSTRING("Spieler"), PSTRING("Gamer")),
	LANGDEP(PSTRING("Schönheit"), PSTRING("Beauty")),
	LANGDEP(PSTRING("Schwimmerin"), PSTRING("SwimmerSTRING6")),
	LANGDEP(PSTRING("Psycho"), PSTRING("Psychic")),
	LANGDEP(PSTRING("Rocker"), PSTRING("Rocker")),
	LANGDEP(PSTRING("Jongleur"), PSTRING("Juggler")),
	LANGDEP(PSTRING("Dompteur"), PSTRING("Tamer")),
	LANGDEP(PSTRING("Vogelfänger"), PSTRING("Bird Keeper")),
	LANGDEP(PSTRING("Schwarzgurt"), PSTRING("Black Belt")),
	LANGDEP(PSTRING("Rivale"), PSTRING("Rival")),
	LANGDEP(PSTRING("Forscher"), PSTRING("Scientist")),
	LANGDEP(PSTRING("Boss"), PSTRING("Boss")),
	LANGDEP(PSTRING("Arenaleiter"), PSTRING("Leader")),
	LANGDEP(PSTRING("Team Violet"), PSTRING("Team Violet")),
	LANGDEP(PSTRING("Ass-Trainer"), PSTRING("Cooltrainer")),
	LANGDEP(PSTRING("Top Vier"), PSTRING("Elite Four")),
	LANGDEP(PSTRING("Gentleman"), PSTRING("Gentleman")),
	LANGDEP(PSTRING("Rivale"), PSTRING("Rival")),
	LANGDEP(PSTRING("Champ"), PSTRING("Champion")),
	LANGDEP(PSTRING("Exorzistin"), PSTRING("Channeler")),
	LANGDEP(PSTRING("Zwil."), PSTRING("Twins")),
	LANGDEP(PSTRING("Primapaar"), PSTRING("Cool Couple")),
	LANGDEP(PSTRING("Junges Glück"), PSTRING("Young Couple")),
	LANGDEP(PSTRING("Mühlensippe"), PSTRING("Crush Kin")),
	LANGDEP(PSTRING("Geschwister"), PSTRING("Sis And Bro")),
	LANGDEP(PSTRING("PKMN Prof."), PSTRING("PKMN Prof.")),
	LANGDEP(PSTRING("Spieler"), PSTRING("Player")),
	LANGDEP(PSTRING("Mühlenmädel"), PSTRING("Crush Girl")),
	LANGDEP(PSTRING("Planscher"), PSTRING("Tuber")),
	LANGDEP(PSTRING("PKMN-Züchter"), PSTRING("PKMN Breeder")),
	LANGDEP(PSTRING("PKMN-Ranger"), PSTRING("PKMN Ranger")),
	LANGDEP(PSTRING("Aromalady"), PSTRING("Aroma Lady")),
	LANGDEP(PSTRING("Ruinenmaniac"), PSTRING("Ruin Maniac")),
	LANGDEP(PSTRING("Lady"), PSTRING("Lady")),
	LANGDEP(PSTRING("Malerin"), PSTRING("Painter")),
};
