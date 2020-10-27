#include "types.h"
#include "pokemon/virtual.h"
#include "pokemon/evolution.h"
#include "pokemon/moves.h"
#include "constants/items.h"
#include "constants/species.h"
#include "constants/pokemon_attributes.h"
#include "constants/evolution_methods.h"
#include "constants/pokemon_types.h"
#include "constants/attacks.h"
#include "debug.h"
#include "attack.h"
#include "rtc.h"
#include "save.h"

u16 pokemon_get_evolution(pokemon * p, u8 type, u16 arg) {
    u16 species = (u16) pokemon_get_attribute(p, ATTRIBUTE_SPECIES, 0);
    u16 held_item = (u16) pokemon_get_attribute(p, ATTRIBUTE_ITEM, 0);
	dprintf("Pokemon evolutions[species] @%x\n", pokemon_evolutions[species]);
    if (pokemon_evolutions[species]) {
        pokemon_evolution *evolutions = pokemon_evolutions[species];
        switch (type) {
        case EVOLUTION_TRIGGER_LEVEL_UP:
        {   //The usual case
            arg = (u8) pokemon_get_attribute(p, ATTRIBUTE_LEVEL, 0);
            for (int i = 0; evolutions[i].method != EVOLUTION_METHOD_NONE; i++) {
            	dprintf("Checking evolution index %d with method %d @ %x\n", i, evolutions[i].method, &evolutions[i]);
                switch (evolutions[i].method) {
                case EVOLUTION_METHOD_FRIENDSHIP:
                {
                    u8 friendship = (u8) pokemon_get_attribute(p, ATTRIBUTE_HAPPINESS, 0);
                    if (friendship >= 220)
                        return evolutions[i].target;
                    break;
                }
                case EVOLUTION_METHOD_FRIENDSHIP_DAY:
                {
                    u8 friendship = (u8) pokemon_get_attribute(p, ATTRIBUTE_HAPPINESS, 0);
                    if (!time_test())
                        dprintf("A Pokemon that evolves at day has leveled up but your time seems to be turned off!\n");
                    rtc_timestamp time = {
                        0
                    };
                    time_read( & time);
                    if (time.hour > 6 && time.hour < 22 && friendship >= 220)
                        return evolutions[i].target;
                    break;
                }
                case EVOLUTION_METHOD_FRIENDSHIP_NIGHT:
                {
                    u8 friendship = (u8) pokemon_get_attribute(p, ATTRIBUTE_HAPPINESS, 0);
                    if (!time_test())
                        dprintf("A Pokemon that evolves at night has leveled up but your time seems to be turned off!\n");
                    rtc_timestamp time = {
                        0
                    };
                    time_read( & time);
                    dprintf("Night evolution with friendship at %d\n", friendship);
                    if ((time.hour <= 6 || time.hour >= 22) && friendship >= 220)
                        return evolutions[i].target;
                    break;
                }
                case EVOLUTION_METHOD_SPAWN_SECOND:
                case EVOLUTION_METHOD_LEVEL_UP:
                {
                    dprintf("Level up called with arg %d and cond %d\n", arg, evolutions[i].condition);
                    if (evolutions[i].condition <= arg)
                        return evolutions[i].target;
                    break;
                }
                case EVOLUTION_METHOD_ATK_GT_DEF:
                {
                    u16 atk = (u16) pokemon_get_attribute(p, ATTRIBUTE_ATK, 0);
                    u16 def = (u16) pokemon_get_attribute(p, ATTRIBUTE_DEF, 0);
                    if (atk > def && evolutions[i].condition <= arg)
                        return evolutions[i].target;
                    break;
                }
                case EVOLUTION_METHOD_ATK_EQ_DEF:
                {
                    u16 atk = (u16) pokemon_get_attribute(p, ATTRIBUTE_ATK, 0);
                    u16 def = (u16) pokemon_get_attribute(p, ATTRIBUTE_DEF, 0);
                    if (atk == def && evolutions[i].condition <= arg)
                        return evolutions[i].target;
                    break;
                }
                case EVOLUTION_METHOD_ATK_LT_DEF:
                {
                    u16 atk = (u16) pokemon_get_attribute(p, ATTRIBUTE_ATK, 0);
                    u16 def = (u16) pokemon_get_attribute(p, ATTRIBUTE_DEF, 0);
                    if (atk < def && evolutions[i].condition <= arg)
                        return evolutions[i].target;
                    break;
                }
                case EVOLUTION_METHOD_PID_EVEN:
                {
                    pid_t pid = {.value = (u32) pokemon_get_attribute(p, ATTRIBUTE_PID, 0)
                                };
                    if (evolutions[i].condition <= arg &&
                            pid.value % 10 <= 4)
                        return evolutions[i].target;
                    break;
                }
                case EVOLUTION_METHOD_PID_ODD:
                {
                    pid_t pid = {.value = (u32) pokemon_get_attribute(p, ATTRIBUTE_PID, 0)
                                };
                    if (evolutions[i].condition <= arg &&
                            pid.value % 10 > 4)
                        return evolutions[i].target;
                    break;
                }
                case EVOLUTION_METHOD_ON_MAP:
                {
                    u16 condition = evolutions[i].condition;
                    u8 bank = (u8)(condition & 0xFF);
                    u8 mapid = (u8)((condition >> 8) & 0xFF);
                    if (bank == save1->bank && mapid == save1->map)
                        return evolutions[i].target;
                    break;
                }
                case EVOLUTION_METHOD_HOLD_ITEM:
                {
                    if (held_item == evolutions[i].condition) {
                        held_item = 0; //Remove this item
                        pokemon_set_attribute(p, ATTRIBUTE_ITEM, & held_item);
                        return evolutions[i].target;
                    }
                    break;
                }
                case EVOLUTION_METHOD_KNOW_MOVE:
                {
                    u16 move = evolutions[i].condition;
                    int j;
                    for (j = 0; j < 4; j++) {
                        if (pokemon_get_attribute(p,
                                                  (u16)(ATTRIBUTE_ATTACK1 + j), 0) == move)
                            return evolutions[i].target;

                    }
                    break;
                }
                case EVOLUTION_METHOD_HOLD_ITEM_AND_NIGHT:
                {
                    if (!time_test())
                        dprintf("A Pokemon that evolves at night has leveled up but your RTC seems to be turned off!\n");
                    rtc_timestamp time = {
                        0
                    };
                    time_read( & time);
                    if ((time.hour <= 6 || time.hour >= 22) &&
                            held_item == evolutions[i].condition) {
                        held_item = 0; //Remove this item
                        pokemon_set_attribute(p, ATTRIBUTE_ITEM, & held_item);
                        return evolutions[i].target;
                    }
                    break;
                }
                case EVOLUTION_METHOD_HOLD_ITEM_AND_DAY:
                {
                    if (!time_test())
                        dprintf("A Pokemon that evolves at day has leveled up but your RTC seems to be turned off!\n");
                    rtc_timestamp time = {
                        0
                    };
                    time_read( & time);
                    if ((time.hour > 6 || time.hour < 22) &&
                            held_item == evolutions[i].condition) {
                        held_item = 0; //Remove this item
                        pokemon_set_attribute(p, ATTRIBUTE_ITEM, & held_item);
                        return evolutions[i].target;
                    }
                    break;
                }
                case EVOLUTION_METHOD_FEMALE_AND_LEVEL_UP: {
                    u8 gender = pokemon_get_gender(&p->box);
                    if (gender == GENDER_FEMALE && evolutions[i].condition <= arg)
                        return evolutions[i].target;
                    break;
                }
                }
            }
            break;
        }
        case EVOLUTION_TRIGGER_TRADE_EVO:
            // Deprecated as trade evo does not exist
            break;
        case EVOLUTION_TRIGGER_ITEM:
        case EVOLUTION_TRIGGER_ITEM2:
        case EVOLUTION_TRIGGER_ITEM_AND_REMOVE_HOLD_ITEM:
        {
            dprintf("Item evolution with type %d\n", type);
            //Check for evolutions triggered by an item
            int i;
            for (i = 0; evolutions[i].method != EVOLUTION_METHOD_NONE; i++) {
                switch (evolutions[i].method) {
                case EVOLUTION_METHOD_STONE: //Regular evolution stone
                    if (evolutions[i].condition == arg)
                        return evolutions[i].target;
                    break;
                case EVOLUTION_METHOD_LINK_CABLE_AND_ITEM:
                    if (arg == ITEM_LINKKABEL &&
                            evolutions[i].condition == held_item) {
                        if (type == EVOLUTION_TRIGGER_ITEM_AND_REMOVE_HOLD_ITEM) {
                            held_item = 0;
                            pokemon_set_attribute(p, ATTRIBUTE_ITEM, & held_item);
                        }
                        return evolutions[i].target;

                    }
                    break;
                case EVOLUTION_METHOD_MALE_AND_STONE:
                {
                    u8 gender = pokemon_get_gender(&p->box);
                    if (gender == GENDER_MALE && evolutions[i].condition == arg)
                        return evolutions[i].target;
                    break;
                }
                case EVOLUTION_METHOD_FEMALE_AND_STONE:
                {
                    u8 gender = pokemon_get_gender(&p->box);
                    if (gender == GENDER_FEMALE && evolutions[i].condition == arg)
                        return evolutions[i].target;
                    break;
                }
                }
            }
            break;
        }

        }

    }
    return 0;
}

