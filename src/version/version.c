#include "types.h"
#include "romfuncs.h"
#include "version.h"
#include "item.h"
#include "save.h"
#include "tile.h"
#include "pokemon.h"
#include "battle.h"
#include "rtc.h"

void version_init(){
    *vardecrypt(VAR_SAVEGAME_VERSION) = VERSION_LATEST;
}

void version_transfer(){
    
    //Buffer the continuation string
    u8 **pointerbank_0 = (u8**)0x03000F14;
    switch(*vardecrypt(VAR_SAVEGAME_VERSION)){
        case 0:
        default:
            *pointerbank_0 = str_version_alpha_1_0;
            break;
    }
    *vardecrypt(0x8004) = (u16)(*vardecrypt(VAR_SAVEGAME_VERSION) + 1);
    while(*vardecrypt(VAR_SAVEGAME_VERSION) != VERSION_LATEST){
        //transfer savegames to a higher version until we reach the latest
        switch(*vardecrypt(VAR_SAVEGAME_VERSION)){
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
    *vardecrypt(0x8005) = (u16)(*vardecrypt(VAR_SAVEGAME_VERSION) + 1);
}

/**
 * Upgrades savegame from version 1.X to 2.0
 */
void version_upgrade_alpha_1_X_to_2_0(){
    worldmapflag_state_set(0x892);
    worldmapflag_set(0x892);
    new_a_vector();
    setflag(0x96B);
    //update entire player party
    int i;
    for(i = 0; i < countpokemon(); i++){
        recalculate_stats(&player_pokemon[i]);
    }
    //Give Gengarnite if chance was missed in 1.X
    if(checkflag(0x90A)){
        additem(ITEM_GENGARNIT, 1);
    }
    *vardecrypt(VAR_SAVEGAME_VERSION) = VERSION_ALPHA_2_0;
}


void version_upgrade_alpha_2_0_to_2_1(){
    *vardecrypt(VAR_SAVEGAME_VERSION) = VERSION_ALPHA_2_1;
    *vardecrypt(BATTLE_BG_OVERRIDE) = 0;
}

u16 version_is_latest(){
    return *vardecrypt(VAR_SAVEGAME_VERSION) == VERSION_LATEST;
}
