WAV2AGB=@wav2agb
AR=arm-none-eabi-ar
AS=@arm-none-eabi-as
LD=@arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy
GRIT=@grit
CC=@arm-none-eabi-gcc
NM=@arm-none-eabi-nm
ARS=@armips
MID2AGB=@mid2agb
#MID2AGB=/media/d/romhacking/midi2agb/midi2agb
PY3=@python3
BIN2S=@bin2s.py
PYSET2S=@pyset2s.py
PYMAP2S=@pymap2s.py
PYPROJ2S=@pyproj2s.py
PYPREPROC=@pypreproc.py
PYMAPCONSTEX=pymapconstex.py
READELF=@arm-none-eabi-readelf
SOUNDFONTRIPPER=sound_font_ripper

# Py-Preprocessor settings (pypreproc.py)
CHARMAP=charmap.txt
LANGUAGE=LANG_GER
#LANGUAGE=LANG_EN
CLANGMACRO=PSTRING

# Define compiler flags
ASFLAGS=-mthumb -Iinclude/as/ -Iinclude/as/constants/ -mcpu=arm7tdmi -march=armv4t --defsym $(LANGUAGE)=1
MIDFLAGS=-V92
CFLAGS=-c -std=c99 -mthumb -mthumb-interwork -mcpu=arm7tdmi -fno-inline -mlong-calls -march=armv4t -Wall -Werror -Wextra -Wconversion -O2 -Iinclude/c/ -D$(LANGUAGE)
LDFLAGS=-z muldefs -Ilibm
GRITFLAGS=-fh! -ftc
WAVFLAGS=-c
MAPTILESETGRITFLAGS=-gu32 -gzl -gB 4 -gt -m! -p!

BLDPATH=bld
BLDROM=$(BLDPATH)/violet.gba
BASEROM=base/bprd.gba
MAPPROJ=proj.pmp
SYMBOLDUMP=$(BLDPATH)/symbols

# Pokemon crawler settings
PKMNCRAWLERDATA=$(BLDPATH)/pkmncrawlerdata.pkl
# Define the symbol of the evolution talbe (linked elf is parsed by movegenerator)
PKMNEVOTABLE=pokemon_evolutions
# Define a file that contains information about the .text section of the linked file
# and also location and size of the evolution table
LINKEDTEXTHEADER=$(BLDPATH)/linked.o.text
LINKEDEVOTABLEHEADER=$(BLDPATH)/linked.o.evotable
PKMNLVLUPATTACKS=pokemon_moves
PKMNEGGMOVES=pokemon_egg_moves
PKMNTMCOMPATIBILITY=pokemon_tm_compatibility
PKMNMOVETUTORCOMPATIBILITY=pokemon_move_tutor_compatibility
PKMNINACESSIBLEMOVES=pokemon_inacessible_moves
# Define a file that contains all manual pokemon moveset (changes)
PKMNCRAWLEREXTERN=tools/pokemon_move_generator/data.py


# Fata morgana lookup table generator settings 
# Define the map the fata morgana is executed on
DESERTMAP=src/map/banks/3/21/map_3_21.pmh
# Define the symbol of the lookup table
FATAMORGANALUT=fata_morgana_blocks
# Define the symbol of the lookup table size
FATAMORGANALUTSIZE=fata_morgana_blocks_cnt

# Soundfont ripper
PSG_DATA=/media/d/romhacking/gba-mus-ripper/psg_data.raw
GOLDENSUN_SYNTH=/media/d/romhacking/gba-mus-ripper/goldensun_synth.raw

rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))#


ASSRC1:= $(call rwildcard,src/,*.asm)
ASSRC2:= $(call rwildcard,src/,*.s)
CSRC:= $(call rwildcard,src/,*.c)
MIDSRC:=$(call rwildcard,asset/mus/,*.mid)
GFXSRC:=$(call rwildcard,asset/gfx/,*.png)
WAVSRC:=$(call rwildcard,asset/cry/,*.wav)


SAMPLESRC:=$(call rwildcard,asset/sample/,*.bin)
MAPTILESETSRC:=$(call rwildcard,src/,*.pts)
MAPSRC:=$(call rwildcard,src/,*.pmh)
CONSTANTS=$(MAPPROJ).constants
CONSTANTSH=$(shell ($(PYMAPCONSTEX) --get $(MAPPROJ)))

ASOBJS1= $(ASSRC1:%.asm=$(BLDPATH)/%.o)
ASOBJS2= $(ASSRC2:%.s=$(BLDPATH)/%.o)
COBJS= $(CSRC:%.c=$(BLDPATH)/%.o)
	
MIDAS= $(MIDSRC:%.mid=$(BLDPATH)/%.s)
MIDOBJS= $(MIDAS:%.s=%.o)
	
GFXC= $(GFXSRC:%.png=$(BLDPATH)/%.c)
GFXOBJS= $(GFXC:%.c=%.o)
	
