
@this code makes the additional ow we load into every map also appear as NPC be loading personcnt+1 as counter variable

.global pokeradar_map_increment_person_cnt
.global pokeradar_npc_get_person_increment_person_cnt

.align 2
.thumb

.thumb_func
pokeradar_map_increment_person_cnt:
mov r0, r1
add r0, #0x10
lsl r0, #0x10
lsr r0, #0x10
mov r10, r0
ldrb r3, [r3]
add r3, #1
str r3, [sp, #0x10]
ldr r5, =0x0805EC75
bx r5

.thumb_func
pokeradar_npc_get_person_increment_person_cnt:
ldrb r2, [r0]
add r2, #1
mov r0, r4
bl person_get_by_target_index
pop {r4}
pop {r1}
bx r1

person_get_by_target_index:
ldr r3, =0x0805FDb1
bx r3
