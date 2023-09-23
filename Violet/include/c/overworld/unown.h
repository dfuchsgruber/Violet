#ifndef H_OVERWORLD_UNOWN
#define H_OVERWORLD_UNOWN

#include "types.h"
#include "save.h"

#define UNOWN_MESSAGE_MAX_LEN 6
#define UNOWN_MESSAGE_TAG 0x6555

typedef struct {
    u8 box_idx;
    u8 message_length;
    u8 oams[UNOWN_MESSAGE_MAX_LEN + 1];
} overworld_unown_state_t;

extern EWRAM overworld_unown_state_t *overworld_unown_state;



#endif