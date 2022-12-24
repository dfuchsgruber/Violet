.align 2
.thumb

.global tm_sale

.equ text, 0x88FB174

.thumb_func
tm_sale:
lsl r0, r4, #0x10
lsr r4, r0, #0x10
mov r0, r4
bl _item_get_pocket
cmp r0, #4
bne no_mpocket

mov r0, r4
mov r1, #1
bl checkitem
cmp r0, #0
bne has_tm

mov r0, r4
mov r1, #1
bl checkpcitem
cmp r0, #0
beq no_mpocket

has_tm:
ldr r1, =text
ldr r2, =0x0809BD4B
bx r2

@player possesses the tm

no_mpocket:
mov r0, r4
bl item_get_price
ldr r1, =0x0809BD29
bx r1

item_get_price:
ldr r1, =0x0809A9E5
bx r1

.thumb_func
_item_get_pocket:
ldr r1, =item_get_pocket
bx r1

checkitem:
ldr r2, =0x0809A025
bx r2

checkpcitem:
ldr r2, =0x0809A459
bx r2
