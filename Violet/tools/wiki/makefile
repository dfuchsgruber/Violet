# Is to be executed from the main makefile
POKEMON_WIKI=./tools/wiki/pokemon.py
WIKI_OUTPUT ?= docs/pokemon

.PHONY: pokemon_wiki wiki

pokemon_wiki: $(POKEMON_INDEX_PKL) $(POKEMON_STATS_PKL)
	$(POKEMON_WIKI) --pokemon-pkl $(POKEMON_INDEX_PKL) --stats-pkl $(POKEMON_STATS_PKL) --project $(MAPPROJ) --output $(WIKI_OUTPUT) --language $(LANGUAGE) --clean

wiki: pokemon_wiki
