@insert at 0x42E98 via bx_r0.bin

.align 2
.thumb

.global evolutions_evee

.equ feelinara, 0x2f
.equ folipurba, 0x2e
.equ glaziola, 0xa3

.equ evoli, 0x85

.equ attack_data, 0x9100000	@this is my repointed offset

@format: 0xAABB , AA = Map, BB=Bank (in HEX!)
.equ mapdataeis, 0xAAAA
.equ mapdatagrass, 0xBBBB

.equ fairy, 0x9


evolutions_evee:
@lets check weather we have evoli
ldr r0, =evoli
cmp r0, r7
bne normal
@first we check weather feelinara_condition_is_given
ldr r0, [sp, #8]	@happiness
cmp r0, #0x80
ble map_eveelutions
@now we have to check weather feelinara knows fairy move
mov r0, r8
bl scan_for_fairy_attack
cmp r0, #0
beq map_eveelutions
ldr r0, =feelinara
mov r10, r0
return_r10:
ldr r0, =0x080430A3
bx r0
map_eveelutions:
ldr r2, = 0x2025530 	@current Map
ldrh r2, [r2]
ldr r0, =mapdataeis

cmp r0, r2
bne check_grass
@we evolve into glaziola
ldr r0, =glaziola
mov r10, r0
b return_r10
check_grass:
ldr r0, =mapdatagrass
cmp r0, r2
bne normal
ldr r0, =folipurba
mov r10, r0
b return_r10
normal:
ldr r1, =0x08042EBC
ldr r1, [r1]		@reference to evolution table, uses a already given pointer to read from
ldr r0, [sp, #4]
lsl r2, r0, #3
add r0, r6, r7
lsl r0, #3
ldr r3, =0x08042EA1
bx r3

get_pkmn_attr:
ldr r3, =0x803FAE9
bx r3

scan_for_fairy_attack:
push {r4-r5, lr}
mov r5, r0
mov r4, #0	@cnt
scan_attacks:
mov r0, r5
mov r1, #0xD
add r1, r4
mov r2, #0
bl get_pkmn_attr
mov r1, #0xC
mul r0, r1
ldr r1, =attack_data
add r0, r1
ldrb r0, [r0,#2]
cmp r0, #fairy
beq found_fairy_attack
add r4, #1
cmp r4, #3
ble scan_attacks
mov r0, #0
b end_scan
found_fairy_attack:
mov r0, #1
end_scan:
pop {r4-r5, pc}



