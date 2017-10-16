.org 0x083A7190
    .word str_pokepad
    .word startmenu_init_pokepad | 1
    .word str_pokemon

//pokeradar
.org 0x0805EC6C
    ldr r0, =pokeradar_map_increment_person_cnt | 1
    bx r0
    .pool

.org 0x0805FDA0
    ldr r2, =pokeradar_npc_get_person_increment_person_cnt | 1
    bx r2
    .pool 

.org 0x080550B4
    ldr r0, =pokeradar_load_additional_person | 1
    bx r0 
    .pool

.org 0x08081AE8
    ldr r1, =pokeradar_alert_pokemon | 1
    bx r1
    .pool

//Pokedex

.org 0x08104D5C
    //push{r4-r7, lr}
    //lsl r0, #0x10
    //lsr r3, r0, #0x10
    //lsl r1, #0x18
    ldr r3, =pokedex_operator | 1
    bx r3
    .pool

.org 0x804313c
	.word pokedex_order

.org 0x80431b0
	.word pokedex_order

.org 0x08088F70
        ldr r1, =pokedex_get_number_seen_or_caught | 1
        bx r1
        .pool

//Fix the wondertrade gb
.org 0x8050c38
	.word gfx_vanilla_gb_tradeTiles

.org 0x8050d2c
	.word gfx_vanilla_gb_tradeTiles

