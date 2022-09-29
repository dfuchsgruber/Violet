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
