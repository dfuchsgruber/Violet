@ This hook changes the overworld state after initializing a wild battle such that
@ a script is triggered, as long as TRAINERSCHOOL_PROGRESS <= 6

.include "vars.s"

.global wildbattle_trainerschool_hook_trigger_script

.thumb

.thumb_func
wildbattle_trainerschool_hook_trigger_script:
	ldr r0, =TRAINERSCHOOL_PROGRESS
	bl _var_access
	ldrh r1, [r0]
	cmp r1, #6
	ble trigger_script
	@ Set state to normal wildbattle
	ldr r0, =0x03004FC8
	ldrb r1, [r0]
	mov r2, #2
	ldr r3, =0x0806CC7A | 1
	bx r3

trigger_script:
	ldr r0, =0x0806CAD0 | 1
	bx r0

_var_access:
	ldr r1, =var_access
	bx r1
