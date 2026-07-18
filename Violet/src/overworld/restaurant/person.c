#include "overworld/restaurant.h"
#include "vars.h"
#include "prng.h"
#include "trainer/trainer.h"
#include "flags.h"
#include "overworld/npc.h"
#include "map/header.h"
#include "map/event.h"
#include "save.h"
#include "debug.h"

void restaurant_randomize() {
    *var_access(VAR_RESTAURANT_SEED) = rnd16();
    for (int i = 0; i < NUM_RESTAURANT_TRAINERS; i++) {
        bool visible = (rnd16() & 1) == 0;
        if (visible) {
            clearflag((u16)INVERSE_FLAG(FLAG_RESTAURANT_TRAINER_0 + i));
        } else {
            setflag((u16)INVERSE_FLAG(FLAG_RESTAURANT_TRAINER_0 + i));
        }
        cleartrainerflag((u16)(RESTAURANT_TRAINER_BASE + i));
    }
}

void restaurant_update_sprites() {
    const map_header_t *header = get_mapheader(save1->bank, save1->map);
    for (u8 i = 0; i < header->events->person_cnt; i++) {
        u16 flag = header->events->persons[i].flag;
        if (flag == 0 || !checkflag(flag)
        ) {
            person_showsprite(header->events->persons[i].target_index, save1->map, save1->bank);
        } else {
            person_hidesprite(header->events->persons[i].target_index, save1->map, save1->bank);
        }
    }
    pal_set_all_to_black();
}