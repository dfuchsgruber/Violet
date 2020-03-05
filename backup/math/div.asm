.align 2
.thumb

.global __aeabi_uidiv
.global __aeabi_uidivmod


.thumb_func
__aeabi_uidiv:
.thumb_func
__aeabi_uidivmod:
	@ r0, r1 = num, denom
	mov r2, #1 @ place
	lsr r3, r0, #1 @ r3 = num >> 1
	place_check_loop:
		@ Check if (num >>1) >= den)
		cmp r3, r1
		blo exit_place_check_loop
		lsl r2, r2, #1 @ place <<= 1
		lsl r1, r1, #1 @ denom <<= 1
		b place_check_loop
	exit_place_check_loop:
	@ r3 = ret := 0
	mov r3, #0
	@ Perform division
	div_loop:
		cmp r2, #0
		beq exit_div_loop
		cmp r0, r1
		blo div_loop_tail
		@ Subtract
		sub r0, r1
		add r3, r2
	div_loop_tail:
		@ div loop tail
		lsr r2, r2, #1 @ place >>= 1
		lsr r1, r1, #1 @ denom >>= 1
		b div_loop
	exit_div_loop:
		@ r0, r1 = div, mod
		mov r1, r0
		mov r0, r3
	bx lr
