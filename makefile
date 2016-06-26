AS=@arm-none-eabi-as
LD=@arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy
GRIT=@grit
CC=@arm-none-eabi-gcc
NM=@arm-none-eabi-nm
ARS=@armipsd
MID2AGB=@mid2agb

ASFLAGS=-mthumb -Iinclude/
MIDFLAGS=-V92
CFLAGS=-c -std=gnu11 -mthumb -mthumb-interwork -mcpu=arm7tdmi -fno-inline -mlong-calls -march=armv4t -Wall -Wextra -Wconversion -O2 -Iinclude/
LDFLAGS=-z muldefs
GRITFLAGS=-fa -ftc

BLDPATH= bld
ASSRC1= $(shell find src -type f -iname '*.asm')
ASSRC2= $(shell find src -type f -iname '*.s')
CSRC= $(shell find src -type f -iname '*.c')
MIDSRC= $(shell find asset/mus -type f -iname '*.mid')
GFXSRC= $(shell find asset/gfx -type f -iname '*.png')
GFXSRC2 = $(shell find asset/gfx -type f -iname '*.bmp')

ASOBJS1= $(ASSRC1:%.asm=$(BLDPATH)/%.o)
ASOBJS2= $(ASSRC2:%.s=$(BLDPATH)/%.o)
COBJS= $(CSRC:%.c=$(BLDPATH)/%.o)
	
MIDAS= $(MIDSRC:%.mid=$(BLDPATH)/%.s)
MIDOBJS= $(MIDAS:%.s=$(BLDPATH)/%.o)
	
GFXC= $(BLDPATH)/asset/gfx/gfx.c

.PHONY: build clean

$(ASOBJS1): $(BLDPATH)/%.o: %.asm
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS)  $< -o $@

$(ASOBJS2): $(BLDPATH)/%.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) $< -o $@
	
$(COBJS): $(BLDPATH)/%.o: %.c asset
	$(shell mkdir -p $(dir $@))
	$(CC) $(CFLAGS) $< -o $@
	
$(MIDAS): $(BLDPATH)/%.s: %.mid
	$(shell mkdir -p $(dir $@))
	$(MID2AGB) $(MIDFLAGS) -G$(shell echo "$<" | sed -n 's?.*\/vcg\(.*\)\/.*?\1?p') $< $@ > /dev/null
	
$(MIDOBJS): $(BLDPATH)/%.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) $< -o $@	
	
$(GFXC): $(GFXSRC)
	$(shell mkdir -p $(dir $(GFXC)))
	@for png in $?; do \
	    grit $$png $(GRITFLAGS) -ff $${png%.png}.grit -o $@; \
	done
	mv -f $(subst .c,.h,$(GFXC)) include/gfx.h

asset: gfx music
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o $(BLDPATH)/asset.o $(BLDPATH)/asset/gfx/gfx.o $(BLDPATH)/asset/mus.o

gfx: $(GFXC)
	$(shell mkdir -p $(BLDPATH)/asset/gfx)
	$(CC) $(CFLAGS) -o $(BLDPATH)/asset/gfx/gfx.o $(GFXC)

music: $(MIDOBJS)
	$(shell mkdir -p $(BLDPATH)/asset/mus)
	$(AS) $(ASFLAGS) -o $(BLDPATH)/asset/mus/voice.o asset/mus/voice.s
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o $(BLDPATH)/asset/mus.o $(BLDPATH)/asset/mus/voice.o $(MIDOBJS)
	
build:  $(ASOBJS1) $(ASOBJS2) $(COBJS)
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o $(BLDPATH)/linked.o $(ASOBJS1) $(ASOBJS2) $(COBJS) $(BLDPATH)/asset.o
	$(ARS) patches.asm
	$(NM) $(BLDPATH)/linked.o -n -g --defined-only | \
	sed -e '{s/^/0x/g};{/.*\sA\s.*/d};{s/\sT\s/ /g}' > $(BLDPATH)/__symbols.sym
	cat $(BLDPATH)/__symbols.sym
		
clean:
	rm -rf $(BLDPATH)