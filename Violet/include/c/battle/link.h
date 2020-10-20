#ifndef H_BATTLE_LINK
#define H_BATTLE_LINK

#include "types.h"

typedef struct {
    u16 version;
    u16 field_2;
    u32 tid;
    u8 name[11];
    u8 gender;
    u32 link_type;
    u16 battler_idx;
    u16 language;
} link_player_t;

extern link_player_t link_players[5];

#endif