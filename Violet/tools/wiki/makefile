# Is to be executed from the main makefile
POKEMON_WIKI=./tools/wiki/pokemon.py
WIKI_OUTPUT ?= docs/pokemon
MEGA_EVOLUTIONS_PMS=src/battle/mega/mega_evolutions.pms

.PHONY: pokemon_wiki wiki

pokemon_wiki: $(POKEMON_INDEX_PKL) $(POKEMON_STATS_PKL) $(UPDATES) $(MEGA_EVOLUTIONS_PMS)
	$(POKEMON_WIKI) --pokemon-pkl $(POKEMON_INDEX_PKL) --stats-pkl $(POKEMON_STATS_PKL) --updates-json $(UPDATES) --mega-evolutions-pms $(MEGA_EVOLUTIONS_PMS) --project $(MAPPROJ) --output $(WIKI_OUTPUT) --language $(LANGUAGE) --clean

wiki: pokemon_wiki
