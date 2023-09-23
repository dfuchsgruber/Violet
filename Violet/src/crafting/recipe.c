#include "types.h"
#include "crafting.h"
#include "item/item.h"
#include "vars.h"
#include "debug.h"
#include "flags.h"

static const crafting_recipe crafting_recipies_healing[] = {
    /*
    {
        .item = ITEM_TRANK, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 1,
    },{
        .item = ITEM_SUPERTRANK, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 1,
    },{
        .item = ITEM_HYPERTRANK, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_SINELBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 1,
        .flag = FRBADGE_2,
    },{
        .item = ITEM_TOP_TRANK, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_TSITRUBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 1,
        .flag = FRBADGE_4,
    },{
        .item = ITEM_TOP_GENESUNG, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_TSITRUBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_PRUNUSBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 1,
        .flag = FRBADGE_5,
    },{
        .item = ITEM_TOP_GENESUNG, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_TSITRUBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_HYPERHEILER, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 1,
        .flag = FRBADGE_5,
    },{
        .item = ITEM_HYPERHEILER, 
        .ingredients = {
            [0] = {.item = ITEM_AMRENABEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_PIRSIFBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_FRAGIABEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [3] = {.item = ITEM_MARONBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 1,
    },
    */
    {
        .item = ITEM_WIRBELPILZ, 
        .ingredients = {
            [0] = {.item = ITEM_MINIPILZ, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 1,
    },{
        .item = ITEM_BELEBER, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_APFEL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 1,
        .flag = 0,
    },{
        .item = ITEM_TOP_BELEBER, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 20, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_RIESENAPFEL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [3] = {.item = ITEM_BELEBER, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 1,
        .flag = FRBADGE_1,
    },{
        .item = ITEM_SEEGESANG,
        .ingredients = {
            [0] = {.item = ITEM_KUESTENSALZ, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_KUESTENSCHALE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 1,
    },{
        .item = ITEM_RIESENAPFEL,
        .ingredients = {
            [0] = {.item = ITEM_APFEL, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 1,
    },{
        .item = ITEM_GOLDAPFEL,
        .ingredients = {
            [0] = {.item = ITEM_RIESENAPFEL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_NUGGET, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 1,
    }
};
static const crafting_recipe crafting_recipies_jewels[] = {
    {
        .item = ITEM_ENERGIEQUARZ, 
        .ingredients = {
            [0] = {.item = ITEM_QUARZSTAUB, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 1,
    },
    {
        .item = ITEM_ENERGIEDISK,
        .ingredients = {
            [0] = {.item = ITEM_QUARZSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 1,
    },
    {
        .item = ITEM_NUGGET, 
        .ingredients = {
            [0] = {.item = ITEM_MININUGGET, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 1,
    },{
        .item = ITEM_STERNENSTUECK, 
        .ingredients = {
            [0] = {.item = ITEM_STERNENSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 1,
    },{
        .item = ITEM_NORMALJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_HIMMIHBEERE, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 50, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_KAMPFJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_MORBBEERE, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 50, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
        .count = 1,
    
    },{
        .item = ITEM_FLUGJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_NANABBEERE, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 50, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_GIFTJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_NIRBEBEERE, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 50, .type = CRAFTING_INGREDIENT_ASH},
        },
        .flag = FLAG_JEWEL_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_BODENJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_SANANABEERE, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 50, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_GESTEINJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_GRANABEERE, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 50, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_KAEFERJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_SETANGBEERE, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 50, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_GEISTJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_QUALOTBEERE, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 50, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_STAHLJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_HONMELBEERE, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 50, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_FEEJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_LABRUSBEERE, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 50, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_FEUERJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_TAMOTBEERE, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 50, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_WASSERJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_SAIMBEERE, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 50, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_PFLANZEJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_MAGOSTBEERE, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 50, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_ELEKTROJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_RABUTABEERE, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 50, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_PSYCHOJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_TRONZIBEERE, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 50, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_EISJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_KIWANBEERE, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 50, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_DRACOJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_PALLMBEERE, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 50, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
        .flag = FLAG_JEWEL_RECIPIES,
    },{
        .item = ITEM_UNLICHTJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_WASMELBEERE, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 50, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
        .flag = FLAG_JEWEL_RECIPIES,
    }
};
static const crafting_recipe crafting_recipies_pokeballs[] = {
    {
        .item = ITEM_WOLKENBALL, 
        .ingredients = {
            [0] = {.item = ITEM_POKEBALL, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_NANABBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 5,
        .flag = FLAG_RECIPE_WOLKENBALL,
    },{
        .item = ITEM_NESTBALL, 
        .ingredients = {
            [0] = {.item = ITEM_POKEBALL, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_MINIPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 5,
        .flag = FLAG_RECIPE_NESTBALL,
    },{
        .item = ITEM_NETZBALL, 
        .ingredients = {
            [0] = {.item = ITEM_POKEBALL, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_PERLE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 5,
        .flag = FLAG_RECIPE_NETZBALL,
    },{
        .item = ITEM_WIEDERBALL, 
        .ingredients = {
            [0] = {.item = ITEM_POKEBALL, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 5,
        .flag = FLAG_RECIPE_WIEDERBALL,
    },{
        .item = ITEM_FINSTERBALL, 
        .ingredients = {
            [0] = {.item = ITEM_POKEBALL, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_DUESTERSTUECK, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 5,
        .flag = FLAG_RECIPE_FINSTERBALL,
    },{
        .item = ITEM_FLOTTBALL, 
        .ingredients = {
            [0] = {.item = ITEM_POKEBALL, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_WUNDERSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 5,
        .flag = FLAG_RECIPE_FLOTTBALL
    },{
        .item = ITEM_TIMERBALL, 
        .ingredients = {
            [0] = {.item = ITEM_POKEBALL, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_STERNENSTAUB, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 5,
        .flag = FLAG_RECIPE_TIMER_BALL,
    },{
        .item = ITEM_LUXUSBALL, 
        .ingredients = {
            [0] = {.item = ITEM_POKEBALL, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_MININUGGET, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 5,
        .flag = FLAG_RECIPE_LUXUSBALL,
    },{
        .item = ITEM_LOTUS_BALL, 
        .ingredients = {
            [0] = {.item = ITEM_POKEBALL, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_LOTUSBLUETE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 5,
        .flag = FLAG_RECIPE_LOTUS_BALL,
    },{
        .item = ITEM_MASSEBALL, 
        .ingredients = {
            [0] = {.item = ITEM_POKEBALL, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_APFEL, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 5,
        .flag = FLAG_RECIPE_STAT_BALLS,
    },{
        .item = ITEM_KRAFTBALL, 
        .ingredients = {
            [0] = {.item = ITEM_POKEBALL, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_LYDZIBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 5,
        .flag = FLAG_RECIPE_STAT_BALLS,
    },{
        .item = ITEM_SCHILDBALL, 
        .ingredients = {
            [0] = {.item = ITEM_POKEBALL, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_LINGANBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 5,
        .flag = FLAG_RECIPE_STAT_BALLS,
    },{
        .item = ITEM_AGILBALL, 
        .ingredients = {
            [0] = {.item = ITEM_POKEBALL, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_SALKABEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 5,
        .flag = FLAG_RECIPE_STAT_BALLS,
    },{
        .item = ITEM_GEDANKENBALL, 
        .ingredients = {
            [0] = {.item = ITEM_POKEBALL, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_TAHAYBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 5,
        .flag = FLAG_RECIPE_STAT_BALLS,
    },{
        .item = ITEM_FOKUSBALL, 
        .ingredients = {
            [0] = {.item = ITEM_POKEBALL, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_APIKOBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 5,
        .flag = FLAG_RECIPE_STAT_BALLS,
    },
};
static const crafting_recipe crafting_recipies_evolution[] = {
    {
        .item = ITEM_BLATTSTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_GRUENSTUECK, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 20, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
    },{
        .item = ITEM_WASSERSTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_INDIGOSTUECK, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 20, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
    },{
        .item = ITEM_FEUERSTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_PURPURSTUECK, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 20, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
    },{
        .item = ITEM_DONNERSTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_GELBSTUECK, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 20, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
    },{
        .item = ITEM_SONNENSTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_SOLARSTUECK, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 20, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
    },{
        .item = ITEM_MONDSTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_LUNARSTUECK, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 20, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
    },{
        .item = ITEM_FINSTERSTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_DUESTERSTUECK, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 20, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
    },{
        .item = ITEM_LEUCHTSTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_LICHTSTUECK, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 20, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
    },{
        .item = ITEM_FUNKELSTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_GLITZERSTUECK, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 20, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
    },{
        .item = ITEM_LINKKABEL, 
        .ingredients = {
            [0] = {.item = ITEM_STERNENSTUECK, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 25, .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
        .flag = FLAG_LINK_CABLE_RECIPE,
    },
};
static const crafting_recipe crafting_recipies_mints[] = {
    {
        .item = ITEM_ANGR_ORB_P, 
        .ingredients = {
            [0] = {.item = ITEM_LYDZIBEERE, .count = 15, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_ANGR_ORB_N, 
        .ingredients = {
            [0] = {.item = ITEM_GIEFEBEERE, .count = 15, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_VERT_ORB_P, 
        .ingredients = {
            [0] = {.item = ITEM_LINGANBEERE, .count = 15, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_VERT_ORB_N, 
        .ingredients = {
            [0] = {.item = ITEM_YAPABEERE, .count = 15, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_INIT_ORB_P, 
        .ingredients = {
            [0] = {.item = ITEM_SALKABEERE, .count = 15, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_INIT_ORB_N, 
        .ingredients = {
            [0] = {.item = ITEM_MAGOBEERE, .count = 15, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_SPA_ORB_P, 
        .ingredients = {
            [0] = {.item = ITEM_TAHAYBEERE, .count = 15, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_SPA_ORB_N, 
        .ingredients = {
            [0] = {.item = ITEM_WIKIBEERE, .count = 15, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_SPV_ORB_P, 
        .ingredients = {
            [0] = {.item = ITEM_APIKOBEERE, .count = 15, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_SPV_ORB_N, 
        .ingredients = {
            [0] = {.item = ITEM_GAUVEBEERE, .count = 15, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_MINTS_RECIPIES,
        .count = 1,
    },
};
static const crafting_recipe crafting_recipies_nutrients[] = {
    {
        .item = ITEM_KP_PLUS, 
        .ingredients = {
            [0] = {.item = ITEM_RIESENAPFEL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BITTERKRAUT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_NUTRIENT_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_PROTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_X_ANGRIFF, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BITTERKRAUT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_NUTRIENT_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_EISEN, 
        .ingredients = {
            [0] = {.item = ITEM_X_ABWEHR, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BITTERKRAUT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_NUTRIENT_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_CARBON, 
        .ingredients = {
            [0] = {.item = ITEM_X_TEMPO, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BITTERKRAUT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_NUTRIENT_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_KALZIUM, 
        .ingredients = {
            [0] = {.item = ITEM_X_SPEZIAL, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BITTERKRAUT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_NUTRIENT_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_ZINK, 
        .ingredients = {
            [0] = {.item = ITEM_X_SPEZIAL, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BITTERKRAUT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_NUTRIENT_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_NULLSAFT, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_KUESTENSALZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_KUESTENSCHALE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_NULLSAFT_RECIPE,
        .count = 1,
    },{
        .item = ITEM_AP_PLUS, 
        .ingredients = {
            [0] = {.item = ITEM_JONAGOBEERE, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_MINIPILZ, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_ENERGIESTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_PP_ITEM_RECIPE,
        .count = 1,
    },{
        .item = ITEM_AP_TOP, 
        .ingredients = {
            [0] = {.item = ITEM_JONAGOBEERE, .count = 15, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_PP_ITEM_RECIPE,
        .count = 1,
    },{
        .item = ITEM_SUESSBONBON, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 1,
    },{
        .item = ITEM_EP_BONBON_S, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_RECIPE_EXP_CANDY_S,
        .count = 1,
    },{
        .item = ITEM_EP_BONBON_M, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_MINIPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_RECIPE_EXP_CANDY_M,
        .count = 1,
    },{
        .item = ITEM_EP_BONBON_L, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_RECIPE_EXP_CANDY_L,
        .count = 1,
    },{
        .item = ITEM_EP_BONBON_XL, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 20, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_MINIPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_RIESENPILZ, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_RECIPE_EXP_CANDY_XL,
        .count = 1,
    },{
        .item = ITEM_SONDERBONBON, 
        .ingredients = {
            [0] = {.item = ITEM_BITTERKRAUT, .count = 20, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_ENERGIEQUARZ, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_RARE_CANDY_RECIPE,
        .count = 1,
    },{
        .item = ITEM_GOLDBONBON, 
        .ingredients = {
            [0] = {.item = ITEM_SONDERBONBON, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_NUGGET, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_GOLD_CANDY_RECIPE,
        .count = 1,
    },{
        .item = ITEM_REGULAER_PFLASTER,
        .ingredients = {
            [2] = {.item = ITEM_RIESENPILZ, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [0] = {.item = ITEM_QUARZSTAUB, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BITTERKRAUT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
            [3] = {.count = CRAFTING_INGREDIENT_ASH_TO_COUNT(1500), .type = CRAFTING_INGREDIENT_ASH},
        },
        .count = 1,
        .flag = FLAG_RECIPE_REGULAERES_PFLASTER,
    },{
        .item = ITEM_FAEHIGK_PFLASTER, 
        .ingredients = {
            [0] = {.item = ITEM_REGULAER_PFLASTER, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_LOTUSBLUETE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_RECIPE_LOTUS_ITEMS,
        .count = 1,
    }
};
static const crafting_recipe crafting_recipies_battle[] = {
    {
        .item = ITEM_X_ANGRIFF, 
        .ingredients = {
            [0] = {.item = ITEM_LYDZIBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 3,
    },{
        .item = ITEM_X_ABWEHR, 
        .ingredients = {
            [0] = {.item = ITEM_LINGANBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 3,
    },{
        .item = ITEM_X_TEMPO, 
        .ingredients = {
            [0] = {.item = ITEM_SALKABEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 3,
    },{
        .item = ITEM_X_SPEZIAL, 
        .ingredients = {
            [0] = {.item = ITEM_TAHAYBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 3,
    },{
        .item = ITEM_MEGABLOCK, 
        .ingredients = {
            [0] = {.item = ITEM_KRAMBOBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 3,
    },{
        .item = ITEM_ANGRIFFPLUS, 
        .ingredients = {
            [0] = {.item = ITEM_LANSATBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_QUARZSTAUB, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .count = 3,
    },{
        .item = ITEM_SONNEN_EI, 
        .ingredients = {
            [0] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_LICHTSTUECK, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_WEATHER_EGG_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_GEWITTER_EI, 
        .ingredients = {
            [0] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_INDIGOSTUECK, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_WEATHER_EGG_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_WUESTEN_EI, 
        .ingredients = {
            [0] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_SANANABEERE, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_WEATHER_EGG_RECIPIES,
        .count = 1,
    },{
        .item = ITEM_TUNDRA_EI, 
        .ingredients = {
            [0] = {.item = ITEM_ENERGIEQUARZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_KIWANBEERE, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        },
        .flag = FLAG_WEATHER_EGG_RECIPIES,
        .count = 1,
    },
};

const crafting_recipe *const crafting_recipies[CRAFTING_TYPE_CNT] = {
    [CRAFTING_HEALING] = crafting_recipies_healing,
    [CRAFTING_POKEBALLS] = crafting_recipies_pokeballs,
    [CRAFTING_JEWELS] = crafting_recipies_jewels,
    [CRAFTING_EVOLUTION] = crafting_recipies_evolution,
    [CRAFTING_MINTS] = crafting_recipies_mints,
    [CRAFTING_NUTRIENTS] = crafting_recipies_nutrients,
    [CRAFTING_BATTLE] = crafting_recipies_battle,
};

const u8 crafting_num_recipies_by_type[CRAFTING_TYPE_CNT] = {
    [CRAFTING_HEALING] = ARRAY_COUNT(crafting_recipies_healing),
    [CRAFTING_POKEBALLS] = ARRAY_COUNT(crafting_recipies_pokeballs),
    [CRAFTING_JEWELS] = ARRAY_COUNT(crafting_recipies_jewels),
    [CRAFTING_EVOLUTION] = ARRAY_COUNT(crafting_recipies_evolution),
    [CRAFTING_MINTS] = ARRAY_COUNT(crafting_recipies_mints),
    [CRAFTING_NUTRIENTS] = ARRAY_COUNT(crafting_recipies_nutrients),
    [CRAFTING_BATTLE] = ARRAY_COUNT(crafting_recipies_battle),
};

size_t crafting_get_num_recipies_by_type(u16 type) {
    if (type < CRAFTING_TYPE_CNT)
        return crafting_num_recipies_by_type[type];
    else
        return 0;
}

const crafting_recipe *crafting_recipies_get_by_type(u16 type) {
    if (type < CRAFTING_TYPE_CNT)
        return crafting_recipies[type];
    else
        return NULL;
}

bool ingredient_requirements_fulfilled(const crafting_ingredient *ingredient, u16 count) {
    count = (u16)(count * ingredient->count);
    if (count == 0)
        return true;
    switch (ingredient->type) {
        case CRAFTING_INGREDIENT_ITEM: {
            return item_check(ingredient->item, count);
        }
        case CRAFTING_INGREDIENT_ASH: {
            u16 ash = *var_access(ASH);
            return ash >= (count * CRAFTING_INGREDIENT_ASH_MULTIPLIER);
        }
    }
    return false;
}

bool recipe_requirements_fulfilled(const crafting_recipe *r, u16 count) {
    for (u8 i = 0; i < ARRAY_COUNT(r->ingredients); i++) {
        if (r->ingredients[i].count > 0) {
            if (!ingredient_requirements_fulfilled(r->ingredients + i, count))
                return false;
        }
    }
    return true;
}

u16 recipe_max_count_with_requirements_fulfilled(const crafting_recipe *r) {
    int max_count = INT_MAX;
    for (u8 i = 0; i < ARRAY_COUNT(r->ingredients); i++) {
        const crafting_ingredient *ingredient = r->ingredients + i;
        if (ingredient->count > 0) {
            switch (ingredient->type) {
                case CRAFTING_INGREDIENT_ITEM: {
                    max_count = MIN(max_count, item_get_count(ingredient->item) / ingredient->count);
                    break;
                }
                case CRAFTING_INGREDIENT_ASH: {
                    max_count = MIN(max_count, *var_access(ASH) / (ingredient->count * CRAFTING_INGREDIENT_ASH_MULTIPLIER));
                    break;
                }
            } 
            DEBUG("After ingredient %d with item %d the max count is %d\n", i, ingredient->item, max_count);
        }
        while (!item_has_room(r->item, (u16)(r->count * max_count)) && max_count > 0)
            max_count--;
    }
    return (u16) max_count;
}

bool recipe_use(const crafting_recipe *r, u16 count) {
    if (recipe_requirements_fulfilled(r, count) && item_has_room(r->item, count)) {
        for (u8 i = 0; i < ARRAY_COUNT(r->ingredients); i++) {
            if (r->ingredients[i].type == CRAFTING_INGREDIENT_ASH) {
                *var_access(ASH) = (u16)(*var_access(ASH) - r->ingredients[i].count * CRAFTING_INGREDIENT_ASH_MULTIPLIER * count);
            } else if (r->ingredients[i].count > 0) {
                item_remove(r->ingredients[i].item, (u16)(r->ingredients[i].count * count));
            }
        }
        item_add(r->item, (u16)(count * r->count));
        return true;
    }
    return false;
}
