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
#include "mega.h"


static void trainer_load_items(u16 trainer_idx, u16 *items, u8 *num_items, bool load_additional_items) {
	for (int i = 0; i < 4; i++) {
		u16 item = trainers[trainer_idx].items[i];
		if (item) {
			items[(*num_items)++] = item;
		}
	}
	if (load_additional_items) {
		switch(*var_access(DIFFICULTY)) {
			case DIFFICULTY_HARD: {
				u16 additional_item = ITEM_TRANK;
				int num_additional_items = 1;
				if (checkflag(FRBADGE_7)) {
					additional_item = ITEM_TOP_GENESUNG;
					num_additional_items = 4;
				} else if (checkflag(FRBADGE_5)) {
					additional_item = ITEM_TOP_TRANK;
					num_additional_items = 4;
				} else if (checkflag(FRBADGE_3)) {
					additional_item = ITEM_HYPERTRANK;
					num_additional_items = 3;
				} else if (checkflag(FRBADGE_1)) {
					additional_item = ITEM_SUPERTRANK;
					num_additional_items = 2;
				}
				for (int i = 0; i < num_additional_items && *num_items < 4; i++) {
					items[(*num_items)++] = additional_item;
				}
			}
		}
	}
}

void trainer_load_items_and_ai() {
	memset(battle_struct->history, 0, sizeof(battle_history_t));
	DEBUG("Active Battler %d\n", active_battler);
	for (active_battler = 0; active_battler < 4; active_battler++) {
		battle_state2->num_items[active_battler] = 0;
		// trainer_load_ai(battler_); I suppose we don't need this? // Todo Load AI thinking struct for the active battler only
		for (int j = 0; j < 4; j++)
			battle_state2->items[active_battler][j] = 0;
	}
	active_battler = 0;
	if (trainer_vars.trainer_id != 0x400 && !(battle_flags & (BATTLE_LINK | BATTLE_SAFARI | BATTLE_EREADER | BATTLE_TOWER |
					BATTLE_FACTORY))) {
		trainer_load_items(trainer_vars.trainer_id, battle_state2->items[OWNER_TRAINER_A], battle_state2->num_items + OWNER_TRAINER_A, true);
		if (battle_flags & BATTLE_TWO_TRAINERS)
			trainer_load_items(trainer_varsB.trainer_id, battle_state2->items[OWNER_TRAINER_B], battle_state2->num_items + OWNER_TRAINER_B, true);
		if (battle_flags & BATTLE_ALLY)
			trainer_load_items(*var_access(VAR_ALLY), battle_state2->items[OWNER_ALLY], battle_state2->num_items + OWNER_ALLY, true);
	}
}

