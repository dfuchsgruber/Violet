#include "types.h"
#include "romfuncs.h"
#include "oams.h"
#include "callbacks.h"
#include "battle.h"
#include "basestats.h"
#include "trainer.h"
#include "item.h"
#include "mega.h"
#include <stdbool.h>
#include "unaligned_types.h"
#include "debug.h"



extern u8 str_mega_reacts[];
extern u8 str_mega_opp[];
extern u8 str_mega_evolved[];
extern u8 str_regent_evolved[];
extern u8 str_aura_pulses[];

static u8 clear_script[] = {0x10, 0x30, 0x1, //printstring 0x130
    0x12, 0x1, 0x0, //waitmessage 0x1
    0x3D //end
};

mega_table_entry *get_mega_if_can_mega_evolve(battler *b);

void cb_mega_anim(u8 self) {

    big_callback* cself = &big_callbacks[self];

    //execute bsc if bsc active
    u8 battle_state = *((u8*) 0x02023BE3);
    if (battle_state == 0xC) {
        bsc_executer();
    }

    


    //at frame 0x0: clear the message box
    if (cself->params[0] == 0x0) {
        u8 battle_state = *((u8*) 0x02023BE3);
        cself->params[3] = battle_state;
        *((u8*) 0x02023BE3) = 0xC; //we go to state : execute bsc
        //*((u8**)0x02023D74) = (u8*)0x81DD2Ae; //test bsc
        *((u8**) 0x02023D74) = clear_script;
    }

    //at frame 0x4: print "reacts to mega"
    if (cself->params[0] == 0x4 || cself->params[0] == 540) {
        //we copy our string into the ram buffer
        u8* ram_buf = (u8*) 0x02021D18;
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
                        u16 item = is_opponent(slot) ? *(vardecrypt(0x50E4)) : *(vardecrypt(0x50E5));
                        ram_buf = (strcpy(ram_buf, items[item].name));
                        break;
                    }
                    case 2:
                    {
                        //We request the pokemons name
                        ram_buf = (strcpy(ram_buf, battlers[slot].name));
                        if (is_opponent(slot)) {
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
                        if (!is_opponent(slot)) {
                            ram_buf = (strcpy(ram_buf, (*(u8**) 0x03004F5C)));
                        } else {
                            u16 trainer_id = *((u16*) 0x020386AE);
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
        battle_printmsg((u8*) 0x02021D18, 0x40);
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
        remove_big_callback(self);
        //dprintf("removed callback with slot %d\n", 8);
        //dprintf("executing ability_management with %d\n", 4);

        dprintf("Hello world\nLinebreak:%d", 57);
        //we know execute ability management for battle enter
        *((u8*) 0x02023D6B) = slot; //active index is current slot
        ability_management(0, slot, 0, 0, 0);


    } else {
        cself->params[0] = (u16) (cself->params[0] + 1);
    }
}