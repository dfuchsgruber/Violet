@hook at 3EE04 via r1

.align 2
.thumb
.global physical_special_item_load

physical_special_item_load:
cmp r9, r0
bne scan_next_entry

@code

ldr r0, [sp, #8]
mov r1, #0xC
mul r0, r1
ldr r1, =0x09100000 @attack_data
add r0, r1
ldrb r1, [r0, #10]
cmp r1, #0
beq physical
ldr r0, =0x0803EE0F @attack_is_special
bx r0

physical:
ldr r0, =0x0803ECD5 @attack_is_physical
bx r0

scan_next_entry:
ldr r1, =0x0803EE3D @scan_next_entry
bx r1
