/* -------------------------------------------------------------------------
 * Keccak f[1600] SHA3 Algorithm to create cryto hashes of present codes
 * based on: https://github.com/mjosaarinen/tiny_sha3/blob/master/sha3.c
 * ---------------------------------------------------------------------- */

#include "types.h"
#include "present.h"
#include "agbmemory.h"


// Round constants
u64 keccakf_rndc[24] = {
    0x0000000000000001, 0x0000000000008082, 0x800000000000808a,
    0x8000000080008000, 0x000000000000808b, 0x0000000080000001,
    0x8000000080008081, 0x8000000000008009, 0x000000000000008a,
    0x0000000000000088, 0x0000000080008009, 0x000000008000000a,
    0x000000008000808b, 0x800000000000008b, 0x8000000000008089,
    0x8000000000008003, 0x8000000000008002, 0x8000000000000080,
    0x000000000000800a, 0x800000008000000a, 0x8000000080008081,
    0x8000000000008080, 0x0000000080000001, 0x8000000080008008
};

u8 keccak_f_rotc[] = {
    1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 2, 14, 27, 41, 56, 8, 25, 43, 62,
    18, 39, 61, 20, 44
};


u8 keccakf_piln[24] = {
    10, 7, 11, 17, 18, 3, 5, 16, 8, 21, 24, 4, 15, 23, 19, 13, 12, 2, 20,
    14, 22, 9, 6, 1
};

void sha3_keccak_f_round(u64 a[25], u64 rc){
    u64 c[5];
    u64 d[5];
    
    // Theta Step
    for(int i = 0; i < 5; i++)
        c[i] = a[i] ^ a[i + 5] ^ a[i + 10] ^ a[i + 15] ^ a[i + 20];
    for(int i = 0; i < 5; i++)
        d[i] = c[(i + 4) % 5] + ROT64(c[(i + 1) % 5], 1);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            a[5 * i + j] ^= d[i];
        }
    }
    
    // Rho and pi step
    u64 t = a[1];
    for(int i = 0; i < 24; i++){
        u8 j = keccakf_piln[i];
        u64 tmp = a[j];
        a[j] = ROT64(t, keccak_f_rotc[i]);
        t = tmp;
    }
    
    // Chi step
    for(int j = 0; j < 25; j += 5) {
            for(int i = 0; i < 5; i++)
                c[i] = a[j + i];
            for(int i = 0; i < 5; i++)
                a[j + i] ^= (~c[(i + 1) % 5]) & c[(i + 2) % 5];
    }
    
    // Iota step
    a[0] ^= rc;
}

void sha3_keccak_f(u64 A[25]){
    for(int i = 0; i < KECACK_F_ROUNDS; i++){
        sha3_keccak_f_round(A, keccakf_rndc[i]);
    }
}

void sha3_init(sha3_state *s){
    for(int i = 0; i < 25; i++)
        s->state.dwords[i] = 0;
    s->mdlen = SHA3_MDLEN;
    s->bitrate = 200 - 2 * SHA3_MDLEN;
}

u8 *sha3(u8 *in, u8 *md){
    sha3_state *sha3 = malloc(sizeof(sha3_state));
   
    sha3_init(sha3);
    
    // Feed date into sha3 state
    int j = 0;
    for(int i = 0; i < SHA3_INLEN; i++){
        sha3->state.bytes[j++] ^= in[i];
        if(j >= sha3->bitrate){
            sha3_keccak_f(sha3->state.dwords);
            j = 0;
        }
    }
    
    // Finalize
    sha3->state.bytes[j] ^= 0x6;
    sha3->state.bytes[sha3->bitrate - 1] ^= 0x80;
    sha3_keccak_f(sha3->state.dwords);

    for(int i = 0; i < SHA3_MDLEN; i++)
        md[i] = sha3->state.bytes[i];
    
    free(sha3);
    
    return md;
}
