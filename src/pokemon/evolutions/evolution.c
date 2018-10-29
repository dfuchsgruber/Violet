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

#define TYPE_LEVEL_UP 0
#define TYPE_TRADE_EVO 1
#define TYPE_ITEM_TRIGGER 2
#define TYPE_ITEM_TRIGGER2 3
#define TYPE_ITEM_TRIGGER_AND_REMOVE 4

#define BANK_GLAZEON 0xFF
#define MAP_GLAZEON 0xFF
#define BANK_LEAFEON 0xFF
#define MAP_LEAFEON 0xFF

u16 pokemon_get_evolution(pokemon *p, u8 type, u16 arg){
    u16 species = (u16)pokemon_get_attribute(p, ATTRIBUTE_SPECIES, 0);
    u16 held_item = (u16)pokemon_get_attribute(p, ATTRIBUTE_ITEM, 0);
    dprintf("Pokemon get evolution called with type %d\n", type);
    switch(type){
        case TYPE_LEVEL_UP:{ //The usual case
            arg = (u8)pokemon_get_attribute(p, ATTRIBUTE_LEVEL, 0);
            if(species == POKEMON_EVOLI){
                //Special case for Eevee, as it has 7 possible evolutions...
                //In particular we check for Glazeon, Leafeon, Silveon as those are not listed
                if(save1->bank == BANK_GLAZEON && save1->map == MAP_GLAZEON)
                    return POKEMON_GLAZIOLA;
                if(save1->bank == BANK_LEAFEON && save1->map == MAP_LEAFEON)
                    return POKEMON_FOLIPURBA;
                u8 friendship = (u8)pokemon_get_attribute(p, ATTRIBUTE_HAPPINESS, 0);
                if(friendship >= 220){
                    int j;
                    for(j = 0; j < 4; j++){
                        u16 attack = (u16)pokemon_get_attribute(p, (u8)(ATTRIBUTE_ATTACK1 + j), 0);
                        if(attacks[attack].type == TYPE_FEE)
                            return POKEMON_FEELINARA;
                    }
                }
            }
            int i;
            for(i = 0; i < 5; i++){
                switch(pokemon_evolutions[species][i].method){
                    case EVOLUTION_METHOD_FRIENDSHIP:{
                        u8 friendship = (u8)pokemon_get_attribute(p, ATTRIBUTE_HAPPINESS, 0);
                        if(friendship >= 220)
                            return pokemon_evolutions[species][i].target;
                        break;
                    }
                    case EVOLUTION_METHOD_FRIENDSHIP_DAY:{
                        u8 friendship = (u8)pokemon_get_attribute(p, ATTRIBUTE_HAPPINESS, 0);
                        if(!rtc_test())
                            dprintf("A Pokemon that evolves at day has leveled up but your RTC seems to be turned off!\n");
                        rtc_timestamp time = {0};
                        time_read(&time);
                        if(time.hour > 6 && time.hour < 22 && friendship >= 220)
                            return pokemon_evolutions[species][i].target;
                        break;
                    }
                    case EVOLUTION_METHOD_FRIENDSHIP_NIGHT:{
                        u8 friendship = (u8)pokemon_get_attribute(p, ATTRIBUTE_HAPPINESS, 0);
                        if(!rtc_test())
                            dprintf("A Pokemon that evolves at night has leveled up but your RTC seems to be turned off!\n");
                        rtc_timestamp time = {0};
                        time_read(&time);
                        dprintf("Night evolution with friendship at %d\n", friendship);
                        if((time.hour <= 6 || time.hour >= 22) && friendship >= 220)
                            return pokemon_evolutions[species][i].target;
                        break;
                    }
                    case EVOLUTION_METHOD_SPAWN_SECOND:
                    case EVOLUTION_METHOD_LEVEL_UP:{
                        dprintf("Level up called with arg %d and cond %d\n", arg, pokemon_evolutions[species][i].condition);
                        if(pokemon_evolutions[species][i].condition <= arg)
                            return pokemon_evolutions[species][i].target;
                        break;
                    }
                    case EVOLUTION_METHOD_ATK_GT_DEF:{
                        u16 atk = (u16)pokemon_get_attribute(p, ATTRIBUTE_ATK, 0);
                        u16 def = (u16)pokemon_get_attribute(p, ATTRIBUTE_DEF, 0);
                        if(atk > def && pokemon_evolutions[species][i].condition <= arg)
                            return pokemon_evolutions[species][i].target;
                        break;
                    }
                    case EVOLUTION_METHOD_ATK_EQ_DEF:{
                        u16 atk = (u16)pokemon_get_attribute(p, ATTRIBUTE_ATK, 0);
                        u16 def = (u16)pokemon_get_attribute(p, ATTRIBUTE_DEF, 0);
                        if(atk == def && pokemon_evolutions[species][i].condition <= arg)
                            return pokemon_evolutions[species][i].target;
                        break;
                    }
                    case EVOLUTION_METHOD_ATK_LT_DEF:{
                        u16 atk = (u16)pokemon_get_attribute(p, ATTRIBUTE_ATK, 0);
                        u16 def = (u16)pokemon_get_attribute(p, ATTRIBUTE_DEF, 0);
                        if(atk < def && pokemon_evolutions[species][i].condition <= arg)
                            return pokemon_evolutions[species][i].target;
                        break;
                    }
                    case EVOLUTION_METHOD_PID_EVEN:{
                        pid_t pid = {.value = (u32)pokemon_get_attribute(p, ATTRIBUTE_PID, 0)};
                        if(pokemon_evolutions[species][i].condition <= arg &&
                                pid.value % 10 <= 4)
                            return pokemon_evolutions[species][i].target;
                        break;
                    }
                    case EVOLUTION_METHOD_PID_ODD:{
                        pid_t pid = {.value = (u32)pokemon_get_attribute(p, ATTRIBUTE_PID, 0)};
                        if(pokemon_evolutions[species][i].condition <= arg &&
                                pid.value % 10 > 4)
                            return pokemon_evolutions[species][i].target;
                        break;
                    }
                    case EVOLUTION_METHOD_ON_MAP:{
                        u16 condition = pokemon_evolutions[species][i].condition;
                        u8 bank = (u8)(condition & 0xFF);
                        u8 mapid = (u8)((condition >> 8) & 0xFF);
                        if(bank == save1->bank && mapid == save1->map)
                            return pokemon_evolutions[species][i].target;
                        break;
                    }
                    case EVOLUTION_METHOD_HOLD_ITEM:{
                        if(held_item == pokemon_evolutions[species][i].condition){
                            held_item = 0; //Remove this item
                            pokemon_set_attribute(p, ATTRIBUTE_ITEM, &held_item);
                            return pokemon_evolutions[species][i].target;
                        }
                        break;
                    }
                    case EVOLUTION_METHOD_KNOW_MOVE:{
                        u16 move = pokemon_evolutions[species][i].condition;
                        int j;
                        for(j = 0; j < 4; j++){
                            if(pokemon_get_attribute(p, 
                                    (u16)(ATTRIBUTE_ATTACK1 + j), 0) == move)
                                return pokemon_evolutions[species][i].target;
                                
                        }
                        break;
                    }
                    case EVOLUTION_METHOD_HOLD_ITEM_AND_NIGHT:{
                        if(!time_test())
                            dprintf("A Pokemon that evolves at night has leveled up but your RTC seems to be turned off!\n");
                        rtc_timestamp time = {0};
                        time_read(&time);
                        if((time.hour <= 6 || time.hour >= 22) &&
                                held_item == pokemon_evolutions[species][i].condition){
                            held_item = 0; //Remove this item
                            pokemon_set_attribute(p, ATTRIBUTE_ITEM, &held_item);
                            return pokemon_evolutions[species][i].target;
                        }
                        break;
                    }
                    case EVOLUTION_METHOD_HOLD_ITEM_AND_DAY:{
                        if(!time_test())
                            dprintf("A Pokemon that evolves at day has leveled up but your RTC seems to be turned off!\n");
                        rtc_timestamp time = {0};
                        time_read(&time);
                        if((time.hour > 6 || time.hour < 22) &&
                                held_item == pokemon_evolutions[species][i].condition){
                            held_item = 0; //Remove this item
                            pokemon_set_attribute(p, ATTRIBUTE_ITEM, &held_item);
                            return pokemon_evolutions[species][i].target;
                        }
                        break;
                    }
                }
            }
            break;
        }
        case TYPE_TRADE_EVO:
            //Deprecated as trade evo does not exist
            //dprintf("Error: Trade evolution for pokemon %d at %x is not implemented!\n", species, p);
            //err(ERR_TRADE_EVO_NOT_IMPLEMENTED);
            break;
        case TYPE_ITEM_TRIGGER:
        case TYPE_ITEM_TRIGGER2:
        case TYPE_ITEM_TRIGGER_AND_REMOVE:
        {
            //Check for evolutions triggered by an item
            int i;
            for(i = 0; i < 5; i++){
                switch(pokemon_evolutions[species][i].method){
                    case EVOLUTION_METHOD_STONE: //Regular evolution stone
                        if(pokemon_evolutions[species][i].condition == arg)
                            return pokemon_evolutions[species][i].target;
                        break;
                    case EVOLUTION_METHOD_LINK_CABLE_AND_ITEM:
                        if(arg == ITEM_LINKKABEL &&
                                pokemon_evolutions[species][i].condition == held_item){
                            if(type == TYPE_ITEM_TRIGGER_AND_REMOVE){
                                held_item = 0;
                                pokemon_set_attribute(p, ATTRIBUTE_ITEM, &held_item);
                            }
                            return pokemon_evolutions[species][i].target;
                            
                        }
                        break;
                    case EVOLUTION_METHOD_MALE_AND_STONE:{
                        u8 gender = pokemon_get_gender(p);
                        if(gender == 0 && pokemon_evolutions[species][i].condition == arg)
                            return pokemon_evolutions[species][i].target;
                        break;
                    }
                    case EVOLUTION_METHOD_FEMALE_AND_STONE:{
                        u8 gender = pokemon_get_gender(p);
                        if(gender == 0xFE && pokemon_evolutions[species][i].condition == arg)
                            return pokemon_evolutions[species][i].target;
                        break;
                    }
                }
            }
            break;
        }
    }
    return 0;
}
