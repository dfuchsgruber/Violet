#ifndef H_POKEMON_TRADE
#define H_POKEMON_TRADE

#include "types.h"
#include "constants/pokemon_stat_names.h"
#include "constants/ingame_trades.h"
#include "pokemon/virtual.h"

typedef struct {
    u8 nickname[11];
    u8 field_11;
    u16 species;
    u8 ivs[6];
    u8 has_custom_moves : 1;
    u8 field_21[3];
    u32 tid;
    u16 moves;
    pid_t pid;
    u16 item;
    u8 mail_idx;
    u8 ot_name[11];
    u8 ot_is_female;
    u8 hidden_ability;
    u16 requested_species;
    u16 field_58;
} ingame_trade_t;

#endif