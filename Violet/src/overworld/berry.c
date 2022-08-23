#include "types.h"
#include "save.h"
#include "berry.h"
#include "debug.h"
#include "agbmemory.h"
#include "vars.h"
#include "overworld/sprite.h"
#include "item/item.h"
#include "prng.h"
#include "constants/berry_pouch_contexts.h"
#include "callbacks.h"
#include "overworld/map_control.h"
#include "fading.h"
#include "overworld/pokemon_party_menu.h"
#include "rtc.h"
#include "overworld/effect.h"
#include "constants/sav_keys.h"
#include "options.h"
#include "item/bag2.h"
#include "language.h"

berry berries[] = {
    [ITEM_IDX_TO_BERRY_IDX(ITEM_AMRENABEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Amrena"), PSTRING("Cheri")),
        .firmness = 2, .size = 20,
        .max_yield = 3, .min_yield = 2, .stage_duration = 3,
        .spicy = 10, .dry = 0, .sweet = 0,
        .bitter = 0, .sour = 0, .smoothness = 25,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_MARONBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Maron"), PSTRING("Chesto")),
        .firmness = 5, .size = 80,
        .max_yield = 3, .min_yield = 2, .stage_duration = 3,
        .spicy = 0, .dry = 10, .sweet = 0,
        .bitter = 0, .sour = 0, .smoothness = 25,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_PIRSIFBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Pirsif"), PSTRING("Pecha")),
        .firmness = 1, .size = 40,
        .max_yield = 3, .min_yield = 2, .stage_duration = 3,
        .spicy = 0, .dry = 0, .sweet = 10,
        .bitter = 0, .sour = 0, .smoothness = 25,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_FRAGIABEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Fragia"), PSTRING("Rawst")),
        .firmness = 3, .size = 32,
        .max_yield = 3, .min_yield = 2, .stage_duration = 3,
        .spicy = 0, .dry = 0, .sweet = 0,
        .bitter = 10, .sour = 0, .smoothness = 25,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_WILBIRBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Wilbir"), PSTRING("Aspear")),
        .firmness = 5, .size = 50,
        .max_yield = 3, .min_yield = 2, .stage_duration = 3,
        .spicy = 0, .dry = 0, .sweet = 0,
        .bitter = 0, .sour = 10, .smoothness = 25,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_JONAGOBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Jonago"), PSTRING("Leppa")),
        .firmness = 4, .size = 28,
        .max_yield = 3, .min_yield = 2, .stage_duration = 4,
        .spicy = 10, .dry = 0, .sweet = 10,
        .bitter = 10, .sour = 10, .smoothness = 20,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_SINELBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Sinel"), PSTRING("Oran")),
        .firmness = 5, .size = 35,
        .max_yield = 3, .min_yield = 2, .stage_duration = 3,
        .spicy = 10, .dry = 10, .sweet = 10,
        .bitter = 10, .sour = 10, .smoothness = 20,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_PERSIMBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Persim"), PSTRING("Persim")),
        .firmness = 3, .size = 47,
        .max_yield = 3, .min_yield = 2, .stage_duration = 3,
        .spicy = 10, .dry = 10, .sweet = 10,
        .bitter = 10, .sour = 10, .smoothness = 20,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_PRUNUSBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Prunus"), PSTRING("Lum")),
        .firmness = 5, .size = 34,
        .max_yield = 2, .min_yield = 1, .stage_duration = 12,
        .spicy = 10, .dry = 10, .sweet = 10,
        .bitter = 10, .sour = 10, .smoothness = 20,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_TSITRUBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Tsitru"), PSTRING("Sitrus")),
        .firmness = 4, .size = 95,
        .max_yield = 3, .min_yield = 2, .stage_duration = 6,
        .spicy = 10, .dry = 10, .sweet = 10,
        .bitter = 10, .sour = 10, .smoothness = 20,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_GIEFEBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Giefe"), PSTRING("Figy")),
        .firmness = 2, .size = 100,
        .max_yield = 3, .min_yield = 2, .stage_duration = 6,
        .spicy = 10, .dry = 0, .sweet = 0,
        .bitter = 0, .sour = 0, .smoothness = 25,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_WIKIBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Wiki"), PSTRING("Wiki")),
        .firmness = 3, .size = 115,
        .max_yield = 3, .min_yield = 2, .stage_duration = 6,
        .spicy = 0, .dry = 10, .sweet = 0,
        .bitter = 0, .sour = 0, .smoothness = 25,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_MAGOBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Mago"), PSTRING("Mago")),
        .firmness = 3, .size = 126,
        .max_yield = 3, .min_yield = 2, .stage_duration = 6,
        .spicy = 0, .dry = 0, .sweet = 10,
        .bitter = 0, .sour = 0, .smoothness = 25,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_GAUVEBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Gauve"), PSTRING("Aguav")),
        .firmness = 5, .size = 64,
        .max_yield = 3, .min_yield = 2, .stage_duration = 6,
        .spicy = 0, .dry = 0, .sweet = 0,
        .bitter = 10, .sour = 0, .smoothness = 25,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_YAPABEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Yapa"), PSTRING("Iapapa")),
        .firmness = 2, .size = 223,
        .max_yield = 3, .min_yield = 2, .stage_duration = 6,
        .spicy = 0, .dry = 0, .sweet = 0,
        .bitter = 0, .sour = 10, .smoothness = 25,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_HIMMIHBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Himmih"), PSTRING("Razz")),
        .firmness = 4, .size = 120,
        .max_yield = 6, .min_yield = 3, .stage_duration = 1,
        .spicy = 10, .dry = 10, .sweet = 0,
        .bitter = 0, .sour = 0, .smoothness = 20,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_MORBBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Morb"), PSTRING("Bluk")),
        .firmness = 2, .size = 108,
        .max_yield = 6, .min_yield = 3, .stage_duration = 1,
        .spicy = 0, .dry = 10, .sweet = 10,
        .bitter = 0, .sour = 0, .smoothness = 20,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_NANABBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Nanab"), PSTRING("Nanab")),
        .firmness = 4, .size = 77,
        .max_yield = 6, .min_yield = 3, .stage_duration = 1,
        .spicy = 0, .dry = 0, .sweet = 10,
        .bitter = 10, .sour = 0, .smoothness = 20,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_NIRBEBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Nirbe"), PSTRING("Wepear")),
        .firmness = 5, .size = 74,
        .max_yield = 6, .min_yield = 3, .stage_duration = 1,
        .spicy = 0, .dry = 0, .sweet = 0,
        .bitter = 10, .sour = 10, .smoothness = 20,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_SANANABEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Sanana"), PSTRING("Pinap")),
        .firmness = 3, .size = 80,
        .max_yield = 6, .min_yield = 3, .stage_duration = 1,
        .spicy = 10, .dry = 0, .sweet = 0,
        .bitter = 0, .sour = 10, .smoothness = 20,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_GRANABEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Grana"), PSTRING("Pomeg")),
        .firmness = 4, .size = 135,
        .max_yield = 6, .min_yield = 2, .stage_duration = 3,
        .spicy = 10, .dry = 0, .sweet = 10,
        .bitter = 10, .sour = 0, .smoothness = 20,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_SETANGBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Setang"), PSTRING("Kelpsy")),
        .firmness = 3, .size = 150,
        .max_yield = 6, .min_yield = 2, .stage_duration = 3,
        .spicy = 0, .dry = 10, .sweet = 0,
        .bitter = 10, .sour = 10, .smoothness = 20,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_QUALOTBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Qualot"), PSTRING("Qualot")),
        .firmness = 3, .size = 110,
        .max_yield = 6, .min_yield = 2, .stage_duration = 3,
        .spicy = 10, .dry = 0, .sweet = 10,
        .bitter = 0, .sour = 10, .smoothness = 20,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_HONMELBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Honmel"), PSTRING("Hondew")),
        .firmness = 3, .size = 162,
        .max_yield = 6, .min_yield = 2, .stage_duration = 3,
        .spicy = 10, .dry = 10, .sweet = 0,
        .bitter = 10, .sour = 0, .smoothness = 20,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_LABRUSBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Labrus"), PSTRING("Grepa")),
        .firmness = 2, .size = 149,
        .max_yield = 6, .min_yield = 2, .stage_duration = 3,
        .spicy = 0, .dry = 10, .sweet = 10,
        .bitter = 0, .sour = 10, .smoothness = 20,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_TAMOTBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Tamot"), PSTRING("Tamato")),
        .firmness = 2, .size = 200,
        .max_yield = 4, .min_yield = 2, .stage_duration = 6,
        .spicy = 20, .dry = 10, .sweet = 0,
        .bitter = 0, .sour = 0, .smoothness = 30,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_SAIMBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Saim"), PSTRING("Cornn")),
        .firmness = 3, .size = 75,
        .max_yield = 4, .min_yield = 2, .stage_duration = 6,
        .spicy = 0, .dry = 20, .sweet = 10,
        .bitter = 0, .sour = 0, .smoothness = 30,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_MAGOSTBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Magost"), PSTRING("Magost")),
        .firmness = 3, .size = 140,
        .max_yield = 4, .min_yield = 2, .stage_duration = 6,
        .spicy = 0, .dry = 0, .sweet = 20,
        .bitter = 10, .sour = 0, .smoothness = 30,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_RABUTABEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Rabuta"), PSTRING("Rabuta")),
        .firmness = 2, .size = 226,
        .max_yield = 4, .min_yield = 2, .stage_duration = 6,
        .spicy = 0, .dry = 0, .sweet = 0,
        .bitter = 20, .sour = 10, .smoothness = 30,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_TRONZIBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Tronzi"), PSTRING("Nomel")),
        .firmness = 5, .size = 285,
        .max_yield = 4, .min_yield = 2, .stage_duration = 6,
        .spicy = 10, .dry = 0, .sweet = 0,
        .bitter = 0, .sour = 20, .smoothness = 30,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_KIWANBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Kiwan"), PSTRING("Spelon")),
        .firmness = 2, .size = 133,
        .max_yield = 2, .min_yield = 1, .stage_duration = 18,
        .spicy = 40, .dry = 10, .sweet = 0,
        .bitter = 0, .sour = 0, .smoothness = 70,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_PALLMBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Pallm"), PSTRING("Pamtre")),
        .firmness = 1, .size = 244,
        .max_yield = 2, .min_yield = 1, .stage_duration = 18,
        .spicy = 0, .dry = 40, .sweet = 10,
        .bitter = 0, .sour = 0, .smoothness = 70,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_WASMELBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Wasmel"), PSTRING("Watmel")),
        .firmness = 2, .size = 250,
        .max_yield = 2, .min_yield = 1, .stage_duration = 18,
        .spicy = 0, .dry = 0, .sweet = 40,
        .bitter = 10, .sour = 0, .smoothness = 70,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_UNBEKANNTER_SAMEN) - 1]  = {
        .name = LANGDEP(PSTRING("Samen"), PSTRING("Samen")),
        .firmness = 3, .size = 280,
        .max_yield = 2, .min_yield = 1, .stage_duration = 7,
        .spicy = 0, .dry = 0, .sweet = 0,
        .bitter = 40, .sour = 10, .smoothness = 70,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_ANTIKER_SAMEN) - 1]  = {
        .name = LANGDEP(PSTRING("Samen"), PSTRING("Samen")),
        .firmness = 1, .size = 300,
        .max_yield = 1, .min_yield = 1, .stage_duration = 60,
        .spicy = 5, .dry = 5, .sweet = 5,
        .bitter = 5, .sour = 5, .smoothness = 70,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_LYDZIBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Lydzi"), PSTRING("Liechi")),
        .firmness = 4, .size = 111,
        .max_yield = 2, .min_yield = 1, .stage_duration = 24,
        .spicy = 40, .dry = 0, .sweet = 40,
        .bitter = 0, .sour = 10, .smoothness = 80,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_LINGANBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Lingan"), PSTRING("Ganlon")),
        .firmness = 4, .size = 33,
        .max_yield = 2, .min_yield = 1, .stage_duration = 24,
        .spicy = 0, .dry = 40, .sweet = 0,
        .bitter = 40, .sour = 0, .smoothness = 80,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_SALKABEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Salka"), PSTRING("Salac")),
        .firmness = 4, .size = 95,
        .max_yield = 2, .min_yield = 1, .stage_duration = 24,
        .spicy = 0, .dry = 0, .sweet = 40,
        .bitter = 0, .sour = 40, .smoothness = 80,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_TAHAYBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Tahay"), PSTRING("Petaya")),
        .firmness = 4, .size = 237,
        .max_yield = 2, .min_yield = 1, .stage_duration = 24,
        .spicy = 40, .dry = 0, .sweet = 0,
        .bitter = 40, .sour = 0, .smoothness = 80,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_APIKOBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Apiko"), PSTRING("Apicot")),
        .firmness = 3, .size = 75,
        .max_yield = 2, .min_yield = 1, .stage_duration = 24,
        .spicy = 0, .dry = 40, .sweet = 0,
        .bitter = 0, .sour = 40, .smoothness = 80,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_LANSATBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Lansat"), PSTRING("Lansat")),
        .firmness = 2, .size = 97,
        .max_yield = 2, .min_yield = 1, .stage_duration = 24,
        .spicy = 10, .dry = 10, .sweet = 10,
        .bitter = 10, .sour = 10, .smoothness = 30,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_KRAMBOBEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Krambo"), PSTRING("Starf")),
        .firmness = 5, .size = 153,
        .max_yield = 2, .min_yield = 1, .stage_duration = 24,
        .spicy = 10, .dry = 10, .sweet = 10,
        .bitter = 10, .sour = 10, .smoothness = 30,
    },
    [ITEM_IDX_TO_BERRY_IDX(ITEM_ENIGMABEERE) - 1]  = {
        .name = LANGDEP(PSTRING("Enigma"), PSTRING("Enigma")),
        .firmness = 0, .size = 0,
        .max_yield = 2, .min_yield = 1, .stage_duration = 24,
        .spicy = 40, .dry = 40, .sweet = 40,
        .bitter = 40, .sour = 40, .smoothness = 40,
    },
};

