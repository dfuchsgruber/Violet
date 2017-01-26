#include "types.h"
#include "romfuncs.h"
#include "battle.h"
#include "gfx.h"
#include "attack.h"

battle_bg battle_bgs[29] = {
    // Battle bg 0
    {
        (void*) 0x93c5730,
        (void*) 0x9372c40,
        NULL,
        NULL,
        (void*) 0x9374370
    },
    // Battle bg 1
    {
        (void*) 0x93c4620,
        (void*) 0x9372c40,
        NULL,
        NULL,
        (void*) 0x9372c20
    },
    // Battle bg 2
    {
        (void*) 0x93c68d0,
        (void*) 0x9372c40,
        NULL,
        NULL,
        (void*) 0x9375ecc
    },
    // Battle bg 3
    {
        (void*) 0x93c8410,
        (void*) 0x9372c40,
        NULL,
        NULL,
        (void*) 0x9376b04
    },
    // Battle bg 4
    {
        gfx_battle_bg_cloudsTiles,
        gfx_battle_bg_cloudsMap,
        NULL,
        NULL,
        gfx_battle_bg_cloudsPal
    },
    // Battle bg 5
    {
        (void*) 0x93c9040,
        (void*) 0x9372c40,
        NULL,
        NULL,
        (void*) 0x93775a8
    },
    // Battle bg 6
    {
        (void*) 0x93c9ad0,
        (void*) 0x9372c40,
        NULL,
        NULL,
        (void*) 0x9378188
    },
    // Battle bg 7
    {
        (void*) 0x93cb0d0,
        (void*) 0x9372c40,
        NULL,
        NULL,
        (void*) 0x93c4130
    },
    // Battle bg 8
    {
        (void*) 0x93ca6a0,
        (void*) 0x9372c40,
        NULL,
        NULL,
        (void*) 0x9378bc8
    },
    // Battle bg 9
    {
        (void*) 0x93d59f0,
        (void*) 0x9372c40,
        NULL,
        NULL,
        (void*) 0x93d59c0
    },
    // Battle bg 10
    {
        (void*) 0x93db330,
        (void*) 0x9372c40,
        NULL,
        NULL,
        (void*) 0x93db300
    },
    // Battle bg 11
    {
        gfx_battle_bg_museumTiles,
        gfx_battle_bg_museumMap,
        NULL,
        NULL,
        gfx_battle_bg_museumPal
    },
    // Battle bg 12
    {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },
    // Battle bg 13
    {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },
    // Battle bg 14
    {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },
    // Battle bg 15
    {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },
    // Battle bg 16
    {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },
    // Battle bg 17
    {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    },
    // Battle bg 18
    {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },
    // Battle bg 19
    {
        gfx_battle_bg_fireTiles,
        gfx_battle_bg_fireMap,
        NULL,
        NULL,
        gfx_battle_bg_firePal
    },
    // Battle bg 20
    {
        (void*) 0x8980000,
        (void*) 0x9135000,
        NULL,
        NULL,
        (void*) 0x8a2e060
    },
    // Battle bg 21
    {
        (void*) 0x8976000,
        (void*) 0x890b1ac,
        NULL,
        NULL,
        (void*) 0x8a2e0c0
    },
    // Battle bg 22
    {
        (void*) 0x9020000,
        (void*) 0x890b1ac,
        NULL,
        NULL,
        (void*) 0x8a2e240
    },
    // Battle bg 23
    {
        (void*) 0x9020000,
        (void*) 0x824c828,
        NULL,
        NULL,
        (void*) 0x824c4a8
    },
    // Battle bg 24
    {
        (void*) 0x901ef80,
        (void*) 0x9020888,
        NULL,
        NULL,
        (void*) 0x8a2e2a0
    },
    // Battle bg 25
    {
        (void*) 0x8910454,
        (void*) 0x9020888,
        NULL,
        NULL,
        (void*) 0x8a2e300
    },
    // Battle bg 26
    {
        (void*) 0x8874768,
        (void*) 0x890b1ac,
        NULL,
        NULL,
        (void*) 0x8a2e360
    },
    // Battle bg 27
    {
        (void*) 0x8a2b7e0,
        (void*) 0x890b1ac,
        NULL,
        NULL,
        (void*) 0x8a30fb0
    },
    // Battle bg 28
    {
        (void*) 0x8910454,
        (void*) 0x890b1ac,
        NULL,
        NULL,
        (void*) 0x8a2e300
    }

};

u16 terrain_moves[] = {
    ATTACK_STERNSCHAUER,
    ATTACK_STACHELSPORE,
    ATTACK_STEINHAGEL,
    ATTACK_AQUAWELLE,
    
    0,
    ATTACK_SCHAUFLER,
    ATTACK_SURFER,
    ATTACK_SPUKBALL,
    
    ATTACK_ERDBEBEN,
    ATTACK_HYPERSTRAHL,
    ATTACK_NASSMACHER, //inside cave route4, kaskada
    ATTACK_ANTIK_KRAFT, //museum
    
    0,
    0,
    0,
    0,
    
    0,
    0,
    ATTACK_FLAMMENWURF, //fire route
    0,
    
    0,
    0,
    0,
    0,
    
    0,
    0,
    0,
    0,
    
    0,
    0,
    0,
    0,
    
    0,
    0,
    0,
    0,
    
    0,
    0,
    0,
    0,
    
    0,
    0,
    0,
    0,
};