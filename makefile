AS=@arm-none-eabi-as
LD=@arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy
GRIT=@grit
CC=@arm-none-eabi-gcc
NM=@arm-none-eabi-nm
ARS=@armipsd

ASFLAGS=-mthumb

CFLAGS=-c -std=gnu11 -mthumb -mthumb-interwork -mcpu=arm7tdmi -fno-inline -mlong-calls -march=armv4t -Wall -Wextra -Wconversion -O2
CFLAGSAS=-c -std=gnu11 -mthumb -mthumb-interwork -mcpu=arm7tdmi -fno-inline -mlong-calls -march=armv4t -Wall -Wextra -Wconversion -O2 -x assembler
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
	$(CC) $(CFLAGSAS) $< -o $@

$(ASOBJS2): $(BLDPATH)/%.o: %.s
	$(shell mkdir -p $(dir $@))
	$(CC) $(CFLAGSAS) $< -o $@
	
$(COBJS): $(BLDPATH)/%.o: %.c
	$(shell mkdir -p $(dir $@))
	$(CC) $(CFLAGS) $< -o $@


build:  $(ASOBJS1) $(ASOBJS2) $(COBJS)
	$(info $(ASOBJS1) $(ASOBJS2) $(COBJS))
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o "bld/linked.o" $(ASOBJS1) $(ASOBJS2) $(COBJS)
	$(ARS) patches.asm
	$(NM) "bld/linked.o" -n -g --defined-only
		
clean:
	rm -rf $(BLDPATH)