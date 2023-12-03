
# Move tutor list generator
MOVETUTORGEN:=tools/move_tutor/move_tutor.py
# Define the symbol of the move tutor list
MOVETUTORS:=move_tutors

MOVETUTORS_OBJ:=$(BLDPATH)/move_tutors.o

$(MOVETUTORS_OBJ): $(MAPPROJ)
	@echo "Creating move tutor list $(MOVETUTORS)..."
	$(PY3) $(MOVETUTORGEN) -o $(BLDPATH)/move_tutors.s $(MOVETUTORS) $(MAPPROJ)
	$(AS) $(ASFLAGS) $(BLDPATH)/move_tutors.s -o $(MOVETUTORS_OBJ)
