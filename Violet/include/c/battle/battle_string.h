#ifndef H_BATTLE_BATTLESTRING
#define H_BATTLE_BATTLESTRING

#include "types.h"


// These three battle buffers can be decrypted with the FD XX commands
// The buffer 

#define BSC_BUFFER_DISPLAY_STRING 0
#define BSC_BUFFER_DISPLAY_NUMBER 1
#define BSC_BUFFER_DISPLAY_MOVE 2
#define BSC_BUFFER_DISPLAY_TYPE 3
#define BSC_BUFFER_DISPLAY_BATTLER_NICKNAME_WITH_PREFIX 4
#define BSC_BUFFER_DISPLAY_STAT 5
#define BSC_BUFFER_DISPLAY_SPECIES 6
#define BSC_BUFFER_BATTLER_NICKNAME 7
#define BSC_BUFFER_DISPLAY_NEGATIVE_FLAVOR 8
#define BSC_BUFFER_DISPLAY_ABILITY 9
#define BSC_BUFFER_DISPLAY_ITEM 10

#define BSC_BUFFER_BEGIN 0xFD
#define BSC_BUFFER_EOS 0xFF

extern u8 bsc_string_buffer0[16];
extern u8 bsc_string_buffer1[16];
extern u8 bsc_string_buffer2[16];


/**
 * Decrypts one of the three battle buffers.
 * @param src which buffer to decrypt
 * @param dst where to write the decrypted string to
 **/
void battle_buffer_decrypt(u8 *src, u8 *dst);


#define BSC_BUFFER_SPECIES(buffer, species) \
{ \
    buffer[0] = BSC_BUFFER_BEGIN; \
    buffer[1] = BSC_BUFFER_DISPLAY_SPECIES; \
    buffer[2] = (u8)species; \
    buffer[3] = (u8)(species >> 8); \
    buffer[4] = BSC_BUFFER_EOS; \
}

#define BSC_BUFFER_ITEM(buffer, item) \
{ \
    buffer[0] = BSC_BUFFER_BEGIN; \
    buffer[1] = BSC_BUFFER_DISPLAY_ITEM; \
    buffer[2] = (u8)item; \
    buffer[3] = (u8)(item >> 8); \
    buffer[4] = BSC_BUFFER_EOS; \
}

#define BSC_BUFFER_BATTLER_NICKNAME_WITH_PREFIX(buffer, battler_idx, party_idx) \
{ \
    buffer[0] = BSC_BUFFER_BEGIN; \
    buffer[1] = BSC_BUFFER_DISPLAY_BATTLER_NICKNAME_WITH_PREFIX; \
    buffer[2] = battler_idx; \
    buffer[3] = party_idx; \
    buffer[4] = BSC_BUFFER_EOS; \
}

#define BSC_BUFFER_TYPE(buffer, type) \
{ \
    buffer[0] = BSC_BUFFER_BEGIN; \
    buffer[1] = BSC_BUFFER_DISPLAY_TYPE; \
    buffer[2] = type; \
    buffer[3] = BSC_BUFFER_EOS; \
}

#endif