u8 berry_tree_get_berry(u8 berry_tree_idx) {
    return cmem.berry_trees[berry_tree_idx].berry;
}

u8 berry_tree_initial_items[NUM_BERRY_TREES] = {
    [0] = ITEM_IDX_TO_BERRY_IDX(ITEM_SAIMBEERE),
    [1] = ITEM_IDX_TO_BERRY_IDX(ITEM_SAIMBEERE),
    [2] = ITEM_IDX_TO_BERRY_IDX(ITEM_SINELBEERE),
    [3] = ITEM_IDX_TO_BERRY_IDX(ITEM_PIRSIFBEERE),
    [4] = ITEM_IDX_TO_BERRY_IDX(ITEM_MORBBEERE),
    [5] = ITEM_IDX_TO_BERRY_IDX(ITEM_AMRENABEERE),
    [6] = ITEM_IDX_TO_BERRY_IDX(ITEM_MORBBEERE),
    [7] = ITEM_IDX_TO_BERRY_IDX(ITEM_MARONBEERE),
    [8] = ITEM_IDX_TO_BERRY_IDX(ITEM_FRAGIABEERE),
    [9] = ITEM_IDX_TO_BERRY_IDX(ITEM_PERSIMBEERE),
    [10] = ITEM_IDX_TO_BERRY_IDX(ITEM_GIEFEBEERE),
    [11] = ITEM_IDX_TO_BERRY_IDX(ITEM_WIKIBEERE),
    [12] = ITEM_IDX_TO_BERRY_IDX(ITEM_MAGOBEERE),
    [13] = ITEM_IDX_TO_BERRY_IDX(ITEM_PIRSIFBEERE),
    [14] = ITEM_IDX_TO_BERRY_IDX(ITEM_SINELBEERE),
    [15] = ITEM_IDX_TO_BERRY_IDX(ITEM_MAGOSTBEERE),
    [16] = ITEM_IDX_TO_BERRY_IDX(ITEM_PIRSIFBEERE),
    [17] = ITEM_IDX_TO_BERRY_IDX(ITEM_MARONBEERE),
    [18] = ITEM_IDX_TO_BERRY_IDX(ITEM_LINGANBEERE),
    [19] = ITEM_IDX_TO_BERRY_IDX(ITEM_MAGOSTBEERE),
    [20] = ITEM_IDX_TO_BERRY_IDX(ITEM_JONAGOBEERE),
    [21] = ITEM_IDX_TO_BERRY_IDX(ITEM_SANANABEERE),
    [22] = ITEM_IDX_TO_BERRY_IDX(ITEM_MAGOBEERE),
    [23] = ITEM_IDX_TO_BERRY_IDX(ITEM_SANANABEERE),
    [24] = ITEM_IDX_TO_BERRY_IDX(ITEM_GRANABEERE), 
    [25] = ITEM_IDX_TO_BERRY_IDX(ITEM_YAPABEERE),
    [26] = ITEM_IDX_TO_BERRY_IDX(ITEM_HIMMIHBEERE),
    [27] = ITEM_IDX_TO_BERRY_IDX(ITEM_AMRENABEERE),
    [28] = ITEM_IDX_TO_BERRY_IDX(ITEM_SETANGBEERE),
    [29] = ITEM_IDX_TO_BERRY_IDX(ITEM_LYDZIBEERE),
    [30] = ITEM_IDX_TO_BERRY_IDX(ITEM_LYDZIBEERE),
    [31] = ITEM_IDX_TO_BERRY_IDX(ITEM_GAUVEBEERE),
    [32] = ITEM_IDX_TO_BERRY_IDX(ITEM_FRAGIABEERE),
    [33] = ITEM_IDX_TO_BERRY_IDX(ITEM_AMRENABEERE),
    [34] = ITEM_IDX_TO_BERRY_IDX(ITEM_MARONBEERE),
    [35] = ITEM_IDX_TO_BERRY_IDX(ITEM_NANABBEERE),
    [36] = ITEM_IDX_TO_BERRY_IDX(ITEM_NANABBEERE),
    [37] = ITEM_IDX_TO_BERRY_IDX(ITEM_MARONBEERE),
    [38] = ITEM_IDX_TO_BERRY_IDX(ITEM_AMRENABEERE),
    [39] = ITEM_IDX_TO_BERRY_IDX(ITEM_SALKABEERE),
    [40] = ITEM_IDX_TO_BERRY_IDX(ITEM_SINELBEERE),
    [41] = ITEM_IDX_TO_BERRY_IDX(ITEM_TSITRUBEERE),
    [42] = ITEM_IDX_TO_BERRY_IDX(ITEM_TAHAYBEERE),
    [43] = ITEM_IDX_TO_BERRY_IDX(ITEM_RABUTABEERE),
    [44] = ITEM_IDX_TO_BERRY_IDX(ITEM_AMRENABEERE),
    [45] = ITEM_IDX_TO_BERRY_IDX(ITEM_FRAGIABEERE),
    [46] = ITEM_IDX_TO_BERRY_IDX(ITEM_TAMOTBEERE),
    [47] = ITEM_IDX_TO_BERRY_IDX(ITEM_SINELBEERE),
    [48] = ITEM_IDX_TO_BERRY_IDX(ITEM_MARONBEERE),
    [49] = ITEM_IDX_TO_BERRY_IDX(ITEM_WILBIRBEERE),
    [50] = ITEM_IDX_TO_BERRY_IDX(ITEM_APIKOBEERE),
    [51] = ITEM_IDX_TO_BERRY_IDX(ITEM_SINELBEERE),
    [52] = ITEM_IDX_TO_BERRY_IDX(ITEM_PERSIMBEERE),
    [53] = ITEM_IDX_TO_BERRY_IDX(ITEM_AMRENABEERE),
    [54] = ITEM_IDX_TO_BERRY_IDX(ITEM_GIEFEBEERE),
    [55] = ITEM_IDX_TO_BERRY_IDX(ITEM_YAPABEERE),
    [56] = ITEM_IDX_TO_BERRY_IDX(ITEM_FRAGIABEERE),
    [57] = ITEM_IDX_TO_BERRY_IDX(ITEM_AMRENABEERE),
};


