
.org 0x080598CC
	ldr r2, =dns_hook_apply_shaders | 1
	bx r2
	.pool
	
.org 0x08059948
	ldr r2, =dns_hook_apply_shaders2 | 1
	bx r2
	.pool
	
.org 0x080834FC
	ldr r1, =dns_hook_apply_shaders3 | 1
	bx r1
	.pool
	
.org 0x08056824
	.word callback_switch_timezone | 1
	.pool
	
.org 0x08056758
	ldr r0, =hook_update_timezone | 1
	bx r0
	.pool
	
.org 0x0800F1E4
	ldr r1, =battle_bg_load | 1
	bx r1
	.pool

.org 0x083CC16C
        .word str_settings_color

.org 0x083CC198
        .word str_settings_color_dn
        .word str_settings_color_standard