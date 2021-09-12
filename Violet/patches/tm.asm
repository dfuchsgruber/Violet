// Items become unsellable
.org 0x081329ba
	bl _item_is_sellable

// Don't display a count / HM-box in the the TM-case
.org 0x08131eb8
	ldr r3, =tm_vm_print_item | 1
	bx r3
	.pool
_item_is_hm: // Target in branching range
	ldr r1, =item_is_hm | 1
	bx r1
	.pool

// Don't display a HM-box when when selecting a TM
.org 0x08132590
	bl _item_is_hm // Need a target in branching range


.org 0x08124f4c
	ldr r1, =sub_08124f4c | 1
	bx r1
	.pool
_item_is_sellable: // Target in branching range
	ldr r1, =item_is_sellable | 1
	bx r1
	.pool

.org 0x08125c98
	ldr r1, = pokemon_party_menu_big_callback_learned_move | 1
	bx r1
	.pool

.org 0x08131d98
	ldr r2, =tm_hm_get_str_number_and_name | 1
	bx r2 
	.pool

.org 0x08131ca0
	ldr r0, =tm_hm_initialize_list_menu | 1
	bx r0
	.pool

.org 0x08131c60
	ldr r0, =tm_hm_alloc_list_menu_buffers | 1
	bx r0
	.pool

.org 0x0813268c
	ldr r1, =tm_hm_context_menu_action_use | 1
	bx r1
	.pool

.org 0x0813252e
	// The procedure with which this string is assembled is very sus...
	// We do it as follows: Copy the tm string directly to the allocated buffer
	// since buffer0 may be unable to hold the color commands
	// r1 : item_actived
	mov r0, r4 // Allocated buffer
	ldr r2, =tm_hm_get_str_number_and_name | 1
	bl _blx_r2
	ldr r1, =str_lb_is_selected
	mov r0, r4 // Allocated buffer
	ldr r2, =strcat
	bl _blx_r2
	b 0x0813256a
	.pool
	_blx_r2:
		bx r2

.org 0x081325b2 // Print the HM symbol at the right height (2 pixels y offset)
	mov r2, #2

.org 0x08132904
	ldr r1, = tm_hm_context_callback_recharge | 1
	bx r1
	.pool