#include "types.h"
#include "version.h"
#include "save.h"
#include "rtc.h"
#include "constants/vars.h"
#include "constants/items.h"
#include "constants/flags.h"
#include "constants/time_types.h"
#include "tile/trash.h"
#include "language.h"
#include "vars.h"
#include "flags.h"
#include "worldmap.h"
#include "item/item.h"
#include "debug.h"
#include "overworld/script.h"
#include "text.h"
#include "pokemon/virtual.h"

void version_init(){
    *var_access(SGM_VER) = VERSION_LATEST;
}

u8 str_version_alpha_1_0[] = LANGDEP(
    PSTRING("Herzlichen Glückwunsch!\nDeine Version wurde von\lBUFFER_1.X auf BUFFER_2.X"
        "\lgeupdated.\pSetze dein Abenteuer im Osten\nder Felsigen Ödnis fort."),
    PSTRING("Congratulations!\nYour version was updated from\lBUFFER_1.X to BUFFER_2.X."
        "\pContinue your adventure in the east\nof the Rocky Desolation."));

void version_transfer(){
	*var_access(0x8004) = *var_access(SGM_VER);
    while(*var_access(SGM_VER) != VERSION_LATEST){
        //transfer savegames to a higher version until we reach the latest
        switch(*var_access(SGM_VER)){
        	case VERSION_ALPHA_2_2:
				// Latest
				break;
            case VERSION_ALPHA_2_1:
                version_upgrade_alpha_2_1_to_2_2();
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
	*var_access(0x8005) = *var_access(SGM_VER);
	u8 str_version[] = LANGDEP(
    		PSTRING("Alpha 2.2"),
			PSTRING("Alpha 2.2."));
	strcpy(buffer0, str_version);
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

void version_upgrade_alpha_2_1_to_2_2() {
    *var_access(SGM_VER) = VERSION_ALPHA_2_2;
	*var_access(TRAINERSCHOOL_PROGRESS) = 10;
	*var_access(TRAINERSCHOOL_ALLOWED_TO_ENTER_GRASS) = 1;
	*var_access(TRAINERSCHOOL_GOODBYE_CNT) = 3;
	setflag(TRAINERSCHOOL_MAY_INSIDE);
	setflag(TRAINERSCHOOL_BLAISE_INSIDE);
	setflag(TRAINERSCHOOL_FELIX_INSIDE);
	setflag(TRAINERSCHOOL_MAY_OUTSIDE);
	setflag(TRAINERSCHOOL_BLAISE_OUTSIDE);
	setflag(TRAINERSCHOOL_FELIX_OUTSIDE);
	setflag(TRAINERSCHOOL_TALKED_TO_FELIX);
	setflag(TRAINERSCHOOL_FAUN_OUTSIDE);
	setflag(TRAINERSCHOOL_TALKED_TO_BLAISE);
	setflag(ROUTE_1_RIVAL);
	setflag(TRAINERSCHOOL_RIVAL);
	setflag(TRAINERSCHOOL_RIVAL_INSIDE);
	setflag(TRAINERSCHOOL_FAUN_INSIDE);
	setflag(ROUTE_2_FELIX);
    setflag(ROUTE_3_MAY);
    clearflag(POKEDEX_FEATURE_0);
    clearflag(POKEDEX_FEATURE_1);
    clearflag(POKEDEX_FEATURE_2);
    worldmap_flag_state_set(WM_ORINA_CITY);
    worldmap_flag_state_set(WM_AKTANIA);
    worldmap_flag_set(WM_ORINA_CITY);
    worldmap_flag_set(WM_AKTANIA);
	// Pick time system that works
	if (rtc_test()) {
		*var_access(TIME_TYPE) = TIME_TYPE_RTC;
	} else {
		*var_access(TIME_TYPE) = TIME_TYPE_INGAME_CLOCK;
	}
	time_reset_events();
	// Reorder pokedex flags
	version_transfer_pokedex();

	// Pokemon pid structure has changed as well
	// Update the party
	for (int i = 0; i < 6; i++) {
		version_alpha_2_2_fix_pid(&player_pokemon[i]);
		pokemon_calculate_stats(&player_pokemon[i]);
	}
	// Update the boxes
	for (int box_idx = 0; box_idx < 15; box_idx++) {
		for (int idx = 0; idx < 30; idx++) {
			version_alpha_2_2_fix_pid(pokemon_get_by_box(box_idx, idx));
		}
	}

}

u16 version_is_latest(){
    return *var_access(SGM_VER) == VERSION_LATEST;
}
