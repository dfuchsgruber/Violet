//attack split
.org 0x0803EE04
	ldr r1, = physical_special_item_load | 1
	bx r1
	.pool

.org 0x803EE04
        ldr r0, =hook_dmg_calc_pick_atk | 1
        bx r0
        .pool

.org 0x803F124
        ldr r0, =hook_dmg_calc_pick_def | 1
        bx r0
        .pool

.org 0x0803F290
        lsl r0, #0 //prevent fairy type (???) from not causing any dmg

.org 0x081375E0
        ldr r0, =load_split_chart3 | 1
        bx r0
        .pool

