#include "types.h"
#include "trainer/virtual.h"
#include "constants/items.h"
#include "constants/vars.h"
#include "constants/flags.h"
#include "vars.h"
#include "flags.h"
#include "battle/state.h"
#include "agbmemory.h"
#include "trainer/virtual.h"
#include "trainer/trainer.h"
#include "constants/difficulties.h"
#include "debug.h"
#include "battle/ai.h"

void trainer_load_items_and_ai() {
	memset(battle_struct->history, 0, sizeof(battle_history_t));
	if (trainer_vars.trainer_id != 0x400 &&
			!(battle_flags & (BATTLE_LINK | BATTLE_SAFARI | BATTLE_EREADER | BATTLE_TOWER |
					BATTLE_FACTORY))) { // Why the hell is the factory in here???
		for (int i = 0; i < 4; i++) {
			u16 item = trainers[trainer_vars.trainer_id].items[i];
			if (item) {
				battle_struct->history->
				trainer_items[battle_struct->history->trainer_item_count++] = item;
				dprintf("Load trainer item %d\n", item);
			}
		}
		switch(*var_access(DIFFICULTY)) {
		case DIFFICULTY_HARD:
		case DIFFICULTY_VERY_HARD: {
			u16 additional_item = ITEM_TRANK;
			int additional_items = 1;
			if (checkflag(FRBADGE_6) || *var_access(DIFFICULTY) == DIFFICULTY_VERY_HARD) {
				additional_item = ITEM_TOP_GENESUNG;
				additional_items = 4;
			} else if (checkflag(FRBADGE_4)) {
				additional_item = ITEM_HYPERTRANK;
				additional_items = 3;
			} else if (checkflag(FRBADGE_2)) {
				additional_item = ITEM_SUPERTRANK;
				additional_items = 2;
			}
			// Add these items to the trainer as well if there are slots
			while(additional_items > 0 && battle_struct->history->trainer_item_count < 4) {
				battle_struct->history->
					trainer_items[battle_struct->history->trainer_item_count++] = additional_item;
				additional_items--;
				dprintf("Addded additional item %d\n", additional_item);
			}
		}
		}
	}
	trainer_load_ai();
}

