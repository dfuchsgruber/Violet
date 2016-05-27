AS=@arm-none-eabi-as
LD=@arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy
GRIT=@grit
CC=@arm-none-eabi-gcc
NM=@arm-none-eabi-nm
ARS=@armipsd

ASFLAGS=-mthumb

CFLAGS=-c -std=gnu11 -mthumb -mthumb-interwork -mcpu=arm7tdmi -fno-inline -mlong-calls -march=armv4t -Wall -Wextra -Wconversion -O2 -Isrc/include/
LDFLAGS=-z muldefs

BLDPATH= bld
ASSRC1= $(shell find src -type f -name '*.asm')
ASSRC2= $(shell find src -type f -name '*.s')
CSRC= $(shell find src -type f -name '*.c')

ASOBJS1= $(ASSRC1:%.asm=$(BLDPATH)/%.o)
ASOBJS2= $(ASSRC2:%.s=$(BLDPATH)/%.o)
COBJS= $(CSRC:%.c=$(BLDPATH)/%.o)

.PHONY: build clean

$(ASOBJS1): $(BLDPATH)/%.o: %.asm
	$(shell mkdir -p $(dir $@))
	$(CC) $(CFLAGS) -x assembler  $< -o $@

$(ASOBJS2): $(BLDPATH)/%.o: %.s
	$(shell mkdir -p $(dir $@))
	$(CC) $(CFLAGS) -x assembler  $< -o $@
	
$(COBJS): $(BLDPATH)/%.o: %.c
	$(shell mkdir -p $(dir $@))
	$(CC) $(CFLAGS) $< -o $@


build:  $(ASOBJS1) $(ASOBJS2) $(COBJS)
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o $(BLDPATH)/linked.o $(ASOBJS1) $(ASOBJS2) $(COBJS)
	$(ARS) patches.asm
	$(NM) $(BLDPATH)/linked.o -n -g --defined-only | \
	sed -e '{s/^/0x/g};{/.*\sA\s.*/d};{s/\sT\s/ /g}' > $(BLDPATH)/__symbols.sym
	cat $(BLDPATH)/__symbols.sym
		
clean:
	rm -rf $(BLDPATH)