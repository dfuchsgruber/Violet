#include "types.h"
#include "item/mart.h"
#include "constants/items.h"
#include "save.h"
#include "debug.h"
#include "flags.h"
#include "overworld/script.h"


mart_item mart_items_ball_std[] = {
    {0x823, ITEM_HYPERBALL},
    {0x821, ITEM_SUPERBALL},
    {0x829, ITEM_POKEBALL},
    {0xFFFF, 0}
};

mart_item mart_item_potion_std[] = {
    {0x825, ITEM_TOP_TRANK},
    {0x823, ITEM_HYPERTRANK},
    {0x821, ITEM_SUPERTRANK},
    {0, ITEM_TRANK},
    {0xFFFF, 0}
};

mart_item mart_item_full_restore[] = {
    {0x827, ITEM_TOP_GENESUNG},
    {0xFFFF, 0}
};

mart_item mart_item_feuerheiler[] = {
    {0x823, ITEM_HYPERHEILER},
    {0, ITEM_FEUERHEILER},
    {0xFFFF, 0}
};

mart_item mart_item_eisheiler[] = {
    {0x823, ITEM_HYPERHEILER},
    {0, ITEM_EISHEILER},
    {0xFFFF, 0}
};

mart_item mart_item_para_heiler[] = {
    {0x823, ITEM_HYPERHEILER},
    {0, ITEM_PARA_HEILER},
    {0xFFFF, 0}
};

mart_item mart_item_aufwecker[] = {
    {0x823, ITEM_HYPERHEILER},
    {0, ITEM_AUFWECKER},
    {0xFFFF, 0}
};

mart_item mart_item_gegengift[] = {
    {0x823, ITEM_HYPERHEILER},
    {0, ITEM_GEGENGIFT},
    {0xFFFF, 0}
};

mart_item mart_item_repel_std[] = {
    {0x823, ITEM_TOP_SCHUTZ},
    {0x821, ITEM_SUPERSCHUTZ},
    {0, ITEM_SCHUTZ},
    {0xFFFF, 0}
};

mart_item mart_item_fluchtseil[] = {
    {0, ITEM_FLUCHTSEIL},
    {0xFFFF, 0}
};

mart_item mart_item_beleber[] = {
    {0x823, ITEM_BELEBER},
    {0xFFFF, 0}
};

mart_item mart_item_ether[] = {
    {0x948, ITEM_AETHER},
    {0xFFFF, 0}
};

mart_item mart_item_elixier[] = {
    {0x949, ITEM_ELIXIER},
    {0xFFFF, 0}
};



mart_item *mart_items[] = {
    mart_items_ball_std,
    mart_item_full_restore,
    mart_item_potion_std,
    mart_item_gegengift,
    mart_item_aufwecker,
    mart_item_para_heiler,
    mart_item_feuerheiler,
    mart_item_eisheiler,
    mart_item_repel_std,
    mart_item_fluchtseil,
    mart_item_beleber,
    mart_item_elixier,
    NULL
};


bool script_cmd_x88_pokemart3(void *script_state){
    u16* additional_items = (u16*) overworld_script_read_word(script_state);
    u16 *item_space = (fmem->dmart); //256 items is the maximum
    int i = 0;
    int j = 0;
    int z;
    while(mart_items[i]){
        u16 to_add = 0;
        for(z = 0; mart_items[i][z].item; z++){
            if(!mart_items[i][z].flag || checkflag(mart_items[i][z].flag)){
                to_add = mart_items[i][z].item;
                break;
            }
        }
        if(to_add){
            //check if we can add this item to our list (maybe it is already there)
            bool contained = false;
            for(z = 0; z < j; z++){
                if(item_space[z] == to_add){
                    contained = true;
                    break;
                }
            }
            if(!contained){
                item_space[j++] = to_add;
            }
        }
        i++;
    }
    if(additional_items){
        for(i = 0; additional_items[i]; i++){
            bool contained = false;
            for(z = 0; z < j; z++){
                if(item_space[z] == additional_items[i]){
                    contained = true;
                    break;
                }
            }
            if(!contained){
                item_space[j++] = additional_items[i];
            }
        }
    }
    item_space[j] = 0;
    pokemart(item_space);
    mart_state->end_callback = overworld_script_resume;
    overworld_script_halt();
    return true;
}
