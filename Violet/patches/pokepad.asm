.org 0x083A7190
    .word str_pokepad
    .word start_menu_pokepad_initialize | 1 //startmenu_init_pokepad | 1
    .word str_pokemon

.org 0x083A71E0
	.word str_pokepad_description

//Pokeradar
.org 0x0805FDB0
    ldr r3, =person_get_by_target_index | 1
    bx r3
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

//Pokedex from battle
.org 0x08106C20
        mov r0, r5
        ldr r1, =pokedex_init_entry_from_battle | 1
        bl bxr1
        pop {r4, r5}
        pop {r1}
bxr1:
        bx r1
        .pool

//Fix the wondertrade gb
.org 0x8050c38
	.word gfx_vanilla_gb_tradeTiles

.org 0x8050d2c
	.word gfx_vanilla_gb_tradeTiles

//Wondertrade names after trade
.org 0x08050E52
    lsl r0, #0
