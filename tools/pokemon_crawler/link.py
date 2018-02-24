"""
This module is responsible for normalizing the pokemon
data such that it only contains move in a constants
table and also allows to link the same moveset
to different pokemon.
"""

from . import pokemon_crawler as crawler

# Defintions for additional moves on pokemon

# Lockschal
pokemon_lockschal = {
    "lvlup" : [
        (1, "Pfund"),
        (1, "Härtner"),
        (7, "Rasierblatt"),
        (12, "Natur-Kraft"),
        (15, "Zornklinge"),
        (19, "Energiefokus"),
        (23, "Laubklinge"),
        ()
    ]
}
ATTACK_KLINGENSTURM
ATTACK_SCHWERTTANZ
ATTACK_WIRBELWIND
ATTACK_KUGELSAAT
ATTACK_ZAUBERBLATT
ATTACK_PATRONENHIEB
ATTACK_TIEFSCHLAG
ATTACK_STAHLSTREICH
ATTACK_SCHALLSTICH

ATTACK_FLUCH
ATTACK_DRESCHFLEGEL
ATTACK_VERFOLGUNG

RASIERBLATT, 7},
	{ATTACK_NATUR_KRAFT, 12},
	{ATTACK_GEDULD, 16},
	{ATTACK_LAUBKLINGE, 21},
	{ATTACK_RUCKZUCKHIEB, 25},
	{ATTACK_KOPFNUSS, 29},
	{ATTACK_STAHLSTREICH, 36},
	{ATTACK_NAHKAMPF, 42},
	{ATTACK_SCHALLSTICH, 55},
	{0x1FF, 0x7F}
};

pokemon_move moveset_pokemon_stichschal[] = {
	{ATTACK_PFUND, 1},
	{ATTACK_HAERTNER, 1},
	{ATTACK_RASIERBLATT, 7},
	{ATTACK_NATUR_KRAFT, 12},
	{ATTACK_GEDULD, 16},
	{ATTACK_LAUBKLINGE, 21},
	{ATTACK_RUCKZUCKHIEB, 25},
	{ATTACK_KOPFNUSS, 29},
	{ATTACK_STAHLSTREICH, 36},
	{ATTACK_NAHKAMPF, 42},
	{ATTACK_SCHALLSTICH, 55},
	{0x1FF, 0x7F}