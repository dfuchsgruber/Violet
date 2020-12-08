
# Worldmap csv -> assembly
WORLDMAPCSV2AS:=tools/worldmap/worldmapcsv2as.py

WORLDMAPCSV:= $(call rwildcard,src/worldmap,*.csv)
WORLDMAPAS = $(WORLDMAPCSV:%.csv=$(BLDPATH)/%.s)
WORLDMAPOBJS = $(WORLDMAPAS:%.s=%.o)

$(WORLDMAPOBJS): %.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) $< -o $@

$(WORLDMAPAS): $(BLDPATH)/%.s: %.csv
	$(shell mkdir -p $(dir $(WORLDMAPAS)))
	$(WORLDMAPCSV2AS) $< $(basename $(<F)) $(MAPPROJ) -o $@