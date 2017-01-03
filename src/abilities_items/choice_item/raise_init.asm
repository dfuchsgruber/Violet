.align 2
.thumb

.global scarf_poke1_hook
.global scarf_poke2_hook
.equ special_value, 29	@this special value indicates choice items (band, scarf, specs)


scarf_poke1_hook:
cmp r6, #0x18
bne no_heavy_item
mov r2, r8
lsr r2, #1
mov r8, r2
b end_scarf_poke1_hook
no_heavy_item:
cmp r6, #special_value
bne end_scarf_poke1_hook

@check if the pokemon wears a scarf

ldr r1, =0x02023BE4
mov r0, #0x58
mov r3, r9
mul r0, r3
add r0, r1
ldrh r0, [r0, #0x2E]	@item
bl get_v
cmp r0, #1
bne end_scarf_poke1_hook

mov r0, r8
lsr r0, #1
mov r2, r8
add r2, r0
mov r8, r2

end_scarf_poke1_hook:
ldr r1, =0x08014DCB
bx r1


scarf_poke2_hook:
cmp r6, #0x18
bne no_heavy_item2
lsr r7, #1
b end_scarf_poke2_hook
no_heavy_item2:
cmp r6, #special_value
bne end_scarf_poke2_hook

@check if has the effect param 1
ldr r2, =0x02023BE4
mov r0, #0x58
mov r1, r10
mul r1, r0
add r1, r2
ldrh r0, [r1, #0x2E]
bl get_v
cmp r0, #1
bne end_scarf_poke2_hook

lsr r2, r7, #1
add r7, r2
end_scarf_poke2_hook:
ldr r2, =0x02023BE4
ldr r0, =0x08014EAD
bx r0

get_v:
ldr r1, = get_item_effect_param
bx r1
