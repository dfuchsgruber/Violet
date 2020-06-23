#include "types.h"
#include "crafting.h"
#include "item/item.h"
#include "vars.h"

static crafting_recipe crafting_recipies_healing[] = {

    // stub
    {
        .item = ITEM_ABYSSZAHN, 
        .ingredients = {
            [1] = {.item = ITEM_HAFENBRIEF, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [0] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    },

    // stub
    {
        .item = ITEM_DETEKTOR, 
        .ingredients = {
            [0] = {.item = ITEM_AMRENABEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_WUNDERSTAUB, .count = 4, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    },

    // stub
    {
        .item = ITEM_AEON_TICKET, 
        .ingredients = {
            [0] = {.item = ITEM_AMRENABEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_WUNDERSTAUB, .count = 4, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    },

    // stub
    {
        .item = ITEM_HEILPUDER, 
        .ingredients = {
            [0] = {.item = ITEM_AMRENABEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_WUNDERSTAUB, .count = 4, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    },

    // stub
    {
        .item = ITEM_POKEPUPPE, 
        .ingredients = {
            [0] = {.item = ITEM_AMRENABEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_WUNDERSTAUB, .count = 4, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    },
};
static crafting_recipe crafting_recipies_pokeballs[] = {

    // stub
    {
        .item = ITEM_ABYSSZAHN, 
        .ingredients = {
            [1] = {.item = ITEM_HAFENBRIEF, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [0] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    },

    // stub
    {
        .item = ITEM_DETEKTOR, 
        .ingredients = {
            [0] = {.item = ITEM_AMRENABEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_WUNDERSTAUB, .count = 4, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    },

    // stub
    {
        .item = ITEM_AEON_TICKET, 
        .ingredients = {
            [0] = {.item = ITEM_AMRENABEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_WUNDERSTAUB, .count = 4, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    },

    // stub
    {
        .item = ITEM_HEILPUDER, 
        .ingredients = {
            [0] = {.item = ITEM_AMRENABEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_WUNDERSTAUB, .count = 4, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    },

    // stub
    {
        .item = ITEM_POKEPUPPE, 
        .ingredients = {
            [0] = {.item = ITEM_AMRENABEERE, .count = 2, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_WUNDERSTAUB, .count = 4, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    },
    // stub
    {
        .item = ITEM_ABYSSZAHN, 
        .ingredients = {
            [1] = {.item = ITEM_HAFENBRIEF, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [0] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    },
    // stub
    {
        .item = ITEM_MEISTERBALL, 
        .ingredients = {
            [0] = {.item = ITEM_MINIPILZ, .count = 1, .type = CRAFTING_INGREDIENT_ITEM},
            [1] = {.item = ITEM_WUNDERSTAUB, .count = 4, .type = CRAFTING_INGREDIENT_ITEM},
            [2] = {.count = 10, .type = CRAFTING_INGREDIENT_ASH},
        }
    },

};
static crafting_recipe crafting_recipies_jewels[] = {};
static crafting_recipe crafting_recipies_evolution[] = {};
static crafting_recipe crafting_recipies_mints[] = {};
static crafting_recipe crafting_recipies_nutrients[] = {};


size_t crafting_get_num_recipies_by_type(u16 type) {
    switch (type) {
        case CRAFTING_HEALING: return ARRAY_COUNT(crafting_recipies_healing);
        case CRAFTING_POKEBALLS: return ARRAY_COUNT(crafting_recipies_pokeballs);
        case CRAFTING_JEWELS: return ARRAY_COUNT(crafting_recipies_jewels);
        case CRAFTING_EVOLUTION: return ARRAY_COUNT(crafting_recipies_evolution);
        case CRAFTING_MINTS: return ARRAY_COUNT(crafting_recipies_mints);
        case CRAFTING_NUTRIENTS: return ARRAY_COUNT(crafting_recipies_nutrients);
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