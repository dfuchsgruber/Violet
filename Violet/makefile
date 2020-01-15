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
PYMAP2S=pymap2s.py
PYPREPROC=@pypreproc.py
PYMAPCONSTEX=pymapconstex.py
READELF=@arm-none-eabi-readelf
SOUNDFONTRIPPER=sound_font_ripper

# Py-Preprocessor settings (pypreproc.py)
LANGUAGE=LANG_GER
#LANGUAGE=LANG_EN

# Define compiler flags
ASFLAGS=-mthumb -Iinclude/as/ -Iinclude/as/constants/ -mcpu=arm7tdmi -march=armv4t --defsym $(LANGUAGE)=1
MIDFLAGS=-V92
CFLAGS=-c -std=c99 -mthumb -mthumb-interwork -mcpu=arm7tdmi -fno-inline -mlong-calls -march=armv4t -Wall -Werror -Wextra -Wconversion -O2 -Iinclude/c/ -D$(LANGUAGE)
LDFLAGS=-z muldefs -Ilibm
GRITFLAGS=-fh! -ftc
CRYFLAGS=-c
WAVFLAGS=
MAPTILESETGRITFLAGS=-gu32 -gzl -gB 4 -gt -m! -p!

BLDPATH=bld
BLDROM=$(BLDPATH)/violet.gba
BASEROM=base/bprd.gba
MAPPROJ=proj.pmp
SYMBOLDUMP=$(BLDPATH)/symbols

# Pokemon crawler settings
SPECIESCONSTANTTABLE=species
PKLPATH=pkl
MOVESETPKL=$(addprefix $(PKLPATH)/, $(addsuffix .pkl, $(shell tools/pokemon_move_generator/get_species.py $(MAPPROJ) $(SPECIESCONSTANTTABLE))))

# Soundfont ripper
PSG_DATA=psg_data.raw
GOLDENSUN_SYNTH=goldensun_synth.raw

rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))#


ASSRC1:= $(call rwildcard,src/,*.asm)
ASSRC2:= $(call rwildcard,src/,*.s)
CSRC:= $(call rwildcard,src/,*.c)
MIDSRC:=$(call rwildcard,asset/mus/,*.mid)
GFXSRC:=$(call rwildcard,asset/gfx/,*.png)
CRYSRC:=$(call rwildcard,asset/cry,*.wav)
WAVSRC:=$(call rwildcard,asset/sample,*.wav)


SAMPLESRC:=$(call rwildcard,asset/sample/,*.bin)
PYAGBSRC:=$(call rwildcard,src/,*.pms)
CONSTANTS=$(call rwildcard,constants/,*.const)

ASOBJS1= $(ASSRC1:%.asm=$(BLDPATH)/%.o)
ASDEP1 = $(ASOBJS1:%.o=%.d)
ASOBJS2= $(ASSRC2:%.s=$(BLDPATH)/%.o)
ASDEP2= $(ASOBJS1:%.o=%.d)
COBJS= $(CSRC:%.c=$(BLDPATH)/%.o)
CDEP = $(COBJS:%.o=%.d)
	
MIDAS= $(MIDSRC:%.mid=$(BLDPATH)/%.s)
MIDOBJS= $(MIDAS:%.s=%.o)
	
GFXC= $(GFXSRC:%.png=$(BLDPATH)/%.c)
GFXOBJS= $(GFXC:%.c=%.o)
	
CRYAS = $(CRYSRC:%.wav=$(BLDPATH)/%.s)
CRYOBJS = $(CRYAS:%.s=%.o)

WAVAS = $(WAVSRC:%.wav=$(BLDPATH)/%.s)
WAVOBJS = $(WAVAS:%.s=%.o)

SAMPLEAS = $(SAMPLESRC:%.bin=$(BLDPATH)/%.s)
SAMPLEOBJS = $(SAMPLEAS:%.s=%.o)
	
PYAGBS=$(PYAGBSRC:%.pms=$(BLDPATH)/%.s)
PYAGBOBJS=$(PYAGBS:%.s=%.o)
PYAGBDEP=$(PYAGBOBJS:%.o=%.d)

CONSTANTSHAS=$(CONSTANTS:%.const=include/as/%.s)
CONSTANTSHC=$(CONSTANTS:%.const=include/c/%.h)

OPENPAREN := (
CLOSEPAREN := )

include pokeapi/makefile tools/fata_morgana/makefile tools/index/makefile tools/cloud_maps/makefile

define build_list
	$(file >$(1),INPUT$(OPENPAREN))
	$(foreach file,$(2),$(file >>$(1),    $(file)))
	$(file >>$(1),$(CLOSEPAREN))
endef

.PHONY: all clean soundfont test

$(CONSTANTSHAS): include/as/%.s: %.const
	$(shell mkdir -p $(dir $@))
	$(PYMAPCONSTEX) -t as $< $@
	
$(CONSTANTSHC): include/c/%.h: %.const
	$(shell mkdir -p $(dir $@))
	$(PYMAPCONSTEX) -t c $< $@

$(ASOBJS1): $(BLDPATH)/%.o: %.asm
	$(shell mkdir -p $(dir $@))
	@echo "$<"
	$(PYPREPROC) -o $(BLDPATH)/$*.i $< $(MAPPROJ)
	$(AS) $(ASFLAGS) --MD $(BLDPATH)/$*.d $(BLDPATH)/$*.i -o $@

