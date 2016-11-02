#include "types.h"
#include "romfuncs.h"
#include "battle.h"
#include "basestats.h"
#include "trainer.h"
#include "item.h"

void load_trainer_items(trainer_items *t_items) {


    u16 difficulty = *vardecrypt(0x50F9);

    //First we get difficulty
    switch (difficulty) {

        case 0:
            //Very easy, trainer have no items
            t_items->items[0] = 0;
            t_items->items[1] = 0;
            t_items->items[2] = 0;
            t_items->items[3] = 0;
            t_items->cnt = 0;
            break;
        case 3:
        case 4:
        {


            //Hard, trainer have game stage depending items
            //Very hard, trainer have full restore and +2 items in every case
            u16 trainer_item = ITEM_TRANK;
            u8 additional_items = 1;
            if (checkflag(0x820)) {
                trainer_item = ITEM_SUPERTRANK;
                additional_items++;
            }
            if (checkflag(0x822)) {
                trainer_item = ITEM_HYPERTRANK;
                additional_items++;
            }
            if (checkflag(0x824) || difficulty == 4) {
                trainer_item = ITEM_TOP_GENESUNG;
                additional_items++;
            }

            u8 i;
            for (i = 0; i < additional_items && t_items->cnt < 4; i++) {
                t_items->items[t_items->cnt] = trainer_item;
                t_items->cnt++;
            }
            break;
        }

    }
}