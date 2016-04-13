@insert at 0x45878 via bx_r1.bin (00 49 08 47 XX XX XX XX)
.align 2
.thumb

.global get_pokemons_basis_stage

.equ feelinara, 0x2f
.equ folipurba, 0x2e
.equ glaziola, 0xa3
.equ evoli, 0x85

get_pokemons_basis_stage:
push {r7}
lsl r0, #0x10
lsr r2, r0, #0x10
mov r0, #0
@now we check_weather we have one of our poke
ldr r1, =feelinara
cmp r2, r1
beq ret_e
ldr r1, =folipurba
cmp r2, r1
beq ret_e
ldr r1, =glaziola
cmp r1, r2
beq ret_e
ldr r1, =0x08045881
bx r1
ret_e:
ldr r2, =evoli
ldr r0, =0x080458E3
bx r0
