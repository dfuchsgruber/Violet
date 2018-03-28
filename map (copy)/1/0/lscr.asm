.include "std.s"

.global lscr_0x719d18

lscr_0x719d18:
	.byte 0x2
.word lscr_0x719cc3
	.byte 0x3
.word ow_script_0x87bd10
	.byte 0x4
.word lscr_0x719d28
	.byte 0x0


.align 4
.global lscr_0x719cc3

lscr_0x719cc3:
	.hword STORY_PROGRESS, 0x1b
	.word ow_script_0x8f2223
	.hword 0x0




.align 4
.global lscr_0x719d28

lscr_0x719d28:
	.hword STORY_PROGRESS, 0x1b
	.word ow_script_0x81c506
	.hword 0x0
