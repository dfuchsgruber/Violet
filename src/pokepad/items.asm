.global pokepad_items

.align 4
pokepad_items:
    .word items

.align 4
items:
    //Wondertrade
    .word 0x915
    .word str_pokepad_wondertrade
    .word 0 //should be initilaizer func
    .word 0 //should be descr

    .word 0xFFFF
    .word 0
    .word 0
    .word 0
