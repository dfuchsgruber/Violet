
# Fata morgana lookup table generator settings
FATAMORGANAGEN:=tools/fata_morgana/fata_morgana_lut.py
# Define the footer the fata morgana is executed on
DESERTFOOTER:=src/map/banks/3/21/map_footer_91.pms
# Define the symbol of the lookup table
FATAMORGANALUT:=fata_morgana_blocks
# Define the symbol of the lookup table size
FATAMORGANALUTSIZE:=fata_morgana_blocks_cnt

FATAMORGANA_OBJ:=$(BLDPATH)/fata_morgana.o

# Fata morgana lookup table
$(FATAMORGANA_OBJ): $(DESERTFOOTER)
#	Run python script for generating a sorted list of morgana tiles
	@echo "Creating fata morgana lookup table $(FATAMORGANALUT) of size $(FATAMORGANALUTSIZE) based on $(DESERTFOOTER)..."
	$(PY3) $(FATAMORGANAGEN) -o $(BLDPATH)/fata_morgana.s $(DESERTFOOTER) $(FATAMORGANALUT) $(FATAMORGANALUTSIZE) $(MAPPROJ)
	$(AS) $(ASFLAGS) $(BLDPATH)/fata_morgana.s -o $(FATAMORGANA_OBJ)