int berry_get_adjacent_berries_of_different_kind(u8 berry_tree_idx) {
    u16 berry_idx = cmem.berry_trees[berry_tree_idx].berry;
    int num = 0;
    for (size_t i = 0; i < berry_tree_adjacency[berry_tree_idx].count; i++) {
        u8 other = berry_tree_adjacency[berry_tree_idx].adjacent_berry_tree_idxs[i];
        if (cmem.berry_trees[other].stage != BERRY_STAGE_NO_BERRY && cmem.berry_trees[other].berry != berry_idx)
            num++;
    }
    DEBUG("Berry tree %d with berry %d has %d different type berry tree neighbours\n", berry_tree_idx, berry_idx, num);
    return num;
}

void berry_tree_calculate_yield(u8 berry_tree_idx) {
    u8 berry_idx = cmem.berry_trees[berry_tree_idx].berry;
    berry *b = berry_get(berry_idx);
    if (berry_idx == ITEM_IDX_TO_BERRY_IDX(ITEM_ANTIKER_SAMEN)) {
        cmem.berry_trees[berry_tree_idx].yield = 1; // The lotus flower always only yields one new seed
        // A flower is yielded with a 1/2 chance and increased by 1/4 for fertiziling and growing berries close of different type
        int odds = 2 + 
            (cmem.berry_trees[berry_tree_idx].fertilized ? 1 : 0) + 
            (berry_get_adjacent_berries_of_different_kind(berry_tree_idx) > 0 ? 1 : 0);
        cmem.berry_trees[berry_tree_idx].yields_flower = (rnd16() & 3) < odds;
        DEBUG("Odds are %d, yields %d\n", odds, cmem.berry_trees[berry_tree_idx].yields_flower);
    } else {  
        int yield = (rnd16() % (b->max_yield - b->min_yield + 1)) + b->min_yield;
        // Additional yield for planting many berries
        int num_berries_planted = save_get_key(SAV_KEY_PLANTED_BERRIES);
        if ((rnd16() % 100) < num_berries_planted) {
            yield++;
            if (rnd16() % 3 < berry_get_adjacent_berries_of_different_kind(berry_tree_idx)) {
                yield += MAX(1, yield / 2); 
            }
        }
        DEBUG("Unfertilized yield is %d\n", yield);
        if (cmem.berry_trees[berry_tree_idx].fertilized) {
            yield += MAX(1, yield / 2);
            DEBUG("Fertilized yield is %d\n", yield);
        }
        yield = MIN(7, yield);
        cmem.berry_trees[berry_tree_idx].yield = (u8)(yield & 7);
        cmem.berry_trees[berry_tree_idx].yields_flower = false;
        // DEBUG("Initialized berry tree %d with yield %d\n", berry_tree_idx, yield);
    }
}