WAVAS = $(WAVSRC:%.wav=$(BLDPATH)/%.s)
WAVOBJS = $(WAVAS:%.s=%.o)

SAMPLEAS = $(SAMPLESRC:%.bin=$(BLDPATH)/%.s)
SAMPLEOBJS = $(SAMPLEAS:%.s=%.o)
	
MAPAS = $(MAPSRC:%.pmh=$(BLDPATH)/%.s)
MAPOBJS = $(MAPAS:%.s=%.o)

MAPTILESETAS = $(MAPTILESETSRC:%.pts=$(BLDPATH)/%.s)
MAPTILESETOBJS = $(MAPTILESETAS:%.s=%.o)

.PHONY: all clean soundfont

$(ASOBJS1): $(BLDPATH)/%.o: %.asm $(CONSTANTSH)
	$(shell mkdir -p $(dir $@))
	$(PYPREPROC) -o $(BLDPATH)/$*.i $< $(CHARMAP) $(LANGUAGE) 
	$(AS) $(ASFLAGS)  $(BLDPATH)/$*.i -o $@

$(ASOBJS2): $(BLDPATH)/%.o: %.s $(CONSTANTSH)
	$(shell mkdir -p $(dir $@))
	$(PYPREPROC) -o $(BLDPATH)/$*.i $< $(CHARMAP) $(LANGUAGE)   
	$(AS) $(ASFLAGS)  $(BLDPATH)/$*.i -o $@
	
$(COBJS): $(BLDPATH)/%.o: %.c $(CONSTANTSH)
	$(shell mkdir -p $(dir $@))
	$(PYPREPROC) -o $(BLDPATH)/$*.c $< $(CHARMAP) $(CLANGMACRO)   
	$(CC) $(CFLAGS) $(BLDPATH)/$*.c -o $@
	
$(MIDAS): $(BLDPATH)/%.s: %.mid
	$(shell mkdir -p $(dir $@))
	$(MID2AGB) $(MIDFLAGS) -G$(shell echo "$<" | sed -n 's?.*\/vcg\(.*\)\/.*?\1?p') $< $@ > /dev/null
	#$(MID2AGB) $< $@ -m 92 -g voicegroup$(shell echo "$<" | sed -n 's?.*\/vcg\(.*\)\/.*?\1?p') 
	
$(MIDOBJS): %.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) $< -o $@	
	
$(GFXC): $(BLDPATH)/%.c: %.png
	$(shell mkdir -p $(dir $(GFXC)))
	$(GRIT) $< $(GRITFLAGS) -ff $(basename $<).grit -o $@ 
	
	
$(GFXOBJS): %.o: %.c
	$(shell mkdir -p $(dir $@))
	$(CC) $(CFLAGS) $< -o $@
	
	
$(WAVAS): $(BLDPATH)/%.s: %.wav
	
	$(shell mkdir -p $(dir $(WAVAS)))
	$(WAV2AGB) $< $@ $(WAVFLAGS)
	
$(WAVOBJS): %.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) $< -o $@
	
$(SAMPLEAS): $(BLDPATH)/%.s: %.bin
	$(shell mkdir -p $(dir $@))
	$(BIN2S) -o $@ $<
	
$(SAMPLEOBJS): %.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) $< -o $@
	
$(MAPAS): $(BLDPATH)/%.s: %.pmh
	$(shell mkdir -p $(dir $@))
	$(PYMAP2S) -o $@ $< $(MAPPROJ)

$(MAPOBJS): %.o: %.s $(CONSTANTSH)
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) $< -o $@
	
$(MAPTILESETAS): $(BLDPATH)/%.s: %.pts
	$(shell mkdir -p $(dir $@))
	$(PYSET2S)  -o $@ $<

$(MAPTILESETOBJS): %.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) $< -o $@
	

# Map project
$(BLDPATH)/$(basename $(MAPPROJ)).o: $(MAPPROJ)
#	Compile pmp map project
	@echo "Building map from project $(MAPPROJ)..." 
	$(PYPROJ2S) -b mapbanks -f mapfooters -o $(BLDPATH)/$(basename $(MAPPROJ)).s $(MAPPROJ)
	$(AS) $(ASFLAGS) $(BLDPATH)/$(basename $(MAPPROJ)).s -o $(BLDPATH)/$(basename $(MAPPROJ)).o
	
	
# Fata morgana lookup table
$(BLDPATH)/fata_morgana.o: $(DESERTMAP)
#	Run python script for generating a sorted list of morgana tiles
	@echo "Creating fata morgana lookup table $(FATAMORGANALUT) of size $(FATAMORGANALUTSIZE) based on $(DESERTMAP)..."
	$(PY3) tools/fata_morgana_gen.py $(DESERTMAP) $(BLDPATH)/fata_morgana.s $(FATAMORGANALUT) $(FATAMORGANALUTSIZE)
	$(AS) $(ASFLAGS) $(BLDPATH)/fata_morgana.s -o $(BLDPATH)/fata_morgana.o

	