bool pokemon_can_evolve (u16 species) {
    if (pokemon_evolutions[species]) {
        pokemon_evolution *evolutions = pokemon_evolutions[species];
        // Has at least one evolution
        return evolutions[0].method != EVOLUTION_METHOD_NONE;
    }
    return false;
}

u16 pokemon_get_basis_stage (u16 species) {
	for (u16 i = 0; i < POKEMON_CNT; i++) {
		if (pokemon_evolutions[i]) {
	        pokemon_evolution *evolutions = pokemon_evolutions[i];
			for (int j = 0; evolutions[j].method != EVOLUTION_METHOD_NONE; j++) {
				if (evolutions[j].target == species) {
					return pokemon_get_basis_stage(i);
				}
			}
		}
	}
	// No pokemon evolves into this one
	return species;
}

static size_t pokemon_get_evolution_item_line_dfs(u16 species, u16 *items, size_t max_size, size_t depth) {
    if (depth > 2) {
        dprintf("Scanning for all items in a evolution line for species %d reached a depth greater than 2.\n", species);
        return 0;
    }
    dprintf("Evolution item DFS for species %d at depth %d, items %x, max_items %d\n", species, depth, items, max_size);
    size_t cnt = 0; // count how  many items were already added
    pokemon_evolution *evolutions = pokemon_evolutions[species];
    if (evolutions) {
        for (int j = 0; evolutions[j].method != EVOLUTION_METHOD_NONE && cnt < max_size && j < 20; j++) { // j < 20 is a safety condition, a pokémon should not have more than 20 successors (i.e. mons it evolves into)
            if (evolutions[j].method == EVOLUTION_METHOD_TRADE_HOLD_ITEM || evolutions[j].method == EVOLUTION_METHOD_HOLD_ITEM ||
                evolutions[j].method == EVOLUTION_METHOD_LINK_CABLE_AND_ITEM || evolutions[j].method == EVOLUTION_METHOD_HOLD_ITEM_AND_NIGHT ||
                evolutions[j].method == EVOLUTION_METHOD_HOLD_ITEM_AND_DAY) {
                items[cnt++] = evolutions[j].condition;
            }
            // DFS on evolution targets, if we can collect more items
            if (cnt < max_size) {
                cnt += pokemon_get_evolution_item_line_dfs(evolutions[j].target, items + cnt, max_size - cnt, depth + 1);
            }
        }
    }
    dprintf("Evolution item DFS for species %d at depth %d found %d items.\n", species, depth, cnt);
    return cnt;
}


size_t pokemon_get_evolution_item_line(u16 species, u16 *items, size_t max_size) {
    dprintf("Basis stage of %d\n ", species);
    species = pokemon_get_basis_stage(species);
    dprintf("Is %d\n", species);
    // Unfold the dfs tree of this species, we assume no cycles and therefore don't save visited nodes
    return pokemon_get_evolution_item_line_dfs(species, items, max_size, 0);
}

void pokemon_get_evolution_item_line_test() {
    u16 items[10];
    size_t cnt = pokemon_get_evolution_item_line(POKEMON_PORYGON2, items, ARRAY_COUNT(items));
    for (size_t i = 0; i < cnt; i++) {
        dprintf("Item %d is %d\n", i, items[i]);
    }
}