u16 berry_get_stage_duration(u8 berry_tree_idx) {
    berry *b = berry_get(cmem.berry_trees[berry_tree_idx].berry);
    int factor;
    switch (berry_get_adjacent_berries_of_different_kind(berry_tree_idx)) {
        case 0:
            factor = 12;
            break;
        case 1:
            factor = 8;
            break;
        default:
            factor = 6;
            break;
    }
    return (u16)(b->stage_duration * factor); // Where as in the original game the unit of stage duration would be hours, we simply make a stage 6 times faster (`factor` minutes)
}

void berry_tree_initialize(u8 berry_tree_idx, u8 berry_idx, u8 stage) {
    cmem.berry_trees[berry_tree_idx].berry = (u8)(berry_idx & 63);
    cmem.berry_trees[berry_tree_idx].stage = (u8)(stage & 7);
    berry *b = berry_get(cmem.berry_trees[berry_tree_idx].berry);
    cmem.berry_trees[berry_tree_idx].yield = (u8)(b->min_yield & 7);
    // cmem.berry_trees[berry_tree_idx].yield = 0; // Only when blossoming, the yield is determined
    cmem.berry_trees[berry_tree_idx].minutes_to_next_stage = berry_get_stage_duration(berry_tree_idx);
}


void berry_trees_initialize_all() {
    memset(cmem.berry_trees, 0, sizeof(cmem.berry_trees));
    for (size_t i = 0; i < ARRAY_COUNT(berry_tree_initial_items); i++) {
        u8 berry_idx = berry_tree_initial_items[i];
        if (berry_idx > 0)
            berry_tree_initialize((u8)i, berry_idx, BERRY_STAGE_BERRIES);
        else
            berry_tree_initialize((u8)i, 1, BERRY_STAGE_NO_BERRY);
    }
}