# Pokemon crawler
$(PKMNCRAWLERDATA): 
	@echo "Fetching pokemon data form pokewiki.de..."
	$(PY3) tools/pokemon_move_generator_fetch.py $(PKMNCRAWLERDATA)	$(MAPPROJ)
	
$(BLDPATH)/pkmnmoves.o: $(PKMNCRAWLERDATA) $(BLDPATH)/src.o $(PKMNCRAWLEREXTERN)
	@echo "Dumping .text header of linked.o elf into $(LINKEDTEXTHEADER)..."
	$(READELF) -S $(BLDPATH)/src.o | grep ".text" > $(LINKEDTEXTHEADER)
	@echo "Dumping offset of $(PKMNEVOTABLE) into $(LINKEDEVOTABLEHEADER)..."
	$(READELF) -s $(BLDPATH)/src.o | grep $(PKMNEVOTABLE) > $(LINKEDEVOTABLEHEADER)
	$(PY3) tools/pokemon_move_generator.py $(MAPPROJ) $(BLDPATH)/src.o $(LINKEDTEXTHEADER) \
	$(LINKEDEVOTABLEHEADER) $(PKMNEVOTABLE) $(PKMNLVLUPATTACKS) $(PKMNEGGMOVES) \
	$(PKMNTMCOMPATIBILITY) $(PKMNMOVETUTORCOMPATIBILITY) $(PKMNINACESSIBLEMOVES) \
	$(PKMNCRAWLERDATA) $(BLDPATH)/pkmnmoves.c
	$(CC) $(CFLAGS) $(BLDPATH)/pkmnmoves.c -o $(BLDPATH)/pkmnmoves.o
	


	
# Intermediate object files (large input lists are not supported by console)

$(BLDPATH)/asset/mus.o: $(MIDOBJS)
	@echo "Collecting midi objects..."
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o $(BLDPATH)/asset/mus.o $(MIDOBJS)

$(BLDPATH)/asset.o: $(GFXOBJS) $(WAVOBJS) $(SAMPLEOBJS) $(BLDPATH)/asset/mus.o 
#	Create a ld script
	@echo "Collecting asset objects..."
	@echo "INPUT($(GFXOBJS) $(WAVOBJS) $(SAMPLEOBJS))" > $(BLDPATH)/asset.ld
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym -T $(BLDPATH)/asset.ld --relocatable -o $(BLDPATH)/asset.o $(BLDPATH)/asset/mus.o 
	
$(BLDPATH)/map.o: $(MAPOBJS) $(MAPTILESETOBJS) $(BLDPATH)/$(basename $(MAPPROJ)).o $(BLDPATH)/fata_morgana.o
#	Create a ld script
	@echo "Collecting map objects..."
	@echo "INPUT($(MAPOBJS) $(MAPTILESETOBJS) $(BLDPATH)/$(basename $(MAPPROJ)).o)" > $(BLDPATH)/map.ld
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym -T $(BLDPATH)/map.ld --relocatable -o $(BLDPATH)/map.o $(BLDPATH)/fata_morgana.o 
	
	
$(BLDPATH)/src.o: $(ASOBJS1) $(ASOBJS2) $(COBJS)
	@echo "Collecting src files..."
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o $(BLDPATH)/src.o $(ASOBJS1) $(ASOBJS2) $(COBJS)
	
# Building constants
$(CONSTANTSH): $(CONSTANTS)
	@echo "Exporting constants..."
	$(PYMAPCONSTEX) $(MAPPROJ)		
	
soundfont: $(BLDROM)
	$(shell mkdir -p $(BLDPATH)/soundfont)
	$(foreach vcg,000 001 002, \
	$(SOUNDFONTRIPPER) $(BLDROM) $(BLDPATH)/soundfont/vcg$(vcg).sf2 $(PSG_DATA) $(GOLDENSUN_SYNTH) -mv12 $(shell grep "voicegroup$(vcg)" $(BLDPATH)/symbols | cut -d' ' -f1 | sed -e "s/.*/obase\=16\;ibase\=16\;&-8000000/" | bc | sed -e "s/^/0x/");)

$(BLDROM): $(BLDPATH)/asset.o $(BLDPATH)/map.o $(BLDPATH)/pkmnmoves.o $(BLDPATH)/src.o
	@echo "Creating rom object..."
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o $(BLDPATH)/linked.o $(BLDPATH)/map.o $(BLDPATH)/asset.o $(BLDPATH)/pkmnmoves.o $(BLDPATH)/src.o
	$(ARS) patches.asm -sym $(SYMBOLDUMP) -strequ bldrom $(BLDROM) -strequ base $(BASEROM)
	#$(PY3) tools/index.py
	
all: $(BLDROM) soundfont
		
clean:
	rm -rf $(BLDPATH)
	rm -rf $(CONSTANTSH)
