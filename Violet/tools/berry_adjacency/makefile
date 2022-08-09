
# Berry adjacency graph generator settings
BERRYADJACENCYGEN:=tools/berry_adjacency/berry_adjacency.py
# Define the symbol of the adjacency table
BERRYADJACENCY:=berry_tree_adjacency

BERRYADJACENCY_OBJ:=$(BLDPATH)/berry_tree_adjacency.o

# Fata morgana lookup table
$(BERRYADJACENCY_OBJ): $(MAPPROJ)
#	Run python script for generating a sorted list of morgana tiles
	@echo "Creating berry adjacency graph $(BERRYADJACENCY)..."
	$(PY3) $(BERRYADJACENCYGEN) -o $(BLDPATH)/berry_adjacency_graph.s $(BERRYADJACENCY) $(MAPPROJ)
	$(AS) $(ASFLAGS) $(BLDPATH)/berry_adjacency_graph.s -o $(BERRYADJACENCY_OBJ)
