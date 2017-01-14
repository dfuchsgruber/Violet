#include "types.h"
#include "stdbool.h"
#include "romfuncs.h"
#include "tile.h"
#include "item.h"
#include "pokepad.h"


bool trigger_trainer_tipp(){
    u16 *ttip_cnt = vardecrypt(VAR_TRAINER_TIPP_CNT);
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
    if(!checkflag(FLAG_TRAINERTIPP_DNS)){
        if(!trigger_trainer_tipp()) return NULL;
        setflag( FLAG_TRAINERTIPP_DNS);
        return script_trainer_tipp_dns;
    }
    if(checkflag(0x828) && !checkflag( FLAG_TRAINERTIPP_FP_MENU)){
        if(!trigger_trainer_tipp()) return NULL;
        setflag(FLAG_TRAINERTIPP_FP_MENU);
        return script_trainer_tipp_fp_menu;
    }
    if(checkflag( FLAG_WONDERTRADE) && !checkflag(FLAG_TRAINERTIPP_WONDERTRADE)){
        if(!trigger_trainer_tipp()) return NULL;
        setflag( FLAG_TRAINERTIPP_WONDERTRADE);
        return script_trainer_tipp_wondertrade;
    }
    if(checkflag( FLAG_POKERADAR) && !checkflag( FLAG_TRAINERTIPP_POKERADAR)){
        if(!trigger_trainer_tipp()) return NULL;
        setflag( FLAG_TRAINERTIPP_POKERADAR);
        return script_trainer_tipp_pokeradar;
    }
    if(checkflag(POKEDEX_FLAG_HABITAT) && !checkflag( FLAG_TRAINERTIPP_HABITAT)){
        if(!trigger_trainer_tipp()) return NULL;
        setflag( FLAG_TRAINERTIPP_HABITAT);
        return script_trainer_tipp_habitat;
    }
    if(checkitem(ITEM_FAHRRAD, 1) && !checkflag (FLAG_TRAINERTIPP_CLOUD)){
        if(!trigger_trainer_tipp()) return NULL;
        setflag(FLAG_TRAINERTIPP_CLOUD);
        return script_trainer_tipp_cloud;
    }
    return NULL;
}
