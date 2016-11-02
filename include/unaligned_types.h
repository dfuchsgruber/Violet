#ifndef H_UNALIGNED_TYPES
#define H_UNALIGNED_TYPES
#include "types.h"

// Unaligned word, hword
#define UA_WORD(x) (u8) (((u32) (x)) & 0xFF), (u8) ((((u32) (x)) & 0xFF00) >> 8), (u8) ((((u32) (x)) & 0xFF0000) >> 16), (u8) ((((u32) (x)) & 0xFF000000) >> 24)

#define UA_HWORD(x) (u8) (((u32) (x)) & 0xFF),	\
    (u8) ((((u32) (x)) & 0xFF00) >> 8)
#endif	