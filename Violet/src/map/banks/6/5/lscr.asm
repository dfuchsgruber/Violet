
.global lscr_0x16a6cc

lscr_0x16a6cc:
	.byte 0x3
.word ow_script_0x16a6d7
	.byte 0x5
.word ow_script_init_union_room
	.byte 0x0




.include "overworld_script.s"
.include "healingplaces.s"

.global ow_script_0x16a6d7
ow_script_0x16a6d7:
sethealingplace HEALINGPLACE_AKTANIA
end