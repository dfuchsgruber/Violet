#include "types.h"
#include "version.h"
#include "save.h"
#include "rtc.h"
#include "constants/vars.h"
#include "constants/items.h"
#include "tile/trash.h"
#include "language.h"
#include "vars.h"
#include "flags.h"
#include "worldmap.h"
#include "item/item.h"

void version_init(){
    *var_access(SGM_VER) = VERSION_LATEST;
}

u8 str_version_alpha_1_0[] = LANGDEP(
    PSTRING("Herzlichen Glückwunsch!\nDeine Version wurde von\lBUFFER_1.X auf BUFFER_2.X"
        "\lgeupdated.\pSetze dein Abenteuer im Osten\nder Felsigen Ödnis fort."),
    PSTRING("Congratulations!\nYour version was updated from\lBUFFER_1.X to BUFFER_2.X."
        "\pContinue your adventure in the east\nof the Rocky Desolation."));

void version_transfer(){
    
    //Buffer the continuation string
    u8 **pointerbank_0 = (u8**)0x03000F14;
    switch(*var_access(SGM_VER)){
        case 0:
        default:
            *pointerbank_0 = str_version_alpha_1_0;
            break;
    }
    *var_access(0x8004) = (u16)(*var_access(SGM_VER) + 1);
    while(*var_access(SGM_VER) != VERSION_LATEST){
        //transfer savegames to a higher version until we reach the latest
        switch(*var_access(SGM_VER)){
            case VERSION_ALPHA_2_1:
                //Latest
                break;
            case VERSION_ALPHA_2_0:
                version_upgrade_alpha_2_0_to_2_1();
                break;
            case 0:
            default:
                //Version Alpha 1.0 (no version system was implemented there)
                version_upgrade_alpha_1_X_to_2_0();
                break;
            
        }
    }
    *var_access(0x8005) = (u16)(*var_access(SGM_VER) + 1);
}

/**
 * Upgrades savegame from version 1.X to 2.0
 */
void version_upgrade_alpha_1_X_to_2_0(){
    worldmap_flag_state_set(0x892);
    worldmap_flag_set(0x892);
    tmp_hash_new_seed();
    setflag(0x96B);
    //update entire player party
    int i;
    for(i = 0; i < pokemon_get_number_in_party(); i++){
        pokemon_calculate_stats(&player_pokemon[i]);
    }
    //Give Gengarnite if chance was missed in 1.X
    if(checkflag(0x90A)){
        item_add(ITEM_GENGARNIT, 1);
    }
    *var_access(SGM_VER) = VERSION_ALPHA_2_0;
}


void version_upgrade_alpha_2_0_to_2_1(){
    *var_access(SGM_VER) = VERSION_ALPHA_2_1;
    *var_access(BATTLE_BG_OVERRIDE) = 0;
}

u16 version_is_latest(){
    return *var_access(SGM_VER) == VERSION_LATEST;
}
