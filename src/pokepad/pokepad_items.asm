.global pokepad_items

.align 4
pokepad_items:
    .word items

.align 4
items:
    //Wondertrade
    .word 0x915
    .word str_pokepad_wondertrade
    .word wondertrade_init //should be initilaizer func
    .word str_pokepad_wondertrade_desc //should be descr
    //Pokedex
    .word 0x829
    .word str_pokepad_pokedex
    .word pokedex_init //should be initilaizer func
    .word str_pokepad_pokedex_desc //should be descr
    //Pokeradar
    .word 0x23c
    .word str_pokepad_pokeradar
    .word pokeradar_init //should be initilaizer func
    .word str_pokepad_pokeradar_desc //should be descr
    
    .word 0xFFFF
    .word 0
    .word 0
    .word 0
