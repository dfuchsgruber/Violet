#include "types.h"
#include "crafting.h"
#include "item/item.h"
#include "vars.h"

static crafting_recipe crafting_recipies_healing[] = {
    {
        .item = ITEM_TRANK, 
        .ingredients = {
            [0] = {.item = ITEM_SINELBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_SUPERTRANK, 
        .ingredients = {
            [0] = {.item = ITEM_TSITRUBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_HYPERTRANK, 
        .ingredients = {
            [0] = {.item = ITEM_SINELBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_TSITRUBEERE, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_TOP_TRANK, 
        .ingredients = {
            [0] = {.item = ITEM_SINELBEERE, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_TSITRUBEERE, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_TOP_GENESUNG, 
        .ingredients = {
            [0] = {.item = ITEM_SINELBEERE, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_TSITRUBEERE, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_PRUNUSBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_TOP_GENESUNG, 
        .ingredients = {
            [0] = {.item = ITEM_SINELBEERE, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_TSITRUBEERE, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_PRUNUSBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_HYPERHEILER, 
        .ingredients = {
            [0] = {.item = ITEM_AMRENABEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_PIRSIFBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_FRAGIABEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [3] = {.item = ITEM_MARONBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_BELEBER, 
        .ingredients = {
            [0] = {.item = ITEM_BEERENSAFT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_WUNDERSTAUB, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_TSITRUBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [3] = {.item = ITEM_PRUNUSBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_TOP_BELEBER, 
        .ingredients = {
            [0] = {.item = ITEM_BEERENSAFT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_WUNDERSTAUB, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_ELIXIER, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [3] = {.item = ITEM_BELEBER, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_SEEGESANG,
        .ingredients = {
            [0] = {.item = ITEM_KUESTENSALZ, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_KUESTENSCHALE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        }
    }
};
static crafting_recipe crafting_recipies_jewels[] = {
    {
        .item = ITEM_NORMALJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_HIMMIHBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    
    },{
        .item = ITEM_KAMPFJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_MORBBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    
    },{
        .item = ITEM_FLUGJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_NANABBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    
    },{
        .item = ITEM_GIFTJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_NIRBEBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    
    },{
        .item = ITEM_BODENJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_SANANABEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    
    },{
        .item = ITEM_GESTEINJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_GRANABEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    
    },{
        .item = ITEM_KAEFERJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_SETANGBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    
    },{
        .item = ITEM_GEISTJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_QUALOTBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    
    },{
        .item = ITEM_STAHLJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_HONMELBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    
    },{
        .item = ITEM_FEEJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_LABRUSBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    
    },{
        .item = ITEM_FEUERJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_TAMOTBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    
    },{
        .item = ITEM_WASSERJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_SAIMBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    
    },{
        .item = ITEM_PFLANZEJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_MAGOSTBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    
    },{
        .item = ITEM_ELEKTROJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_RABUTABEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    
    },{
        .item = ITEM_PSYCHOJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_TRONZIBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    
    },{
        .item = ITEM_EISJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_KIWANBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    
    },{
        .item = ITEM_DRACOJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_PALLMBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    
    },{
        .item = ITEM_UNLICHTJUWEL, 
        .ingredients = {
            [0] = {.item = ITEM_WASMELBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    }
};

static crafting_recipe crafting_recipies_pokeballs[] = {
    {
        .item = ITEM_TAUCHBALL, 
        .ingredients = {
            [0] = {.item = ITEM_PERLE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_POKEBALL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_NESTBALL, 
        .ingredients = {
            [0] = {.item = ITEM_MINIPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_POKEBALL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_NETZBALL, 
        .ingredients = {
            [0] = {.item = ITEM_PERLE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_POKEBALL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_WIEDERBALL, 
        .ingredients = {
            [0] = {.item = ITEM_BEERENSAFT, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_POKEBALL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_TIMERBALL, 
        .ingredients = {
            [0] = {.item = ITEM_STERNENSTAUB, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_POKEBALL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_LUXUSBALL, 
        .ingredients = {
            [0] = {.item = ITEM_SUESSBONBON, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_POKEBALL, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },
};
static crafting_recipe crafting_recipies_evolution[] = {};
static crafting_recipe crafting_recipies_mints[] = {
    {
        .item = ITEM_ANGR_ORB_P, 
        .ingredients = {
            [0] = {.item = ITEM_LYDZIBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BEERENSAFT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_ANGR_ORB_N, 
        .ingredients = {
            [0] = {.item = ITEM_GIEFEBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BEERENSAFT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_VERT_ORB_P, 
        .ingredients = {
            [0] = {.item = ITEM_LINGANBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BEERENSAFT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_VERT_ORB_N, 
        .ingredients = {
            [0] = {.item = ITEM_YAPABEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BEERENSAFT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_INIT_ORB_P, 
        .ingredients = {
            [0] = {.item = ITEM_SALKABEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BEERENSAFT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_INIT_ORB_N, 
        .ingredients = {
            [0] = {.item = ITEM_MAGOBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BEERENSAFT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_SPA_ORB_P, 
        .ingredients = {
            [0] = {.item = ITEM_TAHAYBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BEERENSAFT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_SPA_ORB_N, 
        .ingredients = {
            [0] = {.item = ITEM_WIKIBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BEERENSAFT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_SPV_ORB_P, 
        .ingredients = {
            [0] = {.item = ITEM_APIKOBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BEERENSAFT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_SPV_ORB_N, 
        .ingredients = {
            [0] = {.item = ITEM_GAUVEBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BEERENSAFT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_MINIPILZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },
};
static crafting_recipe crafting_recipies_nutrients[] = {
    {
        .item = ITEM_KP_PLUS, 
        .ingredients = {
            [0] = {.item = ITEM_MEGABLOCK, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BEERENSAFT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_PROTEIN, 
        .ingredients = {
            [0] = {.item = ITEM_X_ANGRIFF, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BEERENSAFT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_EISEN, 
        .ingredients = {
            [0] = {.item = ITEM_X_ABWEHR, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BEERENSAFT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_CARBON, 
        .ingredients = {
            [0] = {.item = ITEM_X_TEMPO, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BEERENSAFT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_KALZIUM, 
        .ingredients = {
            [0] = {.item = ITEM_X_SPEZIAL, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BEERENSAFT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_ZINK, 
        .ingredients = {
            [0] = {.item = ITEM_X_SPEZIAL, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BEERENSAFT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_NULLSAFT, 
        .ingredients = {
            [0] = {.item = ITEM_KUESTENSALZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_KUESTENSALZ, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BEERENSAFT, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_AP_PLUS, 
        .ingredients = {
            [0] = {.item = ITEM_JONAGOBEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_MINIPILZ, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BEERENSAFT, .count = 10, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_AP_TOP, 
        .ingredients = {
            [0] = {.item = ITEM_JONAGOBEERE, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_RIESENPILZ, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.item = ITEM_BEERENSAFT, .count = 25, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_SONDERBONBON, 
        .ingredients = {
            [0] = {.item = ITEM_WUNDERSTAUB, .count = 25, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_STERNENSTAUB, .count = 5, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_SUESSBONBON, 
        .ingredients = {
            [0] = {.item = ITEM_WUNDERSTAUB, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_STERNENSTAUB, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_GOLDBONBON, 
        .ingredients = {
            [0] = {.item = ITEM_SONDERBONBON, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_NUGGET, .count = 3, .type = CRAFTING_INGREDIENT_ITEM},
        }
    }
};

static crafting_recipe crafting_recipies_battle[] = {
    {
        .item = ITEM_X_ANGRIFF, 
        .ingredients = {
            [0] = {.item = ITEM_LYDZIBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BEERENSAFT, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_X_ABWEHR, 
        .ingredients = {
            [0] = {.item = ITEM_LINGANBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BEERENSAFT, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_X_TEMPO, 
        .ingredients = {
            [0] = {.item = ITEM_SALKABEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BEERENSAFT, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_X_SPEZIAL, 
        .ingredients = {
            [0] = {.item = ITEM_TAHAYBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BEERENSAFT, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_MEGABLOCK, 
        .ingredients = {
            [0] = {.item = ITEM_KRAMBOBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BEERENSAFT, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },{
        .item = ITEM_ANGRIFFPLUS, 
        .ingredients = {
            [0] = {.item = ITEM_LANSATBEERE, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_BEERENSAFT, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
        }
    },
};

size_t crafting_get_num_recipies_by_type(u16 type) {
    switch (type) {
        case CRAFTING_HEALING: return ARRAY_COUNT(crafting_recipies_healing);
        case CRAFTING_POKEBALLS: return ARRAY_COUNT(crafting_recipies_pokeballs);
        case CRAFTING_JEWELS: return ARRAY_COUNT(crafting_recipies_jewels);
        case CRAFTING_EVOLUTION: return ARRAY_COUNT(crafting_recipies_evolution);
        case CRAFTING_MINTS: return ARRAY_COUNT(crafting_recipies_mints);
        case CRAFTING_NUTRIENTS: return ARRAY_COUNT(crafting_recipies_nutrients);
        case CRAFTING_BATTLE: return ARRAY_COUNT(crafting_recipies_battle);
        default: return 0;
    }
}

crafting_recipe *crafting_recipies_get_by_type(u16 type) {
    switch (type) {
        case CRAFTING_HEALING: return crafting_recipies_healing;
        case CRAFTING_POKEBALLS: return crafting_recipies_pokeballs;
        case CRAFTING_JEWELS: return crafting_recipies_jewels;
        case CRAFTING_EVOLUTION: return crafting_recipies_evolution;
        case CRAFTING_MINTS: return crafting_recipies_mints;
        case CRAFTING_NUTRIENTS: return crafting_recipies_nutrients;
        case CRAFTING_BATTLE: return crafting_recipies_battle;
        default: return 0;
    }
}

bool ingredient_requirements_fulfilled(crafting_ingredient *ingredient) {
    if (ingredient->count == 0)
        return true;
    switch (ingredient->type) {
        case CRAFTING_INGREDIENT_ITEM: {
            return item_check(ingredient->item, ingredient->count);
        }
        case CRAFTING_INGREDIENT_ASH: {
            u16 ash = *var_access(ASH);
            return ash >= (ingredient->count * CRAFTING_INGREDIENT_ASH_MULTIPLIER);
        }
    }
    return false;
}

bool recipe_requirements_fulfilled(crafting_recipe *r) {
    for (u8 i = 0; i < ARRAY_COUNT(r->ingredients); i++) {
        if (r->ingredients[i].count > 0) {
            if (!ingredient_requirements_fulfilled(r->ingredients + i))
                return false;
        }
    }
    return true;
}

bool recipe_use(crafting_recipe *r) {
    if (recipe_requirements_fulfilled(r) && item_has_room(r->item, 1)) {
        for (u8 i = 0; i < ARRAY_COUNT(r->ingredients); i++) {
            if (r->ingredients[i].type == CRAFTING_INGREDIENT_ASH) {
                *var_access(ASH) = (u16)(*var_access(ASH) - r->ingredients[i].count * CRAFTING_INGREDIENT_ASH_MULTIPLIER);
            } else if (r->ingredients[i].count > 0) {
                item_remove(r->ingredients[i].item, r->ingredients[i].count);
            }
        }
        item_add(r->item, 1);
        return true;
    }
    return false;
}