# Is to be executed from the main makefile
POKEAPI_DIR=pokeapi
CRAWLER=./tools/pokemon_generator/crawler.py
UPDATER=./tools/pokemon_generator/update.py
EXPORTER=./tools/pokemon_generator/export.py

POKEAPIBLD=$(BLDPATH)/pokeapi

POKEAPI_STATS = $(POKEAPI_DIR)/pokeapi_stats.pkl
UPDATES = $(POKEAPI_DIR)/updates.json
UPDATED_STATS = $(POKEAPIBLD)/updated.pkl

EXPORTED_BASESTATS=$(POKEAPIBLD)/stats.pms
BASESTATS_LABEL=basestats

EXPORTED_LEVELUP_MOVES=$(POKEAPIBLD)/levelup_moves.pms
LEVELUP_MOVES_LABEL=pokemon_moves

EXPORTED_EGG_MOVES=$(POKEAPIBLD)/egg_moves.pms
EGG_MOVES_LABEL=pokemon_egg_moves

EXPORTED_TM_COMPATIBILITY=$(POKEAPIBLD)/tm_compatibility.pms
TM_COMPATIBILITY_LABEL=pokemon_tm_compatibility

EXPORTED_TUTOR_COMPATIBILITY=$(POKEAPIBLD)/tutor_compatibility.pms
TUTOR_COMPATIBILITY_LABEL=pokemon_move_tutor_compatibility

EXPORTED_ACCESSIBLE_MOVES=$(POKEAPIBLD)/accessible_moves.pms
ACCESSIBLE_MOVES_LABEL=pokemon_accessible_moves

EXPORTED_NAMES=$(POKEAPIBLD)/pokemon_names.pms
NAMES_LABEL=pokemon_names

EXPORTED_POKEDEX_ORDER=$(POKEAPIBLD)/pokedex_order.pms
POKEDEX_ORDER_LABEL=pokedex_order

EXPORTED_POKEDEX_ENTRIES=$(POKEAPIBLD)/pokedex_entries.pms
POKEDEX_ENTRIES_LABEL=pokedex_entries

EXPORTED_EVOLUTIONS=$(POKEAPIBLD)/evolutions.pms
EVOLUTIONS_LABEL=pokemon_evolutions

EXPORTED_STATS=$(EXPORTED_BASESTATS) $(EXPORTED_LEVELUP_MOVES) $(EXPORTED_EGG_MOVES) $(EXPORTED_TM_COMPATIBILITY) $(EXPORTED_TUTOR_COMPATIBILITY) $(EXPORTED_ACCESSIBLE_MOVES) $(EXPORTED_NAMES) $(EXPORTED_POKEDEX_ORDER) $(EXPORTED_POKEDEX_ENTRIES) $(EXPORTED_EVOLUTIONS)

EXPORTED_STATS_OBJ=$(EXPORTED_STATS:%.pms=%.o)
EXPORTED_STATS_DEP=$(EXPORTED_STATS_OBJ:%.o=%.d)

$(EXPORTED_STATS_OBJ): %.o: %.pms
	@echo "$<"
	$(PYMAP2S)  -o $*.asm $< $(MAPPROJ)
	$(PYPREPROC) -o $*.i $*.asm $(MAPPROJ)   
	$(AS) $(ASFLAGS) --MD $*.d $*.i -o $@

$(EXPORTED_STATS): $(UPDATED_STATS)
	$(shell mkdir -p $(dir $@))
	$(EXPORTER) --basestatslabel $(BASESTATS_LABEL) --levelupmoveslabel $(LEVELUP_MOVES_LABEL) --eggmoveslabel $(EGG_MOVES_LABEL) --tmcompatibilitylabel $(TM_COMPATIBILITY_LABEL) \
	--tutorcompatibilitylabel $(TUTOR_COMPATIBILITY_LABEL) --accessiblemoveslabel $(ACCESSIBLE_MOVES_LABEL) --pokemonnameslabel $(NAMES_LABEL) \
	--pokedexorderlabel $(POKEDEX_ORDER_LABEL) --pokedexentrieslabel $(POKEDEX_ENTRIES_LABEL) --evolutionslabel $(EVOLUTIONS_LABEL) --language $(LANGUAGE) $(UPDATED_STATS) $(MAPPROJ) \
	$(EXPORTED_BASESTATS) $(EXPORTED_LEVELUP_MOVES) $(EXPORTED_EGG_MOVES) $(EXPORTED_TM_COMPATIBILITY) $(EXPORTED_TUTOR_COMPATIBILITY) $(EXPORTED_ACCESSIBLE_MOVES) \
	$(EXPORTED_NAMES) $(EXPORTED_POKEDEX_ORDER) $(EXPORTED_POKEDEX_ENTRIES) $(EXPORTED_EVOLUTIONS)

$(UPDATED_STATS): $(POKEAPI_STATS) $(UPDATES)
	$(shell mkdir -p $(dir $@))
	@echo "Creating stats and movesets..."
	$(UPDATER) -o $(UPDATED_STATS) $(POKEAPI_STATS) $(UPDATES) $(MAPPROJ)

$(POKEAPI_STATS):
	$(CRAWLER) --cache -o $(POKEAPI_STATS) $(MAPPROJ)

updated_stats: $(UPDATED_STATS)