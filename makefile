WAV2AGB=@wav2agb
AR=arm-none-eabi-ar
AS=@arm-none-eabi-as
LD=@arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy
GRIT=@grit
CC=@arm-none-eabi-gcc
NM=@arm-none-eabi-nm
ARS=@armipsd
MID2AGB=@mid2agb
STR2S=@python str2s.py
PY=@python
BIN2S=@python bin2s.py
PYSET2S=@python tools/pyset2s.py
PYMAP2S=@python tools/pymap2s.py
PYPROJ2S=@python tools/pyproj2s.py

ASFLAGS=-mthumb -Iinclude/
MIDFLAGS=-V92
CFLAGS=-c -std=c99 -mthumb -mthumb-interwork -mcpu=arm7tdmi -fno-inline -mlong-calls -march=armv4t -Wall -Wextra -Wconversion -O2 -Iinclude/
LDFLAGS=-z muldefs
GRITFLAGS=-fh! -ftc
STR2SFLAGS=-t table.tbl -a 0xFF -l GER
WAVFLAGS=-c
MAPTILESETGRITFLAGS=-gu32 -gzl -gB 4 -gt -m! -p!

BLDPATH= bld

rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))#


ASSRC1:= $(call rwildcard,src/,*.asm)
ASSRC2:= $(call rwildcard,src/,*.s)
CSRC:= $(call rwildcard,src/,*.c)
MIDSRC:=$(call rwildcard,asset/mus/,*.mid)
GFXSRC:=$(call rwildcard,asset/gfx/,*.png)
STRSRC:=$(call rwildcard,asset/string/,*.txt)
WAVSRC:=$(call rwildcard,asset/cry/,*.wav)


SAMPLESRC:=$(call rwildcard,asset/sample/,*.bin)
MAPTILESETSRC:=$(call rwildcard,map/,*.pts)
MAPTILESETGFXSRC:=$(call rwildcard,map/,*.png)
MAPSRC:=$(call rwildcard,map/,*.pmh)
MAPASSRC:=$(call rwildcard,map/,*.asm)
MAPSTRSRC:=$(call rwildcard,map/,*.txt)

ASOBJS1= $(ASSRC1:%.asm=$(BLDPATH)/%.o)
ASOBJS2= $(ASSRC2:%.s=$(BLDPATH)/%.o)
COBJS= $(CSRC:%.c=$(BLDPATH)/%.o)
	
MIDAS= $(MIDSRC:%.mid=$(BLDPATH)/%.s)
MIDOBJS= $(MIDAS:%.s=%.o)
	
GFXC= $(GFXSRC:%.png=$(BLDPATH)/%.c)
GFXOBJS= $(GFXC:%.c=%.o)

STRAS= $(STRSRC:%.txt=$(BLDPATH)/%.s)
STROBJS= $(STRAS:%.s=$(BLDPATH)/%.o)
	
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

MAPSTRAS= $(MAPSTRSRC:%.txt=$(BLDPATH)/%.s)
MAPSTROBJS= $(MAPSTRAS:%.s=%.o)

.PHONY: build clean

$(ASOBJS1): $(BLDPATH)/%.o: %.asm
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS)  $< -o $@

$(ASOBJS2): $(BLDPATH)/%.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) $< -o $@
	
$(COBJS): $(BLDPATH)/%.o: %.c 
	$(shell mkdir -p $(dir $@))
	$(CC) $(CFLAGS) $< -o $@
	
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
	
$(STRAS): $(BLDPATH)/%.s: %.txt
	$(shell mkdir -p $(dir $@))
	$(STR2S) $(STR2SFLAGS) -i $< -o $@
	
$(STROBJS): $(BLDPATH)/%.o: %.s
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
	$(BIN2S) -i $< -o $@
	
$(SAMPLEOBJS): %.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) $< -o $@
	
$(MAPAS): $(BLDPATH)/%.s: %.pmh
	$(shell mkdir -p $(dir $@))
	$(PYMAP2S)  -o $@ $<

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

$(MAPASOBJS): $(BLDPATH)/%.o: %.asm
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS)  $< -o $@

$(MAPSTRAS): $(BLDPATH)/%.s: %.txt
	$(shell mkdir -p $(dir $@))
	$(STR2S) $(STR2SFLAGS) -i $< -o $@
	
$(MAPSTROBJS): %.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) $< -o $@


$(BLDPATH)/map/proj.o: map/proj.pmp
#	Compile pmp map project
	$(PYPROJ2S) -b mapbanks -f mapfooters -o $(BLDPATH)/map/proj.s map/proj.pmp
	$(AS) $(ASFLAGS) $(BLDPATH)/map/proj.s -o $(BLDPATH)/map/proj.o

$(BLDPATH)/asset.o: $(GFXOBJS) $(WAVOBJS) $(SAMPLEOBJS) $(MAPOBJS) $(MAPTILESETOBJS) $(MAPTILESETGFXOBJS) $(MAPASOBJS) $(MAPSTROBJS) $(BLDPATH)/map/proj.o $(BLDPATH)/asset/mus.o $(BLDPATH)/asset/str.o
#	Create a ld script
	@echo "INPUT($(GFXOBJS) $(WAVOBJS) $(SAMPLEOBJS) $(MAPOBJS) $(MAPTILESETOBJS) $(MAPTILESETGFXOBJS) $(MAPASOBJS) $(MAPSTROBJS) $(BLDPATH)/map/proj.o)" > $(BLDPATH)/asset.ld
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym -T $(BLDPATH)/asset.ld --relocatable -o $(BLDPATH)/asset.o $(BLDPATH)/asset/mus.o $(BLDPATH)/asset/str.o
	

$(BLDPATH)/asset/str.o: $(STROBJS)
	$(shell mkdir -p $(BLDPATH)/asset/string)
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o $(BLDPATH)/asset/str.o $(STROBJS)


$(BLDPATH)/asset/mus.o: $(MIDOBJS)
	$(shell mkdir -p $(BLDPATH)/asset/mus)
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o $(BLDPATH)/asset/mus.o $(MIDOBJS)
	
build:  $(ASOBJS1) $(ASOBJS2) $(COBJS) $(BLDPATH)/asset.o
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o $(BLDPATH)/linked.o $(ASOBJS1) $(ASOBJS2) $(COBJS) $(BLDPATH)/asset.o
	$(ARS) patches.asm
	$(NM) $(BLDPATH)/linked.o -n -g --defined-only | \
	sed -e '{s/^/0x/g};{/.*\sA\s.*/d};{s/\sT\s/ /g}' > $(BLDPATH)/__symbols.sym
	cat $(BLDPATH)/__symbols.sym
		
clean:
	rm -rf $(BLDPATH)