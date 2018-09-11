#include "types.h"
#include "map/header.h"
#include "pokepad/gui.h"
#include "pokepad/pokeradar.h"
#include "callbacks.h"
#include "save.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "overworld/npc.h"
#include "fading.h"
#include "pokemon/basestat.h"
#include "agbmemory.h"
#include "vars.h"
#include "overworld/map_control.h"
#include "prng.h"
#include "superstate.h"
#include "flags.h"
#include "overworld/script.h"

extern u8 script_pokeradar_battle[];

map_event_person pokeradar_map_event_person = {
    254, //scripts use this as target reference
    155, //the picture to be displayed
    0,
    0,
    0, //x
    0, //y
    0, //level
    2, //move arround
    0, //behaviour range
    0, 
    1, //is trainer -> yes;
    0, //padding is trainer;
    0,
    3, //sight range;
    script_pokeradar_battle,
    POKERADAR_POKEMON_SPAWNED,
    0,
};

bool pokeradar_determine_position(coordinate *result) {
    s16 camera_pos[2];
    player_get_position(&camera_pos[0], &camera_pos[1]);
    coordinate *candidates = (coordinate*) malloc(sizeof (coordinate)*15 * 11); //Every tile could be a candidate
    int candidate_cnt = 0;
    int i, j;
    for (i = -7; i <= 7; i++) {
        for (j = -5; j <= 5; j++) {
            s16 x = (s16) (camera_pos[0] + i);
            s16 y = (s16) (camera_pos[1] + j);
            if (block_get_field_by_pos(x, y, FIELD_HM_USAGE) == 1) {
                //Now we have to check if there is a npc on this tile
                int k;
                bool match = false;
                for (k = 0; k < 16; k++) {
                    if (npcs[k].dest_x == x && npcs[k].dest_y == y) {
                        match = true;
                        break;
                    }
                }
                if (!match) {
                    //Tile is candidate
                    candidates[candidate_cnt].x = x;
                    candidates[candidate_cnt].y = y;
                    candidate_cnt++;
                }
            }
        }
    }
    s16 x = -1;
    s16 y = -1;
    //test(candidates);
    if (candidate_cnt) {
        //now we choose a random candidate
        int r = rnd16() %  candidate_cnt;
        x = candidates[r].x;
        y = candidates[r].y;
    }
    result->x = x;
    result->y = y;
    free(candidates);
    return candidate_cnt;
}

void pokeradar_callback_return_to_ow_and_init_script() {
    generic_callback1();
    if (!fading_is_active()) {
        pokepad_free_components();
        overworld_script_init(script_pokeradar);
        map_reload();
    }
}

void pokeradar_init(bool is_outdoor) {
    *var_access(0x800D) = pokeradar_prepeare();
    if (is_outdoor) {
        overworld_script_init(script_pokeradar);
    } else {
        fadescreen_all(1, 0);
        callback1_set(pokeradar_callback_return_to_ow_and_init_script);
    }

}

u8 pokeradar_prepeare() {
    if (!checkflag(POKERADAR_POKEMON_SPAWNED))
        return 4; //already spawned a poke
    coordinate npc_pos;
    u16 wild_table_entry = map_wild_pokemon_get_current_table_id();
    if (wild_table_entry != 0xFFFF) {
        if (wild_pokemon[wild_table_entry].other) {
            if (!pokeradar_determine_position(&npc_pos))
                return 3;
            //There is a pokemon we can spawn, we check if random < frequency
            u8 random = (u8) rnd16();
            if (wild_pokemon[wild_table_entry].other->frequency <= random) {
                return 2; //Unlucky, pokemon did not appear
            }
            int index;
            //Now we select a pokemon
            random = (u8) rnd16();
            if (random < 76) { //0.3 chance
                index = 0;
            } else if (random < 140) { //0.25 chance
                index = 1;
            } else if (random < 191) { //0.2 chance
                index = 2;
            } else if (random < 230) { //0.15 chance
                index = 3;
            } else {
                index = 4; //0.1 chance
            }
            u16 result = wild_pokemon[wild_table_entry].other->data[index].species;
            //now we determine the level
            u8 min = wild_pokemon[wild_table_entry].other->data[index].level_min;
            u8 max = wild_pokemon[wild_table_entry].other->data[index].level_max;
            int level = (rnd16() % (max - min + 1)) + min;
            *var_access(0x8000) = result;
            *var_access(0x8001) = (u16) level;

            memcpy(&(cmem.pokeradar_person), &pokeradar_map_event_person, sizeof(map_event_person));
            cmem.pokeradar_person.x = (s16)(npc_pos.x - 7);
            cmem.pokeradar_person.y = (s16)(npc_pos.y - 7);
            cmem.pokeradar_person.overworld_index = (u8)(154 + basestats[result].form);
            

            return 0;
        }
    }
    return 1; //No pokemon found on this map
}

bool pokeradar_npc_alert(u8 npc_id) {
    if (npcs[npc_id].overworld_id == 254) {
        if (npc_sees_player(&npcs[npc_id])) {
            overworld_script_init(script_pokeradar_alert);
            overworld_script_set_active();
            return true;
        }
    }
    return false;
}

u16 pokeradar_next_seed() {
    u32 d = (u32) ((*var_access(POKERADAR_ENCOUNTER_COUNT) >> 4) + 1);
    if (d > 4) d = 4;
    u16 seed = rnd16() & 511;
    return (u16) (seed / d);
}

void pokeradar_spawn_pokemon() {
    pokemon_clear_opponent_party();
    u16 species = *var_access(POKERADAR_EMENY_SPECIES);
    u8 level = (u8) * var_access(POKERADAR_ENEMY_LEVEL);
    if (*var_access(POKERADAR_ENCOUNTER_COUNT) != 0xFFFF)
        (*var_access(POKERADAR_ENCOUNTER_COUNT))++;
    pid_t p = {.value = 0};
    pokemon_spawn_by_seed_algorithm(&opponent_pokemon[0], species, level, 32, false, p,
        false, 0, pokeradar_next_seed, NULL);
}

bool pokeradar_step() {
    if (checkflag(POKERADAR_POKEMON_SPAWNED))
        return false;
    u16 steps = (*var_access(POKERADAR_ENEMY_STATE))++;
    u16 r = rnd16() % 10;
    if (steps > r) {

        //we either do a pos change (0,75) or a flee (0,25)
        if ((u8) rnd16() < 64) {
            //flee script
            overworld_script_init(script_pokeradar_flee);
            overworld_script_set_active();
            return true;
        } else {
            //pos change
            *var_access(POKERADAR_ENEMY_STATE) = 0;
            coordinate npc_pos;
            if (pokeradar_determine_position(&npc_pos)) {
                cmem.pokeradar_person.x = (s16) (npc_pos.x - 7);
                cmem.pokeradar_person.y = (s16) (npc_pos.y - 7);
                overworld_script_init(script_pokeradar_poschange);
                overworld_script_set_active();
                return true;
            }
        }
    }
    return false;
}
