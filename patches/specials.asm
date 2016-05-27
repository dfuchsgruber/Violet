	
special_table equ 0x0815FCC0

.org (special_table + (0xC * 4))
	.word special_addkarma_wrap | 1
	.pool
	
.org (special_table +(0x16 * 4))
	.word special_get_rtc | 1
	.pool
	
.org (special_table +(0x17 * 4))
	.word special_set_trashflag | 1
	.pool
	
.org (special_table +(0x18 * 4))
	.word reset_trash_flags
	.pool