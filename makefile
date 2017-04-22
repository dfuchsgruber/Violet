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
MAP2AGB=@D:/Hacking/map2agb/map2agb/bin/Debug/map2agb.exe

ASFLAGS=-mthumb -Iinclude/
MIDFLAGS=-V92
CFLAGS=-c -std=c99 -mthumb -mthumb-interwork -mcpu=arm7tdmi -fno-inline -mlong-calls -march=armv4t -Wall -Wextra -Wconversion -O2 -Iinclude/
LDFLAGS=-z muldefs
GRITFLAGS=-fh! -ftc
STR2SFLAGS=-t table.tbl -a 0xFF -l GER
WAVFLAGS=-c
MAPTILESETGRITFLAGS=-gu32 -gzl -gB 4 -gt -m! -p!

BLDPATH= bld
ASSRC1= $(shell find src -type f -iname '*.asm')
ASSRC2= $(shell find src -type f -iname '*.s')
CSRC= $(shell find src -type f -iname '*.c')
MIDSRC= $(shell find Violet_Sources_Private/asset/mus -type f -iname '*.mid')
GFXSRC= $(shell find Violet_Sources_Private/asset/gfx -type f -iname '*.png')
STRSRC = $(shell find Violet_Sources_Private/asset/string -type f -iname '*.txt')
WAVSRC = $(shell find Violet_Sources_Private/asset/cry -type f -iname '*.wav')
SAMPLESRC = $(shell find Violet_Sources_Private/asset/sample -type f -iname '*.bin')
MAPSRC = $(shell find map -type f -iname '*.mapheader')
MAPTILESETSRC = $(shell find map -type f -iname '*.tileset')
MAPTILESETGFXSRC = $(shell find map -type f -iname '*.png')


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
	
MAPAS = $(MAPSRC:%.mapheader=$(BLDPATH)/%.s)
MAPOBJS = $(MAPAS:%.s=%.o)
	
MAPTILESETAS = $(MAPTILESETSRC:%.tileset=$(BLDPATH)/%.s)
MAPTILESETOBJS = $(MAPTILESETAS:%.s=%.o)
	
MAPTILESETGFXC = $(MAPTILESETGFXSRC:%.png=$(BLDPATH)/%.c)
MAPTILESETGFXOBJS = $(MAPTILESETGFXC:%.c=%.o)

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
	
$(MAPAS): $(BLDPATH)/%.s: %.mapheader
	$(shell mkdir -p $(dir $@))
	$(MAP2AGB)  -o $@ -m map $<

$(MAPOBJS): %.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) $< -o $@
	
$(MAPTILESETAS): $(BLDPATH)/%.s: %.tileset
	$(shell mkdir -p $(dir $@))
	$(MAP2AGB)  -o $@ -m tileset $<

$(MAPTILESETOBJS): %.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) $< -o $@
	
$(MAPTILESETGFXC): $(BLDPATH)/%.c: %.png
	$(shell mkdir -p $(dir $@))
	$(GRIT) $< $(MAPTILESETGRITFLAGS) -o $@
	
$(MAPTILESETGFXOBJS): %.o: %.c
	$(shell mkdir -p $(dir $@))
	$(CC) $(CFLAGS) $< -o $@
	

$(BLDPATH)/asset.o: $(GFXOBJS) $(WAVOBJS) $(SAMPLEOBJS) $(MAPOBJS) $(MAPTILESETOBJS) $(MAPTILESETGFXOBJS) $(BLDPATH)/Violet_Sources_Private/asset/mus.o $(BLDPATH)/Violet_Sources_Private/asset/str.o
#	Create a ld script
	@echo "INPUT($(GFXOBJS) $(WAVOBJS) $(SAMPLEOBJS) $(MAPOBJS) $(MAPTILESETOBJS) $(MAPTILESETGFXOBJS))" > $(BLDPATH)/asset.ld
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym -T $(BLDPATH)/asset.ld --relocatable -o $(BLDPATH)/asset.o $(BLDPATH)/Violet_Sources_Private/asset/mus.o $(BLDPATH)/Violet_Sources_Private/asset/str.o
	

$(BLDPATH)/Violet_Sources_Private/asset/str.o: $(STROBJS)
	$(shell mkdir -p $(BLDPATH)/Violet_Sources_Private/asset/string)
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o $(BLDPATH)/Violet_Sources_Private/asset/str.o $(STROBJS)


$(BLDPATH)/Violet_Sources_Private/asset/mus.o: $(MIDOBJS)
	$(shell mkdir -p $(BLDPATH)/Violet_Sources_Private/asset/mus)
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o $(BLDPATH)/Violet_Sources_Private/asset/mus.o $(MIDOBJS)
	
build:  $(ASOBJS1) $(ASOBJS2) $(COBJS) $(BLDPATH)/asset.o
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o $(BLDPATH)/linked.o $(ASOBJS1) $(ASOBJS2) $(COBJS) $(BLDPATH)/asset.o
	$(ARS) patches.asm
	$(NM) $(BLDPATH)/linked.o -n -g --defined-only | \
	sed -e '{s/^/0x/g};{/.*\sA\s.*/d};{s/\sT\s/ /g}' > $(BLDPATH)/__symbols.sym
	cat $(BLDPATH)/__symbols.sym
		
clean:
	rm -rf $(BLDPATH)