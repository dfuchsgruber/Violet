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
PY=@python3
BIN2S=@bin2s.py
PYSET2S=@pyset2s.py
PYMAP2S=@pymap2s.py
PYPROJ2S=@pyproj2s.py
PYPREPROC=@pypreproc.py
PYMAPCONSTEX=pymapconstex.py


# Py-Preprocessor settings (pypreproc.py)
CHARMAP=charmap.txt
LANGUAGE=LANG_GER#LANG_EN
CLANGMACRO=PSTRING

# Define compiler flags
ASFLAGS=-mthumb -Iinclude/as/ -Iinclude/as/constants/ -mcpu=arm7tdmi -march=armv4t --defsym $(LANGUAGE)=1
MIDFLAGS=-V92
CFLAGS=-c -std=c99 -mthumb -mthumb-interwork -mcpu=arm7tdmi -fno-inline -mlong-calls -march=armv4t -Wall -Wextra -Wconversion -O2 -Iinclude/c/ -Iinclude/c/constants/ -D$(LANGUAGE)
LDFLAGS=-z muldefs
GRITFLAGS=-fh! -ftc
WAVFLAGS=-c
MAPTILESETGRITFLAGS=-gu32 -gzl -gB 4 -gt -m! -p!


# Misc
BLDPATH= bld
MAPPROJ=map/proj.pmp


rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))#


ASSRC1:= $(call rwildcard,src/,*.asm)
ASSRC2:= $(call rwildcard,src/,*.s)
CSRC:= $(call rwildcard,src/,*.c)
MIDSRC:=$(call rwildcard,asset/mus/,*.mid)
GFXSRC:=$(call rwildcard,asset/gfx/,*.png)
WAVSRC:=$(call rwildcard,asset/cry/,*.wav)


SAMPLESRC:=$(call rwildcard,asset/sample/,*.bin)
MAPTILESETSRC:=$(call rwildcard,map/,*.pts)
MAPTILESETGFXSRC:=$(call rwildcard,map/,*.png)
MAPSRC:=$(call rwildcard,map/,*.pmh)
MAPASSRC:=$(call rwildcard,map/,*.asm)
CONSTANTS=map/proj.pmp.constants
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
	
MAPTILESETGFXC = $(MAPTILESETGFXSRC:%.png=$(BLDPATH)/%.c)
MAPTILESETGFXOBJS = $(MAPTILESETGFXC:%.c=%.o)
	
MAPASOBJS= $(MAPASSRC:%.asm=$(BLDPATH)/%.o)




.PHONY: all clean


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

$(MAPOBJS): %.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) $< -o $@
	
$(MAPTILESETAS): $(BLDPATH)/%.s: %.pts
	$(shell mkdir -p $(dir $@))
	$(PYSET2S)  -o $@ $<

$(MAPTILESETOBJS): %.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) $< -o $@
	
$(MAPTILESETGFXC): $(BLDPATH)/%.c: %.png
	$(shell mkdir -p $(dir $@))
	$(GRIT) $< $(MAPTILESETGRITFLAGS) -o $@
	
$(MAPTILESETGFXOBJS): %.o: %.c
	$(shell mkdir -p $(dir $@))
	$(CC) $(CFLAGS) $< -o $@

$(MAPASOBJS): $(BLDPATH)/%.o: %.asm $(CONSTANTSH)
	$(shell mkdir -p $(dir $@))
	$(PYPREPROC) -o $(BLDPATH)/$*.i $< $(CHARMAP) $(LANGUAGE)   
	$(AS) $(ASFLAGS)  $(BLDPATH)/$*.i -o $@



$(BLDPATH)/map/proj.o: map/proj.pmp
#	Compile pmp map project
	$(PYPROJ2S) -b mapbanks -f mapfooters -o $(BLDPATH)/map/proj.s map/proj.pmp
	$(AS) $(ASFLAGS) $(BLDPATH)/map/proj.s -o $(BLDPATH)/map/proj.o
	
$(BLDPATH)/map/morgana.o: map/3/21/map_3_21.pmh
#	Run python script for generating a sorted list of morgana tiles
	$(PY) tools/fata_morgana_gen.py map/3/21/map_3_21.pmh $(BLDPATH)/map/morgana.s fata_morgana_blocks fata_morgana_blocks_cnt
	$(AS) $(ASFLAGS) $(BLDPATH)/map/morgana.s -o $(BLDPATH)/map/morgana.o

$(BLDPATH)/asset.o: $(GFXOBJS) $(WAVOBJS) $(SAMPLEOBJS) $(MAPOBJS) $(MAPTILESETOBJS) $(MAPTILESETGFXOBJS) $(MAPASOBJS) $(BLDPATH)/map/proj.o $(BLDPATH)/asset/mus.o $(BLDPATH)/map/morgana.o
#	Create a ld script
	@echo "INPUT($(GFXOBJS) $(WAVOBJS) $(SAMPLEOBJS) $(MAPOBJS) $(MAPTILESETOBJS) $(MAPTILESETGFXOBJS) $(MAPASOBJS) $(BLDPATH)/map/proj.o $(BLDPATH)/map/morgana.o)" > $(BLDPATH)/asset.ld
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym -T $(BLDPATH)/asset.ld --relocatable -o $(BLDPATH)/asset.o $(BLDPATH)/asset/mus.o 
	



$(BLDPATH)/asset/mus.o: $(MIDOBJS)
	$(shell mkdir -p $(BLDPATH)/asset/mus)
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o $(BLDPATH)/asset/mus.o $(MIDOBJS)
	
$(CONSTANTSH): $(CONSTANTS)
	# Building constants
	$(PYMAPCONSTEX) $(MAPPROJ)
		
	
all: $(ASOBJS1) $(ASOBJS2) $(COBJS) $(BLDPATH)/asset.o #index
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o $(BLDPATH)/linked.o $(ASOBJS1) $(ASOBJS2) $(COBJS) $(BLDPATH)/asset.o
	$(ARS) patches.asm
	$(NM) $(BLDPATH)/linked.o -n -g --defined-only | \
	sed -e '{s/^/0x/g};{/.*\sA\s.*/d};{s/\sT\s/ /g}' > $(BLDPATH)/__symbols.sym
	cat $(BLDPATH)/__symbols.sym
	@cd tools && python3 index.py
		
clean:
	rm -rf $(BLDPATH)