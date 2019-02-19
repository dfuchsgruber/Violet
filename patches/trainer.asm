//trainer
.org 0x08011264
	ldr r2, =trainer_build_party | 1
	bx r2
	.pool

.org 0x0802596C
	ldr r0, =hook_price_money | 1
	bx r0
	.pool
	
	
.org 0x080C6F38
	ldr r0, =hook_trainer_items | 1
	bx r0
	.pool

.org 0x080802DC
        ldr r1, =checktrainerflag | 1
        bl do_r1_3
        pop {r1}
        do_r1_3:
        bx r1
        .pool


.org 0x081A7C81
        .byte 0x4
        .word subscript_trainer_challange

.org 0x800fb84
	.word trainers

.org 0x800fc04
	.word trainers

.org 0x80112c0
	.word trainers

.org 0x8011340
	.word trainers

.org 0x8011648
	.word trainers

.org 0x80156ac
	.word trainers

.org 0x80258a4
	.word trainers

.org 0x8025960
	.word trainers

.org 0x8037d6c
	.word trainers

.org 0x8037f40
	.word trainers

.org 0x8043594
	.word trainers

.org 0x8043784
	.word trainers

.org 0x8043f28
	.word trainers

.org 0x807fdec
	.word trainers

.org 0x807ff1c
	.word trainers

.org 0x80c70f8
	.word trainers

.org 0x80d7ac4
	.word trainers

.org 0x80d7af8
	.word trainers

.org 0x80d8360
	.word trainers

.org 0x81138d4
	.word trainers

.org 0x81152f4
	.word trainers

.org 0x812c098
	.word trainers

.org 0x080d7b0c
	.word trainer_class_names

.org 0x0811b58c
	.word trainer_class_names

.org 0x080D7A48
        ldr r2, =trainer_get_class_name | 1
        bx r2
        .pool

