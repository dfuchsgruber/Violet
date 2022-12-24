
.global lscr_0x16b05b

lscr_0x16b05b:
	.byte 0x3
.word ow_script_0x16b066
	.byte 0x5
.word ow_script_init_union_room
	.byte 0x0




.include "overworld_script.s"
.include "healingplaces.s"

.global ow_script_0x16b066
ow_script_0x16b066:
sethealingplace HEALINGPLACE_KASKADA
end