u16 berry_tree_get_stage() {
    return cmem.berry_trees[*var_access(0x8000)].stage;
}

u16 berry_tree_get_item() {
    return (u16)BERRY_IDX_TO_ITEM_IDX(cmem.berry_trees[*var_access(0x8000)].berry);
}

u16 berry_tree_get_yield() {
    return cmem.berry_trees[*var_access(0x8000)].yield;
}

void berry_tree_update_gfx() {
    u8 person_idx = (u8)(*var_access(LASTTALKED));
    u8 npc_idx = npc_get_by_person_idx(person_idx, save1->map, save1->bank);
    DEBUG("Berry update, npc idx %d for person %d\n", npc_idx, person_idx);
    if (npc_idx < 16) {
        u8 oam_idx = npcs[npc_idx].oam_id;
        npcs[npc_idx].flags.active = 0; // Temporarily disable the npc such that the pal can be released
        u8 pal_idx_old = (u8)((oams[oam_idx].final_oam.attr2 >> 12) & 15);
        npc_free_palette_if_unused_by_slot(pal_idx_old);
        npcs[npc_idx].flags.active = 1; // Set the npc to active again
        overworld_npc_update_palette(npcs + npc_idx, oams + oam_idx);
        overworld_sprite *ow = overworld_get_by_npc(npcs + npc_idx);
        DEBUG("Updated overworld sprite %d with @0x%x\n", person_idx, ow);
        oams[oam_idx].gfx_table = ow->graphics;
        oam_gfx_anim_start(oams + oam_idx, 0);
    }
}

