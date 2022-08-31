
# Treasure map generator settings
TREASUREMAPGEN:=tools/treasure_map/treasure_map.py
# Define the symbol of the treasure map list
TREASUREMAPS:=treasure_maps

TREASUREMAP_OBJ:=$(BLDPATH)/treasure_maps.o

# Fata morgana lookup table
$(TREASUREMAP_OBJ): $(MAPPROJ)
	@echo "Creating treasure map list $(TREASUREMAPS)..."
	$(PY3) $(TREASUREMAPGEN) -o $(BLDPATH)/treasure_maps.s $(TREASUREMAPS) $(MAPPROJ)
	$(AS) $(ASFLAGS) $(BLDPATH)/treasure_maps.s -o $(TREASUREMAP_OBJ)
