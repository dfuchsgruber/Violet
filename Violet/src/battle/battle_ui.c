#include "types.h"
#include "battle/battler.h"
#include "battle/state.h"
#include "oam.h"
#include "pokepad/pokedex/operator.h"
#include "pokemon/virtual.h"
#include "bios.h"
#include "bg.h"
#include "mega.h"
#include "debug.h"


extern const u8 gfx_mega_indicatorTiles[];

bool battle_healthbox_add_mega_indicator(u8 oam_idx) {
    u8 battler_idx = (u8)oams[oam_idx].private[6];
    u8 offset;
    if (battler_is_opponent(battler_idx))
        offset = 0x11;
    else if (battle_is_double()) 
        offset = 0x12;
    else
        offset = 0x1a;
    // u8 healthbar_oam_idx = (u8)oams[oam_idx].private[5];
    u16 tile_num = oams[oam_idx].final_oam.attr2 & 1023;
    mega_evolution_t *mega = mega_evolution_get_by_mega_species(battlers[battler_idx].species);
    if (mega) {
        switch (mega->type) {
            case MEGA_EVOLUTION: {
                dprintf("Print mega indicator to tile %d\n", tile_num);
                cpuset(gfx_mega_indicatorTiles + 0 * GRAPHIC_SIZE_4BPP(16, 8), OAMCHARBASE(tile_num + offset), CPUSET_COPY | CPUSET_WORD | CPUSET_WORD_SIZE(GRAPHIC_SIZE_4BPP(16, 8)));
                return true;
                break;
            }
            case REGENT_EVOLUTION: {
                dprintf("Print regent to tile %d\n", tile_num);
                cpuset(gfx_mega_indicatorTiles + 1 * GRAPHIC_SIZE_4BPP(16, 8), OAMCHARBASE(tile_num + offset), CPUSET_COPY | CPUSET_WORD | CPUSET_WORD_SIZE(GRAPHIC_SIZE_4BPP(16, 8)));
                return true;
                break;
            }
        }
    }
    return false;
}

void battle_healthbox_add_pokeball_and_mega_indicator(u8 oam_idx, bool has_no_status_aliment) {
    if (has_no_status_aliment) {
        if (battle_healthbox_add_mega_indicator(oam_idx))  // The mega indicator overrides the caught icon
            return;
    }
    if (battle_flags & (BATTLE_OAK | BATTLE_TUTORIAL | 0x10000))
        return;
    if (battle_flags & BATTLE_TRAINER)
        return;
    
    u8 battler_idx = (u8)oams[oam_idx].private[6];
    if (!battler_is_opponent(battler_idx))
        return;
    // Omit the BATTLE_GHOST_CHECK
    u8 first, last;
    pokemon *party = battler_load_party_range(battler_idx, &first, &last);

    if (!pokedex_operator((u16)pokemon_get_attribute(party + battler_idx_to_party_idx(battler_idx), ATTRIBUTE_SPECIES, NULL), POKEDEX_CAUGHT, true))
        return;
    u8 healthbar_oam_idx = (u8)oams[oam_idx].private[5];
    u16 tile_num = oams[healthbar_oam_idx].final_oam.attr2 & 1023;
    if (has_no_status_aliment) {
        cpuset(battle_healthbox_get_gfx(0x46), OAMCHARBASE(tile_num + 8), CPUSET_COPY | CPUSET_WORD | CPUSET_WORD_SIZE(32));
    } else {
        int zero = 0;
        cpuset(&zero, OAMCHARBASE(tile_num + 8), CPUSET_FILL | CPUSET_WORD | CPUSET_WORD_SIZE(32));
    }

}