//trainer
.org 0x08011264
	ldr r2, =trainer_party_setup | 1
	bx r2
	.pool
	
	
.org 0x080C6EC4
	ldr r0, =trainer_load_items_and_ai | 1
	bx r0
	.pool

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



.org 0x080802d0
	.word ow_script_trainerbattle_challange_spotted


.org 0x0808018c
	ldr r1, =trainer_configure_by_overworld_script | 1
	bx r1
	.pool

.org 0x08081a94
	ldr r0, =trigger_npc_spotting | 1
	bx r0
	.pool

.org 0x08080634
	ldr r0, =trainer_get_challange_message | 1
	bx r0
	.pool

.org 0x08080584
	ldr r0, =trainer_play_encounter_music | 1
	bx r0
	.pool
 
 .org 0x08080358
	ldr r0, =trainer_set_flags | 1
	bx r0
	.pool
/**
**/