bool berry_pick() {
    u16 item_idx = (u16)(BERRY_IDX_TO_ITEM_IDX(cmem.berry_trees[*var_access(0x8000)].berry));
    u8 count = cmem.berry_trees[*var_access(0x8000)].yield;
    DEBUG("Picked %d times %d\n", count, item_idx);
    if (!item_has_room(item_idx, count))
        return false;
    item_add(item_idx, count);
    cmem.berry_trees[*var_access(0x8000)].picked_once = true;
    cmem.berry_trees[*var_access(0x8000)].stage = BERRY_STAGE_NO_BERRY;
    cmem.berry_trees[*var_access(0x8000)].fertilized = false;
    return true;
}

bool berry_is_fertilized() {
    return cmem.berry_trees[*var_access(0x8000)].fertilized;
}

u16 berry_yields_flower() {
    DEBUG("Berry tree %d yields flower %d\n", *var_access(0x8000), cmem.berry_trees[*var_access(0x8000)].yields_flower);
    return cmem.berry_trees[*var_access(0x8000)].yields_flower;
}

void berry_fertilize() {
    cmem.berry_trees[*var_access(0x8000)].fertilized = true;
}

void berry_plant_callback_initialize_berry_pouch(u8 self) {
    if (!fading_control.active) {
        // berry_pouch_initialize(BERRY_POUCH_CONTEXT_PLANTING, map_reload, 0);
        bag_open(BAG_CONTEXT_PLANT_BERRY, BAG_OPEN_BERRIES, map_reload);
        big_callback_delete(self);
    }
}

