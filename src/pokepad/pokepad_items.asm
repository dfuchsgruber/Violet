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
    //Wondertrade
    .word 0x915
    .word str_pokepad_wondertrade
    .word leak_test + 1 //should be initilaizer func
    .word str_pokepad_wondertrade //should be descr
    //Wondertrade
    .word 0x915
    .word str_pokepad_wondertrade
    .word 0 //should be initilaizer func
    .word str_pokepad_wondertrade_desc //should be descr
//Wondertrade
    .word 0x915
    .word str_pokepad_wondertrade
    .word 0 //should be initilaizer func
    .word str_pokepad_wondertrade_desc //should be descr
    //Wondertrade
    .word 0x915
    .word str_pokepad_wondertrade
    .word 0 //should be initilaizer func
    .word str_pokepad_wondertrade_desc //should be descr
    //Wondertrade
    .word 0x915
    .word str_pokepad_wondertrade
    .word 0 //should be initilaizer func
    .word str_pokepad_wondertrade_desc //should be descr

    .word 0xFFFF
    .word 0
    .word 0
    .word 0
