
# Berry adjacency graph generator settings
AGGRESSIVEGEN:=tools/aggressive_wild/aggressive_wild.py
# Define the symbol of the aggressive wild encounters
AGGRESSIVETABLE:=aggressive_wild_encounters

AGGRESIVE_WILD_OBJ:=$(BLDPATH)/aggressive_wild_encounters.o

# Fata morgana lookup table
$(AGGRESIVE_WILD_OBJ): $(MAPPROJ)
#	Run python script for generating a sorted list of morgana tiles
	@echo "Creating aggressive wild encounters $(AGGRESSIVETABLE)..."
	$(PY3) $(AGGRESSIVEGEN) -o $(BLDPATH)/aggressive_wild_encounters.s $(AGGRESSIVETABLE) $(MAPPROJ)
	$(AS) $(ASFLAGS) $(BLDPATH)/aggressive_wild_encounters.s -o $(AGGRESIVE_WILD_OBJ)
