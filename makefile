AS=@arm-none-eabi-as
LD=@arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy
GRIT=@grit
CC=@arm-none-eabi-gcc
NM=@arm-none-eabi-nm
ARS=@armipsd
MID2AGB=@mid2agb

ASFLAGS=-mthumb
MIDFLAGS=-V92
CFLAGS=-c -std=gnu11 -mthumb -mthumb-interwork -mcpu=arm7tdmi -fno-inline -mlong-calls -march=armv4t -Wall -Wextra -Wconversion -O2 -Iinclude/
LDFLAGS=-z muldefs

BLDPATH= bld
ASSRC1= $(shell find src -type f -name '*.asm')
ASSRC2= $(shell find src -type f -name '*.s')
CSRC= $(shell find src -type f -name '*.c')
MIDSRC000= $(shell find mus/vcg000 -type f -name '*.mid')
MIDSRC001= $(shell find mus/vcg001 -type f -name '*.mid')



ASOBJS1= $(ASSRC1:%.asm=$(BLDPATH)/%.o)
ASOBJS2= $(ASSRC2:%.s=$(BLDPATH)/%.o)
COBJS= $(CSRC:%.c=$(BLDPATH)/%.o)
MIDAS000= $(MIDSRC000:%.mid=$(BLDPATH)/%.s)
MIDOBJS000= $(MIDAS000:%.s=$(BLDPATH)/%.o)
MIDAS001= $(MIDSRC001:%.mid=$(BLDPATH)/%.s)
MIDOBJS001= $(MIDAS001:%.s=$(BLDPATH)/%.o)

.PHONY: build clean

$(ASOBJS1): $(BLDPATH)/%.o: %.asm
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS)  $< -o $@

$(ASOBJS2): $(BLDPATH)/%.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) -x assembler  $< -o $@
	
$(COBJS): $(BLDPATH)/%.o: %.c
	$(shell mkdir -p $(dir $@))
	$(CC) $(CFLAGS) $< -o $@
	
$(MIDAS000): $(BLDPATH)/%.s: %.mid
	$(shell mkdir -p $(dir $@))
	$(MID2AGB) $(MIDFLAGS) -G000 $< $@
	
$(MIDOBJS000): $(BLDPATH)/%.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) $< -o $@
	
$(MIDAS001): $(BLDPATH)/%.s: %.mid
	$(shell mkdir -p $(dir $@))
	$(MID2AGB) $(MIDFLAGS) -G001 $< $@
	
$(MIDOBJS001): $(BLDPATH)/%.o: %.s
	$(shell mkdir -p $(dir $@))
	$(AS) $(ASFLAGS) $< -o $@

music: $(MIDOBJS000) $(MIDOBJS001)	
	$(AS) $(ASFLAGS) mus/voice.s -o $(BLDPATH)/voice.o
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o $(BLDPATH)/mus.o $(MIDOBJS000) $(MIDOBJS001) $(BLDPATH)/voice.o
	
build:  $(ASOBJS1) $(ASOBJS2) $(COBJS) music
	
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o $(BLDPATH)/linked.o $(ASOBJS1) $(ASOBJS2) $(COBJS) $(BLDPATH)/mus.o
	$(ARS) patches.asm
	$(NM) $(BLDPATH)/linked.o -n -g --defined-only | \
	sed -e '{s/^/0x/g};{/.*\sA\s.*/d};{s/\sT\s/ /g}' > $(BLDPATH)/__symbols.sym
	cat $(BLDPATH)/__symbols.sym
		
clean:
	rm -rf $(BLDPATH)