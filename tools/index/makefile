# Is to be executed from the main makefile
INDEXPATH=$(BLDPATH)/index
HABITATS_INDEX_PKL=$(INDEXPATH)/habitats.pkl
HABITATS_INDEXER=./tools/index/habitats.py
HABITATS_READABLE=$(INDEXPATH)/habitats.txt
ITEMS_INDEX_PKL=$(INDEXPATH)/items.pkl
ITEMS_INDEXER=./tools/index/items.py
ITEMS_READABLE=$(INDEXPATH)/items.txt
HIDDEN_READABLE=$(INDEXPATH)/hidden.txt
PRINT_INDEX=./tools/index/print.py

.PHONY: index

$(HABITATS_INDEX_PKL): $(BLDROM) $(MAPPROJ)
	$(shell mkdir -p $(dir $@))
	$(HABITATS_INDEXER) -o $(HABITATS_INDEX_PKL) $(BLDROM) $(SYMBOLDUMP) $(MAPPROJ)

$(ITEMS_INDEX_PKL): $(BLDROM) $(MAPPROJ)
	$(shell mkdir -p $(dir $@))
	$(ITEMS_INDEXER) -o $(ITEMS_INDEX_PKL) $(BLDROM) $(SYMBOLDUMP) $(MAPPROJ)

index: $(HABITATS_INDEX_PKL) $(ITEMS_INDEX_PKL)
	$(PRINT_INDEX) -o $(HABITATS_READABLE) --habitats $(HABITATS_INDEX_PKL)
	$(PRINT_INDEX) -o $(ITEMS_READABLE) --items $(ITEMS_INDEX_PKL)
	$(PRINT_INDEX) -o $(HIDDEN_READABLE) --hidden $(ITEMS_INDEX_PKL)