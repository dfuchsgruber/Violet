"""
This module holds additional pokemon and data updates
for the movesets.
"""

from . import pokemon_crawler as crawler

# Defintions for additional moves on pokemon

# Lockschal
pokemon_lockschal = crawler.Pokemon(attacks_lvlup=[
        (1, "Pfund"),
        (1, "Härtner"),
        (7, "Rasierblatt"),
        (12, "Natur-Kraft"),
        (15, "Zornklinge"),
        (19, "Energiefokus"),
        (23, "Laubklinge"),
        (27, "Eisenabwehr"),
        (33, "Schwerttanz"),
        (39, "Klingensturm"),
        (44, "Wirbelwind")
    ]
    )

pokemon_stichschal = crawler.Pokemon(attacks_lvlup=[
        (1, "Pfund"),
        (1, "Härtner"),
        (1, "Rasierblatt"),
        (1, "Natur-Kraft"),
        (1, "Zornklinge"),
        (14, "Energiefokus"),
        (24, "Laubklinge"),
        (29, "Eisenabwehr"),
        (34, "Schwerttanz"),
        (42, "Klingensturm"),
        (48, "Wirbelwind")
    ]
    )

pokemon_altaria = crawler.Pokemon(attacks_lvlup=[
        (40, "Donnerblitz"),
        (60, "Himmelsfeger")
    ]
    )

# Local pokemon data pool
local_pkmn = {
    277 : pokemon_lockschal,
    278 : pokemon_stichschal,
    279 : pokemon_lockschal,
    280 : pokemon_lockschal,
    281 : pokemon_stichschal,
    282 : pokemon_lockschal,
    283 : pokemon_lockschal,
    284 : pokemon_stichschal,
    285 : pokemon_lockschal,
}

# Updates for each pokemon
updates = {
    0x167 : pokemon_altaria
}