void berry_plant() {
    *var_access(LASTRESULT) = 0; // No berry planted
    big_callback_new(berry_plant_callback_initialize_berry_pouch, 0);
    fadescreen_all(1, 0);
}

static u32 unknown_seed_probabilities[] = {
    [ITEM_IDX_TO_BERRY_IDX(ITEM_AMRENABEERE)] = 7,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_MARONBEERE)] = 7,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_PIRSIFBEERE)] = 7,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_FRAGIABEERE)] = 7,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_WILBIRBEERE)] = 7,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_JONAGOBEERE)] = 4,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_SINELBEERE)] = 7,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_PERSIMBEERE)] = 7,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_PRUNUSBEERE)] = 1,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_TSITRUBEERE)] = 5,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_GIEFEBEERE)] = 5,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_WIKIBEERE)] = 5,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_MAGOBEERE)] = 5,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_GAUVEBEERE)] = 5,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_YAPABEERE)] = 5,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_HIMMIHBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_MORBBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_NANABBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_NIRBEBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_SANANABEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_GRANABEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_SETANGBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_QUALOTBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_HONMELBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_LABRUSBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_TAMOTBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_SAIMBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_MAGOSTBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_RABUTABEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_TRONZIBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_KIWANBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_PALLMBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_WASMELBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_LYDZIBEERE)] = 2,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_LINGANBEERE)] = 2,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_SALKABEERE)] = 2,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_TAHAYBEERE)] = 2,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_APIKOBEERE)] = 2,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_LANSATBEERE)] = 2,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_KRAMBOBEERE)] = 1,
};

static void berry_tree_unknown_seed_randomize_berry(u8 berry_tree_idx) {
    size_t idx = choice(unknown_seed_probabilities, ARRAY_COUNT(unknown_seed_probabilities), NULL);
    cmem.berry_trees[berry_tree_idx].berry = (u8)(idx & 63);
}

bool berry_tree_grow(u8 berry_tree_idx, size_t minutes) {
    berry_tree *tree = cmem.berry_trees + berry_tree_idx;
    if (tree->stage == BERRY_STAGE_NO_BERRY || tree->stage == BERRY_STAGE_BERRIES)
        return false;
    while(minutes > 0) {
        if (tree->minutes_to_next_stage <= minutes) {
            minutes -= tree->minutes_to_next_stage;
            if (tree->stage == BERRY_STAGE_DIRT_PILE && tree->berry == ITEM_IDX_TO_BERRY_IDX(ITEM_UNBEKANNTER_SAMEN)) 
                berry_tree_unknown_seed_randomize_berry(berry_tree_idx); // The unknown seed grows into a random plant
            if (tree->stage == BERRY_STAGE_BLOSSOM)
                berry_tree_calculate_yield(berry_tree_idx);
            tree->stage++;
            if (tree->stage == BERRY_STAGE_BERRIES)
                break;
            tree->minutes_to_next_stage = berry_get_stage_duration(berry_tree_idx);
        } else {
            tree->minutes_to_next_stage = (u16)(tree->minutes_to_next_stage - minutes);
            minutes = 0;
            break;
        }
    }
    return true;
}

bool special_berry_tree_grow() {
    return berry_tree_grow((u8)*var_access(0x8000), 15);
}

void berry_proceed_minutes(u16 minutes) {
    DEBUG("Proceeding berries by %d minutes\n", minutes);
    for (size_t i = 0; i < ARRAY_COUNT(cmem.berry_trees); i++) {
        berry_tree *tree = cmem.berry_trees + i;
        if (tree->stage != BERRY_STAGE_NO_BERRY && tree->stage != BERRY_STAGE_BERRIES) {
            berry_tree_grow((u8)i, minutes);
        }
    }
}

void berry_proceed() {
    if (!time_test()) return;
	if (!fmem.berry_tree_time_last_updated_initialized) {
        time_read(&fmem.berry_tree_time_last_update);
        fmem.berry_tree_time_last_updated_initialized = 1;
        DEBUG("Reference timestamp for berry tree updated initialized.\n");
	}
    rtc_timestamp time = {0};
    time_read(&time);
    u64 lseconds_last_update = rtc_timestamp_to_seconds(&fmem.berry_tree_time_last_update);
    u64 lseconds_current = rtc_timestamp_to_seconds(&time);
    if (lseconds_current < lseconds_last_update) {
        DEBUG("Timestamp of last update is %d.%d.%d clock time: %d:%d (%d s)\n", fmem.berry_tree_time_last_update.day, fmem.berry_tree_time_last_update.month, fmem.berry_tree_time_last_update.year,
            fmem.berry_tree_time_last_update.hour, fmem.berry_tree_time_last_update.minute, fmem.berry_tree_time_last_update.second);
        DEBUG("Timestamp current is %d.%d.%d clock time: %d:%d (%d s)\n", time.day, time.month, time.year,
            time.hour, time.minute, time.second);
        DEBUG("Warning: The current time is before the last berry tree update, this most likely is a bug...\n");
        return;
    }
    u64 ldelta_minutes = MIN(60 * 24 * 7, (lseconds_current - lseconds_last_update) / 64); // We do not care about delays longer than a week...
    if (ldelta_minutes > 0) {
        u16 delta_minutes = (u16)ldelta_minutes;
        berry_proceed_minutes(delta_minutes);
        time_read(&fmem.berry_tree_time_last_update);
    }
}

