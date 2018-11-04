#include "types.h"
#include <stdbool.h>
#include "oam.h"
#include "callbacks.h"
#include "mega.h"
#include "debug.h"
#include "text.h"
#include "language.h"
#include "trainer/trainer.h"
#include "trainer/virtual.h"
#include "item/item.h"
#include "constants/vars.h"
#include "battle/battlescript.h"
#include "vars.h"
#include "battle/battler.h"
#include "abilities.h"


u8 str_mega_reacts[] = LANGDEP(
		PSTRING("BUFFER_2 von BUFFER_1\nreagiert auf PLAYER von BUFFER_3."),
		PSTRING("BUFFER_1\'s BUFFER_2\nreacts to BUFFER_3\'s PLAYER.")
);

u8 str_mega_opp[] = LANGDEP(
		PSTRING("(Gegner)"),
		PSTRING("(foe)")
);

u8 str_mega_evolved[] = LANGDEP(
		PSTRING("BUFFER_1 hat sich zu\nMega-KUN entwickelt!"),
		PSTRING("BUFFER_1 evolved into\nMega-KUN!")
);

u8 str_regent_evolved[] = LANGDEP(
		PSTRING("BUFFER_1 umgibt die Aura\neines Kaisers!"),
		PSTRING("BUFFER_1 is surrouned by\nthe aura of an emperor!")
);

u8 str_aura_pulses[] = LANGDEP(
		PSTRING("Die Aura von BUFFER_1\npulsiert!"),
		PSTRING("BUFFER_1\'s aura begins\nto pulse!")
);


extern u8 mega_anim_clear_script[];


void cb_mega_anim(u8 self) {

    big_callback* cself = &big_callbacks[self];

    //execute bsc if bsc active
    u8 battle_state = *((u8*) 0x02023BE3);
    if (battle_state == 0xC) {
        battlescript_execute();
    }

    


    //at frame 0x0: clear the message box
    if (cself->params[0] == 0x0) {
        u8 battle_state = *((u8*) 0x02023BE3);
        cself->params[3] = battle_state;
        *((u8*) 0x02023BE3) = 0xC; //we go to state : execute bsc
        //*((u8**)0x02023D74) = (u8*)0x81DD2Ae; //test bsc
        *((u8**) 0x02023D74) = mega_anim_clear_script;
    }

    //at frame 0x4: print "reacts to mega"
    if (cself->params[0] == 0x4 || cself->params[0] == 540) {
        //we copy our string into the ram buffer
        u8* ram_buf = strbuf;
        u8 slot = (u8) cself->params[1];
        
        //debug1(&big_callbacks[self]);

        u8* src = (cself->params[0] == 540) ? str_mega_evolved : str_mega_reacts;

        //searching for the mega evolution that has current species as target and is a regent evolution
        cself->params[5] = 0;
        int i = 0;
        while (megas[i].species != 0xFFFF) {
            if (megas[i].target == battlers[slot].species && megas[i].regent) {
                cself->params[5] = megas[i].species;
                src = (cself->params[0] == 540) ? str_regent_evolved : str_aura_pulses;
            }
            i++;
        }

        while (*src != 0xFF) {
            u8 cchar = *src++;
            if (cchar == 0xFD) {

                //buffer hit
                //for testing we just skip the buffer
                u8 buffer_id = *src++;
                switch (buffer_id) {
                    case 1:
                    {
                        //We request the mega item (depending on side)
                        u16 item = battler_is_opponent(slot) ? *(var_access(OPPONENT_MEGA_ITEM))
                        		: *(var_access(PLAYER_MEGA_ITEM));
                        ram_buf = (strcpy(ram_buf, items[item].name));
                        break;
                    }
                    case 2:
                    {
                        //We request the pokemons name
                        ram_buf = (strcpy(ram_buf, battlers[slot].name));
                        if (battler_is_opponent(slot)) {
                            ram_buf = strcpy(ram_buf, str_mega_opp);
                        }
                        break;
                    }
                    case 3:
                    {
                        //We request the held item
                        u16 item = battlers[slot].item;
                        ram_buf = (strcpy(ram_buf, items[item].name));
                        break;
                    }
                    case 4:
                    {
                        //We request the ot-name
                        if (!battler_is_opponent(slot)) {
                            ram_buf = (strcpy(ram_buf, (*(u8**) 0x03004F5C)));
                        } else {
                            u16 trainer_id = trainer_vars.trainer_id;
                            //if trainerclass is of rival we load name form saveblock as well
                            if (trainers[trainer_id].trainerclass == 0x51) {
                                ram_buf = (strcpy(ram_buf, (u8*) ((*((u8**) 0x03004F58)) + 0x3A4C)));
                            } else {
                                ram_buf = (strcpy(ram_buf, trainers[trainer_id].name));
                            }
                        }
                        break;
                    }
                    case 5:
                    {
                        //We request the original species
                        u16 species = battlers[slot].species;
                        ram_buf = (strcpy(ram_buf, (u8*) (0x8245Db0 + 11 * species)));
                        break;
                    }
                }
            } else {
                *ram_buf++ = cchar;
            }
        }
        *ram_buf = 0xFF; //adding the end of string to the ram buffer
        battle_print_string(strbuf, 0x40);
    }


    //start mega animation
    if (cself->params[0] == 0x44) {
        //*((u8*)0x02023BE3) = 0xC; //we go to state : execute bsc
        //*((u8**)0x02023D74) = pause_script;
        u8 slot = (u8) cself->params[1];

        u8* canim = (u8*) attack_anim_mega;
        if (cself->params[5]) {
            //find corresponding mega
            if (cself->params[5] == 0x195) {
                canim = (u8*) attack_anim_groudon;
            } else if (cself->params[5] == 0x194) {
                canim = (u8*) attack_anim_kyogre;
            } else if (cself->params[5] == 0x196) {
                canim = (u8*) attack_anim_rayquaza;
            }
        }

        call_attack_anim_by_offset(slot, 1, canim);

        *((u8*) 0x02037F1B) = slot; //target of animation is also the user
        //call_attack_anim_from_offset(slot, 1,(void*)0x81CFC00);


    }


    if (cself->params[0] == 800) {
        
        u8 slot = (u8) cself->params[1];
        mega_disable_blurr(slot);
        
        *((u8*) 0x02023BE3) = (u8) (cself->params[3]);
        big_callback_delete(self);
        //dprintf("removed callback with slot %d\n", 8);
        //dprintf("executing ability_management with %d\n", 4);

        dprintf("Hello world\nLinebreak:%d", 57);
        //we know execute ability management for battle enter
        *((u8*) 0x02023D6B) = slot; //active index is current slot
        ability_execute(0, slot, 0, 0, 0);


    } else {
        cself->params[0] = (u16) (cself->params[0] + 1);
    }
}
