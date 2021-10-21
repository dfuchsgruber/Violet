#ifndef H_HASH
#define H_HASH

#include "types.h"

/**
 * Hashes any sequence of u32 values.
 * @param seq the sequence to hash
 * @param size the length of the sequence
 * @param seed with which value to seed the hashing
 * @return hash the hash value
 */
u32 hash_sequence(u32 seq[], size_t size, u32 seed);

#endif