palette berry_tree_growth_sparkle_palette = {
    .pal = gfx_berry_tree_growth_sparklePal, .tag = TAG_BERRY_GROWTH_SPARKLE
};

graphic berry_tree_growth_sparkle_graphics[] = {
    [0] = {.sprite = gfx_berry_tree_growth_sparkleTiles + 0 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = TAG_BERRY_GROWTH_SPARKLE},
    [1] = {.sprite = gfx_berry_tree_growth_sparkleTiles + 1 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = TAG_BERRY_GROWTH_SPARKLE},
    [2] = {.sprite = gfx_berry_tree_growth_sparkleTiles + 2 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = TAG_BERRY_GROWTH_SPARKLE},
    [3] = {.sprite = gfx_berry_tree_growth_sparkleTiles + 3 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = TAG_BERRY_GROWTH_SPARKLE},
    [4] = {.sprite = gfx_berry_tree_growth_sparkleTiles + 4 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = TAG_BERRY_GROWTH_SPARKLE},
    [5] = {.sprite = gfx_berry_tree_growth_sparkleTiles + 5 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = TAG_BERRY_GROWTH_SPARKLE},
};

gfx_frame berry_tree_growth_sparkle_gfx_animation[] = {
    {.data = 0, .duration = 0}, {.data = 0, .duration = 8},  {.data = 1, .duration = 8}, {.data = 2, .duration = 8},
    {.data = 3, .duration = 8},  {.data = 4, .duration = 8}, {.data = 5, .duration = 8}, {.data = GFX_ANIM_END, .duration = 0},
};

gfx_frame *berry_tree_growth_sparkle_gfx_animations[] = {berry_tree_growth_sparkle_gfx_animation};

oam_template berry_tree_growth_sparkle_oam_template = {
    .tiles_tag = 0xFFFF, .pal_tag = TAG_BERRY_GROWTH_SPARKLE, .oam = &ow_final_oam_16_16, .animation = berry_tree_growth_sparkle_gfx_animations,
    .graphics = berry_tree_growth_sparkle_graphics, .rotscale = oam_rotscale_anim_table_null,
    .callback = overworld_effect_oam_callback_wait_for_gfx_animation,
};

void overworld_effect_berry_tree_growth_sparkle() {
    // Set up the x,y,z triplet for the berry tree
    u8 person_idx = (u8)(*var_access(LASTTALKED));
    u8 npc_idx = npc_get_by_person_idx(person_idx, save1->map, save1->bank);
    if (npc_idx >= 16) { // Should never happen
        ERROR("Overworld effect berry tree growth sparkle could not be located.\n");
    }
    overworld_effect_state.x = npcs[npc_idx].dest_x;
    overworld_effect_state.y = npcs[npc_idx].dest_y;
    overworld_effect_state.bg_priority = (oams[npcs[npc_idx].oam_id].final_oam.attr2 >> 10) & 3;

    oam_palette_load_if_not_present(&berry_tree_growth_sparkle_palette);
    overworld_effect_ow_coordinates_to_screen_coordinates((s16*)(&overworld_effect_state.x), (s16*)(&overworld_effect_state.y), 8, 4);
    u8 oam_idx = oam_new_forward_search(&berry_tree_growth_sparkle_oam_template, (s16)(overworld_effect_state.x), (s16)(overworld_effect_state.y), (u8)(overworld_effect_state.bg_priority));
    if (oam_idx < 0x40) {
        oam_object *o = oams + oam_idx;
        o->flags |= OAM_FLAG_CENTERED;
        o->final_oam.attr2 = (u16)((o->final_oam.attr2 & (~ATTR2_PRIO(3))) | ATTR2_PRIO(overworld_effect_state.bg_priority & 3));
        o->private[0] = 23;
    }
}

void berry_tree_option_all_wonderdust_enabled() {
    *var_access(LASTRESULT) = (u16) (options[OPTION_WONDER_DUST_AUTOMATIC_USAGE].getter() == OPTION_ON);
}