$(ASOBJS2): $(BLDPATH)/%.o: %.s
	$(shell mkdir -p $(dir $@))
	$(PYPREPROC) -o $(BLDPATH)/$*.i $< $(MAPPROJ)   
	$(AS) $(ASFLAGS) --MD $(BLDPATH)/$*.d $(BLDPATH)/$*.i -o $@

-include $(CDEP) $(ASDEP1) $(ASDEP2) $(PYAGBDEP) $(EXPORTED_STATS_DEP)


$(COBJS): $(BLDPATH)/%.o: %.c
	$(shell mkdir -p $(dir $@))
	@echo "$<"
	$(PYPREPROC) -o $(BLDPATH)/$*.c $< $(MAPPROJ)   
	$(CC) $(CFLAGS) -MMD $(BLDPATH)/$*.c -o $@
	
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
	
	
$(CRYAS): $(BLDPATH)/%.s: %.wav
	$(shell mkdir -p $(dir $(CRYAS)))
	$(WAV2AGB) $< $@ $(CRYFLAGS)
	
$(CRYOBJS): %.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) $< -o $@
	
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
	
$(PYAGBS): $(BLDPATH)/%.s: %.pms
	$(shell mkdir -p $(dir $@))
	$(PYMAP2S) $< $(MAPPROJ) -o $@
	
$(PYAGBOBJS): %.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) --MD $*.d $< -o $@
	
# Map project
$(BLDPATH)/$(basename $(MAPPROJ)).o: $(MAPPROJ)
#	Compile pmp map project
	@echo "Building map from project $(MAPPROJ)..."
	$(PYMAP2S) $(MAPPROJ) $(MAPPROJ) -o $(BLDPATH)/$(basename $(MAPPROJ)).s -p --headertable mapbanks --footertable mapfooters
	$(AS) $(ASFLAGS) $(BLDPATH)/$(basename $(MAPPROJ)).s -o $(BLDPATH)/$(basename $(MAPPROJ)).o
	
# Intermediate object files (large input lists are not supported by console)

$(BLDPATH)/asset/mus.o: $(MIDOBJS)
	@echo "Collecting midi objects..."
	$(call build_list,$(BLDPATH)/midi.ld,$(MIDOBJS))
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym -T $(BLDPATH)/midi.ld --relocatable -o $(BLDPATH)/asset/mus.o

$(BLDPATH)/asset.o: $(GFXOBJS) $(CRYOBJS) $(SAMPLEOBJS) $(WAVOBJS) $(BLDPATH)/asset/mus.o 
#	Create a ld script
	$(call build_list,$(BLDPATH)/asset.ld,$(GFXOBJS) $(CRYOBJS) $(SAMPLEOBJS) $(WAVOBJS))
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym -T $(BLDPATH)/asset.ld --relocatable -o $(BLDPATH)/asset.o $(BLDPATH)/asset/mus.o 
	
$(BLDPATH)/map.o: $(PYAGBOBJS) $(BLDPATH)/$(basename $(MAPPROJ)).o $(BLDPATH)/fata_morgana.o
#	Create a ld script
	$(call build_list,$(BLDPATH)/map.ld,$(PYAGBOBJS) $(BLDPATH)/$(basename $(MAPPROJ)).o)
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym -T $(BLDPATH)/map.ld --relocatable -o $(BLDPATH)/map.o $(BLDPATH)/fata_morgana.o 
	
	
$(BLDPATH)/src.o: $(ASOBJS1) $(ASOBJS2) $(COBJS) $(CLOUD_MAPS_OBJ)
	@echo "Collecting src files..."
	$(call build_list,$(BLDPATH)/sources.ld,$(ASOBJS1) $(ASOBJS2) $(COBJS) $(CLOUD_MAPS_OBJ))
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym -T $(BLDPATH)/sources.ld --relocatable -o $(BLDPATH)/src.o
		
	
soundfont: $(BLDROM)
	$(shell mkdir -p $(BLDPATH)/soundfont)
	$(foreach vcg,000 001 002, \
	$(SOUNDFONTRIPPER) $(BLDROM) $(BLDPATH)/soundfont/vcg$(vcg).sf2 $(PSG_DATA) $(GOLDENSUN_SYNTH) -mv12 $(shell grep "voicegroup$(vcg)" $(BLDPATH)/symbols | cut -d' ' -f1 | sed -e "s/.*/obase\=16\;ibase\=16\;&-8000000/" | bc | sed -e "s/^/0x/");)

$(BLDROM): $(CONSTANTSHAS) $(CONSTANTSHC) $(BLDPATH)/asset.o $(BLDPATH)/map.o $(BLDPATH)/src.o $(EXPORTED_STATS_OBJ)
	@echo "Creating rom object..."
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o $(BLDPATH)/linked.o $(BLDPATH)/map.o $(BLDPATH)/asset.o $(BLDPATH)/src.o $(EXPORTED_STATS_OBJ)
	$(ARS) patches.asm -sym $(SYMBOLDUMP) -strequ bldrom $(BLDROM) -strequ base $(BASEROM)
	#$(PY3) tools/index.py
	
all: $(BLDROM) soundfont
		
clean:
	rm -rf $(BLDPATH)
