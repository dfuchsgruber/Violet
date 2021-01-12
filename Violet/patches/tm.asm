
// tm hack
/**
	
.org 0x0809BD20
	ldr r1, =tm_sale | 1
	bx r1
	.pool
	
.org 0x0809BE44
	ldr r0, =tm_count_arrows | 1
	bx r0
	.pool
	
// Prevents TMs from being given
//.org 0x08132926
//	cmp r0, #0xFF
.org 0x08132924
	mov r0, #1

.org 0x08132752
	mov r0, #1

	
// TM count in bag
.org 0x08108752
	b 0x081087a8

**/

// Items become unsellable
.org 0x081329ba
	bl _item_is_sellable

// Don't display a count / HM-box in the the TM-case
.org 0x08131ee6
	bl _item_is_hm
	cmp r0, #0
	beq 0x08131f4e // Don't draw anything
	b 0x08131f44 // Draw HM tile
_item_is_hm: // Target in branching range
	ldr r1, =item_is_hm | 1
	bx r1
	.pool

// Don't display a HM-box when when selecting a TM
.org 0x08132590
	bl _item_is_hm // Need a target in branching range

// Don't use up TMs on use
.org 0x08124fba
	b 0x08124fcc
_item_is_sellable: // Target in branching range
	ldr r1, =item_is_sellable | 1
	bx r1
	.pool

// Don't use up TMs on use if cancelled "fancy" item animation
.org 0x08125cd0
	lsl r0, #0
	lsl r0, #0
