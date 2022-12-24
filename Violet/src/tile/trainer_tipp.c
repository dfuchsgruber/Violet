#include "types.h"
#include "stdbool.h"
#include "vars.h"
#include "flags.h"
#include "tile/trainer_tipp.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/items.h"
#include "item/item.h"

bool trigger_trainer_tipp(){
    u16 *ttip_cnt = var_access(TRAINER_TIPP_CNT);
        if(*ttip_cnt){
            (*ttip_cnt)--;
            return false;
        }else{
            *ttip_cnt = TRAINER_TIPP_RELOAD;
            return true;
        }
}

/**
 * 
 * @return A new Trainer-Tipp Script if one is possible 
 */
u8 *get_trainer_tipp(){
    if(!checkflag(TRAINER_TIPP_DNS)){
        if(!trigger_trainer_tipp()) return NULL;
        setflag(TRAINER_TIPP_DNS);
        return script_trainer_tipp_dns;
    }
    if(checkflag(0x828) && !checkflag(TRAINER_TIPP_FP_MENU)){
        if(!trigger_trainer_tipp()) return NULL;
        setflag(TRAINER_TIPP_FP_MENU);
        return script_trainer_tipp_fp_menu;
    }
    if(checkflag(WONDERTRADE) && !checkflag(TRAINER_TIPP_WONDERTRADE)){
        if(!trigger_trainer_tipp()) return NULL;
        setflag(TRAINER_TIPP_WONDERTRADE);
        return script_trainer_tipp_wondertrade;
    }
    if(checkflag(POKERADAR) && !checkflag(TRAINER_TIPP_POKERADAR)){
        if(!trigger_trainer_tipp()) return NULL;
        setflag(TRAINER_TIPP_POKERADAR);
        return script_trainer_tipp_pokeradar;
    }
    if(checkflag(POKEDEX_FEATURE_HABITAT) && !checkflag(TRAINER_TIPP_HABITAT)){
        if(!trigger_trainer_tipp()) return NULL;
        setflag(TRAINER_TIPP_HABITAT);
        return script_trainer_tipp_habitat;
    }
    if(item_check(ITEM_FAHRRAD, 1) && !checkflag (TRAINER_TIPP_CLOUD)){
        if(!trigger_trainer_tipp()) return NULL;
        setflag(TRAINER_TIPP_CLOUD);
        return script_trainer_tipp_cloud;
    }
    return NULL;
}
