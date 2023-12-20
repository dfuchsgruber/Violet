
# Move tutor list generator
TUTORCRYSTALGEN:=tools/tutor_crystal/tutor_crystal.py
# Define the symbol of the move tutor list
TUTORCRYSTALS:=move_tutor_crystals

TUTORCRYSTALS_OBJ:=$(BLDPATH)/move_tutor_crystals.o

$(TUTORCRYSTALS_OBJ): $(MAPPROJ)
	@echo "Creating move tutor crystal list $(TUTORCRYSTALS)..."
	$(PY3) $(TUTORCRYSTALGEN) -o $(BLDPATH)/move_tutor_crystals.s $(TUTORCRYSTALS) $(MAPPROJ)
	$(AS) $(ASFLAGS) $(BLDPATH)/move_tutor_crystals.s -o $(TUTORCRYSTALS_OBJ)
