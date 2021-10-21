#ifndef H_OVERWORLD_UNOWN
#define H_OVERWORLD_UNOWN

#include "save.h"
#include "types.h"

#define UNOWN_MESSAGE_MAX_LEN 6
#define UNOWN_MESSAGE_TAG 0x6555

typedef struct {
    u8 box_idx;
    u8 message_length;
    u8 oams[UNOWN_MESSAGE_MAX_LEN + 1];
} overworld_unown_state_t;

#define OVERWORLD_UNOWN_MESSAGE_STATE ((overworld_unown_state_t *)fmem.gp_state)

#endif
